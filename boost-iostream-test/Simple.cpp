#include <string>
#include <chrono>
#include <iostream>
#include <algorithm>

#include <iosfwd>

#include <ctype.h>                        // toupper
#include <boost/iostreams/categories.hpp> // output_filter_tag
#include <boost/iostreams/operations.hpp> // put

#include <boost/iostreams/chain.hpp>
#include <boost/iostreams/device/array.hpp>
#include <boost/iostreams/filter/counter.hpp>

using std::cout;
using std::endl;
using std::string;

namespace io = boost::iostreams;

struct toupper_output_filter
{
	typedef char char_type;
	typedef io::output_filter_tag category;

	template<typename Sink>
	bool put(Sink& snk, char c)
	{ 
		return io::put(snk, toupper((unsigned char) c)); 
	}
};

int main()
{
	io::chain<io::output> my_chain;

	toupper_output_filter upper;
	my_chain.push(upper);

	io::counter my_counter;
	my_chain.push(boost::ref(my_counter));

	char my_array[1000];
	my_chain.push(io::array_sink(my_array, 1000));

	my_chain.write("Salam\n", 6);
	my_chain.write("AleYkOoM\n", 9);

	my_chain.pop();
	cout << "Characters: " << my_counter.characters()
			<< ", Lines: " << my_counter.lines() << endl;

	cout << string(my_array, my_counter.characters());
	return 0;
}
