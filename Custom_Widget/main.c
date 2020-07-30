#include <gtk/gtk.h>

void main_ui(GtkApplication *app, gpointer *user_data);

int main(int argc, char *argv[])
{
    GtkApplication *app;
    int status;
    app = gtk_application_new("id.yogiastawan.app2", G_APPLICATION_FLAGS_NONE);
    // g_application_register(G_APPLICATION(app), NULL, NULL);//for show notif when startup
    g_signal_connect(app, "activate", G_CALLBACK(main_ui), "Test Notification");
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

void main_ui(GtkApplication *app, gpointer *user_data)
{
    GtkWidget *window;
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), (gchar *)user_data);

    gtk_widget_show_all(window);
}
