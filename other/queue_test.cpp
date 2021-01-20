#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);

	cout << "Queue: ";
	for (auto i : q)
		cout << i << " ";
	cout << endl;

	cout <<	"Front: " << q.front() << endl;
			<< "Back: " << q.back() << endl;

	
}