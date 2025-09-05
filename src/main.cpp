#include <iostream>
#include "demo01.cpp"

int main() {

	std::cout << "This is my cpp learning demo" << std::endl;

	basic::RefAndPointer();
	basic::DataType();
	basic::ConstKeyWord();
	basic::StaticKeyWord();

	for (int i = 0; i < 10; i++) {
		basic::StaticFunction(); // 局部静态变量会递增
	}
	
	basic::A::staticFunction();

	return 0;
}