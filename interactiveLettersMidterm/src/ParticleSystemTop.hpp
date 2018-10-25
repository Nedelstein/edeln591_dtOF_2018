#pragma once

#include "ofMain.h"
#include "Particle.hpp"
#include "Letters.hpp"

class ParticleSystemTop{
public:
    
    ParticleSystemTop();
    ParticleSystemTop(glm::vec2 _pos);
    
    void setup();
    void update();
    void applyForce(glm::vec2 force);
    void draw();
    void applyElasticForce(float strength);
    void applyDampingForce(float strength);
    void letterCollide();
    void oCollide();
    void nCollide();
    void init();
    
    
    glm::vec2 pos;
    glm::vec2 leftPos;

    
    glm::vec2 center = glm::vec2(ofGetWidth()/2, ofGetHeight()/2);
    
    vector<Particle> particles;
    
    int numParticles = 500;
    
    Letters letter;
    bool oForce;
    bool collision;
    
};
