#include <iostream>
#include <string>
#include "../header files/boxClass.h"
#include <time.h>
#include <array>


using namespace std;

void place_mines(int h, int w, bool hidden,int numofmines, boxClass** boxes ){
    int randheight;
    int randwidth;
    srand(time(0));

    while (true) {
        if (numofmines >= (h * w)) {
            cout << "please input a number less than (" << h * w << ") a number less than the number of boxes" << endl;
            cin >> numofmines;
        } else {
            break;
        }

    }

    int counter = 0;
    while (numofmines > counter) {

        randheight = rand() % (h);
        randwidth = rand() % (w);
        if (boxes[randheight][randwidth].get_value() == 0) {
            boxes[randheight][randwidth].set_value(11, hidden);
            cout << "placed mined at " << randheight << " " << randwidth << endl;
            counter++;
        }


    }

}

void display_boxes(int h, int w, boxClass **boxes){
    for (int i = 0; i < h; i++) {

        for (int j = 0; j < w; j++) {
            boxes[i][j].displaybox();
        }

        cout << endl;

    }
    cout << endl;
}

//void reveal_boxes(int h, int w,int mine,int empty, bool shown, boxClass** boxes){
//
//    while (true) {
//        int l;
//        int c;
//        cout << "input line";
//        cin >> l;
//        cout << "input column";
//        cin >> c;
//
//        if (boxes[l][c].get_value() == mine) {
//            cout << "YOU LOOSE";
//            break;
//        }
//
//        if (boxes[l][c].get_value() == empty) {  //current cell
//            boxes[l][c].set_value(empty, shown);
//
//
//
//        }
//        if ((0 <= l - 1) && (c + 1 < w) && boxes[l - 1][c + 1].get_value() == empty) { //upright
//            boxes[l - 1][c + 1].set_value(empty, shown);
//
//        }
//        if ((c + 1 < w) && boxes[l][c + 1].get_value() == empty) { //right
//            boxes[l][c + 1].set_value(empty, shown);
//
//
//        }
//        if ((c + 1 < w) && (l + 1 < h)  && boxes[l + 1][c + 1].get_value() == empty ) {  //rightbot
//            boxes[l + 1][c + 1].set_value(empty, shown);
//
//        }
//        if ((l + 1 < h) && boxes[l + 1][c].get_value() == empty) {  //bot
//            boxes[l + 1][c].set_value(empty, shown);
//
//
//        }
//        if ((0 <= c - 1) && (l + 1 < h) && boxes[l + 1][c - 1].get_value() == empty) {  //bot
//            boxes[l + 1][c - 1].set_value(empty, shown);
//
//
//        }
//        if ((0 <= c - 1) && boxes[l][c - 1].get_value() == empty) {  //left
//            boxes[l][c - 1].set_value(empty, shown);
//
//
//        }
//        if ((0 <= c - 1) && (0 <= l - 1) && boxes[l - 1][c - 1].get_value() == empty) {  //upleft
//            boxes[l - 1][c - 1].set_value(empty, shown);
//
//
//        }
//        if ((0 <= l - 1) && boxes[l - 1][c].get_value() == empty) {  //upleft
//            boxes[l - 1][c].set_value(empty, shown);
//
//
//        }
//
//
//
//    }
//}

