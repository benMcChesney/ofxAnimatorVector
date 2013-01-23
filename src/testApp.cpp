#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
    //Setup our animator with it's xml path
    vectorAnimator.setup( 60 , ofToDataPath( "animatorData.xml") ) ;
    ofBackground(0, 0, 0) ; 
    ofSetFrameRate( 60 ) ;
}

//--------------------------------------------------------------
void testApp::update()
{
    vectorAnimator.update( ) ;
    
    //Add a point when we drag
    if ( vectorAnimator.bDragging )
        vectorAnimator.addPoint( ofPoint ( mouseX , mouseY ) ) ;
}

//--------------------------------------------------------------
void testApp::draw()
{
    vectorAnimator.draw ( ) ;
    
    string instructions = "c - clear , s - save settings " ;
    ofDrawBitmapStringHighlight( instructions , ofPoint ( 15 , 15 ) ) ; 
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch ( key )
    {
        case 'c':
        case 'C':
            vectorAnimator.clear( ) ;
            break ;
            
        case 's':
        case 'S':
            vectorAnimator.saveToXml( ofToDataPath( "animationData.xml" ) ) ; 
            break ;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    vectorAnimator.startDrag() ; 
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    vectorAnimator.endDrag() ; 
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

testApp::~testApp()
{
    //on exit, save XML data
    vectorAnimator.saveToXml( ofToDataPath( "animatorData.xml" ) ) ;
}


