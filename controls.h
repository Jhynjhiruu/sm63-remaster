#ifndef CONTROLS_H
#define CONTROLS_H

struct key { bool isDown(int); };
struct Pointer { float _x, _y; };

bool KeyUP();
bool KeyTapUP();
bool KeyDOWN();
bool KeyTapDOWN();
bool KeyLEFT();
bool KeyTapLEFT();
bool KeyRIGHT();
bool KeyTapRIGHT();
bool KeySHIFT();
bool KeySPACE();
bool KeyZ();
bool KeyX();
bool KeySPIN();
bool KeyPlus();
bool KeyMinus();
bool KeyHome();

void ChangeFludd();

extern Pointer pointer;
extern key Key;

#endif