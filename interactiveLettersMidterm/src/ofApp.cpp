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
    ParticleSystemTop _particleSystemTop = ParticleSystemTop(posTop);
    particleSystemTop.push_back(_particleSystemTop);
    
    elasticForceOn = true;
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    
    for (int i=0; i<particleSystemTop.size(); i++){
        glm::vec2 force = noah[currentChar].getForce(particleSystemTop[i].pos);
        particleSystemTop[i].applyForce(force);
        particleSystemTop[i].applyDampingForce(0.2);
        particleSystemTop[i].update();
        
        if (elasticForceOn){
            particleSystemTop[i].applyElasticForce(0.3);
            
            
        }
    
        
        //particle force from top to center/////
        for (int i=0; i<particleSystemTop.size(); i++){
        glm::vec2 dirTop = noah[currentChar].pos - particleSystemTop[i].pos;
        float distanceTop = glm::length(dirTop);
        if(distanceTop >0){
            glm::vec2 normalizedDirTop = dirTop / distanceTop;

            attractionTop = normalizedDirTop;
        }

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
        particleSystemTop[i].applyForce(attractionTop);
        particleSystemTop[i].collision = false;
        elasticForceOn = false;
        }
    }
    
//    if (key == 'n'){
//        for (int i=0; i<particleSystemTop.size(); i++){
//
////            letter.nDraw = true;
//
//        }
    
    
//    if (key == 'o'){
//        for(int i=0; i<particleSystemTop.size(); i++){
//            particleSystemTop[i].applyForce(attractionTop);
//            letter.oDraw = true;
//            particleSystemTop[i].oForce = true;
//        }
//    }
//
//    if (key == 'a'){
//
//    }
//    if (key == 'h'){
//
//    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'n' || key == 'o' || key == 'a' || key == 'h'){
        currentChar = ' ';
        for (int i=0; i<particleSystemTop.size(); i++){
//            elasticForceOn = true;
            particleSystemTop[i].applyElasticForce(1);
            particleSystemTop[i].oForce = false;
            particleSystemTop[i].collision = false;
    }
        letter.nDraw = false;
        letter.oDraw = false;
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
