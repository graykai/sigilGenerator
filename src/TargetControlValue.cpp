#include "ofApp.h"

TargettingControlValue::TargettingControlValue(): 
current_value(0), target_value(0), velocity_per_ms(0) {
}

bool TargettingControlValue::update(float delta_ms) {
	current_value += velocity_per_ms * delta_ms;
	if (fabs(current_value - target_value) < 0.1) {
		current_value = target_value;
		velocity_per_ms = 0.0;
	}

	return running();
}

float TargettingControlValue::operator()() {
	return current_value;
}

void TargettingControlValue::operator()(float target, float velocity) {
	target_value = target;
	if (velocity == 0.0) {
		velocity = (target - current_value) / 1000.0; // TODO: Make this value tunable
	}
	velocity_per_ms = velocity;
}