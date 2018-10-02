#pragma once

#include "ofMain.h"

class Circle{
    
public:
    void setup(float pX, float pY, float size, float _rotationZ, float interp);
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void twirl();
    
    float radius;
    float rotateee;
    glm::vec2 pos, vel, frc, acc;
    float lerp;
    
    
    
    
};
