// From "https://accu.org/journals/overload/9/43/frogley_442/" with edits.

#include <iostream>

template<typename T> 
struct is_void
{
	static const bool value = false;
};

template<> 
struct is_void<void>
{ 
	static const bool value = true; 
};

template<typename T> 
struct is_pointer
{
	static const bool value = false; 
};

template<typename T> 
struct is_pointer<T*>
{ 
	static const bool value = true; 
};

int main()
{
	using std::cout;
	using std::endl;

	cout << "is_void<void>: " << is_void<void>::value << endl;
	cout << "is_void<int>: " << is_void<int>::value << endl;

	cout << "is_pointer<int>: " << is_pointer<int>::value << endl;
	cout << "is_pointer<int*>: " << is_pointer<int*>::value << endl;
}
