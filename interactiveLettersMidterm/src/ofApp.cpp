#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(false);
    ofSetBackgroundAuto(false);
    ofSetCircleResolution(100);
    
    noah['n'] = Letters();
    noah['n'].setup('N', center);
    noah['o'] = Letters();
    noah['o'].setup('O', center);
    noah['a'] = Letters();
    noah['a'].setup('A', center);
    noah['h'] = Letters();
    noah['h'].setup('H', center);
    
    
    glm::vec2 posTop = glm::vec2(ofRandom(ofGetWidth()), ofRandom(0,5));
    glm::vec2 posLeft = glm::vec2(ofRandom(1,30), ofRandom(ofGetHeight()));
    glm::vec2 posRight = glm::vec2(ofRandom(ofGetWidth() - 1, ofGetWidth()- 30), ofGetHeight());
    glm::vec2 posBottom = glm::vec2(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()-1, ofGetHeight()-30));
    
    ParticleSystemTop _particleSystemTop = ParticleSystemTop(posTop);
    particleSystemTop.push_back(_particleSystemTop);
    
    ParticleSystemTop _particleSystemLeft = ParticleSystemTop(posLeft);
    particleSystemTop.push_back(_particleSystemLeft);
    
    ParticleSystemTop _particleSystemRight = ParticleSystemTop(posRight);
    particleSystemTop.push_back(_particleSystemRight);
    
    elasticForceOn = true;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    
    for (int i=0; i<particleSystemTop.size(); i++){
//        glm::vec2 force = noah[currentChar].getForce(particleSystemTop[i].pos);
//        particleSystemTop[i].applyForce(force);
        particleSystemTop[i].applyDampingForce(0.3);
        particleSystemTop[i].update();
        
        if (elasticForceOn){
            particleSystemTop[i].applyElasticForce(1);
            
            
        }
    }
    
    
        for (int i=0; i<particleSystemTop.size(); i++){
        glm::vec2 dir = noah[currentChar].pos - particleSystemTop[i].pos;
        float distance = glm::length(dir);
        if(distance >0){
            glm::vec2 normalizedDir = dir / distance;

            attraction = normalizedDir;
        }

        

    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushStyle();
    ofSetColor(0, 0, 0, 10);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofPopStyle();

    for (int i=0; i<particleSystemTop.size(); i++){
        particleSystemTop[i].draw();
    }
    if (currentChar != ' '){
    noah[currentChar].draw();
    }
    
    


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
    if (key == 'f'){
        ofToggleFullscreen();
        
    }
    
    if (key == 'n' || key == 'o' || key == 'a' || key == 'h'){
        currentChar = key;
        for (int i=0; i<particleSystemTop.size(); i++){
            glm::vec2 force = noah[currentChar].getForce(particleSystemTop[i].pos);
            particleSystemTop[i].applyForce(force);
//        particleSystemTop[i].applyForce(attraction);
        particleSystemTop[i].collision = false;
        elasticForceOn = false;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'n' || key == 'o' || key == 'a' || key == 'h'){
        currentChar = ' ';
//        elasticForceOn = true;
        for (int i=0; i<particleSystemTop.size(); i++){
            particleSystemTop[i].applyElasticForce(1);
            particleSystemTop[i].collision = false;
    }
    }
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
