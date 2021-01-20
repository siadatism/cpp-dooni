#include <iostream> 

using namespace std;

class Point
{
public:
	Point(int x, int y)
	: my_x(x)
	, my_y(y)
	{}

	Point()
	: Point(0, 0)
	{}

	int x() const { return my_x; }
	int y() const { return my_y; }

	bool operator==(const Point& other) const
	{
		return my_x == other.my_x && my_y == other.my_y;
	}

protected:
	const int my_x, my_y;
};

int main()
{
	cout << "Salam!" << endl;
	Point p;
	cout << p.x() << " " << p.y() << endl;
	cout << (p == Point()) << endl;
	cout << (Point() == p) << endl;
}
