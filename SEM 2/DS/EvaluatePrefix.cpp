#include <iostream>
#include <string>
#include <cmath>

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

bool isOperator(char c){
	switch(c){
		case '+':
		case '-':
		case '/':
		case '*': return true;
	}
	
	return false;
}

// ASSUMPTION 1: expressions containing single digit numbers are input
// ASSUMPTION 2: expression is valid postfix
int evaluate(string exp){
	stack<int> s;
	
	for(int i = exp.length() - 1; i >= 0; i--){
		char c = exp[i];
		
		if(isOperator(c)){
			int op1 = s.pop();
			int op2 = s.pop();
			
			int res;
			
			switch(c){
				case '+':
					res = op1 + op2;
					break;
				case '-':
					res = op1 - op2;
					break;
				case '*':
					res = op1 * op2;
					break;
				case '/':
					res = op1 / op2;
					break;
				case '%':
					res = op1 % op2;
					break;
				case '^':
					res = pow(op1, op2);
					break;
			}
			
			s.push(res);
		}
		else s.push(c - '0');
	}
	
	return s.top();
}

int main(){
	string exp = "-+*6538";
	cout << evaluate(exp);
	return 0;
}
