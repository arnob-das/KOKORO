#include "iGraphics.h"
//#include "function.h"
//#include "variable.h"

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

// game state
int game_state = 0;

// score
int playerScore = 0;
int *ptr = &playerScore;

int pillBigValue = 20;
int pillSmallValue = 10;

/// for screen size
int screen_width = 1300;
int screen_height = 650;

// start bg screen size
int start_bg_height = 650;
int start_bg_width = 1300;

// KoKo's initial co-ordinate
int kokoro_x = 650;
int kokoro_y = 130;

// wall width and height
int wallWidthHeight[50] = {
	65, 65, 65, 65, 65, 65, 65, 65, // 8
	65, 65, 65,						// 3
	65, 65, 65,						// 3
	65, 65, 65, 65, 65, 65, 65,		// 7
	65, 65, 65, 65,					// 4
	65, 65, 65, 65,					// 4
	65, 65, 65, 65, 65, 65, 65,		// 7
	65, 65, 65,						// 3
	65, 65, 65,						// 3
	65, 65, 65, 65, 65, 65, 65, 65	// 8
};

// pil big width and height
int pillBigWidthHeight[4] = {65, 65, 65, 65};

// pill small width and height
int pillSmallWidthHeight[31] = {
	65, 65, 65,					// 3
	65, 65, 65, 65, 65, 65, 65, // 7
	65, 65, 65,					// 3
	65, 65, 65,					// 3
	65, 65,						// 2
	65, 65, 65,					// 3
	65, 65, 65, 65, 65, 65, 65, // 7
	65, 65, 65					// 3
};

// floor width and height
int floorWidthHeight[12] = {
	65, 65, // 2
	65, 65, // 2
	65, 65, // 2
	65, 65, // 2
	65, 65, // 2
	65, 65, // 2
};

// wall x co-ordinate
int wall_X[50] = {
	325, 325, 325, 325, 325, 325, 325, 325, // 8
	390, 390, 390,							// 3
	455, 455, 455,							// 3
	520, 520, 520, 520, 520, 520, 520,		// 7
	585, 585, 585, 585,						// 4
	650, 650, 650, 650,						// 4
	715, 715, 715, 715, 715, 715, 715,		// 7
	780, 780, 780,							// 3
	845, 845, 845,							// 3
	910, 910, 910, 910, 910, 910, 910, 910	// 8
};
// wall y co-ordinate
int wall_y[50] = {
	0, 65, 130, 260, 325, 455, 520, 585, // 8
	0, 130, 585,						 // 3
	0, 325, 585,						 // 3
	0, 195, 260, 325, 390, 520, 585,	 // 7
	0, 65, 195, 585,					 // 4
	0, 65, 195, 585,					 // 4
	0, 195, 260, 325, 390, 520, 585,	 // 7
	0, 325, 585,						 // 3
	0, 130, 585,						 // 3
	0, 65, 130, 260, 325, 455, 520, 585	 // 8
};

// pill small x co-ordinate
int pillSmall_x[31] = {
	390, 390, 390,					   // 3
	455, 455, 455, 455, 455, 455, 455, // 7
	520, 520, 520,					   // 3
	585, 585, 585,					   // 3
	650, 650,						   // 2
	715, 715, 715,					   // 3
	780, 780, 780, 780, 780, 780, 780, // 7
	845, 845, 845					   // 3
};

// pill small y co-ordinate
int pillSmall_y[31] = {
	260, 325, 455,					  // 3
	65, 130, 195, 260, 390, 455, 520, // 7
	65, 130, 455,					  // 3
	130, 455, 520,					  // 3
	455, 520,						  // 2
	65, 130, 455,					  // 3
	65, 130, 195, 260, 390, 455, 520, // 7
	260, 325, 455					  // 3
};

// pill-big x co-ordinate
int pillBig_x[4] = {390, 390, 845, 845};

// pill-big y co-ordinate
int pillBig_y[4] = {65, 520, 65, 520};

// floor x co-ordinate
int floor_x[12] = {
	325, 325, // 2
	390, 390, // 2
	585, 585, // 2
	650, 650, // 2
	845, 845, // 2
	910, 910, // 2
};

