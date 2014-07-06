//
//  UserInterface.h
//  Game1
//
//  Created by Alex on 6/16/14.
//  Copyright (c) 2014 AlexTheLionHeart. All rights reserved.
//

#ifndef __Game1__UserInterface__
#define __Game1__UserInterface__

#include <iostream>
#include <SFML/Graphics.hpp>

#include <cstdio>
#include <fstream>
#include <cstdio>

using namespace std;
using namespace sf;

class UserInterface
{
public:
    string filepath;
    bool ChangeMusic;
    string NewMusicPath;
    void CreateADialog(string Text , int fontsize, Font font, RenderWindow &win);
    void CreateADialogFromTextFile(  int fontsize , Font font , RenderWindow &win,const char *filepath);
    bool LoadSptireFiles(string Spritesheet, RenderWindow &win );
    
    IntRect dialog_box_Rect;
    IntRect combobox_default_Rect;
    IntRect confirm_bg_Rect;
    IntRect slider_default_Rect;
    IntRect listbox_default_Rect;
    IntRect button_default_Rect;
    IntRect button_small_Rect;
    IntRect button_x_Rect;
    IntRect input_Rect;
    IntRect bar_hp_mp_Rect;
    IntRect menu_xp_Rect;
    IntRect scrollbar_default_Rect;
    IntRect checkbox_default_Rect;
    IntRect arrowsright_Rect;
    IntRect arrowsleft_Rect;
    IntRect arrowsup_Rect;
    IntRect arrowsdown_Rect;
    std::ifstream File;
    bool firstDraw;


    Texture SptireSheet;
    Texture CharactersFaceTexture;
    Sprite DialogSprite;
    Sprite NextarrowSprite;
    Sprite MenuSprite;
    Sprite CharactersFace;

    /*
    saparate each Part of a dialog with a <<NewBox>> if a txt file
    Use \n if a string
    */
    //To DO add image
    //Plans and a tag <<Image:filename.png>> and read it form the txt





};




#endif /* defined(__Game1__UserInterface__) */
