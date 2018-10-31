#include "Letters.hpp"

void Letters::setup(char c, glm::vec2 _pos) {
    pos = _pos;
    letterFont.load("Courier New.ttf", 600, false,false,true);
    
    ofPath nLetter = letterFont.getCharacterAsPoints(c, true, false);
    
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
}

    glm::vec2 Letters::getForce(glm::vec2 particlePos){
        glm::vec2 force = glm::vec2(0,0);
        glm::vec2 closestPt = getClosestAttractor(particlePos);
        if (closestPt != glm::vec2(0,0)){
            glm::vec2 diff = closestPt - particlePos;
            float distance = glm::length(diff);
            if (distance !=0){
                force = diff/ distance *0.1;
            }
        }
        return force;
    }

glm::vec2 Letters::getClosestAttractor(glm::vec2 toPos){
    glm::vec2 closestPt;
    float closestDist = 9999999;
    for (unsigned int i = 0; i <attractors.size(); i++){
        glm::vec2 dir = attractors[i] - toPos;
        float distance = glm::length(dir);
        if(distance < closestDist){
            closestDist = distance;
            closestPt   = attractors[i];
        }
    }
    return closestPt;   // returns (0,0) on failure (if no points < 9999999 away)
}

void Letters::draw(){
    
    for(int i=0; i<attractors.size(); i++){
        ofDrawCircle(attractors[i], 4);
    }
}



    



