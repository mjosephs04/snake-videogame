/* AUTHOR: Caleb Beckering, Ruth Edwards, Karina Garza, Mark Josephs
 * ASSIGNMENT TITLE: Group Project: Snake
 * ASSIGNMENT DESCRIPTION: Create a snake-themed game
 * DUE DATE: 12-07-22
 * DATE CREATED: 11-03-22
 * DATE LAST MODIFIED: 12-07-22
 */

#ifndef constants_h
#define constants_h

const int NUM_ROW = 700;
const int NUM_COL = 1000;
const int MAX = 1000;
const int SIZE = 50;
const int SPEED = 75;

enum direction {UP, DOWN, LEFT, RIGHT};
enum gameState {START, PLAY, PAUSE, OVER};

#endif /* constants_h */
