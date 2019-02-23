//
//  ButtonEvent.cpp
//  This file is part of the "Input" project and released under the MIT License.
//
//  Created by Samuel Williams on 23/2/2019.
//  Copyright, 2019, by Samuel Williams. All rights reserved.
//

#include <UnitTest/UnitTest.hpp>

#include <Input/ButtonEvent.hpp>

namespace Input
{
	using namespace UnitTest::Expectations;
	
	UnitTest::Suite ButtonEventTestSuite {
		"Input::ButtonEvent",
		
		{"it can report the button was pressed",
			[](UnitTest::Examiner & examiner) {
				ButtonEvent event(Time::Interval(), {DefaultKeyboard, 'a'}, Pressed);
				
				examiner.expect(event.button_pressed('a')).to(be_true);
				examiner.expect(event.button_pressed('b')).to(be_false);
			}
		},
	};
}
