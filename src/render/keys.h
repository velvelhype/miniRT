/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akito <akito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:33:54 by akito             #+#    #+#             */
/*   Updated: 2022/05/21 12:17:11 by akito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

// Key codes
// which is placed in /usr/include/X11/keysymdef.h
typedef enum e_key
{
	ESCAPE = 0xff1b,
	KEY_A = 0x0061,
	KEY_B = 0x0062,
	KEY_C = 0x0063,
	KEY_D = 0x0064,
	KEY_E = 0x0065,
	KEY_F = 0x0066,
	KEY_G = 0x0067,
	KEY_H = 0x0068,
	KEY_I = 0x0069,
	KEY_J = 0x006a,
	KEY_K = 0x006b,
	KEY_L = 0x006c,
	KEY_M = 0x006d,
	KEY_N = 0x006e,
	KEY_O = 0x006f,
	KEY_P = 0x0070,
	KEY_Q = 0x0071,
	KEY_R = 0x0072,
	KEY_S = 0x0073,
	KEY_T = 0x0074,
	KEY_U = 0x0075,
	KEY_V = 0x0076,
	KEY_W = 0x0077,
	KEY_X = 0x0078,
	KEY_Y = 0x0079,
	KEY_Z = 0x007a
}	t_key;

typedef enum e_mouse_button
{
	MOUSE_LIGHT_CLICK = 1,
	MOUSE_SCROLL_UP = 4,
	MOUSE_SCROLL_DOWN = 5,
	ARROW_LEFT = 65361,
	ARROW_RIGHT = 65363,
	ARROW_DOWN = 65364,
	ARROW_UP = 65362,
	BUTTON_PLUS = 59,
	BUTTON_MINUS = 45,
	BUTTON_LESS = 44,
	BUTTON_MORE = 46,
	BUTTON_ESC = 65307,
	BUTTON_1 = 49,
	BUTTON_2 = 50,
	BUTTON_3 = 51,
	BUTTON_7 = 55,
	BUTTON_8 = 56,
	BUTTON_9 = 57,
	BUTTON_I = 105,
	BUTTON_P = 112
}	t_mouse_button;

// EventMasks
// which is placed in /usr/include/X11/X.h
// ref: https://xjman.dsl.gr.jp/X11R6/X11/CH10.html
typedef enum e_event_mask
{
	NoEventMask = 0L,
	KeyPressMask = (1L << 0),
	KeyReleaseMask = (1L << 1),
	ButtonPressMask = (1L << 2),
	ButtonReleaseMask = (1L << 3),
	EnterWindowMask = (1L << 4),
	LeaveWindowMask = (1L << 5),
	PointerMotionMask = (1L << 6),
	PointerMotionHintMask = (1L << 7),
	Button1MotionMask = (1L << 8),
	Button2MotionMask = (1L << 9),
	Button3MotionMask = (1L << 10),
	Button4MotionMask = (1L << 11),
	Button5MotionMask = (1L << 12),
	ButtonMotionMask = (1L << 13),
	KeymapStateMask = (1L << 14),
	ExposureMask = (1L << 15),
	VisibilityChangeMask = (1L << 16),
	StructureNotifyMask = (1L << 17),
	ResizeRedirectMask = (1L << 18),
	SubstructureNotifyMask = (1L << 19),
	SubstructureRedirectMask = (1L << 20),
	FocusChangeMask = (1L << 21),
	PropertyChangeMask = (1L << 22),
	ColormapChangeMask = (1L << 23),
	OwnerGrabButtonMask = (1L << 24)
}	t_event_mask;

typedef enum e_event_type
{
	KeyPress = 2,
	KeyRelease = 3,
	ButtonPress = 4,
	ButtonRelease = 5,
	MotionNotify = 6,
	EnterNotify = 7,
	LeaveNotify = 8,
	FocusIn = 9,
	FocusOut = 10,
	KeymapNotify = 11,
	Expose = 12,
	GraphicsExpose = 13,
	NoExpose = 14,
	VisibilityNotify = 15,
	CreateNotify = 16,
	DestroyNotify = 17,
	UnmapNotify = 18,
	MapNotify = 19,
	MapRequest = 20,
	ReparentNotify = 21,
	ConfigureNotify = 22,
	ConfigureRequest = 23,
	GravityNotify = 24,
	ResizeRequest = 25,
	CirculateNotify = 26,
	CirculateRequest = 27,
	PropertyNotify = 28,
	SelectionClear = 29,
	SelectionRequest = 30,
	SelectionNotify = 31,
	ColormapNotify = 32,
	ClientMessage = 33,
	MappingNotify = 34,
	GenericEvent = 35,
	LASTEvent = 36
}	t_event_type;

#endif
