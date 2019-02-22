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
    extern float m_fmod(float,float);
}

void StartChar(std::string a, float b, float c, float d, float e, float f, std::string g, char h, std::string i, bool resetmusic) // starts a course // g unused
{
   playingcourse = a;
   if(Starnamenum == 0)
   {
      //AreaTextAppear = true;
   }
   //CinemaMessage = 'N';
   //CinemaMessageFrame = 1;
   TextHint = 'N';
   ToadMessage = 'N';
   //if(_root[a + "Gravity"] == undefined)
   //{
      gravity = 1;
   //}
   //else
   //{
   //   gravity = _root[a + "Gravity"];
   //}
   //if(_root[a + "defaultstep"] == undefined)
   //{
      //defaultstep = "Char-Step";
   //}
   //else
   //{
   //   defaultstep = _root[a + "defaultstep"];
   //
   //attachMovie(_root[a + "FarBackground"],"FarBackground",getNextHighestDepth(),{_x:screensizeX / 2,_y:screensizeY / 2});
   //createEmptyMovieClip("BGCourse",getNextHighestDepth());
   //BGCourse._y = screensizeY / 2;
   //BGCourse._x = screensizeX / 2;
   //BGCourse.attachMovie(_root[a + "Background"],"BG",BGCourse.getNextHighestDepth(),{_x:(- b) / 10,_y:(- c) / 10});
   //createEmptyMovieClip("MidBackground",getNextHighestDepth());
   //MidBackground._y = screensizeY / 2;
   //MidBackground._x = screensizeX / 2;
   //MidBackground.attachMovie(_root[a + "MidBackground"],"BG",MidBackground.getNextHighestDepth(),{_x:(- b) / 5,_y:(- c) / 5});
   //createEmptyMovieClip("BGCloseCourse",getNextHighestDepth());
   //BGCloseCourse._y = screensizeY / 2;
   //BGCloseCourse._x = screensizeX / 2;
   //BGCloseCourse.attachMovie(_root[a + "CloseBackground"],"BG",BGCloseCourse.getNextHighestDepth(),{_x:(- b) / 2,_y:(- c) / 2});
   //createEmptyMovieClip("Course",getNextHighestDepth());
   //Course._y = screensizeY / 2;
   //Course._x = screensizeX / 2;
   Course._x = 0;
   Course._y = 0;
   Char._x = b;
   Char._y = c;
   _X = b;
   _Y = c;
   b = - b;
   c = - c;
   d = - d;
   e = - e;
   //Course.attachMovie(a + "Puddle","Puddle",Course.getNextHighestDepth(),{_x:b,_y:c});
   //Course.attachMovie(a + "Ice","Ice",Course.getNextHighestDepth(),{_x:b,_y:c});
   //Course.attachMovie(a + "BackGFX","BackGFX",Course.getNextHighestDepth(),{_x:b,_y:c});
   //Course.attachMovie(a + "Platforms","Platforms",Course.getNextHighestDepth(),{_x:b,_y:c,_visible:false});
   //Course.attachMovie(a + "BPlatforms","BPlatforms",Course.getNextHighestDepth(),{_x:b,_y:c,_visible:false});
   //Course.attachMovie("Char","Char",Course.getNextHighestDepth(),{_x:b - d,_y:c - e});
   //Course.attachMovie(a + "Water","Water",Course.getNextHighestDepth(),{_x:b,_y:c});
   //Course.attachMovie(a + "Lava","Lava",Course.getNextHighestDepth(),{_x:b,_y:c,_visible:false});
   //Course.attachMovie(a + "FrontGFX","FrontGFX",Course.getNextHighestDepth(),{_x:b,_y:c});
   //if(Course.FrontGFX._x == undefined)
   //{
      //Course.createEmptyMovieClip("FrontGFX",Course.getNextHighestDepth());
      //Course.FrontGFX._x = b;
      //Course.FrontGFX._y = c;
   //}
   //Course.attachMovie(a + "Edge","Edge",Course.getNextHighestDepth(),{_x:b,_y:c,_alpha:0});
   //Course.attachMovie(a + "CamEdge","CamEdge",Course.getNextHighestDepth(),{_x:b,_y:c,_alpha:0});
   //Course.createEmptyMovieClip("Enemyhurt",Course.getNextHighestDepth());
   //Enemyhurt._x = b;
   //Enemyhurt._y = c;
   //Course.BackGFX.createEmptyMovieClip("StartClip",Course.BackGFX.getNextHighestDepth());
   /*Course.BackGFX.StartClip._y = Char._y - Course.BackGFX._y;
   Course.BackGFX.StartClip._x = Char._x - Course.BackGFX._x;
   StartY = Course.BackGFX.StartClip._y - Course.BackGFX._y;
   StartX = Course.BackGFX.StartClip._x - Course.BackGFX._x;
   *///tellTarget(Char)
   //{
      Char.tall = 35;
      Char.wide = 10;
      Char.yspeed = 0;
      Char.xspeed = 0;
      air = true;
      frame = 1;
      lockon = true;
      Ice = false;
      Puddle = false;
      Water = false;
      attack = false;
      attackFrame = 'N';
      DiveRot = 0;
      hurt = false;
      blink = 0;
      StunTime = 0;
      doublejump = 0;
      doublejumpcount = 0;
      playpause = false;
      spinattackcount = 0;
      spincount = 0;
      spinattackcounter = 0;
      Squish = false;
      underwatercount = 0;
      abovewatercount = 0;
      swimup = false;
      changeFludd = false;
      canChangeFludd = true;
      landtime = 0;
      fallcount = 0;
      hurtfallcount = 0;
      divewaitcount = 7;
      swimupcount = 0;
      swimup = false;
      JumpPress = false;
      LastFrameJumpPress = false;
      _xscale = CharXscale;
   //}
   //Camcenter = Char;
   Controll = true;
   /*CameraZoom = 100;
   coursescale2 = f - 100;
   coursescale = coursescale2;
   CameraZoom2 = CameraZoom;
   CamYchange = 50;
   CamXchange = 0;
   StepSound = defaultstep;
   changestep = 0;*/
   Fluddpow = h;
   CanSwitchFludd = true;
   //if(_root[a + "Maxzoomout"] == undefined)
   //{
      //Maxzoomout = 50;
   //}
   //else
   //{
   //   Maxzoomout = _root[a + "Maxzoomout"];
   //}
   //if(_root[a + "Maxzoomin"] == undefined)
   //{
      //Maxzoomin = 200;
   //}
   //else
   //{
   //   Maxzoomin = _root[a + "Maxzoomin"];
   //}
   //attachMovie("Stats Clip","Stats",getNextHighestDepth(),{_x:0,_y:0});
   //attachMovie(i,"Transition",getNextHighestDepth(),{_x:screensizeX / 2,_y:screensizeY / 2});
   //attachMovie("Pointer","pointer",getNextHighestDepth(),{_x:screensizeX / 2,_y:screensizeY / 2});
   if(CurrentPlayer == "Char")
   {
      //Char.gotoAndStop(1);
      jumpspeed = Charjumpspeed;
   }
   if(CurrentPlayer == "Char2")
   {
      //Char.gotoAndStop(4);
      jumpspeed = Char2jumpspeed;
   }
   AntiSquish = 0;
   std::string PlayingChar = CurrentPlayer;
   if(resetmusic == true)
   {
      Invincible = false;
      Metal = false;
      Invisible = false;
      WingCap = false;
      PowerTimer = 0;
      /*if(_root[a + "MusicIntro"] != undefined && _root[a + "MusicIntro"] != "None")
      {
         //StopBGsong();
         //bgsong.stop();
         //bgsong = new Sound(this);
         //bgsong.attachSound(_root[a + "MusicIntro"]);
         if(MuteBGMusic == false)
         {
            //bgsong.start(0,1);
         }
         //bgsong.setVolume(BgVolume);
         //SongIntro = _root[a + "MusicIntro"];
         //SongRepeat = _root[a + "Music"];
         PlayingIntro = true;
         bgsong.onSoundComplete = function()
         {
            PlayingIntro = false;
            bgsong.attachSound(_root[a + "Music"]);
            if(MuteBGMusic == false)
            {
               bgsong.start(0,999);
            }
            bgsong.setVolume(BgVolume);
         };
      }
      else
      {
         PlayingIntro = false;
         SongIntro = "None";
         SongRepeat = _root[a + "Music"];
         StopBGsong();
         bgsong.stop();
         bgsong = new Sound(this);
         bgsong.attachSound(_root[a + "Music"]);
         if(MuteBGMusic == false)
         {
            bgsong.start(0,999);
         }
         bgsong.setVolume(BgVolume);
         bgsong.onSoundComplete = function()
         {
            PlayingIntro = false;
            bgsong.attachSound(_root[a + "Music"]);
            if(MuteBGMusic == false)
            {
               bgsong.start(0,999);
            }
            bgsong.setVolume(BgVolume);
         };
      }*/
   }
}
void CharCode()
{
   //bgsong.setVolume(BgVolume);
   //lastcoinsound = lastcoinsound - 1;
   //lastcoinsound = max(lastcoinsound,0.0f);
   /*StartY = Course.BackGFX.StartClip._y + Course.BackGFX._y;
   StartX = Course.BackGFX.StartClip._x + Course.BackGFX._x;
   Power = min(Power,TotalPower);
   Power = max(Power,0.0f);
   WaterAmount = min(WaterAmount,TotalWater);
   WaterAmount = max(WaterAmount,0.0f);
   Course._yscale = coursescale;
   Course._xscale = coursescale;*/
   /*BGCourse._yscale = (coursescale - 100) / 5 + 100;
   BGCourse._xscale = (coursescale - 100) / 5 + 100;
   MidBackground._yscale = (coursescale - 100) / 2 + 100;
   MidBackground._xscale = (coursescale - 100) / 2 + 100;
   BGCloseCourse._yscale = (coursescale - 100) / 1 + 100;
   BGCloseCourse._xscale = (coursescale - 100) / 1 + 100;*/
   /*Waterpercent = WaterAmount / TotalWater * 100;
   Powerpercent = Power / TotalPower * 100;
   if(KeyPlus())
   {
      CameraZoom = CameraZoom + 2;
   }
   if(KeyMinus())
   {
      CameraZoom = CameraZoom - 2;
   }
   while(coincount >= 100)
   {
      coincount = coincount - 100;
      CharLives = CharLives + 1;
      //Course.FrontGFX.attachMovie("1upAnimation","1up" + Course.FrontGFX.getNextHighestDepth(),Course.FrontGFX.getNextHighestDepth(),{_x:Char._x - Course.FrontGFX._x,_y:Char._y - Course.FrontGFX._y});
   }
   while(hpcoincount >= 5 && CharHP < 8)
   {
      hpcoincount = hpcoincount - 5;
      CharHP = CharHP + 1;
      hpcoinplay = true;
   }
   hpcoincount = min(hpcoincount,5.0f);
   if(Invincible == true)
   {
      CharHP = CharHP + 1;
   }
   CharHP = min(CharHP,8.0f);
   if(CharHP == 8)
   {
      hpcoincount = 0;
   }
   //tellTarget(Char)
   //{
      if(CurrentPlayer == "Char")
      {
         if(Fluddpow == 'N')
         {
            tall = 34;
         }
         else
         {
            tall = 40;
         }
         if(attack == true && attackFrame == "Dive")
         {
            tall = 25;
            wide = 8;
         }
         else
         {
            wide = 10;
         }
      }
      if(CurrentPlayer == "Char2")
      {
         if(Fluddpow == 'N')
         {
            tall = 36;
         }
         else
         {
            tall = 43;
         }
         if(attack == true && attackFrame == "Dive")
         {
            tall = 23;
            wide = 8;
         }
         else
         {
            wide = 9;
         }
      }
   //}*/
   if(PauseGame == false)
   {
      UnpausedCharEngine();
      Controll = true;
   }
   /*if(Camcenter == Char)
   {
      camYspeed = (- Camcenter._y + CamYchange) / Camspeed;
      camXspeed = (- Camcenter._x + CamXchange) / Camspeed;
      if(air == true)
      {
         CamYchange = (80 - CamYchange) / 10;
      }
      else
      {
         CamYchange = (50 - CamYchange) / 10;
      }
      CamXchange = (- CamXchange) / 10;
      camYspeed = camYspeed - Char.yspeed / 4;
      camXspeed = camXspeed - Char.xspeed / 4;
      currentCamY = Camcenter._y;
      currentCamX = Camcenter._x;
   }
   else
   {
      camYspeed = (- Camcenter._y + Camcenter._parent._y) / Camspeed;
      camXspeed = (- Camcenter._x + Camcenter._parent._x) / Camspeed;
      currentCamY = Camcenter._y + Camcenter._parent._y;
      currentCamX = Camcenter._x + Camcenter._parent._x;
   }
   if(KeySPACE() && Power >= 100 && WaterAmount > 0 && Fluddpow == 'T'
   //&& Camcenter == Char
   && PauseGame == false && Controll == true)
   {
      camXspeed = (- Char._x) / 5;
      camXspeed = camXspeed - Char.xspeed;
   }
   if(attack == true && attackFrame == "Flying")
   {
      camXspeed = camXspeed - (Char.xspeed * 1.5 - Char._xscale / 40);
      camYspeed = camYspeed - Char.yspeed * 1.5;
   }
   if(attack == true && attackFrame == "Lava" 
   //&& Camcenter == Char*
   )
   {
      camYspeed = (- _Y) / 500;
   }
   camYspeed = max(- MaxCamspeed,camYspeed);
   camYspeed = min(MaxCamspeed,camYspeed);
   camXspeed = max(- MaxCamspeed,camXspeed);
   camXspeed = min(MaxCamspeed,camXspeed);
   CameraZoom = min(Maxzoomin,CameraZoom);
   CameraZoom = max(Maxzoomout,CameraZoom);
   CameraZoom2 = CameraZoom2 + m_round(CameraZoom - CameraZoom2) / 20;
   coursescale2 = groundFriction(coursescale2,3,1.01);
   coursescale = coursescale2 + CameraZoom2;
   if(Camspeed > 1)
   {
      if(Course.CamEdge.hitTest(screensizeX / 2,screensizeY - min(camYspeed,0.0f) + 1,true))
      {
         camYspeed = max(-1.0f,camYspeed);
      }
      if(Course.CamEdge.hitTest(screensizeX / 2,- max(camYspeed,0.0f) - 1,true) && Camspeed > 1)
      {
         camYspeed = min(1.0f,camYspeed);
      }
      if(Course.CamEdge.hitTest(screensizeX - min(camXspeed,0.0f) + 1,screensizeY / 2,true))
      {
         camXspeed = max(-1.0f,camXspeed);
      }
      if(Course.CamEdge.hitTest(- max(camXspeed,0.0f) - 1,screensizeY / 2,true))
      {
         camXspeed = min(1.0f,camXspeed);
      }
      smcount = 0;
      while(Course.CamEdge.hitTest(screensizeX / 2,screensizeY - smcount,true))
      {
         smcount++;
         if(smcount > 50)
         {
            break;
         }
      }
      MoveAllPlats(smcount,0);
      smcount = 0;
      while(Course.CamEdge.hitTest(screensizeX / 2,smcount,true))
      {
         smcount++;
         if(smcount > 50)
         {
            break;
         }
      }
      MoveAllPlats(- smcount,0);
      smcount = 0;
      while(Course.CamEdge.hitTest(screensizeX - smcount,screensizeY / 2,true))
      {
         smcount++;
         if(smcount > 50)
         {
            break;
         }
      }
      MoveAllPlats(0,smcount);
      smcount = 0;
      while(Course.CamEdge.hitTest(smcount,screensizeY / 2,true))
      {
         smcount++;
         if(smcount > 50)
         {
            break;
         }
      }
      MoveAllPlats(0,- smcount);
   }
   if(!nullCam == true)
   {
      if(m_abs(camYspeed) < 1)
      {
         camYspeed = 0;
      }
      if(m_abs(camXspeed) < 1)
      {
         camXspeed = 0;
      }
      MoveAllPlats(camYspeed,camXspeed);
   }
   Camspeed = 10;
   MaxCamspeed = 1200;
   nullCam = false;
   Camcenter = Char;*/
}
void StartCreditsCourse(std::string a, float b, float c, float d, float e, float f) // f unused
{/*
   playingcourse = a;
   if(Starnamenum == 0)
   {
      AreaTextAppear = true;
   }
   CinemaMessage = 'N';
   CinemaMessageFrame = 1;
   TextHint = 'N';
   ToadMessage = 'N';
   if(_root[a + "Gravity"] == undefined)
   {
      gravity = 1;
   }
   else
   {
      gravity = _root[a + "Gravity"];
   }
   if(_root[a + "defaultstep"] == undefined)
   {
      defaultstep = "Char-Step";
   }
   else
   {
      defaultstep = _root[a + "defaultstep"];
   }
   //attachMovie(_root[a + "FarBackground"],"FarBackground",getNextHighestDepth(),{_x:screensizeX / 2,_y:screensizeY / 2});
   //createEmptyMovieClip("BGCourse",getNextHighestDepth());
   BGCourse._y = screensizeY / 2;
   BGCourse._x = screensizeX / 2;
   //BGCourse.attachMovie(_root[a + "Background"],"BG",BGCourse.getNextHighestDepth(),{_x:(- b) / 10,_y:(- c) / 10});
   //createEmptyMovieClip("MidBackground",getNextHighestDepth());
   MidBackground._y = screensizeY / 2;
   MidBackground._x = screensizeX / 2;
   //MidBackground.attachMovie(_root[a + "MidBackground"],"BG",MidBackground.getNextHighestDepth(),{_x:(- b) / 5,_y:(- c) / 5});
   //createEmptyMovieClip("BGCloseCourse",getNextHighestDepth());
   BGCloseCourse._y = screensizeY / 2;
   BGCloseCourse._x = screensizeX / 2;
   //BGCloseCourse.attachMovie(_root[a + "CloseBackground"],"BG",BGCloseCourse.getNextHighestDepth(),{_x:(- b) / 2,_y:(- c) / 2});
   //createEmptyMovieClip("Course",getNextHighestDepth());
   Course._y = screensizeY / 2;
   Course._x = screensizeX / 2;
   b = - b;
   c = - c;
   d = - d;
   e = - e;
   //Course.attachMovie(a + "Puddle","Puddle",Course.getNextHighestDepth(),{_x:b,_y:c});
   //Course.attachMovie(a + "Ice","Ice",Course.getNextHighestDepth(),{_x:b,_y:c});
   //Course.attachMovie(a + "BackGFX","BackGFX",Course.getNextHighestDepth(),{_x:b,_y:c});
   //Course.attachMovie(a + "Platforms","Platforms",Course.getNextHighestDepth(),{_x:b,_y:c,_visible:false});
   //Course.attachMovie(a + "BPlatforms","BPlatforms",Course.getNextHighestDepth(),{_x:b,_y:c,_visible:false});
   //Course.attachMovie(a + "Water","Water",Course.getNextHighestDepth(),{_x:b,_y:c});
   //Course.attachMovie(a + "Lava","Lava",Course.getNextHighestDepth(),{_x:b,_y:c,_visible:false});
   //Course.attachMovie(a + "FrontGFX","FrontGFX",Course.getNextHighestDepth(),{_x:b,_y:c});
   if(Course.FrontGFX._x == undefined)
   {
      //Course.createEmptyMovieClip("FrontGFX",Course.getNextHighestDepth());
      Course.FrontGFX._x = b;
      Course.FrontGFX._y = c;
   }
   //Course.attachMovie(a + "Edge","Edge",Course.getNextHighestDepth(),{_x:b,_y:c,_alpha:0});
   //Course.attachMovie(a + "CamEdge","CamEdge",Course.getNextHighestDepth(),{_x:b,_y:c,_alpha:0});
   //Course.createEmptyMovieClip("Enemyhurt",Course.getNextHighestDepth());
   Enemyhurt._x = b;
   Enemyhurt._y = c;
   PauseGame = false;
   CreditsQuiet = true;
   CreditsCamFirstFrame = 0;
   onEnterFrame = function()
   {
      CreditsEnterFrame();
   };*/
}
void CreditsEnterFrame()
{/*
   Course._yscale = CreditsCourseScaleY;
   Course._xscale = CreditsCourseScaleX;
   BGCourse._yscale = (CreditsCourseScaleY - 100) / 5 + 100;
   BGCourse._xscale = (CreditsCourseScaleX - 100) / 5 + 100;
   MidBackground._yscale = (CreditsCourseScaleY - 100) / 2 + 100;
   MidBackground._xscale = (CreditsCourseScaleX - 100) / 2 + 100;
   BGCloseCourse._y = (CreditsCourseScaleY - 100) / 1 + 100;
   BGCloseCourse._x = (CreditsCourseScaleX - 100) / 1 + 100;
   coursescale = CreditsCourseScaleY;
   Course.Puddle._y = CreditsCourseY;
   Course.Puddle._x = CreditsCourseX;
   Course.Ice._y = CreditsCourseY;
   Course.Ice._x = CreditsCourseX;
   Course.BackGFX._y = CreditsCourseY;
   Course.BackGFX._x = CreditsCourseX;
   Course.Platforms._y = CreditsCourseY;
   Course.Platforms._x = CreditsCourseX;
   Course.BPlatforms._y = CreditsCourseY;
   Course.BPlatforms._x = CreditsCourseX;
   Course.Water._y = CreditsCourseY;
   Course.Water._x = CreditsCourseX;
   Course.Lava._y = CreditsCourseY;
   Course.Lava._x = CreditsCourseX;
   Course.FrontGFX._y = CreditsCourseY;
   Course.FrontGFX._x = CreditsCourseX;
   Course.Edge._y = CreditsCourseY;
   Course.Edge._x = CreditsCourseX;
   Course.CamEdge._y = CreditsCourseY;
   Course.CamEdge._x = CreditsCourseX;
   FarBackground.BG._y = (CreditsCourseY - 100) / 10 + 100;
   FarBackground.BG._x = (CreditsCourseX - 100) / 10 + 100;
   BGCourse.BG._y = (CreditsCourseY - 100) / 5 + 100;
   BGCourse.BG._x = (CreditsCourseX - 100) / 5 + 100;
   MidBackground.BG._y = (CreditsCourseY - 100) / 3 + 100;
   MidBackground.BG._x = (CreditsCourseX - 100) / 3 + 100;
   BGCloseCourse.BG._y = (CreditsCourseY - 100) / 2 + 100;
   BGCloseCourse.BG._x = (CreditsCourseX - 100) / 2 + 100;
   currentCamX = 0;
   currentCamY = 0;
   Course._rotation = CreditsCourseRot;
   BGCourse._rotation = CreditsCourseRot;
   MidBackground._rotation = CreditsCourseRot;
   BGCloseCourse._rotation = CreditsCourseRot;
   FarBackground._rotation = CreditsCourseRot;*/
}
void RemoveCreditsCourse()
{
   CreditsQuiet = false;
   //Course.removeMovieClip(Course);
   //BGCourse.removeMovieClip(BGCourse);
   //MidBackground.removeMovieClip(MidBackground);
   //BGCloseCourse.removeMovieClip(BGCloseCourse);
   //FarBackground.removeMovieClip(FarBackground);
   //onEnterFrame = null;
}
char playedStepSound = 'N';
void playWalkSound()
{/*
   if(playedStepSound != StepSound)
   {
      playedStepSound = StepSound;
      walksound = new Sound(this);
      walksound.attachSound(StepSound);
   }
   walksound.start(0,1);
   walksound.setVolume(CharVolume);
   panX = Char._x;
   panX = panX * 1;
   panX = min(100.0f,panX);
   panX = max(-100.0f,panX);
   walksound.setPan(panX);*/
}