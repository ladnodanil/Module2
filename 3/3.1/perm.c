#include "perm.h"

void printBits(mode_t st_mode)
{
    for (int i = 4 * sizeof(st_mode); i >= 0; --i)
        printf("%d", ((st_mode >> i) & 1));
    printf("\n");
}

mode_t letterToPerm(char *letters)
{
    mode_t perm = 0;
    if (letters[0] == 'r')
        perm |= S_IRUSR;
    if (letters[1] == 'w')
        perm |= S_IWUSR;
    if (letters[2] == 'x')
        perm |= S_IXUSR;
    if (letters[3] == 'r')
        perm |= S_IRGRP;
    if (letters[4] == 'w')
        perm |= S_IWGRP;
    if (letters[5] == 'x')
        perm |= S_IXGRP;
    if (letters[6] == 'r')
        perm |= S_IROTH;
    if (letters[7] == 'w')
        perm |= S_IWOTH;
    if (letters[8] == 'x')
        perm |= S_IXOTH;
    return perm;
}

mode_t numbersToPerm(char *numbers)
{
    int value = strtol(numbers, NULL, 8);
    mode_t perm = 0;

    // U
    if (value & 0400)
        perm |= S_IRUSR;
    if (value & 0200)
        perm |= S_IWUSR;
    if (value & 0100)
        perm |= S_IXUSR;
    // G
    if (value & 0040)
        perm |= S_IRGRP;
    if (value & 0020)
        perm |= S_IWGRP;
    if (value & 0010)
        perm |= S_IXGRP;
    // O
    if (value & 0004)
        perm |= S_IROTH;
    if (value & 0002)
        perm |= S_IWOTH;
    if (value & 0001)
        perm |= S_IXOTH;

    return perm;
}

char *permToLetters(mode_t perm)
{
    static char letters[10];
    letters[0] = (perm & S_IRUSR) ? 'r' : '-';
    letters[1] = (perm & S_IWUSR) ? 'w' : '-';
    letters[2] = (perm & S_IXUSR) ? 'x' : '-';
    letters[3] = (perm & S_IRGRP) ? 'r' : '-';
    letters[4] = (perm & S_IWGRP) ? 'w' : '-';
    letters[5] = (perm & S_IXGRP) ? 'x' : '-';
    letters[6] = (perm & S_IROTH) ? 'r' : '-';
    letters[7] = (perm & S_IWOTH) ? 'w' : '-';
    letters[8] = (perm & S_IXOTH) ? 'x' : '-';
    letters[9] = '\0';
    return letters;
}

mode_t permission(char *permission)
{
    switch (strlen(permission))
    {
    case 9:
        return letterToPerm(permission);
    case 3:
        return numbersToPerm(permission);
    default:
        return 0;
    }
}

mode_t infoFile(char *filename)
{
    struct stat fileInfo;

    if (stat(filename, &fileInfo) == 0)
    {
        mode_t perm = fileInfo.st_mode & 0777;
        return perm;
    }
    else
    {
        perror("Error file");
    }
}

void printPerm(mode_t permission)
{
    printf("letters: %s\n", permToLetters(permission));
    printf("numbers: %o\n", permission);
    printf("bits: ");
    printBits(permission);
}

void permissionChange(char *filename, char *cmd)
{
    mode_t oldPerm = infoFile(filename);
    mode_t newPerm = oldPerm;



    // =654
    if (cmd[0] == '=') {
        if (strlen(cmd+1) == 9) {
            newPerm = letterToPerm(cmd + 1);
        } else if (strlen(cmd+1) == 3) {
            newPerm = numbersToPerm(cmd + 1);
        }
    } else {
        //  [ugoa]*[+-=][rwx]*
        char *p = cmd;
        while (*p) {
            int who[3] = {0, 0, 0}; 
            int any_who = 0;
            while (*p == 'u' || *p == 'g' || *p == 'o' || *p == 'a') {
                if (*p == 'u') who[0] = 1;
                if (*p == 'g') who[1] = 1;
                if (*p == 'o') who[2] = 1;
                if (*p == 'a') who[0] = who[1] = who[2] = 1;
                ++p;
                any_who = 1;
            }
            if (!any_who) who[0] = who[1] = who[2] = 1;
            char op = *p;
            if (op != '+' && op != '-' && op != '=') break;
            ++p;
            int perm_mask[3] = {0, 0, 0};
            while (*p == 'r' || *p == 'w' || *p == 'x') {
                if (*p == 'r') { if (who[0]) perm_mask[0] |= S_IRUSR; if (who[1]) perm_mask[1] |= S_IRGRP; if (who[2]) perm_mask[2] |= S_IROTH; }
                if (*p == 'w') { if (who[0]) perm_mask[0] |= S_IWUSR; if (who[1]) perm_mask[1] |= S_IWGRP; if (who[2]) perm_mask[2] |= S_IWOTH; }
                if (*p == 'x') { if (who[0]) perm_mask[0] |= S_IXUSR; if (who[1]) perm_mask[1] |= S_IXGRP; if (who[2]) perm_mask[2] |= S_IXOTH; }
                ++p;
            }
            mode_t mask = perm_mask[0] | perm_mask[1] | perm_mask[2];
            if (op == '+') newPerm |= mask;
            else if (op == '-') newPerm &= ~mask;
            else if (op == '=') {
                if (who[0]) newPerm = (newPerm & ~(S_IRUSR|S_IWUSR|S_IXUSR)) | (perm_mask[0]);
                if (who[1]) newPerm = (newPerm & ~(S_IRGRP|S_IWGRP|S_IXGRP)) | (perm_mask[1]);
                if (who[2]) newPerm = (newPerm & ~(S_IROTH|S_IWOTH|S_IXOTH)) | (perm_mask[2]);
            }
            if (*p == ',') ++p; 
        }
    }

    printf("\nOld perm:\n");
    printPerm(oldPerm);
    printf("\nNew perm:\n");
    printPerm(newPerm);
}
