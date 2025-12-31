#include "Commons.hpp"
#include "Game.hpp"

int main(int argc, char** argv){
    Game game;
    std::string debugSet;
    bool debug = false;

    if(argc > 1){
        debugSet = argv[1];
        if(debugSet == "-d" || debugSet == "-D"){
            debug = true;
        }
    }

    game.run(debug);
    return 0;
}