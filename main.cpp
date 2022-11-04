#include <iostream>
#include <cmath>
#include <vector>
#include "SDL_Plotter.h"

using namespace std;

const int NUM_ROW = 1000;
const int NUM_COL = 1000;
const int SIZE    = 10;

enum Direction {UP, DOWN, LEFT, RIGHT};

int main(int argc, char **argv){
    char key;
    SDL_Plotter g(NUM_ROW, NUM_COL);
    int R = 20;
    int G = 20;
    int B = 255;

    Direction dir = RIGHT;
    int speed = 10;
    int length = SIZE;
    vector<int> xLoc(length);
    vector<int> yLoc(length);

    while(!g.getQuit()){
        if(g.kbhit()){
            key = g.getKey();

            switch(key){
                case UP_ARROW:    dir = UP;    break;
                case DOWN_ARROW:  dir = DOWN;  break;
                case LEFT_ARROW:  dir = LEFT;  break;
                case RIGHT_ARROW: dir = RIGHT; break;
            }
        }

        switch(dir){
            case UP:    yLoc[0] -= SIZE; break;
            case DOWN:  yLoc[0] += SIZE; break;
            case LEFT:  xLoc[0] -= SIZE; break;
            case RIGHT: xLoc[0] += SIZE; break;
        }

        //Erase
        for(int i = 0; i <length; i++){
            for(int y = 0; y < SIZE; y++){
                for(int x = 0; x < SIZE; x++){
                    g.plotPixel(xLoc[i] + x, yLoc[i], R, G, B);
                }
            }
        }

        //Copy cell locations
        for(int i = length - 1; i > 0; i--){
            xLoc[i] = xLoc[i-1];
            yLoc[i] = yLoc[i-1];
        }

        //Draw
        for(int i = 0; i < length; i++){
            for(int y = 0; y < SIZE; y++){
                for(int x = 0; x < SIZE; x++){
                    g.plotPixel(xLoc[i] + x, yLoc[i] + y, R, G, B);
                }
            }
        }

        g.update();
        g.Sleep(speed);
    }
    return 0;
}



//void drawCircle(point loc, int size, color c, SDL_Plotter& g);
//
//int main(int argc, char ** argv)
//{
//
//    SDL_Plotter g(1000,1000);
//    point p;
//    color c;
//    int size;
//    Uint32 RGB;
//
//
//
//
//
//
//
//
//    while (!g.getQuit())
//    {
//
//		if(g.kbhit()){
//			switch(toupper(g.getKey())){
//				case 'C': g.clear();
//				          break;
//			}
//		}
//
//		if(g.mouseClick()){
//			p = g.getMouseClick();
//			size = rand()%50;
//			c.R  = rand()%256;
//			c.G  = rand()%256;
//			c.B  = rand()%256;
//			drawCircle(p, size, c, g);
//		}
//		g.update();
//
//    }
//}
//
//
//void drawCircle(point loc, int size, color c, SDL_Plotter& g){
//	for(double i = -size; i <= size;i+=0.1){
//		for(double j = -size; j <= size; j+=0.1){
//			if(i*i + j*j <= size*size){
//				g.plotPixel(round(loc.x+i),round(loc.y+j),c);
//			}
//		}
//	}
//
//}
