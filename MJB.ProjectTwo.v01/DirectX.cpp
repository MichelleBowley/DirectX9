#include "DirectX.h"

DirectX::DirectX()
{
}

DirectX::~DirectX()
{
}

void
DirectX::InitDx(HWND hw, int w, int h, bool fs)
{
	//Initialse directx and its parameters.

	d3d9 = Direct3DCreate9(D3D_SDK_VERSION);
	if (d3d9 == NULL)
	{
		//If d3d9 fails a message box is displayed
		MessageBox(hw, "Failed on d3d9 initalisation", "Fail 1", MB_OK);
	}
	else
	{
		initD3pp();
		D3DCAPS9 caps;
		DWORD behavior;
		res = d3d9->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);
		if ((caps.DevCaps& D3DDEVCAPS_HWTRANSFORMANDLIGHT) == 0 || caps.VertexShaderVersion < D3DVS_VERSION(1, 1))
			behavior = D3DCREATE_SOFTWARE_VERTEXPROCESSING;  // use software only processing
		else
			behavior = D3DCREATE_HARDWARE_VERTEXPROCESSING;  // use hardware only processing
		res = d3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hw, behavior, &d3dpp, &d3d9_Device);
		if (FAILED(res))
			MessageBox(hw, "Failed to Create device", "Fail2", MB_OK);
	}

}

void
DirectX::initD3pp()
{
	//This code is fairly generic and shouldnt need to be changed
	//Initalise Presentation parameters
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.BackBufferWidth = width;
	d3dpp.BackBufferHeight = height;
	if (fullscreen)
		d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	else
		d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

	d3dpp.BackBufferCount = 1;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hWindow;
	d3dpp.Windowed = (!fullscreen);
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
}

HRESULT
DirectX::PresentBB()
{
	res = E_FAIL;
	d3d9_Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 0.0f, 0);
	res = d3d9_Device->Present(NULL, NULL, NULL, NULL);
	return res;
}

void
DirectX::Clear(D3DCOLOR backColour)
{
	d3d9_Device->Clear(0, NULL, D3DCLEAR_TARGET, backColour, 0.0f, 0);
}

void
DirectX::Begin()
{
	d3d9_Device->BeginScene();
}

void
DirectX::End()
{
	d3d9_Device->EndScene();
}