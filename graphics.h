#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "game.h"

extern "C" {
	extern void drawRect(int,int,int,int,int);
	extern void ctxLine(int,int,int,int,int);
	extern void beginPath();
	extern void moveTo(float,float);
	extern void lineTo(float,float);
	extern void curveTo(float,float,float,float);
	extern void closePath();
	extern void fill(int);
	extern void stroke();
}

struct Vec2f { float x, y; };
struct Vec2i { int x, y; };
struct Image { int id, width, height; };


void draw();
void makePath(int);
void drawPath(Vec2f* pathNum, char* pathCom, int length);

void printText(std::string);

#endif