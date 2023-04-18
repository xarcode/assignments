#include <iostream>
#include<math.h>
#define maxCapacity 50
using namespace std;
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
class MaxHeap{
	private:
		int arr[maxCapacity];
		int size,capacity;
	public:
		MaxHeap(int c=10)
		{
			capacity=c;
			size=0;
		}
		bool isEmpty()
		{
			return size==0;
		}
		bool isFull()
		{
			return size==capacity;
		}
		void heapify(int i)
		{
		    int largest = i;
		    int l = 2 * i + 1;
		    int r = 2 * i + 2;
		    if (l < size and arr[l] > arr[largest])
		        largest = l;
		    if (r < size and arr[r] > arr[largest])
		        largest = r;
		    if (largest != i)
		    {
		        swap(arr[largest], arr[i]);
		        heapify(largest);
		    }
		    return;
		}
		void buildHeap()
		{
		    for (int i = (size/2)- 1; i >= 0; i--)
		       heapify(i);
		}
		void insertVal(int val)
		{
			arr[size]=val;
			size++;
			buildHeap();
			return;
		}
		bool deleteVal(int val)
		{
			for(int i=0;i<size;i++)
			{
				if(arr[i]==val)
				{
					swap(arr[i],arr[size-1]);
					size--;
					heapify(0);
					return true;
				}
			}
			return false;
		}
		int getMax()
		{
			return arr[0];
		}
		int extractMax()
		{
			int val = arr[0];
			deleteVal(val);
			return val;
		}
		void display()
		{
			int c=0,count=0;
			for(int i=0;i<size;i++)
			{
				cout<<arr[i]<<" ";
				count++;
				if(count==pow(2,c))
				{
					cout<<endl;
					c++;
					count=0;
				}
			}
			return;
		}
};

int main()
{
    MaxHeap h;
    int ch, x;
    do
    {
        cout << "\n1.Insert 2.Delete 3.Find max 4.Extract max 5.Display heap\n";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
     	case 1: if(h.isFull()) cout<<"Heap is full\n";
     			else
		 		{
				 cout<<"Enter the value to be inserted: ";
     			 cin>>x;
     			 h.insertVal(x);
     			 cout<<x<<" is inserted\n";
     			}	
     			break;
     	case 2:	if(h.isEmpty()) cout<<"Heap is empty\n";
     			else
		 		{
				 cout<<"Enter the value to be deleted: ";
     			 cin>>x;
     			 if(h.deleteVal(x))
     			 	cout<<x<<" is deleted\n";
     			 else
     			 	cout<<x<<" is not present in heap\n";
     			}	
     			break;	
     	case 3:	if(h.isEmpty()) cout<<"Heap is empty\n";
     			else
     			{
     				cout<<"Maximum element in heap: "<<h.getMax()<<endl;
				}
		case 4: if(h.isEmpty()) cout<<"Heap is empty\n";
     			else
     			{
     				cout<<"Maximum element extracted is: "<<h.extractMax()<<endl;
				}
				break;
		case 5: if(h.isEmpty()) cout<<"Heap is empty\n";
				else h.display();
				break;
        default:
            cout << "Wrong choice\n";
            break;
        }
    } while (ch >= 1 && ch <= 5);
    return 0;
}
