#include "Letters.hpp"

void Letters::setup() {
    letterFont.loadFont("Courier New.ttf", 700, true,true,true);
    pos.x = ofGetWidth()/4;
    pos.y = ofGetHeight() - ofGetHeight()/5;
    
    
    letterN.moveTo(nStartX, nStartY);
    letterN.lineTo(nStartX +10, nStartY);
    letterN.lineTo(nStartX +10, ofGetHeight()/4);
    letterN.lineTo(nStartX, ofGetHeight()/4);
    letterN.close();


    letterN.moveTo(nStartX +10, ofGetHeight()/4);
    letterN.lineTo(nStartX, ofGetHeight()/4);
    letterN.lineTo(nStartX +200, nStartY);
    letterN.lineTo(nStartX +210, nStartY);
    letterN.close();

    letterN.moveTo(nStartX+200, nStartY);
    letterN.lineTo(nStartX+210, nStartY);
    letterN.lineTo(nStartX+210, ofGetHeight()/4);
    letterN.lineTo(nStartX+200, ofGetHeight()/4);
    letterN.close();

    letterN.setStrokeColor(255);
    letterN.setFilled(true);
    letterN.setFillColor(255);
    letterN.setStrokeWidth(10);
    
}



void Letters::update(){

}

void Letters::collide(){
    for(int i=0; i<particles.size(); i ++){
        for (int j = 0; j<letterN.getOutline().size(); j++){
            
        }
            
        }
        
    }



void Letters::draw(string _str){

    if(nDraw){
    letterN.draw();
    }
    
    
    
    str = _str;
    
    ofPoint startPos;
    startPos.x =  ofGetWidth() *.5;
    startPos.y =  ofGetHeight() * .5;

}



