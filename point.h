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

   void draw(SDL_Plotter& g, color c = color(0, 0, 0)){
       g.plotPixel(x, y, c);
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
