#include "Particle.hpp"

Particle::Particle(){
    pos = glm::vec2(0,0);
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
}

Particle::Particle(glm::vec2 _pos, glm::vec2 _vel, float _mass){
    origPos = _pos;
    pos = origPos;
    vel = _vel;
    mass = _mass;
    radius = mass*2;
}

void Particle::applyForce(glm::vec2 force){
    
    acc += force / mass;
    
}
void Particle::applyElasticForce(float strength){
    glm::vec2 diff = origPos - pos;
    float length = glm::length(diff);
    if(length !=0){
        glm::vec2 dir = diff/length;
        elasticForce = dir * strength;
        applyForce(elasticForce);
    }
    
}


void Particle::update(){
    vel +=acc;
    pos +=vel;
    
    acc*=0;
    
    
}



void Particle::draw(){
    
    ofDrawCircle(pos.x, pos.y, radius);
}

void Particle::collide(Particle& p){

    glm::vec2 delta = pos - p.pos;
    float d = delta.x * delta.x + delta.y * delta.y; // this is the square of the distance
    
    float r = radius + p.radius;
    if (d< r*r){
        glm::vec2 dir = pos-p.pos;
                    //normalize dir/////
                    float length = glm::length(dir);
                    glm::vec2 normDir;
                    if(length !=0){
                        normDir = dir/length;
                    }
                    applyForce(2*normDir);
    }
    }


