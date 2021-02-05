// From "https://www.bogotobogo.com/cplusplus/template_specialization_traits.php" with edits.

#include <climits>
#include <cfloat>

#include <limits>

#include <iostream>


int main()
{
	using namespace std;

	cout << "Max int: " << INT_MAX << endl;
	cout << "Max double: " << DBL_MAX << endl;

	cout << endl;
	cout << "Max int: " << numeric_limits<int>::max() << endl;
	cout << "Max double: " << numeric_limits<double>::max() << endl;
	cout << "Max float: " << numeric_limits<float>::max() << endl;
	cout << "Max unsigned int: " << numeric_limits<unsigned int>::max() << endl;
}
