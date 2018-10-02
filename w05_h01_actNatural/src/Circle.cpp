#include "ofApp.h"
#include "Circle.hpp"


void Circle::setup(float pX, float pY, float size, float _rotationZ, float interp){
    
    pos.x = pX;
    pos.y = pY;
    radius = size;
    rotateee = _rotationZ;
    lerp = interp;

}

void Circle::update(){
    glm::vec2 mouse;
    mouse.x = ofGetMouseX();
    mouse.y = ofGetMouseY();
    
    float time = ofGetElapsedTimef();
    pos.x +=ofSignedNoise(time)*2;
    pos.y +=ofSignedNoise(time)*2;
    rotateee+=ofRandom(1,10);
    pos += (mouse - pos) * lerp;
}


void Circle::draw(){
    ofNoFill();
//    ofSetCircleResolution(3);
    ofSetColor(225);
    ofRotateZ(rotateee);
    ofDrawCircle(pos, radius);
    
}
    
    

