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
 *   playerName : player's name input by user
 *   monsterName: monster's name input by user
 *   door       : door player enters input by user
 *
 * OUTPUT:
 *   bananas    : number of bananas player has
 *   oranges    : number of oranges player has
 *   playerName : player's name input by user
 *   monsterName: monster's name input by user
 *
 ******************************************************************************/
/*******************************************************************************
 * getNames
 *   This function receives two string variables passed by reference (playerName
 *   and monsterName). The function first prompts the user to enter their name
 *   and sets the input to playerName. Then it prompts the user to enter the
 *   name of their scariest monster and sets the input to monsterName - returns
 *   nothing → This will output two prompts, first for the user to enter their
 *   name and then for the user to enter the name of their scariest monster.
 ******************************************************************************/
void getNames(string& playerName,       // IN - player's name input by user
              string& monsterName);     // IN - monster's name input by user

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
 * exitRoom
 *   This function receives two integers, bananas and oranges. It outputs a
 *   message notifying the player they have found the exit and then outputs the
 *   player's combined and individual scores - returns nothing → This will
 *   output a message notifying the player they have found the exit and then
 *   outputs the player's combined and individual scores.
 ******************************************************************************/
void exitRoom(int bananas,              // IN - number of bananas the player has
              int oranges);             // IN - number of oranges the player has

/*******************************************************************************
 * doorN
 *   This function recieves a boolean (alignment), two integers passed by
 *   reference (bananas and oranges), and a string (monsterName). If alignment
 *   is equal to 0, the function will call monsterRoom and return 1. Otherwise,
 *   the function will call exitRoom and return 0 - returns a boolean.
 ******************************************************************************/
bool doorN(bool alignment,              // IN - two possible alignments of four
                                        //      doors decided randomly at
                                        //      beginning of each turn
           int& bananas,                // IN - number of bananas the player has
           int& oranges,                // IN - number of oranges the player has
           string monsterName);         // IN - monster's name input by user

/*******************************************************************************
 * doorE
 *   This function recieves a boolean (alignment), two integers passed by
 *   reference (bananas and oranges), and a string (monsterName). If alignment
 *   is equal to 0, the function will call genieRoom and return 1. Otherwise,
 *   the function will call monsterRoom and return 1 - returns a boolean.
 ******************************************************************************/
bool doorE(bool alignment,              // IN - two possible alignments of four
                                        //      doors decided randomly at
                                        //      beginning of each turn
           int& bananas,                // IN - number of bananas the player has
           int& oranges,                // IN - number of oranges the player has
           string monsterName);         // IN - monster's name input by user

/*******************************************************************************
 * doorS
 *   This function recieves a boolean (alignment) and two integers passed by
 *   reference (bananas and oranges). If alignment is equal to 0, the function
 *   will call pictureRoom and return 1. Otherwise, the function will call
 *   genieRoom and return 1 - returns a boolean.
 ******************************************************************************/
bool doorS(bool alignment,              // IN - two possible alignments of four
                                        //      doors decided randomly at
                                        //      beginning of each turn
           int& bananas,                // IN - number of bananas the player has
           int& oranges);               // IN - number of oranges the player has

/*******************************************************************************
 * doorW
 *   This function recieves a boolean (alignment) and two integers passed by
 *   reference (bananas and oranges). If alignment is equal to 0, the function
 *   will call exitRoom and return 0. Otherwise, the function will call
 *   pictureRoom and return 1 - returns a boolean.
 ******************************************************************************/
bool doorW(bool alignment,              // IN - two possible alignments of four
                                        //      doors decided randomly at
                                        //      beginning of each turn
           int& bananas,                // IN - number of bananas the player has
           int& oranges);               // IN - number of oranges the player has

/*******************************************************************************
 * outputUpdate
 *   This function receives a string (playerName) and two integers (bananas and
 *   oranges). It outputs an update with the player name, location, and the
 *   number of bananas and oranges they have - returns nothing → This will
 *   output an update with the player name, location, and the number of bananas
 *   and oranges they have.
 *
 ******************************************************************************/
void outputUpdate (string playerName,   // IN - player's name input by user
                   int bananas,         // IN - number of bananas the player has
                   int oranges);        // IN - number of oranges the player has

/*******************************************************************************
 * pickDoor
 *   This function receives a character (door) passed by reference. It uses an
 *   input validation loop to output a prompt for the user to choose a door, and
 *   it will validate the input - returns nothing → This will output a prompt
 *   for the user to choose a door.
 *
 ******************************************************************************/
void pickDoor (char& door);             // IN - door player enters input by user

/*******************************************************************************
 * matchDoor
 *   This function receives a character variable (door), a boolean variable
 *   (alignment), two integer variables passed by reference (bananas and
 *   oranges, respectively), a string variable (monsterName) and a boolean
 *   variable passedd by reference (go). This function matches the door variable
 *   with the correct door function and calls that function - returns nothing.
 *
 ******************************************************************************/
