#include <iostream>
#include <thread>
#include "listing_2_4.h"
#include "thread_3_1.h"
//#define _2_1_1

//1. Normal
void Hello()
{
	std::cout << "Hello Concurrent World" << std::endl;
}
// 2.仿函数
class background_task
{
public:
	void operator()()const
	{
		std::cout << "hello background_task" << std::endl;
	}
};

struct func
{
	int& i;
	func(int& i_) : i(i_){}
	void operator()()
	{
		for (unsigned j = 0; j < 1000000; ++j)
		{
			std::cout << "hello : " << j << ":" << i << std::endl;
		}
	}
};

void oops()
{
	int some_local_state = 0;
	func my_func(some_local_state);
	std::thread my_thread(my_func);
	my_thread.detach();
}

int main()
{
#ifdef _1_4_1
	std::thread t(Hello);
	t.join();
#elif defined _2_1_1
	background_task task;
	std::thread t{background_task()};
	t.join();
	std::thread lambdaThread([] {
		std::cout << "Hello Lambda thread" << std::endl;
		});
	try
	{
		lambdaThread.detach();
	}
	catch (...)
	{
		lambdaThread.join();
		throw;
	}
	oops();
	
#endif

	thread_2_4::editor_document("bar.doc");
	using thread_2_4::X;
	X my_x;
	std::thread t(&X::do_lenghty_work, &my_x);
	t.join();

	THREAD_3_1_::add_to_list(42);
	std::cout << "contains(1)=" << THREAD_3_1_::list_contains(1) << ", contains(42) = " << THREAD_3_1_::list_contains(42) << std::endl;
}