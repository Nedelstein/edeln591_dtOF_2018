#pragma once
#include "ofMain.h"

class Firework{
public:
    Firework();
    Firework(glm::vec2 _pos);
    void setup(glm::vec2 _vel);
    void update();
    void draw();
    
    glm::vec2 pos, vel, acc;
    ofPoint frc;

    
    
    
};
