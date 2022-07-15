#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	debug = true;
	captureNextFrame = false;
	ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::whiteSmoke);
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2.0, ofGetHeight() / 2.0);

	glm::vec2 lastPos(0,0);
	int idx = 0;
	ofNoFill();
	ofSetColor(ofColor::black);
	ofDrawCircle(0, 0, SIGIL_SIZE * 1.15);
	ofSetLineWidth(3);
	for (const auto l : sigilData) {
		ofSetColor(ofColor::black);
		glm::vec2 currentPos = coordinateFor(l);

		if (currentPos.x != 0 || currentPos.y != 0) {
			if (lastPos.x != 0 || lastPos.y != 0) {
				ofDrawLine(lastPos, currentPos);
			}

			lastPos = currentPos;
			idx++;
		}
		else {
			ofLogError() << "Cannot find " << l;
		}
	}

	if (sigilData.length() > 2) {
		drawFilledCircle(sigilData.at(0));
		// drawFilledCircle(sigilData.at(-1));
	}
	ofPopMatrix();
	if (debug && !captureNextFrame) {
		ofSetColor(ofColor::darkMagenta);
		ofDrawBitmapString(inputData, 10, 20);
		ofDrawBitmapString(sigilData, 10, 30);
	}
}

void ofApp::drawFilledCircle(char l) {
	glm::vec2 pos = coordinateFor(l);
	ofFill();
	ofSetColor(ofColor::whiteSmoke);
	ofDrawCircle(pos, 10.0);

	ofNoFill();
	ofSetColor(ofColor::black);
	ofDrawCircle(pos, 10.0);
}

glm::vec2 ofApp::coordinateFor(char l) {
	int charIdx = LETTERS.find_first_of(l);
	if (charIdx == std::string::npos) {
		return glm::vec2(0, 0);
	}

	float angle = 360.0 / (float)LETTERS.length() * (float)charIdx;
	glm::vec2 currentPos(SIGIL_SIZE, 0);
	return glm::rotate(currentPos, (float)DEG_TO_RAD * angle);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

void ofApp::updateSigilData() {
	sigilData.clear();
	for (const auto c : inputData) {
		const auto lc = tolower(c);
		if (sigilData.find_first_of(lc) == std::string::npos && LETTERS.find_first_of(lc) != std::string::npos) {
			sigilData.push_back(lc);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	switch (key) {
	 case OF_KEY_BACKSPACE:
		 if (inputData.length() > 0) {
			 inputData.pop_back();
			 updateSigilData();
		 }
		 break;
	 case 19: // CTRL-S
		 captureNextFrame = true;
		 break;

	 default:
		 inputData.push_back(key);
		 updateSigilData();
		 break;
	}
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
