#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    myfont.load("arial.ttf", 32);

    //ambient background video
    backgroundLoop_new.load("backgroundLoop.mp4");
    backgroundLoop_new.setLoopState(OF_LOOP_PALINDROME);
    backgroundLoop_new.play();
    
    //triggered background video
    backgroundDetect_new.load("backgroundDetect.mp4");
    backgroundDetect_new.setLoopState(OF_LOOP_NONE);
    
    //background sound
    backgroundSound.load("backgroundNoise.mp3");
    backgroundSound.play();
    backgroundSound.setLoop(true);
    
    blobDetected = false;
    
    kinect.setRegistration(true);
    kinect.init();
    kinect.open();
    
    grayImage.allocate(kinect.width, kinect.height);
    
    angle = 20;
    kinect.setCameraTiltAngle(angle);
    
    grayFarThresh = 145;
    grayNearThresh = 250;
    
    farThresh = -800;
    nearThresh = 900;
    
    contourFinder.setMinArea(100);
    contourFinder.setThreshold(30);
    contourFinder.getTracker().setPersistence(100);


    colors[0] = ofColor(255,255,255);
    colors[1] = ofColor(78, 54, 41);
    colors[2] = ofColor(33, 68, 2);
}

//--------------------------------------------------------------
void ofApp::update(){
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
    kinect.update();
    
    backgroundLoop_new.update();
    if(blobDetected == true){
        backgroundDetect_new.update();
    }
    
    if(kinect.isFrameNew()){
        mesh.clear();
        grayImage.setFromPixels(kinect.getDepthPixels());
        ofPixels & pix = grayImage.getPixels();
        int numPixels = pix.size();
        for(int i=0; i<numPixels; i++){
            if(pix[i] < grayNearThresh && pix[i] > grayFarThresh){
                pix[i] = 255;
            } else{
                pix[i] = 0;
            }
        }
        
        //update the cv images
        grayImage.flagImageChanged();
        
        // find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
        // also, find holes is set to true so we will get interior contours as well...
//        contourFinder.findContours(grayImage, 50, (kinect.width*kinect.height)/2, 5, false);
//         cout << "number of blobs: " << contourFinder.nBlobs << endl;
        
        contourFinder.findContours(grayImage);
        
        int width = kinect.width/skip;
        int height = kinect.height/skip;
        for(int y=0; y<height; y++){
            for(int x=0; x<width; x++){
//                if(kinect.getDistanceAt(x, y) > 0){
                glm::vec3 vertex = kinect.getWorldCoordinateAt(x *skip, y*skip);
                ofColor kinCol = kinect.getColorAt(x*skip, y*skip);
                glm::vec3 normal = glm::vec3(0,0,0);
              
                vertex.z *= -1;
                vertex.z += 1000;
                
                if(vertex.z > nearThresh || vertex.z <farThresh){
                    kinCol.a = 0;
                }
                
                    mesh.addVertex(vertex);
                    mesh.addNormal(normal);
                    mesh.addColor(kinCol);
//        }
        }
        }
    for(int y = 0; y<height-1; y++){
        for(int x = 0; x<width-1; x++){
            
            mesh.addIndex(x+y*width);         // 0
            mesh.addIndex((x+1)+y*width);     // 1
            mesh.addIndex(x+(y+1)*width);     // 10
            
            mesh.addIndex((x+1)+y*width);     // 1
            mesh.addIndex((x+1)+(y+1)*width); // 11
            mesh.addIndex(x+(y+1)*width);     // 10
            }
        }
    }
    updateNormals();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(blobDetected == false){
        backgroundDetect_new.setPaused(true);
        backgroundLoop_new.play();
        backgroundLoop_new.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
    else if(blobDetected == true){
//                backgroundLoop.setPaused(true);
        backgroundLoop_new.stop();
        backgroundDetect_new.play();
        backgroundDetect_new.draw(0,0, ofGetWidth(), ofGetHeight());
        if(backgroundDetect_new.getPosition() >=0.99f){
//            backgroundDetect_new.setPaused(true);
            cout << "it's done" << endl;
            int lastFrame = backgroundDetect_new.getTotalNumFrames();
            backgroundDetect_new.setFrame(lastFrame);
            backgroundDetect_new.setPaused(true);
        }
    }

    ofPushMatrix();
    ofPushStyle();
    cam.begin();
    ofEnableDepthTest();
    ofTranslate(0, 0, 0);
    ofScale(-1,-1, 1);
//    mesh.drawFaces();
    
    
    vector<ofMeshFace> faces = mesh.getUniqueFaces();
    for(int i=0; i<faces.size(); i++) {
        
        ofVec3f v1 = faces[i].getVertex(0);
        ofVec3f v2 = faces[i].getVertex(1);
        ofVec3f v3 = faces[i].getVertex(2);
        
        ofVec3f n1 = faces[i].getNormal(0);
        ofVec3f n2 = faces[i].getNormal(1);
        ofVec3f n3 = faces[i].getNormal(2);
        
        ofFloatColor c1 = faces[i].getColor(0);
        ofFloatColor c2 = faces[i].getColor(1);
        ofFloatColor c3 = faces[i].getColor(2);
        
        if(c1.a > 0 && c2.a > 0 && c3.a > 0) {
            ofPushStyle();
            ofSetColor(0);
            ofDrawCircle(v1, 4);
            ofPopStyle();
        }
    }
    
    //set colors randomly test
//    for (int j = 0; j < contourFinder.size(); j++){
//        int id = contourFinder.getLabel(j);
//        if(id ==1){
//        ofSetColor(colors[0]);
//        }
//        if(id == 2){
//            ofSetColor(colors[1]);
//        }
//        if(id == 3){
//            ofSetColor(colors[2]);
//        }
//        cout << "blobs: " << id << endl;
//    }
    
    //dark brown
    ofSetColor(78, 54, 41);
    
    //forest green
//    ofSetColor(33, 68, 2);

    if (contourFinder.size() > 0){
        blobDetected = true;
    }
    else{
        blobDetected = false;
    }
    
    if (contourFinder.size()){
        normalLines.draw();
    }
    
    ofPopStyle();
    cam.end();
    ofDisableDepthTest();
    ofPopMatrix();
    
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
    
    //threshold values
    if(key == 'q'){
        farThresh +=50;
    }
    else    if(key == 'w'){
        farThresh -=50;
    }
    
    else    if(key == 'e'){
        nearThresh +=50;
    }
    
    else    if(key == 'r'){
        nearThresh -=50;
    }
    
    cout<<"near thresh: " << nearThresh<<endl;
    cout<<"far thresh:" << farThresh <<endl;
    
}

//--------------------------------------------------------------
void ofApp::updateNormals(){
    
    
    auto& verts = mesh.getVertices();
    normalLines.clear();
    normalLines.setMode(OF_PRIMITIVE_LINES);
    int normalIndex = 0;
    
    
    //generate vertex normals:
    //based on ofxMeshUtils addon:
    // https://github.com/ofZach/ofxMeshUtils/blob/master/src/ofxMeshUtils.cpp#L32-L58
  
    
    // reset current normals
    mesh.clearNormals();
    mesh.addNormals( vector<glm::vec3>(verts.size()) );
    // 1 normal per vertex
    
    // loop through the triangles
    for( int i=0; i+2 < mesh.getIndices().size(); i+=3 ){
        // 3 vertices per triangle
        const int va = mesh.getIndices()[i];
        const int vb = mesh.getIndices()[i+1];
        const int vc = mesh.getIndices()[i+2];
    
        ofFloatColor ca = mesh.getColors()[va];
        ofFloatColor cb = mesh.getColors()[vb];
        ofFloatColor cc = mesh.getColors()[vc];

        
        if (ca.a > 0 && cb.a > 0 && cc.a > 0){
            
        // calculate triangle face normal:
        // cross product of two edges
        glm::vec3 e1 = verts[va] - verts[vb];
        glm::vec3 e2 = verts[vc] - verts[vb];
        glm::vec3 nml = glm::normalize(glm::cross(e2,e1));
        
        // distribute face normal to 3 vertex normals:
        mesh.getNormals()[va] += nml;    // *add* face normal
        mesh.getNormals()[vb] += nml;    // to each vertex -
        mesh.getNormals()[vc] += nml;    // averages faces
    
        // extra --
        // store the face normal as a line
        // in normalLines mesh for drawing
        // -- normalLines mesh uses OF_PRIMITIVE_LINES mode
        
        glm::vec3 faceCenter = getTriangleCenter(verts[va],verts[vb],verts[vc]);
            (va,vb,vc);
        
        
        normalLength = ofRandom(10,40);
        glm::vec3 normalEnd = faceCenter + nml * normalLength;
       
        // 1 line = 2 vertices, 2 indices
        normalLines.addVertex(faceCenter);
        normalLines.addVertex(normalEnd);
        
        normalLines.addIndex(normalIndex);
        normalLines.addIndex(normalIndex+1);
            
        normalIndex += 2;   // increment
        
        }
    }
}
//--------------------------------------------------------------

glm::vec3 ofApp::getTriangleCenter(glm::vec3 a, glm::vec3 b, glm::vec3 c){
    // center of a triangle:
    // 2/3 from point to center of opposite edge
    glm::vec3 edgePt = (b + c) * 0.5;     // middle b_c edge
    return a * .333f + edgePt * .667f;    // lerp 2/3 a --> edgePt
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
