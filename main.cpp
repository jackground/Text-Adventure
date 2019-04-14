/*******************************************************************************
 *  AUTHOR       : John Hawley
 *  Assignment #7: Text Adventure
 *  CLASS        : CS 002
 *  SECTION      : MW: 10:45a - 12:50p, TR: 10:45a - 12:10p
 *  Due Date     : 4/21/19
 ******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
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
/*******************************************************************************
 * monsterRoom
 *   This function receives two integer variables (bananas and oranges, by
 *   reference and a string variable, monsterName by value. It reduces the
 *   values of the variables storing the number of bananas and oranges to 0.
 *   This function will output a warning and what monster attacked the player
 *   - returns nothing → This will output a warning and what monster attacked
 *   the player.
 ******************************************************************************/
void monsterRoom(int& bananas,          // IN - number of bananas the player has
                 int& oranges,          // IN - number of oranges the player has
                 string monsterName);   // IN - monster's name input by user

/*******************************************************************************
 * genieRoom
 *   This function receives two integers by reference, bananas and oranges, and
 *   increases their values by 2 and 1, respectively. Then the function ouputs a
 *   message telling the player what happened - returns nothing → This will
 *   output a message telling the player what happened.
 ******************************************************************************/
void genieRoom(int& bananas,            // IN - number of bananas the player has
               int& oranges);           // IN - number of oranges the player has
/*******************************************************************************
 * drawPicture
 *   This function receives nothing and will output text resembling R2D2 -
 *   returns nothing → This will output text resembling R2D2.
 ******************************************************************************/
void drawPicture();

/*******************************************************************************
 * pictureRoom
 *   This function recieves nothing. It will output a message notifying the user
 *   they have found a picture and then output the "picture" to the screen -
 *   returns nothing → This will output a message notifying the user they have
 *   found a picture and then output the "picture" to the screen.
 ******************************************************************************/
void pictureRoom();

/*******************************************************************************
 *
 ******************************************************************************/
void exitRoom(int bananas,              // IN - number of bananas the player has
              int oranges);             // IN - number of oranges the player has

/*******************************************************************************
 * doorN
 *
 ******************************************************************************/
bool doorN(bool alignment,              //
           int& bananas,                //
           int& oranges,                //
           string monsterName);         //

/*******************************************************************************
 * doorE
 *
 ******************************************************************************/
bool doorE(bool alignment,              //
           int& bananas,                //
           int& oranges,                //
           string monsterName);         //

/*******************************************************************************
 * doorS
 *
 ******************************************************************************/
bool doorS(bool alignment,              //
           int& bananas,                //
           int& oranges);               //

/*******************************************************************************
 * doorW
 *
 ******************************************************************************/
bool doorW(bool alignment,              //
           int& bananas,                //
           int& oranges);               //

/*******************************************************************************
 * outputUpdate
 *
 ******************************************************************************/
void outputUpdate (string playerName,
                   int bananas,
                   int oranges);

/*******************************************************************************
 * pickDoor
 *
 ******************************************************************************/
void pickDoor (char& door);

/*******************************************************************************
 * matchDoor
 *
 ******************************************************************************/
void matchDoor (char& door,
                bool alignment,
                int& bananas,
                int& oranges,
                string monsterName,
                bool& go);


int main()
{
    // Seed random with 500 for consistent testing results
    srand(500);

    // Seed random with time for closer to random values
    // srand(static_cast<unsigned int>(time(nullptr)));

    // Variables
    int bananas;            // CALC & OUT - number of bananas player has
    int oranges;            // CALC & OUT - number of oranges player has
    string playerName;      // INPUT & OUT - player's name input by user
    string monsterName;     // INPUT & OUT - monster's name input by user
    bool alignment;         // CALC - two possible alignments of four doors
                            //     decided randomly at beginning of each turn
    char door;              // INPUT & CALC - door player enters input by user
    bool go;                // CALC - value set at the end of every round to
                            //     determine when to stop the game

    // Variable Initialization
    bananas = 5;
    oranges = 3;
    go = 1;

    // INPUT - user prompted to input name then name of scariest monster
    cout << "Please enter your name: ";
    cin >> playerName;
    cout << endl;

    cout << "Name your scariest monster: ";
    cin >> monsterName;
    cout << endl;

    // PROC - output update, setting alignment, prompting user to pick door and
    //     matching door to room based on alignment. Process repeated until go
    //     is set to 0 when user exits.
    do
    {
        outputUpdate(playerName, bananas, oranges);
        alignment = rand() % 2;
        cout << alignment << endl;
        pickDoor(door);
        matchDoor(door, alignment, bananas, oranges, monsterName, go);

    } while (go != 0);

    return 0;
}
/*******************************************************************************
 *
 * FUNCTION monsterRoom
 *______________________________________________________________________________
 * This function receives two integer variables, bananas and oranges, by
 *   reference and a string variable, monsterName by value. It reduces the
 *   values of the variables storing the number of bananas and oranges to 0.
 *   This function will output a warning and what monster attacked the player
 *   - returns nothing.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     bananas    : number of bananas the player has
 *     oranges    : number of oranges the player has
 *     monsterName: monster's name input by user
 *
 * POST-CONDITIONS
 *     This function will output a warning and what monster attacked the player.
 *      bananas    : number of bananas the player has
 *      oranges    : number of oranges the player has
 ******************************************************************************/
