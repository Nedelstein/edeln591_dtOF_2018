#include "ParticleSystemTop.hpp"

//ParticleSystemTop::ParticleSystemTop(){
//    pos = glm::vec2(0,0);
////    init();
//}

ParticleSystemTop::ParticleSystemTop(glm::vec2 _pos){
    pos = _pos;
    leftPos = _pos;
    rightPos = _pos;
    bottomPos = _pos;
    
    
    init();
    
}

void ParticleSystemTop::applyForce(glm::vec2 force){
    for (int i=0; i<particles.size(); i++){
        particles[i].applyForce(force);
    }
}
void ParticleSystemTop::applyDampingForce(float strength){
    for (int i = 0; i>particles.size(); i++){
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
        
        if (collision){
        for (int j=0; j< particles.size(); j++){
            if(i !=j){
                if (particles[i].pos != particles[j].pos){

                particles[i].collide(particles[j]);
                }
            }
            }
        }
        }
}

void ParticleSystemTop::init(){
    for (int i=0; i <numParticles; i++){
        glm::vec2 vel = glm::vec2(0, 0);
        float mass = ofRandom(0.5, 2);
        pos.x = ofRandom(ofGetWidth());
        pos.y = ofRandom(1,30);
        particles.emplace_back(pos, vel, mass);
}

for (int  i = 0; i<numParticles; i++){
    glm::vec2 vel = glm::vec2(0, 0);
    float mass = ofRandom(0.5, 2);
    leftPos.x = ofRandom(1, 30);
    leftPos.y = ofRandom(ofGetHeight());
    particles.emplace_back(leftPos, vel, mass);
}
    for (int  i = 0; i<numParticles; i++){
        glm::vec2 vel = glm::vec2(0, 0);
        float mass = ofRandom(0.5, 2);
        rightPos.x = ofRandom(ofGetWidth() - 1, ofGetWidth()- 30);
        rightPos.y = ofRandom(ofGetHeight());
        particles.emplace_back(rightPos, vel, mass);
    }
    for (int  i = 0; i<numParticles; i++){
        glm::vec2 vel = glm::vec2(0, 0);
        float mass = ofRandom(0.5, 2);
        bottomPos.x = ofRandom(ofGetWidth());
        bottomPos.y = ofRandom(ofGetHeight()-1, ofGetHeight()-30);
        particles.emplace_back(bottomPos, vel, mass);
    }
    
}
void ParticleSystemTop::draw(){
    for(int i=0; i<particles.size(); i++){
        particles[i].draw();
    }
}


//void ParticleSystemTop::oCollide(){
//    if (oForce){
//        for(int i=0; i<particles.size(); i++){
//            glm::vec2 diff = letter.oPos - particles[i].pos;
//            particles[i].applyForce(diff * 0.03);
//            particles[i].applyDampingForce(0.1);
//            float distance = ofDist(particles[i].pos.x, particles[i].pos.y, letter.oPos.x, letter.oPos.y);
//            if (distance < letter.oRad + particles[i].radius){
//                particles[i].vel = glm::vec2(0,0);
//            }
//        }
//    }
//}

//void ParticleSystemTop::nCollide(){
//    for(int i=0; i<particles.size(); i ++){
//        vector<ofPolyline> outline = letter.letterN.getOutline();
//        for (int j = 0; j < outline.size(); j++){
//            if(outline[j].inside(particles[i])){
//                particles[i].vel = glm::vec2(0,0);
//
//            }
//        }
//    } 
//}



//void ParticleSystemTop::letterCollide(){
//    for(int i=0; i<particles.size(); i++){
//        float distance = ofDist(particles[i].pos.x, particles[i].pos.y, letter.pos.x, letter.pos.y);
//        if (distance < 0){
//            particles[i].vel *=-1;
//        }
//
//    }
//}


