#include <gtk/gtk.h>

void main_ui(GtkApplication *app, gpointer *user_data);

int main(int argc, char *argv[])
{
    GtkApplication *app;
    int status;
    app = gtk_application_new("id.yogiastawan.menuapp", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(main_ui), "Test Menu App");
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

void main_ui(GtkApplication *app, gpointer *user_data)
{
    (void) user_data;
    GtkWidget *window;    
    GtkBuilder *builder;
    builder = gtk_builder_new_from_resource("/com/yogiastawan/windowui/window.ui");
    window=GTK_WIDGET(gtk_builder_get_object(builder,"window"));
    gtk_application_add_window(app,(GtkWindow*) window);     

    gtk_widget_show_all(window);
}
