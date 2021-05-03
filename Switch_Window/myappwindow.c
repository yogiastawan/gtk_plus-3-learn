#include <gtk/gtk.h>

#include "myappwindow.h"

struct _MyAppWindow
{
    GtkApplicationWindow *parent;
};

typedef struct _MyAppWindowPrivate MyAppWindowPrivate;

struct _MyAppWindowPrivate
{
    GtkWidget *stack;
};

G_DEFINE_TYPE_WITH_PRIVATE(MyAppWindow, my_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void my_app_window_init(MyAppWindow *win)
{
    gtk_window_set_title(GTK_WINDOW(win),"Entry");
}
static void my_app_window_class_init(MyAppWindowClass *class)
{
    GtkWidgetClass *w_class;
    w_class=GTK_WIDGET_CLASS(class);
}

MyAppWindow *my_app_window_new(GtkApplication *app)
{
    g_return_val_if_fail(GTK_IS_APPLICATION(app),NULL);
    return g_object_new(MY_APP_WINDOW_TYPE, "application", app, NULL);
}