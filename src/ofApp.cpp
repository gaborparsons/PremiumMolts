#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    filename = "creta";
    src_img.loadImage(filename + ".jpg");
    dst_img.allocate(src_img.width, src_img.height, OF_IMAGE_COLOR);
    
    setupGui();
    process();
}

void ofApp::setupGui(){
    ofEnableSmoothing();
    ofSetCircleResolution(60);
    
    min_hue = 100;
    max_hue = 200;
    
    gui0 = new ofxUISuperCanvas("SLIDER WIDGETS");
    
    gui0->addSpacer();
    gui0->addLabel("min_hue");
    gui0->addSlider("min", 0.0, 255.0, &min_hue);
    gui0->addLabel("max_hue");
    gui0->addSlider("max", 0.0, 255.0, &max_hue);
    
    gui0->autoSizeToFitWidgets();
    ofAddListener(gui0->newGUIEvent,this,&ofApp::guiEvent);
}
void ofApp::process(){
    ofColor src_col,dst_col;
    for(int i=0; i<dst_img.height; i++){
        for (int j=0; j<dst_img.width; j++) {
            src_col = src_img.getColor(j, i);
            
            if( min_hue < src_col.getHue() && src_col.getHue() < max_hue){
                dst_col = src_col;
            } else {
                dst_col = ofColor(src_col.g);
            }
            dst_img.setColor(j, i, dst_col);
        }
    }
    dst_img.update();
}
void ofApp::guiEvent(ofxUIEventArgs &e){
    process();
    cout << min_hue << ":" << max_hue << endl;
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    float rate = ofGetWidth() / (float)src_img.width / 2;
    ofScale(rate,rate);
    src_img.draw(0, 0);
    dst_img.draw(src_img.width, 0);
    ofPopMatrix();

}

void ofApp::exit(){
    delete gui0;
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key)
    {
            
        case 'g':
        {
            gui0->toggleVisible();
            break;
        }
        case 's':
        {
            string save_filename =  filename + ofGetTimestampString() + ".jpg";
            dst_img.saveImage(save_filename);
            cout << "save as " << save_filename << endl;
            break;
        }
        default:
            break;
    }

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
