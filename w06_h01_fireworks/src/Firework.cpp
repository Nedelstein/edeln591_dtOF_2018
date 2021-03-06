
#include "Firework.hpp"

Firework::Firework(){
    pos = glm::vec2(0,0);
}

Firework::Firework(glm::vec2 _pos){
    pos = _pos;
 
}

void Firework::setup(glm::vec2 _vel){

    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
    vel = _vel;
    pos = glm::vec2(ofRandom(ofGetWidth()-10), ofGetHeight());
}

void Firework::update(){
    vel = glm::vec2(ofRandom(-2,2), ofRandom(-1,-3));
    pos+=vel;
    vel+=acc;
    acc*=0;
    
}

void Firework::draw(){
    ofPushStyle();
    ofSetColor(255);
    ofDrawEllipse(pos, 3, 6);
    ofPopStyle();
    
    
}
