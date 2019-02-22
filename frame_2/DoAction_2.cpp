#include "../game.h"
#include <string>

extern "C" {
   extern float m_round(float);
   extern float m_abs(float);
   extern float m_sin(float);
   extern float m_cos(float);
   extern bool hitTestF(float,float);
}

bool invis::hitTest(float x, float y, bool n) {
   return false;
}
bool terrain::hitTest(float x, float y, bool n) {
   if (type=="Platforms") {
      return hitTestF(x, y);
   }
   return false;
}

float radiansToAngle(float a)
{
   a = 57.29577951308232 * a;
   return a;
};
float angleToRadians(float a)
{
   a = a / 180 * 3.141592653589793;
   return a;
};
float groundFriction(float a, float b, float c)
{
   int d;
   if(a > 0)
   {
      d = 1;
   }
   else
   {
      d = -1;
   }
   a = m_abs(a);
   a = a - b;
   if(a < 0)
   {
      a = 0;
   }
   a = a / c;
   a = a * d;
   return a;
};
void moveObject(float a, float b, entity c)
{
   c._x = c._x + a;
   c._y = c._y + b;
};
void moveObjectFromAngle(float a, float b, entity c)
{
   c._x = c._x + m_cos(angleToRadians(b)) * a;
   c._y = c._y + m_sin(angleToRadians(b)) * a;
};
void moveObjectFromRadians(float a, float b, entity c)
{
   c._x = c._x + m_cos(b) * a;
   c._y = c._y + m_sin(b) * a;
};
/*float shuffleArray(float a[], float b)
{
   d = a.push();
   int i = 0;
   while(i < b)
   {
      e = random(d);
      f = random(d);
      if(e !== f)
      {
         g = a[e];
         a[e] = a[f];
         a[f] = g;
      }
      i++;
   }
   return a;
};*/
void MoveAllPlats(float Yamount, float Xamount)
{
   Xamount = m_round(Xamount * 10) / 10;
   Yamount = m_round(Yamount * 10) / 10;
   if(m_abs(Yamount) > 0.1 || m_abs(Xamount) > 0.1)
   {
      Course.Platforms._y = Course.Platforms._y + Yamount;
      Course.Platforms._x = Course.Platforms._x + Xamount;
      Course.BPlatforms._y = Course.BPlatforms._y + Yamount;
      Course.BPlatforms._x = Course.BPlatforms._x + Xamount;
      Course.FrontGFX._y = Course.FrontGFX._y + Yamount;
      Course.FrontGFX._x = Course.FrontGFX._x + Xamount;
      Course.BackGFX._y = Course.BackGFX._y + Yamount;
      Course.BackGFX._x = Course.BackGFX._x + Xamount;
      Course.Water._y = Course.Water._y + Yamount;
      Course.Water._x = Course.Water._x + Xamount;
      Course.Lava._y = Course.Lava._y + Yamount;
      Course.Lava._x = Course.Lava._x + Xamount;
      Course.Puddle._y = Course.Puddle._y + Yamount;
      Course.Puddle._x = Course.Puddle._x + Xamount;
      Course.Ice._y = Course.Ice._y + Yamount;
      Course.Ice._x = Course.Ice._x + Xamount;
      Course.Edge._y = Course.Edge._y + Yamount;
      Course.Edge._x = Course.Edge._x + Xamount;
      Course.CamEdge._y = Course.CamEdge._y + Yamount;
      Course.CamEdge._x = Course.CamEdge._x + Xamount;
      BGCourse.BG._y = BGCourse.BG._y + Yamount / 10;
      BGCourse.BG._x = BGCourse.BG._x + Xamount / 10;
      MidBackground.BG._y = MidBackground.BG._y + Yamount / 5;
      MidBackground.BG._x = MidBackground.BG._x + Xamount / 5;
      BGCloseCourse.BG._y = BGCloseCourse.BG._y + Yamount / 2;
      BGCloseCourse.BG._x = BGCloseCourse.BG._x + Xamount / 2;

      //Char._y = Char._y + Yamount;
      //Char._x = Char._x + Xamount;

      Enemyhurt._y = Enemyhurt._y + Yamount;
      Enemyhurt._x = Enemyhurt._x + Xamount;
   }
};

// controls moved to controls.cpp