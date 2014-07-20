//
//  NPC.h
//  Game1
//
//  Created by Alex on 6/11/14.
//  Copyright (c) 2014 Alex. All rights reserved.
//

#ifndef __Game1__NPC__
#define __Game1__NPC__

#include <iostream>
#include "Technique.h"
#include "Magic.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class NPC {
public:
    bool Fighter;
    string Name;
    int level;
    int healf;
    bool inYourParty;
    vector<Technique> Techs;
    vector<Magic> Mattacks;
    int attack;
    int speed;
    int def;
    int res;
    Vector2f location;
    Sprite sprite;
    string SpriteSheetPath;
    bool isMoving;
    Vector2f StartPoint;
    Vector2f EndPoint;
    FloatRect MovementBoundris;
    bool hostile;

    // Basic Static NPC who can't move but you can talk to
    NPC(string name,string SpriteSheetPath , Vector2f Location);
    // Basic NPC who can move form coordinate to coordinate
    NPC(string name , string SpriteSheetPath , int Startx , int Starty , int Endx , int Endy);
    //Basic NPC who can move randomly in the preset Radius
    NPC(String name , string SpriteSheetPath , int x , int y , int width , int height);
    //Enemy or Character
    NPC(string name , string SpriteSheetPath , Vector2f Location, int healf , int level , int def , int resist ,vector<Technique> Techs, vector<Magic> Mattacks, int speed , int res , bool hostile,int attack);

    
};




#endif /* defined(__Game1__NPC__) */
