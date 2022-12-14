#include "iGraphics.h"
#include <string>
#include <iostream>
//#include <cstdlib>
#include <cstring>=
#include <sstream>
#include<fstream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;

// file
ofstream file;
ifstream readFile;

// once file written indicator
int fileWrittenIndicator = 1;

// score array from file
int score[6];
int p = 0;
int scoreValue;

// level
int level = 1;
int levelOneCompleted = 0;
int levelTwoCompleted = 0;
// last lastLevelCompleted = 0;
int lastLevelCompleted = 0;
// lastLevelScoreWrittenIndicator
int lastLevelScoreWrittenIndicator = 1;
// live
int live = 3;

// game quit variable
int gameQuit = 0;

// play music
int playMusic = 0;
int* playMusicPtr = &playMusic;

// score
int playerScore = 0;
int* playerScorePtr = &playerScore;

/// for screen size
int screen_width = 1300;
int screen_height = 650;

// start bg screen size
int start_bg_height = 650;
int start_bg_width = 1300;

// KoKo's initial co-ordinate
int kokoro_x = 650;
int kokoro_y = 130;

// ghost's initial co-ordinate
int ghost_green_x = 585;
int ghost_green_y = 260;

int ghost_red_x = 520;
int ghost_red_y = 65;

int ghost_violet_x = 455;
int ghost_violet_y = 455;

int ghost_orange_x = 845;
int ghost_orange_y = 260;

int ghost_pink_x = 780;
int ghost_pink_y = 520;

// ghost power
int ghostGreenPower = 10;
int ghostRedPower = 50;
int ghostVioletPower = 10;
int ghostOrangePower = 10;
int ghostPinkPower = 10;

// wall width and height
int wallWidthHeight[50] = {
    65, 65, 65, 65, 65, 65, 65, 65, // 8
    65, 65, 65,                     // 3
    65, 65, 65,                     // 3
    65, 65, 65, 65, 65, 65, 65,     // 7
    65, 65, 65, 65,                 // 4
    65, 65, 65, 65,                 // 4
    65, 65, 65, 65, 65, 65, 65,     // 7
    65, 65, 65,                     // 3
    65, 65, 65,                     // 3
    65, 65, 65, 65, 65, 65, 65, 65  // 8
};

// pil big width and height
int pillBigWidthHeight[4] = { 65, 65, 65, 65 };

// pill small width and height
int pillSmallWidthHeight[27] = {
    65, 65, 65,             // 3
    65, 65, 65, 65, 65, 65, // 6
    65, 65,                 // 2
    65, 65, 65,             // 3
    65, 65,                 // 2
    65, 65, 65,             // 3
    65, 65, 65, 65, 65, 65, // 6
    65, 65                  // 2
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
    390, 390, 390,                          // 3
    455, 455, 455,                          // 3
    520, 520, 520, 520, 520, 520, 520,      // 7
    585, 585, 585, 585,                     // 4
    650, 650, 650, 650,                     // 4
    715, 715, 715, 715, 715, 715, 715,      // 7
    780, 780, 780,                          // 3
    845, 845, 845,                          // 3
    910, 910, 910, 910, 910, 910, 910, 910  // 8
};
// wall y co-ordinate
int wall_y[50] = {
    0, 65, 130, 260, 325, 455, 520, 585, // 8
    0, 130, 585,                         // 3
    0, 325, 585,                         // 3
    0, 195, 260, 325, 390, 520, 585,     // 7
    0, 65, 195, 585,                     // 4
    0, 65, 195, 585,                     // 4
    0, 195, 260, 325, 390, 520, 585,     // 7
    0, 325, 585,                         // 3
    0, 130, 585,                         // 3
    0, 65, 130, 260, 325, 455, 520, 585  // 8
};

// pill small x co-ordinate
int pillSmall_x[27] = {
    390, 390, 390,                // 3
    455, 455, 455, 455, 455, 455, // 6
    520, 520,                     // 2
    585, 585, 585,                // 3
    650, 650,                     // 2
    715, 715, 715,                // 3
    780, 780, 780, 780, 780, 780, // 6
    845, 845                      // 2
};

// pill small y co-ordinate
int pillSmall_y[27] = {
    260, 325, 455,               // 3
    65, 130, 195, 260, 390, 520, // 6
    130, 455,                    // 2
    130, 455, 520,               // 3
    455, 520,                    // 2
    65, 130, 455,                // 3
    65, 130, 195, 260, 390, 455, // 6
    325, 455                     // 2
};

// pill-big x co-ordinate
int pillBig_x[4] = { 390, 390, 845, 845 };

// pill-big y co-ordinate
int pillBig_y[4] = { 65, 520, 65, 520 };

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
int kokoMovePosition_x[50] = {
    // pill small x co-ordinate
    390, 390, 390,                // 3
    455, 455, 455, 455, 455, 455, // 6
    520, 520,                     // 2
    585, 585, 585,                // 3
    650, 650,                     // 2
    715, 715, 715,                // 3
    780, 780, 780, 780, 780, 780, // 6
    845, 845,                     // 2
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
    // koko's initital x co-ordinate
    650,
    // ghost green's x co-ordinate
    585,
    // ghost red's x co-ordinate
    520,
    // ghost violet's x co-ordinate
    455,
    // ghost orange's x co-ordinate
    845,
    // ghost pink's x co-ordinate
    780 };

