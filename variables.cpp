#include <string>
#include "game.h"

using namespace std;

terrain Platforms, BPlatforms;

gameSound Charsound;
gameSound bgsong;

entity Enemyhurt;
entity Char;

MovieClip Camcenter;

course Course;
bgcourse BGCourse, MidBackground, BGCloseCourse;
charclip charClip;
bool FluddArray[8][4];

/**/
//## GUI stats
int CharLives = 4; 
int TotalStars = 0;

float hpcoincount = 0; // POWER meter

//- blue coins +15, red coins +5, gold coins +1 
//- for every 5 points you get 1 CharHP point

float coincount = 0;
float RedCoins = 0;
float SilverStars = 0;
float CharHP = 8;
float WaterHP = 8; // oxygen meter
float WaterAmount = TotalWater; 
float Power = TotalPower;

//## int
int Qualitynum = 1;
int Playinglevel = 0;

//## float
float Coins = 0; // useless; appears anywhere coincount does
float TotalPower = 100; // max Power
float TotalWater = 10000; // max WaterAmount 

float framerate = 32;
float screensizeX = 450; // screen width?
float screensizeY = 300; // screen height?
float CameraZoom = 100;
float CharXscale = 100; // for orientation? >0 to the right, <0 to the left

float PowerTimer = 0; // timer for last power taken
float DiveRot = 0; 
float gravity = 1; // gravity of the current course
float bounce = 0.5;
float IceAccel = 5;
float PuddleAccel = 2.2;
float tapwalkspeed = 0.6;
float walkspeed = 1.2; // default walking speed
float Charjumpspeed = 10;
float Char2jumpspeed = 11;
float airtapspeed = 2.5;
float airwalkspeed = 5; // horizontal speed in air
float airmaxWalkspeed = 20;
float airmaxtapWalkspeed = 30;
float Hoverspeed = 0.92;
float RocketBlast = 25;
float turbospeed = 75;
float Divespeed = 35;
float risespeed = 0.1;
float waterBounce1 = 13;
float waterBounce2 = 0.5;
float WaterDrownSpeed = 80;
float WaterHealSpeed = 8;
float BgVolume = 100;
float CharVolume = 100;
float SoundFXVolume = 100;
float respawnblink = 90;
float lastcoinsound = 0;
float Starnamenum = 0;
float AntiSquish;
float mousemoveX;
float mousemoveY;
float jumpspeed;
float coursescale = 100;
float StartX;
float StartY;
float changestep;
float Playinglevelnum;
float coursescale2;
float CameraZoom2;
float Waterpercent;
float Powerpercent;
float Camspeed;
float hpcoinplay;
float Maxzoomin;
float Maxzoomout;
float CamXchange;
float CamYchange;
float currentCamX;
float currentCamY;
float MaxCamspeed;

//---
//## bool
bool Invincible = false;
bool Metal = false;
bool Invisible = false;
bool WingCap = false;
bool SaveFluddH = false; // if you have unlocked a type of fludd in the current course
bool SaveFluddR = false; //
bool SaveFluddT = false; //
bool BossKey1 = false;
bool BossKey2 = false;
bool BossKey3 = false;
bool JumpPress = false;
bool LastFrameJumpPress = false;
bool playpause = false;
bool PauseGame = false;
bool CreditsQuiet = false;
bool CheatCastleRestore = false;
bool CheatCastleUnlock = false;
bool CheatStarToggle = false;
bool CheatAllShines = false;
bool WiiMode = false;
bool MuteBGMusic = false;
bool AutoQuality = true;
bool newstar = false;
bool CanSwitchFludd = false;
bool Controll = true;
bool MouseDown = false;
bool waterblast = false;
bool PlayingLevelDesigner = false;
bool nullCam;

//---
//## char
char File = 'A';
char Fluddpow = 'H';

//## string

std::string StarMessage1;
std::string StarMessage2;
std::string StarMessage3;
std::string StarMessage5;
std::string StarMessage8;
std::string StarMessage10;
std::string StarMessage15;
std::string StarMessage20;
std::string StarMessage24;
std::string StarMessage31;
std::string StarMessage32;
std::string StarMessage48;
std::string StarMessage63;

std::string CurrentPlayer = "Char";
std::string BGquality = "MEDIUM";
std::string Level1Background = "GrassandHillsBG";
std::string Level1FarBackground = "CloudBackground";
std::string Level1MusicIntro = "NSMBLandIntro";
std::string Level1Music = "NSMBLandRepeat";
std::string _quality;
std::string playingcourse = "LevelDesigner";
std::string ToadMessage;
std::string TextHint;
std::string LastItemGot;
std::string defaultstep;

/**/

/**/
//##int/float
float tall = 35;
float wide = 10;
float yspeed = 0;
float xspeed = 0;
float blink = 0;
float StunTime = 0;
float doublejump = 0;
float doublejumpcount = 0;
float spinattackcount = 0;
float spinattackcounter = 0;
float underwatercount = 0;
float abovewatercount = 0;
float landtime = 0;
float fallcount = 0;
float hurtfallcount = 0;
float divewaitcount = 7;
float swimupcount = 0;
float _xscale = CharXscale;  // for orientation? >0 to the right, <0 to the left

//---
//##bool
bool air = true;
bool lockon = true;
bool Ice = false;
bool Puddle = false;
bool Water = false;
bool attack = false;
bool swimup = false;
bool changeFludd = false;
bool canChangeFludd = true;
bool Squish = false;
bool hurt = false;

//---
//## char
char spincount = '0';

//## string
std::string frame = "1";
std::string attackFrame = "";
/**/

bool _focusrect;
float saveX;
float saveY;
bool icedive;
float runcount;
std::string runtap;
float fallingyspeed;
bool fallingsfx;
float _rotation;
float _X;
float _Y;
float camXspeed;
float camYspeed;
std::string StepSound;
float smcount;
float rotation;
float frontpointX;
float frontpointY;
float coint;
bool hitplatform;
bool backpointX;
bool backpointY;
bool speedslide;