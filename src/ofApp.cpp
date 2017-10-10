#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup() {
	//ofTrueTypeFont::setGlobalDpi(72);
	ofSetFrameRate(60);
	myFont.loadFont("BROADW.TTF", 80);

	currentLine = 0;
	clearCanvas = false;

	playheadMoving = false;
	movePlayhead = 0;

	//currentLineLength = 0;
	//lineNumber = 1;
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(ofColor::black);

	// if shit won't work
	string stringprint(charInput.begin(), charInput.end());
	myFont.drawString(stringprint, 120, (ofGetHeight()/2 + (myFont.stringHeight(stringprint)/2)));

	if (clearCanvas) { 
		//reset canvas
		ofClear(0,0,0);
		charInput.clear(); 
		clearCanvas = false;

		//reset playhead
		playheadMoving = false;
		movePlayhead = 0;
	}

	ofDrawLine(100+movePlayhead, ofGetHeight(), 100+movePlayhead, 0);

	//for moving playhead
	if (playheadMoving) { 
		movePlayhead += 1;

		ofPixels p = screenGrab.getPixels();
		int startY = (ofGetHeight() / 2 + (myFont.stringHeight(stringprint) / 2));

		for (int y = startY; y < myFont.stringHeight(stringprint); ++y) {
			if (p.getColor(100+movePlayhead, y) == ofColor::white) {
				p.setColor(100 + movePlayhead, y, ofColor::blueViolet);
			}
		}
	}

	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key != '~' && !playheadMoving) {
		charInput.push_back(key);
	}
	if( key == OF_KEY_BACKSPACE){
		cout << "clear canvas" << endl;
		clearCanvas = true;
	}
	if (key == OF_KEY_RETURN) {
		screenGrab.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		screenGrab.save("screenshot.png");

		if (playheadMoving) { playheadMoving = false; }
		else { playheadMoving = true; }
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
