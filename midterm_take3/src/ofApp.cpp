#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    b2Vec2 gravity(0.0f, -10.0f);
    b2World world(gravity);
    groundBodyDef.position.Set(0.0f, -10.0f);
    b2Body* groundBody = world.CreateBody(&groundBodyDef);
    groundBox.SetAsBox(50.0f, 10.0f);
    groundBody -> CreateFixture(&groundBox, 0.0f);
    
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);
    b2Body* body = world.CreateBody(&bodyDef);
    
    dynamicBox.SetAsBox(1.0f, 1.0f);
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    
    body -> CreateFixture(&fixtureDef);
    

    
    
}

//--------------------------------------------------------------
void ofApp::update(){



}

//--------------------------------------------------------------
void ofApp::draw()
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == 'f'){
        ofToggleFullscreen();
    }
//    if(key == 'n'){
//        nDraw = true;
//    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'n'){
        nDraw = false;
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
