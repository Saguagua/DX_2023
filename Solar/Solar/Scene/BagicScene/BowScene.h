#pragma once
class BowScene: public Scene
{
public:
	BowScene();
	~BowScene();
	
	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<Character> _player;
	shared_ptr<Planet> _sun;
	shared_ptr<CircleCollider> _object;

	vector<shared_ptr<Bullet>> _bullet;

	double _timer = 0.0;
};

