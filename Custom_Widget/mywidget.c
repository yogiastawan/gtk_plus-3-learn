#include "mywidget.h"

/* Properties enum*/
enum{
    P_0, // for padding
    P_VALUE // for value
};

/* Private data structure */
struct _MyWidgetPrivate{
    gdouble value;
    GdkWindow *window;
};

const gint WIDTH=100;
const gint HEIGHT=100;

/* Internal API */
static void my_widget_set_property(GObject *object,guint prop_id, const GValue *value,GParamSpec *pspec);
static void my_widget_get_property(GObject *object,guint prop_id, GValue *value,GParamSpec *pspec);
static void my_widget_size_request(GtkWidget *widget, GtkRequisition *requisition);
static void my_widget_size_allocate(GtkWidget *widget, GtkAllocation *allocation);
static void my_widget_realize(GtkWidget *widget);
static gboolean my_widget_draw(GtkWidget *widget,cairo_t *cr);

/* Define type */
G_DEFINE_TYPE(MyWidget, my_widget, GTK_TYPE_WIDGET);

/* Initialization */
static void my_widget_class_init(MyWidgetClass *klass){
    GObjectClass *g_class;
    GtkWidgetClass *w_class;
    GParamSpec *pspec;

    g_class=G_OBJECT_CLASS(klass);
    /* Override widget class methods */
    g_class->set_property=my_widget_set_property;
    g_class->get_property=my_widget_get_property;

    w_class=GTK_WIDGET_CLASS(klass);
    /* Override widget class methods */
    w_class->realize=my_widget_realize;
    w_class->adjust_size_request=my_widget_size_request;
    w_class->size_allocate=my_widget_size_allocate;
    w_class->draw =my_widget_draw;
}
