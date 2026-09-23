#pragma once
#include "Common.h"

namespace dx3d {

	namespace GraphicsUtils {
		//lets this function be included in mutliple locations using inline
		inline const char* getShaderModelTarget(ShaderType type)
		{
			switch (type) {
				//vertex shader and the version
			case ShaderType::VertexShader: return "vs_5_0";
			case ShaderType::PixelShader: return "ps_5_0";
			default: return "";
			}
		}
	}
}
