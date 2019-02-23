//
//  MotionEvent.cpp
//  This file is part of the "Input" project and released under the MIT License.
//
//  Created by Samuel Williams on 23/2/2019.
//  Copyright, 2019, by Samuel Williams. All rights reserved.
//

#include <UnitTest/UnitTest.hpp>

#include <Input/MotionEvent.hpp>

namespace Input
{
	using namespace UnitTest::Expectations;
	
	UnitTest::Suite MotionEventTestSuite {
		"Input::MotionEvent",
		
		{"it can report left mouse button pressed",
			[](UnitTest::Examiner & examiner) {
				MotionEvent event(Time::Interval(), {DefaultMouse, MouseLeftButton}, Pressed, {10, 10}, {5, 10}, {{0, 0}, {100, 100}});
				
				examiner.expect(event.button_pressed(MouseLeftButton)).to(be_true);
				examiner.expect(event.button_pressed(MouseRightButton)).to(be_false);
			}
		},
	};
}
