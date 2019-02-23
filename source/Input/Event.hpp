//
//  Event.hpp
//  This file is part of the "Input" project and released under the MIT License.
//
//  Created by Samuel Williams on 23/2/2019.
//  Copyright, 2019, by Samuel Williams. All rights reserved.
//

#pragma once

#include <Time/Interval.hpp>

namespace Input
{
	class Handler;
	
	class Event
	{
	public:
		Event(const Time::Interval & time) : _time(time) {}
		virtual ~Event();
		
		Time::Interval time() const {return _time;}
		virtual bool apply(Handler & handler) const = 0;
		
	protected:
		Time::Interval _time;
	};
}
