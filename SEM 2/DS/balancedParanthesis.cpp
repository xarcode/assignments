#include <iostream>
#include <string>

using namespace std;

template <typename T>
class stack
{
private:
	int capacity;
	int topIdx;
	T arr[100];

public:
	stack()
	{
		capacity = 5;
		topIdx = -1;
	}
	
	stack(int c)
	{
		capacity = c;
		topIdx = -1;
	}
	
	bool isEmpty() { return (topIdx == -1); }
	bool isFull() { return (topIdx == capacity - 1); }
	int size() { return topIdx + 1; }
	
	bool push(T c)
	{
		if(isFull()) return false;
		arr[++topIdx] = c;
		
		return true;
	}
	
	T pop()
	{
		T ele;
		if(!isEmpty())
			ele = arr[topIdx--];
		
		return ele;
	}
	
	T top()
	{ 
		T ele;
		if(!isEmpty())
			ele = arr[topIdx];
		
		return ele;
	}
		
	void print()
	{
		cout << "Stack: " << endl;
		for(int i = topIdx; i > -1; i--)
		{
			cout << arr[i];
			if(i == topIdx) cout << " <- top";
			cout << endl;
		}
	}	
};

int isPar(char c){
	switch(c){
		case '(':
		case '{':
		case '[':
		case '<': return 1;
		case ')':
		case '}':
		case ']':
		case '>': return 2;
	}
	
	return 0;
}

bool isBalPar(char p, char g){
	switch(p){
		case '(': return g == ')';
		case '{': return g == '}';
		case '[': return g == ']';
		case '<': return g == '>';
	}
	
	return false;
}

void checkBalPar(string exp){
	stack<char> s;
	int i = 0;
	bool bal = true;
	do{
		char ch = exp[i++]; 
		switch(isPar(ch)){
			case 1:
				s.push(ch);
				break;
			case 2:
				if(!s.isEmpty()){
					char t = s.pop();
					bal = isBalPar(t, ch);
				}
				else bal = false;
				break;
		}
	}while(i != exp.length() && bal);
	
	if(bal && s.isEmpty()) cout << "Balanced";
	else cout << "Not balanced";
}

int main(){
	string exp;
	cout << "Enter an expression: ";
	cin >> exp;
	checkBalPar(exp);
	return 0;
}
