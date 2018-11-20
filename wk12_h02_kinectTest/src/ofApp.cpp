#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
ofBackground(0);
//    ofSetLogLevel(OF_LOG_VERBOSE);

    kinect.setRegistration(true);
    
    kinect.init();
    
    kinect.open();
    
//    ofSetBackgroundAuto(false);
    
    colorImg.allocate(kinect.width, kinect.height);
    grayImage.allocate(kinect.width, kinect.height);
    grayThreshNear.allocate(kinect.width, kinect.height);
    grayThreshFar.allocate(kinect.width, kinect.height);
    
    nearThreshold = 70;
    farThreshold = 230;
    
    pointCloudMinZ = 50;
    pointCloudMaxZ = 1500;
    
    bKinectOpen = true;
    
    bDrawPointCloud = true;
    bDrawPointCloudLines = false;
    ofSetFrameRate(60);
    
    angle = 20;
    kinect.setCameraTiltAngle(angle);
    
    ofSetFrameRate(60);
    
    
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    kinect.update();
    
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255, 255, 255);
//    ofPushMatrix() ;
//    ofTranslate( 0,0 ) ;
    if(kinect.isFrameNew()){
    if(bDrawPointCloud) {
        cam.begin();
        drawPointCloud();
        cam.end();
    } else {
        // draw from the live kinect
        kinect.drawDepth(10, 10, 400, 300);
        kinect.draw(420, 10, 400, 300);
//        ofPopMatrix();
    }
}
}

//---------------------------------------------
    void ofApp::drawPointCloud(){
        int w = 640;
        int h = 480;
        ofMesh mesh;
        ofPoint pt;
        ofPoint ptEnd;
        ofPolyline line;
        mesh.setMode(OF_PRIMITIVE_LINES);
        mesh.enableIndices();

        
        int step = 4;
        for(int y = 0; y<h; y+=step){
            for(int x = 0; x<w; x +=step){
                if(kinect.getDistanceAt(x, y) > 0){
                    
                    glm::vec3 vertex = kinect.getWorldCoordinateAt(x, y);
                    if(vertex.z > pointCloudMinZ && vertex.z <pointCloudMaxZ){
                    mesh.addVertex(vertex);
                    
                    glm::vec3 vertexEnd = kinect.getWorldCoordinateAt(x,y) + ofRandom(-50,50);
                        mesh.addVertex(vertexEnd);
//                        ofColor col = kinect.getColorAt(x,y);
//                        mesh.addColor(col);
                        ofColor brown = ofColor(63,37,11);
//                        ofColor green = ofColor(34,139,34, 127);
                        mesh.addColor(brown);
//                        mesh.addColor(green);
                        pt.set(vertex.z, vertex.z);
                        line.addVertex(pt);
                        ptEnd.set(pt + 30);
                        line.addVertex(ptEnd);
               
                    }
                }
            }
        }
        ofEnableBlendMode(OF_BLENDMODE_ADD);
        ofSetLineWidth(2);
        ofPushMatrix();
        // the projected points are 'upside down' and 'backwards'
        ofScale(1, -1, -1);
        ofTranslate(0, 0, -1000); // center the points a bit
        ofEnableDepthTest();
        mesh.drawVertices();
        mesh.setupIndicesAuto();
        line.draw();
        ofDisableDepthTest();
        ofPopMatrix();
        ofEnableBlendMode(OF_BLENDMODE_ALPHA);


    }

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
case OF_KEY_UP:
    angle++;
    if(angle>30) angle=30;
    kinect.setCameraTiltAngle(angle);
    break;
    
case OF_KEY_DOWN:
    angle--;
    if(angle<-30) angle=-30;
    kinect.setCameraTiltAngle(angle);
    break;
    }
    
    if(key == 'f'){
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
