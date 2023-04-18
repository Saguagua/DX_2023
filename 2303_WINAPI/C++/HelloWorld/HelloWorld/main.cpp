#include <iostream>

int main() {
	std::cout << " ----------  자기소개  ----------" << std::endl<<std::endl;
	std::cout << " 안녕하세요 송정훈입니다." << std::endl;
	std::cout << " 나이는 25살이고 전공은 정보통신공학입니다." << std::endl;
	std::cout << " 게임 개발에 도전하고 싶어서 지원했습니다.";

	std::cout<<std::endl<<std::endl;

	std::cout << " ----------  컴파일 4단계 설명  ----------" << std::endl<<std::endl;
	std::cout << " 전처리기 -> 컴파일러 -> 어셈블러 -> 링커 순으로 진행"<<std::endl<<std::endl << std::endl;

	std::cout << " 1. 전처리기 : #으로 시작하는 구문을 처리한다. ex) #include" << std::endl << std::endl;

	std::cout << " 2. 컴파일러 : 고수준언어를 저수준언어로 나타내는 역할.  ";
	std::cout << "*저수준 언어는 기계어에 가까운 언어다." << std::endl << std::endl;
	std::cout << " 3. 어셈블러 : 컴파일러에서 변환된 저수준언어를 완전한 기계어로 바꿔주는 역할" << std::endl << std::endl;

	std::cout << " 4. 링커 : 여러개의 오브젝트파일을 하나로 합치거나 라이브러리를 합치는 역할" << std::endl << std::endl;
	int a = 10;
	return 0;
}