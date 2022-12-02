#include<bits/stdc++.h>
using namespace std;
class CustomerData{
	protected :
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
class PreferredCustomer: public CustomerData{
	private :
		double purchaseAmount;
		double discountLevel;
		
	public:
		void purchasedata()
		{
			cout<<"\nEnter Total Purchase done by the customer:";
			cin>>purchaseAmount;
			
			if(purchaseAmount>=2000)
				discountLevel= 10;
			else if(purchaseAmount>=1500 && purchaseAmount<2000 )
				discountLevel= 7;
			else if(purchaseAmount>=1000 && purchaseAmount<1500 )
				discountLevel= 6;
			else
				discountLevel= 5;
		}
		void showdata()
		{
			cout<<"\n\nTotal Purchase is->"<<purchaseAmount;
			cout<<"\nDiscount to be applied on future purchases->"<<discountLevel<<"%";
			
		}
};
int main()
{
	PreferredCustomer pd;
	pd.Getdata();
	pd.purchasedata();
	pd.displaydata();
	pd.showdata();
}
