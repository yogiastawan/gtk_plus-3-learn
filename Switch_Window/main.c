#include <gtk/gtk.h>

#include "myappwindow.h"

void main_ui(GtkApplication *app, gpointer *user_data);

int main(int argc, char *argv[])
{
    GtkApplication *app;
    int status;
    app = gtk_application_new("id.yogiastawan.switchwindow", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(main_ui), "Test Notification");
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

void main_ui(GtkApplication *app, gpointer *user_data){
    MyAppWindow *win_app;

    win_app=my_app_window_new(app);

}
