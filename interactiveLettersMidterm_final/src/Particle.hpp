#pragma once

#include "ofMain.h"


class Particle{
public:
    
    Particle();
    Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass);
    
    void setup();
    void attract(glm::vec2 toPos, float strength);
    void applyDistanceDamping(glm::vec2 toPos, float minDist, float maxDist, float minDamp, float maxDamp);
    void update();
    void applyForce(glm::vec2 force);
    void applyDampingForce(float strength);
    void applyElasticForce(float strength);
//    void collide(Particle& p);
    void draw();
    void Ocollide();
    void checkEdges();
    
    glm::vec2 pos, vel, acc;
    glm::vec2 origPos;
    glm::vec2 elasticForce;
    float mass;
    float radius;
    bool bCollisionChecked;
    
};
