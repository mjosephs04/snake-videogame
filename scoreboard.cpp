//
//  scoreboard.cpp
//  groupProject(final)
//
//  Created by Caleb Beckering on 12/5/22.
//

#include "scoreboard.h"
#include "constants.h"
void Scoreboard::saveToFile(fstream& fout){
    fout << "High Score: " << highScore << endl;
}
void Scoreboard::initialize(ifstream& fin){
    string temp;
    getline(fin, temp ,':');
    fin >> highScore;
}
int Scoreboard::getHighScore(){
    return highScore;
}

void Scoreboard::setHighScore(int score){
    highScore = score;
}

void Scoreboard::printHighScore(SDL_Plotter& g){
    ffont.printFontLetter("H.txt", 0, 600, g, 3, 0, 0, 0);
    ffont.printFontLetter("I.txt", 100, 600, g, 3, 0, 0, 0);
    ffont.printFontLetter("G.txt", 200, 600, g, 3, 0, 0, 0);
    ffont.printFontLetter("H.txt", 0, 600, g, 3, 0, 0, 0);
    
    ffont.printFontLetter("S.txt", 500, 600, g, 3, 0, 0, 0);
    ffont.printFontLetter("C.txt", 600, 600, g, 3, 0, 0, 0);
    ffont.printFontLetter("O.txt", 700, 600, g, 3, 0, 0, 0);
    ffont.printFontLetter("R.txt", 800, 600, g, 3, 0, 0, 0);
    ffont.printFontLetter("E.txt", 900, 600, g, 3, 0, 0, 0);
    
    if(highScore < 10){
        stringstream ss;
        int num = highScore;
        ss << num;
        string name = ss.str();
        ffont.printFont(name + ".txt", 520, 702, g, 3, 0, 0, 0);
        ss.flush();

    }
    else if(highScore >= 10 && (highScore < 100)){
        stringstream ss;
        int num = highScore;
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
        ffont.printFont(fname, 490, 702, g, 3, 0, 0, 0);
        ffont.printFont(fname1, 535, 702, g, 3, 0, 0, 0);
        ss.flush();
    }
    else{
        stringstream ss;
        int num = highScore;
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
        ffont.printFont(fname, 490, 702, g, 3, 0, 0, 0);
        ffont.printFont(fname1, 535, 702, g, 3, 0, 0, 0);
        ffont.printFont(fname2, 535, 702, g, 3, 0, 0, 0);
        ss.flush();
    }
}
