#include "Letters.hpp"

void Letters::setup() {
    letterFont.loadFont("Courier New.ttf", 700, true,true,true);
    pos.x = ofGetWidth()/4;
    pos.y = ofGetHeight() - ofGetHeight()/5;
}



void Letters::update(){}


void Letters::draw(string _str){
    str = _str;
    letterFont.drawStringAsShapes(str, pos.x, pos.y);
}