// floor y co-ordinate
int floor_y[12] = {
	195, 390, // 2
	195, 390, // 2
	325, 390, // 2
	325, 390, // 2
	195, 390, // 2
	195, 390, // 2
};

// koko's easy move
int kokoMovePosition_x[49] = {
	// pill small x co-ordinate
	390, 390, 390,					   // 3
	455, 455, 455, 455, 455, 455, 455, // 7
	520, 520, 520,					   // 3
	585, 585, 585,					   // 3
	650, 650,						   // 2
	715, 715, 715,					   // 3
	780, 780, 780, 780, 780, 780, 780, // 7
	845, 845, 845,					   // 3
	// pill big x co-ordinate
	390, 390, 845, 845,
	// floor x co-ordinate
	325, 325, // 2
	390, 390, // 2
	585, 585, // 2
	650, 650, // 2
	845, 845, // 2
	910, 910, // 2
	// only one empty space
	650, // 1
	// kono's initital x co-ordinate
	650};

int kokoMovePosition_y[49] = {
	// pill y co-ordinate
	260, 325, 455,					  // 3
	65, 130, 195, 260, 390, 455, 520, // 7
	65, 130, 455,					  // 3
	130, 455, 520,					  // 3
	455, 520,						  // 2
	65, 130, 455,					  // 3
	65, 130, 195, 260, 390, 455, 520, // 7
	260, 325, 455,					  // 3
	// pill big y co-ordinate
	65, 520, 65, 520,
	// floor y co-ordinate
	195, 390, // 2
	195, 390, // 2
	325, 390, // 2
	325, 390, // 2
	195, 390, // 2
	195, 390, // 2
	// only one empty space
	260, // 1
	// kono's initital y co-ordinate
	130

};

// pill small score value
int pillSmall_ScoreValue[31] = {
	10, 10, 10,					// 3
	10, 10, 10, 10, 10, 10, 10, // 7
	10, 10, 10,					// 3
	10, 10, 10,					// 3
	10, 10,						// 2
	10, 10, 10,					// 3
	10, 10, 10, 10, 10, 10, 10, // 7
	10, 10, 10					// 3
};

// pill big score value
int pillBig_ScoreValue[4] = { 20, 20, 20, 20};

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
	// WALLS
	for (int x = 0; x < 50; x++)
	{

		iShowImage(wall_X[x], wall_y[x], wallWidthHeight[x], wallWidthHeight[x], iLoadImage("images\\wall.png"));
	}

	// pill big
	for (int x = 0; x < 4; x++)
	{
		iShowImage(pillBig_x[x], pillBig_y[x], pillBigWidthHeight[x], pillBigWidthHeight[x], iLoadImage("images\\pillBig.png"));
	}

	// pill small
	for (int x = 0; x < 31; x++)
	{
		iShowImage(pillSmall_x[x], pillSmall_y[x], pillSmallWidthHeight[x], pillSmallWidthHeight[x], iLoadImage("images\\pillSmall.png"));
	}

	// Floor
	for (int x = 0; x < 12; x++)
	{
		iShowImage(floor_x[x], floor_y[x], floorWidthHeight[x], floorWidthHeight[x], iLoadImage("images\\newFloor.png"));
	}

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

// menu item height and width
int menuItemHeight = 650;
int menuItemWidth = 1300;

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

