#ifndef _LETTER_DEFS_H
#define _LETTER_DEFS_H

#ifndef _TYPEDEFS_H
#include "typedefs.h"
#endif // _TYPEDEFS_H


#define LETTER_WIDTH 3
#define LETTER_HEIGHT 5


static const vec2i letter_positions[28] = {
	{0, 0}, // A
	{1, 0}, // B
	{2, 0}, // C
	{3, 0}, // D
	{4, 0}, // E
	{5, 0}, // F
	{6, 0}, // G
	{0, 1}, // H
	{1, 1}, // I
	{2, 1}, // J
	{3, 1}, // K
	{4, 1}, // L
	{5, 1}, // M
	{6, 1}, // N
	{0, 2}, // O
	{1, 2}, // P
	{2, 2}, // Q
	{3, 2}, // R
	{4, 2}, // S
	{5, 2}, // T
	{6, 2}, // U
	{0, 3}, // V
	{1, 3}, // W
	{2, 3}, // X
	{3, 3}, // Y
	{4, 3}, // Z
	{5, 3}, // normal hyphen
	{6, 3}, // red/error hyphen
};


#define GET_LETTER_RECT(index) SDL_Rect{letter_positions[index].x*LETTER_WIDTH, letter_positions[index].y*LETTER_HEIGHT, LETTER_WIDTH, LETTER_HEIGHT}
#define SPRITE_SHEET_PATH "../lib/ABC 3x5.png"


#define LETTER_A	0
#define LETTER_B	1
#define LETTER_C	2
#define LETTER_D	3
#define LETTER_E	4
#define LETTER_F	5
#define LETTER_G	6
#define LETTER_H	7
#define LETTER_I	8
#define LETTER_J	9
#define LETTER_K	10
#define LETTER_L	11
#define LETTER_M	12
#define LETTER_N	13
#define LETTER_O	14
#define LETTER_P	15
#define LETTER_Q	16
#define LETTER_R	17
#define LETTER_S	18
#define LETTER_T	19
#define LETTER_U	20
#define LETTER_V	21
#define LETTER_W	22
#define LETTER_X	23
#define LETTER_Y	24
#define LETTER_Z	25
#define LETTER_NORMAL_HYPHEN	26
#define LETTER_ERROR_HYPHEN		27


#endif // _LETTER_DEFS_H
