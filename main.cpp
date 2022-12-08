#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <SDL2/SDL.h>
#include "SDL_Plotter.h"
#include "gameObject.h"
#include "snake.h"
#include "fruit.h"
#include "sound.h"
#include "font.h"
#include "scoreboard.h"
#include "functions.h"
using namespace std;

int main(int argc, char** argv) {
// Data Abstraction
    char key;
    int highScore;

    ifstream fin;
    ofstream fout;
    string input;

    SDL_Plotter g(NUM_ROW + 50, NUM_COL);
    snake hiss(3);
    Fruit apple;
    Direction dir;
    Game fun;
    Sound soundEffects(g);
    font text;
    Scoreboard currHighScore;
    color black;

    // Initialize
    srand(time(0));
    apple.eatenFruit(hiss);

    fin.open("SnakeSave.txt");
    currHighScore.initialize(fin);
    if(getline(fin, input, ':')){
        apple.initialize(fin);
        fun.initialize(fin);
        hiss.initialize(fin);
    }
    fin.close();

    fun.changeState(START);

    // Main Loop
    while(!g.getQuit()){
    //User Interface
        if(g.kbhit()){
            key = g.getKey();

            switch(key){
                case UP_ARROW:
                    if(hiss.getDir() != DOWN){
                        hiss.setDir(UP);
                    }
                    break;
                case DOWN_ARROW:
                    if(hiss.getDir() != UP){
                        hiss.setDir(DOWN);
                    }
                    break;
                case LEFT_ARROW:
                    if(hiss.getDir() != RIGHT){
                        hiss.setDir(LEFT);
                    }
                    break;
                case RIGHT_ARROW:
                    if(hiss.getDir() != LEFT){
                        hiss.setDir(RIGHT);
                    }
                    break;
                case SPACE:
                    if(fun.checkState() == PLAY){
                        fun.changeState(PAUSE);
                    }
                    else if(fun.checkState() == PAUSE){
                        fun.changeState(PLAY);
                    }
                    break;
                case P:
                    if(fun.checkState() != OVER){
                        fun.changeState(PLAY);
                    }
                    break;
                case R:
                    fun.changeState(PLAY);
                    hiss.reset();
                    fun.resetScore();
                    break;
            }
        }

        //Check States
        if(fun.checkState() == START){
            plotBackground(g);
            printPressStart(g, text);
            currHighScore.printHighScore(g, text);

        }
        else if(fun.checkState() == PLAY || fun.checkState() == PAUSE){
            if(fun.checkState() == PLAY){
                // Advance
                hiss.advance();

                // die check
                fun.changeState(hiss.checkDie(soundEffects, g));

                // Fruit
                if(hiss.getPoint(1).x == apple.getPoint().x &&
                   hiss.getPoint(1).y == apple.getPoint().y){
                    apple.eatenFruit(hiss);
                    hiss.incLength(1);
                    fun.addPoint();
                    soundEffects.eating(g);
                }

            }

        // Draw
            // Draw background
            for(int y = 0; y < NUM_ROW; y++){
                for(int x = 0; x < NUM_COL; x++){
                    if(y%SIZE == 0 || x%SIZE == 0){
                        g.plotPixel(x, y,20,250,20);
                    }
                    else{
                        g.plotPixel(x, y,0,0,0);
                    }
                }
            }

            // Draw Fruit
            apple.draw(g);

            // Draw Snake
            hiss.draw(g);

            //draws the white bar at bottom
            for(int y = NUM_ROW; y < NUM_ROW + SIZE; y++){
                    for(int x = 0; x < NUM_COL; x++){
                        g.plotPixel(x, y, 255, 255, 255);
                    }
                }
            printScoreText(g, text);
            printEscSave(g, text);
            printPause(g, text);
            fun.printScoreInGame(g);

        }
        else if(fun.checkState() == OVER){
            for(int y = 0; y < NUM_ROW + SIZE; y++){
                for(int x = 0; x < NUM_COL; x++){
                    g.plotPixel(x, y, 250, 20, 20);
                }
                if(fun.getScore() > currHighScore.getHighScore()){
                    currHighScore.setHighScore(fun.getScore());
                }
            }

            currHighScore.printHighScore(g, text);
            
            printGameOver(g, text);
            printYourScore(g, text);
            fun.printScorePostGame(g);
            printRestart(g, text);
        }

        // Score stuff
        if(fun.getScore() > highScore){
            highScore = fun.getScore();
        }

        g.update();
        g.Sleep(SPEED);
    }

    fout.open("SnakeSave.txt");
    currHighScore.saveToFile(fout);
    if(fun.checkState() != OVER){
        fout << "Saved Data: " << endl;
        apple.saveToFile(fout);
        fun.saveToFile(fout);
        hiss.saveToFile(fout);
    }
    fout.close();


    return 0;
}
