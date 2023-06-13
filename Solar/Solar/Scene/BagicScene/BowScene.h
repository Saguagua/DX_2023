#pragma once
class BowScene: public Scene
{
public:
	BowScene();
	~BowScene();
	
	virtual void Update() override;
	virtual void Render() override;

private:
	void SpawnMonsters();

	shared_ptr<Character> _player;
	shared_ptr<Planet> _sun;
	shared_ptr<CircleCollider> _object;
	shared_ptr<Quad> _stage;
	vector<shared_ptr<class Monster>> _monsters;

	double _spawnTimer = 0.0;
};

