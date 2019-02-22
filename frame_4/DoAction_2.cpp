#include "../game.h"
#include <string>

extern "C" {
    extern float m_sin(float);
    extern float m_cos(float);
    extern float m_round(float);
    extern float m_floor(float);
    extern float m_ceil(float);
    extern float m_abs(float);
    extern float m_sqrt(float);
    extern float m_atan2(float,float);
    extern float m_fmod(float,float);
}

void CharRotationCode()
{/*
   //tellTarget(Char)
   //{
      float rotation = _rotation;
      float distance = 5;
      frontpointX = Char._x - m_cos(angleToRadians(rotation)) * distance;
      frontpointY = Char._y - m_sin(angleToRadians(rotation)) * distance + 15;
      hitplatform = false;
      int i = 0;
      while(i < 9)
      {
         if(hitplatform == false && i <= 8)
         {
            frontpointY = frontpointY - 5;
         }
         coint = 0;
         /*while(!(Course.Platforms.hitTest(frontpointX * coursescale / 100 + Course._x,frontpointY * coursescale / 100 + Course._y,true) && (!Course.Platforms.invisground.hitTest(frontpointX * coursescale / 100 + Course._x,frontpointY * coursescale / 100 + Course._y,true) || Invisible != true)) && !Course.BPlatforms.hitTest(frontpointX * coursescale / 100 + Course._x,frontpointY * coursescale / 100 + Course._y,true) && (Course.Platforms.hitTest(frontpointX * coursescale / 100 + Course._x,(frontpointY + 7) * coursescale / 100 + Course._y,true) && (!Course.Platforms.invisground.hitTest(frontpointX * coursescale / 100 + Course._x,(frontpointY + 7) * coursescale / 100 + Course._y,true) || Invisible != true) || Course.BPlatforms.hitTest(frontpointX * coursescale / 100 + Course._x,(frontpointY + 7) * coursescale / 100 + Course._y,true)))
         {
            frontpointY++;
            hitplatform = true;
            smcount++;
            if(smcount > 50)
            {
               break;
            }
         }*/
        // coint = 0;
         /*while(Course.Platforms.hitTest(frontpointX * coursescale / 100 + Course._x,frontpointY * coursescale / 100 + Course._y,true) && (!Course.Platforms.invisground.hitTest(frontpointX * coursescale / 100 + Course._x,frontpointY * coursescale / 100 + Course._y,true) || Invisible != true) || Course.BPlatforms.hitTest(frontpointX * coursescale / 100 + Course._x,frontpointY * coursescale / 100 + Course._y,true))
         {
            frontpointY--;
            hitplatform = true;
            smcount++;
            if(smcount > 50)
            {
               break;
            }
         }*/
         /*if(hitplatform == true)
         {
            break;
         }
         if(i >= 8)
         {
            frontpointX = Char._x - m_cos(angleToRadians(rotation)) * distance;
            frontpointY = Char._y - m_sin(angleToRadians(rotation)) * distance;
         }
         i++;
      }
      float backpointX = Char._x + m_cos(angleToRadians(rotation)) * distance;
      float backpointY = Char._y - m_sin(angleToRadians(rotation)) * distance + 15;
      hitplatform = false;
      i = 0;
      while(i < 9)
      {
         if(hitplatform == false && i <= 8)
         {
            backpointY = backpointY - 5;
         }
         coint = 0;
         /*while(!(Course.Platforms.hitTest(backpointX * coursescale / 100 + Course._x,backpointY * coursescale / 100 + Course._y,true) && (!Course.Platforms.invisground.hitTest(backpointX * coursescale / 100 + Course._x,backpointY * coursescale / 100 + Course._y,true) || Invisible != true)) && !Course.BPlatforms.hitTest(backpointX * coursescale / 100 + Course._x,backpointY * coursescale / 100 + Course._y,true) && (Course.Platforms.hitTest(backpointX * coursescale / 100 + Course._x,(backpointY + 7) * coursescale / 100 + Course._y,true) && (!Course.Platforms.invisground.hitTest(backpointX * coursescale / 100 + Course._x,(backpointY + 7) * coursescale / 100 + Course._y,true) || Invisible != true) || Course.BPlatforms.hitTest(backpointX * coursescale / 100 + Course._x,(backpointY + 7) * coursescale / 100 + Course._y,true)))
         {
            backpointY++;
            hitplatform = true;
            smcount++;
            if(smcount > 50)
            {
               break;
            }
         }*/
         //coint = 0;
         /*while(Course.Platforms.hitTest(backpointX * coursescale / 100 + Course._x,backpointY * coursescale / 100 + Course._y,true) && (!Course.Platforms.invisground.hitTest(backpointX * coursescale / 100 + Course._x,backpointY * coursescale / 100 + Course._y,true) || Invisible != true) || Course.BPlatforms.hitTest(backpointX * coursescale / 100 + Course._x,backpointY * coursescale / 100 + Course._y,true))
         {
            backpointY--;
            hitplatform = true;
            smcount++;
            if(smcount > 50)
            {
               break;
            }
         }*/
         /*if(hitplatform == true)
         {
            break;
         }
         if(i >= 8)
         {
            backpointX = Char._x + m_cos(angleToRadians(rotation)) * distance;
            backpointY = Char._y - m_sin(angleToRadians(rotation)) * distance;
         }
         i++;
      }
      rotation = radiansToAngle(m_atan2(backpointY - frontpointY,backpointX - frontpointX));
      float groundrot = rotation;
      float speedslide = m_sin(angleToRadians(rotation));
      speedslide = max(speedslide,-0.5f);
      speedslide = min(speedslide,0.5f);
      if(Ice == true)
      {
         xspeed = xspeed + speedslide * 0.3;
      }
      else if(Puddle == true)
      {
         xspeed = xspeed + speedslide * 0.1;
      }
      _rotation = _rotation + (rotation / 2 - _rotation) / 2;
      if(m_abs(rotation) > 25 && Ice == true)
      {
         if(icedive == true)
         {
            attack = true;
            attackFrame = "Dive";
         }
         icedive = true;
      }
      else
      {
         icedive = false;
      }
   //}*/
};
