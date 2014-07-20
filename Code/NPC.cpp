//
//  NPC.cpp
//  Game1
//
//  Created by Alex on 6/11/14.
//  Copyright (c) 2014 Alex. All rights reserved.
//

#include "NPC.h"

// Basic Static NPC who can't move but you can talk to
   NPC::NPC(string name,string SpriteSheetPath , Vector2f Location){
	   NPC::Name = name;
	   NPC::SpriteSheetPath = SpriteSheetPath;
	   NPC::location = Location;
	   NPC::isMoving = false;

   }
   // Basic NPC who can move form coordinate to coordinate
   NPC::NPC(string name , string SpriteSheetPath , int Startx , int Starty , int Endx , int Endy){
	   NPC::Name = name;
	   NPC::SpriteSheetPath = SpriteSheetPath;
	   NPC::StartPoint = Vector2f(Startx,Starty);
	   NPC::EndPoint = Vector2f(Endx,Endy);
	   NPC::isMoving = true;
   }
   //Basic NPC who can move randomly in the preset Radius
   NPC::NPC(String name , string SpriteSheetPath , int x , int y , int width , int height){
	   NPC::Name = name;
	   NPC::SpriteSheetPath = SpriteSheetPath;
	   NPC::MovementBoundris = FloatRect(x , y , width , height);
	   NPC::isMoving = true;

   }
   //Enemy or Character
   NPC::NPC(string name , string SpriteSheetPath , Vector2f Location, int healf , int level , int def , int resist ,vector<Technique> Techs, vector<Magic> Mattacks, int speed , int res , bool hostile,int attack){
	   NPC::Name = name;
	   NPC::SpriteSheetPath = SpriteSheetPath;
	   NPC::healf = healf;
	   NPC::level = level;
	   NPC::def = def;
	   NPC::res = resist;
	   NPC::Techs = Techs;
	   NPC::Mattacks = Mattacks;
	   NPC::speed = speed;
	   NPC::hostile = hostile;
	   NPC::attack = attack;
	   NPC::Fighter = true;
	   NPC::isMoving = false;



   }

