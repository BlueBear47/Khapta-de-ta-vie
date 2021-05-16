#include "khapta.h"

khapta_s *create_node(khapta_s *player_list, char *name, char *paris, char *symbole)
{
    khapta_s *tmp = player_list;
    khapta_s *element = malloc(sizeof(*element));
    static int nb;
    nb = 1;
    element->name = malloc(sizeof(char) * strlen(name) + 1);
    element->paris = malloc(sizeof(char) * strlen(paris) + 1);
    element->symbole = malloc(sizeof(char) * strlen(symbole) + 1);
    element->name = strcpy(element->name, name);
    element->name[strlen(name) - 1] = '\0';
    element->paris = strcpy(element->paris, paris);
    element->paris[strlen(paris) - 1] = '\0';
    element->symbole = strcpy(element->symbole, symbole);
    element->symbole[strlen(symbole) - 1] = '\0';
    element->nb = nb;
    element->next = NULL;
    element->before = NULL;
    if (tmp == NULL)
        tmp = element;
    else {
        for (; tmp->next != NULL; tmp = tmp->next);
        element->before = tmp;
        tmp->next = element;
    }
    nb++;
    for (; tmp->before != NULL; tmp = tmp->before);
    return (tmp);
}

khapta_s *player_register(khapta_s *player_list)
{
    char *name = malloc(sizeof(char) * 128);
    char *symbole = malloc(sizeof(char) * 8);
    char *paris = malloc(sizeof(char) * 10);
    char *rep = malloc(sizeof(char) * 1);
    size_t size = 0;

    while (1) {
        printf(YELLOW "Nom du joueur : " NORMAL);
        getline(&name, &size, stdin);
        size = 0;
        printf(YELLOW "combien de gorgées : " NORMAL);
        size = 0;
        getline(&paris, &size, stdin);
        while (error_paris(paris) == 1)
            getline(&paris, &size, stdin);
        printf(YELLOW "quel symbole (pic / coeur / trefles / carreau) : " NORMAL);
        size = 0;
        getline(&symbole, &size, stdin);
        while(error_symbole(symbole) == 1)
            getline(&symbole, &size, stdin);
        player_list = create_node(player_list, name, paris, symbole);
        printf(YELLOW "Autre joueur ? (y/n) : " NORMAL); 
        size = 0;
        getline(&rep, &size, stdin);
        if (strcmp(rep, "n\n") == 0)
            break;
        name = NULL;
        symbole = NULL;
        paris = NULL;
        rep = NULL;
        size = 0;
    }
    return (player_list);
}

void pmu(void)
{
    int pic = 0, coeur = 0, trefles = 0, carreau = 0;
    int temp = 0;
    khapta_s *player_list = NULL;
    player_list = player_register(player_list);
    clock_t begin, end;
    double time_spent;
    unsigned int i;
    int j = 0;
   
    srand(time(NULL));
    while (pic < 15 && coeur < 15 && trefles < 15 && carreau < 15) {
        for (; 1; i++) {
            time_spent = (double)(clock() - begin) / CLOCKS_PER_SEC;
            if (time_spent >= 1.0) {
                system("clear");
                j++;
                temp = rand() % 4;
                (temp == 0 && 1 == j % 2) ? pic++, printf(RED"le pique a été tiré\n" NORMAL):0;
                (temp == 1 && 1 == j % 2) ? coeur++, printf(RED"le coeur a été tiré\n" NORMAL):0;
                (temp == 2 && 1 == j % 2) ? trefles++, printf(RED"le trèfle a été tiré\n" NORMAL):0;
                (temp == 3 && 1 == j % 2) ? carreau++, printf(RED"le carreau a été tiré\n" NORMAL):0;
                (temp == 0 && 0 == j % 2) ? pic++, printf("le pique a été tiré\n"):0;
                (temp == 1 && 0 == j % 2) ? coeur++, printf("le coeur a été tiré\n"):0;
                (temp == 2 && 0 == j % 2) ? trefles++, printf("le trèfle a été tiré\n"):0;
                (temp == 3 && 0 == j % 2) ? carreau++, printf("le carreau a été tiré\n"):0;
                begin = clock();
                printf("Pique[%d]            Coeur[%d]              Trefles[%d]              Carreau[%d]\n", pic, coeur, trefles, carreau);
                break;
                }
            }
        end = clock();
    }
    (pic == 15)?win("pic", player_list):0;
    (coeur == 15)?win("coeur", player_list):0;
    (trefles == 15)?win("trefles", player_list):0;
    (carreau == 15)?win("carreau", player_list):0;
}