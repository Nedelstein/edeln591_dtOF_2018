#include "Letters.hpp"

void Letters::setup(char c, glm::vec2 _pos) {
    pos = _pos;
    letterFont.loadFont("Courier New.ttf", 600, false,false,true);
    
    ofTTFCharacter nLetter = letterFont.getCharacterAsPoints(c, true, false);
    
    float width   = letterFont.stringWidth(ofToString(c));  // char width and height
    float height  = letterFont.stringHeight(ofToString(c));
    glm::vec2 adjustedPos = _pos + glm::vec2(-width*0.5, height*0.5);
    
    vector<ofPolyline> nPolylines = nLetter.getOutline();
    
    for (int j = 0; j<nPolylines.size(); j++){
        ofPolyline outline = nPolylines[j].getResampledBySpacing(4);
        outline.translate(adjustedPos);
        for (int k = 0; k < outline.size(); k++){
            
            attractors.push_back(outline[k]);
            }
        }
    
    
    oPos.x = ofGetWidth() *0.5;
    oPos.y = ofGetHeight() *0.5;
    oRad = ofGetWidth()/4;
    
    
}

glm::vec2 Letters::getForce(glm::vec2 particlePos){
    glm::vec2 force = glm::vec2(0,0);
    for (int i=0; i<attractors.size(); i++){
        glm::vec2 dir = attractors[i] - particlePos;
        float distance = glm::length(dir);
        if (distance !=0 ){
            glm::vec2 norm = dir/distance;
            force = norm * 0.001;
        }
        else if (distance !=0 && distance < 10){
            force*=-1;
            }
        }
    
    
//   clamp the total force strength like so:
    float totalStrength = glm::length(force);
    if (totalStrength > 0){
        force = force / totalStrength; // normalize
        totalStrength = ofClamp(totalStrength, 0, 0.5);
        force *= totalStrength; // reapply clamped strength
    }
    return force;
}

void Letters::update(){

}




void Letters::draw(){
    
    for(int i=0; i<attractors.size(); i++){
        ofDrawCircle(attractors[i], 2);
    }
}



    



