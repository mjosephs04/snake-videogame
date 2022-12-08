/* AUTHOR: Caleb Beckering, Ruth Edwards, Karina Garza, Mark Josephs
 * ASSIGNMENT TITLE: Group Project: Snake
 * ASSIGNMENT DESCRIPTION: Create a snake-themed game
 * DUE DATE: 12-07-22
 * DATE CREATED: 11-03-22
 * DATE LAST MODIFIED: 12-07-22
 */

#include <stdio.h>
#include "fruit.h"



void Fruit::draw(SDL_Plotter& g){
    for(int y = p.y; y < p.y+SIZE; y++){
        for(int x = p.x; x < p.x+SIZE; x++){
            g.plotPixel(x, y, 200, 20, 20);
        }
    }
}

Point_t Fruit::getPoint() const{
    return p;
}

void Fruit::setPoint(int x, int y){
    p.x = x;
    p.y = y;
}

void Fruit::eatenFruit(snake s){
    bool pointSet = false;
    while(!pointSet){
        pointSet= true;
        setPoint( ((rand()%(NUM_COL / SIZE) ) * SIZE), (rand()%(NUM_ROW / SIZE) * SIZE));
        for(int i = 0; i < s.getLength(); i++){
            if(p.x == s.getPoint(i).x &&
               p.y == s.getPoint(i).y){
                pointSet = false;
            }
        }
    }
}

void Fruit::initialize(ifstream& fin){
    string input;
    getline(fin, input, ':');
    fin >> p.x;
    fin.ignore();
    fin >> p.y;
    fin.ignore();
}

void Fruit::saveToFile(ofstream& fout){
    fout << "Fruit: " << p.x << ", " << p.y << endl;
}
