//
//  GamePlay.cpp
//  Game1
//
//  Created by Alex on 6/11/14.
//  Copyright (c) 2014 Alex. All rights reserved.
//

#include "GamePlay.h"
#include <fstream>
#include <cstdio>
using namespace  std;
using namespace  sf;

int amounOfTrees {100};

GamePlay::GamePlay(string name):
    system(600, 600, "Game", Style::Titlebar | Style::Close | Style::Fullscreen, false)
{
    running = true;
}
/*
 return 0 if no collision
 1=left
 2=right
 4=up
 8=down
 */


bool GamePlay::GamePlayInit()
{

    system.window.setFramerateLimit(60);
    player = Player("Images/Player_Male.png", 32 , 0, 0, 2);
    if (!player.LoadFile("Images/Player_Male.png"))
    {
        cout << "Failed Loading Players SpriteSheet" << endl;
        running = false;
        return false;
    }
    GameMusic BackgroundMusic;
    if (!BackgroundMusic.Steamfromfile(   "Music/ClearDay_Moosader.ogg"))
    {
        cout << "Failed to load the background Music" << endl;
        running = false;
        return false;
    }
    BackgroundMusic.playing = false;
    if (!env.LoadBackgroundFile("Images/BackgroundGrass.png" , system.window))
    {
        cout << "Failed to load the Background Image " << endl;
        running = false;
        return false;
    }
    if (!env.LoadTreeFiles(   "Images/EnvironmentTiles_Moosader.png", system.window, 0, 64, 64, 64))
    {
        cout << "Failed to load Tree Sprite Files " << endl;
        running = false;
        return false;
    }
    if (!UI.LoadSptireFiles("Images/DialogBox.png", system.window))
    {
        cout << "Failed to load the UI elements either the Xml file or the png" << endl;


        return false;
    }
    if (!font.loadFromFile(   "Font/sansation.ttf"))
    {
        cout << "Error While Loading the Fond File " << endl;
        return false;
    }
    //Drawing Trees
    //
    //    int xRan;
    //    int yRan;
    //  srand( time(0));
    //  for(unsigned int i = 0 ; i < amounOfTrees;++i){
    //  xRan=rand()%system.window.getSize().x;
    //    yRan= rand()%system.window.getSize().y;
    //
    //    env.DrawTrees(system.window, xRan , yRan);
    //
    //    }
    env.DrawTrees(system.window, 312, 231);
    env.DrawTrees(system.window, 521, 313);
    env.DrawTrees(system.window, 412, 543);
    env.DrawTrees(system.window, 543, 231);
    env.DrawTrees(system.window, 231, 412);
    env.DrawTrees(system.window, 312, 123);

    oldTime = 0;
    currentTime = 0;
    system.window.setMouseCursorVisible(false);
    BackgroundMusic.Steamfromfile(   "Music/ClearDay_Moosader.ogg");
    BackgroundMusic.setLoop(true);

    running = true;
    return true;
}

void GamePlay::DrawStaticObjects()
{
    env.DrawBackground(system.window);
    system.window.draw(player.psprite);
    env.RefreshTrees(system.window);

}
void GamePlay::GameEventHandler()
{

    if (env.CheckforColisionwithTrees(player) > 0)
    {
        if (event.key.code == Keyboard::Space )
        {
            UI.firstDraw = true;
           
            string TestString;
            UI.File >> TestString;

           
            cout << "File Size Is " << TestString.length() << endl;
            cout << "The Test String is " << TestString << endl;
           

            while (event.key.code != Keyboard::RShift)
            {
                system.window.pollEvent(event);




                
                UI.CreateADialogFromTextFile( 29, font, system.window,"Dialogs/Trees/Normal.txt");
                DrawStaticObjects();


            }

        }
        UI.File.close();
    }






}






bool GamePlay::Start()
{


    while ( system.window.isOpen())
    {

        system.window.pollEvent(event);

        if (event.type == Event::Closed)
        {
            system.window.close();

        }

        currentTime =  clock.restart().asSeconds();


        //      float timepassed =  ( oldTime - currentTime);
        //        cout << "Time passed is " << timepassed << endl;

        if (oldTime >= .20)
        {
            player.Move(system.window, true, env.CheckforColisionwithTrees(player));

            oldTime = 0;

        }
        else
        {
            player.Move(system.window, false, env.CheckforColisionwithTrees(player));
        }


        GameEventHandler();

        if (Keyboard::isKeyPressed(Keyboard::Key::M))
        {
            if (BackgroundMusic.playing)
            {
                BackgroundMusic.mute();
                BackgroundMusic.playing = false;
            }
            else
            {
                BackgroundMusic.play();
                BackgroundMusic.playing = true;
            }
        }


        oldTime +=  currentTime ;
        if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
        {
            system.window.close();
            break;

        }
        DrawStaticObjects();
        system.window.display();
        system.window.clear();

    }
    BackgroundMusic.stop();
    running = false;
    return true;
}





