#include "khapta.h"

de_list *add_node(de_list *list, char *name)
{
    de_list *tmp = list;
    de_list *element = malloc(sizeof(*element));
    static int nb;
    nb = 1;
    element->name = malloc(sizeof(char) * strlen(name) + 1);
    element->name = strcpy(element->name, name);
    element->name[strlen(name) - 1] = '\0';
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

de_list *register_de_player(de_list *list)
{
    char *name = malloc(sizeof(char) * 128);
    char *rep = malloc(sizeof(char) * 1);
    size_t size = 0;

    while(1) {
        printf(YELLOW "Nom du joueur : " NORMAL);
        getline(&name, &size, stdin);
        list = add_node(list, name);
        size = 0;
        printf(YELLOW "Autre joueur ? (y/n) : " NORMAL); 
        size = 0;
        getline(&rep, &size, stdin);
        if (strcmp(rep, "n\n") == 0)
            break;
    }
    return (list);
}

void de(void)
{
    size_t size = 0;
    de_list *list = NULL;
    clock_t begin, end;
    double time_spent;
    unsigned int i;
    int j = 0;
    int cycle = 0;
    int value;
    char *char_cycle = malloc(sizeof(char) * 2);

    list = register_de_player(list);
    printf(YELLOW "combien de tour ? " NORMAL);
    getline(&char_cycle, &size, stdin);
    while (error_cycle(char_cycle) == 1)
            getline(&char_cycle, &size, stdin);
    cycle = atoi(char_cycle);
    srand(time(NULL));
    while (j != cycle) {
        begin = clock();
        for (; 1; i++) {
            time_spent = (double)(clock() - begin) / CLOCKS_PER_SEC;
            if (time_spent >= 10.0) {
                system("clear");
                printf(GREEN "cycle : %d\n" NORMAL, j + 1);
                for (de_list *tmp = list; tmp != NULL; tmp = tmp->next) {
                        value = rand() % 6;
                        (value == 0) ? value = 6:0;
                        printf(CYAN "%s == [%d]    " NORMAL, tmp->name, value);
                }
                printf("\n");   
                break;
            }
            i = 0;
        }
        end = clock();
        j++;
    }
}
