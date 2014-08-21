//
//  Created by Takashi Aoki (c) takashiaoki.com
//

#include "AppModel.h"

int App::Position::STAGE_WIDTH  = -1;
int App::Position::STAGE_HEIGHT = -1;
int App::Position::HALF_X       = -1;
int App::Position::HALF_Y       = -1;
int App::Position::QUARTER_Y    = -1;
int App::Position::QUARTER_X    = -1;

AppModel* AppModel::instance = NULL;

#pragma mark -
#pragma mark constructor & destructor - private

AppModel::AppModel() : _current_msg(0)
{
    
}
AppModel::~AppModel()
{

}

#pragma mark -
#pragma mark public methods

void AppModel::setup()
{
    _cAlpha = 0.f;

    // simple timer test
	_timer = new at::Timer();
	_timer->setInterval(5);
	//ofAddEventManager(_timer->completeEvent, this, &AppModel::timerUpdate);
	_timer->start();
}
void AppModel::update()
{
	_timer->update();

	float t = ofGetElapsedTimef();
	float d = at::fastmap(t, 0, 1.0, 0.f, 1.f);
	_cAlpha = (_cAlpha < 0.99)? at::easeInOutSine(d) : 1.0;
	
}
void AppModel::drawConsole()
{
	ofEnableAlphaBlending();
	ofSetColor(0,0,0,_cAlpha*150);
	ofRect(0, 0, App::Position::STAGE_WIDTH,App::Position::HALF_Y);
	ofSetColor(255,255,255,_cAlpha*255);

	// inspired from OF/examples/addons/oscReceiveExample
	int i = 0;
	while (i < App::NUM_MSG_STRINGS)
	{
		if(_timers[i] < ofGetElapsedTimef()) _msg_strings[i] = "";
		ofDrawBitmapString(_msg_strings[i], 20, 20 + 15 * i);
	    i++;
	}

	ofDrawBitmapString(ofToString(ofGetFrameRate()), App::Position::STAGE_WIDTH-80, 20);
}

#pragma mark -
#pragma mark event

// void AppModel::timerUpdate(ofxEventManager::Event& e)
// {
// 	static int lap = 0;
// 	lap++;
// 	std::cout << "timerUpdate, Event Called: " << lap << std::endl;	
// }