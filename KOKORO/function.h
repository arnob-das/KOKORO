#include "variable.h"

#include<iostream>
using namespace std;


// show game resources
void show_game_res(){
	// 1st row
	for (int i = 0; i < 650; i += 65){
		iShowImage(i, 0, 65, 65, iLoadImage("images\\wall.png"));

	}
	// 10th row
	for (int col = 0, row = 586; col < 650; col += 65){
		iShowImage(col, row, 65, 65, iLoadImage("images\\wall.png"));
	}

	// Rest of the WALLS
	for (int x = 0; x < 30; x++){
		iShowImage(wall_X[x], wall_y[x], 65, 65, iLoadImage("images\\wall.png"));
	}
	// Floor
	iShowImage(197, 66, 55, 55, iLoadImage("images\\Floor.png"));

	// koko initial position
	iShowImage(kokoro_x, kokoro_y, 55, 55, iLoadImage("images\\pacman.png"));
}