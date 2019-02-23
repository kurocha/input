//
//  Handler.hpp
//  This file is part of the "Input" project and released under the MIT License.
//
//  Created by Samuel Williams on 23/2/2019.
//  Copyright, 2019, by Samuel Williams. All rights reserved.
//

#pragma once

namespace Input
{
	class Event;
	class ResizeEvent;
	class ButtonEvent;
	class MotionEvent;
	
	class Handler
	{
	public:
		Handler() {}
		virtual ~Handler();
		
		virtual bool process(const Event &);
		
		virtual bool process(const ResizeEvent &);
		virtual bool process(const ButtonEvent &);
		virtual bool process(const MotionEvent &);
	};
}
