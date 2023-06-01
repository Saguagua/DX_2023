// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <memory>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <wrl/client.h> //COM 개체 생성

#include <d3d11.h> 
//DirectX 11 API를 정의하는 헤더파일
#include <d3dcompiler.h>
//DirectX 컴파일러를 사용하기 위한 헤더파일
//셰이더를 컴파일할 수 있게 된다. 
#include <DirectXMath.h>
//3D 수학 연산을 효율적으로 처리하기 위한 고성능 수학 라이브러리

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dcompiler.lib")
//컴파일러에게 특정 라이브러리 파일을 링크하도록 지시
//d3d11.lib : DX11 api를 제공하는 라이브러리
//d3dcompiler.lib DX셰이더 컴파일러를 사용하기 위한 라이브러리 파일(셰이더 코드를 컴파일하고 로드할 수 있다.)

#include "../DXTex/DirectXTex.h"

using namespace std;
using namespace DirectX;
using namespace Microsoft::WRL;

//Math
#include "Framework/Math/Vector2.h"
#include "Framework/Math/Transform.h"

//Framework
#include "Framework/Device/Device.h"

//Render
#include "Framework/Render/ConstantBuffer.h"
#include "Framework/Render/GlobalBuffer.h"
#include "Framework/Render/VertexLayout.h"
#include "Framework/Render/VertexBuffer.h"
#include "Framework/Render/IndexBuffer.h"
#include "Framework/Render/VertexShader.h"
#include "Framework/Render/PixelShader.h"

//TextureMapping
#include "TextureMapping/SamplerState.h"
#include "TextureMapping/SRV.h"

//Obj
#include "Object/BasicObject/Quad.h"
#include "Object/BasicObject/Line.h"

//Scene
#include "Scene/Scene.h"

//Program
#include "Program/Program.h"

#include "Types.h"
extern HWND hWnd;