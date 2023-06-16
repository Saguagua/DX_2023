#pragma once
class ShaderManager
{
private:
	ShaderManager() {}
	~ShaderManager() {}

public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new ShaderManager();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static ShaderManager* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;
		return _instance;
	}

	shared_ptr<VertexShader> Add_VertexShader(wstring path)
	{
		if (_shaderTable.count(path) != 0)
			return dynamic_pointer_cast<VertexShader>(_shaderTable[path]);

		shared_ptr<VertexShader> vs = make_shared<VertexShader>(path);
		_shaderTable[path] = vs;

		return vs;
	}

	shared_ptr<PixelShader> AddPixelShader(wstring path)
	{
		if (_shaderTable.count(path) != 0)
			return dynamic_pointer_cast<PixelShader>(_shaderTable[path]);

		shared_ptr<PixelShader> ps = make_shared<PixelShader>(path);
		_shaderTable[path] = ps;

		return ps;
	}

private:
	static ShaderManager* _instance;
	unordered_map<wstring, shared_ptr<Shader>> _shaderTable;
};

