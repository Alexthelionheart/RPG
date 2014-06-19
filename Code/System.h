//
//  System.h
//  Game1
//
//  Created by Alex on 6/9/14.
//  Copyright (c) 2014 Alex. All rights reserved.
//

#ifndef __Game1__System__
#define __Game1__System__

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window.hpp>
using namespace sf;
using namespace std;
class System {
public:
    RenderWindow window;
    
    void DrawSprite(RenderWindow &win,sf::Sprite &objtodraw);
    System(int width , int heigh , string title , Uint32 flags, bool FullScreen);
    System(int width , int heigh , string title);
    bool CreateSystem(int width , int heigh , string title , Uint32 flags, bool FullScreen);
    
    
};

#endif /* defined(__Game1__System__) */
