#include <iostream>
#include <SDL3/SDL.h>

#include "typedefs.h"
#include "spritesheet_handling.h"

SDL_Rect find_character(const char chr, SDL_Texture* spritesheet, const char* spritesheet_string) {
	SDL_Rect character = { 0, 0, 0, 0 };
	int sw = 0;
	SDL_QueryTexture(spritesheet, NULL, NULL, &sw, &character.h);

	character.w = sw / strlen(spritesheet_string);
	
	bool found = false;
	for (int i = 0; i <= (signed int)strlen(spritesheet_string) - 1; i++) {
		if (chr == spritesheet_string[i]) {
			character.x = character.w * i;
			found = true;
		}
	}

	if (!found) character.x = -1;

	return character;
}
