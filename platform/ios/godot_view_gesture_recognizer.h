<<<<<<<< HEAD:platform/macos/godot_button_view.h
/**************************************************************************/
/*  godot_button_view.h                                                   */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef GODOT_BUTTON_VIEW_H
#define GODOT_BUTTON_VIEW_H

#include "servers/display_server.h"

#import <AppKit/AppKit.h>
#import <Foundation/Foundation.h>

@interface GodotButtonView : NSView {
	NSTrackingArea *tracking_area;
	NSPoint offset;
	CGFloat spacing;
	bool mouse_in_group;
	bool rtl;
	NSButton *close_button;
	NSButton *miniaturize_button;
	NSButton *zoom_button;
}

- (void)initButtons:(CGFloat)button_spacing offset:(NSPoint)button_offset rtl:(bool)is_rtl;
- (void)displayButtons;
- (void)setOffset:(NSPoint)button_offset;
- (NSPoint)getOffset;

@end

#endif // GODOT_BUTTON_VIEW_H
========
/*************************************************************************/
/*  godot_view_gesture_recognizer.h                                      */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2022 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2022 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

// GodotViewGestureRecognizer allows iOS gestures to work correctly by
// emulating UIScrollView's UIScrollViewDelayedTouchesBeganGestureRecognizer.
// It catches all gestures incoming to UIView and delays them for 150ms
// (the same value used by UIScrollViewDelayedTouchesBeganGestureRecognizer)
// If touch cancellation or end message is fired it fires delayed
// begin touch immediately as well as last touch signal

#import <UIKit/UIKit.h>

@interface GodotViewGestureRecognizer : UIGestureRecognizer {
@private

	// Timer used to delay begin touch message.
	// Should work as simple emulation of UIDelayedAction
	NSTimer *delayTimer;

	// Delayed touch parameters
	NSSet *delayedTouches;
	UIEvent *delayedEvent;
}

@property(nonatomic, readonly, assign) NSTimeInterval delayTimeInterval;

- (instancetype)init;

@end
>>>>>>>> 6fed1ffa313c6760fa88b368ae580378daaef0f0:platform/ios/godot_view_gesture_recognizer.h
