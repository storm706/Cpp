#include <iostream>
#include<thread>
using namespace std;

class myclass
{
public:
	void work()
	{
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout  << "________id potoka work  " << this_thread::get_id() << "_________________start\n" ;
		
		cout << "this is function Work " << endl;
		cout  << "________id potoka " << this_thread::get_id() << "_________________work stop" << endl;
	}
	void work2(int a)
	{
		cout << "_________id potoka work2  " << this_thread::get_id() << "_________________start" << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "\t\tthis is function Work2 and value:  "<<a << endl;
		cout  << "________id potoka " << this_thread::get_id() << "_________________work2 stop" << endl;
	}
	int work3(int a,int b)
	{
		cout <<   "_________id potoka " << this_thread::get_id() << "_________________work3 start" << endl;
	
		this_thread::sleep_for(chrono::milliseconds(2500));
		cout << "this is function Work3   "  << endl;
		
		return a + b;
		cout <<  "__________id potoka " << this_thread::get_id() << "_________________work3 stop" << endl;
	}

	void task()
	{
		for (size_t i = 0; i < 10; i++)
		{
			cout  <<i<< "  id potoka " << this_thread::get_id() << "++++++++++++++start" << endl;
			this_thread::sleep_for(chrono::milliseconds(800));
		}
		cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++end task" << endl;
	}
};

int main()
{
	myclass m;
	
	thread t(&myclass::work,m);
	m.task();
	t.join();

	thread t1(&myclass::work2, m,5);
	m.task();
	t1.join();

	int result;
	thread t2( [&](){result = m.work3(5, 5);} );
	m.task();
	t2.join();
	cout << "\t\tresult work3 :" << result << endl;
}