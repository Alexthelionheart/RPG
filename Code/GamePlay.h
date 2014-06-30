//
//  GamePlay.h
//  Game1
//
//  Created by Alex on 6/11/14.
//  Copyright (c) 2014 Alex. All rights reserved.
//

#ifndef __Game1__GamePlay__
#define __Game1__GamePlay__

#include <iostream>
#include <vector>
#include <ctime> 
#include <math.h>
#include <cstdlib>
using namespace std;

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

#include "System.h" 
#include "Player.h"
#include "Environment.h"
#include "GameMusic.h"
#include "UserInterface.h"


class GamePlay{
public:
    GamePlay(string name);
    float PlayerSpeed{3.f};
    Environment env;
    System system;
    Player player;
    Event event;
    Font font;
    GameMusic BackgroundMusic;
    Clock clock;
    float oldTime;
    float currentTime;
    bool GamePlayInit();
    bool Start();
    bool running;
    void GameEventHandler();
    UserInterface UI;
private:
    void DrawStaticObjects();
    
};
#endif /* defined(__Game1__GamePlay__) */
