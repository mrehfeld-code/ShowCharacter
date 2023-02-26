#ifndef _SPRITESHEET_HANDLING_H
#define _SPRITESHEET_HANDLING_H

#ifndef __cplusplus
#define SPRITESHEET_HANDLING_EXPORT export
#else 
#define SPRITESHEET_HANDLING_EXPORT
#endif

SPRITESHEET_HANDLING_EXPORT SDL_Rect find_character(const char chr, SDL_Texture* spritesheet, const char* spritesheet_string);

#endif // _SPRITESHEET_HANDLING_H
