#pragma once
#include "ofMain.h"

class Circle{
public:
    void setup(float posX, float posY, float width, float height);
    void update();
    void draw();
    void keyPressed(int key);

    float x, y, w, h;
    float dirX, dirY;
    bool hit = false;
    ofColor color;
    
};
