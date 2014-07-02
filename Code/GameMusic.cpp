//
//  GameMusic.cpp
//  Game1
//
//  Created by Alex on 6/9/14.
//  Copyright (c) 2014 Alex. All rights reserved.
//


#include "GameMusic.h"
void GameMusic::stop()
{
    BackgroundMusic.stop();
}
void GameMusic::mute()
{
    BackgroundMusic.pause();
}

void GameMusic::play()
{
    BackgroundMusic.play();
}
bool GameMusic::Steamfromfile(string path)
{
    if (!BackgroundMusic.openFromFile(path))
    {
        return false;
    }
    return true;
}
void GameMusic::setLoop(bool state)
{
    BackgroundMusic.setLoop(state);
}