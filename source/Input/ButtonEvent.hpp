//
//  ButtonEvent.hpp
//  This file is part of the "Input" project and released under the MIT License.
//
//  Created by Samuel Williams on 23/2/2019.
//  Copyright, 2019, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Event.hpp"
#include "Key.hpp"

namespace Input
{
	class ButtonEvent : public Event
	{
	public:
		ButtonEvent(const Time::Interval & time, const Key & key, const State & state) : Event(time), _key(key), _state(state) {}
		virtual ~ButtonEvent();
		
		Key key() const noexcept {return _key;}
		State state() const noexcept {return _state;}
		
		bool button_pressed(const Button button) const {
			return _state == Pressed && _key.button() == button;
		}
		
		bool button_released(const Button button) const {
			return _state == Released && _key.button() == button;
		}
		
		virtual bool apply(Handler & handler) const;
		
	protected:
		Key _key;
		State _state;
	};
}
