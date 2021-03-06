#pragma once

#include <vector>

#ifdef _WIN32
#ifdef _LIB_DYNAMIC
#define DLL_EXPORT __declspec( dllexport )
#else
#define DLL_EXPORT 
#endif
#endif

namespace BrokenBytes::ControllerKit {
	struct Color {
		uint8_t R;
		uint8_t G;
		uint8_t B;
	};

	enum class Feature {
		Rumble,
		Gyroscope,
		Lightbar,
		AdaptiveTriggers,
		ImpulseTriggers,
		Touchpad
	};
	
	enum class ButtonState {
		Down,
		Pressed,
		Up,
		Released
	};

	enum class DPadDirection {
		None,
		Left,
		LeftUp,
		Up,
		RightUp,
		Right,
		RightDown,
		Down,
		LeftDown
	};

	enum class Trigger {
		Left,
		Right
	};

	enum class Rumble {
		Left,
		Right
	};

	enum class ControllerType {
		XBoxOne,
		XBoxSeries,
		DualShock4,
		DualSense,
		Generic
	};
	
	enum class Axis {
		LeftX,
		LeftY,
		RightX,
		RightY,
		LeftTrigger,
		RightTrigger
	};

	enum class Button {
		Button0, Cross, A = 0,
		Button1, Square, X = 1,
		Button2, Circle, B = 2,
		Button3, Triangle, Y = 3,
		Button4, L1, LB = 4,
		Button5, R1, RB = 5,
		Button6, L2, LT = 6,
		Button7, R2, RT = 7,
		Button8, Share, Create, View = 8,
		Button9, Options, Menu = 9,
		Button10, L3 = 10,
		Button11, R3 = 11,
		Button12, PS, XBox = 12,
		Button13, TouchPad, XBox_Share = 13,
		Button14, PS_MUTE = 14,
		Button15 = 15,
		Button16 = 16
	};

	enum class AdaptiveTriggerMode {
		Disabled = 0x00,
		Continuous = 0x01,
		Sectional = 0x02,
		ContinuousAdvanced = 0x25,
		SectionalAdvanced = 0x26
	};


	DLL_EXPORT void Init();
	DLL_EXPORT bool HasFeature(uint8_t controller, Feature feature);
	DLL_EXPORT ButtonState GetButtonState(int controller, Button button);
	DLL_EXPORT float GetAxis(int controller, Axis axis);
	DLL_EXPORT ControllerType GetControllerType(int controller);
}
