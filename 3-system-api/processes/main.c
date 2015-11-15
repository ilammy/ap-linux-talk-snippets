#include <stdio.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	printf("Running...\n");

	pid_t pid;

	if ((pid = fork())) {
		printf("Hello from parent. I'm %d, my parent is %d, I got %d from fork()\n", getpid(), getppid(), pid);

		printf("Parent waiting for child...\n");

		int status = -1;
		pid = wait(&status);

		printf("Child %d died and left us this: %d\n", pid, status);
	} else {
		printf("Hello from child.  I'm %d, my parent is %d, I got %d from fork()\n", getpid(), getppid(), pid);

		char *args[] = { "KAZOOMBA", ".", NULL };
		char *env[] = { NULL };

		printf("Child running ls:\n");

		execve("/bin/ls", args, env);
	}

	printf("Done %d\n", getpid());

	return 0;
}
