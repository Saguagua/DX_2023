#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <math.h>
#include <memory>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

// Math
#include "Math/Vector2.h"
#include "Math/Collider.h"
#include "Math/Line.h"
#include "Math/CircleCollider.h"
#include "Math/RectangleCollider.h"

// Object
#include "Object/Bullet.h"
#include "Object/Tank.h"

// Scene
#include "Scene/Scene.h"


// Program
#include "Program/Program.h"

#include "Types.h"

extern Vector2 mousePos;
extern HWND hWnd;