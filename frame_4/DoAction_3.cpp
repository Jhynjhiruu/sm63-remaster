#include "../game.h"
#include <string>

extern "C" {
    extern float m_round(float);
}

void FallSquish()
{
   //tellTarget(Char)
   //{
   float hurtfall;
   bool nohurt = false;
   if((attack == false || attackFrame == "land") && fallingyspeed >= 14.5 && yspeed > 10)
   {
      hurtfall = m_round((fallingyspeed - 14.5) * 3);
   }
   else if(fallingyspeed >= 21 && yspeed > 10 && attackFrame == "Ground")
   {
      hurtfall = m_round((fallingyspeed - 23) / 2);
   }
   else
   {
      nohurt = true;
   }
   if(fallingyspeed >= 15 && yspeed > 10 && hurtfallcount > 3 && nohurt != true)
   {
      hurtfall = max(hurtfall,1.0f);
      hurtfall = min(hurtfall,4.0f);
      CharHP = CharHP - hurtfall;
      attack = true;
      attackFrame = "Squish";
   }
   hurtfall = 0;
   fallingyspeed = 0;
   //}
}