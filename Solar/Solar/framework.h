﻿// header.h: 표준 시스템 포함 파일
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
#include <time.h>
#include <tchar.h>
#include <memory>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <wrl/client.h>

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dcompiler.lib")

#include "../DXTex/DirectXTex.h"

#include "../ImGui/imgui.h"
#include "../ImGUI/imgui_impl_dx11.h"
#include "../ImGUI/imgui_impl_win32.h"

using namespace std;
using namespace DirectX;
using namespace Microsoft::WRL;

// Framework
#include "Framework/Device/Device.h"

// Math
#include "Framework/Math/Vector2.h"
#include "Framework/Math/Transform.h"

// Utility
#include "Framework/Utility/InputManager.h"
#include "Framework/Utility/Timer.h"

// Render
#include "Framework/Render/ConstantBuffer.h"
#include "Framework/Render/GlobalBuffer.h"
#include "Framework/Render/VertexLayout.h"
#include "Framework/Render/VertexBuffer.h"
#include "Framework/Render/IndexBuffer.h"
#include "Framework/Render/VertexShader.h"
#include "Framework/Render/PixelShader.h"

// TextureMapping
#include "Framework/TextureMapping/SRV.h"
#include "Framework/TextureMapping/SRVManager.h"
#include "Framework/TextureMapping/SamplerState.h"
#include "Framework/TextureMapping/BlendState.h"
#include "Framework/TextureMapping/StateManager.h"

// Collider
#include "Framework/Collider/Collider.h"
#include "Framework/Collider/CircleCollider.h"
#include "Framework/Collider/RectCollider.h"

// Animation
#include "Framework/Animation/Action.h"

// Obj
#include "Object/BagicObject/Quad.h"
#include "Object/BagicObject/Sprite.h"

// GameObj
#include "Object/Obj/Planet.h"
#include "Object/Obj/Character.h"
#include "Object/Obj/Monster.h"
#include "Object/Obj/Bow.h"
#include "Object/Obj/Bullet.h"
#include "Object/Obj/Vible.h"

// Scene
#include "Scene/Scene.h"

// Program
#include "Program/Program.h"

#include "Types.h"

extern HWND hWnd;
extern Vector2 mousePos;