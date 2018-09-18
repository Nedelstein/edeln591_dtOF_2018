#include "ofApp.h"

float area;
//--------------------------------------------------------------
void ofApp::setup(){
    for (int i=0; i<1000; i++){
        circles[i].setup(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()),ofRandom(5,25), ofRandom(5,25));
    
    
    float area = circles[i].w * circles[i].h;
//    ofMap(area, 25, 625, 5, 20);
    float speed = area/100;
    
        circles[i].vel.x += speed * ofRandom(-1,1);
        circles[i].vel.y += speed * ofRandom(-1,1);
        
        circles[i].color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255),ofRandom(40,100));
        
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<1000; i++){
    circles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<1000; i++){
    circles[i].draw();
    
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    for (int i=0; i<1000; i++){
        circles[i].mousePressed(x, y,button);
    }
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
