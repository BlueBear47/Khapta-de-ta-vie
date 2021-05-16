#include "khapta.h"

int error_paris(char *getline)
{
    if (strcmp(getline, "cul sec\n")!= 0) {
        for (int l = 0; getline[l] != '\n'; l++) {
            if (getline[l] < 48 || getline[l] > 57) {
                printf(YELLOW"ton nombre de gorgées est pas bon le frère remet stp : "NORMAL);
                return (1);
            }
        }
    }
    return (0);
}

int error_symbole(char *symbole)
{
    if (strcmp(symbole, "pic\n")== 0)
        return (0);
    if (strcmp(symbole, "coeur\n")== 0)
        return (0);
    if (strcmp(symbole, "trefles\n")== 0)
        return (0);
    if (strcmp(symbole, "carreau\n")== 0)
        return (0);
    printf(YELLOW"ton symbole est pas bon le frère remet stp : "NORMAL);
    return (1);
}