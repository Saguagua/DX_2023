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
	shared_ptr<Bow> _bow;
	shared_ptr<Planet> _sun;
	shared_ptr<Bullet> _bullet;
};

