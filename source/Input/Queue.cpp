//
//  Queue.cpp
//  This file is part of the "Input" project and released under the MIT License.
//
//  Created by Samuel Williams on 23/2/2019.
//  Copyright, 2019, by Samuel Williams. All rights reserved.
//

#include "Queue.hpp"

namespace Input
{
	Queue::Queue()
	{
	}
	
	void Queue::dequeue(Handler & handler)
	{
		const auto & items = _queue.dequeue();
		
		for (auto & item : items) {
			handler.process(reinterpret_cast<const Event &>(item));
		}
	}
	
	bool Queue::process(const ResizeEvent & event)
	{
		_queue.emplace(std::make_unique<ResizeEvent>(event));
		
		return true;
	}
	
	bool Queue::process(const ButtonEvent & event)
	{
		_queue.emplace(std::make_unique<ButtonEvent>(event));
		
		return true;
	}
	
	bool Queue::process(const MotionEvent & event)
	{
		_queue.emplace(std::make_unique<MotionEvent>(event));
		
		return true;
	}
	
	bool Queue::process(const SystemEvent & event)
	{
		_queue.emplace(std::make_unique<SystemEvent>(event));
		
		return true;
	}
}
