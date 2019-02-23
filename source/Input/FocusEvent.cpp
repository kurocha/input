//
//  FocusEvent.cpp
//  This file is part of the "Input" project and released under the MIT License.
//
//  Created by Samuel Williams on 24/2/2019.
//  Copyright, 2019, by Samuel Williams. All rights reserved.
//

#include "FocusEvent.hpp"

#include "Handler.hpp"

namespace Input
{
	FocusEvent::~FocusEvent()
	{
	}
	
	bool FocusEvent::apply(Handler & handler) const
	{
		return handler.process(*this);
	}
}
