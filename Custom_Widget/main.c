#include <gtk/gtk.h>
#include "mywidget.h"

void main_ui(GtkApplication *app, gpointer *user_data);
void addValue(GtkWidget *widget, gpointer *user_data);

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
    GtkWidget *mywidget, *grid, *button;

    grid=gtk_grid_new();
    button=gtk_button_new_with_label("Add value");

    gtk_grid_attach(GTK_GRID(grid),GTK_WIDGET(button),0,1,1,1);

    mywidget=my_widget_new();
    gtk_grid_attach(GTK_GRID(grid),GTK_WIDGET(mywidget),0,0,1,1);    

    g_signal_connect(button,"clicked",G_CALLBACK(addValue),mywidget);

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), (gchar *)user_data);
    gtk_container_add(GTK_CONTAINER(window),grid);

    gtk_widget_show_all(window);
}

void addValue(GtkWidget *widget, gpointer *user_data){
    (void) widget;
    my_widget_set_value(MY_WIDGET(user_data),my_widget_get_value(MY_WIDGET(user_data))+2);
}