#include <gtk/gtk.h>

void main_ui(GtkApplication *app, gpointer *user_data);

void quit_activate(GSimpleAction *simple_action, GVariant *parameter, gpointer app);
void preference_activate(GSimpleAction *simple_action, GVariant *parameter, gpointer str);

static GActionEntry app_entrys[] = {
    {.name = "quit", .activate = quit_activate, NULL, NULL, NULL} //,
    // {.name = "preferences", .activate = preference_activate, .parameter_type="s", NULL, NULL}
};

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
    GtkWidget *window;
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), (gchar *)user_data);

    GtkBuilder *builder;
    GMenuModel *app_menu;
    GMenuModel *menubar;

    builder = gtk_builder_new_from_file("menu.ui");
    menubar = G_MENU_MODEL(gtk_builder_get_object(builder, "menubar"));
    gtk_application_set_menubar(app, menubar);
    app_menu = G_MENU_MODEL(gtk_builder_get_object(builder, "appmenu"));
    gtk_application_set_app_menu(app, app_menu);

    GSimpleAction *action_prefere = g_simple_action_new("preferences", NULL /*G_VARIANT_TYPE_STRING*/);
    g_signal_connect(action_prefere, "activate", G_CALLBACK(preference_activate), "Yogi");
    g_action_map_add_action_entries(G_ACTION_MAP(app), app_entrys, G_N_ELEMENTS(app_entrys), app);
    g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action_prefere));

    gtk_widget_show_all(window);
}

void quit_activate(GSimpleAction *simple_action, GVariant *parameter, gpointer app)
{
    (void)simple_action;
    (void)parameter;
    g_application_quit(G_APPLICATION(app));
}

void preference_activate(GSimpleAction *simple_action, GVariant *parameter, gpointer str)
{
    (void)simple_action;
    (void)parameter;
    g_print("preference menu clicked: %s\n",(gchar*)str);
}