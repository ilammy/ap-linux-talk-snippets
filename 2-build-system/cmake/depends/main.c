#include "hello.h"

#include <stdlib.h>

int main(int argc, char *argv[])
{
	int count = 10;

	if (argc > 1) {
		count = atoi(argv[1]);
	}

	hello("feeble peasants", count);

	return 0;
}
