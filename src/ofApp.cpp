#include "ofApp.h"

#pragma mark -
#pragma mark public

void ofApp::setup()
{
	App::Position::init(ofGetWidth(), ofGetHeight());
	ofBackground(ofColor::gray);
	ofSetVerticalSync(true);
	ofSetFrameRate(App::FPS);

	_showConsole = true;
	_model = AppModel::getInstance();
}	
void ofApp::update()
{
	_model->update();
}
void ofApp::draw()
{
	if(_showConsole)_model->drawConsole();
}

#pragma mark -
#pragma mark private

#pragma mark -
#pragma mark events

#pragma mark -
#pragma mark key & mouse

void ofApp::keyPressed(int key)
{
	switch(key)
	{
		default:
		case ' ':
			_model->log("hi");
			break;
		case 'd':
			_showConsole = !_showConsole;
			break;
		case '1':
			break;
		case '2':
			break;
		case '3':
			break;
	}
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}
//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}
//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}
//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}
//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{ 

}