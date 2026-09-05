#pragma once
#include "Core.h"

namespace dx3d {
	class Rect {
	public:
		Rect() = default;
		//two types of constructors one with just width and height and then one where all need to be set
		Rect(i32 width, i32 height): left(0), top(0),width(width),height(height) {}
		Rect(i32 left, i32 top,i32 width, i32 height) : left(left), top(top), width(width), height(height) {}
	public:
		i32 left{}, top{}, width{}, height{};
	};
}