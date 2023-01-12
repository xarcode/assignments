#include <iostream>

using namespace std;

int main()
{
	int men_p = 52, literacy_p = 48, literate_men_p = 35, total_pop = 80000;
	int illiterate_men = (total_pop * (men_p / 100.0)) - (total_pop * (literate_men_p / 100.0));
	int illiterate_women = total_pop - (total_pop * (literacy_p / 100.0)) - illiterate_men;
	cout << "Total illiterate men = " << illiterate_men << endl;
	cout << "Total illiterate women = " << illiterate_women;
	return 0;
}