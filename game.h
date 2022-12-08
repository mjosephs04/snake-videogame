/* AUTHOR: Caleb Beckering, Ruth Edwards, Karina Garza, Mark Josephs
 * ASSIGNMENT TITLE: Group Project: Snake
 * ASSIGNMENT DESCRIPTION: Create a snake-themed game
 * DUE DATE: 12-07-22
 * DATE CREATED: 11-03-22
 * DATE LAST MODIFIED: 12-07-22
 */

#ifndef game_h
#define game_h

#include "fruit.h"
#include "constants.h"
#include "font.h"
#include "snake.h"
#include "scoreboard.h"


class game{
private:
    gameState currState;
    int score = 0;
    font ffont;
public:
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: Game constructor                                          *
    * return: N/A                                                            *
    * precondition: none                                                     *
    * postcondition: Game object exists                                      *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    game();
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: checks and returns the GameState                          *
    * return: GameState                                                      *
    * precondition: Game object exists                                       *
    * postcondition: GameState is returned                                   *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    gameState checkState();
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: change the GameState                                      *
    * return: void                                                           *
    * precondition: GameState exists, game object exists                     *
    * postcondition: GameState is changed                                    *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void changeState(gameState);
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: add one point to the score                                *
    * return: void                                                           *
    * precondition: game object exists                                       *
    * postcondition: score is incremented                                    *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void addPoint();
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: returns the current score                                 *
    * return: integer                                                        *
    * precondition: game object exists                                       *
    * postcondition: nothing is changed, score is returned                   *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    int getScore();
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: displays the score to the screen                          *
    * return: void                                                           *
    * precondition: game object exists, SDL_Plotter exists                   *
    * postcondition: score is displayed, nothing is changed                  *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void displayYourScore(SDL_Plotter&);
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: resets the score to 0                                     *
    * return: void                                                           *
    * precondition: game object exists                                       *
    * postcondition: score is set to 0                                       *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void resetScore();
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: initializes the score to whatever is stored in save file  *
    * return: void                                                           *
    * precondition: input file stream exists, game object exists             *
    * postcondition: score is initialized to whatever is stored in file      *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void initialize(ifstream&);
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: saves current score to save file                          *
    * return: void                                                           *
    * precondition: output file stream exists, game object exists            *
    * postcondition: score is saved to file                                  *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void saveToFile(ofstream&);
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: displays score to screen - formatted for in-game display  *
    * return: void                                                           *
    * precondition: SDL_Plotter exists, game object exists                   *
    * postcondition: score is printed to screen, nothing is changed          *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void printScoreInGame(SDL_Plotter&);
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: prints score - formatted for game over screen             *
    * return: void                                                           *
    * precondition: SDL_Plotter exists, game object exists                   *
    * postcondition: score is printed to screen, nothing is changed          *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void printScorePostGame(SDL_Plotter&);

};



#endif /* game_h */
