#pragma once
#include "Core.h"

namespace dx3d {
	class Rect {
	public:
		Rect() = default;
	public:
		i32 left{}, top{}, width{}, height{};
	};
}