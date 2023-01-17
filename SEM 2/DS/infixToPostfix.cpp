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

bool isOperator(char c){
	switch(c){
		case '+':
		case '-':
		case '/':
		case '*': return true;
	}
	
	return false;
}

int getPrecedence(char op){
	switch(op){
		case '+':
		case '-': return 1;
		case '*':
		case '/': 
		case '%': return 2;
		case '^': return 3;
	}
	
	return -1;
}

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

bool isHigherPrecedence(char op1, char op2){
	return getPrecedence(op2) >= getPrecedence(op1);
}

// ASSUMPTION: valid infix expression is input
string InfixToPostfix(string infix){
	string postfix = "";
	stack<char> s;
	
	for(int i = 0; i < infix.length(); i++){
		char curr = infix[i];
		
		if(isOperator(curr)){
			while(!s.isEmpty() && isHigherPrecedence(curr, s.top())){
				postfix += s.pop();
			}
			s.push(curr);
		}
		else if(isPar(curr) == 1) s.push(curr);
		else if(isPar(curr) == 2){
			char t;
			do{
				t = s.pop();
				if(!isPar(t)) postfix += t;
			}while(isPar(t) != 1);
		}
		else postfix += curr;
	}
	
	while(!s.isEmpty()) postfix += s.pop();
		
	return postfix;
}

int main(){
	string exp = "A*B-(C+D)+E";
	cout << InfixToPostfix(exp);
	return 0;
}
