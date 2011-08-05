// Пример использования dxut_wonly
//
//#include "stdafx.h"

#include <d3dx9.h>
#include  "e:/!dapplLibr2/dappllibr/dapplLibr/dxut_wonly/dxut_wonly.h"

#include "E:/ksd3d9ut/ksd3d9ut/ksd3d9ut/draw/draw.h"

#include <gbmath/_gbmath.h>
using namespace gbmath;

gbmath::model_view_camera g_camera;

// library d3d9
#pragma comment( lib, "d3d9.lib" )

#include <dxerr.h>
#pragma comment( lib, "dxerr.lib" )

// library win32 
#pragma comment( lib, "winmm.lib" )
#pragma comment( lib, "comctl32.lib" )
#pragma comment( lib, "netapi32.lib" )
#include <mmsystem.h>
#include <mmreg.h>


 

//--------------------------------------------------------------------------------------
// Rejects any devices that aren't acceptable by returning false
//--------------------------------------------------------------------------------------
bool CALLBACK IsDeviceAcceptable( D3DCAPS9* pCaps, D3DFORMAT AdapterFormat, 
								 D3DFORMAT BackBufferFormat, bool bWindowed, void* pUserContext )
{
	// Typically want to skip backbuffer formats that don't support alpha blending
	IDirect3D9* pD3D = DXUTGetD3DObject(); 
	if( FAILED( pD3D->CheckDeviceFormat( pCaps->AdapterOrdinal, pCaps->DeviceType,
		AdapterFormat, D3DUSAGE_QUERY_POSTPIXELSHADER_BLENDING, 
		D3DRTYPE_TEXTURE, BackBufferFormat ) ) )
		return false;

	return true;
}


//--------------------------------------------------------------------------------------
// Before a device is created, modify the device settings as needed
//--------------------------------------------------------------------------------------
bool CALLBACK ModifyDeviceSettings( DXUTDeviceSettings* pDeviceSettings, 
								   const D3DCAPS9* pCaps, void* pUserContext )
{
	return true;
}


//--------------------------------------------------------------------------------------
// Create any D3DPOOL_MANAGED resources here 
//--------------------------------------------------------------------------------------
HRESULT CALLBACK OnCreateDevice( IDirect3DDevice9* pd3dDevice, const D3DSURFACE_DESC* pBackBufferSurfaceDesc, void* pUserContext )
{


   g_camera.setViewParams(vec3(5.0f,0.0f,0.0f) , vec3(0.0f,-0.0f,0.0f) );

	return S_OK;
}


//--------------------------------------------------------------------------------------
// Create any D3DPOOL_DEFAULT resources here 
//--------------------------------------------------------------------------------------
HRESULT CALLBACK OnResetDevice( IDirect3DDevice9* pd3dDevice, 
							   const D3DSURFACE_DESC* pBackBufferSurfaceDesc, void* pUserContext )
{



   g_camera.setProjParams( 3.14f/4.0f, 1.0f, 0.1f , 100.0f   );
	return S_OK;
}


//--------------------------------------------------------------------------------------
// Handle updates to the scene
//--------------------------------------------------------------------------------------
void CALLBACK OnFrameMove( IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext )
{
  g_camera.frameMove(1000.0f);

}


//--------------------------------------------------------------------------------------
// Render the scene 
//--------------------------------------------------------------------------------------
void CALLBACK OnFrameRender( IDirect3DDevice9* pd3dDevice, double fTime, float fElapsedTime, void* pUserContext )
{
	HRESULT hr;

	// Clear the render target and the zbuffer 
	V( pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_ARGB(0, 45, 50, 170), 1.0f, 0) );

	// Render the scene
	if( SUCCEEDED( pd3dDevice->BeginScene() ) )
	{
	
	//g_camera.makeCurrent( pd3dDevice );
	//hr |= pDevice->SetTransform( D3DTS_WORLD ,      getWorldMatrix()  );
 

	hr |= pd3dDevice->SetTransform(D3DTS_VIEW ,        g_camera.getViewMatrix()  );
	hr |= pd3dDevice->SetTransform(D3DTS_PROJECTION ,  g_camera.getProjMatrix()   );
	
	ksd3d9ut::draw::drawMeshPrimitiveCube1x1Mem(pd3dDevice);
	
	
	
		V( pd3dDevice->EndScene() );
	}
}


//--------------------------------------------------------------------------------------
// Handle messages to the application 
//--------------------------------------------------------------------------------------
LRESULT CALLBACK MsgProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, 
						 bool* pbNoFurtherProcessing, void* pUserContext )
{

	g_camera.handleMessages(hWnd,   uMsg,   wParam,   lParam);


	return 0;
}


//--------------------------------------------------------------------------------------
// Release resources created in the OnResetDevice callback here 
//--------------------------------------------------------------------------------------
void CALLBACK OnLostDevice( void* pUserContext )
{


}


//--------------------------------------------------------------------------------------
// Release resources created in the OnCreateDevice callback here
//--------------------------------------------------------------------------------------
void CALLBACK OnDestroyDevice( void* pUserContext )
{


}



//--------------------------------------------------------------------------------------
// Initialize everything and go into a render loop
//--------------------------------------------------------------------------------------
//INT WINAPI WinMain( HINSTANCE, HINSTANCE, LPSTR, int )
int WINAPI WinMain(	HINSTANCE	hInstance,			// Instance
				   HINSTANCE	hPrevInstance,		// Previous Instance
				   LPSTR		lpCmdLine,			// Command Line Parameters
				   int			nCmdShow)			// Window Show State
{
 

	// Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif

	// Set the callback functions
	DXUTSetCallbackDeviceCreated( OnCreateDevice );
	DXUTSetCallbackDeviceReset( OnResetDevice );
	DXUTSetCallbackDeviceLost( OnLostDevice );
	DXUTSetCallbackDeviceDestroyed( OnDestroyDevice );
	DXUTSetCallbackMsgProc( MsgProc );
	DXUTSetCallbackFrameRender( OnFrameRender );
	DXUTSetCallbackFrameMove( OnFrameMove );

	// TODO: Perform any application-level initialization here

	// Initialize DXUT and create the desired Win32 window and Direct3D device for the application
	DXUTInit( true, true, true ); // Parse the command line, handle the default hotkeys, and show msgboxes
	DXUTSetCursorSettings( true, true ); // Show the cursor and clip it when in full screen
	DXUTCreateWindow( L"EmptyProject" );
	DXUTCreateDevice( D3DADAPTER_DEFAULT, true, 640, 480, IsDeviceAcceptable, ModifyDeviceSettings );

	// Start the render loop
	DXUTMainLoop();

	// TODO: Perform any application-level cleanup here

	return DXUTGetExitCode();
}


