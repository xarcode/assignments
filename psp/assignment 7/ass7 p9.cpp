#include <iostream>

using namespace std;

class static_example
{
	int data;
	static int count;
	
	public:
		static_example()
		{
			data = 0;
			count++;
		}	
		
		static_example(int n)
		{
			data = n;
			count++;
		}
		
		void show_data()
		{
			cout << "Data = " << data << endl;
		}
		
		void show_count()
		{
			cout << "Number of objects created = " << count << endl;
		}
};

int static_example::count = 0;

int main()
{
	static_example ob1;
	static_example ob2(10);
	
	ob1.show_data();
	ob2.show_data();
	ob2.show_count();
	return 0;
}
