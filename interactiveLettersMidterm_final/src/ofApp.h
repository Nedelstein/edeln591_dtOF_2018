#pragma once

#include "ofMain.h"
#include "Letters.hpp"
#include "ParticleSystemTop.hpp"

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
    
    
    ParticleSystemTop particles;
    
    glm::vec2 center = glm::vec2(ofGetWidth()/2, ofGetHeight()/2);
    glm::vec2 attraction;
    bool bAttraction = false;
    
    map< char, Letters> alphabet;
    char currentChar;
};
