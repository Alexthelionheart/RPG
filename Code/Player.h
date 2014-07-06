//
//  Player.h
//  Game1
//
//  Created by Alex on 6/9/14.
//  Copyright (c) 2014 Alex. All rights reserved.
//

#ifndef __Game1__Player__
#define __Game1__Player__

#include <iostream>

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <vector>
#include "System.h"
#include "NPC.h"


using namespace sf;
using namespace std;

class Player
{
public:

    int PlayerSpeed;
    Sprite psprite;
    Texture ptexture;
    int score;
    int sourceX;
    int sourceY;
    int sizePreSprite;
    FloatRect Bounds;
    Player(string filepath , int siplzePreSprite , int sourceX, int sourceY, int PlayerSpeed );
    Player();
    bool LoadFile(string filepath);
    void Move(RenderWindow &win , bool animate , int colliosionSide);
    void Move(RenderWindow &win , bool animate );
    void checkforcolision(RenderWindow &win);
    std::vector<NPC> Party;



};



#endif /* defined(__Game1__Player__) */
