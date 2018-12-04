#include "CompileTimeAssert.h"

int main()
{
	STATIC_CHECK( (0 == 0), "What_the_hell");

	return 0;
}