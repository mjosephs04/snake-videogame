/* AUTHOR: Caleb Beckering, Ruth Edwards, Karina Garza, Mark Josephs
 * ASSIGNMENT TITLE: Group Project: Snake
 * ASSIGNMENT DESCRIPTION: Create a snake-themed game
 * DUE DATE: 12-07-22
 * DATE CREATED: 11-03-22
 * DATE LAST MODIFIED: 12-07-22
 */

#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED

#include <string>
#include <fstream>
#include "SDL_Plotter.h"
#include <sstream>
#include "font.h"

using namespace std;

class font{
private:
    int number;
    
public:
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description:                    
    * return:                                                            
    * precondition:                                                      
    * postcondition:                                  
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void printFontNumber(string fileName, int xBaseLocation , int yBaseLocation, SDL_Plotter& g, int thickness, int R, int G, int B);
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description:                    
    * return:                                                            
    * precondition:                                                      
    * postcondition:                                  
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void printFontLetter(string fileName, int xBaseLocation , int yBaseLocation, SDL_Plotter& g, int thickness, int, int, int);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description:                    
    * return:                                                            
    * precondition:                                                      
    * postcondition:                                  
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void printScoreSingle(int, font&, SDL_Plotter&, int, int, int = 3);
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description:                    
    * return:                                                            
    * precondition:                                                      
    * postcondition:                                  
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void printScoreDouble(int, font&, SDL_Plotter&, int, int, int, int, int = 3);
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description:                    
    * return:                                                            
    * precondition:                                                      
    * postcondition:                                  
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void printScoreTriple(int, font&, SDL_Plotter&, int, int, int, int, int, int, int = 3);

};

#endif // FONT_H_INCLUDED
