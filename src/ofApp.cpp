#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(15);
	idleTrigger = std::make_unique<IdleTrigger>(onIdle, 1000.0f);
	testValue(10.0);
	last_ms = ofGetElapsedTimeMillis();
	ofAddListener(ofApp::onIdle, this, &ofApp::onIdleTrigger);
}

//--------------------------------------------------------------
void ofApp::update() {
	float now = ofGetElapsedTimeMillis();
	if (testValue.update(now - last_ms)) {
		ofLogNotice() << testValue();
		(*idleTrigger)();
	}
	idleTrigger->update(now - last_ms);
	last_ms = now;
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	ofLogWarning() << "key pressed";
	(*idleTrigger)();
	if (!testValue.running()) {
		float newValue = testValue() + 10.0;
		ofLogNotice() << "Setting " << ofToString(newValue);
		testValue(newValue);
	}
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

void ofApp::onIdleTrigger() {
	ofLogNotice() << "Idle";
}
