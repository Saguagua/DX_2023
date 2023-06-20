#pragma once

class Sprite
{
public:
	Sprite(wstring path);
	Sprite(wstring path, Vector2 size);
	~Sprite() {}

	void Render();
	void Update();

	void SetCurClip(Action::Clip clip);

	void SetRight() { _rBuffer->SetSlot1(0); }
	void SetLeft() { _rBuffer->SetSlot1(1); }
	void SetFront(int val) { _rBuffer->SetSlot1(val); }
	
	int GetFront() { return _rBuffer->GetSlot1(); }
	Vector2 GetClipSize() { return _aBuffer->GetClipSize(); }

private:
	void CreateVertices();
	void CreateData(wstring path);

	vector<int> _indices;
	vector<Vertex_Texture> _vertices;

	shared_ptr<VertexBuffer> _vBuffer;
	shared_ptr<IndexBuffer> _iBuffer;
	shared_ptr<ActionBuffer> _aBuffer;
	shared_ptr<IntBuffer> _rBuffer;

	weak_ptr<SRV> _srv;
	weak_ptr<PixelShader> _ps;
	weak_ptr<VertexShader> _vs;

	Vector2 _size;
};
