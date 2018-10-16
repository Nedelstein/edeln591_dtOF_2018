#include "ParticleSystemTop.hpp"

ParticleSystemTop::ParticleSystemTop(){
//    pos = glm::vec2(0,0);
}

ParticleSystemTop::ParticleSystemTop(glm::vec2 _pos){
    pos = _pos;
    
}

void ParticleSystemTop::applyForce(glm::vec2 force){
    for (int i=0; i<numParticles; i++){
        particles[i].applyForce(force);
    }
}

void ParticleSystemTop::applyElasticForce(float strength){
    for (int i=0; i<numParticles; i++){
        particles[i].applyElasticForce(strength);
    }
}

void ParticleSystemTop::intersects(){
    
}

void ParticleSystemTop::update(){
    for (int i=0; i <numParticles; i++){
        glm::vec2 vel = glm::vec2(ofRandom(-1,1), ofRandom(-1,1));
        float mass = ofRandom(0.05, 5);
        pos.x = ofRandom(ofGetWidth());
        pos.y = ofRandom(0,5);
        Particle particle = Particle(pos, vel, mass);
        particles.push_back(particle);
        particles[i].update();
//        for (int j=0; j< numParticles; j++){
//            if (i !=j){
//                particles[i].collide(particles[j]);
//            }
//        }
    }
        for(int i =0 ; i <particles.size(); i++ ){
            particles[i].collide(particles);
            
        }
}

void ParticleSystemTop::draw(){
    for(int i=0; i<numParticles; i++){
        particles[i].draw();
    }
}
