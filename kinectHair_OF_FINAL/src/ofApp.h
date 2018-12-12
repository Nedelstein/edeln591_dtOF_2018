#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"

using namespace cv;
using namespace ofxCv;

class ofApp : public ofBaseApp {

	public:
		void setup();
		void update();
		void draw();
    
    void updateNormals();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofxKinect kinect;
    
//    ofVideoPlayer backgroundLoop;
//    ofVideoPlayer backgroundDetect;
    
    ofVideoPlayer backgroundLoop_new;
    ofVideoPlayer backgroundDetect_new;
    
    ofSoundPlayer backgroundSound;
    
    bool blobDetected;
    
    ofMesh mesh;
    ofMesh normalLines;
    
    
    ofxCv::ContourFinder contourFinder;

    ofxCvGrayscaleImage grayImage;
    
    ofEasyCam cam;
    
    float nearThresh, farThresh;
    float grayFarThresh, grayNearThresh;
    float normalLength;
    int angle;
    int skip = 2;
    
    glm::vec3 getTriangleCenter(glm::vec3 a, glm::vec3 b, glm::vec3 c);
		
    ofTrueTypeFont myfont;
    
    ofColor colors[3];
};
