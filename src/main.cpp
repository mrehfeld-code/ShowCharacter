#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>

#include "typedefs.h"
#include "letter_defs.h"

#define DEFAULT_BORDER_SIZE		20
#define DEFAULT_WINDOW_WIDTH	360
#define DEFAULT_WINDOW_HEIGHT	600
#define DEFAULT_WINDOW_WIDTH_WITH_BORDER	(DEFAULT_BORDER_SIZE + DEFAULT_WINDOW_WIDTH + DEFAULT_BORDER_SIZE)
#define DEFAULT_WINDOW_HEIGHT_WITH_BORDER	(DEFAULT_BORDER_SIZE + DEFAULT_WINDOW_HEIGHT + DEFAULT_BORDER_SIZE)
#define DEFAULT_WINDOW_TITLE	"ShowCharacter"


int main() {
	SDL_version ver;

	if (SDL_Init(SDL_INIT_VIDEO)) printf("Failed to initialize SDL3!\n%s\n", SDL_GetError()), exit(EXIT_FAILURE);
	SDL_VERSION(&ver);
	printf("SDL %u.%u.%u\n", ver.major, ver.minor, ver.patch);

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) printf("Failed to initialize SDL3_image!\n%s\n", IMG_GetError()), exit(EXIT_FAILURE);
	SDL_IMAGE_VERSION(&ver);
	printf("SDL_image %u.%u.%u\n", ver.major, ver.minor, ver.patch);

	SDL_Window* window = SDL_CreateWindow(DEFAULT_WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DEFAULT_WINDOW_WIDTH_WITH_BORDER, DEFAULT_WINDOW_HEIGHT_WITH_BORDER, NULL);
	if (!window) printf("Cannot create a window!\n%s\n", SDL_GetError()), exit(EXIT_FAILURE);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL, SDL_RENDERER_ACCELERATED);
	if (!renderer) printf("Cannot create a renderer!\n%s\n", SDL_GetError()), exit(EXIT_FAILURE);

	
	SDL_Texture* sprite_sheet = IMG_LoadTexture(renderer, SPRITE_SHEET_PATH);
	if (!sprite_sheet) printf("Failed to load sprite sheet from \"%s\"!\n%s\n", SPRITE_SHEET_PATH, IMG_GetError());

	SDL_Rect letter = GET_LETTER_RECT(LETTER_NORMAL_HYPHEN);
	SDL_FRect draw_area = { DEFAULT_BORDER_SIZE, DEFAULT_BORDER_SIZE, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT };

	SDL_Event event;
	bool loop = true;
	while (loop) {
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);
		SDL_RenderClear(renderer);

		SDL_RenderTexture(renderer, sprite_sheet, &letter, &draw_area);

		SDL_RenderPresent(renderer);

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) 
				loop = false;
			if (event.type == SDL_EVENT_KEY_DOWN) {
				switch (event.key.keysym.sym) {
				case SDLK_a:
					letter = GET_LETTER_RECT(LETTER_A);
					break;
				case SDLK_b:
					letter = GET_LETTER_RECT(LETTER_B);
					break;
				case SDLK_c:
					letter = GET_LETTER_RECT(LETTER_C);
					break;
				case SDLK_d:
					letter = GET_LETTER_RECT(LETTER_D);
					break;
				case SDLK_e:
					letter = GET_LETTER_RECT(LETTER_E);
					break;
				case SDLK_f:
					letter = GET_LETTER_RECT(LETTER_F);
					break;
				case SDLK_g:
					letter = GET_LETTER_RECT(LETTER_G);
					break;
				case SDLK_h:
					letter = GET_LETTER_RECT(LETTER_H);
					break;
				case SDLK_i:
					letter = GET_LETTER_RECT(LETTER_I);
					break;
				case SDLK_j:
					letter = GET_LETTER_RECT(LETTER_J);
					break;
				case SDLK_k:
					letter = GET_LETTER_RECT(LETTER_K);
					break;
				case SDLK_l:
					letter = GET_LETTER_RECT(LETTER_L);
					break;
				case SDLK_m:
					letter = GET_LETTER_RECT(LETTER_M);
					break;
				case SDLK_n:
					letter = GET_LETTER_RECT(LETTER_N);
					break;
				case SDLK_o:
					letter = GET_LETTER_RECT(LETTER_O);
					break;
				case SDLK_p:
					letter = GET_LETTER_RECT(LETTER_P);
					break;
				case SDLK_q:
					letter = GET_LETTER_RECT(LETTER_Q);
					break;
				case SDLK_r:
					letter = GET_LETTER_RECT(LETTER_R);
					break;
				case SDLK_s:
					letter = GET_LETTER_RECT(LETTER_S);
					break;
				case SDLK_t:
					letter = GET_LETTER_RECT(LETTER_T);
					break;
				case SDLK_u:
					letter = GET_LETTER_RECT(LETTER_U);
					break;
				case SDLK_v:
					letter = GET_LETTER_RECT(LETTER_V);
					break;
				case SDLK_w:
					letter = GET_LETTER_RECT(LETTER_W);
					break;
				case SDLK_x:
					letter = GET_LETTER_RECT(LETTER_X);
					break;
				case SDLK_y:
					letter = GET_LETTER_RECT(LETTER_Y);
					break;
				case SDLK_z:
					letter = GET_LETTER_RECT(LETTER_Z);
					break;
				case SDLK_SPACE:
				case SDLK_MINUS:
					letter = GET_LETTER_RECT(LETTER_NORMAL_HYPHEN);
					break;
				default:
					letter = GET_LETTER_RECT(LETTER_ERROR_HYPHEN);
					break;
				}
			}
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
