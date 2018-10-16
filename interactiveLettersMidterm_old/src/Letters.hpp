#pragma once

#include "ofMain.h"
#include "ofxCenteredTrueTypeFont.h"
#include "Particle.hpp"

class Letters{
public:

    void setup();
    void update();
    void draw(string _str);
    
    
ofxCenteredTrueTypeFont letterFont;
    
    string str = "";
    glm::vec2 pos;
    float mass;
    const float G = 0.1;
    
};
