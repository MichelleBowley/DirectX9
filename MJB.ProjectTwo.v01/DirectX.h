#ifndef _DIRECTX_H_
#define _DIRECTX_H_
#include <d3d9.h>
#pragma comment (lib,"d3d9.lib")

class DirectX
{
public:
	DirectX();
	~DirectX();

	void InitDx(HWND hw, int w, int h, bool fs);
	void initD3pp();
	HRESULT PresentBB();

	void Clear(D3DCOLOR backColour);
	void Begin();
	void End();

private:

	LPDIRECT3D9 d3d9;
	LPDIRECT3DDEVICE9 d3d9_Device;
	D3DPRESENT_PARAMETERS d3dpp;
	HRESULT res;

	int width;
	int height;
	bool fullscreen;
	HWND hWindow;
	
};
#endif //!_DIRECTX_H_