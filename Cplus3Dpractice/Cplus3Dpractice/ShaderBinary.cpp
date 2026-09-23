#include "ShaderBinary.h"
#include "GraphicsUtils.h"
#include <d3dcompiler.h>

dx3d::ShaderBinary::ShaderBinary(const ShaderCompilerDesc& desc, const GraphicsResourceDesc& gDesc): 
	GraphicsResource(gDesc)
{
	UINT compileFlags{};

#ifdef _DEBUG
	compileFlags |= D3DCOMPILE_DEBUG;
#endif // _DEBUG


	Microsoft::WRL::ComPtr<ID3DBlob> errorBlob{};
	//some of the variables are optional or not needed for what we are doing
	D3DCompile(
		desc.shaderSourceCode,
		desc.shaderSourceCodeSize,
		desc.shaderSourceName,
		nullptr,
		nullptr,
		desc.shaderEntryPoint,
		dx3d::GraphicsUtils::getShaderModelTarget(desc.shaderType),
		compileFlags,
		0,
		&m_blob,
		&errorBlob
	);

}
