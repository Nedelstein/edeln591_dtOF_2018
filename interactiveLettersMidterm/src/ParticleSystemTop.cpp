#include "ParticleSystemTop.hpp"

ParticleSystemTop::ParticleSystemTop(){
    pos = glm::vec2(0,0);
//    init();
}

ParticleSystemTop::ParticleSystemTop(glm::vec2 _pos){
    pos = _pos;
    
    init();
    
}

void ParticleSystemTop::applyForce(glm::vec2 force){
    for (int i=0; i<particles.size(); i++){
        particles[i].applyForce(force);
    }
}

void ParticleSystemTop::applyElasticForce(float strength){
    for (int i=0; i<particles.size(); i++){
        particles[i].applyElasticForce(strength);
    }
}

void ParticleSystemTop::update(){
//    for (int i=0; i <numParticles; i++){
//        glm::vec2 vel = glm::vec2(ofRandom(-1,1), ofRandom(-1,1));
//        float mass = ofRandom(0.05, 5);
//        pos.x = ofRandom(ofGetWidth());
//        pos.y = ofRandom(0,5);
//        Particle particle = Particle(pos, vel, mass);
//        particles.push_back(particle);
//        particles[i].update();
//    }

//    for(auto& p:particles){
//        p.bCollisionChecked = false;
//    }
    for (int i=0; i <particles.size(); i++){
        particles[i].update();

        
        for (int j=0; j< particles.size(); j++){
            if(i !=j){
                if (particles[i].pos != particles[j].pos){
            
                particles[i].collide(particles[j]);
            }
            }
        }
        }
}

void ParticleSystemTop::init(){
    for (int i=0; i <numParticles; i++){
        glm::vec2 vel = glm::vec2(ofRandom(-1,1), ofRandom(1,3));
        float mass = ofRandom(0.5, 5);
        pos.x = ofRandom(ofGetWidth());
        pos.y = ofRandom(1,30);
        particles.emplace_back(pos, vel, mass);
//        Particle particle = Particle(pos, vel, mass);
//        particles.push_back(particle);
}
}
void ParticleSystemTop::draw(){
    for(int i=0; i<particles.size(); i++){
        particles[i].draw();
    }
}


//void ParticleSystemTop::letterCollide(){
//    for(int i=0; i<particles.size(); i++){
//        float distance = ofDist(particles[i].pos.x, particles[i].pos.y, letter.pos.x, letter.pos.y);
//        if (distance < 0){
//            particles[i].vel *=-1;
//        }
//
//    }
//}


