#include <gtk/gtk.h>

void show_notification(GtkWidget *widget, gpointer *app);
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

    GtkWidget *button_box;
    GtkWidget *button;
    button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_container_add(GTK_CONTAINER(window), button_box);

    button = gtk_button_new_with_label("Click me...");
    g_signal_connect(button, "clicked", G_CALLBACK(show_notification), app);
    gtk_container_add(GTK_CONTAINER(button_box), button);

    gtk_widget_show_all(window);
}

void show_notification(GtkWidget *widget, gpointer *app)
{
    if (GTK_IS_BUTTON(widget))
    {
        GNotification *notification;
        notification = g_notification_new("New Message");
        g_notification_set_body(notification, "This is your message from your friends...");
        GIcon *icon = g_themed_icon_new("7765_winebrowser.0");
        g_notification_set_icon(notification, icon);
        g_notification_set_priority(notification, G_NOTIFICATION_PRIORITY_NORMAL);
        g_notification_add_button(notification, "reply", "app.NULL");
        //add action

        g_application_send_notification(G_APPLICATION(app), "test-1", notification);
        g_object_unref(notification);
        g_object_unref(icon);
    }
}