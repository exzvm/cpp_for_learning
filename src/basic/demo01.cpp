#include <iostream>
#include <climits>
#include <memory>

int g_value = 42;   // 定义全局变量

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

  constexpr int *p = nullptr; //常量指针 顶层const  相当于 int * const p = nullptr; 只不过加上了编译期常量属性。
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

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

void funcPtr() {
	int (*operationPtr)(int, int);
	operationPtr = &add;

	int res = operationPtr(3, 9);
	std::cout << "res=" << res << std::endl;

	operationPtr = &sub;
	res = operationPtr(3, 9);
	std::cout << "res=" << res << std::endl;
}

void smartPointer() {
	// 2种初始化方式
	std::unique_ptr<int> p1 = std::make_unique<int>(42);
	std::unique_ptr<int> p2(new int(33));

	// std::unique_ptr<int> p3 = p1; // ❌ 错误，不能拷贝
	std::unique_ptr<int> p4 = std::move(p1);
	std::cout << *p4 << std::endl;


	std::shared_ptr<int> p5 = std::make_shared<int>(20);
	std::shared_ptr<int> p6 = p5; // 引用计数+1
	std::cout << *p5 << ", count=" << p5.use_count() << std::endl; // 20, count=2
}

} // namespace::basic

