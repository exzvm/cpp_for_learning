#include <iostream>
#include <climits>

namespace basic {

void RefAndPointer() {
  int x = 10;
	int* ptr = &x;

	int y = 20;
	int& ref = y;

	int value = *ptr; // 获取指针指向的值
	int* address = &x; // 获取变量 x 的地址

  int newValue = ref; // 获取引⽤的值

	std::cout << "value=" << value << " address=" << address << " ref value=" << newValue << std::endl;
}

void DataType() {
  std::cout << "int is " << sizeof (int) << " bytes. \n";
  std::cout << "short is " << sizeof (short) << " bytes. \n";
	std::cout << "INT_MAX=" << INT_MAX  << " INT_MIN=" << INT_MIN << std::endl;
}

void ConstKeyWord() {
	// 1.常量指针
	int tmp = 10;
	int tmp2 = 11;
	const int* a = &tmp;
	// *a = 9; // 不能更改对象值
	tmp = 9;
	a = &tmp2;

	// 2.指针常量
	int tmp3 = 12;
	int tmp4 = 13;
	int* const p = &tmp3; // 常量指针
	*p = 9;
	// p = &tmp4; // 不可以指向新的对象
}

void StaticKeyWord() {
	static int count = 0; // 静态变量
	count++;
	count++;
	std::cout << "Count: " << count << std::endl;
}

void StaticFunction() {
	static int localVar = 0; // 静态局部变量
	localVar++;
	std::cout << "LocalVar: " << localVar << std::endl;
}

void ConstExpr() {
  constexpr int n = 20;
  constexpr int m = n + 1;
  static constexpr int MOD = 1000000007;

  constexpr int *p = nullptr; //常量指针 顶层const
  const int *q = nullptr; //指向常量的指针， 底层const
  //int *const q = nullptr; //顶层const
}

class A {
public:
	static void staticFunction() {
		std::cout << "Static function" << std::endl;
	}

	static int staticVar; // 静态成员变量声明
};

int A::staticVar = 0;

} // namespace::basic