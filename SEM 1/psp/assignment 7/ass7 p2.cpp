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
		
		void show_data();
		void increase_hitbox(float newHitbox);
};

void RL_Cars::show_data()
{
	cout << "Car Name: " << name << endl;
	cout << "HitBox Area: " << hitbox << " sq m" << endl;
}

void RL_Cars::increase_hitbox(float newHitbox)
{
	hitbox = newHitbox;
}

RL_Cars global_car;

int main()
{
	RL_Cars car1;
	cout << "Local Object Data...\n";
	car1.show_data();
	car1.increase_hitbox(40);
	car1.show_data();
	cout << "Global Object Data...\n";
	global_car.show_data();
	global_car.increase_hitbox(50);
	global_car.show_data();
	return 0;
}
