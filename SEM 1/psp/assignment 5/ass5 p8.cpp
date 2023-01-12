#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cout << "Please enter a sentence: "; getline(cin, s);
	
	int word_count = 0, char_count = s.length();
	for(int i = 0; i < char_count; i++)
		if(s[i] == ' ') word_count ++;
		
	cout << "Number of characters is: " << char_count << endl;
	cout << "Number of words is: " << word_count + 1;
	return 0;
}
