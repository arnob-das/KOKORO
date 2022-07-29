#include "iGraphics.h"
//#include "function.h"
#include <string>
//#include "variable.h"

#include <iostream>
using namespace std;

// game state
int game_state = 0;

/// for screen size
int screen_width = 1300;
int screen_height = 650;

// start bg screen size
int start_bg_height = 650;
int start_bg_width = 1300;

// CO-ORDINATE OF WALL'S X AND Y AXIS
int wall_X[30] = { 325, 325, 325, 325, 325, 325,
391,
456,
521, 521, 521, 521, 521,
586, 586,
651, 651,
716, 716, 716, 716, 716,
781,
846,
911, 911, 911, 911, 911, 911 };

int wall_y[30] = { 66, 131, 261, 326, 391, 521,
131,
326,
197, 261, 326, 391, 521,
66, 196,
66, 196,
197, 261, 326, 391, 521,
326, 131,
66, 131, 261, 326, 391, 521 };

// KoKo's initial co-ordinate
int kokoro_x = 651;
int kokoro_y = 131;

// koko's image height & width
int kokoHeight = 65;
int kokoWidth = 65;

// koko's direction wise image
// koko_right = 1;
// koro_left = 2;
// koko_up = 3;
// koko_down = 4;

// show game resources
void show_game_res()
{
	// 1st row
	for (int i = 325; i < 975; i += 65)
	{
		iShowImage(i, 0, 65, 65, iLoadImage("images\\wall.png"));
	}
	// 10th row
	for (int col = 325, row = 585; col < 975; col += 65)
	{
		iShowImage(col, row, 65, 65, iLoadImage("images\\wall.png"));
	}

	// Rest of the WALLS
	for (int x = 0; x < 30; x++)
	{
		if (x == 0)
		{
			iShowImage(wall_X[x], wall_y[x], 65, 65, iLoadImage("images\\wall.png"));
		}
		if (x != 0)
		{
			iShowImage(wall_X[x] - 1, wall_y[x] - 1, 65, 65, iLoadImage("images\\wall.png"));
		}
	}



	// Floor
	iShowImage(325, 196, 65, 65, iLoadImage("images\\Floor.png"));

	// koko initial position
	iShowImage(kokoro_x, kokoro_y, kokoWidth, kokoHeight, iLoadImage("images\\koko_right.png"));

	// ghost green
	iShowImage(586, 261, 65, 65, iLoadImage("images\\ghost_green.png"));
}

// for menu screen hidden
void hide_menu_screen()
{
	start_bg_height = 0;
	start_bg_width = 0;
}

// for menu screen shown
void show_menu_screen()
{
	start_bg_height = 650;
	start_bg_width = 1300;
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

void iDraw()
{
	iClear();

	// start background
	iShowImage(0, 0, start_bg_width, start_bg_height, iLoadImage("images\\start_bg.png"));

	// show_game_res();
	if (game_state == 1)
	{
		show_game_res();
	}
}

/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/

void iMouseMove(int mx, int my)
{
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
}

void iMouse(int button, int state, int mx, int my)
{
	// when mouse left button is clicked
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		// play game menu item
		if (game_state == 0)
		{
			if ((mx >= 132 && mx <= 354) && (my >= 434 && my <= 538))
			{
				cout << "Play Game" << endl;

				// make the menu screen hidden
				// when play game button is clicked
				hide_menu_screen();

				// game state = 1
				// if game state == 1
				// that means play game is clicked
				// when play game is clicked
				// that means game state == 1
				// and when game state == 1
				// then game resources function will be called and show the interfaces
				game_state = 1;
			}

			// high score menu item
			if ((mx >= 132 && mx <= 354) && (my >= 273 && my <= 377))
			{
				cout << "High Scores" << endl;
			}

			// Levels menu item
			if ((mx >= 132 && mx <= 354) && (my >= 119 && my <= 222))
			{
				cout << "Levels" << endl;
			}

			// Learn menu item
			if ((mx >= 721 && mx <= 942) && (my >= 434 && my <= 538))
			{
				cout << "Learn" << endl;
			}

			// about menu item
			if ((mx >= 721 && mx <= 942) && (my >= 276 && my <= 380))
			{
				cout << "About" << endl;
			}

			// quit menu item
			if ((mx >= 721 && mx <= 942) && (my >= 118 && my <= 223))
			{
				cout << "Quit" << endl;
			}
		}
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/

void iKeyboard(unsigned char key)
{
	if (key == '\r')
	{
	}
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_RIGHT)
	{
		kokoro_x += 65;
		if (kokoro_x >= 975){
			kokoWidth -= 65;
		}
		cout << kokoro_x << "   " << kokoro_y << endl;

	}
	if (key == GLUT_KEY_LEFT)
	{
		kokoro_x -= 65;
		cout << kokoro_x << "   " << kokoro_y << endl;

	}
	if (key == GLUT_KEY_UP)
	{
		int trueUp = 1;
		int x = 0;
		while (x < 30)
		{

			if ((kokoro_y + 65 != wall_y[x]) && (kokoro_x + 65 != wall_X[x]))
			{
				kokoro_y += 65;
				trueUp = 0;

			}

			if (trueUp != 0){
				x++;
			}
		}
		cout << kokoro_x << "   " << kokoro_y << endl;

	}
	if (key == GLUT_KEY_DOWN)
	{
		if (kokoro_y >= 66){
			kokoro_y -= 65;
		}

		cout << kokoro_x << "   " << kokoro_y << endl;

	}

	if (key == GLUT_KEY_END)
	{
		cout << "GLUT_KEY_END" << endl;
	}


}

int main()
{

	// initialize pacman window
	iInitialize(screen_width, screen_height, "KOKORO");

	// machine starts here
	iStart();


	return 0;
}