#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct khapta_s
{
    char *name;
    char *symbole;
    char *paris;
    int nb;
    struct khapta_s *next;
    struct khapta_s *before;
}khapta_s;

typedef struct de_list
{
    char *name;
    int value;
    struct de_list *next;
    struct de_list *before;
}de_list;

void de(void);
int main(int ac, char **av);
void pmu(void);
void print_list(khapta_s *player_list);
void help(void);
void win(char *symbole, khapta_s *player_list);
int error_paris(char *getline);
int error_symbole(char *symbole);
int error_cycle(char *getline);


#define CYAN "\033[01;34m"
#define RED "\033[00;31m"
#define GREEN "\033[00;32m"
#define YELLOW "\033[00;33m"
#define UNDERLINE "\033[04m"
#define NORMAL "\033[00m"
