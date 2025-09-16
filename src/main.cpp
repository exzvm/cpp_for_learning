#include <iostream>
#include <functional>
#include "demo01.cpp"
#include "singleton.cpp"
#include "taskqueue.cpp"

extern int g_value; // 声明，不分配存储空间
void foo() {
	std::cout << g_value << std::endl;
}

// 回调函数
void bar(std::function<void()> cb) {
  std::function<void()> f;
  f = std::move(cb);
  f();
}

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
	foo();

	singleton::TaskQueue* obj = singleton::TaskQueue::getInstance();
	singleton::TaskAtomicQueue::getInstance()->print();
	singleton::TaskStaticQueue::getInstance()->print();

  std::string big(2000000, 'x'); // 大字符串
  bar([big]() { std::cout << big.size() << std::endl; });

  basic::funcPtr();
  basic::smartPointer();

  //thread t1([]() {
  //  TaskQueue* taskQ = TaskQueue::getInstance();
  //  for (int i = 0; i < 100; ++i)
  //  {
  //    taskQ->addTask(i + 100);
  //    cout << "+++push task: " << i + 100 << ", threadID: "
  //      << this_thread::get_id() << endl;
  //    this_thread::sleep_for(chrono::milliseconds(500));
  //  }
  //  });
  //thread t2([]() {
  //  TaskQueue* taskQ = TaskQueue::getInstance();
  //  this_thread::sleep_for(chrono::milliseconds(100));
  //  while (!taskQ->isEmpty())
  //  {
  //    int data = taskQ->takeTask();
  //    cout << "---take task: " << data << ", threadID: "
  //      << this_thread::get_id() << endl;
  //    taskQ->popTask();
  //    this_thread::sleep_for(chrono::seconds(1));
  //  }
  //  });
  //t1.join();
  //t2.join();

	return 0;
}