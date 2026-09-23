#pragma once
#include "GraphicsResource.h"


namespace dx3d {


	class ShaderBinary final: public GraphicsResource
	{
	public:
		ShaderBinary(const ShaderCompilerDesc& desc,const GraphicsResourceDesc& gDesc);
	private:
		Microsoft::WRL::ComPtr<ID3DBlob> m_blob{};
	};
}