int kokoMovePosition_y[50] = {
    // pill small y co-ordinate
    260, 325, 455,               // 3
    65, 130, 195, 260, 390, 520, // 6
    130, 455,                    // 2
    130, 455, 520,               // 3
    455, 520,                    // 2
    65, 130, 455,                // 3
    65, 130, 195, 260, 390, 455, // 6
    325, 455,                    // 2
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
    130,
    // ghost green's y co-ordinate
    260,
    // ghost red's y co-ordinate
    65,
    // ghost violet's y co-ordinate
    455,
    // ghost orange's y co-ordinate
    260,
    // ghost pink's y co-ordinate
    520

};

// pill small score value
int pillSmall_ScoreValue[27] = {
    10, 10, 10,             // 3
    10, 10, 10, 10, 10, 10, // 6
    10, 10,                 // 2
    10, 10, 10,             // 3
    10, 10,                 // 2
    10, 10, 10,             // 3
    10, 10, 10, 10, 10, 10, // 6
    10, 10                  // 2
};

// pill big score value
int pillBig_ScoreValue[4] = { 20, 20, 20, 20 };

// koko's image height & width
int kokoHeight = 65;
int kokoWidth = 65;

// koko's direction wise image

// koko_right = 1;
// koro_left = 2;
// koko_up = 3;
// koko_down = 4;

// koko's image direction initially 1
// koko's image direction initially right direction
int kokoImgDirection = 1;

// menu image variable

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
    for (int x = 0; x < 27; x++)
    {
        iShowImage(pillSmall_x[x], pillSmall_y[x], pillSmallWidthHeight[x], pillSmallWidthHeight[x], iLoadImage("images\\pillSmall.png"));
    }

    // Floor
    for (int x = 0; x < 12; x++)
    {
        iShowImage(floor_x[x], floor_y[x], floorWidthHeight[x], floorWidthHeight[x], iLoadImage("images\\newFloor.png"));
    }

    // koko's initial position

    // right direction koko
    if (kokoImgDirection == 1)
    {
        iShowImage(kokoro_x, kokoro_y, kokoWidth, kokoHeight, iLoadImage("images\\koko_right.png"));
    }
    // left direction koko
    if (kokoImgDirection == 2)
    {
        iShowImage(kokoro_x, kokoro_y, kokoWidth, kokoHeight, iLoadImage("images\\koko_left.png"));
    }
    // upward direction koko
    if (kokoImgDirection == 3)
    {
        iShowImage(kokoro_x, kokoro_y, kokoWidth, kokoHeight, iLoadImage("images\\koko_up.png"));
    }
    // downward direction koko
    if (kokoImgDirection == 4)
    {
        iShowImage(kokoro_x, kokoro_y, kokoWidth, kokoHeight, iLoadImage("images\\koko_down.png"));
    }

    // level wise ghost
    // ghost for
    // level 1
    if (level == 1)
    {
        // ghost green
        iShowImage(ghost_green_x, ghost_green_y, 65, 65, iLoadImage("images\\ghost_green.png"));
        // ghost red
        iShowImage(ghost_red_x, ghost_red_y, 65, 65, iLoadImage("images\\ghost_red.png"));
        // ghost violet
        iShowImage(ghost_violet_x, ghost_violet_y, 65, 65, iLoadImage("images\\ghost_violet.png"));
    }

    else if (level == 2)
    {
        // ghost green
        iShowImage(ghost_green_x, ghost_green_y, 65, 65, iLoadImage("images\\ghost_green.png"));
        // ghost red
        iShowImage(ghost_red_x, ghost_red_y, 65, 65, iLoadImage("images\\ghost_red.png"));
        // ghost violet
        iShowImage(ghost_violet_x, ghost_violet_y, 65, 65, iLoadImage("images\\ghost_violet.png"));
        // ghost orange
        iShowImage(ghost_orange_x, ghost_orange_y, 65, 65, iLoadImage("images\\ghost_orange.png"));
        // ghost pink
        iShowImage(ghost_pink_x, ghost_pink_y, 65, 65, iLoadImage("images\\ghost_pink.png"));
    }
}

// menu array
int menu[7] = { 0, 1, 2, 3, 4, 5, 6 };

int menuItem = menu[0];
int* menuItemPtr = &menuItem;

// menu item height and width
int menuItemHeight = 650;
int menuItemWidth = 1300;

// reinitialize game resources function
void reinitializeGameRes()
{
    // small pill visiable
    // reinitialize the small pill score value
    for (int i = 0; i < 27; i++)
    {
        pillSmallWidthHeight[i] = 65;
        pillSmall_ScoreValue[i] = 10;
    }

    // big pill visiable
    // reinitialize the big pill score value
    for (int i = 0; i < 4; i++)
    {

        pillBigWidthHeight[i] = 65;
        pillBig_ScoreValue[i] = 20;
    }

    // reinitialize the koko's previous co-ordinate
    kokoro_x = 650;
    kokoro_y = 130;

    // game live
    if (level == 1) {
        live = 3;
    }
    else if (level == 2) {
        live = 5;
    }
    if (lastLevelCompleted == 1) {
        *playerScorePtr = 0;
    }
    if (level == 1) {
        if (live <= 0 || playerScore <= 0) {
            *playerScorePtr = 0;
        }
    }
    if (level == 2) {
        if (live <= 0 || playerScore <= 0) {
            *playerScorePtr = 0;
        }
    }

}

