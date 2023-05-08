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
#include <queue>
#include <stack>
#include <string>
#include <time.h>
#include <algorithm>

using namespace std;

// Math
#include "Math/Vector2.h"
#include "Math/DisjointSet.h"
#include "Math/Collider.h"
#include "Math/Line.h"
#include "Math/CircleCollider.h"
#include "Math/RectangleCollider.h"

// Object
#include "Object/Bullet.h"
#include "Object/Tank.h"
#include "Object/Maze/MazeBlock.h"
#include "Object/Maze/Maze.h"
#include "Object/Maze/Player.h"

// Scene
#include "Scene/Scene.h"

// Program
#include "Program/Program.h"

#include "Types.h"

extern Vector2 mousePos;
extern HWND hWnd;