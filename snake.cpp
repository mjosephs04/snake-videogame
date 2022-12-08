
/* AUTHOR: Caleb Beckering, Ruth Edwards, Karina Garza, Mark Josephs
 * ASSIGNMENT TITLE: Group Project: Snake
 * ASSIGNMENT DESCRIPTION: Create a snake-themed game
 * DUE DATE: 12-07-22
 * DATE CREATED: 11-03-22
 * DATE LAST MODIFIED: 12-07-22
 */
#include "snake.h"

snake::snake(int l){
    length = l;
    dir = UP;
    setColorBody();
    setColorHead();

    for(int i = 0; i < MAX; i++){
        loc[i] = point(-SIZE, -SIZE);
    }

    for(int i = 0; i < length; i++){
        loc[i] = point(NUM_ROW / 2 - i*SIZE,
                         NUM_COL / 2 - i*SIZE);
    }
}

void snake::setColorBody(color c){
    cBody = c;
}
void snake::setColorHead(color c){
    cHead = c;
}
void snake::setDir(direction d){
    dir = d;
}
void snake::setLength(int l){
    length = l;
}

direction snake::getDir(void){
    return dir;
}
int snake::getLength(void){
    return length;
}

void snake::incLength(int n){
    length += n;
}

gameState snake::checkDie(sound& soundEffects, SDL_Plotter& g){
    gameState retVal = PLAY;
    for(int i = 1; i < length; i++){
        if(loc[0].x == loc[i].x && loc[0].y == loc[i].y){
            retVal = OVER;
        }
    }
    if(loc[0].x == -SIZE || loc[0].x == NUM_COL){
        retVal = OVER;
    }
    if(loc[0].y == -SIZE || loc[0].y == NUM_ROW){
        retVal = OVER;
    }
    if(retVal == OVER){
        soundEffects.dying(g);
    }
    return retVal;
}

void snake::advance(){
    for(int i = length - 1; i > 0; i--){
        loc[i] = loc[i-1];
    }
    switch(dir){
        case UP:
                loc[0].y -= SIZE;
                break;

        case DOWN:
                loc[0].y += SIZE;
                break;

        case LEFT:
                loc[0].x -= SIZE;
                break;

        case RIGHT:
                loc[0].x += SIZE;
                break;
    }

}

void snake::draw(SDL_Plotter& g){
    for(int i = 0; i < length; i++){
        for(int y = 0; y < SIZE; y++){
            for(int x = 0; x < SIZE; x++){

                if(i == 0){
                    g.plotPixel(loc[i].x + x, loc[i].y + y, cHead);
                }
                else{
                    g.plotPixel(loc[i].x + x, loc[i].y + y, cBody);
                }
            }
        }
    }
}

void snake::reset(){
    length = 3;
    dir = UP;

    for(int i = 0; i < MAX; i++){
        loc[i] = point(-SIZE, -SIZE);
    }

    for(int i = 0; i < length; i++){
        loc[i] = point(NUM_ROW / 2 - i*SIZE,
                         NUM_COL / 2 - i*SIZE);
    }
}

void snake::initialize(ifstream& fin){
    string input;
    char c;

    getline(fin, input, ':');
    fin >> c;
    switch(c){
        case 'U':
                dir = UP;
                break;

        case 'D':
                dir = DOWN;
                break;

        case 'L':
                dir = LEFT;
                break;

        case 'R':
                dir = RIGHT;
                break;
    }
    getline(fin, input, ':');
    fin >> length;
    for(int i = 0; i < length; i++){
        fin >> loc[i].x;
        fin.ignore();
        fin >> loc[i].y;
        fin.ignore();
    }
}

void snake::saveToFile(ofstream& fout){
    fout << "Direction: ";
    switch(dir){
        case UP:
                fout << 'U';
                break;

        case DOWN:
                fout << 'D';
                break;

        case LEFT:
                fout << 'L';
                break;

        case RIGHT:
                fout << 'R';
                break;
    }
    fout << endl;
    fout << "Length: " << length << endl;

    for(int i = 0; i < length; i++){
        fout << loc[i].x << ", " << loc[i].y << endl;
    }
}


point snake::getPoint(int i){
    return loc[i];
}
