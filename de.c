#include "khapta.h"

void de(void)
{
    int a , b;
    long long i = 0;
    srand(time(NULL));
    
    while (1) {
        if (i == 5000000000) {
            a = rand() % 6;
            b = rand() % 6;
            if (a == 0)
                a = 6;
            if (b == 0)
                b = 6;
            printf("alex = [%d] | teddy = [%d]\n", a, b);
            i = 0;
        }
        i++;
    }
}