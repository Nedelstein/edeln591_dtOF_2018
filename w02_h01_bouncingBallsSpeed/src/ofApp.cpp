#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    for (int i = 0; i<40; i++){
        circle[i].setup(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 40,40);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
for (int i = 0; i<40; i++){
    circle[i].update();
}
}
//--------------------------------------------------------------
void ofApp::draw(){
for (int i = 0; i<40; i++){
    circle[i].draw();
}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
for (int i = 0; i<40; i++){
    circle[i].keyPressed(key);
    
}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if(key == 'b'){
        ofToggleFullscreen();
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
