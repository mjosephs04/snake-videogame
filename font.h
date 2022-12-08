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
    * description: prints the 
    * return: void
    * precondition: 6 integers, one string, and one plotter
    * postcondition: prints a number on the plotter
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void printFontNumber(string fileName, int xBaseLocation , int yBaseLocation, SDL_Plotter& g, int thickness, int R, int G, int B);
    
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: prints a letter on the screen
    * return: void
    * precondition: one string, 6 integers and one plotter
    * postcondition: letter is printed on the plotter
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void printFontLetter(string fileName, int xBaseLocation , int yBaseLocation, SDL_Plotter& g, int thickness, int, int, int);

    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: prints the score when it is a single digit
    * return: void
    * precondition: four integers, plotter and a font
    * postcondition: printed score on the screen when it is a single digit
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void printScoreSingle(int, font&, SDL_Plotter&, int, int, int = 3);
    
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: prints the score when it is two digits
    * return: void
    * precondition: six integers, a font class and SDL plotter class
    * postcondition: printed score on the screen when it is a double digit number
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void printScoreDouble(int, font&, SDL_Plotter&, int, int, int, int, int = 3);
    
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
    * description: prints the score when it is three digits
    * return: void
    * precondition: eight integers, a font class and SDL Plotter class
    * postcondition: printed score on the screen when it is a tripe digit number
    * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    void printScoreTriple(int, font&, SDL_Plotter&, int, int, int, int, int, int, int = 3);

};

#endif // FONT_H_INCLUDED
