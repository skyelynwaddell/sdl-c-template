//main.c
#include <stdio.h>
#include <SDL.h>
#include "./headers/defs.h"
#include "./headers/global.h"
#include "./headers/window.h"

#include "./headers/init.h"
#include "./headers/input.h"
#include "./headers/update.h"
#include "./headers/draw.h"

void game_loop()
{
    input();
    delta_calc_time();
    update();
    draw();
    //draw_gui();
}

int main(int argc, char *argv[])
{
    game_is_running = window_init(); //create the game window
    init(); //initialize game settings

    while(game_is_running) game_loop(); //main game loop

    //program was terminated
    window_destroy();
    return 0;
}