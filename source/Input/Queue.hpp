//
//  Queue.hpp
//  This file is part of the "Input" project and released under the MIT License.
//
//  Created by Samuel Williams on 23/2/2019.
//  Copyright, 2019, by Samuel Williams. All rights reserved.
//

#pragma once

#include "Event.hpp"
#include "Handler.hpp"

#include <Parallel/Queue.hpp>

#include <memory>

namespace Input
{
	class Queue : public Handler
	{
	public:
		Queue();
		virtual ~Queue();
		
		void dequeue(Handler & handler);
		
		virtual bool process(const ResizeEvent &);
		virtual bool process(const ButtonEvent &);
		virtual bool process(const MotionEvent &);
		virtual bool process(const RenderEvent &);
		virtual bool process(const FocusEvent &);
		
	protected:
		using EventPtr = std::unique_ptr<Event>;
		Parallel::Queue<EventPtr> _queue;
	};
}
