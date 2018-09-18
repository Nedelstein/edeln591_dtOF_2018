
#pragma once
#include "ofMain.h"


class Circle {
public:
    void setup(float posX, float posY, float width, float height);
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    
    float w, h;
    float time;
    float gravity;
    
    glm::vec2 pos;
    glm::vec2 vel;
    glm::vec2 acc;
    glm::vec2 wind;
    
    ofColor color;
};
