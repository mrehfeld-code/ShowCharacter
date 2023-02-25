#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>

#define DEFAULT_WINDOW_WIDTH 1600
#define DEFAULT_WINDOW_HEIGHT 900
#define DEFAULT_WINDOW_TITLE "ShowCharacter"

int main() {
	if (SDL_Init(SDL_INIT_VIDEO)) printf("Failed to initialize SDL3!\n%s\n", SDL_GetError()), exit(EXIT_FAILURE);

	SDL_Window* window = SDL_CreateWindow(DEFAULT_WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, NULL);
	if (!window) printf("Cannot create a window!\n%s\n", SDL_GetError()), exit(EXIT_FAILURE);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL, SDL_RENDERER_ACCELERATED);
	if (!renderer) printf("Cannot create a renderer!\n%s\n", SDL_GetError()), exit(EXIT_FAILURE);

	SDL_Event event;
	bool loop = true;
	while (loop) {
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);
		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) 
				loop = false;
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
