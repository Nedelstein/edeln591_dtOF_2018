#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
    ofSetCircleResolution(100);
    
    particles = ParticleSystemTop();
    
    alphabet['a'] = Letters();
    alphabet['a'].setup('A', center);
    alphabet['b'] = Letters();
    alphabet['b'].setup('B', center);
    alphabet['c'] = Letters();
    alphabet['c'].setup('C', center);
    alphabet['d'] = Letters();
    alphabet['d'].setup('D', center);
    alphabet['e'] = Letters();
    alphabet['e'].setup('E', center);
    alphabet['f'] = Letters();
    alphabet['f'].setup('F', center);
    alphabet['g'] = Letters();
    alphabet['g'].setup('G', center);
    alphabet['h'] = Letters();
    alphabet['h'].setup('H', center);
    alphabet['i'] = Letters();
    alphabet['i'].setup('I', center);
    alphabet['j'] = Letters();
    alphabet['j'].setup('J', center);
    alphabet['k'] = Letters();
    alphabet['k'].setup('K', center);
    alphabet['l'] = Letters();
    alphabet['l'].setup('L', center);
    alphabet['m'] = Letters();
    alphabet['m'].setup('M', center);
    alphabet['n'] = Letters();
    alphabet['n'].setup('N', center);
    alphabet['o'] = Letters();
    alphabet['o'].setup('O', center);
    alphabet['p'] = Letters();
    alphabet['p'].setup('P', center);
    alphabet['q'] = Letters();
    alphabet['q'].setup('Q', center);
    alphabet['r'] = Letters();
    alphabet['r'].setup('R', center);
    alphabet['s'] = Letters();
    alphabet['s'].setup('S', center);
    alphabet['t'] = Letters();
    alphabet['t'].setup('T', center);
    alphabet['u'] = Letters();
    alphabet['u'].setup('U', center);
    alphabet['v'] = Letters();
    alphabet['v'].setup('V', center);
    alphabet['w'] = Letters();
    alphabet['w'].setup('W', center);
    alphabet['x'] = Letters();
    alphabet['x'].setup('X', center);
    alphabet['y'] = Letters();
    alphabet['y'].setup('Y', center);
    alphabet['z'] = Letters();
    alphabet['z'].setup('Z', center);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(bAttraction){
    
    for (int i=0; i<particles.particles.size(); i++){
        
        glm::vec2 attraction = alphabet[currentChar].getForce(particles.particles[i].pos);
        particles.particles[i].applyForce(attraction);
        
        glm::vec2 attractor = alphabet[currentChar].getClosestAttractor(particles.particles[i].pos);
        particles.particles[i].applyDistanceDamping(attractor, 0, 20, 0.2, 0.01);
    }
    }
        
        else {
            particles.applyElasticForce(0.2);
            particles.applyDampingForce(0.1);
        }
            
    
    particles.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushStyle();
    ofSetColor(0, 0, 0, 10);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofPopStyle();

    particles.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    bAttraction = true;
    currentChar = key;
    

//////        for (int i=0; i<particles.particles.size(); i++){
////////        particleSystemTop[i].applyForce(attraction);
//////        particles.particles[i].collision = false;
//////        elasticForceOn = false;
//////        }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    currentChar = ' ';
    bAttraction = false;
    
//    if (key == 'n' || key == 'o' || key == 'a' || key == 'h'){
//        currentChar = ' ';
//        bAttraction = false;
////        elasticForceOn = true;
////        for (int i=0; i<particleSystemTop.size(); i++){
////            particleSystemTop[i].collision = false;
////    }
//    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
