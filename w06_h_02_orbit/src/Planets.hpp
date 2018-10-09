#pragma once

#include "ofMain.h"


class Planets {
public:
    
    void setup(glm::vec2 _pos);
    Planets(glm::vec2 _pos, float _mass);
    Planets();
    void update();
    void addForce(glm::vec2 force);
    void draw();
    void applyDampingForce(float strength);
    void bouncingWindowEdges();
    
    glm::vec2 pos, vel, acc, frc;
    
    float gravity;
    float radius;
    float d;
    float angle;
    float orbitSpeed;
    float rotation = 0;
    float mass;
    
    
    
};
