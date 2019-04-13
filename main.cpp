/*******************************************************************************
 *  AUTHOR       : John Hawley
 *  Assignment #7: Text Adventure
 *  CLASS        : CS 002
 *  SECTION      : MW: 10:45a - 12:50p, TR: 10:45a - 12:10p
 *  Due Date     : 4/21/19
 ******************************************************************************/
#include <iostream>
#include <cstdlib>
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

void exitRoom(int bananas,              //
              int oranges);             //

bool doorN(bool alignment,              //
           int& bananas,                //
           int& oranges,                //
           string monsterName);         //

bool doorE(bool alignment,              //
           int& bananas,                //
           int& oranges,                //
           string monsterName);         //

bool doorS(bool alignment,              //
           int& bananas,                //
           int& oranges);               //

bool doorW(bool alignment,              //
           int& bananas,                //
           int& oranges);               //

void outputUpdate (string playerName,
                   int bananas,
                   int oranges);

void pickDoor (char& door);

void matchDoor (char& door,
                bool alignment,
                int& bananas,
                int& oranges,
                string monsterName,
                bool& go);


int main()
{
    // Seed Random
    srand(500);

    // Variables
    int bananas;
    int oranges;
    string playerName;
    string monsterName;
    bool alignment;
    char door;
    bool go;

    // Variable Initialization
    bananas = 5;
    oranges = 3;
    go = 1;

    cout << "Please enter your name: ";
    cin >> playerName;
    cout << endl;

    cout << "Name your scariest monster: ";
    cin >> monsterName;
    cout << endl;

    do
    {
        outputUpdate(playerName, bananas, oranges);
        alignment = rand() % 2;
        pickDoor(door);
        matchDoor(door, alignment, bananas, oranges, monsterName, go);

    } while (go != 0);

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

void exitRoom(int bananas,          //
              int oranges)          //
{
    cout << "You found the exit!" << endl;
    cout << "Your score is " << bananas + oranges << " (" << bananas
         << " bananas and " << oranges << " oranges)." << endl;
}

bool doorN(bool alignment,          //
           int& bananas,            //
           int& oranges,            //
           string monsterName)      //
{
    if (alignment == 0)
    {
        monsterRoom(bananas, oranges, monsterName);
        return 1;
    }
    else
    {
        exitRoom(bananas, oranges);
        return 0;
    }
}

bool doorE(bool alignment,          //
           int& bananas,            //
           int& oranges,            //
           string monsterName)      //
{
    if (alignment == 0)
    {
        genieRoom(bananas, oranges);
        return 1;
    }
    else
    {
        monsterRoom(bananas, oranges, monsterName);
        return 1;
    }
}

bool doorS(bool alignment,          //
           int& bananas,            //
           int& oranges)            //
{
    if (alignment == 0)
    {
        pictureRoom();
        return 1;
    }
    else
    {
        genieRoom(bananas, oranges);
        return 1;
    }
}

bool doorW(bool alignment,          //
           int& bananas,            //
           int& oranges)            //
{
    if (alignment == 0)
    {
        exitRoom(bananas, oranges);
        return 0;
    }
    else
    {
        pictureRoom();
        return 1;
    }
}

void outputUpdate (string playerName,
                   int bananas,
                   int oranges)
{
    cout << playerName << ", you are in a room with 4 doors." << endl;
    cout << "You are carrying " << bananas << " bananas and " << oranges
         << " oranges." << endl;
    cout << endl;
}

void pickDoor (char& door)
{
    do
    {
    cout << "Pick a door to enter by typing the direction it is in (N/E/S/W): ";
    cin >> door;
    cout << endl;

    }
    while (door != 'N' && door != 'S' && door != 'E' && door != 'W');
}

void matchDoor (char& door,
                bool alignment,
                int& bananas,
                int& oranges,
                string monsterName,
                bool& go)
{
    if (door == 'N')
    {
        go = doorN(alignment, bananas, oranges, monsterName);
    }
    else if (door == 'E')
    {
        go = doorE(alignment, bananas, oranges, monsterName);
    }
    else if (door == 'S')
    {
        go = doorS(alignment, bananas, oranges);
    }
    else if (door == 'W')
    {
        go = doorW(alignment, bananas, oranges);
    }
}



