/*******************************************************************************
 *  AUTHOR       : John Hawley
 *  Assignment #7: Text Adventure
 *  CLASS        : CS 002
 *  SECTION      : MW: 10:45a - 12:50p, TR: 10:45a - 12:10p
 *  Due Date     : 4/21/19
 ******************************************************************************/
#include <iostream>
using namespace std;
/*******************************************************************************
 *
 *  Text Adventure
 *______________________________________________________________________________
 * This program is a simple text adventure game. Within this game the player
 *  will travel from room to room choosing which door to traverse through.
 * _____________________________________________________________________________
 * INPUT:
 *
 * OUTPUT:
 *
 ******************************************************************************/
void monsterRoom(int& bananas,          //
                 int& oranges,          //
                 string monsterName);   //

void genieRoom(int& bananas,            //
               int& oranges);           //

void drawPicture();

void pictureRoom();

bool exitRoom(int bananas,              //
              int oranges);             //

void doorN(bool alignment,              //
           int& bananas,                //
           int& oranges,                //
           string monsterName);         //

void doorE(bool alignment,              //
           int& bananas,                //
           int& oranges,                //
           string monsterName);         //

void doorS(bool alignment,              //
           int& bananas,                //
           int& oranges);               //

void doorW(bool alignment,              //
           int& bananas,                //
           int& oranges);               //


int main()
{
    // Variables
    int bananas;
    int oranges;
    string playerName;
    string monsterName;
    bool alignment;


// Testing
//    bananas = 3;
//    oranges = 2;
//    monsterName = "penisbreath";
//    alignment = 0;

//    doorN(alignment, bananas, oranges, monsterName);

//    cout << bananas << endl;
//    cout << oranges << endl;


    return 0;
}

void monsterRoom(int& bananas,          //
                 int& oranges,          //
                 string monsterName)    //
{
    bananas = 0;
    oranges = 0;

    cout << "WATCH OUT!!" << endl;
    cout << monsterName << " attacks you and steals all of your bananas and"
         << " oranges." << endl;
    cout << endl;
}

void genieRoom(int& bananas,            //
               int& oranges)            //
{
    bananas += 2;
    oranges += 1;

    cout << "!!POOF!!" << endl;
    cout << "A genie pops out and grants you 2 bananas and 1 orange." << endl;
    cout << endl;
}


void drawPicture()
{
    cout << "        _--~~--_" << endl;
    cout << "      /~/_|  |_\\~\\" << endl;
    cout << "     |____________|" << endl;
    cout << "     |[][][][][][]|" << endl;
    cout << "   __| __         |__" << endl;
    cout << "  |  ||. |   ==   |  |" << endl;
    cout << " (|  ||__|   ==   |  |)" << endl;
    cout << "  |  |[] []  ==   |  |" << endl;
    cout << "  |  |____________|  |" << endl;
    cout << "  /__\\            /__\\" << endl;
    cout << "   ~~              ~~ " << endl;
    cout << endl;
}

void pictureRoom()
{
    cout << "You found a picture!" << endl;
    cout << endl;
    drawPicture();
}

bool exitRoom(int bananas,          //
              int oranges)          //
{
    cout << "You found the exit!" << endl;
    cout << "Your score is " << bananas + oranges << " (" << bananas
         << " bananas and " << oranges << " oranges)." << endl;
    return 0;
}

//You must write a function for each door. When the player chooses a door in a certain direction (N/E/S/W) -- and only one of those values -- the program should call the function for the door in that direction or end the program if she chooses the door to the exit. Some of these functions will use reference variables for all or some of their parameters.

void doorN(bool alignment,          //
           int& bananas,            //
           int& oranges,            //
           string monsterName)      //
{
    if (alignment == 0)
    {
        monsterRoom(bananas, oranges, monsterName);
    }
    else
    {
        exitRoom(bananas, oranges);
    }
}

void doorE(bool alignment,          //
           int& bananas,            //
           int& oranges,            //
           string monsterName)      //
{
    if (alignment == 0)
    {
        genieRoom(bananas, oranges);
    }
    else
    {
        monsterRoom(bananas, oranges, monsterName);
    }
}

void doorS(bool alignment,          //
           int& bananas,            //
           int& oranges)            //
{
    if (alignment == 0)
    {
        pictureRoom();
    }
    else
    {
        genieRoom(bananas, oranges);
    }
}

void doorW(bool alignment,          //
           int& bananas,            //
           int& oranges)            //
{
    if (alignment == 0)
    {
        exitRoom(bananas, oranges);
    }
    else
    {
        pictureRoom();
    }
}






