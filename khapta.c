#include "khapta.h"

int main(int ac, char **av)
{
    if (strcmp(av[1], "-de") == 0)
        de();
    if (strcmp(av[1], "-pmu") == 0)
        pmu();
    if (strcmp(av[1], "-h") == 0)
        help();
    return (0);
}