#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

void ip(char *IP_Src, char *Mask, char* N);

uint32_t randomIP();

char* ipToStr(uint32_t ip);

uint32_t parseIP(char *IP);