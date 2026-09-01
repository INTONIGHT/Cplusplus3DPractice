#pragma once
#include "Base.h"
#include <d3d11.h>
#include <wrl.h>
#include "Core.h"

namespace dx3d {


	class RenderSystem final : public Base
	{
	public:
		RenderSystem();
		virtual ~RenderSystem() override;
	private:
		Microsoft::WRL::ComPtr<ID3D11Device> m_d3dDevice{};
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_d3dContext{};
	};

}