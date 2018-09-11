#include "Circle.h"

void Circle::setup(float posX, float posY, float width, float height){
    ofSetFrameRate(60);
    x = posX;
    y = posY;
    w = width;
    h = height;
    dirX = ofRandom(-5,5);
    dirY = ofRandom(-5,5);
    color.set(0, ofRandom(255), ofRandom(255), ofRandom(20,200));
    
}

void Circle::update(){
    x+=dirX;
    y+=dirY;
    
    if(x>= ofGetWidth() - w/2){
        dirX*=-1;
    }
    else if(x<=0+w/2){
        dirX*=-1;
    }
    
    if(y>=ofGetHeight()-h/2){
        dirY*=-1;
    }
    else if(y<=0+h/2){
        dirY*=-1;
    }
    
}

void Circle::draw(){
    
 
    
    float angle = ofRandom(ofDegToRad(360.0));
    float distance = ofRandom(8);
    float xOffset = cos(angle) * distance;
    float yOffset = sin(angle) * distance;
    
    ofSetColor(color);
    ofDrawEllipse(x+xOffset, y+yOffset, w, h);
//    if(hit == true){
//        dirX *=2;
//        dirY*=2;
//    }

    
}

void Circle::keyPressed(int key){
    ///speed up
    if(key == 'f'){
        dirX *=2;
        dirY*=2;
    }
    ///slow down
    else if (key == 's'){
        dirX *=0.5;
        dirY*=0.5;
    }
    else{
        dirX = ofRandom(-5,5);
        dirY = ofRandom(-5,5);
    }
    
}

