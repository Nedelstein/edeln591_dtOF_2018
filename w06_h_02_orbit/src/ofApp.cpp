#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
    ofBackground(0);
    ofEnableSmoothing();
    ofEnableDepthTest();
    ofSetVerticalSync(true);
    ofDisableArbTex();
    numPlanets = 10;
    numStars = 140;
    
    for (int m =0; m<numPlanets; m++){
        planets.push_back(Planets());
    }
    for (int a =0; a<1; a++){
        sun[a].setup();
    }
    for (int i=0; i <numStars; i++){
        stars[i].setup();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int a = 0; a<1; a++){
        for (int m = 0; m<numPlanets; m++){
            glm::vec2 force = sun[a].getForce(planets[m]);
            planets[m].addForce(force);
            sun[a].update();
        }
    }
    for (int m = 0; m<numPlanets; m++){
        planets[m].update();
    }
    for(int i = 0; i<numStars; i++){
        stars[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int a = 0; a<1; a++){
        sun[a].draw();
    }
    
    for (int m=0; m<numPlanets; m++){
        planets[m].draw();
    }
    for(int i=1; i<numStars; i++){
        stars[i].draw();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key  == 'f'){
        ofToggleFullscreen();
    }
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
//    Planets planet;
//    pos.x = ofGetMouseX();
//    pos.y = ofGetMouseY();
//    size = ofRandom(10,50);
////    planet.setup(pos, size);
//    planet.update();
//    planet.draw();
//    float size = ofRandom(20,100);
//    planets.push_back(planet);


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
