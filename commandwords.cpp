/*
 * CS4076 EDP Project
 * Student ID: 20266928
 * Filename: commandwords.cpp
*/

#include "commandwords.h"   // include commandwords header file

vector<string> CommandWords::validCommands;

/* Initializer List; initialise the command words. */
CommandWords::CommandWords() {
    validCommands.push_back("go");
    validCommands.push_back("quit");
    validCommands.push_back("info");
    validCommands.push_back("map");
    validCommands.push_back("take");
    validCommands.push_back("put");
    validCommands.push_back("teleport");
}

/**
 * Check whether a given String is a valid command word.
 * Return true if it is, false if it isn't.
 **/
bool CommandWords::isCommand(string aString){
    for (unsigned int i = 0; i < validCommands.size(); i++){
        if (validCommands[i].compare(aString) == 0)
            return true;
    }
// if we get here, the string was not found in the commands
    return false;
}

/** Print all valid commands to System.out. */
void CommandWords::showAll(){
// Loops through validCommands and prints each to the screen.
    for(unsigned int i = 0; i < validCommands.size(); i++){
        cout << validCommands[i]<< "  ";
    }
    cout << endl;
}
