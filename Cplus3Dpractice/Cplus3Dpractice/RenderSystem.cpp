#include "RenderSystem.h"



dx3d::RenderSystem::RenderSystem(const RenderSystemDesc& desc): Base(desc.base)
{
	D3D_FEATURE_LEVEL featureLevel{};

	UINT createDeviceFlags{};
#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	//used for all the graphics rendered to the window
	//the ID3D11device part handles feeatures textures shaders etc
	//device context is similar to how the device is also handled
	//you could include an invalid value in here such as -1 after the null to purposely hit the log message
	auto hr = D3D11CreateDevice(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, NULL, 0, D3D11_SDK_VERSION,
		&m_d3dDevice, &featureLevel, &m_d3dContext);
	if (FAILED(hr)) {
		getLogger().log(Logger::LogLevel::Error, "Direct3D11 initialization failed ");
		throw std::runtime_error("Direct3D11 initialization failed");
	}
}

dx3d::RenderSystem::~RenderSystem()
{
}
