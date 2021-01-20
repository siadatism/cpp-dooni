#include <iostream>

using namespace std;

struct Square;

struct Ball
{
	Square* my_square;
	void go()
	{
		int temp = my_square->get_size();
	}
};

struct Square
{
	Ball* my_ball;

	int get_size()
	{
		return 0;
	}
};

int main()
{
	cout << "Salam" << endl;
}
