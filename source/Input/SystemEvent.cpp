//
//  SystemEvent.cpp
//  This file is part of the "Input" project and released under the MIT License.
//
//  Created by Samuel Williams on 23/2/2019.
//  Copyright, 2019, by Samuel Williams. All rights reserved.
//

#include "SystemEvent.hpp"

#include "Handler.hpp"

namespace Input
{
	SystemEvent::~SystemEvent()
	{
	}
	
	bool SystemEvent::apply(Handler & handler) const
	{
		return handler.process(*this);
	}
}