void matchDoor (char& door,             // IN - door player enters input by user
                bool alignment,         // IN - two possible alignments of four
                                        //      doors decided randomly at
                                        //      beginning of each turn
                int& bananas,           // IN - number of bananas the player has
                int& oranges,           // IN - number of oranges the player has
                string monsterName,     // IN - monster's name input by user
                bool& go);              // IN - value set at the end of every
                                        //      round to determine when to stop
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
    // Player begins with 5 bananas and 3 oranges
    bananas = 5;
    oranges = 3;

    // INPUT - user prompted to input name and monster's name
    // getNames - Will prompt the user input name and monster's name and will
    //            set input to playerName and monsterName, respectively.
    getNames(playerName, monsterName);

    // PROC - output update, setting alignment, prompting user to pick door and
    //     matching door to room based on alignment. Process repeated until go
    //     is set to 0 when user exits.
    do
    {
        // outputUpdate - Will output an update with the player's name,
        //                location, and the number of bananas and oranges they
        //                have
        outputUpdate(playerName, bananas, oranges);

        // Randomly setting alignment
        alignment = rand() % 2;

        // pickDoor - Will prompt for the user to choose a door, and it will
        //            validate the input
        pickDoor(door);

        // matchDoor - Will call the matching function of the door chosen
        matchDoor(door, alignment, bananas, oranges, monsterName, go);

    } while (go == 1);

    return 0;
}
/*******************************************************************************
 *
 * FUNCTION getNames
 *______________________________________________________________________________
 * This function receives two string variables passed by reference (playerName
 *   and monsterName). The function first prompts the user to enter their name
 *   and sets the input to playerName. Then it prompts the user to enter the
 *   name of their scariest monster and sets the input to monsterName - returns
 *   nothing.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *   There are no pre-conditions for this function.
 *
 * POST-CONDITIONS
 *     This function will output prompts for the player's and monster's names.
 *      playerName : player's name input by user
 *      monsterName: monster's name input by user
 ******************************************************************************/
