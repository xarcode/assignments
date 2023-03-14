#include <iostream>
#include <cmath>

#define M 13

using namespace std;

int HashTable[M] = {0};

int hash(int x){
	return x % M;
}

void insert(int num){
	int idx = hash(num);
	if(HashTable[idx] == 0) HashTable[idx] = num;
	else{
		int i = 0;
		while(HashTable[hash(idx + pow(i, 2))] != 0) i++;
		idx = hash(idx + pow(i, 2));
		HashTable[idx] = num;
	}
}

void showHashTable(){
	for(int i = 0; i < M; i++) cout << HashTable[i] << " ";
	cout << endl;
}

bool search(int num){
	int idx = hash(num);
	int found = false;
	int i = 0;
	while(true){
		if(HashTable[hash(idx + pow(i, 2))] == num) return true;
		if(HashTable[hash(idx + pow(i, 2))] == 0) return false;
		i++; 
	}
	
	return false;
}

bool Delete(int num){
	if(search(num)){
		int idx = hash(num);
		int i = 0;
		while(HashTable[hash(idx + pow(i, 2))] != num) i++;
		
		HashTable[hash(idx + pow(i, 2))] = -1;
		return true;
	}
	
	return false;
}

int main(){
	int arr[] = {13, 26, 56, 31, 39, 15, 3, 50, 12, 35};
	for(int i = 0; i < 10; i++) insert(arr[i]);
	showHashTable();
	int val;
	cout << "Enter a value to search for: "; cin >> val;
	if(search(val)) cout << "Value has been found" << endl;
	else cout << "Value is not found" << endl;
	
	
	cout << "Enter a value to be deleted: "; cin >> val;
	if(Delete(val)) cout << val << " has been deleted successfuly" << endl;
	else cout << val << " has not been deleted" << endl;
	showHashTable();
	return 0;
}
