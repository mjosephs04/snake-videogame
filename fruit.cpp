//
//  fruit.cpp
//  SDL Practice
//
//  Created by Caleb Beckering on 11/16/22.
//

#include <stdio.h>
#include "fruit.h"



void Fruit::drawFriut(const Point_t& p, SDL_Plotter& g){
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

void Fruit::eatenFruit(){
    setPoint( ((rand()%(NUM_COL / SIZE) ) * SIZE), (rand()%(NUM_ROW / SIZE) * SIZE));
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
