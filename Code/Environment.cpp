//
//  Environment.cpp
//  Game1
//
//  Created by Alex on 6/9/14.
//  Copyright (c) 2014 Alex. All rights reserved.
//

#include "Environment.h"
#include "Player.h"
void Environment::DrawBackground( RenderWindow &win)
{


    win.draw(BackgroundSprite);

}
bool Environment::LoadTreeFiles(string filepath , RenderWindow &win , int x , int y , int w , int h)
{
    if (!TreeTexture.loadFromFile(filepath, IntRect(x, y , w, h)))
    {
        cout << "Error while loading the Tree Texture in Envirement.cpp " << &err();
        return false;
    }


    Tree.setTexture(TreeTexture);
    return true;
}
bool Environment::LoadBackgroundFile(string filepath, RenderWindow &win)
{
    if (!BackgroundTexture.loadFromFile(  filepath))
    {
        cout << "Error While Loading the Image from the path " <<  &err() << endl;
        return false;
    }
    BackgroundTexture.setRepeated(true);

    BackgroundSprite.setTexture(BackgroundTexture);

    BackgroundSprite.setScale(win.getSize().x / 600.f, win.getSize().y / 600.f);
    BackgroundSprite.setOrigin(0, 0);
    return true;
}

Environment::Environment()
{

}


void Environment::DrawTrees(  RenderWindow &win, int x , int y)
{
    vector<int> CurrentClocation;
    CurrentClocation.push_back(x);
    CurrentClocation.push_back(y);
    TreeLocations.push_back(CurrentClocation);
    Tree.setPosition(x, y);
    win.draw(Tree);



}

void Environment::RefreshTrees(RenderWindow &win)
{
    for (unsigned int i = 0; i < TreeLocations.size() ; i++ )
    {



        //    cout << "Redrawing a Tree at X: " << TreeLocations.at(i).at(0) << "and Y: " << TreeLocations.at(i).at(1) << endl;
        Tree.setPosition(TreeLocations.at(i).at(0), TreeLocations.at(i).at(1));
        win.draw(Tree);






    }




}
/*
 return 0 if no collision
 1=left
 2=right
 4=up
 8=down
 */


int Environment::CheckforColisionwithTrees(Player &p)
{



    for (unsigned int i = 0; i < TreeLocations.size() ; i++ ) //TO DO Change to an iterators Loop
    {
        Tree.setPosition(TreeLocations.at(i).at(0), TreeLocations.at(i).at(1));
        TreeBounds = Tree.getGlobalBounds();
        // Player.Direction x=0 y=1
        TreeBounds.left = TreeBounds.left + 18;
        TreeBounds.top = TreeBounds.top + 47;
        TreeBounds.width -= 28;
        TreeBounds.height -= 47;
        FloatRect CollisionArea;
        if (TreeBounds.intersects(p.Bounds , CollisionArea))
        {
            if (CollisionArea.width > CollisionArea.height)
            {
                //Collision is ether form top or bottom
                if (CollisionArea.contains({CollisionArea.left , p.psprite.getPosition().y}))
                {
                    //Something is Coliding with the Bottom of the Tree
                    return 8;
                } else
                {
                    //Something is coliding with the Top of the Tree
                    return 4;
                }


            }
            if (CollisionArea.width < CollisionArea.height)
            {
                //Collision is either form left or Right
                if (CollisionArea.contains({p.psprite.getPosition().x + p.psprite.getGlobalBounds().width - 1.f, CollisionArea.top + 1.f}))
                {
                    //The Left Side of the Tree is hit
                    return 1;
                } else
                {
                    return 2;
                }

            }







        }

    }

    return 0;
}

