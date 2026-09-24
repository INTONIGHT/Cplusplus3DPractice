#pragma once
#include "Logger.h"
#include <d3d11.h>



namespace dx3d {
	namespace GraphicsLogUtils {
		inline void CheckShaderCompile(Logger& logger, HRESULT hr, ID3DBlob* errorBlob) {
			//this will let us get anything if the errorBlob hasd any error messages
			auto errorMsg = errorBlob ? static_cast<const char*>(errorBlob->GetBufferPointer()) : nullptr;
			if (FAILED(hr)) {
				if (errorMsg) {
					DX3DLogThrow(logger, std::runtime_error, Logger::LogLevel::Error, errorMsg);
				}
				else {
					DX3DLogThrow(logger, std::runtime_error, Logger::LogLevel::Error, 
						"Shader Compilation Failed");
				}
			}
			//this is if there are any warnings
			if (errorMsg) {
				DX3DLog(logger, Logger::LogLevel::Warning, errorMsg);
			}
		}
	}
}

#define DX3DGraphicsLogThrowOnFail(hr,message)\
{\
	auto res = (hr);\
	if (FAILED(res)) {\
		DX3DLogThrowError(message);\
	}\
	}

#define DX3DGraphicsCheckShaderCompile(hr,errorBlob)\
{\
auto res = (hr);\
dx3d::GraphicsLogUtils::CheckShaderCompile(getLogger(),res,errorBlob);\
}