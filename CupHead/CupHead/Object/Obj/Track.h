#pragma once
class Track
{
public:
	Track(Vector2 size);
	~Track() {}

	void Render();
	void Update();
	void PostRender();
	shared_ptr<RectCollider> GetCollider() { return _col; }

private:
	shared_ptr<Quad> _quad;
	shared_ptr<Transform> _transform;
	shared_ptr<RectCollider> _col;
	shared_ptr<FilterBuffer> _fBuffer;
};

