/* AUTHOR: Caleb Beckering, Ruth Edwards, Karina Garza, Mark Josephs
 * ASSIGNMENT TITLE: Group Project: Snake
 * ASSIGNMENT DESCRIPTION: Create a snake-themed game
 * DUE DATE: 12-07-22
 * DATE CREATED: 11-03-22
 * DATE LAST MODIFIED: 12-07-22
 */

#ifndef fruit_h
#define fruit_h
#include "SDL_Plotter.h"
#include "point.h"
#include "constants.h"
#include "snake.h"


class Fruit{
private:
    Point_t p;
public:
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: fruit constructor, doesn't do anything                    *
    * return: N/A                                                            *
    * precondition: none                                                     *
    * postcondition: fruit object exists                                     *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    Fruit(){
    }
    
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: draw the fruit                                            *
    * return: void                                                           *
    * precondition: fruit object exists, and SDL_Plotter exists              *
    * postcondition: fruit object exists                                     *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void draw(SDL_Plotter&);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: accessor function for fruit's Point_t                     *
    * return: Point_t                                                        *
    * precondition: fruit object exists                                      *
    * postcondition: nothing is changed, Point is returned                   *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    Point_t getPoint() const;
    
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: mutator function for fruit's Point_t                      *
    * return: void                                                           *
    * precondition: fruit object exists, two integers exist                  *
    * postcondition: fruit's point is changed                                *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void setPoint(int, int);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: sets fruit's point to a random point on the grid that is  *
    *              not on top of the snake's current location                *
    * return: void                                                           *
    * precondition: fruit object exists, snake object exists                 *
    * postcondition: the fruit has a new random point                        *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void eatenFruit(snake);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: get fruit's location from a save file                     *
    * return: void                                                           *
    * precondition: fruit object exists, input file stream exists            *
    * postcondition: fruit's position is changed to saved data from file     *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void initialize(ifstream& fin);
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: save fruit's location to a save file                      *
    * return: void                                                           *
    * precondition: fruit object exists, output file stream exists           *
    * postcondition: fruit's position is saved to a data file                *
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void saveToFile(ofstream& fout);


};

#endif /* fruit_h */
