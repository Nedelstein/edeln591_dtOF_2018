#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    for(int i=0; i<1; i++){
        face[i].setup();
    }
//    nose.load("nose.png");
//    leftEye.load("leftEye.png");
//    rightEye.load("rightEye.png");
//    mouth.load("mouth.png");
//
//     noseX = ofGetWidth()/2;
//     noseY = ofGetHeight()/2;
//      leftEyeX = noseX-100;
//     leftEyeY = noseY-100;
//    rightEyeX = noseX +100;
//    rightEyeY = leftEyeY;
//    mouthX = noseX- 40;
//    mouthY = noseY + 200;
}

//--------------------------------------------------------------
void ofApp::update(){
      for(int i=0; i<1; i++){
          face[i].update();
      }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0; i<1; i++){
        face[i].draw();
    }
    
//    nose.draw(noseX, noseY);
//    leftEye.draw(leftEyeX, leftEyeY);
//    rightEye.draw(rightEyeX, rightEyeY);
//    mouth.draw(mouthX, mouthY);

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
        for(int i=0; i<1; i++){
            face[i].mousePressed(x,y,button);
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
