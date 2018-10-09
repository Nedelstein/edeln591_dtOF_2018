#include "Planets.hpp"

Planets::Planets(){
    pos     = glm::vec2( ofRandom(ofGetWidth()), ofRandom(ofGetHeight()) );
    mass    = ofRandom(1,5);
    
    vel     = glm::vec2(0,0);
    acc     = glm::vec2(0,0);
    radius = ofRandom(20,100);
    mass = ofMap(radius, 10, 50, .5, 5);

}
Planets::Planets(glm::vec2 _pos, float _mass){
    pos = _pos;
    mass = _mass;
    
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
    
}



void Planets::addForce(glm::vec2 force){
    acc +=(force/mass);
    
}

void Planets::applyDampingForce(float strength){
    float length = glm::length(vel);
    if(length !=0){
        glm::vec2 direction = vel / length;
        addForce( -direction * strength );
    }
}
void Planets::bouncingWindowEdges() {
    
    if (pos.x < 0) {
        pos.x = 0;
        vel.x *= -1;
    }
    
    if (pos.x > ofGetWidth()) {
        pos.x = ofGetWidth();
        vel.x *= -1;
    }
    
    if (pos.y < 0) {
        pos.y = 0;
        vel.y *= -1;
    }
    
    if (pos.y > ofGetHeight()) {
        pos.y = ofGetHeight();
        vel.y *= -1;
    }
}
void Planets::update(){
    pos +=vel;
    vel +=acc;
    acc*=0;
    
    
}

void Planets::draw(){
//    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofPushStyle();
    ofSetColor(ofRandom(100), ofRandom(255), ofRandom(255));
    ofDrawCircle(pos.x, pos.y, radius);
    ofPopStyle();
    
    
    
}
