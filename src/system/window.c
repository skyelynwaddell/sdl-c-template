//window.c
#include <stdio.h>
#include <SDL.h>
#include "../headers/defs.h"
#include "../headers/window.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int window_init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error initializing SDL.\n");
        return false;
    };

    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED, //window x_pos
        SDL_WINDOWPOS_CENTERED, //window y_pos
        WINDOW_WIDTH, WINDOW_HEIGHT, 
        SDL_WINDOW_OPENGL
    );

    if (!window)
    {
        fprintf(stderr, "Error creating SDL window.\n");
        return false;
    }

    renderer = SDL_CreateRenderer(window, DISPLAY_DRIVER, false);
    if (!renderer)
    {
        fprintf(stderr, "Error creating SDL renderer.\n");
        return false;
    }

    printf("Game is running!\n"); 
    return true;
}

void window_destroy()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}