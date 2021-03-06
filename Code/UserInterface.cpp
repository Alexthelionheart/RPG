//
//  UserInterface.cpp
//  Game1
//
//  Created by Alex on 6/16/14.
//  Copyright (c) 2014 AlexTheLionHeart. All rights reserved.
//

#include "UserInterface.h"
#include <iostream>
#include <SFML/Graphics.hpp>


bool UserInterface::LoadSptireFiles(string SpritesheetPath, RenderWindow &win )
{
    if (!SptireSheet.loadFromFile(   SpritesheetPath))
    {
        cout << "Error While Loading The Png" << endl;
        return false;
    }
    DialogSprite.setTexture(SptireSheet);
    NextarrowSprite.setTexture(SptireSheet);
    MenuSprite.setTexture(SptireSheet);


    dialog_box_Rect = IntRect( 2 , 2 , 578 , 96 );
    combobox_default_Rect = IntRect( 582 , 2 , 288 , 112 );
    confirm_bg_Rect = IntRect( 872 , 2 , 192 , 64 );
    slider_default_Rect = IntRect( 1066 , 2 , 199 , 52 );
    listbox_default_Rect = IntRect( 1267 , 2 , 143 , 84 );
    button_default_Rect = IntRect( 1412 , 2 , 130 , 110 );
    button_small_Rect = IntRect( 1544 , 2 , 63 , 110 );
    button_x_Rect = IntRect( 1609 , 2 , 24 , 94 );
    input_Rect = IntRect( 872 , 68 , 130 , 40 );
    bar_hp_mp_Rect = IntRect( 1066 , 56 , 106 , 33 );
    menu_xp_Rect = IntRect( 2 , 100 , 106 , 10 );
    scrollbar_default_Rect = IntRect( 1174 , 56 , 75 , 15 );
    checkbox_default_Rect = IntRect( 1004 , 68 , 22 , 38 );
    arrowsright_Rect = IntRect( 1028 , 91 , 94 , 22 );
    arrowsleft_Rect = IntRect( 1124 , 91 , 94 , 22 );
    arrowsup_Rect = IntRect( 1220 , 88 , 92 , 24 );
    arrowsdown_Rect = IntRect( 1314 , 88 , 92 , 24 );



    DialogSprite.setTextureRect(dialog_box_Rect);
    NextarrowSprite.setTextureRect(arrowsdown_Rect);
    MenuSprite.setTextureRect(confirm_bg_Rect);





    //Resizing
    DialogSprite.setScale((win.getSize().x - 10) / DialogSprite.getGlobalBounds().width * 1.f, 2);


    return true;
}
void UserInterface::CreateADialog(string Text , int fontsize, Font font, RenderWindow &win)
{

    sf::Text text;
    text.setFont(font);
    text.setString(Text);
    text.setCharacterSize(fontsize);
    DialogSprite.setPosition(0 + 5, win.getSize().y - DialogSprite.getGlobalBounds().height);
    text.setPosition(DialogSprite.getGlobalBounds().left + 20, DialogSprite.getGlobalBounds().top + 30);
    win.draw(DialogSprite);
    win.draw(text);
    win.display();
    win.clear();

}

bool UserInterface::LoadTextFile(const char *filepath)
{
    File.open(filepath);
    if (!File.is_open())
    {
        cout << "Failed To open The text File from That" << filepath << endl;
        return false;
    }
    string WordString;
    TextString = "";



    while (File.good())
    {
        File >> WordString;
        //if It is a Tag
        /*
                                                                            Tags
         * <<IMG:FileName.png>> - The character image who is saying the lines
         * <<NewBox>> - Create a new Dialog box
         * <<Y?N>> - choose Yes or NO
         */
        if (WordString.find("<<") != string::npos)
        {
            cout << WordString << " is a tag" << endl;
            //Chanking if it is a Image Tag
            if (WordString.find("IMG:"))
            { 
                WordString.erase(0, 6);
                WordString = WordString.substr(0, WordString.size() - 2);
                if (!CharactersFaceTexture.loadFromFile(  "Images/" + WordString))
                {
                    cout << "Failed To load the character file form the file " << WordString << " Which Was presified in the txt file ";
                    return false;
                }
                CharactersFace.setTexture(CharactersFaceTexture);

            }

        }
        else
        {
            TextString = TextString + WordString + " ";
        }




    }

    return true;
}

void UserInterface::CreateADialogFromTextFile(int fontsize , Font font , RenderWindow &win, int TheChar )
{
    sf::Text textline1;
    sf::Text textline2;
    sf::Text textline3;
    if (TheChar < TextString.length() - 1 && dialogLine == 1)
    {
        if (TextString[TheChar] == '|')
        {
            dialogLine++;
        }
        else
        {
            Drawstringline1 = Drawstringline1 + TextString[TheChar];
        }

    }
    else if (TheChar < TextString.length() - 1 && dialogLine == 2)
    {
        if (TextString[TheChar] == '|')
        {
            dialogLine++;
        }
        else
        {
            Drawstringline2 = Drawstringline2 + TextString[TheChar];
        }
    }
    else if (TheChar < TextString.length() - 1 && dialogLine == 3)
    {

        Drawstringline3 = Drawstringline3 + TextString[TheChar];
    }
    else
    {

        firstDraw = false;
    }
    textline1.setFont(font);
    textline1.setString(Drawstringline1);
    textline1.setCharacterSize(fontsize);
    textline2.setFont(font);
    textline2.setString(Drawstringline2);
    textline2.setCharacterSize(fontsize);
    textline3.setFont(font);
    textline3.setString(Drawstringline3);
    textline3.setCharacterSize(fontsize);

    DialogSprite.setPosition(0 + 5, win.getSize().y - DialogSprite.getGlobalBounds().height);
    textline1.setPosition(DialogSprite.getGlobalBounds().left + 20 + CharactersFace.getGlobalBounds().width, DialogSprite.getGlobalBounds().top + 30);
    textline2.setPosition(DialogSprite.getGlobalBounds().left + 20 + CharactersFace.getGlobalBounds().width, DialogSprite.getGlobalBounds().top + 65);
    textline3.setPosition(DialogSprite.getGlobalBounds().left + 20 + CharactersFace.getGlobalBounds().width, DialogSprite.getGlobalBounds().top + 100);
    CharactersFace.setPosition(DialogSprite.getGlobalBounds().left + 20, DialogSprite.getGlobalBounds().top + 30);


    win.draw(DialogSprite);
    win.draw(CharactersFace);
    win.draw(textline1);
    win.draw(textline2);
    win.draw(textline3);
    win.display();
    win.clear();

}






