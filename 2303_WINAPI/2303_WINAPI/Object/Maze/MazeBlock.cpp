#include "framework.h"
#include "MazeBlock.h"

MazeBlock::MazeBlock()
{
	_block = make_shared < RectangleCollider > (Vector2(0, 0), Vector2(14, 14));
	HBRUSH disable = CreateSolidBrush(RED);
	HBRUSH able = CreateSolidBrush(GREEN);
	HBRUSH end = CreateSolidBrush(BLUE);
	HBRUSH player = CreateSolidBrush(GREY);
	HBRUSH current = CreateSolidBrush(WHITE);
	HBRUSH shortCut = CreateSolidBrush(BLACK);

	_brushes.push_back(disable);
	_brushes.push_back(able);
	_brushes.push_back(end);
	_brushes.push_back(player);
	_brushes.push_back(current);
	_brushes.push_back(shortCut);
}

MazeBlock::~MazeBlock()
{
	for (HBRUSH brush : _brushes)
		DeleteObject(brush);
}

void MazeBlock::Update()
{
	_block->Update();
}

void MazeBlock::Render(HDC hdc)
{
	if (_type == BlockType::NONE) return;

	SelectObject(hdc, _brushes[static_cast<unsigned int>(_type)]);
	_block->Render(hdc);
}
