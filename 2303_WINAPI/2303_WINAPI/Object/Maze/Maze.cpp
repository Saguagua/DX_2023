#include "framework.h"
#include "Maze.h"

Maze::Maze()
{
	Vector2 start = {400, 100};

	_blocks.resize(_mazeHeight);
	for (int i = 0; i < _blocks.size(); i++)
	{
		_blocks[i].reserve(_mazeWidth);
		for (int j = 0; j < _blocks.size(); j++)
		{
			shared_ptr<MazeBlock> block = make_shared<MazeBlock>();
			block->SetPos(start + Vector2(17 * j, 17 * i));
			block->SetType(MazeBlock::BlockType::DISABLE);
			_blocks[i].push_back(block);
		}
	}

	CreateMaze_Kruskal();
}

Maze::~Maze()
{
}

void Maze::Update()
{
	for (auto block : _blocks)
	{
		for (int j = 0; j < block.size(); j++)
			block[j]->Update();
	}
}

void Maze::Render(HDC hdc)
{
	for (int i = 0; i < _blocks.size(); i++)
	{
		for (int j = 0; j < _blocks[i].size(); j++)
			_blocks[i][j]->Render(hdc);
	}
}

void Maze::CreateMaze()
{
	for (int i = 0; i < _mazeHeight; i++)
	{
		for (int j = 0; j < _mazeWidth; j++)
		{
			if (i % 2 == 0 || j % 2 == 0)
				continue;
			_blocks[i][j]->SetType(MazeBlock::BlockType::ABLE);
		}
	}

	for (int i = 0; i < _mazeHeight; i++)
	{
		for (int j = 0; j < _mazeWidth; j++)
		{
			if (i % 2 == 0 || j % 2 == 0)
				continue;

			if (i == _mazeHeight - 2 && j == _mazeWidth - 2)
				continue;

			if (i == _mazeHeight - 2) 
			{
				_blocks[i][j + 1]->SetType(MazeBlock::BlockType::ABLE);
				continue;
			}
			if (j == _mazeWidth - 2)
			{
				_blocks[i + 1][j]->SetType(MazeBlock::BlockType::ABLE);
				continue;
			}

			int randNum = rand() % 2;
			if (randNum == 0)
				_blocks[i+1][j]->SetType(MazeBlock::BlockType::ABLE);

			else
				_blocks[i][j+1]->SetType(MazeBlock::BlockType::ABLE);
		}
	}

	_blocks[_mazeHeight - 2][_mazeWidth - 2]->SetType(MazeBlock::BlockType::END);
}

void Maze::CreateMaze_Kruskal()
{

	for (int i = 0; i < _mazeHeight; i++)
	{
		for (int j = 0; j < _mazeWidth; j++)
		{
			if (i % 2 == 0 || j % 2 == 0)
				continue;
			_blocks[i][j]->SetType(MazeBlock::BlockType::ABLE);
		}
	}

	for (int i = 0; i < _mazeHeight; i++)
	{
		for (int j = 0; j < _mazeWidth; j++)
		{
			if (i % 2 == 0 || j % 2 == 0)
				continue;
			_blocks[i][j]->SetType(MazeBlock::BlockType::ABLE);
		}
	}

	for (int i = 1; i < _mazeHeight; i+=2)
	{
		for (int j = 1; j < _mazeWidth; j+=2)
		{
			for (int i = 0; i < 4; i++)
			{
				Vector2 nextBlock = Vector2(i, j) + frontPos[i];
				if (nextBlock.x >= _mazeWidth || nextBlock.y >= _mazeHeight)
					continue;
				Edge edge;
				edge.u = Vector2(i, j);
				edge.v = nextBlock;
				edge.cost = rand() % 10000;
				edges.push_back(edge);
			}
		}
	}

	std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b)->bool
	{
		return a.cost < b.cost;
	}
	);

	DisJointSet sets(25, 25);

	for (auto edge : edges)
	{
		if (sets.FindLeader(edge.u) == sets.FindLeader(edge.v))
			continue;

		sets.Merge(edge.vertexU, edge.vertexV);
		result.push_back(edge);
	}

}