void propagate(int l, int c, int h, int w, int empty, bool shown, boxClass **boxes){
    if (( l >=0 && c >= 0 && l < h && c < w) && boxes[l][c].get_value() == empty && (boxes[l][c].get_state() == true))
    {
        boxes[l][c].set_value(empty,shown);


        if( ( l >=0 && c >= 0 && l < h && c < w) && (boxes[l][c].get_value() == empty)){

            propagate(l, c - 1, h, w, empty, shown, boxes);
            propagate(l, c + 1, h, w, empty, shown, boxes);
            propagate(l - 1, c - 1, h, w, empty, shown, boxes);
            propagate(l + 1, c - 1, h, w, empty, shown, boxes);
            propagate(l + 1, c + 1, h, w, empty, shown, boxes);
            propagate(l - 1, c + 1, h, w, empty, shown, boxes);
            propagate(l - 1, c, h, w, empty, shown, boxes);
            propagate(l + 1, c, h, w, empty, shown, boxes);

        }
    }
    if (( l >=0 && c >= 0 && l < h && c < w) && (boxes[l][c].get_value() != 0) && (boxes[l][c].get_value() != 11) ){
        boxes[l][c].set_value(boxes[l][c].get_value(),shown);
    }

}
//int one, int two, int three, int four, int five
void numberinboxes(int h, int w, int l, int c, boxClass **boxes){

    bool up = (l-1 >= 0) && (l-1 < h) && (boxes[l-1][c].get_value() == 11);

    bool left = (c-1 >= 0) && (c-1 < w) && (boxes[l][c-1].get_value() == 11);

    bool bot = (l+1 >= 0) && (l+1 < h) && (boxes[l+1][c].get_value() == 11);

    bool right = (c+1 >= 0) && (c+1 < w) && (boxes[l][c+1].get_value() == 11);

    bool upright = (l-1 >= 0) && (l-1 < h) && (c+1 >= 0) && (c+1 < w) && (boxes[l-1][c+1].get_value() == 11);

    bool rightbot = (l+1 >= 0) && (l+1 < h) && (c+1 >= 0) && (c+1 < w) && (boxes[l+1][c+1].get_value() == 11);

    bool upleft = (l-1 >= 0) && (l-1 < h) && (c-1 >= 0) && (c-1 < w) && (boxes[l-1][c-1].get_value() == 11);

    bool leftbot = (l+1 >= 0) && (l+1 < h) && (c-1 >= 0) && (c-1 < w) && (boxes[l+1][c-1].get_value() == 11);

    int total =  up + left + bot + right + upright + rightbot + upleft + leftbot;

     if(boxes[l][c].get_value() != 11){
         boxes[l][c].set_value(total,true);
     }


}

bool check_win(int h, int w,int mines, boxClass** boxes){

    int counter = 0;

    for (int i = 0; i < h; i++) {

        for (int j = 0; j < w; j++) {
            if((boxes[i][j].get_state() == true)){
                counter++;
            };
        }
    }
    if (counter == mines){

        return true;
    }
    else{

        return false;
    }

};

void display_mines(int h, int w, boxClass **boxes){

    for (int i = 0; i < h; i++) {

        for (int j = 0; j < w; j++) {
            if(boxes[i][j].get_value() == 11){
                (boxes[i][j].set_value(11,false));
            }
        }

        cout << endl;

    }
}

bool lose(int l, int c, boxClass** boxes){

    if(boxes[l][c].get_value() == 11){
        return true;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;

    int h;
    int w;
    int empty = 0;
    bool hidden = true;
    bool shown = false;


    cout << "input height: ";
    cin >> h;
    cout << "input width: ";
    cin >> w;

    int numofmines;
    cout << "input number of mines: ";
    cin >> numofmines;

    auto ** boxes = new boxClass* [w];

    for(int i = 0; i < w; ++i)

        boxes[i] = new boxClass [h];
    place_mines(h,w,hidden,numofmines,boxes);

    for (int i = 0; i < h; i++) {

        for (int j = 0; j < w; j++) {
            numberinboxes(h, w, i, j, boxes);
        }
    }
    while(true) {

        display_boxes(h, w, boxes);

        int l;
        int c;
        cout << "input line number: ";
        cin >> l;
        cout << "input column number : ";
        cin >> c;

        while(true){

            if((l > h) || (l <= 0) || (c > w) || (c < 0) ){
                cout << "Please input valid numbers in the range of line: " << h << " and column: " << w << endl;
                cout << "input line number: ";
                cin >> l;
                cout << "input column number : ";
                cin >> c;
            }else if(boxes[l-1][c-1].get_state() == shown){
                cout << "Pleas select another box, this one is already revealed" << endl;
                cout << "input line number: ";
                cin >> l;
                cout << "input column number : ";
                cin >> c;
            }
            else{
                break;
            }

        }
        l = l-1;
        c = c-1;




        if(lose(l,c,boxes)){

            display_mines(h,w,boxes);
            boxes[l][c].set_value(99,shown);
            display_boxes(h, w, boxes);
            cout << "YOU LOOSE";
            break;
        }
        propagate(l, c, h, w, empty, shown, boxes);

        display_boxes(h, w, boxes);

        if(check_win(h,w,numofmines,boxes)){

            display_boxes(h, w, boxes);
            cout << "YOU WIN :)";
            break;
        }
    }


    for(int i=0; i < h; i++) {

        delete [] boxes[i];

    }


    return 0;
}