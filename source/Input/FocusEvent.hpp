//
//  FocusEvent.hpp
//  This file is part of the "Input" project and released under the MIT License.
//
//  Created by Samuel Williams on 24/2/2019.
//  Copyright, 2019, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Event.hpp"

namespace Input
{
	// The receiver has gone in to or out of focus.
	class FocusEvent : public Event
	{
	public:
		enum Flags : std::uint8_t
		{
			// Focus was lost.
			LOST = 1,
			
			// Focus was gained.
			GAINED = 2,
			
			// The view was minimised.
			MINIMISED = 4,
			
			// The view was maximised.
			MAXIMISED = 8,
			
			// The window moved to the foreground.
			FOREGROUND = 16,
			
			// The window moved to the background.
			BACKGROUND = 32,
			
			// The window has entered or exited full-screen.
			FULLSCREEN = 64,
			
			// The window has been closed.
			CLOSED = 128,
		};
		
		FocusEvent(const Time::Interval & time, Flags flags) : Event(time), _flags(flags) {}
		virtual ~FocusEvent();
		
		Flags flags() const noexcept {return _flags;}
		
		operator bool() const noexcept {return _flags & GAINED;}
		
		virtual bool apply(Handler & handler) const;
		
	protected:
		Flags _flags;
	};
}
