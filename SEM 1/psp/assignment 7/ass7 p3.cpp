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

int main()
{
	cout << "Object created with default constructor...\n";
	RL_Cars car1;
	car1.show_data();
	car1.increase_hitbox(40);
	car1.show_data();
	cout << "Object created with parameterized constructor...\n";
	RL_Cars car2("Dominus", 60);
	car2.show_data();
	return 0;
}
