#pragma once

#include "ofMain.h"
#include "Particle.hpp"
#include "Letters.hpp"

class ParticleSystemTop{
public:
    
    ParticleSystemTop();
//    ParticleSystemTop(glm::vec2 _pos);
    
    void setup();
    void update();
    void attract(glm::vec2 toPos, float strength);
    void applyDistanceDamping(glm::vec2 toPos, float minDist, float maxDist, float minDamp, float maxDamp);
    void applyForce(glm::vec2 force);
    void draw();
    void applyElasticForce(float strength);
    void applyDampingForce(float strength);
    void init();
    
    
    glm::vec2 pos;

    
    glm::vec2 center = glm::vec2(ofGetWidth()/2, ofGetHeight()/2);
    
    vector<Particle> particles;
    
    int numParticles = 300;
    
    Letters letter;
    bool oForce;
    bool collision;
    
};
