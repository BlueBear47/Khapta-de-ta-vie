#include "khapta.h"

void win(char *symbole, khapta_s *player_list)
{
    system("clear");
    printf(CYAN"le %s a gagné donc :\n" NORMAL, symbole);
    for (; player_list != NULL; player_list = player_list->next) {
        if (strcmp(player_list->symbole, symbole) == 0) {
            if (strcmp(player_list->paris, "cul sec") != 0)
                printf(GREEN "%s tu distribue %s gorgées\n" NORMAL, player_list->name, player_list->paris);
            else
                printf(GREEN "%s tu distribue un %s\n" NORMAL, player_list->name, player_list->paris);
        } else {
             if (strcmp(player_list->paris, "cul sec") != 0)
                printf(RED "%s tu bois %s gorgées\n" NORMAL, player_list->name, player_list->paris);
            else
                printf(RED "%s tu bois un %s\n" NORMAL, player_list->name, player_list->paris);
        }
    }
}