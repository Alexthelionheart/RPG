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

using namespace std;

class NPC {
    bool Fighter;
    string Name;
    int level;
    int healf;
    string DialogPrefix;
    bool inYourParty;
    vector<Technique> Techs;
    vector<Magic> Mattacks;
    int attack;

    
    
    
};




#endif /* defined(__Game1__NPC__) */
