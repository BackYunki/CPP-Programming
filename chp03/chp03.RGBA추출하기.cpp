#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	unsigned int color = 0xB8860BFF;
	unsigned char red, green, blue, alpha;

	cout << "¿ø»ö:\t" << bitset<32>(color) << endl;
	
	red = (color & 0xFF000000) >> 24;
	green = (color & 0x00FF0000) >> 16;
	blue = (color & 0x0000FF00) >> 8;
	alpha = (color & 0x000000FF) >> 0;

	cout << "R:\t" << bitset<8>(red)	<< " = " << (int)red	<< endl;
	cout << "G:\t" << bitset<8>(green)	<< " = " << (int)green	<< endl;
	cout << "B:\t" << bitset<8>(blue)	<< " = " << (int)blue	<< endl;
	cout << "A:\t" << bitset<8>(alpha)	<< " = " << (int)alpha	<< endl;

	return 0;
}