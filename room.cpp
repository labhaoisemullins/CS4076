/*
 * CS4076 EDP Project
 * Student ID: 20266928
 * Filename: room.cpp
*/

#include <algorithm>

#include "room.h"        // include room header file
#include "command.h"     // include command header file

Room::Room(string description){
    this->description = description;
}

/* set the room exists (up, right, down, left) */
void Room::setExits(Room *up, Room *right, Room *down, Room *left) {    // pointers
    if(up != NULL)    exits["up"] = up;
    if(right != NULL) exits["right"] = right;
    if(down != NULL)  exits["down"] = down;
    if(left != NULL)  exits["left"] = left;
}

/* return the short description */
string Room::shortDescription(){
    return description;
}

/* return the long description */
string Room::longDescription(){
    return "\ncurrent room: " + description + exitString();
}

/* displays the exits */
string Room::exitString(){
    string returnString = "\nexits: ";
    for(map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
    // Loops through the map
        returnString += "  " + i->first;
    return returnString;
}

/* move to the next room if there is an exit */
Room* Room::nextRoom(string direction) {
    map<string, Room*>::iterator next = exits.find(direction);
    if(next == exits.end())
        return nullptr;
    return next->second;
}

/* add the item */
void Room::addItem(Item *inItem) {
    itemsInRoom.push_back(*inItem);
}

/* display the item(s) in the room */
string Room::displayItems(){
    string roomItem = "items in this room: ";
    int quantity = itemsInRoom.size();

    if(quantity < 1){
        roomItem = "there are no items in this room.";
    }else if(quantity > 0){
        int i = 0;

     for(int n = quantity; n > 0; n--){
         roomItem += itemsInRoom[i].getShortDescription() + " ";
         i++;
     }
    }
    return roomItem;
}

/* number of items in the room */
int Room::numberOfItems(){
    return itemsInRoom.size();
}

/* find the item in the room */
Item Room::findItem(Item item){
    for(unsigned int i = 0; i < itemsInRoom.size(); i++)
        if(itemsInRoom[i] == item)
            return itemsInRoom[i];
};

/* remove the item */
void Room::removeItem(Item item){
    int position = 0;

    for(unsigned int i = 0; i < (unsigned int)itemsInRoom.size(); i++){
        if(itemsInRoom[i] == item){  // Binary Operator Overloading
            position = (int)i;
            break;
        }
    }
    itemsInRoom.erase(itemsInRoom.begin() + position);
}

/* view the items that are in the room */
vector<Item> Room::viewItems(){
    return itemsInRoom;
}

/* show the items that were gathered */
bool Room::allItemsGathered(){
    if(itemsInRoom.empty()){
        return true;
    }else{
        return false;
    }
}

/* room that contains an exit */
bool Room::containsExit(string exit){
    return exits.find(exit) != exits.end();
}
