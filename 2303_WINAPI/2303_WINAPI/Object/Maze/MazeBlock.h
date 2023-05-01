#pragma once
class MazeBlock
{
public:
	enum class BlockType
	{
		DISABLE,
		ABLE,
		END,
		PLAYER,
		CURRENT,
		SHORTCUT,
		NONE
	};

	MazeBlock();
	~MazeBlock();

	void Update();
	void Render(HDC hdc);

	void SetPos(Vector2 pos) { _block->SetCenter(pos); }
	void SetType(MazeBlock::BlockType type) { _type = type; }
	MazeBlock::BlockType GetType() { return _type; }

private:
	shared_ptr<RectangleCollider> _block;
	BlockType _type = BlockType::NONE;

	vector<HBRUSH> _brushes;
};

