//
//  RenderEvent.hpp
//  This file is part of the "Input" project and released under the MIT License.
//
//  Created by Samuel Williams on 24/2/2019.
//  Copyright, 2019, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Event.hpp"

namespace Input
{
	// The receiver should render itself at the given time.
	class RenderEvent : public Event
	{
	public:
		RenderEvent(const Time::Interval & time, const Time::Interval & at) : Event(time), _at(at) {}
		virtual ~RenderEvent();
		
		const Time::Interval & at() const noexcept {return _at;}
		
		virtual bool apply(Handler & handler) const;
		
	protected:
		Time::Interval _at;
	};
}
