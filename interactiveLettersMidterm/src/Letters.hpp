#pragma once

#include "ofMain.h"
#include "Particle.hpp"

class Letters{
public:

    void setup(char c, glm::vec2 _pos);
    void update(glm::vec2 particlePos);
    void draw();
    void Ncollide();
    void Ocollide();
    glm::vec2 getForce(glm::vec2 pos);
    
    vector<glm::vec2> attractors;
    
    
ofTrueTypeFont letterFont;
    
    glm::vec2 pos;
    float mass;
    typedef ofPath ofTTFCharacter;
    
   ofPath letterN;
    float nStartX = ofGetWidth()/2 - 100;
    float nStartY = ofGetHeight() *0.75;
    bool nDraw;
   vector<Particle> particles;
    
    glm::vec2 oPos;
    float oRad;
    bool oDraw;
    
    
};
