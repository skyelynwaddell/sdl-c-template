// window.h
#ifndef WINDOW_H
#define WINDOW_H

extern SDL_Window* window;
extern SDL_Renderer* renderer;

int window_init();
void window_destroy();

#endif