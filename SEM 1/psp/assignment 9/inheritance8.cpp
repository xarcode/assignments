#include<iostream>
using namespace std;
struct date{
	int day;
	int month;
	int year;
};
ostream& operator<<(ostream& o,date &d)
{
	o<<d.day<<"/"<<d.month<<"/"<<d.year;
	return o;
}
istream& operator>>(istream& i, date &d)
{
	i>>d.day>>d.month>>d.year;
	return i;
}
class Media{
	protected:
		int mediaId;
		string mediaName;
		date DOI;
		date DOD;
		bool isIssued;
	public:
		void addMedia()
		{
			cout<<"Enter Media Id : ";
			cin>>mediaId;
			fflush(stdin);
			cout<<"Enter Media Name : ";
			getline(cin,mediaName);
			isIssued = false;
			DOI.day = DOD.day=DOI.month=DOD.month=DOD.year=DOI.year=0;
			
		}
		int GetId()
		{
			return mediaId;
		}
		void issueMedia()
		{
			cout<<"Enter date of issue : \n";
			cin>>DOI;
			isIssued = true;
		}
		void depositMedia()
		{
			cout<<"Enter date of deposit : \n";
			cin>>DOD;
			isIssued = false;
		}
		void display()
		{
			cout<<"Media Id : "<<this->mediaId<<endl;
			cout<<"Media Name : "<<this->mediaName<<endl;
			cout<<"Media Issued?  : ";
			if(isIssued)
			{
				cout<<"yes \n";
				cout<<"Date of Issue : "<<DOI<<endl;
			}
			else{
				cout<<"no \n";
				cout<<"Date of Deposit : "<<DOD<<endl;
			}	
		}
};
class Books:public Media{
	private:
		int number_of_pages;
		string author;
	public:
		void addMedia()
		{
			Media::addMedia();
			cout<<"Enter Number of pages in the book : ";
			cin>>number_of_pages;
			fflush(stdin);
			cout<<"Enter author's name : ";
			getline(cin,author);
		}
		void display()
		{
			Media::display();
			cout<<"Number of pages in the book : "<<number_of_pages<<endl;
			cout<<"Author's name : "<<author<<endl;
		}	
};
class Tape:public Media{
	private:
		int length_of_tape;
		string singer;
	public:
		void addMedia()
		{
			Media::addMedia();
			cout<<"Enter length of tape : ";
			cin>>length_of_tape;
			fflush(stdin);
			cout<<"Enter singer's name : ";
			getline(cin,singer);
		}
		void display()
		{
			Media::display();
			cout<<"Length of tape : "<<length_of_tape<<endl;
			cout<<"Singer's name : "<<singer<<endl;
		}
};
int main()
{
	Books mybooks[100];
	Tape mytape[100];
	int b=0,t=0;
	while(1)
	{
		int ch,bid,tid;
		
		cout<<"Select Options from the menu : ";
		cout<<"\n1.Add a Book\n2.Add a Tape\n3.Display Book details\n4.Display Tape details\n5.Issue Book\n6.Issue Tape\n7.Return Book\n8.Return Tape\n9.Quit\n:";
		cin>>ch;
		int count=0;
		switch(ch)
		{
			case 1:
				mybooks[b].addMedia();
				b++;
				cout<<"\n Book added Successfully\n";
				cin.get();
				break;
			case 2:
				mytape[t].addMedia();
				t++;
				cout<<"\n Tape added Successfully\n";
				cin.get();
				break;
			case 3:
				cout<<"\nEnter the book Id : ";
				cin>>bid;
				for(int i=0;i<b;i++)
				{
					if(mybooks[i].GetId() == bid)
					{
						mybooks[i].display();
						count++;
					}
				}
				if(count==0)
				{
					cout<<"\nBook not found with id "<<bid<<endl;
				}
				fflush(stdin);
				cin.get();
				break;
			case 4:
				cout<<"\nEnter the Tape Id : ";
				cin>>tid;
				for(int i=0;i<t;i++)
				{
					if(mytape[i].GetId() == tid)
					{
						mytape[i].display();
						count++;
					}
				}
				if(count==0)
				{
					cout<<"\nTape not found with id "<<tid<<endl;
				}
				fflush(stdin);
				cin.get();
				break;
			case 5:
				cout<<"\nEnter book_id of the book you want to issue : ";
				cin>>bid;
				for(int i=0;i<b;i++)
				{
					if(mybooks[i].GetId() == bid)
					{
						count++;
						mybooks[i].issueMedia();
						cout<<"\nBook Issued\n";
						break;
					}
				}
				if(count==0)
				{
					cout<<"\nBook not found with id "<<bid<<endl;
				}
				fflush(stdin);
				cin.get();
				break;
			case 6:
				cout<<"\nEnter tape_id of the tape you want to issue : ";
				cin>>tid;
				for(int i=0;i<t;i++)
				{
					if(mytape[i].GetId() == tid)
					{
						count++;
						mytape[i].issueMedia();
						cout<<"\nTape Issued\n";
						break;
					}
				}
				if(count==0)
				{
					cout<<"\nTape not found with id "<<tid<<endl;
				}
				fflush(stdin);
				cin.get();
				break;
			case 7:
				cout<<"\nEnter book_id of the book you want to deposit : ";
				cin>>bid;
				for(int i=0;i<b;i++)
				{
					if(mybooks[i].GetId() == bid)
					{
						count++;
						mybooks[i].depositMedia();
						cout<<"\nBook Deposited\n";
						break;
					}
				}
				if(count==0)
				{
					cout<<"\nBook not found with id "<<bid<<endl;
				}
				fflush(stdin);
				cin.get();
				break;
			case 8:
				cout<<"\nEnter tape_id of the tape you want to deposit : ";
				cin>>tid;
				for(int i=0;i<t;i++)
				{
					if(mytape[i].GetId() == tid)
					{
						count++;
						mytape[i].depositMedia();
						cout<<"\nTape Deposited\n";
						break;
					}
				}
				if(count==0)
				{
					cout<<"\nTape not found with id "<<tid<<endl;
				}
				fflush(stdin);
				cin.get();
				break;
			case 9:
				exit(0);
			default:
				cout<<"Please enter correct option";
				break;
		}
	}
	return 0;
}