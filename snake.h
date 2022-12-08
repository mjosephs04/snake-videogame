/* AUTHOR: Caleb Beckering, Ruth Edwards, Karina Garza, Mark Josephs
 * ASSIGNMENT TITLE: Group Project: Snake
 * ASSIGNMENT DESCRIPTION: Create a snake-themed game
 * DUE DATE: 12-07-22
 * DATE CREATED: 11-03-22
 * DATE LAST MODIFIED: 12-07-22
 */

#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#include "SDL_PLotter.h"
#include "constants.h"
#include "sound.h"

#include <fstream>


class snake{
private:
    int length;
    direction dir;
    color cBody, cHead;
    point loc[MAX];

public:
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: snake constructor; default sets the length to 3           *
    * return: N/A                                                            *
    * precondition: none                                                     *
    * postcondition: snake object exists                                     *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    snake(int l = 3);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: mutator function for the color of the snake body          *
    * return: void                                                           *
    * precondition: snake object exists, color exists                        *
    * postcondition: color of snake body is changed                          *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void setColorBody(color c = color(112, 112, 112));
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: mutator function for the color of the snake head          *
    * return: void                                                           *
    * precondition: snake object exists, color exists                        *
    * postcondition: color of snake head is changed                          *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void setColorHead(color c = color(255, 153, 0));
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: mutator function for the direction of the snake           *
    * return: void                                                           *
    * precondition: snake object exists, direction exists                    *
    * postcondition: the direction of the snake is changed                   *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void setDir(direction d);
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: mutator function for the length of the snake              *
    * return: void                                                           *
    * precondition: snake object exists, integer exists                      *
    * postcondition: length of the snake is changed                          *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void setLength(int l);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: returns a point in the snake's position array             *
    * return: Point_t                                                        *
    * precondition: snake object exists, integer exists                      *
    * postcondition: data is not changed                                     *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    point getPoint(int);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: accessor function for the direction of the snake          *
    * return: Direction                                                      *
    * precondition: snake object exists                                      *
    * postcondition: nothing is changed                                      *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    direction getDir(void);
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: accessor function for the length of the snake             *
    * return: integer                                                        *
    * precondition: snake object exists                                      *
    * postcondition: nothing is changed                                      *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    int getLength(void);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: increment the length of the snake                         *
    * return: void                                                           *
    * precondition: snake object exists, integer exists                      *
    * postcondition: length is incremented                                   *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void incLength(int n);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: check if the snake is dead                                *
    * return: GameState                                                      *
    * precondition: snake object exists, plotter exists, sound effects exist *
    * postcondition: returns if the snake is dead                            *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    gameState checkDie(sound&, SDL_Plotter&);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: advance the snake                                         *
    * return: void                                                           *
    * precondition: snake object exists and is playable                      *
    * postcondition: snake has advanced by one unit based off its direction  *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void advance();

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: display the snake to the plotter                          *
    * return: void                                                           *
    * precondition: snake object exist, plotter exists                       *
    * postcondition: snake is drawn to plotter                               *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void draw(SDL_Plotter& g);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: reset snake position                                      *
    * return: void                                                           *
    * precondition: snake object exists                                      *
    * postcondition: snake is reinitialized                                  *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void reset();

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: initialize snake to last saved data in file               *
    * return: void                                                           *
    * precondition: input file stream exists, snake object exists            *
    * postcondition: snake is initialized to the information in the file     *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void initialize(ifstream&);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: save current snake state to file                          *
    * return: void                                                           *
    * precondition: snake object exists, output file stream exists           *
    * postcondition: snake data is saved to file                             *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void saveToFile(ofstream&);
};

#endif // SNAKE_H_INCLUDED
