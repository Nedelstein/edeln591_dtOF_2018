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
    
    ofDrawCircle(pos, mass*2);
}


//void Particle::if


void Particle::collide(vector<Particle>& particles){
//    if (ofDist(inParticle-> pos.x, inParticle->pos.y, pos.x, pos.y) <radius*2){
//        vel*=-1;
    
    for(int i =0 ; i<particles.size(); i++){
    
    float distance = ofDist(pos.x, pos.y,particles[i].pos.x, particles[i].pos.y);
        if(distance>0 && distance <5){
            particles[i].pos.x = ofGetWidth()/2;
            particles[i].pos.y =ofGetHeight()/2;
            glm::vec2 dir = particles[i].pos - pos;
//            dir = dir.normalize();
            float length = glm::length(dir);
            glm::vec2 normVec = dir / length;
            
//            ofColor(255,0,0);
            
            
            applyForce(normVec*10);
        }
        
    }
    
    }