void monsterRoom(int& bananas,          // IN - number of bananas the player has
                 int& oranges,          // IN - number of oranges the player has
                 string monsterName)    // IN - monster's name input by user
{
    // PROC - reduces the values of bananas and oranges to 0
    bananas = 0;
    oranges = 0;

    // OUTPUT - output warning and tell player what monster attaked the player
    cout << "WATCH OUT!!" << endl;
    cout << monsterName << " attacks you and steals all of your bananas and"
         << " oranges." << endl;
    cout << endl;
}

/*******************************************************************************
 *
 * FUNCTION genieRoom
 *______________________________________________________________________________
 * This function receives two integers by reference, bananas and oranges, and
 *   increases their values by 2 and 1, respectively. Then the function ouputs a
 *   message telling the player what happened - returns nothing
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values passed by reference:
 *     bananas: number of bananas the player has
 *     oranges: number of oranges the player has
 *
 * POST-CONDITIONS
 *     This function will output a message telling the player what happened.
 *      bananas: number of bananas the player has
 *      oranges: number of oranges the player has
 ******************************************************************************/
void genieRoom(int& bananas,            // IN - number of bananas the player has
               int& oranges)            // IN - number of oranges the player has
{
    // PROC - increments bananas and oranges by 2 and 1, respectively
    bananas += 2;
    oranges += 1;

    // OUTPUT - output what happened
    cout << "!!POOF!!" << endl;
    cout << "A genie pops out and grants you 2 bananas and 1 orange." << endl;
    cout << endl;
}

/*******************************************************************************
 *
 * FUNCTION drawPicture
 *______________________________________________________________________________
 * This function receives nothing and outputs text resembling R2D2 - returns
 *   nothing.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *   There are no pre-conditions.
 *
 * POST-CONDITIONS
 *     This function will output text resembling R2D2.
 ******************************************************************************/
