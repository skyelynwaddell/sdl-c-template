#include <SDL.h>
#include "../headers/global.h"
#include "../headers/defs.h"

int game_is_running = true;
int last_frame_time = 0;
float delta = 0.0;
int should_cap_fps = false;

Ball ball = { .x=20, .y=20, .width=16, .height=16 };

//Limits the frame rate to the #define FPS variable in defs.h
//to be called every game tick
void fps_cap()
{
    int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);
    if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME)
    {
        SDL_Delay(time_to_wait);
    }
}

// Calculates and returns delta time
float delta_calc_time()
{
    //Cap framerate if specified
    if (should_cap_fps) fps_cap();

    // get delta time factor converted to seconds
    delta = (SDL_GetTicks() - last_frame_time) / 1000.0f;
    last_frame_time = SDL_GetTicks(); 
    return delta;
}

// Quits the game 
void game_quit()
{
    game_is_running = false;
}