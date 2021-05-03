#ifndef __MY_WINDOW_APP_H__
#define __MY_WINDOW_APP_H__

#include <gtk/gtk.h>

#define MY_APP_WINDOW_TYPE (my_app_window_get_type())
G_DECLARE_FINAL_TYPE(MyAppWindow, my_app_window, MY, APP_WINDOW, GtkApplicationWindow);

MyAppWindow *my_app_window_new(GtkApplication *app);

#endif /*__MY_WINDOW_APP_H__*/