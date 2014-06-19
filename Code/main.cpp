#include "GamePlay.h"
using namespace sf;
using namespace std;

float PlayerSpeed{3.f};

int main(int, char const**)
{
    
    GamePlay game("Game");
    
    if(!game.GamePlayInit()){
        cout << "Error While Initilizing the gameplay" << endl;
        return EXIT_FAILURE;
    }
    
    
    while( game.running){
        game.Start();

        
    }
 
    
    
    
    return EXIT_SUCCESS;
}
