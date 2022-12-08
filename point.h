/* AUTHOR: Caleb Beckering, Ruth Edwards, Karina Garza, Mark Josephs
 * ASSIGNMENT TITLE: Group Project: Snake
 * ASSIGNMENT DESCRIPTION: Create a snake-themed game
 * DUE DATE: 12-07-22
 * DATE CREATED: 11-03-22
 * DATE LAST MODIFIED: 12-07-22
 */
#ifndef Point_h
#define Point_h
#include "SDL_Plotter.h"

#include <cmath>

using namespace std;

struct Point_t{
   int x,y;

   Point_t(const Point_t& p){
       *this = p;
   }

   Point_t(int x = 0, int y = 0){
      this->x = x;
      this->y = y;
   }

   Point_t& operator+ (const Point_t& p){
        Point_t result;
        result.x = x + p.x;
        result.y = y + p.y;
        return result;
   }
   Point_t& operator- (const Point_t& p){
        Point_t result;
        result.x = x - p.x;
        result.y = y - p.y;
        return result;
   }

   Point_t& operator= (const Point_t& p){
       x = p.x;
       y = p.y;
       return *this;
   }

   double distance(Point_t p){
       return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
   }
};

#endif /* Point_h */
