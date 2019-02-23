//
//  Handler.cpp
//  This file is part of the "Input" project and released under the MIT License.
//
//  Created by Samuel Williams on 23/2/2019.
//  Copyright, 2019, by Samuel Williams. All rights reserved.
//

#include "Handler.hpp"

#include "Event.hpp"

namespace Input
{
	Handler::~Handler()
	{
	}
	
	bool Handler::process(const Event & event)
	{
		return event.apply(*this);
	}
}
