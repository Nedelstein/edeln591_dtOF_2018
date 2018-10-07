
#include "Particle.hpp"
#include "Firework.hpp"


Particle::Particle(){
    
    pos = glm::vec2(0,0);
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
    
}

Particle::Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass){
    pos = _pos;
    vel = _vel;
    mass = _mass;
}

void Particle::applyForce(glm::vec2 force){
    acc += force/mass;
}

void Particle::update(){
    
    pos +=vel;
    vel += acc;
    acc *=0;
}

void Particle::draw(){
    ofPushStyle();
    ofEnableAlphaBlending();
    fade -=3;
    ofSetColor(ofRandom(100,255),ofRandom(100,255), ofRandom(100,255), fade);
    ofDrawCircle(pos, mass*2);
    ofDisableAlphaBlending();
    ofPopStyle();

}

