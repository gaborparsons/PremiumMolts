#pragma once

#include "ofMain.h"
#include "ofxUI.h" // add

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
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    // add from here
    void exit();
    void setupGui();
    void process();
    void guiEvent(ofxUIEventArgs &e);
    
    ofxUISuperCanvas *gui0;
    
    ofImage src_img;
    ofImage dst_img;
    
    string filename;
    float min_hue;
    float max_hue;
};