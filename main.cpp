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
    font ffont;

    color black;

    // Initialize
    srand(time(0));
    apple.eatenFruit();

    fin.open("SnakeSave.txt");
    getline(fin, input, ':');
    fin >> highScore;
    if(getline(fin, input, ':')){
        apple.initialize(fin);
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
                    fun.changeState(PLAY);
                    break;
            }
        }

        //Check States
        if(fun.checkState() == START){
            for(int y = 0; y < NUM_ROW + SIZE; y++){
                for(int x = 0; x > NUM_COL; x++){
                    g.plotPixel(x, y, 255, 255, 255);
                }
            }
            ffont.printFontLetter("p.txt", 190, 150, g, 3, 0, 0, 0);
            ffont.printFontLetter("r.txt", 310, 150, g, 3, 0, 0, 0);
            ffont.printFontLetter("e.txt", 430, 150, g, 3, 0, 0, 0);
            ffont.printFontLetter("s.txt", 550, 150, g, 3, 0, 0, 0);
            ffont.printFontLetter("s.txt", 670, 150, g, 3, 0, 0, 0);
            //newline
            ffont.printFontLetter("quote,txt", 230, 250, g, 1, 0, 0, 0);
            ffont.printFontLetter("p.txt", 250, 250, g, 3, 0, 0, 0);
            ffont.printFontLetter("quote,txt", 370, 250, g, 1, 0, 0, 0);
            ffont.printFontLetter("t.txt", 490, 250, g, 3, 0, 0, 0);
            ffont.printFontLetter("o.txt", 610, 250, g, 3, 0, 0, 0);
            //newline
            ffont.printFontLetter("s.txt", 190, 350, g, 3, 0, 0, 0);
            ffont.printFontLetter("t.txt", 310, 350, g, 3, 0, 0, 0);
            ffont.printFontLetter("a.txt", 430, 350, g, 3, 0, 0, 0);
            ffont.printFontLetter("r.txt", 550, 350, g, 3, 0, 0, 0);
            ffont.printFontLetter("t.txt", 670, 350, g, 3, 0, 0, 0);

        }
        else if(fun.checkState() == PLAY || fun.checkState() == PAUSE){
            if(fun.checkState() == PLAY){
                // Advance
                hiss.advance();

                // die check
                fun.changeState(hiss.checkDie(soundEffects, g));

                // Fruit
                if(hiss.getFirstPt().x == apple.getPoint().x &&
                   hiss.getFirstPt().y == apple.getPoint().y){
                    apple.eatenFruit();
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
            apple.drawFriut(apple.getPoint() , g);

            // Draw Snake
            hiss.draw(g);

            //draws the white bar at bottom
            for(int y = NUM_ROW; y < NUM_ROW + SIZE; y++){
                    for(int x = 0; x < NUM_COL; x++){
                        g.plotPixel(x, y, 255, 255, 255);
                    }
                }

            ffont.printFontLetter("s.txt", 300, 710, g, 1, 0, 0, 0);
            ffont.printFontLetter("c.txt", 340, 710, g, 1, 0, 0, 0);
            ffont.printFontLetter("o.txt", 380, 710, g, 1, 0, 0, 0);
            ffont.printFontLetter("r.txt", 420, 710, g, 1, 0, 0, 0);
            ffont.printFontLetter("e.txt", 460, 710, g, 1, 0, 0, 0);

            if(fun.getScore() < 10){
                stringstream ss;
                int num = fun.getScore();
                ss << num;
                string name = ss.str();
                ffont.printFont(name + ".txt", 520, 702, g, 3, 0, 0, 0);
                ss.flush();

            }

        }
        else if(fun.checkState() == OVER){
            for(int y = 0; y < NUM_ROW + SIZE; y++){
                for(int x = 0; x < NUM_COL; x++){
                    g.plotPixel(x, y, 250, 20, 20);
                }
            }

            ffont.printFontLetter("g.txt", 100, 150, g, 5, 0, 0, 0);
            ffont.printFontLetter("a.txt", 300, 150, g, 5, 0, 0, 0);
            ffont.printFontLetter("m.txt", 500, 150, g, 5, 0, 0, 0);
            ffont.printFontLetter("e.txt", 700, 150, g, 5, 0, 0, 0);
            //new line
            ffont.printFontLetter("o.txt", 100, 300, g, 5, 0, 0, 0);
            ffont.printFontLetter("v.txt", 300, 300, g, 5, 0, 0, 0);
            ffont.printFontLetter("e.txt", 500, 300, g, 5, 0, 0, 0);
            ffont.printFontLetter("r.txt", 700, 300, g, 5, 0, 0, 0);
        }

        // Score stuff
        if(fun.getScore() > highScore){
            highScore = fun.getScore();
        }

        g.update();
        g.Sleep(SPEED);
    }

    fout.open("SnakeSave.txt");
    fout << "High Score: " << highScore << endl;
    if(fun.checkState() != OVER){
        fout << "Saved Data: " << endl;
        apple.saveToFile(fout);
        hiss.saveToFile(fout);
    }
    fout.close();


    return 0;
}
