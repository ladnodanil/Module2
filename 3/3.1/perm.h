#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#define N 9

void printBits(mode_t st_mode);
mode_t letterToPerm(char *letters);
mode_t numbersToPerm(char *numbers);
char *permToLetters(mode_t perm);

mode_t permission(char *permission);
mode_t infoFile(char *filename);

void printPerm(mode_t permission);
void permissionChange(char *filename, char *cmd);;