void getNames(string& playerName,       // IN - player's name input by user
              string& monsterName)      // IN - monster's name input by user
{
    // INPUT - User prompted to input name and monster's name
    cout << "Please enter your name: ";
    cin >> playerName;
    cout << endl;

    cout << "Name your scariest monster: ";
    cin >> monsterName;
    cout << endl;
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
void exitRoom(int bananas,              // IN - number of bananas the player has
              int oranges)              // IN - number of oranges the player has
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
 * FUNCTION doorN
 *______________________________________________________________________________
 * This function recieves a boolean (alignment), two integers passed by
 *   reference (bananas and oranges), and a string (monsterName). If alignment
 *   is equal to 0, the function will call monsterRoom and return 1. Otherwise,
 *   the function will call exitRoom and return 0 - returns a boolean.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     alignment  : two possible alignments of four doors decided randomly at
 *                  beginning of each turn
 *     bananas    : number of bananas the player has
 *     oranges    : number of oranges the player has
 *     monsterName: monster's name input by user
 *
 * POST-CONDITIONS
 *     This function will return a boolean.
 *      bananas: number of bananas the player has
 *      oranges: number of oranges the player has
 ******************************************************************************/
bool doorN(bool alignment,              // IN - two possible alignments of four
                                        //      doors decided randomly at
                                        //      beginning of each turn
           int& bananas,                // IN - number of bananas the player has
           int& oranges,                // IN - number of oranges the player has
           string monsterName)          // IN - monster's name input by user
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
 * FUNCTION doorE
 *______________________________________________________________________________
 * This function recieves a boolean (alignment), two integers passed by
 *   reference (bananas and oranges), and a string (monsterName). If alignment
 *   is equal to 0, the function will call genieRoom and return 1. Otherwise,
 *   the function will call monsterRoom and return 1 - returns a boolean.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     alignment  : two possible alignments of four doors decided randomly at
 *                  beginning of each turn
 *     bananas    : number of bananas the player has
 *     oranges    : number of oranges the player has
 *     monsterName: monster's name input by user
 * POST-CONDITIONS
 *     This function will return a boolean.
 *      bananas: number of bananas the player has
 *      oranges: number of oranges the player has
 ******************************************************************************/
bool doorE(bool alignment,              // IN - two possible alignments of four
                                        //      doors decided randomly at
                                        //      beginning of each turn
           int& bananas,                // IN - number of bananas the player has
           int& oranges,                // IN - number of oranges the player has
           string monsterName)          // IN - monster's name input by user
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
 * FUNCTION doorS
 *______________________________________________________________________________
 * This function recieves a boolean (alignment) and two integers passed by
 *   reference (bananas and oranges). If alignment is equal to 0, the function
 *   will call pictureRoom and return 1. Otherwise, the function will call
 *   genieRoom and return 1 - returns a boolean.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     alignment  : two possible alignments of four doors decided randomly at
 *                  beginning of each turn
 *     bananas    : number of bananas the player has
 *     oranges    : number of oranges the player has
 * POST-CONDITIONS
 *     This function will return a boolean.
 *      bananas: number of bananas the player has
 *      oranges: number of oranges the player has
 ******************************************************************************/
bool doorS(bool alignment,              // IN - two possible alignments of four
                                        //      doors decided randomly at
                                        //      beginning of each turn
           int& bananas,                // IN - number of bananas the player has
           int& oranges)                // IN - number of oranges the player has
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
 * FUNCTION doorW
 *______________________________________________________________________________
 * This function recieves a boolean (alignment) and two integers passed by
 *   reference (bananas and oranges). If alignment is equal to 0, the function
 *   will call exitRoom and return 0. Otherwise, the function will call
 *   pictureRoom and return 1 - returns a boolean.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     alignment: two possible alignments of four doors decided randomly at
 *                  beginning of each turn
 *     bananas  : number of bananas the player has
 *     oranges  : number of oranges the player has
 * POST-CONDITIONS
 *     This function will return a boolean.
 *      bananas: number of bananas the player has
 *      oranges: number of oranges the player has
 ******************************************************************************/
bool doorW(bool alignment,              // IN - two possible alignments of four
                                        //      doors decided randomly at
                                        //      beginning of each turn
           int& bananas,                // IN - number of bananas the player has
           int& oranges)                // IN - number of oranges the player has
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
 * FUNCTION outputUpdate
 *______________________________________________________________________________
 * This function receives a string (playerName) and two integers (bananas and
 *   oranges). It outputs an update with the player name, location, and the
 *   number of bananas and oranges they have - returns nothing.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     playerName: player's name input by user
 *     bananas   : number of bananas the player has
 *     oranges   : number of oranges the player has
 *
 * POST-CONDITIONS
 *     This function will output an update with the player name, location, and
 *       the number of bananas and oranges they have.
 ******************************************************************************/
void outputUpdate (string playerName,   // IN - player's name input by user
                   int bananas,         // IN - number of bananas the player has
                   int oranges)         // IN - number of oranges the player has
{
    // OUTPUT - This function will output a message notifying the player of
    //          their current status (location, number of bananas and oranges)
    cout << playerName << ", you are in a room with 4 doors." << endl;
    cout << "You are carrying " << bananas << " bananas and " << oranges
         << " oranges." << endl;
    cout << endl;
}

/*******************************************************************************
 *
 * FUNCTION pickDoor
 *______________________________________________________________________________
 * This function receives a character (door) passed by reference. It uses an
 *   input validation loop to output a prompt for the user to choose a door,
 *   and it will validate the input - returns nothing.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *   The following needs a previously defined value passed by reference:
 *     door: door player enters input by user
 *
 * POST-CONDITIONS
 *    This function will output a prompt for the user to choose a door.
 *      door: door player enters input by user
 ******************************************************************************/
void pickDoor (char& door)              // IN - door player enters input by user
{
    // PROC - Prompt the user to pick a door and re-prompt if input is invalid
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
 * This function receives a character variable (door), a boolean variable
 *   (alignment), two integer variables passed by reference (bananas and
 *   oranges, respectively), a string variable (monsterName) and a boolean
 *   variable passedd by reference (go). This function matches the door variable
 *   with the correct door function and calls that function - returns nothing.
 *______________________________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *    door       : door player enters input by user
 *    alignment  : two possible alignments of four doors decided randomly at the
 *                 beginning of each turn
 *    bananas    : number of bananas the player has
 *    oranges    : number of oranges the player has
 *    monsterName: monster's name input by user
 *    go         : value set at the end of every round to determind when to stop
 *                 the game
 *
 *
 * POST-CONDITIONS
 *    This function will call another function.
 *      door   : door player enters input by user
 *      bananas: number of bananas the player has
 *      oranges: number of oranges the player has
 *      go     : value set at the end of every round to determind when to stop
 *               the game
 ******************************************************************************/
void matchDoor (char& door,             // IN - door player enters input by user
                bool alignment,         // IN - two possible alignments of four
                                        //      doors decided randomly at
                                        //      beginning of each turn
                int& bananas,           // IN - number of bananas the player has
                int& oranges,           // IN - number of oranges the player has
                string monsterName,     // IN - monster's name input by user
                bool& go)               // IN - value set at the end of every
                                        //      round to determine when to stop
{
    if (door == 'N')
    {
        // doorN - Will call monsterRoom and return 1 if alignment is equal to
        //         0. Otherwise, the function will call exitRoom and return 0.
        go = doorN(alignment, bananas, oranges, monsterName);
    }
    else if (door == 'E')
    {
        // doorE - Will call genieRoom and return 1 if alignment is equal to 0.
        //         Otherwise, the function will call monsterRoom and return 1.
        go = doorE(alignment, bananas, oranges, monsterName);
    }
    else if (door == 'S')
    {
        // doorS - Will call pictureRoom and return 1 if alignment is equal to
        //         0. Otherwise, the function will call genieRoom and return 1.
        go = doorS(alignment, bananas, oranges);
    }
    else if (door == 'W')
    {
        // doorW - Will call exitRoom and return 0 if alignment is equal to 0.
        //         Otherwise, the function will call pictureRoom and return 1.
        go = doorW(alignment, bananas, oranges);
    }
}
