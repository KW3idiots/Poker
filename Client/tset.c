#include <stdio.h>
#include <stdlib.h>

#include "graphic.h"
#include "gameplay.h"

int main()
{
    while (1)
    {
        switch (get_menu_playmode())
        {
        case SINGLE:
            play_single(get_menu_capital());
            break;

        case ONLINE:
            break;

        case EXIT:
            exit(0);
            break;
        }
    }
    return 0;
}