// exit variable
int exitVar = 0;

// when ghost and koko hits together
// koko will loss points
void kokoHitsGhost()
{
    if (*menuItemPtr == menu[1])
    {
        if ((ghost_green_x == kokoro_x) && (ghost_green_y == kokoro_y))
        {
            playerScore -= ghostGreenPower;
            live--;
        }
        if ((ghost_red_x == kokoro_x) && (ghost_red_y == kokoro_y))
        {
            playerScore -= ghostRedPower;
            live--;
        }
        if ((ghost_violet_x == kokoro_x) && (ghost_violet_y == kokoro_y))
        {
            playerScore -= ghostVioletPower;
            live--;
        }
        if ((ghost_orange_x == kokoro_x) && (ghost_orange_y == kokoro_y))
        {
            playerScore -= ghostOrangePower;
            live--;
        }
        if ((ghost_pink_x == kokoro_x) && (ghost_pink_y == kokoro_y))
        {
            playerScore -= ghostPinkPower;
            live--;
        }
    }
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

void iDraw()
{
    iClear();

    // start background
    if (*menuItemPtr == menu[0])
    {
        iShowImage(0, 0, start_bg_width, start_bg_height, iLoadImage("images\\start_bg.png"));
    }

    // play game
    else if (*menuItemPtr == menu[1])
    {
        // controlling ghost game depending on exitVar == 0
        exitVar = 0;
        // rendering game user interface
        show_game_res();
    }

    // high scores
    else if (*menuItemPtr == menu[2])
    {
        // counter
        int m = 0;
        // open file in read mode
        readFile.open("scores.txt");
        while (m < 5) {
            // store value in score array
            readFile >> score[m];
            m++;
        }
        // close file of read mode
        //readFile.close();
        //cout << "read file closed" << endl;


        iShowImage(0, 0, menuItemWidth, menuItemHeight, iLoadImage("images\\highScores.png"));
        string str_scr_1 = to_string(score[0]);
        string str_scr_2 = to_string(score[1]);
        string str_scr_3 = to_string(score[2]);
        string str_scr_4 = to_string(score[3]);
        string str_scr_5 = to_string(score[4]);
        

        char score1[100];
        char score2[100];
        char score3[100];
        char score4[100];
        char score5[100];


        strcpy_s(score1, str_scr_1.c_str());
        strcpy_s(score2, str_scr_2.c_str());
        strcpy_s(score3, str_scr_3.c_str());
        strcpy_s(score4, str_scr_4.c_str());
        strcpy_s(score5, str_scr_5.c_str());

        // showing high scores score text in the high scores screen
        iSetColor(255, 255, 255);
        iText(645, 425, score1, GLUT_BITMAP_TIMES_ROMAN_24);
        iText(645, 385, score2, GLUT_BITMAP_TIMES_ROMAN_24);
        iText(645, 345, score3, GLUT_BITMAP_TIMES_ROMAN_24);
        iText(645, 305, score4, GLUT_BITMAP_TIMES_ROMAN_24);
        iText(645, 265, score5, GLUT_BITMAP_TIMES_ROMAN_24);
    }

    // levels
    else if (*menuItemPtr == menu[3])
    {
        iShowImage(0, 0, menuItemWidth, menuItemHeight, iLoadImage("images\\levels.png"));
    }

    // learn
    else if (*menuItemPtr == menu[4])
    {
        iShowImage(0, 0, start_bg_width, start_bg_height, iLoadImage("images\\learn.png"));
    }

    // about
    else if (*menuItemPtr == menu[5])
    {
        iShowImage(0, 0, start_bg_width, start_bg_height, iLoadImage("images\\about.png"));
    }

    // score text and koko's live
    if (*menuItemPtr == menu[1])
    {
        string scoreString = to_string(*playerScorePtr); // convert int to string data type
        char scoreText[100];                             // declare charracter array
        strcpy_s(scoreText, scoreString.c_str());        // copy string to a charracter array

        // showing score text in the play game screen
        iSetColor(255, 255, 255);
        iText(1075, 330, "SCORE : ", GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255, 255, 255);
        iText(1180, 330, scoreText, GLUT_BITMAP_TIMES_ROMAN_24); // show that charracter array

        // working on Koko's Live
        int redLiveDx;
        if (level == 1) {
            redLiveDx = 150;
        }
        else if (level == 2) {
            redLiveDx = 250;
        }
        if (live >= 0) {
            // red live
            iSetColor(255, 0, 0);
            iFilledRectangle(990, 550, redLiveDx, 65);
            // green live
            iSetColor(0, 255, 0);
            iFilledRectangle(990, 550, 50 * live, 65);
        }
    }

    // checking if first level is finished or not
    int flag = 1;
    for (int i = 0; i < 27; i++)
    {
        // checking small pills and big pills are eaten or not
        if (pillSmall_ScoreValue[i] != 0)
        {
            flag = 0;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        if (pillBig_ScoreValue[i] != 0)
        {
            flag = 0;
        }
    }
    // checking if level 1 is completed or not
    // then go to level 2
    if (flag == 1 && level == 1 && live >= 0)
    {
        // stop the control ghost function because first level is completed
        exitVar = 1;
        // level one is completed
        levelOneCompleted = 1;
        // off level two
        levelTwoCompleted = 0;

        // next level button background
        // iSetColor(255, 255, 255);
        iFilledRectangle(1075, 50, 150, 65);
        // next level button text
        iSetColor(0, 0, 0);
        iText(1095, 73, "Next Level", GLUT_BITMAP_TIMES_ROMAN_24);
    }
    // checking if level 2 is completed or not
    //// then go to level 2
    if (flag == 1 && level == 2)
    {
        // level two is completed
        levelTwoCompleted = 1;
        lastLevelCompleted = 1;
        // off level one
        levelOneCompleted = 0;
        // stop the control ghost function because first level is completed
        exitVar = 1;
        // after level 2 is completed

        // next level button background
        // iSetColor(255, 255, 255);
        iFilledRectangle(1075, 50, 150, 65);
        // main menu button text
        iSetColor(0, 0, 0);
        iText(1095, 73, "Main Menu", GLUT_BITMAP_TIMES_ROMAN_24);
    }

    // showing level one text
    if ((level == 1) && (levelOneCompleted != 1) && (*menuItemPtr == menu[1]))
    {
        iSetColor(255, 255, 255);
        iText(1075, 500, "Level 1", GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if ((level == 2) && (levelTwoCompleted != 1) && (*menuItemPtr == menu[1]))
    {
        iSetColor(255, 255, 255);
        iText(1075, 500, "Level 2", GLUT_BITMAP_TIMES_ROMAN_24);
    }

    // working on live
    if (live == 0) {
        exitVar = 1;
    }

    // working on file
    // to permanently store scores data in files

    // if level 1 is not completed
    if (level == 1 && exitVar == 1 && fileWrittenIndicator) {
        if (live <= 0 || playerScore <= 0) {
            cout << "1 not completed" << endl;
            // counter
            int m = 0;
            // open file in read mode
            readFile.open("scores.txt");
            while (m < 5) {
                // store value in score array
                readFile >> score[m];
                m++;
            }
            // close file of read mode
            readFile.close();
            cout << "read file closed" << endl;

            // print score array
            for (int i = 0;i < 5;i++) {
                cout << score[i] << endl;
            }
            score[5] = playerScore;
            // check high score in array with player score
            for (int i = 0;i < 6;i++) {
                for (int j = i + 1;j < 6;j++) {
                    if (score[i] < score[j])
                    {
                        int a = score[i];
                        score[i] = score[j];
                        score[j] = a;
                    }
                }
            }
            // print score array
            for (int i = 0;i < 5;i++) {
                cout << score[i] << endl;
            }
            // open file in write mode
            file.open("scores.txt");
            if (fileWrittenIndicator == 1) {
                for (int i = 0;i < 5;i++) {
                    // store the updated score in file
                    file << score[i] << endl;
                }
                fileWrittenIndicator = 0;
            }
            // close file
            file.close();
            cout << "file closed" << endl;
            fileWrittenIndicator = 0;
            cout << "done 1 not completed" << endl;
        }
    }
    // if level 1 completed but level 2 not completed
    if (level == 2 && exitVar == 1 && fileWrittenIndicator) {
        if (live <= 0 || playerScore <= 0) {
            cout << "2 not completed" << endl;
            // counter
            int m = 0;
            // open file in read mode
            readFile.open("scores.txt");
            while (m < 5) {
                // store value in score array
                readFile >> score[m];
                m++;
            }
            // close file of read mode
            readFile.close();

            // print score array
            for (int i = 0;i < 5;i++) {
                cout << score[i] << endl;
            }
            score[5] = playerScore;
            // check high score in array with player score
            for (int i = 0;i < 6;i++) {
                for (int j = i + 1;j < 6;j++) {
                    if (score[i] < score[j])
                    {
                        int a = score[i];
                        score[i] = score[j];
                        score[j] = a;
                    }
                }
            }
            // print score array
            for (int i = 0;i < 5;i++) {
                cout << score[i] << endl;
            }
            // open file in write mode
            file.open("scores.txt");
            if (fileWrittenIndicator == 1) {
                for (int i = 0;i < 5;i++) {
                    // store the updated score in file
                    file << score[i] << endl;
                }
                fileWrittenIndicator = 0;
            }
            // close file
            file.close();
            cout << "file closed" << endl;
            fileWrittenIndicator = 0;
            cout << "done 2 not completed" << endl;
        }
    }
    // if level 2 completed
    // that means level 1 and level 2 both are completed
    if (lastLevelCompleted == 1 && lastLevelScoreWrittenIndicator == 1) {
        cout << "2 completed" << endl;
        // counter
        int m = 0;
        // open file in read mode
        readFile.open("scores.txt");
        while (m < 5) {
            // store value in score array
            readFile >> score[m];
            m++;
        }
        // close file of read mode
        readFile.close();

        // print score array
        for (int i = 0;i < 5;i++) {
            cout << score[i] << endl;
        }
        score[5] = playerScore;
        // check high score in array with player score
        for (int i = 0;i < 6;i++) {
            for (int j = i + 1;j < 6;j++) {
                if (score[i] < score[j])
                {
                    int a = score[i];
                    score[i] = score[j];
                    score[j] = a;
                }
            }
        }
        // print score array
        for (int i = 0;i < 5;i++) {
            cout << score[i] << endl;
        }
        // open file in write mode
        file.open("scores.txt");
        if (fileWrittenIndicator == 1) {
            for (int i = 0;i < 5;i++) {
                // store the updated score in file
                file << score[i] << endl;
            }
            fileWrittenIndicator = 0;
        }
        // close file
        file.close();
        cout << "file closed" << endl;
        fileWrittenIndicator = 0;
        lastLevelScoreWrittenIndicator = 0;
        cout << "done 2 completed" << endl;
        lastLevelScoreWrittenIndicator = 0;
        lastLevelCompleted = 0;
    }
    
    
    

    // game quit
    if (gameQuit == 1)
    {
        // close the read file while exit the game
        //readFile.close();
        exit(0);
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
        if ((mx >= 132 && mx <= 354) && (my >= 434 && my <= 538))
        {
            iClear();
            *menuItemPtr = 1;
            cout << "Play Game" << endl;

            // set play music value to 1
            playMusic = 1;
            *playMusicPtr = 1;

            if (playMusic == 1)
            {
                PlaySound("musics//playGameMusic.wav", NULL, SND_LOOP | SND_ASYNC);
            }

            // reset game
            if (lastLevelCompleted == 1) {
                reinitializeGameRes();
            }
            if (level == 1) {
                if (live <= 0 || playerScore <= 0) {
                    reinitializeGameRes();
                }
            }
            if (level == 2) {
                if (live <= 0 || playerScore <= 0) {
                    reinitializeGameRes();
                }
            }
        }

        // high score menu item
        else if ((mx >= 132 && mx <= 354) && (my >= 273 && my <= 377))
        {

            cout << "High Scores" << endl;
            *menuItemPtr = 2;
        }

        // Levels menu item
        else if ((mx >= 132 && mx <= 354) && (my >= 119 && my <= 222))
        {
            cout << "Levels" << endl;
            *menuItemPtr = 3;
        }

        // Learn menu item
        else if ((mx >= 855 && mx <= 1117) && (my >= 434 && my <= 538))
        {
            *menuItemPtr = 4;
            cout << "Learn" << endl;
        }

        // about menu item
        else if ((mx >= 855 && mx <= 1117) && (my >= 276 && my <= 380))
        {
            cout << "About" << endl;
            *menuItemPtr = 5;
        }

        // quit menu item
        else if ((mx >= 855 && mx <= 1117) && (my >= 118 && my <= 223))
        {
            gameQuit = 1;
            cout << "Quit" << endl;
        }

        // first level completed
        else if ((mx >= 1075 && mx <= 1225) && (my >= 50 && my <= 119) && (level == 1))
        {
            level = 2;

            reinitializeGameRes();
        }

        // second level completed
        else if ((mx >= 1075 && mx <= 1225) && (my >= 50 && my <= 119) && (level == 2))
        {
            // if level 2 is completed game will finished and ready the game ui resources for first level
            level = 1;

            reinitializeGameRes(); // reinitialize game resources

            *menuItemPtr = menu[0]; // go to menu page
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
    if (key == 109) // m
    {
        // controlling music
        if (playMusic)
        {
            playMusic = 0;
            PlaySound(0, 0, 0);
        }
        else
        {
            playMusic = 1;
            PlaySound("musics//playGameMusic.wav", NULL, SND_LOOP | SND_ASYNC);
        }
    }
    else if (key == 8) // backspace
    {
        if (menuItem = menu[1])
        {
            exitVar = 1;
        }
        if (menuItem = menu[2]) {
            file.close();
            cout << "read file closed" << endl;
        }
        *menuItemPtr = 0;
    }
}

// control ghost green function

void controlGhostGreen()
{
    // ghost and koko hits themselves
    // koko will lose 10 points
    // int ghostGreenPower = 10;

    // 0 for right, 1 for left, 2 for up and 3 for down direction

    int ghostImgTotalDirections = 4;
    int ghostImgDirection = rand() % (ghostImgTotalDirections - 0);
    // int ghostImgDirection = 2;

    // for right
    if (ghostImgDirection == 0)
    {
        for (int x = 0; x < 50; x++)
        {
            if ((ghost_green_x + 65 == kokoMovePosition_x[x]) && (ghost_green_y == kokoMovePosition_y[x]))
            {
                ghost_green_x += 65;
                break;
            }
        }

        // if ((ghost_green_x == kokoro_x) && (ghost_green_y == kokoro_y))
        // {
        //     playerScore -= ghostGreenPower;
        // }
    }

    // left direction
    if (ghostImgDirection == 1)
    {
        for (int x = 0; x < 50; x++)
        {
            if ((ghost_green_x - 65 == kokoMovePosition_x[x]) && (ghost_green_y == kokoMovePosition_y[x]))
            {
                ghost_green_x -= 65;
                break;
            }
        }
        // if ((ghost_green_x == kokoro_x) && (ghost_green_y == kokoro_y))
        // {
        //     playerScore -= ghostGreenPower;
        // }
    }

    // upward direction
    if (ghostImgDirection == 2)
    {
        for (int x = 0; x < 50; x++)
        {
            if ((ghost_green_x == kokoMovePosition_x[x]) && (ghost_green_y + 65 == kokoMovePosition_y[x]))
            {
                ghost_green_y += 65;
                break;
            }
        }
        // if ((ghost_green_x == kokoro_x) && (ghost_green_y == kokoro_y))
        // {
        //     playerScore -= ghostGreenPower;
        // }
    }

    // downward direction
    if (ghostImgDirection == 3)
    {
        for (int x = 0; x < 50; x++)
        {
            if ((ghost_green_x == kokoMovePosition_x[x]) && (ghost_green_y - 65 == kokoMovePosition_y[x]))
            {
                ghost_green_y -= 65;
                break;
            }
        }

        // if ((ghost_green_x == kokoro_x) && (ghost_green_y == kokoro_y))
        // {
        //     playerScore -= ghostGreenPower;
        // }
    }
}

// control red ghost
void controlGhostRed()
{

    // ghost and koko hits themselves
    // koko will lose 50 points
    // int ghostRedPower = 50;

    // 0 for right, 1 for left, 2 for up and 3 for down direction

    int ghostImgTotalDirections = 4;
    int ghostImgDirection = rand() % (ghostImgTotalDirections - 0);
    // int ghostImgDirection = 2;

    // for right
    if (ghostImgDirection == 0)
    {
        for (int x = 0; x < 50; x++)
        {
            if ((ghost_red_x + 65 == kokoMovePosition_x[x]) && (ghost_red_y == kokoMovePosition_y[x]))
            {
                ghost_red_x += 65;
                break;
            }
        }

        // if ((ghost_red_x == kokoro_x) && (ghost_red_y == kokoro_y))
        // {
        //     playerScore -= ghostRedPower;
        // }
    }

    // left direction
    if (ghostImgDirection == 1)
    {
        for (int x = 0; x < 50; x++)
        {
            if ((ghost_red_x - 65 == kokoMovePosition_x[x]) && (ghost_red_y == kokoMovePosition_y[x]))
            {
                ghost_red_x -= 65;
                break;
            }
        }
        // if ((ghost_red_x == kokoro_x) && (ghost_red_y == kokoro_y))
        // {
        //     playerScore -= ghostRedPower;
        // }
    }

    // upward direction
    if (ghostImgDirection == 2)
    {
        for (int x = 0; x < 50; x++)
        {
            if ((ghost_red_x == kokoMovePosition_x[x]) && (ghost_red_y + 65 == kokoMovePosition_y[x]))
            {
                ghost_red_y += 65;
                break;
            }
        }
        // if ((ghost_red_x == kokoro_x) && (ghost_red_y == kokoro_y))
        // {
        //     playerScore -= ghostRedPower;
        // }
    }

    // downward direction
    if (ghostImgDirection == 3)
    {
        for (int x = 0; x < 50; x++)
        {
            if ((ghost_red_x == kokoMovePosition_x[x]) && (ghost_red_y - 65 == kokoMovePosition_y[x]))
            {
                ghost_red_y -= 65;
                break;
            }
        }

        // if ((ghost_red_x == kokoro_x) && (ghost_red_y == kokoro_y))
        // {
        //     playerScore -= ghostRedPower;
        // }
    }
}

// control violet ghost
void controlGhostViolet()
{

    // ghost and koko hits themselves
    // koko will lose 50 points
    // int ghostVioletPower = 10;

    // 0 for right, 1 for left, 2 for up and 3 for down direction

    int ghostImgTotalDirections = 4;
    int ghostImgDirection = rand() % (ghostImgTotalDirections - 0);
    // int ghostImgDirection = 2;

    // for right
    if (ghostImgDirection == 0)
    {
        for (int x = 0; x < 50; x++)
        {
            if ((ghost_violet_x + 65 == kokoMovePosition_x[x]) && (ghost_violet_y == kokoMovePosition_y[x]))
            {
                ghost_violet_x += 65;
                break;
            }
        }

        // if ((ghost_violet_x == kokoro_x) && (ghost_violet_y == kokoro_y))
        // {
        //     playerScore -= ghostVioletPower;
        // }
    }

    // left direction
    if (ghostImgDirection == 1)
    {
        for (int x = 0; x < 50; x++)
        {
            if ((ghost_violet_x - 65 == kokoMovePosition_x[x]) && (ghost_violet_y == kokoMovePosition_y[x]))
            {
                ghost_violet_x -= 65;
                break;
            }
        }
        // if ((ghost_violet_x == kokoro_x) && (ghost_violet_y == kokoro_y))
        // {
        //     playerScore -= ghostVioletPower;
        // }
    }

    // upward direction
    if (ghostImgDirection == 2)
    {
        for (int x = 0; x < 50; x++)
        {
            if ((ghost_violet_x == kokoMovePosition_x[x]) && (ghost_violet_y + 65 == kokoMovePosition_y[x]))
            {
                ghost_violet_y += 65;
                break;
            }
        }
        // if ((ghost_violet_x == kokoro_x) && (ghost_violet_y == kokoro_y))
        // {
        //     playerScore -= ghostVioletPower;
        // }
    }

    // downward direction
    if (ghostImgDirection == 3)
    {
        for (int x = 0; x < 50; x++)
        {
            if ((ghost_violet_x == kokoMovePosition_x[x]) && (ghost_violet_y - 65 == kokoMovePosition_y[x]))
            {
                ghost_violet_y -= 65;
                break;
            }
        }

        // if ((ghost_violet_x == kokoro_x) && (ghost_violet_y == kokoro_y))
        // {
        //     playerScore -= ghostVioletPower;
        // }
    }
}

// control violet ghost
void controlGhostOrange()
{

    // ghost and koko hits themselves
    // koko will lose 50 points
    // int ghostOrangePower = 10;

    // 0 for right, 1 for left, 2 for up and 3 for down direction

    int ghostImgTotalDirections = 4;
    int ghostImgDirection = rand() % (ghostImgTotalDirections - 0);
    // int ghostImgDirection = 2;

    // for right
    if (ghostImgDirection == 0)
    {
        for (int x = 0; x < 50; x++)
        {
            if ((ghost_orange_x + 65 == kokoMovePosition_x[x]) && (ghost_orange_y == kokoMovePosition_y[x]))
            {
                ghost_orange_x += 65;
                break;
            }
        }

        // if ((ghost_orange_x == kokoro_x) && (ghost_orange_y == kokoro_y))
        // {
        //     playerScore -= ghostOrangePower;
        // }
    }

    // left direction
    if (ghostImgDirection == 1)
    {
        for (int x = 0; x < 50; x++)
        {
            if ((ghost_orange_x - 65 == kokoMovePosition_x[x]) && (ghost_orange_y == kokoMovePosition_y[x]))
            {
                ghost_orange_x -= 65;
                break;
            }
        }
        // if ((ghost_orange_x == kokoro_x) && (ghost_orange_y == kokoro_y))
        // {
        //     playerScore -= ghostOrangePower;
        // }
    }

    // upward direction
    if (ghostImgDirection == 2)
    {
        for (int x = 0; x < 50; x++)
        {
            if ((ghost_orange_x == kokoMovePosition_x[x]) && (ghost_orange_y + 65 == kokoMovePosition_y[x]))
            {
                ghost_orange_y += 65;
                break;
            }
        }
        // if ((ghost_orange_x == kokoro_x) && (ghost_orange_y == kokoro_y))
        // {
        //     playerScore -= ghostOrangePower;
        // }
    }

    // downward direction
    if (ghostImgDirection == 3)
    {
        for (int x = 0; x < 50; x++)
        {
            if ((ghost_orange_x == kokoMovePosition_x[x]) && (ghost_orange_y - 65 == kokoMovePosition_y[x]))
            {
                ghost_orange_y -= 65;
                break;
            }
        }

        // if ((ghost_orange_x == kokoro_x) && (ghost_orange_y == kokoro_y))
        // {
        //     playerScore -= ghostOrangePower;
        // }
    }
}

// control pink ghost
void controlGhostPink()
{

    // ghost and koko hits themselves
    // koko will lose 50 points
    // int ghostPinkPower = 10;

    // 0 for right, 1 for left, 2 for up and 3 for down direction

    int ghostImgTotalDirections = 4;
    int ghostImgDirection = rand() % (ghostImgTotalDirections - 0);
    // int ghostImgDirection = 2;

    // for right
    if (ghostImgDirection == 0)
    {
        for (int x = 0; x < 50; x++)
        {
            if ((ghost_pink_x + 65 == kokoMovePosition_x[x]) && (ghost_pink_y == kokoMovePosition_y[x]))
            {
                ghost_pink_x += 65;
                break;
            }
        }

        // if ((ghost_pink_x == kokoro_x) && (ghost_pink_y == kokoro_y))
        // {
        //     playerScore -= ghostPinkPower;
        // }
    }

    // left direction
    if (ghostImgDirection == 1)
    {
        for (int x = 0; x < 50; x++)
        {
            if ((ghost_pink_x - 65 == kokoMovePosition_x[x]) && (ghost_pink_y == kokoMovePosition_y[x]))
            {
                ghost_pink_x -= 65;
                break;
            }
        }
        // if ((ghost_pink_x == kokoro_x) && (ghost_pink_y == kokoro_y))
        // {
        //     playerScore -= ghostPinkPower;
        // }
    }

    // upward direction
    if (ghostImgDirection == 2)
    {
        for (int x = 0; x < 50; x++)
        {
            if ((ghost_pink_x == kokoMovePosition_x[x]) && (ghost_pink_y + 65 == kokoMovePosition_y[x]))
            {
                ghost_pink_y += 65;
                break;
            }
        }
        // if ((ghost_pink_x == kokoro_x) && (ghost_pink_y == kokoro_y))
        // {
        //     playerScore -= ghostPinkPower;
        // }
    }

    // downward direction
    if (ghostImgDirection == 3)
    {
        for (int x = 0; x < 50; x++)
        {
            if ((ghost_pink_x == kokoMovePosition_x[x]) && (ghost_pink_y - 65 == kokoMovePosition_y[x]))
            {
                ghost_pink_y -= 65;
                break;
            }
        }

        // if ((ghost_pink_x == kokoro_x) && (ghost_pink_y == kokoro_y))
        // {
        //     playerScore -= ghostPinkPower;
        // }
    }
}

// control ghost
void controlGhost()
{
    if (exitVar == 0)
    {
        if (level == 1)
        {
            controlGhostGreen();
            controlGhostRed();
            controlGhostViolet();
        }
        if (level == 2)
        {
            controlGhostGreen();
            controlGhostRed();
            controlGhostViolet();
            controlGhostOrange();
            controlGhostPink();
        }
    }
}

// void run ghost
/*
void runGhost() {
    // koko hits ghost function
    int setTimer = 500;
    if (level == 1) {
        setTimer = 500;
    }
    else if (level == 2) {
        setTimer = 100;
    }
    // set control ghost function after every setTimer variable ms
    iSetTimer(setTimer, controlGhost);
    // set hit ghotst function after every setTimer variable ms
    iSetTimer(setTimer, kokoHitsGhost);
}
*/

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
    // controling kokoro
    // RIGHT KEY PRESSED
    if (key == GLUT_KEY_RIGHT)
    {
        if (exitVar == 0) {
            kokoImgDirection = 1;

            // move koko from right side to left side
            if (kokoro_x == 910 && kokoro_y == 195)
            {
                kokoro_x = 325;
            }
            else if (kokoro_x == 910 && kokoro_y == 390)
            {
                kokoro_x = 325;
            }

            // changing positions to right
            for (int x = 0; x < 50; x++)
            {
                if ((kokoro_x + 65 == kokoMovePosition_x[x]) && (kokoro_y == kokoMovePosition_y[x]))
                {
                    kokoro_x += 65;
                    break;
                }
            }

            // for eating pill big
            for (int x = 0; x < 4; x++)
            {
                if (pillBig_x[x] == kokoro_x && pillBig_y[x] == kokoro_y)
                {
                    pillBigWidthHeight[x] = 0;
                    playerScore += pillBig_ScoreValue[x];
                    pillBig_ScoreValue[x] = 0;
                }
            }
            // for eating small pill
            for (int x = 0; x < 27; x++)
            {
                if (pillSmall_x[x] == kokoro_x && pillSmall_y[x] == kokoro_y)
                {
                    pillSmallWidthHeight[x] = 0;
                    playerScore += pillSmall_ScoreValue[x];
                    pillSmall_ScoreValue[x] = 0;
                }
            }
        }
    }

    // LEFT KEY PRESSED
    if (key == GLUT_KEY_LEFT)
    {

        if (exitVar == 0) {
            // sets koko img direction to 2 for left direction
            kokoImgDirection = 2;

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
            for (int x = 0; x < 50; x++)
            {
                if ((kokoro_x - 65 == kokoMovePosition_x[x]) && (kokoro_y == kokoMovePosition_y[x]))
                {
                    kokoro_x -= 65;
                    break;
                }
            }

            // for eating pill big
            for (int x = 0; x < 4; x++)
            {
                if (pillBig_x[x] == kokoro_x && pillBig_y[x] == kokoro_y)
                {
                    pillBigWidthHeight[x] = 0;
                    playerScore += pillBig_ScoreValue[x];
                    pillBig_ScoreValue[x] = 0;
                }
            }
            // for eating small pill
            for (int x = 0; x < 27; x++)
            {
                if (pillSmall_x[x] == kokoro_x && pillSmall_y[x] == kokoro_y)
                {
                    pillSmallWidthHeight[x] = 0;
                    playerScore += pillSmall_ScoreValue[x];
                    pillSmall_ScoreValue[x] = 0;
                }
            }
        }
    }

    // UP KEY PRESSED
    if (key == GLUT_KEY_UP)
    {

        if (exitVar == 0) {
            // controlling koko

            kokoImgDirection = 3;

            for (int x = 0; x < 50; x++)
            {
                if ((kokoro_x == kokoMovePosition_x[x]) && (kokoro_y + 65 == kokoMovePosition_y[x]))
                {
                    kokoro_y += 65;
                    break;
                }
            }

            // for eating pill big
            for (int x = 0; x < 4; x++)
            {
                if (pillBig_x[x] == kokoro_x && pillBig_y[x] == kokoro_y)
                {
                    pillBigWidthHeight[x] = 0;
                    playerScore += pillBig_ScoreValue[x];
                    pillBig_ScoreValue[x] = 0;
                }
            }
            // for eating small pill
            for (int x = 0; x < 27; x++)
            {
                if (pillSmall_x[x] == kokoro_x && pillSmall_y[x] == kokoro_y)
                {
                    pillSmallWidthHeight[x] = 0;
                    playerScore += pillSmall_ScoreValue[x];
                    pillSmall_ScoreValue[x] = 0;
                }
            }
        }
    }

    // DOWN KEY PRESSED
    if (key == GLUT_KEY_DOWN)
    {

        if (exitVar == 0) {
            // controlling koko

        // sets koko img direction to 4 for down direction
            kokoImgDirection = 4;

            // changing positions to downward directions
            for (int x = 0; x < 50; x++)
            {
                if ((kokoro_x == kokoMovePosition_x[x]) && (kokoro_y - 65 == kokoMovePosition_y[x]))
                {
                    kokoro_y -= 65;
                    break;
                }
            }

            // for eating pill big
            for (int x = 0; x < 4; x++)
            {
                if (pillBig_x[x] == kokoro_x && pillBig_y[x] == kokoro_y)
                {
                    pillBigWidthHeight[x] = 0;
                    playerScore += pillBig_ScoreValue[x];
                    pillBig_ScoreValue[x] = 0;
                }
            }
            // for eating small pill
            for (int x = 0; x < 27; x++)
            {
                if (pillSmall_x[x] == kokoro_x && pillSmall_y[x] == kokoro_y)
                {
                    pillSmallWidthHeight[x] = 0;
                    playerScore += pillSmall_ScoreValue[x];
                    pillSmall_ScoreValue[x] = 0;
                }
            }
        }
    }
}

int main()
{
    // set control ghost function after every setTimer variable ms
    iSetTimer(500, controlGhost);
    // set hit ghotst function after every setTimer variable ms
    iSetTimer(500, kokoHitsGhost);

    //  initialize KOKORO window
    iInitialize(screen_width, screen_height, "KOKORO GAME");

    // machine starts here
    iStart();

    return 0;
}