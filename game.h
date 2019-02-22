#ifndef GAME_H
#define GAME_H

#include <string>

using namespace std;

struct gameSound
{
    void attachSound(char[]) {};
    void start(float,float) {};
    void setVolume(float) {};
};

struct entity
{
    float _x, _y, wide, tall, xspeed, yspeed, _alpha, _xscale, _yscale;
    void gotoAndStop(std::string);
    int getNextHighestDepth();
};

struct MovieClip
{
    float _x, _y;
};

struct invis
{
    bool hitTest(float,float,bool);
};
struct terrain
{
    bool hitTest(float,float,bool);
    int getNextHighestDepth();
    invis invisground;
    float _xscale, _yscale, _x, _y;
    void attachMovie();
    entity StartClip;
    bool _visible;
    string type;
};

struct course {
    terrain Platforms, BPlatforms, Water, Puddle, Ice, FrontGFX, BackGFX, Lava, Edge, CamEdge;
    float _x, _y, _xscale, _yscale;
    int getNextHighestDepth();
    void attachMovie(terrain,int,int,int,bool);
};
struct bgcourse {
    float _x, _y, _xscale, _yscale;
    entity BG;
};

struct charclip {
    bool speed;
    void gotoAndStop(std::string);
};

extern terrain Platforms, BPlatforms;

extern gameSound Charsound;
extern gameSound bgsong;

extern entity Enemyhurt;
extern entity Char;

extern MovieClip Camcenter;

extern course Course;
extern bgcourse BGCourse, MidBackground, BGCloseCourse;
extern charclip charClip;
extern bool FluddArray[][4];

int random(int);

/* functions */

/**/
//##DoAction
//- files, data (stars, coins, etc.); names and descriptions for stars

void SaveFile();
void LoadFile();
void DeleteFile();
void DeleteHighScores();
void SaveHighScores();
void CopyFile();

//...

void CalculateStars();
void CalculateStarCoins();
void CalculateFilesInfo();
void SaveLDCourse(int num);
void LoadLDCourse(int num);

//... descriptions for levels

void Restartcoins();

//...

void RestartFludd();

//---
//##DoAction_2
//- functions for moving objects; controls, changing fludd

float radiansToAngle(float a);
float angleToRadians(float a);
float groundFriction(float a, float b, float c);
//shuffleArray(a, b);
void moveObject(float a, float b, entity c);
void moveObjectFromAngle(float a, float b, entity c);
void moveObjectFromRadians(float a, float b, entity c);
void MoveAllPlats(float Yamount, float Xamount);

/**/

/**/
//##DoAction

void StartChar(std::string a, float b, float c, float d, float e, float f, std::string g, char h, std::string i, bool resetmusic); // starts a course // g unused
void CharCode(); // gets called every frame; physics, game mechanics, etc.
void StartCreditsCourse(std::string a, float b, float c, float d, float e, float f); // f unused
void CreditsEnterFrame();
void RemoveCreditsCourse();
void playWalkSound();

//---
//##DoAction_2
//- initializing variables

//---
//##DoAction_3
void ZoomOutCam();
void CharHit(float a, float b, float c, float d, float e, std::string f, bool g);
void Blackout();
void Blackin();
void Whiteout();

//---
void GetStarMusic1();
void GetStarMusic2();
void GetKeyMusic();
void PaintingSound();
void PaintingSound2();
void StopBGsong();
void StartBossMusic();
void StartBoss64Music();
void PlayMusicAndIntro();
void StartNewMusicAndIntroNoVar(std::string a, std::string b);
void HazymazeCaveSongChange(int a);
void BuoyBaseSongChange(int a); // unused

//---
void RemoveCourse();
void ReturnToTitle();
void ReturnToCastle();
void StartInsideofCastle();
void StartBobombBattlefield();
void StartHazyMazeCave();
void StartNewCourse(std::string level, bool a, std::string b);
void changecourse(std::string transition, std::string level, float a, float b, float c, float d, bool e);
void gotoCourseSelect(int level);
void gotoMiniCourseSelect(int level);
void DoorTransition(std::string doorplace);
void StartLevel1();
void PlayBGSong(std::string song);
void PlayMessage(std::string a);
void PlayPicture(std::string a);
void StopMessage();
void StopPicture();
void HitWall();
void LifeLost();
void ReviveChar(std::string level, float a, float b);
void AreaTextClipF(std::string txt, std::string frame);
void StartLevelDesigner(float num);

/**/

/**/

//#frame_4
//##DoAction
void UnpausedCharEngine(); // character movement; jumping, falling, diving, fludd, etc.

//##DoAction_2
void CharRotationCode();

//##DoAction_3
void FallSquish();

/**/

/* variables */

/**/
//## GUI stats
extern int CharLives;
extern int TotalStars;
extern float hpcoincount;
extern float coincount;
extern float RedCoins;
extern float SilverStars;
extern float CharHP;
extern float WaterHP;
extern float WaterAmount;
extern float Power;

