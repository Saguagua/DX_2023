#include <iostream>
#include <vector>

using namespace std;

// {1 2 8 5 3 7 10}

//�κ� ���� : ������ ������� ������ �´� �κ� ����
//{1 2 8}
// {1 8 7}
//�κ� ���� ���� : �κ� �����̸� ������ �����ϴ� ����
//{1 5 7}
//���� �κ� ���� ���� : �κ� ���� ���� �� ���̰� ���� �� ��
//{1 2 5 7 10}
// {1 2 3 7 10}

//1 : 5
//2 : 4
//3 : 1
//4 : 2
//5 : 1
//6 : 0

vector<int> v1 = {1, 2, 8, 3, 7, 10};
vector<int> v2 = {5, 6, 7, 8, 1, 2, 3};

//1 : 6
//2 : 2
//3 : 1
//4 : 0
//5 : 2
//6 : 1
//7 : 0

//�ɰ��� �ش� �ε��������� ���� �κ� ���� ������ ���ϸ� �ȴ�.
//������ ��� ���ұ�

//�� ���ڸ��� �ڽź��� �� ū ���ڰ� �� ������ ī��Ʈ

//for������ �Ѿ ���ڰ� ����, �ڽź��� ū ���� ã��(�Ѿ ���ڰ� ���ٸ� �� �� ���� �ɷ�)
vector<int> cache = vector<int>(v1.size(), -1);
vector<int> countAll = vector<int>(v1.size(), -1);
int target = v1.size();

int LIS(int index)
{
	if (v1[index] < v1[index + 1])
		return 1;
	
	if (cache[index] != -1)
		return cache[index];
	
	cache[index] = LIS(index - 1) + 1;
		
}


int main()
{
	for (int i = 0; i < v1.size(); i++)
	{
		for (int j = i + 1; j < v1.size(); j++)
		{
			if (v1[i] < v1[j])
				countAll[i]++;
		}
	}
	
	int answer = LIS(v1.size());
	cout << answer << endl;

	return 0;
}