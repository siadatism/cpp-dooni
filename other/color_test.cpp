#include <iostream>

// Colors
#define C_RESET       "\033[0m"
#define C_BLACK       "\033[30m"      
#define C_RED         "\033[31m"     
#define C_GREEN       "\033[32m"     
#define C_YELLOW      "\033[33m"     
#define C_BLUE        "\033[34m"     
#define C_MAGENTA     "\033[35m"     
#define C_CYAN        "\033[36m"     
#define C_WHITE       "\033[37m"     
#define C_BOLDBLACK   "\033[1m\033[30m"     
#define C_BOLDRED     "\033[1m\033[31m"     
#define C_BOLDGREEN   "\033[1m\033[32m"
#define C_BOLDYELLOW  "\033[1m\033[33m"
#define C_BOLDBLUE    "\033[1m\033[34m"     
#define C_BOLDMAGENTA "\033[1m\033[35m"    
#define C_BOLDCYAN    "\033[1m\033[36m"     
#define C_BOLDWHITE   "\033[1m\033[37m"      

// Sleep time between moves
#define EASY 300
#define MEDIUM 200
#define HARD 100

enum Direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

enum Color
{
	RED,
	GREEN,
	YELLOW,
	BLUE
};

using namespace std;

void colorized_print(string s, Color c)
{
	string code;

	switch (c)
	{
		case RED:
			code = C_RED;
			break;
		case GREEN:
			code = C_GREEN;
			break;
		case YELLOW:
			code = C_YELLOW;
			break;
		case BLUE:
			code = C_BLUE;
			break;
		default:
			throw string("Unknown color.");
	}

	cout << code << s << C_RESET;
}

int main()
{
	cout << "Hi" << endl;
	colorized_print("Blue!\n", BLUE);
	colorized_print("Red!\n", RED);
	colorized_print("Green!\n", GREEN);
	colorized_print("Yellow!\n", YELLOW);
	cout << "Bye" << endl;
}
