//
// Created by USER on 3/8/2018.
//

#ifndef MINESWEEPER_BOXCLASS_H
#define MINESWEEPER_BOXCLASS_H

#include <iostream>
#include <string>

using namespace std;

class boxClass {
public:
    boxClass();
    ~boxClass();

    void set_value(int c, bool h);

    void displayvalueandstate();

    void displaybox();

    int get_value();

    bool get_state();

private:
    int value;
    bool hidden;

//    static bool hidden;
//    static int empty;
//    static int mine;

};


#endif //MINESWEEPER_BOXCLASS_H
