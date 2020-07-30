#ifndef __MY_WIDGET_H__
#define __MY_WIDGET_H__

#include <gtk/gtk.h>

#include <cairo.h>//for drawing

G_BEGIN_DECLS

/* Standart GObject macros */
#define MY_TYPE_WIDGET (my_widget_get_type())
#define MY_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_CAST((obj),MY_TYPE_WIDGET, MyWidget))
#define MY_WIDGET_CLASS(klass)  (G_TYPE_CHECK_CLASS_CAST((klass),MY_TYPE_WIDGET,MyWidgetClass))
#define MY_IS_WIDGET(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj),MY_TYPE_WIDGET))
#define MY_IS_WIDGET_CLASS(klass) (G_TYPE_CHECk_CLASS_TYPE((klass),MY_TYPE_WIDGET))
#define MY_WIDGET_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS((obj),MY_TYPE_WIDGET,MyWidgetClass))

/* Type definition */
typedef struct _MyWidget MyWidget;
typedef struct _MyWidgetClass MyWidgetClass;
typedef struct _MyWidgetPrivate MyWidgetPrivate;

struct _MyWidget
{
    GtkWidget parent;
    /*< Private >*/
    MyWidgetPrivate *priv;
};

struct _MyWidgetClass
{
    GtkWidgetClass parent_class;
};

/* public API */
GType my_widget_get_type(void) G_GNUC_CONST;
GtkWidget *my_widget_new(void);

//set value widget
void my_widget_set_value(MyWidget *widget, gdouble value);
//get value widget
void my_widget_get_value(MyWidget *widget);

G_END_DECLS

#endif /*__MY_WIDGET_H__*/