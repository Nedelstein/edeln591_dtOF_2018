#include "Stars.hpp"


void Stars::setup(){
    fade = 0;
    size = ofRandom(.5, 2);
    pos.x = ofRandom(ofGetWidth());
    pos.y = ofRandom(ofGetHeight());
}

void Stars::update(){

//    if (fade <= 0){
//        fade +=1;
//    }
    if (fade >= 200){
        fade-=1;
    }
        fade++;
    
}

void Stars::draw(){
    ofEnableAlphaBlending();
    ofSetColor(255, fade);
    ofDrawCircle(pos, size);
    ofDisableAlphaBlending();
    
}

