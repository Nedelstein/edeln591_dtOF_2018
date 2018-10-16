#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(100);
    letter.setup();

    
    glm::vec2 posTop = glm::vec2(ofRandom(ofGetWidth()), ofRandom(0,5));
    
    ParticleSystemTop _particleSystemTop = ParticleSystemTop(posTop);
    particleSystemTop.push_back(_particleSystemTop);
    
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    
    for (int i=0; i<particleSystemTop.size(); i++){
       
        ///particle force from top to center/////
        
        glm::vec2 dirTop = center - particleSystemTop[i].pos;
        float distanceTop = glm::length(dirTop);
        if(distanceTop >0){
            glm::vec2 normalizedDirTop = dirTop / distanceTop;
        
            attractionTop = normalizedDirTop;
        }
//
        particleSystemTop[i].update();

    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    letter.draw(_str);
    for (int i=0; i<particleSystemTop.size(); i++){
        particleSystemTop[i].draw();
    }

    


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'f'){
        ofToggleFullscreen();
        
    }
    
    if (key == 'n'){
        _str = "N";
        for (int i=0; i<particleSystemTop.size(); i++){
            particleSystemTop[i].applyForce(attractionTop);
        }
        
    }
    if (key == 'o'){
        _str = "O";
    }

    if (key == 'a'){
        _str = "A";
    }
    if (key == 'h'){
        _str = "H";
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'n' || 'o' || 'a' || 'h'){
        _str = "";
        for (int i=0; i<particleSystemTop.size(); i++){
            particleSystemTop[i].applyElasticForce(5);
//            particleSystemTop[i].applyForce(-attractionTop);
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
