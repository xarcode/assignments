#include<iostream>
using namespace std;
class Car;
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

class PersonData{
	public:
		string FirstName;
		string LastName;
		string Address;
		string City;
		string State;
		int Zip;
		long long int PhoneNo;
		date DOB;
		void setdata()
		{
			cout<<"\n\nEnter Driver Details : \n";
			cout<<"Enter First Name : ";
			cin>>FirstName;
			cout<<"Enter Last Name : ";
			cin>>LastName;
			cout<<"Enter Address : ";
			cin>>Address;
			cout<<"Enter City : ";
			cin>>City;
			cout<<"Enter State : ";
			cin>>State;
			cout<<"Enter Zip : ";
			cin>>Zip;
			cout<<"Enter Phone No : ";
			cin>>PhoneNo;
			fflush(stdin);
			cout<<"Enter DOB : ";
			cin>>DOB;
		}
		void const display()
		{
			cout<<"\n\nPerson Details :"<<endl;
			cout<<"First Name : "<<FirstName<<endl;
			cout<<"Last Name : "<<LastName<<endl;
			cout<<"Address : "<<Address<<endl;
			cout<<"City : "<<City<<endl;
			cout<<"State : "<<State<<endl;
			cout<<"Zip : "<<Zip<<endl;
			cout<<"Phone No : "<<PhoneNo<<endl;
			cout<<"DOB : "<<DOB;
		}	
};
class Car:public PersonData{
	PersonData Driver;
	string carName;
	int carId;
	string type;
	public:
		static const int wheels;
		Car(){
			Driver.setdata();
			addCar();
		};
		Car(string car,int id,string typ)
		{
			Driver.setdata();
			carName = car;
			carId = id;
			type = typ;
		}
		Car(Car &mycar)
		{
			Driver.setdata();
			carId = mycar.carId;
			Driver = mycar.Driver;
			carId = mycar.carId;
			type = mycar.type;
		}
		int getid() const
		{
			return carId;
		}
		~Car()
		{
			
		}
		void addCar()
		{
			cout<<"Enter the Car Id : ";
			cin>>this->carId;
			cout<<"Enter Car Name : ";
			cin>>this->carName;
			cout<<"Enter Car type : ";
			cin>>this->type;
		}
		void updateCar()
		{
			int ch,iid;
			string fname,lname,nname,ntype;
			cout<<"\nSelect the Attribute you want to edit : ";
			cout<<"\n1.Driver Name\n2.Car Name\n3.Car Id\n4.Car Type\n:";
			cin>>ch;
			switch(ch)
			{
				case 1:
					cout<<"Enter first Name of Driver: ";
					cin>>fname;
					cout<<"Enter last Name of Driver: ";
					cin>>lname;
					Driver.FirstName = fname;
					Driver.LastName = lname;
					break;
				case 2:
					 cout<<"Enter new name of car :";
					 cin>>nname;
					 carName =nname;
					break;
				case 3:
					cout<<"Enter New Id of car : ";
					cin>>iid;
					this->carId = iid;
					break;
				case 4:
					cout<<"Enter new car type : ";
					cin>>ntype;
					this->type  = ntype;
					break;
				default:
					cout<<"Please select a proper option !";
					return;
			}	
		}
		void printCar() const
		{
			cout<<"\n\nDriver Name : "<<Driver.FirstName<<" "<<Driver.LastName<<endl;
			cout<<"CarId : "<<carId<<endl;
			cout<<"CarName : "<<carName<<endl;
			cout<<"Car Type : "<<type<<endl;
			cout<<"Number of wheels : "<<wheels<<endl<<endl;
		}
};
const int Car::wheels =4;
int main()
{	
	int ch;
	cout<<"Details for Constant car object : \n";	
	const Car constantObj("Nano",2004,"micro");
	constantObj.printCar(); 
	fflush(stdin);
	cout<<"\nPress enter key to Go to menu !";
	cin.get();
	int i=0;
	Car *mycar[100];
	while(1)
	{
		system("cls");	
		fflush(stdin);
		cout<<"Enter the option from the menu : \n";
		cout<<"1.Add Car\n2.Delete Car\n3.Update Car Attributes\n4.Print Details\n5.Print List of cars\n6.Quit\n:";
		cin>>ch; 
		int k,cid,count=0;
		switch(ch)
		{
			case 1:
				mycar[i] = new Car();
				i++;
				cout<<"\nCar Added !";
				fflush(stdin);
				cin.get();
				break;
			case 2:
				cout<<"Enter Car Id you want to delete  : ";
				cin>>cid;
				if(cid == constantObj.getid())
				{
					cout<<"Car is constant , Can't be deleted !";
					fflush(stdin);
					cin.get();
					break;
				}
				for(int j=0;j<i;j++)
				{
					if(mycar[j]->getid() == cid)
					{
						k = j;
						count++;
					}
				}
				if(count==0)
				{
					cout<<"\nCar not found with id "<<cid<<endl;
					fflush(stdin);
					cin.get();
					break;
				}
				for(int j=k;j<i;j++)
				{
					mycar[j] = mycar[j+1];
				}
				i--;
				cout<<"Car deleted Successfully !";
				fflush(stdin);
				cin.get();
				break;		
			case 3:
				cout<<"\nEnter Car Id : ";
				cin>>cid;
				if(cid == constantObj.getid())
				{
					cout<<"Car is constant , Can't be updated !";
					fflush(stdin);
					cin.get();
					break;
				}
				for(int j=0;j<i;j++)
				{
					if(mycar[j]->getid() == cid)
					{
						k = j;
						count++;
					}
				}
				if(count==0)
				{
					cout<<"\nCar not found with id "<<cid<<endl;
					fflush(stdin);
					cin.get();
					break;
				}
				mycar[k]->updateCar();
				fflush(stdin);
				cin.get();
				break;
			case 4:
				cout<<"\nEnter Car Id : ";
				cin>>cid;
				if(cid == constantObj.getid())
				{
					constantObj.printCar();
					fflush(stdin);
					cin.get();
					break;
				}
				for(int j=0;j<i;j++)
				{
					if(mycar[j]->getid() == cid)
					{
						k = j;
						count++;
					}
				}
				if(count==0)
				{
					cout<<"\nCar not found with id "<<cid<<endl;
					fflush(stdin);
					cin.get();
					break;
				}
				mycar[k]->printCar();
				fflush(stdin);
				cin.get();
				break;
			case 5:
				cout<<"Details of all cars are : \n";
				constantObj.printCar();
				for(int j=0;j<i;j++)
				{
					cout<<"\n\n";
					mycar[j]->printCar();
				}
				fflush(stdin);
				cin.get();
				break;
			case 6:
					exit(0);
			default:
					cout<<"Wrong Option Selected ! Please select again";
					fflush(stdin);
					cin.get();
					break;				
		}
	}
	return 0;
}