void drawPicture()
{
    // OUTPUT - output text resembling R2D2, line by line
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

/*******************************************************************************
 *
 * FUNCTION pictureRoom
 *______________________________________________________________________________
 * This function recieves nothing. It will output a message notifying the user
 *   they have found a picture and then output the "picture" to the screen -
 *   returns nothing.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *   There are no pre-conditions.
 *
 * POST-CONDITIONS
 *     This function will output a message notifying the user they have found a
 *       picture and output the "picture" to the screen.
 ******************************************************************************/
void pictureRoom()
{
    // OUTPUT - output message notifying user they have found picture
    cout << "You found a picture!" << endl;
    cout << endl;

    // drawPicture - Will output text resembling R2D2
    drawPicture();
}

/*******************************************************************************
 *
 * FUNCTION exitRoom
 *______________________________________________________________________________
 * This function receives two integers, bananas and oranges. It outputs a
 *   message notifying the player they have found the exit and then outputs the
 *   player's combined and individual scores - returns nothing.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     bananas: number of bananas the player has
 *     oranges: number of oranges the player has
 *
 * POST-CONDITIONS
 *     This function will output a message notifying the player they have found
 *       the exit and then outputs the player's combined and individual scores.
 ******************************************************************************/
void exitRoom(int bananas,          // IN - number of bananas the player has
              int oranges)          // IN - number of oranges the player has
{
    // OUTPUT - This function will output a message notifying the player they
    //          have found the exit and then outputs the player's combined and
    //          individual scores
    cout << "You found the exit!" << endl;
    cout << "Your score is " << bananas + oranges << " (" << bananas
         << " bananas and " << oranges << " oranges)." << endl;
}

/*******************************************************************************
 *
 * FUNCTION matchDoor
 *______________________________________________________________________________
 * This function
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/
bool doorN(bool alignment,          // IN - two possible alignments of four
                                    //      doors decided randomly at beginning
                                    //      of each turn
           int& bananas,            // IN - number of bananas the player has
           int& oranges,            // IN - number of oranges the player has
           string monsterName)      // IN - monster's name input by user
{
    if (alignment == 0)
    {
        // monsterRoom - Will set bananas and oranges to 0 and output what
        //               monster attacked the user
        monsterRoom(bananas, oranges, monsterName);
        return 1;
    }
    else
    {
        // exitRoom - Will output a message notifying the player they have found
        //            the exit and then outputs the player's combined and
        //            individual scores
        exitRoom(bananas, oranges);
        return 0;
    }
}

/*******************************************************************************
 *
 * FUNCTION matchDoor
 *______________________________________________________________________________
 * This function
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/
bool doorE(bool alignment,          // IN - two possible alignments of four
                                    //      doors decided randomly at beginning
                                    //      of each turn
           int& bananas,            // IN - number of bananas the player has
           int& oranges,            // IN - number of oranges the player has
           string monsterName)      // IN - monster's name input by user
{
    if (alignment == 0)
    {
        // genieRoom - Will increment bananas and oranges by 2 and 1,
        //             respectively and output message describing what happened
        genieRoom(bananas, oranges);
        return 1;
    }
    else
    {
        // monsterRoom - Will set bananas and oranges to 0 and output what
        //               monster attacked the user
        monsterRoom(bananas, oranges, monsterName);
        return 1;
    }
}

/*******************************************************************************
 *
 * FUNCTION matchDoor
 *______________________________________________________________________________
 * This function
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/
bool doorS(bool alignment,          // IN - two possible alignments of four
                                    //      doors decided randomly at beginning
                                    //      of each turn
           int& bananas,            // IN - number of bananas the player has
           int& oranges)            // IN - number of oranges the player has
{
    if (alignment == 0)
    {
        // pictureRoom - Will output a message notifying the user they have
        //               found a picture and output the "picture" to the screen.
        pictureRoom();
        return 1;
    }
    else
    {
        // genieRoom - Will increment bananas and oranges by 2 and 1,
        //             respectively and output message describing what happened
        genieRoom(bananas, oranges);
        return 1;
    }
}

/*******************************************************************************
 *
 * FUNCTION matchDoor
 *______________________________________________________________________________
 * This function
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/
bool doorW(bool alignment,          // IN - two possible alignments of four
                                    //      doors decided randomly at beginning
                                    //      of each turn
           int& bananas,            // IN - number of bananas the player has
           int& oranges)            // IN - number of oranges the player has
{
    if (alignment == 0)
    {
        // exitRoom - Will output a message notifying the player they have found
        //            the exit and then outputs the player's combined and
        //            individual scores
        exitRoom(bananas, oranges);
        return 0;
    }
    else
    {
        // pictureRoom - Will output a message notifying the user they have
        //               found a picture and output the "picture" to the screen.
        pictureRoom();
        return 1;
    }
}

/*******************************************************************************
 *
 * FUNCTION matchDoor
 *______________________________________________________________________________
 * This function
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/
void outputUpdate (string playerName,   // IN - player's name input by user
                   int bananas,         // IN - number of bananas the player has
                   int oranges)         // IN - number of oranges the player has
{
    cout << playerName << ", you are in a room with 4 doors." << endl;
    cout << "You are carrying " << bananas << " bananas and " << oranges
         << " oranges." << endl;
    cout << endl;
}

/*******************************************************************************
 *
 * FUNCTION matchDoor
 *______________________________________________________________________________
 * This function
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/
void pickDoor (char& door)  // IN - door player enters input by user
{
    do
    {
    cout << "Pick a door to enter by typing the direction it is in (N/E/S/W): ";
    cin >> door;
    cout << endl;

    }
    while (door != 'N' && door != 'S' && door != 'E' && door != 'W');
}

/*******************************************************************************
 *
 * FUNCTION matchDoor
 *______________________________________________________________________________
 * This function
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *
 * POST-CONDITIONS
 *
 ******************************************************************************/
void matchDoor (char& door,         // IN - door player enters input by user
                bool alignment,     // IN - two possible alignments of four
                                    //      doors decided randomly at beginning
                                    //      of each turn
                int& bananas,       // IN - number of bananas the player has
                int& oranges,       // IN - number of oranges the player has
                string monsterName, // IN - monster's name input by user
                bool& go)           // IN - value set at the end of every round
                                    //      to determine when to stop the game
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



