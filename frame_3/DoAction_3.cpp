#include "../game.h"
#include <string>

void ZoomoutCam()
{
   nullCam = true;
   coursescale2 = coursescale2 - 7;
   coursescale2 = coursescale2 * 0.9;
   MoveAllPlats(3,0);
};

void CharHit(float a, float b, float c, float d, float e, std::string f, bool g)
{
   if(blink <= 0 && Invincible != true && Invisible != true && CharHP >= 1 && !(attack == true && attackFrame == "Fall" && attackFrame == "Respawn" && attackFrame == "Faint" && attackFrame == "Drown") && playpause == false)
   {
      hurt = true;
      attack = false;
      blink = b;
      CharHP = CharHP - a;
      hpcoincount = 0;
      if(a > 0)
      {
         Char.yspeed = Char.yspeed * 0.5;
         Char.xspeed = Char.xspeed * 0.5;
         divewaitcount = 7;
      }
      else
      {
         Char.yspeed = Char.yspeed + c;
         Char.xspeed = Char.xspeed + d;
      }
      if(a > 0)
      {
         //attack = true;
         if(CharHP <= 0)
         {
            if(CurrentPlayer == "Char")
            {
               //Charsound = new Sound(this);
               //Charsound.attachSound("Char - Ohhhhh");
               //Charsound.start(0,1);
               //Charsound.setVolume(CharVolume);
            }
            else if(CurrentPlayer == "Char2")
            {
               //Charsound = new Sound(this);
               //Charsound.attachSound("Char2 - Faint");
               //Charsound.start(0,1);
               //Charsound.setVolume(CharVolume);
            }
         }
         if(g == true)
         {
            Char.yspeed = Char.yspeed + c;
            Char.xspeed = Char.xspeed + d;
            if(Char.xspeed * Char._xscale / 100 < 0)
            {
               attackFrame = "hurt3";
            }
            else
            {
               attackFrame = "hurt2";
            }
         }
         else
         {
            /*Char.setYspeed = c;
            Char.setXspeed = d;*/
            Char.yspeed = c;
            Char.xspeed = d;
            attackFrame = "hurt1";
         }
      }
      if(e > 0)
      {
         StunTime = e;
      }
      if(f != "none" && CharHP > 0)
      {
         if(/*f != undefined && */f != "")
         {
            //Charsound = new Sound(this);
            //Charsound.attachSound(f);
            //Charsound.start(0,1);
            //Charsound.setVolume(CharVolume);
         }
         else
         {
            int randomnum;
            //Charsound = new Sound(this);
            if(CurrentPlayer == "Char")
            {
               randomnum = random(2) + 1;
               if(randomnum == 1)
               {
                  //Charsound.attachSound("Char - Doh");
               }
               else if(randomnum == 2)
               {
                  //Charsound.attachSound("Char - Uh");
               }
               else if(randomnum == 3)
               {
               }
            }
            else if(CurrentPlayer == "Char2")
            {
               randomnum = random(2) + 1;
               if(randomnum == 1)
               {
                  //Charsound.attachSound("Lugi - Owowow!");
               }
               else if(randomnum == 2)
               {
                  //Charsound.attachSound("Char2 - Wah!");
               }
               else if(randomnum == 3)
               {
               }
            }
            //Charsound.start(0,1);
            //Charsound.setVolume(CharVolume);
         }
      } //
      if (CharHP <= 0)
      {
         LifeLost();
      }
   }
}

