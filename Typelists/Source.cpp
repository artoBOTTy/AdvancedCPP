#include "Typelists.h"

int main()
{
	typedef TYPELIST_02(char, unsigned char) terminator;

	RCV::Length<terminator>::value;

	RCV::TypeAt<terminator, 0>::Type temp;
	
	RCV::IndexOf<terminator, int>::index;

	return 0; 
}