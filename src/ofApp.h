#pragma once

#include "ofMain.h"



class TargettingControlValue {
public:
	TargettingControlValue();
	~TargettingControlValue() = default;

	bool update(float delta_ms);
	float operator()();
	void operator()(float target, float velocity = 0.0);
	inline bool running() {
		return velocity_per_ms != 0.0;
	}

private:
	float target_value;
	float current_value;
	float velocity_per_ms;
};

class IdleTrigger {
public:
	IdleTrigger(ofEvent<void>& event, float idle_time_ms);

	void update(float delta_ms);
	void operator()(); // Register action

private:
	float idle_time_ms;
	float last_activity_ms;
	bool triggered;

	ofEvent<void>& evtTrigger;
};

class ofApp : public ofBaseApp {

	public:
		void setup();
		void update();
		void draw() { }

		void keyPressed(int key);
		void gotMessage(ofMessage msg);

		void onIdleTrigger();

		ofEvent<void> onIdle;
		
private:
	TargettingControlValue testValue;
	std::unique_ptr<IdleTrigger> idleTrigger;
	float last_ms;
};
