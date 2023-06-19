#include "framework.h"
#include "Track.h"

Track::Track(Vector2 size)
{
	wstring path = L"Resource/Background/clown_bg_track.png";
	_quad = make_shared<Quad>(path, size);
	_col = make_shared<RectCollider>(size - Vector2(0, 60));
	_transform = make_shared<Transform>();
	_transform->SetPos(Vector2(0, 20));
	_transform->SetParent(_col->GetTransform());
}

void Track::Render()
{
	_transform->Set_World(0);
	_quad->Render();
	_col->Render();
}

void Track::Update()
{
	_transform->Update();
	_col->Update();
}
