#include "controls.h"
#include "game.h"

extern "C" {
   extern float m_sin(float);
   extern float m_cos(float);
   extern float m_round(float);
   extern float m_floor(float);
   extern float m_ceil(float);
   extern float m_abs(float);
   extern float m_sqrt(float);
   extern float m_fmod(float,float);
   void input(int,int);
  	void inputPt(int,int,int);
}

bool keysArray[255]={false};
Pointer pointer = {0,0};
key Key;

bool key::isDown(int keyCode) {
   return keysArray[keyCode];
}

void inputPt(int x, int y, int pointerDown)
{
   mousemoveX = x - pointer._x;
   mousemoveY = y - pointer._y;
   pointer._x = x;
   pointer._y = y;
}
void input(int keyCode, int Id)
{
	if (Id)
        keysArray[keyCode]=true;
	else
        keysArray[keyCode]=false;
   
   if(KeyHome())
      PauseGame = !PauseGame;
}

bool KeyUP()
{
   if(WiiMode == true)
   {
      if((mousemoveY + m_abs(mousemoveX / 2) < -30 && pointer._y < screensizeY/2) || pointer._y < screensizeY/4)
      {
         return true;
      }
   //   return false;
   }
   if(Key.isDown(38) || Key.isDown(65) || Key.isDown(83) || Key.isDown(68))
   {
        return true;
   }
   return false;
};
bool KeyDOWN()
{
   if(WiiMode == true)
   {
      if((mousemoveY - m_abs(mousemoveX / 2) > 30 && pointer._y > screensizeY/2) || pointer._y > screensizeY/4)
      {
         return true;
      }
   //   return false;
   }
   if(Key.isDown(40))
   {
      return true;
   }
   return false;
};
bool KeyLEFT()
{
   if(WiiMode == true)
   {
      if(pointer._x < screensizeX / 2 - screensizeX / 5 || (mousemoveX < -15 && pointer._x < screensizeX / 2 - screensizeX / 6) || (mousemoveX < -40 && pointer._x < screensizeX / 2 + screensizeX / 8))
      {
         return true;
      }
   //   return false;
   }
   if(Key.isDown(37))
   {
      return true;
   }
   return false;
};
bool KeyRIGHT()
{
   if(WiiMode == true)
   {
      if(pointer._x > screensizeX / 2 + screensizeX / 5 || (mousemoveX > 15 && pointer._x > screensizeX / 2 + screensizeX / 6) || (mousemoveX > 40 && pointer._x > screensizeX / 2 - screensizeX / 8))
      {
         return true;
      }
   //   return false;
   }
   if(Key.isDown(39))
   {
      return true;
   }
   return false;
};
bool KeyTapRIGHT()
{
   if(WiiMode == true)
   {
      if(pointer._x > screensizeX / 2 + screensizeX / 8 || (mousemoveX > 7 && pointer._x > screensizeX / 2 + screensizeX / 8) || (mousemoveX > 30 && pointer._x > screensizeX / 2 - screensizeX / 7))
      {
         return true;
      }
   //   return false;
   }
   return false;
};
bool KeyTapLEFT()
{
   if(WiiMode == true)
   {
      if(pointer._x < screensizeX / 2 - screensizeX / 8 || (mousemoveX > 7 && pointer._x < screensizeX / 2 - screensizeX / 8) || (mousemoveX > 30 && pointer._x < screensizeX / 2 - screensizeX / 7))
      {
         return true;
      }
   //   return false;
   }
   return false;
};
bool KeyTapDOWN()
{
   if(Key.isDown(222))
   {
      return true;
   }
   return false;
};
bool KeyTapUP()
{
   if(Key.isDown(186))
   {
      return true;
   }
   return false;
};
bool KeySPACE()
{
   if(WiiMode == true)
   {
      if(MouseDown == true)
      {
         return true;
      }
   //   return false;
   }
   if(Key.isDown(67) || Key.isDown(32))
   {
      return true;
   }
   return false;
};
bool KeyMinus()
{
   if(Key.isDown(34) || Key.isDown(189))
   {
      return true;
   }
   return false;
};
bool KeyPlus()
{
   if(Key.isDown(33) || Key.isDown(187))
   {
      return true;
   }
   return false;
};
bool KeyHome()
{
   if(WiiMode == true)
   {
      if(Key.isDown(80))
      {
         return true;
      }
   //   return false;
   }
   if(Key.isDown(80))
   {
      return true;
   }
   return false;
};
bool KeySHIFT()
{
   if(Key.isDown(16))
   {
      return true;
   }
   return false;
};
bool KeySPIN()
{
   if(Key.isDown(88))
   {
      return true;
   }
   return false;
};
bool KeyX()
{
   if(Key.isDown(88))
   {
      return true;
   }
   return false;
};
bool KeyZ()
{
   if(Key.isDown(90))
   {
      return true;
   }
   return false;
};

void ChangeFludd()
{
   //tellTarget(Char)
   //{
      bool fluddchanged = false;
      if(Fluddpow == 'N')
      {
         if(changeFludd == true && (FluddArray[Playinglevel][1] == true || SaveFluddH == true))
         {
            Fluddpow = 'H';
            fluddchanged = true;
         }
         else if(changeFludd == true && (FluddArray[Playinglevel][2] == true || SaveFluddR == true))
         {
            Fluddpow = 'R';
            fluddchanged = true;
         }
         else if(changeFludd == true && (FluddArray[Playinglevel][3] == true || SaveFluddT == true))
         {
            Fluddpow = 'T';
            fluddchanged = true;
         }
      }
      else if(Fluddpow == 'H')
      {
         if(changeFludd == true && (FluddArray[Playinglevel][2] == true || SaveFluddR == true))
         {
            Fluddpow = 'R';
            fluddchanged = true;
         }
         else if(changeFludd == true && (FluddArray[Playinglevel][3] == true || SaveFluddT == true))
         {
            Fluddpow = 'T';
            fluddchanged = true;
         }
         else if(changeFludd == true)
         {
            Fluddpow = 'N';
            fluddchanged = true;
         }
      }
      else if(Fluddpow == 'R')
      {
         if(changeFludd == true && (FluddArray[Playinglevel][3] == true || SaveFluddT == true))
         {
            Fluddpow = 'T';
            fluddchanged = true;
         }
         else if(changeFludd == true)
         {
            Fluddpow = 'N';
            fluddchanged = true;
         }
      }
      else if(Fluddpow == 'T')
      {
         if(changeFludd == true)
         {
            Fluddpow = 'N';
            fluddchanged = true;
         }
      }
      if(fluddchanged == true)
      {
         //Charsound = new Sound(this);
         //Charsound.attachSound("FluddSwitch");
         //Charsound.start(0,1);
         //Charsound.setVolume(CharVolume);
      }
   //}
};