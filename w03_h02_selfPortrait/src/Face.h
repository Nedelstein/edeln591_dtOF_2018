#pragma once
#include "ofMain.h"

class Face {

public:
void setup();
void update();
void draw();
    void mousePressed(int x, int y, int button);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);



    ofImage leftEye;
    ofImage rightEye;
    ofImage mouth;
    ofImage nose;
    
    float mouthX;
    float mouthY;
    float leftEyeX;
    float leftEyeY;
    float rightEyeX;
    float rightEyeY;
    float noseX;
    float noseY;
    
    float noseSpeed;
    float mouthSpeed;
    float leftEyeSpeed;
    float rightEyeSpeed;
        
};

