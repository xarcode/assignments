#include<bits/stdc++.h>
using namespace std;
class PersonData{
	protected:
		string FirstName,LastName,Address;
		string state,City;
		int ZIP,PhoneNo;
	
	public:
		void Getdata()
		{
			cout<<"\nEnter Customer FirstName:";
			cin>>FirstName;
			cout<<"\nEnter Customer LastName:";
			cin>>LastName;
			cout<<"\nEnter Customer Address:";
			cin>>Address;
			cout<<"\nEnter Customer State:";
			cin>>state;
			cout<<"\nEnter Customer City:";
			cin>>City;
			cout<<"\nEnter Customer Zip code:";
			cin>>ZIP;
			cout<<"\nEnter Customer PhoneNo:";
			cin>>PhoneNo;
			
		}
		void displaydata()
		{
			cout<<"\n\nFirst Name->"<<FirstName;
			cout<<"\nLast Name->"<<LastName;
			cout<<"\nAddress->"<<Address;
			cout<<"\nState ->"<<state;
			cout<<"\nCity->"<<City;
			cout<<"\nZIP->"<<ZIP;
			cout<<"\nPhoneNo->"<<PhoneNo;
		}
};
class CustomerData: public PersonData{
	private :
		int CustomerNumber;
		bool mailList;
	public:
		void Getdata()
		{
			cout<<"Enter Customer Number:";
			cin>>CustomerNumber;
			cout<<"\nDo you want to be in the mailing List? 1->Y OR 0->N -->";
			cin>>mailList;
		}
		void displaydata()
		{
			cout<<"\n\nCustomerNumber is->"<<CustomerNumber;
			cout<<"\nMailing List Status->"<<((mailList)?"Yes":"No");
			
		}
		
};
int main()
{
	CustomerData cd;
	cd.Getdata();
	cd.displaydata();
}
