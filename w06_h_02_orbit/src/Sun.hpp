#pragma once

#include "ofMain.h"
#include "Planets.hpp"

class Sun{
public:
    
void setup();
void update();
void draw();
//    void mouseReleased(int x, int y, int button);
void setVelocity(glm::vec2 velocity);
void newOrb(int x, int y);

float orbRadius;
float orbHover;
glm::vec2 orbPosition;
glm::vec2 vel;
ofTexture orbTexture;
float mass;
//const float G;

glm::vec2 dir;
glm::vec2 getForce(Planets p);
    const float G = 0.4;
    
    ofSpherePrimitive sphere;
    ofTexture water;
    float rotationY, rotateY;
    
    float sphereX;
    float sphereY;
    float sphereDistance;
    float sphereSpeed;
    
    
};
