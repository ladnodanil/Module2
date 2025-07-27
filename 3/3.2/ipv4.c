#include "ipv4.h"

void ip(char *IP_Src, char *Mask, char *N)
{
    uint32_t ip_src = parseIP(IP_Src);
    uint32_t mask = parseIP(Mask);
    uint32_t net_src = ip_src & mask;
    //printf("%s\n", ipToStr(ip_src & mask));
    int counter = 0;
    int num = atoi(N);
    srand(time(NULL));
    for (size_t i = 0; i < num; i++)
    {
        uint32_t ip_dst = randomIP();
        uint32_t net_dst = ip_dst & mask;
        char *ip_str = ipToStr(ip_dst);
        if ((net_dst ^ net_src) == 0)
        { 
            printf("[Local]    %s\n", ip_str);
            counter++;
        }
        free(ip_str);
    }
    printf("\nTraffic statistics:\n");
    printf("%d packets (%.2f%%) were intended for local subnet\n", 
           counter, (float)counter * 100.0 / num);
    printf("%d packets (%.2f%%) were intended for external networks\n", 
           num - counter, 100.0 - (float)counter * 100.0 / num);
}

uint32_t randomIP()
{
    uint8_t octets[4];
    for (size_t i = 0; i < 4; i++)
    {
        octets[i] = rand() % 256;
    }

    return (octets[0] << 24) | (octets[1] << 16) | (octets[2] << 8) | octets[3];
}

char *ipToStr(uint32_t ip) {
    uint8_t octets[4] = {
        (ip >> 24) & 0xFF,
        (ip >> 16) & 0xFF,
        (ip >> 8)  & 0xFF,
        ip & 0xFF
    };
    char *str = malloc(16); 
    if (!str) return NULL;
    
    snprintf(str, 16, "%d.%d.%d.%d", octets[0], octets[1], octets[2], octets[3]);
    return str;
}

uint32_t parseIP(char *IP)
{
    int octet[4];
    if (sscanf(IP, "%d.%d.%d.%d", &octet[0], &octet[1], &octet[2], &octet[3]) == 4)
    {
        return ((uint32_t)octet[0] << 24) | ((uint32_t)octet[1] << 16) | ((uint32_t)octet[2] << 8) | (uint32_t)octet[3];
    }
    else
    {
        perror("false ip\n");
    }
}
