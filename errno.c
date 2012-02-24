#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <defy/expect>
#include <defy/nil>

int main(int argc, char *argv[]) {
	if (unlikely(argc < 2)) {
		fprintf(stderr, "Usage: %s [ error number ]\n", argv[0]);
		return EXIT_FAILURE;
	}

	errno = 0;
	long num = strtol(argv[1], nil, 0);
	if (unlikely(errno)) {
		fprintf(stderr, "Invalid error number “%s”: %s\n",
			argv[1], strerror(errno));
		return EXIT_FAILURE;
	}

	if (unlikely(num < INT_MIN) ||
		unlikely(num > INT_MAX)) {
		fprintf(stderr, "Error number %li out of range\n", num);
		return EXIT_FAILURE;
	}

	puts(strerror(num));
	return EXIT_SUCCESS;
}
