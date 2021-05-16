#include "khapta.h"

void print_list(khapta_s *player_list)
{
    for (; player_list != NULL; player_list = player_list->next) {
        printf("name == %s || symbole == %s || paris == %s || nb == %d\n ", player_list->name, player_list->symbole, player_list->paris, player_list->nb);
    }
}