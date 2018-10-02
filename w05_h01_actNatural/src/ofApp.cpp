#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    startX = ofGetWidth()/2;
    startY = ofGetHeight()/2 +100;
    
    
    
    for ( int i = 0; i < numCircles; i++ ){
        circles[i].setup(
           ofRandom(0 - 20, 0+20),
           ofRandom(0 - 20, 0+20),
           size,
           ofRandom(8,15),
           interp
        );
        
        size = ofRandom(5,200);
        interp = ofMap(size, 5, 200, 0.07, 0.03);
        
    }
    for (int i = 0; i<numCircles2; i++){
        circles2[i].setup(
        ofRandom(0 - 20, 0+20),
        ofRandom(0+10, 0+20),
        size,
        ofRandom(8,15),
        ofMap(size, 5, 170, 0.1, 0.03)
        );
        size =ofRandom(5,170);
    }
    
    for (int i = 0; i<numCircles3; i++){
        circles3[i].setup(
        ofRandom(0 - 20, 0+20),
        ofRandom(0+10, 0+20),
       size,
        ofRandom(8,15),
    ofMap(size, 5, 150, 0.1, 0.03)
        );
        size = ofRandom(5,150);
    }
        for (int i = 0; i<numCircles5; i++){
        circles4[i].setup(
        ofRandom(0 - 20, 0+20),
        ofRandom(0+10, 0+20),
        size,
        ofRandom(8,15),
        ofMap(size, 5, 120, 0.1, 0.03)
        );
            size = ofRandom(5,120);
    }

    for (int i = 0; i<numCircles5; i++){
        circles5[i].setup(
        ofRandom(0 - 20, 0+20),
        ofRandom(0+10, 0+20),
        size,
        ofRandom(8,15),
        ofMap(size, 5, 90, 0.1, 0.03)
        );
        size = ofRandom(5,90);
    }
    for (int i = 0; i<numCircles6; i++){
        circles6[i].setup(
        ofRandom(0 - 20, 0+20),
        ofRandom(0+10, 0+20),
        size,
        ofRandom(8,15),
        ofMap(size, 5, 90, 0.1, 0.03)
        );
        size = ofRandom(5,60);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    glm::vec2 mouse;
    mouse.x = ofGetMouseX();
    mouse.y = ofGetMouseY();
    
    for (int i = 0; i<numCircles; i++){

        circles[i].update();
        circles[i].pos += (mouse -circles[i].pos) * interp;
    }
    for (int i = 0; i<numCircles2; i++){
    circles2[i].update();
      circles2[i].pos += (mouse -circles2[i].pos) * interp;
    }
    for (int i = 0; i<numCircles3; i++){
    circles3[i].update();
    circles3[i].pos += (mouse -circles3[i].pos) * interp;
    }
    for (int i = 0; i<numCircles4; i ++){
    circles4[i].update();
    circles4[i].pos += (mouse -circles4[i].pos) * interp;
    }
    for (int i = 0; i<numCircles5; i ++){
        circles5[i].update();
        circles5[i].pos += (mouse -circles5[i].pos) * interp;
    }
    for (int i = 0; i<numCircles6; i ++){
        circles6[i].update();
        circles6[i].pos += (mouse -circles6[i].pos) * interp;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i<numCircles; i++){
    ofPushMatrix();
    ofSetCircleResolution(10);
    ofTranslate(startX, startY);
    ofRotateX(50);
    circles[i].draw();
    ofPopMatrix();
    

}

    for (int i = 0; i<numCircles2; i++){
        ofPushMatrix();
        ofSetCircleResolution(10);
        ofTranslate(startX, startY+40);
        ofRotateX(55);
        circles2[i].draw();
        ofPopMatrix();
    }
   
    for (int i = 0; i<numCircles3; i++){
        ofPushMatrix();
        ofSetCircleResolution(10);
        ofTranslate(startX, startY+80);
        ofRotateX(60);
        circles3[i].draw();
        ofPopMatrix();
    }
    for (int i = 0; i<numCircles4; i++){
        ofPushMatrix();
        ofSetCircleResolution(10);
        ofTranslate(startX, startY+120);
        ofRotateX(65);
        circles4[i].draw();
        ofPopMatrix();
    }
    for (int i = 0; i<numCircles5; i++){
        ofPushMatrix();
        ofSetCircleResolution(10);
        ofTranslate(startX, startY+160);
        ofRotateX(70);
        circles5[i].draw();
        ofPopMatrix();
    }
    for (int i = 0; i<numCircles6; i++){
        ofPushMatrix();
        ofSetCircleResolution(10);
        ofTranslate(startX, startY+200);
        ofRotateX(70);
        circles6[i].draw();
        ofPopMatrix();
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
