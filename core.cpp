#include <string>
#include "graphics.h"
#include "game.h"
#include "controls.h"
#include "images.h"

extern "C" {
    void run(float);
	void dim(int,int);
	extern void anim(float);
	extern void reqDim();
	extern void addText(char);
	extern void logText();
}

void dim(int width, int height) {
	screensizeX = width;
	screensizeY = height;
}

void step(float dt) {
	CharCode();
}
void run(float dt) {
	if (!PauseGame)
		step(dt);
	draw();
}

int random(int x) {return 1;};

// printing strings from C++ to JS console
void printText(std::string text) {
	for(int i=0; i<text.length(); i++)
		addText(text[i]);
	logText();
}

int main() {
	printText("Module loaded succesfully.");
	reqDim();

	Course.Platforms.type = "Platforms";
	Course._x=0;
	Course._y=0;

	makePath(0);
	makeImages();

	Fluddpow = 'H';
	saveX = 100;
	saveY = 500;

	StartChar("1-1",saveX,saveY,0,0,100,CurrentPlayer,Fluddpow,"Fromwhite",true);

	anim(0);
	return 0;
}