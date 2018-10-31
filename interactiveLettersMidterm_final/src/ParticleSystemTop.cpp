#include "ParticleSystemTop.hpp"


ParticleSystemTop::ParticleSystemTop(){
    setup();
    
}

void ParticleSystemTop::setup(){
    for (int i=0; i <numParticles; i++){
        glm::vec2 vel = glm::vec2(0,0);
        float mass = ofRandom(0.5, 2);
        glm::vec2 pPos;
        pPos.x = ofRandom(ofGetWidth());
        pPos.y = ofRandom(1, 30);
        particles.emplace_back(pPos, vel, mass);
    }
    
    for (int  i = 0; i<numParticles; i++){
        glm::vec2 vel = glm::vec2(0, 0);
        float mass = ofRandom(0.5, 2);
        glm::vec2 pPosLeft;
        pPosLeft.x = ofRandom(1, 30);
        pPosLeft.y = ofRandom(ofGetHeight());
        particles.emplace_back(pPosLeft, vel, mass);
    }
    for (int  i = 0; i<numParticles; i++){
        glm::vec2 vel = glm::vec2(0, 0);
        float mass = ofRandom(0.5, 2);
        glm::vec2 pPosRight;
        pPosRight.x = ofRandom(ofGetWidth() - 1, ofGetWidth()- 30);
        pPosRight.y = ofRandom(ofGetHeight());
        particles.emplace_back(pPosRight, vel, mass);
    }
    for (int  i = 0; i<numParticles; i++){
        glm::vec2 vel = glm::vec2(0, 0);
        float mass = ofRandom(0.5, 2);
        glm::vec2 pPosBottom;
        pPosBottom.x = ofRandom(ofGetWidth());
        pPosBottom.y = ofRandom(ofGetHeight()-1, ofGetHeight()-30);
        particles.emplace_back(pPosBottom, vel, mass);
    }
}

void ParticleSystemTop::attract(glm::vec2 toPos, float strength){
    for (int i=0; i<particles.size(); i++){
        particles[i].attract(toPos, strength);
    }
}

void ParticleSystemTop::applyDistanceDamping(glm::vec2 toPos, float minDist, float maxDist, float minDamp, float maxDamp){
    for (int i=0; i<particles.size(); i++){
        float distance = glm::length(toPos - particles[i].pos);
        float strength = ofMap(distance, minDist, maxDist, minDamp, maxDamp, true); // clamp
        particles[i].applyDampingForce(strength);
    }
}

void ParticleSystemTop::applyForce(glm::vec2 force){
    for (int i=0; i<particles.size(); i++){
        particles[i].applyForce(force);
    }
}
void ParticleSystemTop::applyDampingForce(float strength){
    for (int i = 0; i<particles.size(); i++){
        particles[i].applyDampingForce(strength);
    }
}

void ParticleSystemTop::applyElasticForce(float strength){
    for (int i=0; i<particles.size(); i++){
        particles[i].applyElasticForce(strength);
    }
}

void ParticleSystemTop::update(){

    for (int i=0; i <particles.size(); i++){
        particles[i].update();
        particles[i].checkEdges();
        
//        if (collision){
//        for (int j=0; j< particles.size(); j++){
//            if(i !=j){
//                if (particles[i].pos != particles[j].pos){
//
//                particles[i].collide(particles[j]);
//                }
//            }
//            }
//        }
        }
}

void ParticleSystemTop::draw(){
    for(int i=0; i<particles.size(); i++){
        particles[i].draw();
    }
}



