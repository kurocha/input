//
//  ResizeEvent.cpp
//  This file is part of the "Input" project and released under the MIT License.
//
//  Created by Samuel Williams on 23/2/2019.
//  Copyright, 2019, by Samuel Williams. All rights reserved.
//

#include "ResizeEvent.hpp"

#include "Handler.hpp"

namespace Input
{
	ResizeEvent::~ResizeEvent()
	{
	}
	
	bool ResizeEvent::apply(Handler & handler) const
	{
		return handler.process(*this);
	}
}
