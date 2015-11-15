#include <stdio.h>
#include <errno.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	int fd = -1;
	int ret = 0;

	// Opening a file

	errno = 0;
	fd = open("./example.txt", O_RDONLY);
	if (fd < 0) {
		perror("failed to open file");
		return 1;
	}

	// Querying file size

	struct stat stat;

	errno = 0;
	ret = fstat(fd, &stat);
	if (ret < 0) {
		perror("failed to stat the file");
		goto error;
	}

	// Reading the file

	char buffer[32];
	off_t need = stat.st_size;

	do {
		errno = 0;
		ssize_t count = read(fd, buffer, sizeof(buffer));

		if (count < 0) {
			perror("failed to read the file");
			goto error;
		}

		need -= count;

		errno = 0;
		ssize_t wrote = write(STDOUT_FILENO, buffer, count);

		if (wrote < 0) {
			perror("failed to dump to stdout");
			goto error;
		}
	} while (need > 0);

	// Closing the file
error:
	errno = 0;
	ret = close(fd);
	if (ret < 0) {
		perror("failed to close the file");
	}

	return ret;
}
