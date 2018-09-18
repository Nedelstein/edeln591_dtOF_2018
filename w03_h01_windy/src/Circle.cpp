#include "Circle.h"


void Circle::setup(float posX, float posY, float width, float height){
    pos = glm::vec2(posX, posY);
    w = width;
    h = height;
    
    ofSetBackgroundColor(0, 0, 0);
    

    
    color = ofColor(255);
    
    vel.x = 0.05;
    vel.y = 0.05;
    acc.x = 0;
    acc.y = 0;
    wind.x = 0;
    wind.y = 0;
    gravity = 9.18;
}

void Circle::update(){

    pos +=vel;
    vel += acc+wind;
    time = ofGetElapsedTimef();
    acc.x = time+vel.x;
    acc.y=time+vel.y+gravity;
    
    if (pos.y>ofGetHeight() + 10) {
        pos.y = -5;
    }
    if (pos.y<0){
        pos.y = ofGetHeight()+5;
    }
    if (pos.x >ofGetWidth()+ 10){
        pos.x = -5;
    }
    if (pos.x<0){
        pos.x = ofGetWidth() + 10;
    }
    
    if(pos.y == 0){
        pos.x-=10;
    }
    if(pos.y == ofGetHeight()){
        pos.y+=10;
    }

    acc*=0;
}

void Circle::draw(){
    ofSetColor(color);
    ofDrawEllipse(pos.x, pos.y, w, h);


    
}


void Circle::mousePressed(int x, int y, int button){
    if ((button == 0) || (button == 1) || (button == 2)){
        wind.x = ofMap(ofGetMouseX(), 0, ofGetWidth(), -0.01, .01);
        wind.y = ofMap(ofGetMouseY(),0, ofGetHeight(), -0.01,.01);
        cout << "clicked" << endl;
    }
    else {
        wind.x = 0;
        wind.y = 0;
    }
}



