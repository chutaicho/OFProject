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
	
	// this->e1.param = 100;
	// this->e2.param = 200;

	// ofAddEventManager(this->e1, this, &ofApp::callBackFunc);
	// ofAddEventManager(this->e2, this, &ofApp::callBackFunc);
	// ofAddEventManager(_model->modelEvent, this, &ofApp::fromModel);
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

void ofApp::callBackFunc(ofxEventManager::EventObj& e)
{
	std::cout << "Event Called: param = " << e.param << std::endl;
};
void ofApp::fromModel(ofxEventManager::EventObj& e)
{
	std::cout << "fromModel, Event Called: param = " << e.param << std::endl;	
}

#pragma mark -
#pragma mark key & mouse

void ofApp::keyPressed(int key)
{
	switch(key)
	{
		//default:
		case ' ':
			_model->log("hi");
			break;
		case 'e':
			ofDispatchEvent(this->e1);
			break;
		case 'w':
			ofDispatchEvent(this->e2);
			break;
		case 'r':
			ofRemoveEventManager(this->e1, this, &ofApp::callBackFunc);
			ofRemoveEventManager(this->e2, this, &ofApp::callBackFunc);
			break;
		case 'a':
			ofAddEventManager(this->e1, this, &ofApp::callBackFunc);
			ofAddEventManager(this->e2, this, &ofApp::callBackFunc);
			break;
		case 'd':
			_showConsole = !_showConsole;
			break;
		case 'c':
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