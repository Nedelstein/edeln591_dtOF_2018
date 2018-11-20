#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    sphere.set(250,80);
    sphere.setRadius(ofGetWidth()/4);
    
    vertices0 = sphere.getMesh().getVertices();
    
    ofSetFrameRate(30);
    
    
    }

//--------------------------------------------------------------
void ofApp::update(){
    
    vector<glm::vec3> &vertices = sphere.getMesh().getVertices();
    int skip = 70;
    for(int i=0; i<vertices.size(); i+=skip){
        glm::vec3 v = vertices0[i];
        float length = glm::length(v);
        glm::vec3 normVec;
        if(length !=0){
            normVec = v/length;
        }
        float sx = sin(normVec.x * ofRandom(5));
        float sy = sin(normVec.y * ofRandom(5));
        float sz = sin(normVec.z * ofRandom(5));
        
        normVec.x += sy * sz * ofRandom(0, 1.5);
        normVec.y += sx * sz * ofRandom(0, 1.5);
        normVec.z += sx * sy * ofRandom(0, 1.5);
        normVec*= ofRandom(1,300);
        vertices[i] = normVec;
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    float time = ofGetElapsedTimef();
    ofEnableDepthTest();
    ofBackground(0);
//    glPointSize(4);
    cam.setPosition(0, 0, 100);
    cam.begin();
    ofSetColor(0,127, ofRandom(127,255));
    ofPushMatrix();
    ofTranslate(0,0,-1);
    sphere.setPosition(0,0,-100);
    sphere.drawWireframe();
    ofPopMatrix();
    cam.end();


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
