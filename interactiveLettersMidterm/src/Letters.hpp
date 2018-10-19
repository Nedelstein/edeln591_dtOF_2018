#pragma once

#include "ofMain.h"
#include "ofxCenteredTrueTypeFont.h"
#include "Particle.hpp"

class Letters{
public:

    void setup();
    void update();
    void draw(string _str);
    void collide();
    
    
ofTrueTypeFont letterFont;
    
    string str = "";
    glm::vec2 pos;
    float mass;
    typedef ofPath ofTTFCharacter;
    
   ofPath letterN;
    float nStartX = ofGetWidth()/2 - 100;
    float nStartY = ofGetHeight() *0.75;
    bool nDraw;
   vector<Particle> particles;
    ofPolyline nLine;
};
