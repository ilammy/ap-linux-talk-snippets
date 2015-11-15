#include <gtk/gtk.h>

static window_destroy(GtkWidget* window, gpointer data)
{
	gtk_main_quit();
}

static button_clicked(GtkWidget* button, gpointer data)
{
	GtkWidget* dialog = NULL;
	GtkWidget* window = (GtkWidget*) data;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window),
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_INFO,
			GTK_BUTTONS_OK,
			"Hello world!"
	);

	gtk_dialog_run(GTK_DIALOG(dialog));

	gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[])
{
	GtkWidget* window = NULL;
	GtkWidget* button = NULL;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title(GTK_WINDOW(window), "Example");

	g_signal_connect(window, "destroy", G_CALLBACK(window_destroy), NULL);

	button = gtk_button_new_with_label("Press me");

	g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), window);

	gtk_container_add(GTK_CONTAINER(window), button);

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
