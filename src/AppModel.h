//
//  Created by Takashi Aoki (c) takashiaoki.com
//

#pragma once

#include <iostream>
#include "ofMain.h"
#include "constants.h"

#include "aUtil.h"
#include "aEasing.h"
#include "aTimer.h"

namespace App
{
	// inspired from OF/examples/addons/oscReceiveExample
	static const int NUM_MSG_STRINGS = 20;

	class Position
    {
    public:
        static int STAGE_WIDTH;
        static int STAGE_HEIGHT;
        
        static int HALF_X;
        static int HALF_Y;
        static int QUARTER_X;
        static int QUARTER_Y;
        
        static void init(int sw, int sh)
        {
            STAGE_WIDTH  = sw;
            STAGE_HEIGHT = sh;
            HALF_X = sw >> 1;
            HALF_Y = sh >> 1;
            QUARTER_X = sw >> 2;
            QUARTER_Y = sh >> 2;            
        };
    };
};

class AppModel
{
private:
    static AppModel* instance;
	AppModel();
	~AppModel();

public:
	// singleton --------------------------------------
	static AppModel* getInstance()
	{
		if(instance == NULL)
		{
			instance = new AppModel();
			instance->setup();
		}
		return instance;
	}
	static void deleteInstance()
	{
		if(instance != NULL)
		{
			delete instance;
		}
	}
	// ------------------------------------------------
    
	void setup();
	void update();
	
	// console ////////////////////////////////////////

	template <class T>
	void log(const T& value)
	{
		// inspired from OF/examples/addons/oscReceiveExample

		// add to the list of strings to display
		_msg_strings[_current_msg] = ofToString(value);
		_timers[_current_msg] = ofGetElapsedTimef() + 3.0f;
		_current_msg = (_current_msg + 1) % App::NUM_MSG_STRINGS;
		// clear the next line
		_msg_strings[_current_msg] = "";
	};
	void drawConsole();

	///////////////////////////////////////////////////
	
private:
	// inspired from OF/examples/addons/oscReceiveExample
	int _current_msg;
	std::string _msg_strings[App::NUM_MSG_STRINGS];
	float _timers[App::NUM_MSG_STRINGS];
	float _cAlpha;

	at::Timer* _timer;
};