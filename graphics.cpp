#include "controls.h"
#include "graphics.h"
#include "images.h"
#include <string>

extern "C" {
	extern void drawData();
	extern void drawImage(int,int,int,int);
	extern void drawNum(int,float,float,int);
}

void drawChar() {
	Image img;

	if (attackFrame == "Spin") {
		img = _1130;
	}
	else if (attackFrame == "Dive") {
		if (Char._xscale>0)
			img = _20378;
		else
			img = _378;
	}
	else {
		if (Char._xscale>0)
			img = _21033;
		else
			img = _1033;
	}

	drawRect(Char._x-Char.wide+Course._x, Char._y-Char.tall+Course._y, Char.wide*2, Char.tall, 0xBB4444); // Char hitbox for debugging
	drawImage(img.id, Char._x+Course._x-img.width/2, Char._y+Course._y-img.height, 1);
}

int pathColor = 0x00DD00; // temporary, for debugging and demo

// draws the ground collision shape on an offscreen canvas
void drawPath(Vec2f* pathNum, char* pathCom, int length) {
	char lastCom='M', curCom='M';
	beginPath();
	for (int i=0; i<length; i++) {
		if (pathCom[i]=='O') {
			curCom = lastCom;
		}
		else {
			lastCom = pathCom[i];
			curCom = pathCom[i];
		}
		switch(curCom) {
			case 'M':
				moveTo(pathNum[i].x,pathNum[i].y);
				break;
			case 'L':
				lineTo(pathNum[i].x,pathNum[i].y);
				break;
			case 'Q':				
				curveTo(pathNum[i].x,pathNum[i].y,pathNum[i+1].x,pathNum[i+1].y);
				i++;
				break;
			default:
				printText("error in level code");
				break;
		}
	}
	closePath();
	fill(pathColor);
	stroke();
	pathColor = 0xDD0000;
}

void drawGUI() {
	drawRect(screensizeX-60,screensizeY-110,50,WaterAmount/100,0x44FFFF); // Water amount and power
	drawRect(screensizeX-70,screensizeY-110,5,Power,0x009999);

	drawImage(_109.id,100,0,2); // Char health and power
	drawNum(CharHP,200,70,0x000000);
	drawNum(hpcoincount,200,30,0x000000);

	drawImage(_248.id,300,(20-_248.height/2)*2,2);
	drawNum(CharLives,300+_248.width*2,50,0x000000);

	drawImage(_196.id,400,(20-_196.height/2)*2,2);
	drawNum(TotalStars,400+_196.width*2,50,0x000000);

	drawImage(_1.id,500,(20-_1.height/2)*2,2); // Coins
	drawNum(coincount,500+_1.width*2,50,0x000000);
}

void draw() {
	drawRect(0, 0, 2000, 1000, 0xeeeeee); // solid background, in case background images don't load
	drawImage(_9797.id,0,-200,4); // static background image (temporary)
	drawData(); // draws the ground shape on the screen
	drawChar();
	drawGUI();
}
