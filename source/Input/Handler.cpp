//
//  Handler.cpp
//  This file is part of the "Input" project and released under the MIT License.
//
//  Created by Samuel Williams on 23/2/2019.
//  Copyright, 2019, by Samuel Williams. All rights reserved.
//

#include "Handler.hpp"

#include "Event.hpp"
#include "ResizeEvent.hpp"
#include "ButtonEvent.hpp"
#include "MotionEvent.hpp"

#include <Logger/Console.hpp>
#include <Streams/Container.hpp>

namespace Input
{
	using namespace Logger;
	
	Handler::~Handler()
	{
	}
	
	bool Handler::process(const Event & event)
	{
		return event.apply(*this);
	}
	
	bool Handler::process(const ResizeEvent & event)
	{
		Console::warn("Unhandled Resize Event", Streams::safe(event.size()));
		
		return false;
	}
	
	bool Handler::process(const ButtonEvent & event)
	{
		Console::warn("Unhandled Button Event", Streams::safe(event.key().button()));
		
		return false;
	}
	
	bool Handler::process(const MotionEvent & event)
	{
		Console::warn("Unhandled Motion Event", Streams::safe(event.delta()));
		
		return false;
	}
}