//## int
extern int Qualitynum;
extern int Playinglevel;

//## float
extern float Coins;
extern float TotalPower;
extern float TotalWater;

extern float framerate;
extern float screensizeX;
extern float screensizeY;
extern float CameraZoom;
extern float CharXscale;

extern float PowerTimer;
extern float DiveRot;
extern float gravity;
extern float bounce;
extern float IceAccel;
extern float PuddleAccel;
extern float tapwalkspeed;
extern float walkspeed;
extern float Charjumpspeed;
extern float Char2jumpspeed;
extern float airtapspeed;
extern float airwalkspeed;
extern float airmaxWalkspeed;
extern float airmaxtapWalkspeed;
extern float Hoverspeed;
extern float RocketBlast;
extern float turbospeed;
extern float Divespeed;
extern float risespeed;
extern float waterBounce1;
extern float waterBounce2;
extern float WaterDrownSpeed;
extern float WaterHealSpeed;
extern float BgVolume;
extern float CharVolume;
extern float SoundFXVolume;
extern float respawnblink;
extern float lastcoinsound;
extern float Starnamenum;
extern float AntiSquish;
extern float mousemoveX;
extern float mousemoveY;
extern float jumpspeed;
extern float coursescale;
extern float StartX;
extern float StartY;
extern float changestep;
extern float Playinglevelnum;
extern float coursescale2;
extern float CameraZoom2;
extern float Waterpercent;
extern float Powerpercent;
extern float Camspeed;
extern float hpcoinplay;
extern float Maxzoomin;
extern float Maxzoomout;
extern float CamXchange;
extern float CamYchange;
extern float currentCamX;
extern float currentCamY;
extern float MaxCamspeed;

//---
//## bool
extern bool Invincible;
extern bool Metal;
extern bool Invisible;
extern bool WingCap;
extern bool SaveFluddH;
extern bool SaveFluddR;
extern bool SaveFluddT;
extern bool BossKey1;
extern bool BossKey2;
extern bool BossKey3;
extern bool JumpPress;
extern bool LastFrameJumpPress;
extern bool playpause;
extern bool PauseGame;
extern bool CreditsQuiet;
extern bool CheatCastleRestore;
extern bool CheatCastleUnlock;
extern bool CheatStarToggle;
extern bool CheatAllShines;
extern bool WiiMode;
extern bool MuteBGMusic;
extern bool AutoQuality;
extern bool newstar;
extern bool CanSwitchFludd;
extern bool Controll;
extern bool MouseDown;
extern bool waterblast;
extern bool PlayingLevelDesigner;
extern bool nullCam;

//---
//## char
extern char File;
extern char Fluddpow;

//## string
extern std::string StarMessage1;
extern std::string StarMessage2;
extern std::string StarMessage3;
extern std::string StarMessage5;
extern std::string StarMessage8;
extern std::string StarMessage10;
extern std::string StarMessage15;
extern std::string StarMessage20;
extern std::string StarMessage24;
extern std::string StarMessage31;
extern std::string StarMessage32;
extern std::string StarMessage48;
extern std::string StarMessage63;

extern std::string CurrentPlayer;
extern std::string BGquality;
extern std::string Level1Background;
extern std::string Level1FarBackground;
extern std::string Level1MusicIntro;
extern std::string Level1Music;
extern std::string _quality;
extern std::string playingcourse;
extern std::string ToadMessage;
extern std::string TextHint;
extern std::string LastItemGot;
extern std::string defaultstep;

/**/
/**/
//##int/float
extern float tall;
extern float wide;
extern float yspeed;
extern float xspeed;
extern float blink;
extern float StunTime;
extern float doublejump;
extern float doublejumpcount;
extern float spinattackcount;
extern float spinattackcounter;
extern float underwatercount;
extern float abovewatercount;
extern float landtime;
extern float fallcount;
extern float hurtfallcount;
extern float divewaitcount;
extern float swimupcount;
extern float _xscale;

//---
//##bool
extern bool air;
extern bool lockon;
extern bool Ice;
extern bool Puddle;
extern bool Water;
extern bool attack;
extern bool swimup;
extern bool changeFludd;
extern bool canChangeFludd;
extern bool Squish;
extern bool hurt;

//---
//## char
extern char spincount;

//## string
extern std::string frame;
extern std::string attackFrame;
/**/

extern bool _focusrect;
extern float saveX;
extern float saveY;
extern bool icedive;
extern float runcount;
extern std::string runtap;
extern float fallingyspeed;
extern bool fallingsfx;
extern float _rotation;
extern float _X;
extern float _Y;
extern float camXspeed;
extern float camYspeed;
extern std::string StepSound;
extern float smcount;
extern float rotation;
extern float frontpointX;
extern float frontpointY;
extern float coint;
extern bool hitplatform;
extern bool backpointX;
extern bool backpointY;
extern bool speedslide;

#endif