#include <iostream>

using namespace std;

class DecToBin
{
	private:
		string bin;
	public:
		DecToBin()
		{
			bin = "0";
		}
		
		DecToBin(int nbr)
		{
			bin = "";
			while(nbr)
			{
				bin += (nbr % 2) + '0';
				nbr /= 2;
			}
			
			for(int i = bin.length() - 1; i >= 0; i--)
				cout << bin[i];
			cout << endl;
		}
		
		~DecToBin()
		{
			cout << "Destroying Convertor object ...\n";
		}
};

int main()
{
	DecToBin d(13);
	return 0;
}
