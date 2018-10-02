#pragma once

#include "ofMain.h"
#include "Circle.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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
		
    float rotationZ;
    float startX;
    float startY;
    float interp;
    float size;
    float _posX;
    
    
    int numCircles = 100;
//
   Circle circles[100];
    
    int numCircles2= 100;
    Circle circles2[100];
    
    int numCircles3 = 100;
    Circle circles3[100];
    
    int numCircles4 = 100;
    Circle circles4[100];


    int numCircles5 = 100;
    Circle circles5[100];
    
    int numCircles6 = 100;
    Circle circles6[100];
};
