#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxOpenCv.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        void drawPointCloud();
    void drawPointCloudLines();

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
    
    ofxCvColorImage colorImg;
    
    ofxCvGrayscaleImage grayImage; // grayscale depth image
    ofxCvGrayscaleImage grayThreshNear; // the near thresholded image
    ofxCvGrayscaleImage grayThreshFar; // the far thresholded image
    
    int nearThreshold;
    int farThreshold;
    
    bool bKinectOpen;
    bool bDrawPointCloud;
    bool bDrawPointCloudLines;

    
    float minBlobSize, maxBlobSize;
    float pointCloudMinZ, pointCloudMaxZ;
    
    int angle;
    
    ofEasyCam cam;
    
};
