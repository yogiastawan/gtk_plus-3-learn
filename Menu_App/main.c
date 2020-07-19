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
    GtkWidget *window;
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), (gchar *)user_data);

    // GtkWidget *vbox;
    GtkWidget *menubar;
    GtkWidget *menu;
    GtkWidget *menuH;
    GtkWidget *menuFile;    
    GtkWidget *menuFileItemQuite;
    GtkWidget *menuFileItemSave;
    GtkWidget *menuFileItemMenu;
    GtkWidget *menuHelp;
    GtkWidget *menuHelpItemAbout;

    menubar=gtk_menu_bar_new();

    menu=gtk_menu_new();
    menuFile=gtk_menu_item_new_with_mnemonic("_File");
    menuFileItemSave=gtk_menu_item_new_with_label("Save");
    menuFileItemQuite=gtk_menu_item_new_with_label("Close");
    menuFileItemMenu=gtk_menu_item_new();//with image
    gtk_menu_item_set_label(GTK_MENU_ITEM(menuFileItemMenu),"Menu");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuFile),menu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu),menuFileItemSave);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu),menuFileItemMenu);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu),menuFileItemQuite);

    menuH=gtk_menu_new();
    menuHelp=gtk_menu_item_new_with_mnemonic("He_lp");//with mnemonic->alt+l
    menuHelpItemAbout=gtk_menu_item_new_with_label("About");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuHelp),menuH);
    gtk_menu_shell_append(GTK_MENU_SHELL(menuH),menuHelpItemAbout);

    gtk_menu_shell_append(GTK_MENU_SHELL(menubar),menuFile);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar),menuHelp);

    // gtk_box_pack_start(GTK_BOX(vbox),menubar,FALSE,FALSE,0);
    gtk_container_add(GTK_CONTAINER(window),menubar);

    // GtkWidget *button_box;
    // GtkWidget *button;
    // button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    // gtk_container_add(GTK_CONTAINER(window), button_box);

    // button = gtk_button_new_with_label("Click me...");
    // gtk_container_add(GTK_CONTAINER(button_box), button);



    gtk_widget_show_all(window);    
}

