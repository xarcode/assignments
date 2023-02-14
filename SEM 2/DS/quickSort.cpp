#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partion(int arr[],int l,int r)
{int piv=arr[l];int i=l,j=r;
while(i<j)
{while(arr[i]<=piv)i++;
 while(arr[j]>piv)j--;
 if(i<j)swap(&arr[i],&arr[j]);
}
swap(&arr[l],&arr[j]);
return j;
}
void QuickSort(int arr[],int l,int r){
	if(l<r)
	{
		int pivloc=partion(arr,l,r);
		QuickSort(arr,l,pivloc-1);
		QuickSort(arr,pivloc+1,r);
	}
}

void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"\t";
	}
}

int main()
{
	int ar[]={12, 34 ,56, 78, 76, 54,32},N;
	N=sizeof(ar)/sizeof(ar[0]);
	QuickSort(ar,0,N-1);
	print(ar,N);
}
