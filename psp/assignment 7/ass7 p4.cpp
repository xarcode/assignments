#include <iostream>

using namespace std;

class RL_Cars
{
	private:
		string name;
		float hitbox;
	public:
		RL_Cars()
		{
			name = "Octane";
			hitbox = 30.0;
		}
		
		RL_Cars(string carname, float carhitbox);
		
		void show_data();
		void increase_hitbox(float newHitbox);
		
		~RL_Cars()
		{
			cout << "Destroying object...\n";
		}
};

RL_Cars::RL_Cars(string carname, float carhitbox)
{
	name = carname;
	hitbox = carhitbox;
}

void RL_Cars::show_data()
{
	cout << "Car Name: " << name << endl;
	cout << "HitBox Area: " << hitbox << " sq m" << endl;
}

void RL_Cars::increase_hitbox(float newHitbox)
{
	hitbox = newHitbox;
}

void create_car(string carname, float hitbox)
{
	cout << "Creating a car inside a function...\n";
	RL_Cars car(carname, hitbox);
	cout << "Car created...\n";
	car.show_data();
}

int main()
{
	create_car("Dominus", 60);
	return 0;
}
