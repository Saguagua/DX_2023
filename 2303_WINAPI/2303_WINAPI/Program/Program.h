#pragma once
class Program
{
public:
	Program();
	~Program();

	void Update();
	void Render(HDC hdc);

	static HDC backBuffer;

private:
	shared_ptr<Scene> _scene;
	
	HBITMAP hBit;
};

