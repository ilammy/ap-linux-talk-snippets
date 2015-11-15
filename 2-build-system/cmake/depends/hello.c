#include "hello.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

static void* print_hello(void* arg)
{
	const char *string = (const char*) arg;

	printf("Hello, %s from thread %lu!\n", string, (unsigned long) pthread_self());

	return NULL;
}

void hello(const char *who, int count)
{
	pthread_t *threads = calloc(count, sizeof(threads[0]));

	assert(threads);

	for (int i = 0; i < count; i++) {
		pthread_create(&threads[i], NULL, print_hello, (void*) who);
	}

	for (int i = 0; i < count; i++) {
		pthread_join(threads[i], NULL);
	}

	free(threads);
}
