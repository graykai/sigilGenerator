#pragma once

#include "ofMain.h"
#include "ofxVectorGraphics.h"
#include <string>

const std::string LETTERS("abcdefghijklmnopqrstuvwxyz");
const int SIGIL_SIZE = 250;

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

private:
	std::string inputData;
	std::string sigilData;

	bool debug;
	bool captureNextFrame;
	ofxVectorGraphics output;

	void updateSigilData();
	void drawFilledCircle(char l);
	glm::vec2 coordinateFor(char l);
};
