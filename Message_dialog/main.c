#include <gtk/gtk.h>

void main_ui(GtkApplication *app, gpointer *user_data);

void quit_activate(GSimpleAction *simple_action, GVariant *parameter, gpointer app);
void preference_activate(GSimpleAction *simple_action, GVariant *parameter, gpointer str);

//new
void dialogmessage(GSimpleAction *simple_action, GVariant *parameter, gpointer datas);

static GActionEntry app_entrys[] = {
    {.name = "quit", .activate = quit_activate, NULL, NULL, NULL},
    {.name = "preferences", .activate = preference_activate, .parameter_type = NULL, NULL, NULL}};

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

    GSimpleAction *action_message = g_simple_action_new("save", NULL /*G_VARIANT_TYPE_STRING*/);
    g_signal_connect(action_message, "activate", G_CALLBACK(dialogmessage), window);
    g_action_map_add_action_entries(G_ACTION_MAP(app), app_entrys, G_N_ELEMENTS(app_entrys), app);
    g_action_map_add_action(G_ACTION_MAP(app), G_ACTION(action_message));

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
    (void)str;
    g_print("preference menu clicked\n");
}

void dialogmessage(GSimpleAction *simple_action, GVariant *parameter, gpointer datas)
{
    (void)simple_action;
    (void)parameter;
    GtkWidget *dialog;

    dialog = gtk_message_dialog_new((GtkWindow *)datas, GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK_CANCEL, "Hiiii. Iam dialog...");    
    gint respon = gtk_dialog_run((GtkDialog *)dialog);
    g_print("respon: %d\n", respon);

    gtk_widget_destroy(dialog);
}