// From "https://accu.org/journals/overload/9/43/frogley_442/" with edits.

#include <limits>
#include <iostream>

template<typename T> 
T get_max(const T* const items, size_t count)
{
	T largest = std::numeric_limits<T>::min(); 
	for (size_t i = 0; i < count; ++i) 
		if (items[i] > largest)
			largest = items[i]; 
	return largest; 
}

int main()
{
	using namespace std;

	float numbers[] = {1.1, -5, 3.3, -2, 2.8};
	cout << get_max(numbers, 5) << endl;
}
