//
//  System.cpp
//  Game1
//
//  Created by Alex on 6/9/14.
//  Copyright (c) 2014 Alex. All rights reserved.
//

#include "System.h"
System::System(int width , int heigh , string title , Uint32 flags , bool FullScreen){
    if(FullScreen){
        
        window.create(VideoMode(),title,flags);
    }else{
        window.create(VideoMode(width,heigh),title,flags);
    }
}
System::System(int width , int heigh , string title){
    window.create(VideoMode(width,heigh),title);
}
void DrawSprite(RenderWindow &win,sf::Sprite &objtodraw){
    win.draw(objtodraw);
}
bool System::CreateSystem(int width , int heigh , string title , Uint32 flags, bool FullScreen) {
    if(FullScreen){
        
        window.create(VideoMode(),title,flags);
    }else{
        window.create(VideoMode(width,heigh),title,flags);
    }
    return true;
}
