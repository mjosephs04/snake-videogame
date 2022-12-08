/* AUTHOR: Caleb Beckering, Ruth Edwards, Karina Garza, Mark Josephs
 * ASSIGNMENT TITLE: Group Project: Snake
 * ASSIGNMENT DESCRIPTION: Create a snake-themed game
 * DUE DATE: 12-07-22
 * DATE CREATED: 11-03-22
 * DATE LAST MODIFIED: 12-07-22
 */

/*
 * Data Abstraction: defining all classes and streams needed for snake
 *      1 character is defined to hold the input from the user's keyboard
 *      1 input file stream is declared to access data in save file
 *      1 output file stream is declared to save data into a save file
 *      1 Plotter object is declared
 *      1 snake object is declared
 *      1 fruit object is declared
 *      1 game object is declared
 *      1 sound object is declared
 *      1 font object is declared
 *      1 scoreboard object is declared
 * Input:
 *      Keyboard hits are detected and stored in a character.
 * 		Input from the user allows the user to access the start, play and gave
 *      over pages. Arrows control snake movement
 * Process:
 *      Keyboard hits are used to make the snake move and eat the fruit
 *      When eaten, fruit respawns in a random location
 *      When the fruit is eaten, the snake grows and the score increases
 * Output:
 *      pixels are plotted to the plotter, plotting a start page, background
 *      grid, snake, apple, and text.
 * Assumptions:
 * 		It is assumed that the user has access to the keyboard
 *      It is assumed that the user has a screen and can see it
 *      It is assumed that the user has SDL PLotter downloaded and installed
 */


#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <ctime>

#include "constants.h"
#include "font.h"
#include "fruit.h"
#include "functions.h"
#include "game.h"
#include "scoreboard.h"
#include "SDL_Plotter.h"
#include "snake.h"
#include "sound.h"

using namespace std;

int main(int argc, char** argv) {
// Data Abstraction
    char key;

    ifstream fin;
    ofstream fout;
    string input;

    SDL_Plotter g(NUM_ROW + SIZE, NUM_COL);
    snake hiss(3);
    fruit apple;
    game fun;
    sound soundEffects(g);
    font text;
    scoreboard currHighScore;

    // Initialize
    srand(time(0));
    apple.setRandPoint(hiss);
    fun.changeState(START);

    // Input - Get Data From File
    fin.open("SnakeSave.txt");
    currHighScore.initialize(fin);
    if(getline(fin, input, ':')){
        apple.initialize(fin);
        fun.initialize(fin);
        hiss.initialize(fin);
    }
    fin.close();

    // Main Loop
    while(!g.getQuit()){

        // Input - User Interface
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
                    if(fun.checkState() == OVER){
                        apple.setRandPoint(hiss);
                        hiss.reset();

                        fun.changeState(PLAY);
                        fun.resetScore();
                    }
                    break;
            }
        }

        //Check States
        if(fun.checkState() == START){
            plotBackground(g);
            printPressStart(g, text);
            currHighScore.printHighScore(g, text);

        }
        else if(fun.checkState() != OVER){
            if(fun.checkState() == PLAY){
                // Check if it's dead
                fun.changeState(hiss.checkDie(soundEffects, g));

                // Advance
                hiss.advance();

                // Fruit
                if(hiss.getPoint(1).x == apple.getPoint().x &&
                   hiss.getPoint(1).y == apple.getPoint().y){
                    apple.setRandPoint(hiss);
                    hiss.incLength(1);
                    fun.addPoint();
                    soundEffects.eating(g);
                }

            }

        // Output: Draw
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

            // Draw Menu at Bottom
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
        else{
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

        g.update();
        g.Sleep(SPEED);
    }

    // Save Data to File
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
