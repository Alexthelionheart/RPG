//
//  Environment.h
//  Game1
//
//  Created by Alex on 6/9/14.
//  Copyright (c) 2014 Alex. All rights reserved.
//

#ifndef __Game1__Environment__
#define __Game1__Environment__

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <vector>
 
#include "Player.h"
using namespace std;
using namespace sf;

class Environment {
public:
    // Defult Constructer (there are no defult values needed to be passed the main point of this is to draw inviderment sprites like trees grass , background etc.
    Environment();
    //Textures
    Texture TreeTexture;
    Texture BackgroundTexture;
    // Sprites
    Sprite BackgroundSprite;
    Sprite Tree;
    FloatRect TreeBounds;
    //Loaction the the Sprites Drawn
    vector<vector<int>> TreeLocations;
    
    
    // Loads files so Objects can be drawn to the screen
    
    bool LoadBackgroundFile(string filepath ,  RenderWindow &win);
    bool LoadTreeFiles(string filepath , RenderWindow &win , int x , int y , int w , int h);
    
    
    
    
    // Static Objects that don't need to be interacted with
    void DrawBackground( RenderWindow &win);
    void DrawBackground(string filepath, int x , int y, RenderWindow &win);
    void DrawTrees(  RenderWindow &win, int x ,int y);
    
    //Checking For Collision
    int CheckforColisionwithTrees(Player &p );
    
    void RefreshTrees(RenderWindow &win);
    
    
};


#endif /* defined(__Game1__Environment__) */