void iDraw()
{
	iClear();

	// start background
	iShowImage(0, 0, start_bg_width, start_bg_height, iLoadImage("images\\start_bg.png"));

	// show_game_res();
	if (game_state == 1)
	{
		// rendering game user interface
		show_game_res();

		// score text
		string str = to_string(*ptr); // convert int to string data type
		char str1[100];				  // declare charracter array
		strcpy_s(str1, str.c_str());  // copy string to a charracter array

		iText(1075, 330, "SCORE : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1180, 330, str1, GLUT_BITMAP_TIMES_ROMAN_24); // show that charracter array
	}

	cout << "game score:" << playerScore << endl;
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
			else if ((mx >= 132 && mx <= 354) && (my >= 273 && my <= 377))
			{

				/// working on here ///
				// iFilledRectangle(50, 60, 100, 100);
				iText(50, 60, "This is a text", GLUT_BITMAP_TIMES_ROMAN_10);

				hide_menu_screen();
				iText(50, 60, "This is a text", GLUT_BITMAP_TIMES_ROMAN_10);

				// iShowImage(0, 0, menuItemWidth, menuItemHeight, iLoadImage("images\\highScores.png"));

				cout << "High Scores" << endl;
			}

			// Levels menu item
			else if ((mx >= 132 && mx <= 354) && (my >= 119 && my <= 222))
			{
				cout << "Levels" << endl;
				if (game_state == 0)
				{
					iShowImage(10, 10, menuItemWidth, menuItemHeight, iLoadImage("images\\highScores.png"));
					// hide_menu_screen();
					cout << "High Scores" << endl;
				}
			}

			// Learn menu item
			else if ((mx >= 721 && mx <= 942) && (my >= 434 && my <= 538))
			{
				cout << "Learn" << endl;
			}

			// about menu item
			else if ((mx >= 721 && mx <= 942) && (my >= 276 && my <= 380))
			{
				cout << "About" << endl;
			}

			// quit menu item
			else if ((mx >= 721 && mx <= 942) && (my >= 118 && my <= 223))
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

	// RIGHT KEY PRESSED
	if (key == GLUT_KEY_RIGHT)
	{
		// move koko from right side to left side
		if (kokoro_x == 910 && kokoro_y == 195)
		{
			kokoro_x = 325;
		}
		else if (kokoro_x == 910 && kokoro_y == 390)
		{
			kokoro_x = 325;
		}

		/*
		if ((kokoro_x + 65 == wall_X[0]) && (kokoro_y == wall_y[0])) {
			cout << "position matches" << endl;
			kokoro_x += 65;
		}
		else {
			kokoro_x += 65;
		}
		if ((kokoro_x + 65 != wall_X[23]) && (kokoro_y != wall_y[23])) {
			cout << "position matches" << endl;
			kokoro_x += 65;
		}
		else {
			kokoro_x += 65;
		}
		*/

		// changing positions to right
		for (int x = 0; x < 49; x++)
		{
			if ((kokoro_x + 65 == kokoMovePosition_x[x]) && (kokoro_y == kokoMovePosition_y[x]))
			{
				// cout << "position matches" << endl;
				kokoro_x += 65;
				break;
			}
		}

		// for eating pill big
		for (int x = 0; x < 4; x++)
		{
			if (pillBig_x[x] == kokoro_x && pillBig_y[x] == kokoro_y)
			{
				// cout << "big pill found" << endl;
				pillBigWidthHeight[x] = 0;
				playerScore += pillBig_ScoreValue[x];
				pillBig_ScoreValue[x] = 0;
				// strcpy_s(str1, str.c_str()); // score to char array
			}
		}
		// for eating small pill
		for (int x = 0; x < 31; x++)
		{
			if (pillSmall_x[x] == kokoro_x && pillSmall_y[x] == kokoro_y)
			{
				// cout << "small pill found" << endl;
				pillSmallWidthHeight[x] = 0;
				playerScore += pillSmall_ScoreValue[x];
				pillSmall_ScoreValue[x] = 0;
				// strcpy_s(str1, str.c_str()); // score to char array
			}
		}
	}

	// LEFT KEY PRESSED
	if (key == GLUT_KEY_LEFT)
	{
		// moves koko from left to right in same y co-ordinate
		if (kokoro_x == 325 && kokoro_y == 195)
		{
			kokoro_x = 910;
		}
		if (kokoro_x == 325 && kokoro_y == 390)
		{
			kokoro_x = 910;
		}
		// moves koko to left
		for (int x = 0; x < 49; x++)
		{
			if ((kokoro_x - 65 == kokoMovePosition_x[x]) && (kokoro_y == kokoMovePosition_y[x]))
			{
				// cout << "position matches" << endl;
				kokoro_x -= 65;
				break;
			}
		}

		// for eating pill big
		for (int x = 0; x < 4; x++)
		{
			if (pillBig_x[x] == kokoro_x && pillBig_y[x] == kokoro_y)
			{
				cout << "big pill found" << endl;
				pillBigWidthHeight[x] = 0;
				playerScore += pillBig_ScoreValue[x];
				pillBig_ScoreValue[x] = 0;
				// strcpy_s(str1, str.c_str()); // score to char array
			}
		}
		// for eating small pill
		for (int x = 0; x < 31; x++)
		{
			if (pillSmall_x[x] == kokoro_x && pillSmall_y[x] == kokoro_y)
			{
				cout << "small pill found" << endl;
				pillSmallWidthHeight[x] = 0;
				playerScore += pillSmall_ScoreValue[x];
				pillSmall_ScoreValue[x] = 0;
				// strcpy_s(str1, str.c_str()); // score to char array
			}
		}
	}

	// UP KEY PRESSED
	if (key == GLUT_KEY_UP)
	{
		/*
		if (kokoro_y <= 520)
		{
			kokoro_y += 65;
		}
		cout << kokoro_x << "   " << kokoro_y << endl;
		*/

		// changing positions to upward direction
		for (int x = 0; x < 49; x++)
		{
			if ((kokoro_x == kokoMovePosition_x[x]) && (kokoro_y + 65 == kokoMovePosition_y[x]))
			{
				// cout << "position matches" << endl;
				kokoro_y += 65;
				break;
			}
		}

		// for eating pill big
		for (int x = 0; x < 4; x++)
		{
			if (pillBig_x[x] == kokoro_x && pillBig_y[x] == kokoro_y)
			{
				cout << "big pill found" << endl;
				pillBigWidthHeight[x] = 0;
				playerScore += pillBig_ScoreValue[x];
				pillBig_ScoreValue[x] = 0;
				// strcpy_s(str1, str.c_str()); // score to char array
			}
		}
		// for eating small pill
		for (int x = 0; x < 31; x++)
		{
			if (pillSmall_x[x] == kokoro_x && pillSmall_y[x] == kokoro_y)
			{
				cout << "small pill found" << endl;
				pillSmallWidthHeight[x] = 0;
				playerScore += pillSmall_ScoreValue[x];
				pillSmall_ScoreValue[x] = 0;
				// strcpy_s(str1, str.c_str()); // score to char array
			}
		}
	}

	// DOWN KEY PRESSED
	if (key == GLUT_KEY_DOWN)
	{
		/*
		if (kokoro_y >= 65)
		{
			kokoro_y -= 65;
		}
		cout << kokoro_x << "   " << kokoro_y << endl;
		*/

		// changing positions to downward directions
		for (int x = 0; x < 49; x++)
		{
			if ((kokoro_x == kokoMovePosition_x[x]) && (kokoro_y - 65 == kokoMovePosition_y[x]))
			{
				// cout << "position matches" << endl;
				kokoro_y -= 65;
				break;
			}
		}

		// for eating pill big
		for (int x = 0; x < 4; x++)
		{
			if (pillBig_x[x] == kokoro_x && pillBig_y[x] == kokoro_y)
			{
				cout << "big pill found" << endl;
				pillBigWidthHeight[x] = 0;
				playerScore += pillBig_ScoreValue[x];
				pillBig_ScoreValue[x] = 0;
				// strcpy_s(str1, str.c_str()); // score to char array
			}
		}
		// for eating small pill
		for (int x = 0; x < 31; x++)
		{
			if (pillSmall_x[x] == kokoro_x && pillSmall_y[x] == kokoro_y)
			{
				cout << "small pill found" << endl;
				pillSmallWidthHeight[x] = 0;
				playerScore += pillSmall_ScoreValue[x];
				pillSmall_ScoreValue[x] = 0;
				// strcpy_s(str1, str.c_str()); // score to char array
			}
		}
	}
}

int main()
{
	// initialize KOKORO window
	iInitialize(screen_width, screen_height, "KOKORO");

	// machine starts here
	iStart();

	return 0;
}