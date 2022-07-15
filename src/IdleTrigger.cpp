#include "ofApp.h"

IdleTrigger::IdleTrigger(ofEvent<void>& e, float idle_time_ms) : evtTrigger(e), idle_time_ms(idle_time_ms) {

}

void IdleTrigger::update(float _delta_ms) {
	float now = ofGetElapsedTimeMillis();
	if (now - last_activity_ms > idle_time_ms && !triggered) {
		ofNotifyEvent(evtTrigger);
		triggered = true;
	}
}

void IdleTrigger::operator()() {
	last_activity_ms = ofGetElapsedTimeMillis();
	triggered = false;
}