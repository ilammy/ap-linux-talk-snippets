#include <stdbool.h>
#include <string.h>

#include <X11/Xlib.h>

int main(void)
{
	Display *display = XOpenDisplay(NULL);

	Window window = XCreateSimpleWindow(display,
		DefaultRootWindow(display), 100, 100, 140, 80, 0, 0, 0xFFFFFF);

	GC gc = XCreateGC(display, window, 0, NULL);

	XStoreName(display, window, "Example");
	XSelectInput(display, window, ExposureMask);
	XMapRaised(display, window);

	bool running = true;
	while (running) {
		XEvent event;

		XNextEvent(display, &event);

		switch (event.type) {
		case Expose:
			if (event.xexpose.window == window) {
				XDrawString(display, window, gc, 30, 30, "Press me", strlen("Press me"));
			}
			break;

		case ClientMessage:
			running = false;
			break;
		}
	}

	XUnmapWindow(display, window);
	XFreeGC(display, gc);
	XDestroyWindow(display, window);
	XCloseDisplay(display);

	return 0;
}
