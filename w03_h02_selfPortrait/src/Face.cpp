#include "Face.h"

void Face::setup(){
    
    nose.load("nose.png");
    leftEye.load("leftEye.png");
    rightEye.load("rightEye.png");
    mouth.load("mouth.png");
  
    
    
    noseX = ofRandom(ofGetWidth()/2, ofGetWidth()/6);
    noseY = ofRandom(ofGetHeight()/2, ofGetWidth()/6);
    leftEyeX = noseX-100;
    leftEyeY = noseY-100;
    rightEyeX = noseX +100;
    rightEyeY = leftEyeY;
    mouthX = noseX- 40;
    mouthY = noseY + 200;
    
    noseSpeed = 2;
    mouthSpeed = 3;
    leftEyeSpeed = 2;
    rightEyeSpeed = 2;
    
    
    
    

    
}

void Face::update(){
   
    noseY+=noseSpeed;
    mouthY+=mouthSpeed;
    leftEyeY +=leftEyeSpeed;
    rightEyeY+=rightEyeSpeed;
    



    
}


void Face::draw(){

    
    nose.draw(noseX, noseY);
    leftEye.draw(leftEyeX, leftEyeY);
    rightEye.draw(rightEyeX, rightEyeY);
    mouth.draw(mouthX, mouthY);
    
    if (noseY>=ofGetHeight()-145) {
        noseSpeed=noseSpeed*-1;
    }
    if (noseY<=0){
        noseSpeed = 2;
    }
    
    if (mouthY>=ofGetHeight()-66){
        mouthSpeed=mouthSpeed*-1;
    }
    if (mouthY<= 0){
        mouthSpeed=2;
    }
    
    if(leftEyeY>=ofGetHeight()-65){
        leftEyeSpeed*=-1;
        
    }
    if(leftEyeY<=0){
        leftEyeSpeed=2;
    }
    
    if(rightEyeY>=ofGetHeight()-65){
        rightEyeSpeed*=-1;
    }
    if(rightEyeY<=0){
        rightEyeSpeed = 2;
    }
    if (noseX>=ofGetWidth()+86){
        noseSpeed*=-1;
    }
    if (noseX<=0){
        noseSpeed = 2;
    }
    if (mouthX>=ofGetWidth()+166){
        mouthSpeed*=-1;
    }
    if (mouthX<=0){
        mouthSpeed = 3;
    }
    if(leftEyeX>=ofGetWidth()+85){
        leftEyeSpeed*=-1;
    }
    if(leftEyeX<=0){
        leftEyeSpeed = 2;
    }
    if(rightEyeX>= ofGetWidth()+75){
        rightEyeSpeed*=-1;
    }
    if(rightEyeX<=0){
        rightEyeSpeed= 2;
    }
    
}
    void Face::mouseDragged(int x, int y, int button){
        if ((button == 0) || (button == 1) || (button == 2)){
            glm::vec2 destination;
            destination.x   = ofGetMouseX();
            destination.y   = ofGetMouseY();
            float percent = 0.03;
            
            glm::vec2 diff = destination - pos;
            
            pos+= percent * diff;
            
            
            noseX = pos.x;
            rightEyeX = pos.x;
            leftEyeX = pos.x;
            mouthX = pos.x;
            noseY = pos.y;
            rightEyeY = pos.y;
            leftEyeY = pos.y;
            mouthY = pos.y;
        
    }
    }


    
    
