//
//  Gesture.hpp
//  This file is part of the "Input" project, and is released under the MIT License.
//
//  Created by Samuel Williams on 29/04/09.
//  Copyright, 2009, by Samuel Williams. All rights reserved.
//

#pragma once

#include <unordered_map>
#include <vector>

#include <Numerics/Vector.h>

namespace Input
{
	using Numerics::Vec3;

	typedef std::intptr_t FingerID;

	struct FingerTracking {
		Vec3 position;
		Vec3 motion;

		ButtonT button;
	};

	class MultiFingerInput {
	protected:
		typedef std::unordered_map<FingerID, FingerTracking> FingersMap;
		FingersMap _fingers;

		std::vector<ButtonT> _free_buttons;
		ButtonT _top;

		ButtonT allocate_button ();
		void release_button(ButtonT);

	public:
		MultiFingerInput ();

		const FingerTracking & begin_motion (FingerID finger, Vec3 position);
		const FingerTracking & update_motion (FingerID finger, Vec3 position);
		const FingerTracking finish_motion (FingerID finger, Vec3 position);
	};
}
