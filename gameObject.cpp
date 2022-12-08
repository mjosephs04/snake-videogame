/* AUTHOR: Caleb Beckering, Ruth Edwards, Karina Garza, Mark Josephs
 * ASSIGNMENT TITLE: Group Project: Snake
 * ASSIGNMENT DESCRIPTION: Create a snake-themed game
 * DUE DATE: 12-07-22
 * DATE CREATED: 11-03-22
 * DATE LAST MODIFIED: 12-07-22
 */

#include <stdio.h>
#include "gameObject.h"

Game::Game(){
    currState = START;
}

GameState Game::checkState(){
    return currState;
}

void Game::changeState(GameState n){
    currState = n;
}

void Game::addPoint(){
    score++;
}
int Game::getScore(){
    return score;
}
void Game::resetScore(){
    score = 0;
}
void Game::initialize(ifstream& fin){
    string temp;
    getline(fin, temp, ':');
    fin >> score;
    fin.ignore();
}
void Game::saveToFile(ofstream& fout){
    fout << "Current score: " << score << endl;
}

void Game::displayYourScore(SDL_Plotter& g){
    //ffont.printFontLetter("Y.txt", 100, 600, g, 3, 0, 0, 0);
    ffont.printFontLetter("O.txt", 200, 600, g, 3, 0, 0, 0);
    ffont.printFontLetter("U.txt", 300, 600, g, 3, 0, 0, 0);
    ffont.printFontLetter("R.txt", 400, 600, g, 3, 0, 0, 0);

    ffont.printFontLetter("S.txt", 500, 600, g, 3, 0, 0, 0);
    ffont.printFontLetter("C.txt", 600, 600, g, 3, 0, 0, 0);
    ffont.printFontLetter("O.txt", 700, 600, g, 3, 0, 0, 0);
    ffont.printFontLetter("R.txt", 800, 600, g, 3, 0, 0, 0);
    ffont.printFontLetter("E.txt", 900, 600, g, 3, 0, 0, 0);

    if(score < 10){
        stringstream ss;
        int num = score;
        ss << num;
        string name = ss.str();
        ffont.printFontNumber(name + ".txt", 520, 702, g, 3, 0, 0, 0);
        ss.flush();

    }
    else if(score >= 10 && (score < 100)){
        stringstream ss;
        int num = score;
        ss << num;
        string number = ss.str();
        char first = number.at(0);
        char second = number.at(1);
        string fname = "";
        string fname1 = "";
        fname = fname + first;
        fname.append(".txt");
        fname1 = fname1 + second;
        fname1.append(".txt");
        ffont.printFontNumber(fname, 490, 702, g, 3, 0, 0, 0);
        ffont.printFontNumber(fname1, 535, 702, g, 3, 0, 0, 0);
        ss.flush();
    }
    else{
        stringstream ss;
        int num = score;
        ss << num;
        string number = ss.str();
        char first = number.at(0);
        char second = number.at(1);
        char third = number.at(3);
        string fname = "";
        string fname1 = "";
        string fname2 = "";
        fname = fname + first;
        fname.append(".txt");
        fname1 = fname1 + second;
        fname1.append(".txt");
        fname2 = fname2 + third;
        fname2.append(".txt");
        ffont.printFontNumber(fname, 490, 702, g, 3, 0, 0, 0);
        ffont.printFontNumber(fname1, 535, 702, g, 3, 0, 0, 0);
        ffont.printFontNumber(fname2, 535, 702, g, 3, 0, 0, 0);
        ss.flush();
    }
}

void Game::printScoreInGame(SDL_Plotter& g){
    if(score < 10){
        ffont.printScoreSingle(score, ffont, g, 300, 702);
    }
    else if(score < 100){
        ffont.printScoreDouble(score, ffont, g, 250, 702, 300, 702);
    }
    else{
        ffont.printScoreTriple(score, ffont, g, 250, 702, 300, 702, 350, 702);
    }
}

void Game::printScorePostGame(SDL_Plotter& g){
    if(score < 10){
        ffont.printScoreSingle(score, ffont, g, 850, 495, 5);
    }
    else if(score < 100){
        ffont.printScoreDouble(score, ffont, g, 810, 495, 875, 495, 5);
    }
    else{
        ffont.printScoreTriple(score, ffont, g, 810, 500, 860, 500, 910, 500, 4);
    }
}
