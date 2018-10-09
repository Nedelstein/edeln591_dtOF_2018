#include "Sun.hpp"
#include "ofGraphics.h"


void Sun::setup(){
        
    orbPosition.x = ofGetWidth()/2;
    orbPosition.y = ofGetHeight()/2;
    
    mass = 200;
    orbRadius = mass;
    sphere.setRadius(orbRadius);
    ofSetSphereResolution(100);
    rotationY = 0.0;
    rotateY = 0.05;
    ofLoadImage(water, "water.png");
    

}

glm::vec2 Sun::getForce(Planets p){
    glm::vec2 dir = orbPosition - p.pos;
    float distance = glm::length(dir);
    glm::vec2 force = glm::vec2(0,0);
    
    if (distance > 0){
        float distanceMod = ofClamp(distance, 5,25);
        float strenght = (G * mass * p.mass) / (distanceMod * distanceMod);
        glm::vec2 dirNorm = dir/distance;
        
        force = dirNorm * strenght;
    }
    return force;
}

void Sun::update(){
    rotationY-= rotateY;
}

void Sun::draw(){
//    ofPushStyle();
//    ofSetColor(100,200,200);
//    ofDrawCircle(orbPosition, mass);
//    ofPopStyle();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateYDeg(rotationY);
    sphere.setPosition(0,sphereY, 0);
    water.bind();
    sphere.draw();
    water.unbind();
    sphereY = 0;
    ofPopMatrix();
    sphereY = sphereY+ sphereSpeed;
    
    if (sphereY < ofGetHeight()/2 - 15) {
        sphereSpeed*=-1;
    }
    else if (sphereY > ofGetHeight()/2 + 15){
        sphereSpeed*=-1;
    }
}