void Blackout()
{
   //attachMovie("Blackout","Transition",getNextHighestDepth(),{_x:screensizeX / 2,_y:screensizeY / 2});
};
void Blackin()
{
   //attachMovie("StarIn","Transition",getNextHighestDepth(),{_x:screensizeX / 2,_y:screensizeY / 2});
};
void Whiteout()
{
   //attachMovie("Whiteout","Transition",getNextHighestDepth(),{_x:screensizeX / 2,_y:screensizeY / 2});
};
void GetStarMusic1()
{
   /*StopBGsong();
   bgsong.stop();
   bgsong = new Sound(this);
   bgsong.attachSound("Star Swish");
   bgsong.start(0,1);
   bgsong.setVolume(BgVolume);*/
};
void GetStarMusic2()
{
   /*bgsong = new Sound(this);
   bgsong.attachSound("GetStar");
   bgsong.start(0,1);
   bgsong.setVolume(BgVolume);*/
};
void GetKeyMusic()
{
   /*StopBGsong();
   bgsong.stop();
   bgsong = new Sound(this);
   bgsong.attachSound("Char-gotkey");
   bgsong.start(0,1);
   bgsong.setVolume(BgVolume);*/
};
void PaintingSound()
{
   /*bgsong.stop();
   bgsong = new Sound(this);
   bgsong.attachSound("enter-painting");
   bgsong.start(0,1);
   bgsong.setVolume(BgVolume);*/
};
void PaintingSound2()
{
   /*bgsong.stop();
   bgsong = new Sound(this);
   bgsong.attachSound("exit-painting");
   bgsong.start(0,1);
   bgsong.setVolume(BgVolume);*/
};
void StopBGsong()
{
   /*bgsong.stop();
   bgsong = new Sound(this);
   bgsong.start(0,1);
   bgsong.setVolume(BgVolume);*/
};
void StartBossMusic()
{
   /*bgsong = new Sound();
   bgsong.attachSound("Boss Music");
   if(MuteBGMusic == false)
   {
      bgsong.start(0,999);
   }
   bgsong.setVolume(BgVolume);*/
};
void StartBoss64Music()
{
   /*bgsong = new Sound();
   bgsong.attachSound("Boss Music 64 - Intro");
   if(MuteBGMusic == false)
   {
      bgsong.start(0,1);
   }
   bgsong.setVolume(BgVolume);
   bgsong.onSoundComplete()
   {
      bgsong.attachSound("Boss Music 64 - Repeat");
      if(MuteBGMusic == false)
      {
         bgsong.start(0,999);
      }
      bgsong.setVolume(BgVolume);
   };*/
};
void PlayMusicAndIntro()
{
   /*if(SongIntro !== undefined && SongIntro !== "None")
   {
      StopBGsong();
      bgsong.stop();
      bgsong = new Sound(this);
      bgsong.attachSound(SongIntro);
      if(MuteBGMusic == false)
      {
         bgsong.start(0,1);
      }
      bgsong.setVolume(BgVolume);
      bgsong.onSoundComplete()
      {
         bgsong.attachSound(SongRepeat);
         if(MuteBGMusic == false)
         {
            bgsong.start(0,999);
         }
         bgsong.setVolume(BgVolume);
      };
   }
   else
   {
      StopBGsong();
      bgsong.stop();
      bgsong = new Sound(this);
      bgsong.attachSound(SongRepeat);
      if(MuteBGMusic == false)
      {
         bgsong.start(0,999);
      }
      bgsong.setVolume(BgVolume);
      bgsong.onSoundComplete()
      {
         bgsong.attachSound(SongRepeat);
         if(MuteBGMusic == false)
         {
            bgsong.start(0,999);
         }
         bgsong.setVolume(BgVolume);
      };
   }*/
};
void StartNewMusicAndIntroNoVar(std::string a, std::string b)
{
   /*StopBGsong();
   if(b !== undefined)
   {
      bgsong.stop();
      bgsong = new Sound(this);
      bgsong.attachSound(a);
      if(MuteBGMusic == false)
      {
         bgsong.start(0,1);
      }
      bgsong.setVolume(BgVolume);
      bgsong.onSoundComplete()
      {
         bgsong.attachSound(b);
         if(MuteBGMusic == false)
         {
            bgsong.start(0,999);
         }
         bgsong.setVolume(BgVolume);
      };
   }
   else
   {
      bgsong.stop();
      bgsong = new Sound(this);
      bgsong.attachSound(a);
      if(MuteBGMusic == false)
      {
         bgsong.start(0,999);
      }
      bgsong.setVolume(BgVolume);
      bgsong.onSoundComplete()
      {
         bgsong.attachSound(a);
         if(MuteBGMusic == false)
         {
            bgsong.start(0,999);
         }
         bgsong.setVolume(BgVolume);
      };
   }*/
};
void HazymazeCaveSongChange(int a)
{
   Invincible = false;
   Metal = false;
   Invisible = false;
   WingCap = false;
   PowerTimer = 0;
   /*timeinsong = bgsong.position / 1000;
   bgsong.stop();
   bgsong = new Sound(this);
   SongIntro = "None";
   if(a == 1)
   {
      bgsong.attachSound("HazyMazeCave-Haze");
      bgsong.onSoundComplete()
      {
         bgsong.attachSound("HazyMazeCave-Haze");
         if(MuteBGMusic == false)
         {
            bgsong.start(0,999);
         }
         bgsong.setVolume(BgVolume);
      };
   }
   else
   {
      bgsong.attachSound("HazyMazeCave-Rock");
      bgsong.onSoundComplete()
      {
         bgsong.attachSound("HazyMazeCave-Rock");
         if(MuteBGMusic == false)
         {
            bgsong.start(0,999);
         }
         bgsong.setVolume(BgVolume);
      };
   }
   if(MuteBGMusic == false)
   {
      bgsong.start(timeinsong,1);
   }
   bgsong.setVolume(BgVolume);*/
};
void BuoyBaseSongChange(int a)
{
   Invincible = false;
   Metal = false;
   Invisible = false;
   WingCap = false;
   PowerTimer = 0;
   /*timeinsong = bgsong.position / 1000;
   bgsong.stop();
   bgsong = new Sound(this);
   if(PlayingIntro == false)
   {
      SongIntro = "None";
      if(a == 1)
      {
         bgsong.attachSound("BuoyBaseGalaxy(Wet)-Repeat");
         bgsong.onSoundComplete()
         {
            bgsong.attachSound("BuoyBaseGalaxy(Wet)-Repeat");
            if(MuteBGMusic == false)
            {
               bgsong.start(0,999);
            }
            bgsong.setVolume(BgVolume);
         };
      }
      else
      {
         bgsong.attachSound("BuoyBaseGalaxy(Dry)-Repeat");
         bgsong.onSoundComplete()
         {
            bgsong.attachSound("BuoyBaseGalaxy(Dry)-Repeat");
            if(MuteBGMusic == false)
            {
               bgsong.start(0,999);
            }
            bgsong.setVolume(BgVolume);
         };
      }
   }
   else if(a == 1)
   {
      bgsong.attachSound("BuoyBaseGalaxy(Wet)-Intro");
      bgsong.onSoundComplete()
      {
         PlayingIntro = false;
         bgsong.attachSound("BuoyBaseGalaxy(Wet)-Repeat");
         if(MuteBGMusic == false)
         {
            bgsong.start(0,999);
         }
         bgsong.setVolume(BgVolume);
      };
   }
   else
   {
      bgsong.attachSound("BuoyBaseGalaxy(Dry)-Intro");
      bgsong.onSoundComplete()
      {
         PlayingIntro = false;
         bgsong.attachSound("BuoyBaseGalaxy(Dry)-Repeat");
         if(MuteBGMusic == false)
         {
            bgsong.start(0,999);
         }
         bgsong.setVolume(BgVolume);
      };
   }
   if(MuteBGMusic == false)
   {
      bgsong.start(timeinsong,1);
   }
   bgsong.setVolume(BgVolume);*/
};
void RemoveCourse()
{
   /*pointer.removeMovieClip(pointer);
   Stats.removeMovieClip(Stats);
   Course.removeMovieClip(Course);
   BGCourse.removeMovieClip(BGCourse);
   MidBackground.removeMovieClip(MidBackground);
   BGCloseCourse.removeMovieClip(BGCloseCourse);
   FarBackground.removeMovieClip(FarBackground);
   Blackout.removeMovieClip(Blackout);
   onEnterFrame = null;*/
};
void ReturnToTitle()
{
   PlayingLevelDesigner = false;
   Fluddpow = 'N';
   Starnamenum = 0;
   CalculateStars();
   CharHP = 8;
   WaterHP = 8;
   WaterAmount = TotalWater;
   Power = TotalPower;
   Restartcoins();
   RemoveCourse();
   newstar = false;
   LastItemGot = "";
   //gotoAndStop("Title");
};
void ReturnToCastle()
{
   /*switch(null)
   {
      case true:
         newstar = false;
         RemoveCourse();
         CreateLevelDesigner();
         Charsound.onSoundComplete = null;
         break;
      case true:
         SongIntro = "None";
         SongRepeat = "InsidetheCastleWalls";
         if(LastItemGot !== "BossKey1" && LastItemGot !== "BossKey2")
         {
            StartChar(PaintingPosition[Playinglevel][0],PaintingPosition[Playinglevel][1],PaintingPosition[Playinglevel][2],PaintingPosition[Playinglevel][1],PaintingPosition[Playinglevel][2],200,CurrentPlayer,"","StarIn");
         }
         else if(LastItemGot == "BossKey1")
         {
            StartChar("C-5",-450,50,-450,50,200,CurrentPlayer,"","StarIn");
         }
         else if(LastItemGot == "BossKey2")
         {
            StartChar("C-7",0,0,0,0,0,CurrentPlayer,"","StarIn");
         }
         Playinglevel = 0;
         onEnterFrame()
         {
            CharCode();
         };
         break;
      default:
         StartChar("Castle",0,-100,0,0,100,CurrentPlayer,"","StarIn",true);
         Playinglevel = 0;
         onEnterFrame()
         {
            CharCode();
         };
   }*/
};
void StartInsideofCastle()
{
   RemoveCourse();
   //gotoAndStop("Courseframe");
   StartChar("C-1",0,0,0,0,100,CurrentPlayer,Fluddpow,"StarIn",true);
   /*onEnterFrame()
   {
      CharCode();
   };*/
};
void StartBombombBattlefield()
{
   RemoveCourse();
   //gotoAndStop("Courseframe");
   StartChar("1-1",0,0,0,0,100,CurrentPlayer,Fluddpow,"Fromwhite",true);
   /*onEnterFrame()
   {
      CharCode();
   };*/
};
void StartHazyMazeCave()
{
   RemoveCourse();
   //gotoAndStop("Courseframe");
   StartChar("3-1",0,0,0,0,100,CurrentPlayer,Fluddpow,"Fromwhite",true);
   /*onEnterFrame()
   {
      CharCode();
   };*/
};
void StartNewCourse(std::string level, bool a, std::string b)
{
   if(a == true)
   {
      RemoveCourse();
   }
   //gotoAndStop("Courseframe");
   StartChar(level,0,0,0,0,100,CurrentPlayer,Fluddpow,b,true);
   /*onEnterFrame()
   {
      CharCode();
   };*/
};
void changecourse(std::string transition, std::string level, float a, float b, float c, float d, bool e)
{
   RemoveCourse();
   //gotoAndStop("Courseframe");
   /*if(e == undefined)
   {
      e = false;
   }*/
   StartChar(level,a,b,c,d,100,CurrentPlayer,Fluddpow,transition,e);
   /*onEnterFrame()
   {
      CharCode();
   };*/
   e = false;
};
void gotoCourseSelect(int level)
{
   Playinglevel = level;
   RemoveCourse();
   Restartcoins();
   /*gotoAndStop("CourseSelect");
   Transition.removeMovieClip(Transition);
   attachMovie("Fromwhite","Transition",getNextHighestDepth(),{_x:screensizeX / 2,_y:screensizeY / 2});
   bgsong.stop();
   bgsong = new Sound(this);
   bgsong.attachSound("Star Swish");
   bgsong.start(0,1);
   bgsong.setVolume(BgVolume);*/
};
void gotoMiniCourseSelect(int level)
{
   Playinglevelnum = level;
   Playinglevel = level + 8;
   RemoveCourse();
   Restartcoins();
   /*gotoAndStop("MiniCourseSelect");
   Transition.removeMovieClip(Transition);
   attachMovie("Fromwhite","Transition",getNextHighestDepth(),{_x:screensizeX / 2,_y:screensizeY / 2});
   bgsong.stop();
   bgsong = new Sound(this);
   bgsong.attachSound("Star Swish");
   bgsong.start(0,1);
   bgsong.setVolume(BgVolume);*/
};
void DoorTransition(std::string doorplace)
{/*
   if(doorplace == "XY")
   {
      Char._x = WarpPipeX + Course.BackGFX._x;
      Char._y = WarpPipeY + Course.BackGFX._y;
      Char.attack = false;
      //attachMovie("StarIn","Transition",getNextHighestDepth(),{_x:screensizeX / 2,_y:screensizeY / 2});
   }
   else if(doorplace == "inCastle")
   {
      StartInsideofCastle();
   }
   else if(doorplace == "outCastle")
   {
      RemoveCourse();
      //gotoAndStop("Courseframe");
      StartChar("Castle",0,50,0,50,150,CurrentPlayer,Fluddpow,"StarIn",true);
      onEnterFrame()
      {
         CharCode();
      };
   }
   else if(doorplace == "C-MR")
   {
      changecourse("StarIn","C-4-SC1",-674,-60,-674,-60);
   }
   else if(doorplace == "C-MR-back")
   {
      changecourse("StarIn","C-4",1260,0,1260,0);
   }
   else if(doorplace == "C-1-1")
   {
      changecourse("StarIn","C-1",0,0,0,0);
   }
   else if(doorplace == "Castle-02")
   {
      changecourse("StarIn","Castle",1400,390,1400,390,true);
   }
   else if(doorplace == "C-1-2")
   {
      changecourse("StarIn","C-1",-550,-60,-550,-60);
   }
   else if(doorplace == "C-1-3")
   {
      changecourse("StarIn","C-1",550,-60,550,-60);
   }
   else if(doorplace == "C-1-4")
   {
      changecourse("StarIn","C-1",0,-195,0,-195);
   }
   else if(doorplace == "C-1-5")
   {
      changecourse("StarIn","C-1",160,0,160,0);
   }
   else if(doorplace == "C-1-6")
   {
      changecourse("StarIn","C-1",-160,0,-160,0);
   }
   else if(doorplace == "C-1-7")
   {
      changecourse("StarIn","C-1",460,-200,460,-200);
   }
   else if(doorplace == "C-1-8")
   {
      changecourse("StarIn","C-1",-460,-200,-460,-200);
   }
   else if(doorplace == "C-1-9")
   {
      changecourse("StarIn","C-1",-390,-16,-390,-16);
   }
   else if(doorplace == "C-1-10")
   {
      changecourse("StarIn","C-1",390,-16,390,-16);
   }
   else if(doorplace == "C-2-1")
   {
      changecourse("StarIn","C-2",0,0,0,0);
   }
   else if(doorplace == "C-2-2")
   {
      changecourse("StarIn","C-2-2",0,0,0,0);
   }
   else if(doorplace == "C-3-1")
   {
      changecourse("StarIn","C-3",0,0,0,0);
   }
   else if(doorplace == "C-3-2")
   {
      changecourse("StarIn","C-3-2",0,0,0,0);
   }
   else if(doorplace == "C-4-1")
   {
      changecourse("StarIn","C-4",0,0,0,0);
   }
   else if(doorplace == "C-4-2")
   {
      changecourse("StarIn","C-4",-846,-406,-846,-400);
   }
   else if(doorplace == "C-4-L")
   {
      if(CurrentPlayer !== "Char2")
      {
         CurrentPlayer = "Char2";
      }
      else
      {
         CurrentPlayer = "Char";
      }
      changecourse("StarIn","C-4",1100,0,1100,0);
   }
   else if(doorplace == "C-4H-1")
   {
      changecourse("StarIn","C-4H",0,0,0,0);
   }
   else if(doorplace == "C-4H-2")
   {
      changecourse("StarIn","C-4H",0,0,382,-85);
   }
   else if(doorplace == "C-4H-sd")
   {
      changecourse("StarIn","C-4H",400,-365,400,-365);
   }
   else if(doorplace == "C-4H-3")
   {
      changecourse("StarIn","C-4H",0,-300,20,-575);
   }
   else if(doorplace == "C-5-1")
   {
      changecourse("StarIn","C-5",0,0,0,0);
   }
   else if(doorplace == "C-6-1")
   {
      changecourse("StarIn","C-6",250,0,250,0);
   }
   else if(doorplace == "C-6-2")
   {
      changecourse("StarIn","C-6",-250,0,-250,0);
   }
   else if(doorplace == "C-6-3")
   {
      changecourse("StarIn","C-6",0,-95,0,-95,true);
   }
   else if(doorplace == "C-6-4")
   {
      changecourse("StarIn","C-6",0,80,0,80);
   }
   else if(doorplace == "C-7-1")
   {
      changecourse("StarIn","C-7",0,0,0,0);
   }
   else if(doorplace == "C-7-2")
   {
      changecourse("StarIn","C-7",-820,12,-820,12);
   }
   else if(doorplace == "C-7-3")
   {
      changecourse("StarIn","C-7",610,40,610,40);
   }
   else if(doorplace == "C-8-1")
   {
      changecourse("StarIn","C-8",0,0,0,0);
   }
   else if(doorplace == "C-8-2")
   {
      changecourse("StarIn","C-8",784,-16,784,-16);
   }
   else if(doorplace == "C-8-3")
   {
      changecourse("StarIn","C-8",1201,45,1201,45,true);
   }
   else if(doorplace == "C-9-1")
   {
      changecourse("StarIn","C-9",0,0,0,0);
   }
   else if(doorplace == "C-9-2")
   {
      changecourse("StarIn","C-9",300,-185,300,-185);
   }
   else if(doorplace == "C-10-1")
   {
      changecourse("StarIn","C-10",0,0,0,0);
   }
   else if(doorplace == "C-10-2")
   {
      changecourse("StarIn","C-10",-223,0,-223,0);
   }
   else if(doorplace == "C-10-3")
   {
      changecourse("StarIn","C-10",720,-185,720,-185);
   }
   else if(doorplace == "C-10-sd")
   {
      changecourse("StarIn","C-10",-235,-575,-235,-575);
   }
   else if(doorplace == "C-10-D3")
   {
      changecourse("StarIn","C-10",-170,-512,-170,-512,true);
   }
   else if(doorplace == "C-10-D2")
   {
      changecourse("StarIn","C-10",-235,-512,-235,0);
   }
   else if(doorplace == "C-10-D1")
   {
      changecourse("StarIn","C-10",-297,-512,-297,0);
   }
   else if(doorplace == "C-11-1")
   {
      changecourse("StarIn","C-11",0,0,0,0);
   }
   else if(doorplace == "C-12-1")
   {
      changecourse("StarIn","C-12",0,0,0,0);
   }
   else if(doorplace == "C-12-2")
   {
      changecourse("StarIn","C-12",80,-250,80,-250);
   }
   else if(doorplace == "C-13-1")
   {
      changecourse("StarIn","C-13",0,0,0,0);
   }
   else if(doorplace == "C-O-1")
   {
      changecourse("StarIn","C-O",0,0,0,0,true);
   }
   else if(doorplace == "C-O-2")
   {
      changecourse("StarIn","C-O",300,0,-950,-363,true);
   }
   else if(doorplace == "C-Opening")
   {
      if(Star[39] == true)
      {
         changecourse("righttransition2","Castle",-1300,100,-1300,100);
      }
      else
      {
         bgsong.stop();
         gotoAndStop("Intro2");
         RemoveCourse();
      }
   }
   else if(doorplace == "4-1-1")
   {
      changecourse("StarIn","4-1",610,150,610,150);
   }
   else if(doorplace == "4-1-2")
   {
      changecourse("StarIn","4-1",-315,200,-315,200);
   }
   else if(doorplace == "4-1-3")
   {
      changecourse("StarIn","4-1",610,-810,610,-810);
   }
   else if(doorplace == "4-1-4")
   {
      changecourse("StarIn","4-1",245,-1010,245,-1010);
   }
   else if(doorplace == "4-1-5")
   {
      changecourse("StarIn","4-1",610,-1305,610,-1305);
   }
   else if(doorplace == "4-2-1")
   {
      changecourse("StarIn","4-2",0,0,0,0);
   }
   else if(doorplace == "4-2-2")
   {
      changecourse("StarIn","4-2",-400,0,-400,0);
   }
   else if(doorplace == "4-2-3")
   {
      changecourse("StarIn","4-2",-250,0,-250,0);
   }
   else if(doorplace == "4-2-4")
   {
      changecourse("StarIn","4-2",250,0,250,0);
   }
   else if(doorplace == "4-2-5")
   {
      changecourse("StarIn","4-2",400,0,400,0);
   }
   else if(doorplace == "4-2-6")
   {
      changecourse("StarIn","4-2",-400,-375,-400,-375);
   }
   else if(doorplace == "4-2-7")
   {
      changecourse("StarIn","4-2",-250,-375,-250,-375);
   }
   else if(doorplace == "4-2-8")
   {
      changecourse("StarIn","4-2",250,-375,250,-375);
   }
   else if(doorplace == "4-2-9")
   {
      changecourse("StarIn","4-2",400,-375,400,-375);
   }
   else if(doorplace == "4-2-10")
   {
      changecourse("StarIn","4-2",0,-610,0,-610);
   }
   else if(doorplace == "4-3-1")
   {
      changecourse("StarIn","4-3",0,20,0,20);
   }
   else if(doorplace == "4-3-2")
   {
      changecourse("StarIn","4-3",1300,20,1300,20);
   }
   else if(doorplace == "4-3-3")
   {
      changecourse("StarIn","4-3",0,-780,0,-780);
   }
   else if(doorplace == "4-3-4")
   {
      changecourse("StarIn","4-3",100,-1776,100,-1776);
   }
   else if(doorplace == "4-4-1")
   {
      changecourse("StarIn","4-4",0,20,0,20);
   }
   else if(doorplace == "4-4-2")
   {
      changecourse("StarIn","4-4",-1300,20,-1300,20);
   }
   else if(doorplace == "4-4-3")
   {
      changecourse("StarIn","4-4",0,-780,0,-780);
   }
   else if(doorplace == "4-4-4")
   {
      changecourse("StarIn","4-4",200,-1776,200,-1776);
   }
   else if(doorplace == "4-5-1")
   {
      changecourse("StarIn","4-5",-1300,20,-1300,20);
   }
   else if(doorplace == "4-5-2")
   {
      changecourse("StarIn","4-5",1300,20,1300,20);
   }
   else if(doorplace == "4-6-1")
   {
      changecourse("StarIn","4-6",0,0,0,0);
   }
   else if(doorplace == "4-6-2")
   {
      changecourse("StarIn","4-6",0,-480,0,-480);
   }
   else if(doorplace == "4-7-1")
   {
      changecourse("StarIn","4-7",0,0,0,0);
   }
   else if(doorplace == "4-7-2")
   {
      changecourse("StarIn","4-7",-150,-400,-150,-400);
   }
   else if(doorplace == "4-8-1")
   {
      changecourse("StarIn","4-8",-1350,100,-1350,100);
   }
   else if(doorplace == "4-8-2")
   {
      changecourse("StarIn","4-8",-800,100,-800,100);
   }
   else if(doorplace == "4-8-3")
   {
      changecourse("StarIn","4-8",0,0,0,0);
   }
   else if(doorplace == "4-8-4")
   {
      changecourse("StarIn","4-8",1200,100,1200,100);
   }
   else if(doorplace == "4-8-5")
   {
      changecourse("StarIn","4-8",800,100,800,100);
   }
   else if(doorplace == "4-9-1")
   {
      changecourse("StarIn","4-9",0,0,0,0);
   }
   else if(doorplace == "4-9-2")
   {
      changecourse("StarIn","4-9",-1450,0,-1450,0);
   }
   else if(doorplace == "4-9-3")
   {
      changecourse("StarIn","4-9",0,-1055,0,-1055);
   }
   else if(doorplace == "4-10-1")
   {
      changecourse("StarIn","4-10",-3090,-630,-3090,-630);
   }
   else if(doorplace == "4-11-1")
   {
      changecourse("StarIn","4-11",0,0,0,0,true);
   }
   else if(doorplace == "5-1-1")
   {
      changecourse("StarIn","5-1",620,150,620,150);
   }
   else if(doorplace == "5-1-2")
   {
      changecourse("StarIn","5-1",2980,-50,2980,-50);
   }
   else if(doorplace == "5-5")
   {
      changecourse("StarIn","5-5",0,0,0,0);
   }
   else if(doorplace == "5-7-1")
   {
      changecourse("StarIn","5-7",0,0,0,0);
   }
   else if(doorplace == "5-8-1")
   {
      changecourse("StarIn","5-8",0,0,0,0);
   }
   else if(doorplace == "6-5")
   {
      changecourse("StarIn","6-5",500,500,-600,666,true);
   }
   else if(doorplace == "7-6")
   {
      changecourse("StarIn","7-6",0,0,0,0,true);
   }
   else if(doorplace == "8-1-2")
   {
      changecourse("StarIn","8-1",4128,-10,4128,-10);
   }
   else if(doorplace == "8-2-1")
   {
      changecourse("StarIn","8-2",0,0,0,0);
   }
   else if(doorplace == "8-2-bleft")
   {
      changecourse("StarIn","8-2",-812,-114,-812,-114);
   }
   else if(doorplace == "8-2-bright")
   {
      changecourse("StarIn","8-2",760,-114,760,-114);
   }
   else if(doorplace == "8-2-uleft")
   {
      changecourse("StarIn","8-2",-1350,-420,-1350,-420,true);
   }
   else if(doorplace == "8-2-uright")
   {
      changecourse("StarIn","8-2",830,-420,830,-420);
   }
   else if(doorplace == "8-2-top")
   {
      changecourse("StarIn","8-2",0,-1090,0,-1090);
   }
   else if(doorplace == "8-3")
   {
      changecourse("StarIn","8-3",0,95,0,95);
   }
   else if(doorplace == "8-4")
   {
      changecourse("StarIn","8-4",0,95,0,95);
   }
   else if(doorplace == "8-5")
   {
      changecourse("StarIn","8-5",0,0,0,0,true);
   }
   else if(doorplace == "8-6")
   {
      changecourse("StarIn","8-6",0,0,0,0);
   }
   else if(doorplace == "8-7")
   {
      changecourse("StarIn","8-7",0,0,0,0);
   }
   else if(doorplace == "8-7bleft")
   {
      changecourse("StarIn","8-7",-468,20,-468,20);
   }
   else if(doorplace == "8-7bright")
   {
      changecourse("StarIn","8-7",468,20,468,20);
   }
   else if(doorplace == "8-7uleft")
   {
      changecourse("StarIn","8-7",-556,-577,-556,-577);
   }
   else if(doorplace == "8-7uright")
   {
      changecourse("StarIn","8-7",556,-577,556,-577);
   }
   else if(doorplace == "8-7utop")
   {
      changecourse("StarIn","8-7",0,-582,0,-582);
   }
   else if(doorplace == "8-8")
   {
      changecourse("StarIn","8-8",0,0,0,0);
   }
   else if(doorplace == "8-8u")
   {
      changecourse("StarIn","8-8",-656,-2620,-656,-2620);
   }
   else if(doorplace == "8-9")
   {
      changecourse("StarIn","8-9",0,0,0,0);
   }
   else if(doorplace == "8-9u")
   {
      changecourse("StarIn","8-9",0,0,0,0);
   }
   else if(doorplace == "8-10")
   {
      changecourse("StarIn","8-10",-290,0,-290,0);
   }
   else if(doorplace == "8-10-b")
   {
      changecourse("StarIn","8-10-b",-547,-1470,-547,-1470,true);
   }
   else if(doorplace == "8-10u")
   {
      changecourse("StarIn","8-10-b",-575,-1470,-575,-1470,true);
   }
   else if(doorplace == "8-11")
   {
      changecourse("StarIn","8-11",-170,30,-170,30,true);
   }
   else if(doorplace == "8-11u")
   {
      changecourse("StarIn","8-11",0,-820,0,-820,true);
   }
   else if(doorplace == "8-12")
   {
      changecourse("StarIn","8-12",0,0,0,0);
   }
   else if(doorplace == "8-12-Warp")
   {
      Fluddpow = 'N';
      StopBGsong();
      lvl8keyA = false;
      lvl8keyB = false;
      lvl8keyC = false;
      lvl8keyD = false;
      lvl8keyE = true;
      Playinglevel = 8;
      SongIntro = "BossTrapIntro";
      SongRepeat = "BossTrapRepeat";
      PlayMusicAndIntro();
      changecourse("StarIn","8-12",-192,-52,-192,-52);
   }
   else if(doorplace == "C-13-Warp")
   {
      Fluddpow = 'N';
      StopBGsong();
      lvl8keyA = false;
      lvl8keyB = false;
      lvl8keyC = false;
      lvl8keyD = false;
      lvl8keyE = true;
      Playinglevel = 0;
      SongIntro = "None";
      SongRepeat = "InsidetheCastleWalls";
      StartNewMusicAndIntroNoVar("BossPlan-Intro","BossPlan-Repeat");
      changecourse("StarIn","C-13",1066,-215,1066,-215);
   }
   else if(doorplace == "8-E2-2")
   {
      Fluddpow = 'N';
      changecourse("StarIn","8-E2-2",0,-200,0,-200,true);
   }
   else if(doorplace == "8-13")
   {
      changecourse("StarIn","8-13",0,0,0,0,true);
   }
   else if(doorplace == "8-E3-1")
   {
      changecourse("StarIn","8-E3-1",0,0,0,0,true);
   }
   else if(doorplace == "8-E5-1")
   {
      Restartcoins();
      Fluddpow = 'N';
      changecourse("StarIn","8-E5-1",-1693,-60,-1693,-60,true);
   }
   else if(doorplace == "8-E5-1-1")
   {
      Fluddpow = 'N';
      changecourse("StarIn","8-E5-1",-212,-25,-212,-25,true);
   }
   else if(doorplace == "9-02")
   {
      Restartcoins();
      Fluddpow = 'N';
      changecourse("StarIn","9-02",0,0,0,0,true);
   }
   else if(doorplace == "9-04")
   {
      Restartcoins();
      Fluddpow = 'N';
      changecourse("StarIn","9-04",0,0,0,0,true);
   }
   else if(doorplace == "9-06")
   {
      Restartcoins();
      Fluddpow = 'N';
      changecourse("StarIn","9-06",0,0,0,0,true);
   }
   else if(doorplace == "M1-2")
   {
      changecourse("StarIn","M1-2",-1465,-320,-1465,-320,true);
   }
   else if(doorplace == "M2-1-1")
   {
      changecourse("StarIn","M2-1",795,125,795,125);
   }
   else if(doorplace == "M2-2-1")
   {
      changecourse("StarIn","M2-2",0,0,0,0);
   }
   else if(doorplace == "BC-0")
   {
      gotoAndStop("BossBattle3");
      RemoveCourse();
   }
   else if(doorplace == "BC-1")
   {
      changecourse("StarIn","BC-1",0,0,0,0);
   }
   else if(doorplace == "C-4-SC1")
   {
      changecourse("StarIn","C-4-SC1",0,0,0,0);
   }
   else if(doorplace == "C-4-SC2")
   {
      changecourse("StarIn","C-4-SC1",0,-260,0,-260);
   }
   else if(doorplace == "C-4-SC1-back")
   {
      changecourse("StarIn","C-4",1164,0,1164,0);
   }
   else if(doorplace == "C-4-SC1-back2")
   {
      changecourse("StarIn","C-4",1036,0,1036,0);
   }
   else if(doorplace == "level1")
   {
      changecourse("StarIn","level1",0,0,0,0);
   }
   else
   {
      changecourse("StarIn","C-1",0,0,0,0);
   }*/
};
void StartLevel1()
{
   RemoveCourse();
   //gotoAndStop("Courseframe");
   StartChar("Level1",1200,-500,1200,0,40,CurrentPlayer,Fluddpow,"Fromwhite",false);
   /*onEnterFrame()
   {
      CharCode();
   };*/
};
void PlayBGSong(std::string song)
{
   /*bgsong.stop();
   bgsong.attachSound(song);
   bgsong.start(0,999);
   bgsong.setVolume(BgVolume);*/
};
void PlayMessage(std::string a)
{
   //Stats.Message.gotoAndPlay(1);
   //Stats.Message.mtext = a;
};
void PlayPicture(std::string a)
{
   //Stats.Picture.gotoAndPlay(1);
   //Stats.Picture.picturenum = a;
};
void StopMessage()
{
   //Stats.Message.gotoAndPlay(7);
};
void StopPicture()
{
   //Stats.Picture.gotoAndPlay(7);
};
void HitWall()
{/*
   tellTarget(Char)
   {
      if(attack == false || attackFrame != "hurt2")
      {
         hitwall = true;
         attack = true;
         Char.attackFrame = "hurt2";
         if(Char.xspeed > 0)
         {
            Char._xscale = -100;
         }
         else
         {
            Char._xscale = 100;
         }
         xspeed = 0;
         yspeed = 0;
         //Charsound = new Sound(this);
         if(CurrentPlayer == "Char")
         {
            //Charsound.attachSound("Char-Squish");
         }
         //Charsound.start(0,1);
         //Charsound.setVolume(CharVolume);
      }
   }*/
}
void LifeLost()
{ 
   Invincible = false;
   Metal = false;
   Invisible = false;
   WingCap = false;
   PowerTimer = 0;
   //CharStopBGsong();
   //if(PlayingLevelDesigner != true)
   //{
      if(TotalStars == 0)
      {
         CharLives = CharLives + 1;
      }
      CharLives = CharLives - 1;
      if(CharLives < 0)
      {
         CharLives = 4;
         newstar = true;
         //LastItemGot = "GameOver";
         //RemoveCourse();
         //ReturnToCastle();
      }
      else
      {
         //Char.attachMovie("LifeLost","LifeLost" + ChargetNextHighestDepth(),ChargetNextHighestDepth(),{_x:CharscreensizeX / 2,_y:CharscreensizeY / 2});
         ReviveChar(playingcourse,saveX,saveY);
         RemoveCourse();
         PauseGame = false;
      }
   //}
   /*else
   {
      Invincible = false;
      Metal = false;
      Invisible = false;
      WingCap = false;
      PowerTimer = 0;
      newstar = false;
      RemoveCourse();
      CreateLevelDesigner();
   }*/
}

void ReviveChar(std::string level, float a, float b)
{
   CharHP = 8;
   WaterHP = 8;
   WaterAmount = TotalWater/2;
   Power = 0;
   //gotoAndStop("Courseframe");
   StartChar(level,a,b,a,b,100,CurrentPlayer,Fluddpow,"StarIn",false);
   //attack = true;
   //attackFrame = "Respawn";
   //PlayMusicAndIntro();
      //CharCode();
}
void AreaTextClipF(std::string txt, std::string frame)
{
   //Stats.attachMovie("AreaTextClip","AreaTextClip",Stats.getNextHighestDepth(),{_x:225,_y:75,txt:txt,frame:frame});
};
void StartLevelDesigner(float num)
{
   RemoveCourse();
   //gotoAndStop("LDMenu");
};
