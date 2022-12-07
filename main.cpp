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
                    fun.changeState(START);
                    hiss.reset();
                    fun.resetScore();
                    break;
            }
        }

        //Check States
        if(fun.checkState() == START){


            for(int y = 0; y < NUM_ROW + SIZE; y++){
                for(int x = 0; x < NUM_COL; x++){
                    g.plotPixel(x, y, 255, 255, 255);
                }
            }
            text.printFontLetter("P.txt", 190, 150, g, 3, 0, 0, 0);
            text.printFontLetter("r.txt", 310, 150, g, 3, 0, 0, 0);
            text.printFontLetter("e.txt", 430, 150, g, 3, 0, 0, 0);
            text.printFontLetter("s.txt", 550, 150, g, 3, 0, 0, 0);
            text.printFontLetter("s.txt", 670, 150, g, 3, 0, 0, 0);
            //newline
            text.printFontLetter("p.txt", 250, 250, g, 3, 0, 0, 0);
            text.printFontLetter("quote.txt", 230, 250, g, 1, 0, 0, 0);
            text.printFontLetter("t.txt", 490, 250, g, 3, 0, 0, 0);
            text.printFontLetter("quote.txt", 370, 250, g, 1, 0, 0, 0);
            text.printFontLetter("o.txt", 610, 250, g, 3, 0, 0, 0);
            //newline
            text.printFontLetter("s.txt", 190, 350, g, 3, 0, 0, 0);
            text.printFontLetter("t.txt", 310, 350, g, 3, 0, 0, 0);
            text.printFontLetter("a.txt", 430, 350, g, 3, 0, 0, 0);//need A
            text.printFontLetter("r.txt", 550, 350, g, 3, 0, 0, 0);
            text.printFontLetter("t.txt", 670, 350, g, 3, 0, 0, 0);

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

            text.printFontLetter("s.txt", 50, 710, g, 1, 0, 0, 0);
            text.printFontLetter("c.txt", 90, 710, g, 1, 0, 0, 0);
            text.printFontLetter("o.txt", 130, 710, g, 1, 0, 0, 0);
            text.printFontLetter("r.txt", 170, 710, g, 1, 0, 0, 0);
            text.printFontLetter("e.txt", 210, 710, g, 1, 0, 0, 0);


            if(fun.getScore() < 10){
                text.printScoreSingle(fun.getScore(), text, g, 300, 702);
            }
            else if(fun.getScore() < 100){
                text.printScoreDouble(fun.getScore(), text, g, 250, 702, 300, 702);
            }
            else{
                text.printScoreTriple(fun.getScore(), text, g, 250, 702, 300, 702, 350, 702);
            }

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

            text.printFontLetter("g.txt", 100, 150, g, 5, 0, 0, 0);
            text.printFontLetter("a.txt", 300, 150, g, 5, 0, 0, 0); //need A
            text.printFontLetter("m.txt", 500, 150, g, 5, 0, 0, 0); //need M
            text.printFontLetter("e.txt", 700, 150, g, 5, 0, 0, 0);
            //new line
            text.printFontLetter("o.txt", 100, 300, g, 5, 0, 0, 0);
            text.printFontLetter("v.txt", 300, 300, g, 5, 0, 0, 0);
            text.printFontLetter("e.txt", 500, 300, g, 5, 0, 0, 0);
            text.printFontLetter("r.txt", 700, 300, g, 5, 0, 0, 0);

            text.printFontLetter("y.txt", 75, 500, g, 2, 0, 0, 0);
            text.printFontLetter("o.txt", 150, 500, g, 2, 0, 0, 0); //need A
            text.printFontLetter("u.txt", 225, 500, g, 2, 0, 0, 0); //need M
            text.printFontLetter("r.txt", 300, 500, g, 2, 0, 0, 0);
            //new line
            text.printFontLetter("s.txt", 425, 500, g, 2, 0, 0, 0);
            text.printFontLetter("c.txt", 500, 500, g, 2, 0, 0, 0);
            text.printFontLetter("o.txt", 575, 500, g, 2, 0, 0, 0);
            text.printFontLetter("r.txt", 650, 500, g, 2, 0, 0, 0);
            text.printFontLetter("e.txt", 725, 500, g, 2, 0, 0, 0);

            if(fun.getScore() < 10){
                text.printScoreSingle(fun.getScore(), text, g, 850, 495, 5);
            }
            else if(fun.getScore() < 100){
                text.printScoreDouble(fun.getScore(), text, g, 810, 495, 875, 495, 5);
            }
            else{
                text.printScoreTriple(fun.getScore(), text, g, 810, 500, 860, 500, 910, 500, 4);
            }

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
