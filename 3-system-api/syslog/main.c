#include <syslog.h>

int main(void)
{
	openlog("syslog-example", LOG_PID, LOG_USER);

	syslog(LOG_DEBUG, "will send 5 messages");

	for (int i = 0; i < 5; i++) {
		syslog(LOG_INFO, "message %i", i);
	}

	closelog();

	return 0;
}
