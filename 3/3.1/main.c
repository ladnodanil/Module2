#include "perm.h"
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 256

int main()
{
    int choice;
    char buf[BUF_SIZE];
    char filename[BUF_SIZE];
    char permstr[BUF_SIZE];
    char cmd[BUF_SIZE];
    mode_t perm;

    while (1) {
        printf("\nMenu:\n");
        printf("1) Enter permissions (letters or digits) and show bit representation\n");
        printf("2) Enter file name and show permissions (letters, digits, bits)\n");
        printf("3) Change permissions (chmod emulation)\n");
        printf("0) Exit\n");
        printf("Your choice: ");
        if (!fgets(buf, sizeof(buf), stdin)) break;
        choice = atoi(buf);
        if (choice == 0) break;
        switch (choice) {
        case 1:
            printf("Enter permissions (e.g., rwxr-xr-- or 755): ");
            if (!fgets(permstr, sizeof(permstr), stdin)) break;
            permstr[strcspn(permstr, "\n")] = 0;
            perm = permission(permstr);
            printf("Bit representation: ");
            printBits(perm);
            break;
        case 2:
            printf("Enter file name: ");
            if (!fgets(filename, sizeof(filename), stdin)) break;
            filename[strcspn(filename, "\n")] = 0;
            perm = infoFile(filename);
            printPerm(perm);
            break;
        case 3:
            printf("Enter file name: ");
            if (!fgets(filename, sizeof(filename), stdin)) break;
            filename[strcspn(filename, "\n")] = 0;
            printf("Enter permission change command (u+w, g-r, =755): ");
            if (!fgets(cmd, sizeof(cmd), stdin)) break;
            cmd[strcspn(cmd, "\n")] = 0;
            permissionChange(filename, cmd);
            break;
        default:
            printf("Unknown menu item.\n");
        }
    }
    return 0;
}