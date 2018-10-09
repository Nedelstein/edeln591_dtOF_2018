#pragma once

#include "ofMain.h"

class Stars{
public:
    
    void setup();
    void update();
    void draw();
    
    glm::vec2 pos;
    float size;
    float fade;
    
    
};
