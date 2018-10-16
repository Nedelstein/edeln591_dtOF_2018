#pragma once

#include "ofMain.h"


class Particle{
public:
    
    Particle();
    Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass);
    
    void setup();
    void update();
    void applyForce(glm::vec2 force);
    void applyElasticForce(float strength);
    void collide(vector<Particle>& particles);
    void draw();
    
    glm::vec2 pos, vel, acc;
    glm::vec2 origPos;
    glm::vec2 elasticForce;
    float mass;
    float radius;
    
};
