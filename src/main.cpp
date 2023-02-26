#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>
#include <SDL3/SDL_ttf.h>

#include "typedefs.h"
#include "spritesheet_handling.h"

#define DEFAULT_BORDER_SIZE		20
#define DEFAULT_WINDOW_WIDTH	150
#define DEFAULT_WINDOW_HEIGHT	330
#define DEFAULT_WINDOW_WIDTH_WITH_BORDER	(DEFAULT_BORDER_SIZE + DEFAULT_WINDOW_WIDTH + DEFAULT_BORDER_SIZE)
#define DEFAULT_WINDOW_HEIGHT_WITH_BORDER	(DEFAULT_BORDER_SIZE + DEFAULT_WINDOW_HEIGHT + DEFAULT_BORDER_SIZE)
#define DEFAULT_WINDOW_TITLE	"ShowCharacter"

#define DEFAULT_PT_SIZE 250
#define TTF_FILEPATH	"../lib/JetBrainsMono-2.304/ttf/JetBrainsMonoNL-Regular.ttf"
#define SPRITESHEET_STRING "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890#,;.:-_<>[]()!? "


int main() {
	SDL_version ver;
	/* initializing SDL3 */
	if (SDL_Init(SDL_INIT_VIDEO)) printf("Failed to initialize SDL3!\n%s\n", SDL_GetError()), exit(EXIT_FAILURE);
	SDL_VERSION(&ver);
	printf("SDL %u.%u.%u\n", ver.major, ver.minor, ver.patch);

	/* initializing SDL3_image */
	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) printf("Failed to initialize SDL3_image!\n%s\n", IMG_GetError()), exit(EXIT_FAILURE);
	SDL_IMAGE_VERSION(&ver);
	printf("SDL_image %u.%u.%u\n", ver.major, ver.minor, ver.patch);

	/* initializing SDL3_ttf */
	if (TTF_Init()) printf("Failed to initialize SDL3_ttf!\n%s\n", TTF_GetError()), exit(EXIT_FAILURE);
	SDL_TTF_VERSION(&ver);
	printf("SDL_ttf %u.%u.%u\n", ver.major, ver.major, ver.patch);


	/* creating a window */
	SDL_Window* window = SDL_CreateWindow(DEFAULT_WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DEFAULT_WINDOW_WIDTH_WITH_BORDER, DEFAULT_WINDOW_HEIGHT_WITH_BORDER, NULL);
	if (!window) printf("Cannot create a window!\n%s\n", SDL_GetError()), exit(EXIT_FAILURE);

	/* creating a renderer */
	SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL, SDL_RENDERER_ACCELERATED);
	if (!renderer) printf("Cannot create a renderer!\n%s\n", SDL_GetError()), exit(EXIT_FAILURE);

	
	/* loading ttf file to a font */
	TTF_Font* font = TTF_OpenFont(TTF_FILEPATH, DEFAULT_PT_SIZE);
	if (!font) printf("Failed to load ttf file!\n%s\n", TTF_GetError());

	/* loading font to sprite sheet on a surface */
	SDL_Surface* spritesheet_surface = TTF_RenderUTF8_Blended(font, SPRITESHEET_STRING, SDL_Color{ 0xff, 0xff, 0xff, 0xff });
	if (!spritesheet_surface) printf("Cannot render fon sprite sheet!\n%s\n", TTF_GetError());

	/* copying surface content to a texture on the GPU */
	SDL_Texture* spritesheet = SDL_CreateTextureFromSurface(renderer, spritesheet_surface);
	if (!spritesheet) printf("Cannot create a texture!\n%s\n", SDL_GetError());

	/* the rectangle "letter" is the area on the texture where the letter is located */
	SDL_Rect letter = find_character('#', spritesheet, SPRITESHEET_STRING);
	/* the rectangle "draw_area" is the area the texture is copied on */
	const SDL_FRect draw_area = { DEFAULT_BORDER_SIZE, DEFAULT_BORDER_SIZE,
		DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT };


	/* entering the main loop */
	SDL_Event event;
	bool loop = true;
	while (loop) {
		/* clearing the screen */
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);
		if (letter.x < 0) SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0xff);
		SDL_RenderClear(renderer);

		if (letter.x >= 0) SDL_RenderTexture(renderer, spritesheet, &letter, &draw_area);

		SDL_RenderPresent(renderer);

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) 
				loop = false;
			else if (event.type == SDL_EVENT_KEY_DOWN) {
				switch (event.key.keysym.sym) {
				case SDLK_a:
					letter = find_character('a', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_b:
					letter = find_character('b', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_c:
					letter = find_character('c', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_d:
					letter = find_character('d', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_e:
					letter = find_character('e', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_f:
					letter = find_character('f', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_g:
					letter = find_character('g', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_h:
					letter = find_character('h', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_i:
					letter = find_character('i', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_j:
					letter = find_character('j', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_k:
					letter = find_character('k', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_l:
					letter = find_character('l', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_m:
					letter = find_character('m', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_n:
					letter = find_character('n', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_o:
					letter = find_character('o', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_p:
					letter = find_character('p', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_q:
					letter = find_character('q', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_r:
					letter = find_character('r', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_s:
					letter = find_character('s', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_t:
					letter = find_character('t', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_u:
					letter = find_character('u', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_v:
					letter = find_character('v', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_w:
					letter = find_character('w', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_x:
					letter = find_character('x', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_y:
					letter = find_character('y', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_z:
					letter = find_character('z', spritesheet, SPRITESHEET_STRING);
					break;


				case SDLK_1:
					letter = find_character('1', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_2:
					letter = find_character('2', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_3:
					letter = find_character('3', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_4:
					letter = find_character('4', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_5:
					letter = find_character('5', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_6:
					letter = find_character('6', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_7:
					letter = find_character('7', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_8:
					letter = find_character('8', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_9:
					letter = find_character('9', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_0:
					letter = find_character('0', spritesheet, SPRITESHEET_STRING);
					break;


				case SDLK_HASH:
					letter = find_character('#', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_COMMA:
					letter = find_character(',', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_SEMICOLON:
					letter = find_character(';', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_PERIOD:
					letter = find_character('.', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_COLON:
					letter = find_character(':', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_MINUS:
					letter = find_character('-', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_UNDERSCORE:
					letter = find_character('_', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_LESS:
					letter = find_character('<', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_GREATER:
					letter = find_character('>', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_LEFTBRACKET:
					letter = find_character('[', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_RIGHTBRACKET:
					letter = find_character(']', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_LEFTPAREN:
					letter = find_character('(', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_RIGHTPAREN:
					letter = find_character(')', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_EXCLAIM:
					letter = find_character('!', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_QUESTION:
					letter = find_character('?', spritesheet, SPRITESHEET_STRING);
					break;
				case SDLK_SPACE:
					letter = find_character(' ', spritesheet, SPRITESHEET_STRING);
					break;

				default:
					letter.x = -1;
				}
			}
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
