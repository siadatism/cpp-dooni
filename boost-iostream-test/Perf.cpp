#include <string>
#include <chrono>
#include <iostream>
#include <algorithm>

#include <cctype>                        // toupper
#include <boost/iostreams/categories.hpp> // output_filter_tag
#include <boost/iostreams/operations.hpp> // put

#include <boost/iostreams/chain.hpp>
#include <boost/iostreams/device/array.hpp>
#include <boost/iostreams/filter/counter.hpp>

using std::cout;
using std::endl;
using std::string;
using namespace std::chrono; 

namespace io = boost::iostreams;

inline char fast_transform(char c)
{
	char temp = toupper(c);
	temp += 5;
	temp = tolower(c);
	temp += 10;
	return temp;
}

struct FastFilter
{
	typedef char char_type;
	typedef io::output_filter_tag category;

	template<typename Sink>
	inline bool put(Sink& snk, char c)
	{ 
		return io::put(snk, fast_transform(c)); 
	}
};

const size_t string_size = 1000;
const size_t repeat_count = 50 * 1000;
const size_t buffer_size = string_size * repeat_count;
high_resolution_clock::time_point start = high_resolution_clock::now();

void print_result(const string& title)
{
	size_t milli = duration_cast<milliseconds>(
			high_resolution_clock::now() - start).count();
	cout << title << endl;
	cout << "Time: " << milli << " ms" << endl;
	// cout << "Size: " << buffer_size << " Bytes" << endl;
	cout << "Rate: " << ((float) buffer_size) / (milli * 1000)
			<< " MB/s" << endl;
	cout << endl;
}

int main()
{
	// Preparation
	char* buffer = new char[buffer_size];
	string test(string_size, 'a');

	// One filter
	{
		// Chain creation
		io::chain<io::output> my_chain;
		my_chain.push(FastFilter());
		my_chain.push(io::array_sink(buffer, buffer_size));

		// Chain test
		start = high_resolution_clock::now(); 
		for (size_t i = 0; i < repeat_count; i++)
			my_chain.write(test.data(), test.size());
		print_result("Chain");

		// Normal test 
		start = high_resolution_clock::now();
		size_t index = 0;
		for (size_t i = 0; i < repeat_count; i++)
			for (size_t j = 0; j < string_size; j++)
			{
				buffer[index] = fast_transform(test[j]);
				index++;
			}
		print_result("Normal");
		
		my_chain.pop();
	}

	// Many filters
	{
		const size_t filters_count = 3;

		// Chain creation
		io::chain<io::output> my_chain;
		for (int i = 0; i < filters_count; i++)
			my_chain.push(FastFilter());
		my_chain.push(io::array_sink(buffer, buffer_size));

		// Chain test
		start = high_resolution_clock::now(); 
		for (size_t i = 0; i < repeat_count; i++)
			my_chain.write(test.data(), test.size());
		print_result("Chain plus");

		// Normal test 
		start = high_resolution_clock::now();
		size_t index = 0;
		for (size_t i = 0; i < repeat_count; i++)
			for (size_t j = 0; j < string_size; j++)
			{
				for (int k = 0; k < filters_count; k++)
					buffer[index] = fast_transform(test[j]);
				index++;
			}
		print_result("Normal plus");
		
		my_chain.pop();
	}

	return 0;
}
