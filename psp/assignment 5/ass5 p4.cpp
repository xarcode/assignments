#include <iostream>

using namespace std;

void swap(string *s1, string *s2)
{
	string t = *s1;
	*s1 = *s2;
	*s2 = t;
}

int main()
{
	string words[5] = {"ayush", "is", "a", "good", "boy"};
	string *word_p[5];
	
	for(int i = 0; i < 5; i++) word_p[i] = &words[i];
	
	int i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 5 - i - 1; j++)
            if (*word_p[j] > *word_p[j + 1])
                swap(word_p[j], word_p[j + 1]);
    
    for(int i = 0; i < 5; i++) cout << words[i] << " ";
	return 0;
}
