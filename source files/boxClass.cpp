//
// Created by USER on 3/8/2018.
//

#include "../header files/boxClass.h"

#include <iostream>
#include <string>

using namespace std;


//int boxClass::empty = 10;
//int boxClass::mine = 11;

boxClass::boxClass() {
    value = 0;
    hidden = true;

}

boxClass::~boxClass() {

}


void boxClass::set_value(int c, bool h) {
    value = c;
    hidden = h;
}



void boxClass::displayvalueandstate() {
    cout << value << endl;
    cout << hidden << endl;

}
int boxClass::get_value(){
    return value;

}

bool boxClass::get_state() {
    return hidden;
}


void boxClass::displaybox() {
    if (hidden){
        cout << "[ ]";
    }
    else if(!hidden && value == 0){
        cout << "[-]";
    }
    else if(!hidden && value == 11){
        cout << "[x]";
    }
    else if(!hidden && value == 99){
        cout << "[O]";
    }

    else if(!hidden && value == 1){
        cout << "[1]";
    }
    else if(!hidden && value == 2){
        cout << "[2]";
    }
    else if(!hidden && value == 3){
        cout << "[3]";
    }
    else if(!hidden && value == 4){
        cout << "[4]";
    }
    else if(!hidden && value == 5){
        cout << "[5]";
    }
    else if(!hidden && value == 6){
        cout << "[6]";
    }
    else if(!hidden && value == 7){
        cout << "[7]";
    }
    else if(!hidden && value == 8){
        cout << "[8]";
    }
    else{
        cout << "[?]";
    }
}


