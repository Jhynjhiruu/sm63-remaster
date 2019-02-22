#include "../game.h"
#include "../controls.h"
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

void UnpausedCharEngine()
{
    if(playpause == true)
    {
        Controll = false;
    }
    blink = m_round(blink);

    blink = max(blink,0.0f);
    StunTime = m_round(StunTime);
    StunTime = max(StunTime,0.0f);
    
    if(StunTime > 0)
    {
        StunTime--;
        if(Water == true)
        {
            StunTime = StunTime - 3;
        }
        else
        {
            Controll = false;
        }
    }
    if(blink > 0)
    {
        blink--;
        if(blink / 3 == m_round(blink / 3))
        {
            Char._alpha = 20;
        }
        else
        {
            Char._alpha = 70;
        }
    }
    else
    {
        Char._alpha = 100;
    }
    if(Char.yspeed > -3)
    {
        lockon = true;
    }
    else
    {
        lockon = false;
    }
    if(CanSwitchFludd == true)
    {
        if(!KeySHIFT())
        {
            canChangeFludd = true;
        }
        if(KeySHIFT() && canChangeFludd == true)
        {
            changeFludd = true;
            canChangeFludd = false;
        }
        else
        {
            changeFludd = false;
        }
        if(attack == false)
        {
            ChangeFludd();
        }
    }
    if(newstar == true && !(attackFrame == "Star" && attack == true) && Playinglevel == 0)
    {
        attack = true;
        attackFrame = "ExitPainting";
    }
    if(attackFrame == "Star")
    {
        CameraZoom = 100;
        if(Char.yspeed > 7)
        {
            Char.yspeed = Char.yspeed * 0.95;
        }
    }
    if(attackFrame == "frontflip" && attack == true && !(Fluddpow == 'N'))
    {
        attack = false;
    }
    if(LastFrameJumpPress == false && KeyUP())
    {
        JumpPress = 7;
    }
    else
    {
        JumpPress = JumpPress - 1;
    }
    LastFrameJumpPress = KeyUP();
    if(air == true)
    {
        if(Water == true)
        {
            if(Course.Water.hitTest(_X * coursescale / 100 + Course._x,(_Y - Char.tall / 2) * coursescale / 100 + Course._y,true))
            {
            if(attackFrame == "Star")
            {
                Char.yspeed = Char.yspeed + gravity / 3;
            }
            else if(Metal != true)
            {
                Char.yspeed = Char.yspeed + gravity / 3;
            }
            else
            {
                Char.yspeed = Char.yspeed + gravity / 2;
            }
            }
            Char.yspeed = groundFriction(Char.yspeed,0.05,1.01);
        }
        else
        {
            Char.yspeed = Char.yspeed + gravity;
            if(PowerTimer && WingCap == true && Char.yspeed > 3)
            {
            Char.yspeed = Char.yspeed - gravity / 6;
            fallingyspeed = groundFriction(Char.yspeed,gravity / 4.5,1.07);
            }
            else
            {
            fallingyspeed = groundFriction(Char.yspeed,gravity / 5,1.05);
            }
            if(Char.yspeed > 0)
            {
            if(attack == false && Char.yspeed > 7)
            {
                fallcount++;
                if(KeySPACE() && Power > 0 && WaterAmount > 0 && Fluddpow == 'H')
                {
                    fallcount = 0;
                    hurtfallcount--;
                    hurtfallcount = max(hurtfallcount,0.0f);
                }
                if(fallingyspeed >= 15 && air == true && Char.yspeed > 15 && fallingsfx != true)
                {
                    hurtfallcount++;
                    hurtfallcount = min(hurtfallcount,7.0f);
                    if(hurtfallcount >= 5)
                    {
                        fallingsfx = true;
                        //Charsound = new Sound(this);
                        //Charsound.attachSound("Char-Fall");
                        //Charsound.start(0,1);
                        //Charsound.setVolume(CharVolume);
                    }
                }
            }
            else
            {
                fallcount = m_round(fallcount / 2);
            }
            Char.yspeed = groundFriction(Char.yspeed,gravity / 5,1.05);
            }
            else
            {
            fallcount = 0;
            hurtfallcount--;
            hurtfallcount = max(hurtfallcount,0.0f);
            }
        }
        Char.yspeed = groundFriction(Char.yspeed,0,1.001);
        Char.xspeed = groundFriction(Char.xspeed,0,1.001);
        if(attack == false)
        {
            if(Water == false)
            {
                if(Char.yspeed > 2)
                {
                    //frame = "4";
                }
                else
                {
                    //frame = "3";
                }
            }
            if((!KeyDOWN() && !KeyZ()) || air == false)
            {
            divewaitcount = divewaitcount - 3;
            }
            divewaitcount = divewaitcount - 1;
            if(KeyZ() && (Water == false || Metal == true) && divewaitcount <= 0 && !Course.Platforms.hitTest(_X * coursescale / 100 + Course._x,(_Y + 5) * coursescale / 100 + Course._y,true) && !Course.BPlatforms.hitTest(_X * coursescale / 100 + Course._x,(_Y + 5) * coursescale / 100 + Course._y,true))
            {
            Char.yspeed = 0;
            Char.xspeed = 0;
            attack = true;
            attackFrame = "Ground";

            }
            if(KeyDOWN() && (Water == false || Metal == true) && divewaitcount <= 0)
            {
            attack = true;
            if(Char._xscale < 0)
            {
                Char.xspeed = Char.xspeed - (Char.xspeed - Divespeed) / 5;
            }
            else
            {
                Char.xspeed = Char.xspeed - (Char.xspeed + Divespeed) / 5;
            }
            if(WingCap == true)
            {
                attackFrame = "Flying";
                Char.yspeed = Char.yspeed * 0.5;
            }
            else
            {
                attackFrame = "Dive";
                Char.yspeed = Char.yspeed + 3;
                if(CurrentPlayer == "Char")
                {
                    //soundj = "Char-Dive";
                }
                if(CurrentPlayer == "Char2")
                {
                    if(random(2) == 1)
                    {
                        //soundj = "Char2 - Yah!";
                    }
                    else
                    {
                        //soundj = "Char2 - Yuh!";
                    }
                }
                //Charsound = new Sound(this);
                //Charsound.attachSound(soundj);
                //Charsound.start(0,1);
                //Charsound.setVolume(CharVolume);
            }
            }
            if(KeyRIGHT() && Controll == true)
            {
                Char.xspeed = Char.xspeed - min((Char.xspeed - airwalkspeed) / (airmaxWalkspeed / 3),0.0f);
                Char._xscale = -100;
                if(KeySPACE() && Power > 0 && WaterAmount > 0 && Fluddpow == 'H')
                {
                    _rotation = _rotation + 5;
                    Char.xspeed = Char.xspeed - min((Char.xspeed - airwalkspeed) / airmaxWalkspeed,0.0f);
                }
            }
            if(KeyLEFT() && Controll == true)
            {
                Char.xspeed = Char.xspeed - max((Char.xspeed + airwalkspeed) / (airmaxWalkspeed / 3),0.0f);
                Char._xscale = 100;
                if(KeySPACE() && Power > 0 && WaterAmount > 0 && Fluddpow == 'H')
                {
                    _rotation = _rotation - 5;
                    Char.xspeed = Char.xspeed - max((Char.xspeed + airwalkspeed) / airmaxWalkspeed,0.0f);
                }
            }
            if(KeyTapRIGHT() && !KeyRIGHT() && Controll == true)
            {
            Char.xspeed = Char.xspeed - min((Char.xspeed - airtapspeed) / (airmaxtapWalkspeed / 3.0f),0.0f);
            Char._xscale = -100;
            if(KeySPACE() && Power > 0 && WaterAmount > 0 && Fluddpow == 'H')
            {
                _rotation = _rotation + 5;
                Char.xspeed = Char.xspeed - min((Char.xspeed - airtapspeed) / airmaxtapWalkspeed,0.0f);
            }
            }
            if(KeyTapLEFT() && !KeyLEFT() && Controll == true)
            {
            Char.xspeed = Char.xspeed - max((Char.xspeed + airtapspeed) / (airmaxtapWalkspeed / 3.0f),0.0f);
            Char._xscale = 100;
            if(KeySPACE() && Power > 0 && WaterAmount > 0 && Fluddpow == 'H')
            {
                _rotation = _rotation - 5;
                Char.xspeed = Char.xspeed - max((Char.xspeed + airtapspeed) / airmaxtapWalkspeed,0.0f);
            }
            }
        }
        if(KeyUP() && !Course.Water.hitTest(_X * coursescale / 100 + Course._x,(_Y - 12) * coursescale / 100 + Course._y,true) && Course.Water.hitTest(_X * coursescale / 100 + Course._x,(_Y + 5) * coursescale / 100 + Course._y,true) && Char.yspeed < 1 && Char.yspeed > -5 && Controll == true && Squish == false)
        {
            lockon = false;
            Char.yspeed = Char.yspeed * 0.7;
            Char.yspeed = Char.yspeed - jumpspeed / 1.5;
            //Charsound = new Sound(this);
            //Charsound.attachSound("sound - Splash");
            //Charsound.start(0,1);
            //Charsound.setVolume(CharVolume);
            //Course.FrontGFX.attachMovie("Med-Splash","Med-Splash" + Course.FrontGFX.getNextHighestDepth(),Course.FrontGFX.getNextHighestDepth(),{_x:_X - Course.FrontGFX._x,_y:_Y - Course.FrontGFX._y});
            //frame = "3";
        }
        runcount = 0;
        runtap = "N";
    }
    else
    {
        fallingsfx = false;
        doublejumpcount--;
        doublejumpcount = max(doublejumpcount,0.0f);
        if(doublejumpcount == 0)
        {
            doublejump = 0;
        }
        if(Course.Ice.hitTest(_X * coursescale / 100 + Course._x,(_Y + 3) * coursescale / 100 + Course._y,true))
        {
            Ice = true;
        }
        else
        {
            Ice = false;
        }
        if(Course.Puddle.hitTest(_X * coursescale / 100 + Course._x,(_Y + 3) * coursescale / 100 + Course._y,true))
        {
            Puddle = true;
        }
        else
        {
            Puddle = false;
        }
       // if(//frame == "3" || frame == "4")
        //{
         //  frame = "1";
        //}
        //FallSquish();
        Char.yspeed = min(0.0f,Char.yspeed);
        if(Puddle == false && Ice == false && !(attackFrame == "Dive" && attack == true))
        {
            if(StunTime == 0)
            {
            Char.xspeed = groundFriction(Char.xspeed,0.3,1.15);
            }
            else
            {
            Char.xspeed = groundFriction(Char.xspeed,0.15,1.075);
            }
        }
        else
        {
            if(attackFrame == "Dive" && attack == true && Ice == false && Puddle == false)
            {
            if(StunTime == 0)
            {
                Char.xspeed = groundFriction(Char.xspeed,0.2,1.05);
            }
            else
            {
                Char.xspeed = groundFriction(Char.xspeed,0.1,1.025);
            }
            }
            if(attack == true && attackFrame == "Dive" && Ice == false && Puddle == true)
            {
            if(StunTime == 0)
            {
                Char.xspeed = groundFriction(Char.xspeed,0.1,1.015);
            }
            }
            if(!(attack == true && attackFrame == "Dive") && Puddle == true)
            {
            if(StunTime == 0)
            {
                Char.xspeed = groundFriction(Char.xspeed,0.15,1.07);
            }
            else
            {
                Char.xspeed = groundFriction(Char.xspeed,0.075,1.035);
            }
            }
            if(attack == true && attackFrame == "Dive" && Ice == true)
            {
            if(StunTime == 0)
            {
                Char.xspeed = groundFriction(Char.xspeed,0.04,1.007);
            }
            else
            {
                Char.xspeed = groundFriction(Char.xspeed,0.02,1.0035);
            }
            }
            if(!(attack == true && attackFrame == "Dive") && Ice == true)
            {
            if(StunTime == 0)
            {
                Char.xspeed = groundFriction(Char.xspeed,0.05,1.01);
            }
            else
            {
                Char.xspeed = groundFriction(Char.xspeed,0.025,1.005);
            }
            }
        }
        if(Puddle == true)
        {
            WaterAmount = WaterAmount + 250;
        }
        Power = TotalPower;
        runcount--;
        if(runcount <= 0)
        //|| isNaN(runcount))
        {
            runcount = 0;
            runtap = "N";
        }
        
        if(attack == false && Controll == true && spinattackcounter <= 1)
        {
            if(runtap == "N")
            {
            if(KeyRIGHT())
            {
                runcount = 9;
                runtap = "R";
            }

            if(KeyLEFT())
            {
                runcount = 9;
                runtap = "L";
            }
            }
            else
            {
            if(!KeyRIGHT() && runtap == "R")
            {
                runtap = "Right";
            }
            if(!KeyLEFT() && runtap == "L")
            {
                runtap = "Left";
            }
            if(KeyRIGHT() && runtap == "Right")
            {
                attack = true;
                attackFrame = "Run";
            }
            if(KeyLEFT() && runtap == "Left")
            {
                attack = true;
                attackFrame = "Run";
            }
            }
        }
        if(attack == false && Controll == true)
        {
            if(KeyRIGHT())
            {
            //frame = "2";
            if(Ice == true)
            {
                Char.xspeed = Char.xspeed + walkspeed / IceAccel;
            }
            else if(Puddle == true)
            {
                Char.xspeed = Char.xspeed + walkspeed / PuddleAccel;
            }
            else
            {
                Char.xspeed = Char.xspeed + walkspeed;
            }
            Char._xscale = -100;
            }
            if(KeyLEFT())
            {
            //frame = "2";
            if(Ice == true)
            {
                Char.xspeed = Char.xspeed - walkspeed / IceAccel;
            }
            else if(Puddle == true)
            {
                Char.xspeed = Char.xspeed - walkspeed / PuddleAccel;
            }
            else
            {
                Char.xspeed = Char.xspeed - walkspeed;
            }
            Char._xscale = 100;
            }
            if(KeyTapRIGHT() && !KeyRIGHT())
            {
            //frame = "2";
            if(Ice == true)
            {
                Char.xspeed = Char.xspeed + tapwalkspeed / IceAccel;
            }
            else if(Puddle == true)
            {
                Char.xspeed = Char.xspeed + tapwalkspeed / PuddleAccel;
            }
            else
            {
                Char.xspeed = Char.xspeed + tapwalkspeed;
            }
            Char._xscale = -100;
            }
            if(KeyTapLEFT() && !KeyLEFT())
            {
            //frame = "2";
            if(Ice == true)
            {
                Char.xspeed = Char.xspeed - tapwalkspeed / IceAccel;
            }
            else if(Puddle == true)
            {
                Char.xspeed = Char.xspeed - tapwalkspeed / PuddleAccel;
            }
            else
            {
                Char.xspeed = Char.xspeed - tapwalkspeed;
            }
            Char._xscale = 100;
            }
            if(KeyDOWN())
            {
            attack = true;
            attackFrame = "Dive";
            }
        }
        if(attack == true && attackFrame != "Land")
        {
            doublejump = 0;
        }
        if(attack == false)
        {
            if(Metal == true && JumpPress > 0 && KeyUP() && Controll == true && Squish == false && Char.yspeed >= -3 && Water == true)
            {
            //frame = "3";
            attack = false;
            lockon = false;
            Char.yspeed = min((- jumpspeed) * 1.25f,Char.yspeed);
            }
            if(KeyUP() && JumpPress > 0 && Controll == true && Squish == false && Char.yspeed >= -3 && Water == false)
            {
                attack = false;
                lockon = false;
                if(Puddle == true)
                {
                    //Charsound = new Sound(this);
                    //Charsound.attachSound("step - Water");
                    //Charsound.start(0,1);
                    //Charsound.setVolume(CharVolume);
                }
                if(doublejump == 0)
                {
                    Char.yspeed = min(- jumpspeed,Char.yspeed);
                    doublejumpcount = 9;
                    if(CurrentPlayer == "Char")
                    {
                        if(random(2) == 1)
                        {
                            //soundj = "Char Jump-1";
                        }
                        else
                        {
                            //soundj = "Char Jump-1b";
                        }
                    }
                    else if(CurrentPlayer == "Char2")
                    {
                        if(random(2) == 1)
                        {
                            //soundj = "Char2 - Yah!";
                        }
                        else
                        {
                            //soundj = "Char2 - Yuh!";
                        }
                    }
                    //Charsound = new Sound(this);
                    //Charsound.attachSound(soundj);
                    //Charsound.start(0,1);
                    //Charsound.setVolume(CharVolume);
                }
                else if(doublejump == 1)
                {
                    Char.yspeed = min(- jumpspeed - 2.5f,Char.yspeed);
                    doublejumpcount = 9;
                    //Charsound = new Sound(this);
                    if(CurrentPlayer == "Char")
                    {
                        //Charsound.attachSound("Char Jump-2");
                    }
                    else
                    {
                        //Charsound.attachSound("Char2 - Yoho!");
                    }
                    //Charsound.start(0,1);
                    //Charsound.setVolume(CharVolume);
                }
                else if(m_abs(Char.xspeed) > 3)
                {
                    attack = true;
                    attackFrame = "frontflip";
                    Char.yspeed = min(- jumpspeed - 5.0f,Char.yspeed);
                    //Charsound = new Sound(this);
                    if(CurrentPlayer == "Char")
                    {
                        //Charsound.attachSound("Char Tripple Jump");
                    }
                    else
                    {
                        //Charsound.attachSound("Char2 - Yahoo!");
                    }
                    //Charsound.start(0,1);
                    //Charsound.setVolume(CharVolume);
                    if(Char._xscale < 0)
                    {
                        Char.xspeed = Char.xspeed - (Char.xspeed - 15) / 5;
                    }
                    else
                    {
                        Char.xspeed = Char.xspeed - (Char.xspeed + 15) / 5;
                    }
                    doublejumpcount = 0;
                    doublejump = -1;
                }
                if(doublejump >= 3)
                {
                    doublejump = 0;
                }
                doublejump++;
                //frame = "3";
            }
        }
    }
    spinattackcount--;
    if(spinattackcount <= 0)
    {
        spinattackcount = 0;
        spincount = 'N';
        spinattackcounter = 0;
    }
    if(KeyRIGHT() && !KeyLEFT())
    {
        if(spincount != 'R')
        {
            if(spinattackcounter < 1 || spinattackcount > 0)
            {
            spinattackcounter++;
            spinattackcount = 15 - spinattackcounter * 3;
            }
        }
        spincount = 'R';
    }
    if(KeyLEFT() && !KeyRIGHT())
    {
        if(spincount != 'L')
        {
            if(spinattackcounter < 1 || spinattackcount > 0)
            {
            spinattackcounter++;
            spinattackcount = 11 - spinattackcounter;
            }
        }
        spincount = 'L';
    }
    if((KeySPIN() || spinattackcounter >= 4) && attack == false && Char.yspeed > -3)
    {
        attackFrame = "Spin";
        attack = true;
        spinattackcount = 0;
        spincount = 'N';
        spinattackcounter = 0;
    }
    if(spinattackcounter >= 3 && (attackFrame == "Spin" || attackFrame == "DiveSpin" || attackFrame == "SlingStar") && attack == true)
    {
        charClip.speed = charClip.speed * 0.8;
        charClip.speed = charClip.speed + 15;
        spinattackcount = 0;
        spincount = 'N';
        spinattackcounter = 0;
    }
    if(KeySPACE() && Power >= 100 && WaterAmount > 0 && Fluddpow == 'R')
    {
        waterblast = true;
    }
    else
    {
        waterblast = false;
    }
    if(Water == true && air == true && Metal != true)
    {
        fallcount = 0;
        hurtfallcount--;
        hurtfallcount = max(hurtfallcount,0.0f);
       frame = "swim1";
    }
    if(Water == true && air == true && Metal == true)
    {
        if(Char.yspeed < 0)
        {
           frame = "3";
        }
        else
        {
           frame = "4";
        }
    }
    if(swimup == true && attack == false && Metal != true && Controll == true)
    {
        swimupcount++;
       frame = "swim2";
        if(!KeyUP() && swimupcount > 5)
        {
            swimup = false;
        }
    }
    if(attack == false && Controll == true && playpause == false)
    {
        if((KeyUP() || KeyTapUP()) && (air == true || (Water == true && playpause == false)))
        {
            Char.yspeed = Char.yspeed - risespeed;
            if(Water == true)
            {
            Char.yspeed = Char.yspeed + risespeed;
            if(swimup == true)
            {
                Char.yspeed = Char.yspeed - risespeed * 2;
            }
            if(swimup == false && Metal != true)
            {
                //Charsound = new Sound(this);
                //Charsound.attachSound("sound - Water");
                //Charsound.start(0,1);
                //Charsound.setVolume(CharVolume);
                swimupcount = 0;
                if(KeyDOWN() || KeyTapDOWN())
                {
                    Char.yspeed = Char.yspeed - 4;
                }
                else
                {
                    Char.yspeed = Char.yspeed - 6;
                }
                if(KeyRIGHT())
                {
                    Char.xspeed = Char.xspeed + 2;
                }
                if(KeyLEFT())
                {
                    Char.xspeed = Char.xspeed - 2;
                }
            }
            swimup = true;
            }
        }
        if(KeyDOWN() || KeyTapDOWN())
        {
            Char.yspeed = Char.yspeed + risespeed;
            if(Water == true)
            {
            Char.yspeed = Char.yspeed + risespeed * 2;
            }
        }
        if(KeySPACE() && Power > 0 && WaterAmount > 0 && Fluddpow == 'H')
        {
            lockon = false;
            Char.yspeed = Char.yspeed * 0.8;
            Char.yspeed = Char.yspeed - (Hoverspeed * 10 - Char.yspeed) / 10 * (Power / 175 + 0.75);
            WaterAmount = WaterAmount - 7;
            Power = Power - 1.5;
            Char.xspeed = groundFriction(Char.xspeed,0.05,1.03);
        }
        if(KeySPACE() && Power >= 100 && WaterAmount > 0 && Fluddpow == 'T')
        {
            WaterAmount = WaterAmount - 5;
            if(air == false && Ice == false)
            {
            if(Char._xscale < 0)
            {
                Char.xspeed = Char.xspeed - (Char.xspeed - turbospeed) / 30;
            }
            else
            {
                Char.xspeed = Char.xspeed - (Char.xspeed + turbospeed) / 30;
            }
            }
            else if(Char._xscale < 0)
            {
            Char.xspeed = Char.xspeed - (Char.xspeed - turbospeed / 2) / 30;
            }
            else
            {
            Char.xspeed = Char.xspeed - (Char.xspeed + turbospeed / 2) / 30;
            }
            if(Water == true && playpause == false)
            {
            Char.yspeed = Char.yspeed - gravity / 3;
            if(KeyUP() || KeyTapUP())
            {
                _rotation = _rotation + Char._xscale / 100 * 10;
                Char.yspeed = Char.yspeed - gravity / 1.5;
            }
            if(KeyDOWN() || KeyTapDOWN())
            {
                _rotation = _rotation - Char._xscale / 100 * 10;
                Char.yspeed = Char.yspeed + gravity / 1.5;
            }
            }
            if(Water == false && Course.Water.hitTest(_X * coursescale / 100 + Course._x,(_Y + 5) * coursescale / 100 + Course._y,true))
            {
            fallcount = 0;
            hurtfallcount--;
            hurtfallcount = max(hurtfallcount,0.0f);
            if(Course.Water.hitTest(_X * coursescale / 100 + Course._x,_Y * coursescale / 100 + Course._y,true) && playpause == false)
            {
                Char.yspeed = Char.yspeed - gravity / 5;
                _Y = _Y - 1;
            }
            int waterrepeats = 0;
            while(waterrepeats < m_abs(Char.xspeed) / 7 + random(2))
            {
                //Course.FrontGFX.attachMovie("Run-Splash" + (random(2) + 1),"Run-Splash" + Course.FrontGFX.getNextHighestDepth(),Course.FrontGFX.getNextHighestDepth(),{_x:_X - Course.FrontGFX._x + (waterrepeats - 1) / m_round(Char.xspeed) * 100,_y:_Y - Course.FrontGFX._y});
                waterrepeats++;
            }
            WaterAmount = WaterAmount + 50;
            Char.yspeed = min(0.0f,Char.yspeed);
            if(!KeyRIGHT() && !KeyLEFT())
            {
                Char.xspeed = groundFriction(Char.xspeed,0.1,1.05);
            }
            if(Char._xscale < 0)
            {
                Char.xspeed = Char.xspeed - (Char.xspeed - turbospeed / 2) / 30;
            }
            else
            {
                Char.xspeed = Char.xspeed - (Char.xspeed + turbospeed / 2) / 30;
            }
           frame = "2";
            if(KeySPACE() && KeyUP() && Squish == false)
            {
                lockon = false;
                Char.yspeed = min(Char.yspeed,(- jumpspeed) / 1.5f);
               frame = "3";
            }
            }
        }
    }
    if((frame == "swim1" || frame == "swim2") && Water == false)
    {
        if(air == true)
        {
           frame = "4";
        }
        else
        {
           frame = "1";
        }
    }
    if(attackFrame != "Star")
    {
        if(Course.Water.hitTest(_X * coursescale / 100 + Course._x,_Y * coursescale / 100 + Course._y,true))
        {
            if(Course.Water.hitTest(_X * coursescale / 100 + Course._x,(_Y - Char.tall) * coursescale / 100 + Course._y,true) && playpause == false)
            {
            underwatercount++;
            if(underwatercount > WaterDrownSpeed && Metal != true)
            {
                //Course.FrontGFX.attachMovie("WaterBubble","Bubble" + Course.FrontGFX.getNextHighestDepth(),Course.FrontGFX.getNextHighestDepth(),{_x:_X - Course.FrontGFX._x,_y:_Y - Course.FrontGFX._y - Char.tall * 0.75});
                //Charsound = new Sound(this);
                //Charsound.attachSound("sound - Drain");
                //Charsound.start(0,1);
                //Charsound.setVolume(CharVolume);
                WaterHP = WaterHP - 1;
                if(WaterHP <= 0 && !(attack == true && attackFrame == "Drown"))
                {
                    attack = true;
                    attackFrame = "Drown";

                }
                WaterHP = max(WaterHP,0.0f);
                underwatercount = 0;
            }
            }
            else if(playpause == false)
            {
            abovewatercount++;
            if(abovewatercount > WaterHealSpeed)
            {
                abovewatercount = 0;
                WaterHP = WaterHP + 1;
                WaterHP = min(WaterHP,8.0f);
            }
            }
        }
    }
    if(Water == true)
    {
        WaterAmount = WaterAmount + 500;
        Power = Power + 3;
        Char.yspeed = groundFriction(Char.yspeed,0.05,1.1);
        Char.xspeed = groundFriction(Char.xspeed,0.05,1.05);
    }
    else
    {
        underwatercount = 0;
        abovewatercount++;
        if(abovewatercount > WaterHealSpeed)
        {
            abovewatercount = 0;
            WaterHP = WaterHP + 1;
            WaterHP = min(WaterHP,8.0f);
        }
    }
    if(attack == true && (attackFrame == "Dive" || attackFrame == "frontflip"))
    {
        if(KeySPACE() && Power > 0 && WaterAmount > 0 && Fluddpow == 'S')
        {
            WaterAmount = WaterAmount - 5;
            Power = Power - 1;
        }
        if(KeySPACE() && Power > 0 && WaterAmount > 0 && Fluddpow == 'H')
        {
            WaterAmount = WaterAmount - 7;
            Power = Power - 1.5;
            Char.yspeed = Char.yspeed * 0.98;
            Char.xspeed = Char.xspeed * 0.97;
            if(air == true)
            {
            Char.yspeed = Char.yspeed - m_sin(angleToRadians(DiveRot)) * Hoverspeed;
            if(Char._xscale > 0)
            {
                Char.xspeed = Char.xspeed - m_cos(angleToRadians(DiveRot)) * Hoverspeed / 2;
            }
            else
            {
                Char.xspeed = Char.xspeed + m_cos(angleToRadians(DiveRot)) * Hoverspeed / 2;
            }
            }
            else if(Char._xscale > 0)
            {
            Char.xspeed = Char.xspeed - m_cos(angleToRadians(DiveRot)) * Hoverspeed;
            }
            else
            {
            Char.xspeed = Char.xspeed + m_cos(angleToRadians(DiveRot)) * Hoverspeed;
            }
        }
        if(KeySPACE() && Power >= 100 && WaterAmount > 0 && Fluddpow == 'T')
        {
            WaterAmount = WaterAmount - 10;
            Char.yspeed = Char.yspeed - m_sin(angleToRadians(DiveRot - 90)) / 2;
            if(Char._xscale > 0)
            {
            Char.xspeed = Char.xspeed - m_cos(angleToRadians(DiveRot - 90)) / 2;
            }
            else
            {
            Char.xspeed = Char.xspeed + m_cos(angleToRadians(DiveRot - 90)) / 2;
            }
        }
    }
    if(Course.Lava.hitTest(_X * coursescale / 100 + Course._x,_Y * coursescale / 100 + Course._y,true) && CharHP >= 0 && !(((attackFrame == "Fall" || attackFrame == "Respawn" || attackFrame == "Faint" || attackFrame == "Drown" || attackFrame == "Pause" || attackFrame == "none" || attackFrame == "Squish") && attack == true) || Metal == true || Invincible == true) && playpause == false && Char.yspeed > -3)
    {
        blink = 0;
        //CharHit(3,20,0,0,20,"none",false);
        if(CharHP >= 0)
        {
            Char.yspeed = min(-16.0f,Char.yspeed);
            attack = true;
            attackFrame = "Lava";

        }
        else
        {
            //attack = true;
            attackFrame = "Faint";

        }
        while(Course.Lava.hitTest(_X * coursescale / 100 + Course._x,(_Y + 1) * coursescale / 100 + Course._y,true))
        {
            _Y = _Y - 1;
        }
    }
    AntiSquish = max(AntiSquish,0.0f);
    if(Course.Platforms.hitTest(_X * coursescale / 100 + Course._x,(_Y - Char.tall) * coursescale / 100 + Course._y,true) && Course.Platforms.hitTest(_X * coursescale / 100 + Course._x,_Y * coursescale / 100 + Course._y,true) && air == false && !((attackFrame == "Fall" || attackFrame == "Respawn" || attackFrame == "Faint" || attackFrame == "Drown" || attackFrame == "Pause") && attack == true) && (!Course.Platforms.invisground.hitTest(_X * coursescale / 100 + Course._x,(_Y - Char.tall) * coursescale / 100 + Course._y,true) || Invisible != true) && (!Course.Platforms.invisground.hitTest(Char._x * coursescale / 100 + Course._x,Char._y * coursescale / 100 + Course._y,true) || Invisible != true) && playpause == false && AntiSquish <= 0)
    {
        while(Course.Platforms.hitTest(_X * coursescale / 100 + Course._x,(_Y - Char.tall * Char._yscale / 100) * coursescale / 100 + Course._y,true))
        {
            Char._yscale = Char._yscale - 1;
        }
        if(Char._yscale < 70 && CharHP >= 1 && !(attack == true && attackFrame == "Squish"))
        {
            CharHP = CharHP - 2;
            hpcoincount = 0;
            Char.xspeed = 0;
            Char.yspeed = 0;
            attack = true;
            attackFrame = "Squish";

        }
        if(attack == true && attackFrame == "Squish")
        {
            Char._yscale = 100;
        }
        Squish = true;
    }
    else if(!Course.Platforms.hitTest(_X * coursescale / 100 + Course._x,(_Y - Char.tall) * coursescale / 100 + Course._y,true))
    {
        Squish = false;
        Char._yscale = Char._yscale + 5;
        Char._yscale = min(Char._yscale,100.0f);
    }
    if(playpause == true && Water == true)
    {
        Char.yspeed = 0;
    }
    if(!KeySPACE() && Fluddpow != 'H')
    {
        Power = Power + 1;
    }
    float repeats = m_ceil((m_abs(Char.yspeed) + m_abs(Char.xspeed)) / 5);
    //if(isNaN(repeats))
    //{
        repeats = 0;
    //}
    repeats = min(repeats,50.0f);
    repeats = max(repeats,1.0f);
    int i = 1;
    while(i <= repeats)
    {
        if(Course.Water.hitTest(_X * coursescale / 100 + Course._x,(_Y - Char.tall / 4) * coursescale / 100 + Course._y,true))
        {
            if(Water == false)
            {
            if(Char.yspeed > 7)
            {
                Char.yspeed = Char.yspeed * 0.7;
                //Course.FrontGFX.attachMovie("Med-Splash","Med-Splash" + Course.FrontGFX.getNextHighestDepth(),Course.FrontGFX.getNextHighestDepth(),{_x:_X - Course.FrontGFX._x,_y:_Y - Course.FrontGFX._y});
                //Charsound = new Sound(this);
                //Charsound.attachSound("sound - Splash");
                //Charsound.start(0,1);
                //Charsound.setVolume(CharVolume);
            }
            Char.yspeed = Char.yspeed * 0.9;
            }
            Water = true;
            doublejump = 0;
        }
        else
        {
            Water = false;
        }
        if((Course.Platforms.hitTest(_X * coursescale / 100 + Course._x,_Y * coursescale / 100 + Course._y,true) && (!Course.Platforms.invisground.hitTest(_X * coursescale / 100 + Course._x,_Y * coursescale / 100 + Course._y,true) || Invisible != true)) || Course.BPlatforms.hitTest(_X * coursescale / 100 + Course._x,_Y * coursescale / 100 + Course._y,true))
        {
            air = false;
            if(Char.yspeed < 16)
            {
            landtime = m_round(fallcount / 8) - 2;
            if(KeyUP())
            {
                landtime = landtime - 3;
                if((KeyRIGHT() || KeyLEFT()) && landtime >= 1)
                {
                    landtime = landtime - 2;
                    landtime = max(landtime,1.0f);
                }
            }
            landtime = landtime - min(m_abs(Char.xspeed / 1.5f),3.0f);
            if(Char.yspeed > 3 && landtime > 0 && attack == false)
            {
                landtime = max(landtime,1.0f);
                landtime = min(landtime,3.0f);
                //attack = true;
                attackFrame = "land";

            }
            if(Char.yspeed > 3 && landtime < 1 && attack == false && KeyUP())
            {
                landtime = 1;
                //attack = true;
                attackFrame = "land";
            }
            }
            fallcount = 0;
            hurtfallcount--;
            hurtfallcount = max(hurtfallcount,0.0f);
            //FallSquish();
            Char.yspeed = min(0.0f,Char.yspeed);
        }
        else
        {
            air = true;
        }
        while((Course.Platforms.hitTest(_X * coursescale / 100 + Course._x,(_Y - 3) * coursescale / 100 + Course._y,true) && !(Squish == true && (Char._yscale < 70 || (attack == true && attackFrame == "Squish"))) && (!Course.Platforms.invisground.hitTest(_X * coursescale / 100 + Course._x,(_Y - 3) * coursescale / 100 + Course._y,true) || Invisible != true)) || (Course.BPlatforms.hitTest(_X * coursescale / 100 + Course._x,(_Y - 3) * coursescale / 100 + Course._y,true) && Char.yspeed >= -3))
        {
            _Y = _Y - 1;
            if(!(attack == true && attackFrame == "Dive"))
            {
            Char.xspeed = Char.xspeed * 0.98;
            }
            else
            {
            Char.xspeed = Char.xspeed * 0.997;
            }
            //FallSquish();
            Char.yspeed = min(0.0f,Char.yspeed);
        }
        if(Water == true)
        {
            lockon = false;
        }
        if(lockon == true)
        {
            while(Course.Platforms.hitTest(_X * coursescale / 100 + Course._x,(_Y + 5) * coursescale / 100 + Course._y,true) && !Course.Platforms.hitTest(_X * coursescale / 100 + Course._x,(_Y - 1) * coursescale / 100 + Course._y,true) && (!Course.Platforms.invisground.hitTest(_X * coursescale / 100 + Course._x,(_Y + 5) * coursescale / 100 + Course._y,true) || Invisible != true))
            {
            _Y = _Y + 1;
            if(!(attack == true && attackFrame == "Dive"))
            {
                Char.xspeed = Char.xspeed * 0.98;
            }
            else
            {
                Char.xspeed = Char.xspeed * 0.998;
            }
           frame = "2";
            }
            while(Course.BPlatforms.hitTest(_X * coursescale / 100 + Course._x,(_Y + 5) * coursescale / 100 + Course._y,true) && !Course.BPlatforms.hitTest(_X * coursescale / 100 + Course._x,(_Y - 1) * coursescale / 100 + Course._y,true) && Char.yspeed >= -3)
            {
            _Y = _Y + 1;
            if(!(attack == true && attackFrame == "Dive"))
            {
                Char.xspeed = Char.xspeed * 0.98;
            }
            else
            {
                Char.xspeed = Char.xspeed * 0.998;
            }
           frame = "2";
            }
        }
        if(!(Squish == true && (Char._yscale < 70 || (attack == true && attackFrame == "Squish"))))
        {
            while(Course.Platforms.hitTest((_X + Char.wide - 1) * coursescale / 100 + Course._x,(_Y - Char.tall * Char._yscale / 200) * coursescale / 100 + Course._y,true) && (!Course.Platforms.invisground.hitTest((_X + Char.wide - 1) * coursescale / 100 + Course._x,(_Y - Char.tall * Char._yscale / 200) * coursescale / 100 + Course._y,true) || Invisible != true))
            {
            _X = _X - 1;
            }
            while(Course.Platforms.hitTest((_X - Char.wide + 1) * coursescale / 100 + Course._x,(_Y - Char.tall * Char._yscale / 200) * coursescale / 100 + Course._y,true) && (!Course.Platforms.invisground.hitTest((_X - Char.wide + 1) * coursescale / 100 + Course._x,(_Y - Char.tall * Char._yscale / 200) * coursescale / 100 + Course._y,true) || Invisible != true))
            {
            _X = _X + 1;
            }
        }
        if(Course.Platforms.hitTest((_X + Char.wide) * coursescale / 100 + Course._x,(_Y - Char.tall * Char._yscale / 200) * coursescale / 100 + Course._y,true) && (!Course.Platforms.invisground.hitTest((_X + Char.wide) * coursescale / 100 + Course._x,(_Y - Char.tall * Char._yscale / 200) * coursescale / 100 + Course._y,true) || Invisible != true))
        {
            if((m_abs(Char.xspeed) > 11 && (attack == false || attackFrame == "Run" || attackFrame == "Flying")) || (attack == true && (attackFrame == "Run" || attackFrame == "Flying") && m_abs(Char.xspeed) > 5) || (attack == true && attackFrame == "Lava" && m_abs(Char.xspeed) > 4 && air == false && Water == false) || (attack == true && attackFrame == "Flying" && m_abs(Char.xspeed) > 3 && air == false && Water == false))
            {
            HitWall();
            }
            else if(KeyRIGHT())
            {
            Char.xspeed = min(Char.xspeed,(- Char.xspeed) * bounce);
            Char.xspeed = groundFriction(Char.xspeed,3,1);
            }
            else
            {
            Char.xspeed = min(Char.xspeed - 1.0f,(- Char.xspeed) * bounce);
            }
        }
        if(Course.Platforms.hitTest((_X - Char.wide) * coursescale / 100 + Course._x,(_Y - Char.tall * Char._yscale / 200) * coursescale / 100 + Course._y,true) && (!Course.Platforms.invisground.hitTest((_X - Char.wide) * coursescale / 100 + Course._x,(_Y - Char.tall * Char._yscale / 200) * coursescale / 100 + Course._y,true) || Invisible != true))
        {
            if((m_abs(Char.xspeed) > 11 && (attack == false || attackFrame == "Run" || attackFrame == "Flying")) || (attack == true && (attackFrame == "Run" || attackFrame == "Flying") && m_abs(Char.xspeed) > 5) || (attack == true && attackFrame == "Lava" && m_abs(Char.xspeed) > 4 && air == false && Water == false) || (attack == true && attackFrame == "Flying" && m_abs(Char.xspeed) > 3 && air == false && Water == false))
            {
            HitWall();
            }
            else if(KeyLEFT())
            {
            Char.xspeed = min(Char.xspeed,(- Char.xspeed) * bounce);
            Char.xspeed = groundFriction(Char.xspeed,3,1);
            }
            else
            {
            Char.xspeed = max(Char.xspeed + 1,(- Char.xspeed) * bounce);
            }
        }
        if(Course.Platforms.hitTest(_X * coursescale / 100 + Course._x,(_Y - Char.tall + 1) * coursescale / 100 + Course._y,true) && (!Course.Platforms.invisground.hitTest(_X * coursescale / 100 + Course._x,(_Y - Char.tall - 1) * coursescale / 100 + Course._y,true) || Invisible != true))
        {
            //FallSquish();
            Char.yspeed = max(Char.yspeed,-3.0f);
        }
        if(Squish == false || Char.yspeed < -1)
        {
            while(Course.Platforms.hitTest(_X * coursescale / 100 + Course._x,(_Y - Char.tall * Char._yscale / 100) * coursescale / 100 + Course._y,true) && (!Course.Platforms.invisground.hitTest(_X * coursescale / 100 + Course._x,(_Y - Char.tall) * coursescale / 100 + Course._y,true) || Invisible != true))
            {
            _Y = _Y + 1;
            }
        }
        if(Course.Edge.hitTest(_X * coursescale / 100 + Course._x,(_Y - Char.tall / 2) * coursescale / 100 + Course._y,true) && !((attackFrame == "Fall" || attackFrame == "Respawn" || attackFrame == "Faint" || attackFrame == "Drown" || attackFrame == "Pause") && attack == true) && playpause == false)
        {
            attack = true;
            attackFrame = "Fall";

        }
        _X = _X + Char.xspeed / repeats;
        _Y = _Y + Char.yspeed / repeats;
        i++;
    }
    //abcd
    Char._x = _X;

    Char._y = _Y;
    //abcd
    if(air == false)
    {
        CharRotationCode();
    }
    else
    {
        icedive = false;
        if(attack == false || attackFrame != "SlingStar")
        {
            _rotation = groundFriction(_rotation,3,1.3);
        }
    }
    if(attack == false || attackFrame != "SlingStar")
    {
        _rotation = max(_rotation,-30.0f);
        _rotation = min(_rotation,30.0f);
    }
    if(CharHP <= 0 && !((attackFrame == "Fall" || attackFrame == "Respawn" || attackFrame == "Faint" || attackFrame == "Drown" || attackFrame == "Pause" || attackFrame == "none" || attackFrame == "hurt1" || attackFrame == "hurt2" || attackFrame == "hurt3") && attack == true) && playpause == false)
    {
        //attack = true;
        attackFrame = "Faint";

        Char._yscale = 100;
    }
    if(Invisible == true)
    {
        if(Course.Platforms.invisground.hitTest(Char._x * coursescale / 100 + Course._x,(Char._y - Char.tall / 2) * coursescale / 100 + Course._y,true) || Course.Platforms.invisground.hitTest(Char._x * coursescale / 100 + Course._x,(Char._y - Char.tall) * coursescale / 100 + Course._y,true) || Course.Platforms.invisground.hitTest((Char._x + Char.wide) * coursescale / 100 + Course._x,(Char._y - Char.tall / 2) * coursescale / 100 + Course._y,true) || Course.Platforms.invisground.hitTest((Char._x - Char.wide) * coursescale / 100 + Course._x,(Char._y - Char.tall / 2) * coursescale / 100 + Course._y,true))
        {
            PowerTimer = max(PowerTimer,2.0f);
            if(PowerTimer < 32)
            {
            PowerTimer = PowerTimer + 4;
            }
        }
    }
    if(CurrentPlayer == "Char")
    {/*
        //if(PowerTimer > 160 || m_round(PowerTimer / m_round(PowerTimer / 32)) % 2 == 0)
        if(PowerTimer > 160 || m_fmod(m_round(PowerTimer / m_round(PowerTimer / 32)),2) == 0)
        {
            if(Metal == true && Invincible != true)
            {
                Char.gotoAndStop("2");
            }
            if(Invisible == true)
            {
                if(Metal != true && Invincible != true)
                {
                    Char.gotoAndStop("1");
                }
                Char._alpha = 50;
            }
            if(Invincible == true)
            {
                if(Metal != true)
                {
                    Char.gotoAndStop("3");
                }
                else
                {
                    Char.gotoAndStop("4");
                }
            }
        }
        else
        {
            Char._alpha = 100;
            Char.gotoAndStop("1");
        }
        jumpspeed = Charjumpspeed;
    */}
    if(CurrentPlayer == "Char2")
    {/*
        //if(PowerTimer > 160 || m_round(PowerTimer / m_round(PowerTimer / 32)) % 2 == 0)
        if(PowerTimer > 160 || m_fmod(m_round(PowerTimer / m_round(PowerTimer / 32)),2) == 0)
        {
            if(Metal == true)
            {
            Char.gotoAndStop("6");
            }
            if(Invisible == true)
            {
            if(Metal != true && Invincible != true)
            {
                Char.gotoAndStop("5");
            }
            Char._alpha = 50;
            }
            if(Invincible == true)
            {
            if(Metal != true)
            {
                Char.gotoAndStop("7");
            }
            else
            {
                Char.gotoAndStop("8");
            }
            }
        }
        else
        {
            Char._alpha = 100;
            Char.gotoAndStop("5");
        }
        jumpspeed = Char2jumpspeed;
    */}
    if(Metal != true && Puddle == false && changestep < 0)
    {
        //StepSound = defaultstep;
    }
    else if(Metal == true)
    {
        //StepSound = "step-metalcap";
    }
    else if(Puddle == true)
    {
        //StepSound = "step - Water";
    }
    if(Metal == true || Invisible == true || Invincible == true || WingCap == true)
    {
        if(Invincible == true)
        {
            //Enemyhurt.attachMovie("EnemyHurtBox","Box" + Enemyhurt.getNextHighestDepth(),Enemyhurt.getNextHighestDepth(),{_x:_X - Course.BackGFX._x,_y:_Y - Course.BackGFX._y - 20,Char._yscale:100,Char._xscale:60,time:3});
        }
        PowerTimer = PowerTimer - 1;
        if(PowerTimer <= 0)
        {
            Metal = false;
            Invisible = false;
            Invincible = false;
            WingCap = false;
            PowerTimer = 0;
            PlayMusicAndIntro();
        }
    }
    if(((attackFrame == "Fall" || attackFrame == "Respawn" || attackFrame == "Faint" || attackFrame == "Drown" || attackFrame == "Pause" || attackFrame == "Squish" || attackFrame == "Sign" || attackFrame == "Item" || attackFrame == "Key" || attackFrame == "Door" || attackFrame == "FarDoor" || attackFrame == "FrontDoor" || attackFrame == "BigDoor" || attackFrame == "Painting" || attackFrame == "DiveSpin" || attackFrame == "grabbed" || attackFrame == "WarpPipe" || attackFrame == "Lava" || attackFrame == "hurt1" || attackFrame == "hurt2" || attackFrame == "hurt3" || attackFrame == "land" || attackFrame == "EJump" || attackFrame == "bosscinema" || attackFrame == "Talk" || attackFrame == "UnlockDoor" || attackFrame == "Run" || attackFrame == "SlingStar" || attackFrame == "Ground" || attackFrame == "Flying") && attack == true) || playpause == true || attackFrame == "none")
    {
        if((attackFrame != "Lava" && attackFrame != "hurt1" && attackFrame != "hurt2" && attackFrame != "hurt3" && attackFrame != "land" && attackFrame != "EJump" && attackFrame != "Run" && attackFrame != "SlingStar" && attackFrame != "Ground" && attackFrame != "Flying" && attack == true) || playpause == true || attackFrame == "none")
        {
            Char.yspeed = - gravity;
            if(Water == true)
            {
            Char.yspeed = 0;
            }
            Char.xspeed = 0;
        }
        if(playpause == false || attackFrame == "bosscinema" || attackFrame == "Talk" || attackFrame == "UnlockDoor")
        {
            //charClip.gotoAndStop(attackFrame);
        }
    }
    else if(attack == false)
    {
        //charClip.gotoAndStop(Fluddpow + frame);
    }
    else
    {
        //charClip.gotoAndStop(Fluddpow + attackFrame);
    }
    CharXscale = Char._xscale;
}
