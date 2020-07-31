#include "mywidget.h"

/* Properties enum*/
enum
{
    P_0,    // for padding
    P_VALUE // for value
};

/* Private data structure */
struct _MyWidgetPrivate
{
    gdouble value;
    GdkWindow *window;
};

/* Internal API */
static void my_widget_set_property(GObject *object, guint prop_id, const GValue *value, GParamSpec *pspec);
static void my_widget_get_property(GObject *object, guint prop_id, GValue *value, GParamSpec *pspec);
static void my_widget_size_allocate(GtkWidget *widget, GtkAllocation *allocation);
static void my_widget_realize(GtkWidget *widget);
static gboolean my_widget_draw(GtkWidget *widget, cairo_t *cr);
static void my_widget_get_preferred_height(GtkWidget *widget, gint *minimum_height, gint *natural_height);
static void my_widget_get_preferred_width(GtkWidget *widget, gint *minimum_width, gint *natural_width);
// static void my_widget_size_request(GtkWidget *widget,GtkRequisition *requisition);

/* Define type */
// G_DEFINE_TYPE(MyWidget, my_widget, GTK_TYPE_WIDGET);
G_DEFINE_TYPE_WITH_PRIVATE(MyWidget,my_widget,GTK_TYPE_WIDGET);

/* Initialization */
static void my_widget_class_init(MyWidgetClass *klass)
{
    GObjectClass *g_class;
    GtkWidgetClass *w_class;
    GParamSpec *pspec;

    g_class = G_OBJECT_CLASS(klass);
    /* Override widget class methods */
    g_class->set_property = my_widget_set_property;
    g_class->get_property = my_widget_get_property;

    w_class = GTK_WIDGET_CLASS(klass);
    /* Override widget class methods */
    w_class->realize = my_widget_realize;
    w_class->get_preferred_height = my_widget_get_preferred_height;
    w_class->get_preferred_width = my_widget_get_preferred_width;
    // w_class->size_request=my_widget_size_request;
    w_class->size_allocate = my_widget_size_allocate;
    w_class->draw = my_widget_draw;

    /* Install Property */
    pspec=g_param_spec_double("value","Value","Value will show",0,1,0,G_PARAM_READWRITE|G_PARAM_STATIC_STRINGS);

    g_object_class_install_property(g_class,P_VALUE,pspec);

    /* Add private data*/
    // G_ADD_PRIVATE()
}

static void my_widget_init(MyWidget *widget)
{
    MyWidgetPrivate *priv;
    // priv = G_TYPE_INSTANCE_GET_PRIVATE(widget, MY_TYPE_WIDGET, MyWidgetPrivate);
    priv=my_widget_get_instance_private(widget);
    gtk_widget_set_has_window(GTK_WIDGET(widget), TRUE);

    //set default value
    priv->value = 0;

    //create cache for faster access
    widget->priv = priv;
}

/* Override Methods */
static void my_widget_set_property(GObject *object, guint prop_id, const GValue *value, GParamSpec *pspec)
{
    MyWidget *widget = MY_WIDGET(object);
    switch (prop_id)
    {
    case P_VALUE:
        my_widget_set_value(widget, g_value_get_double(value));
        break;

    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
        break;
    }
}
static void my_widget_get_property(GObject *object, guint prop_id, GValue *value, GParamSpec *pspec)
{
    MyWidget *widget = MY_WIDGET(object);
    switch (prop_id)
    {
    case P_VALUE:
        g_value_set_double(value, widget->priv->value);
        break;

    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
        break;
    }
}
static void my_widget_size_allocate(GtkWidget *widget, GtkAllocation *allocation)
{
    MyWidgetPrivate *priv = MY_WIDGET(widget)->priv;
    gtk_widget_set_allocation(widget, allocation);
    if (gtk_widget_get_realized(widget))
    {
        gdk_window_move_resize(priv->window, allocation->x, allocation->y, allocation->width, allocation->height);
    }
}
static void my_widget_realize(GtkWidget *widget)
{
    MyWidgetPrivate *priv = MY_WIDGET(widget)->priv;
    GtkAllocation alloc;
    GdkWindowAttr attrs;
    gint attrs_mask;

    gtk_widget_set_realized(widget, TRUE);
    gtk_widget_get_allocation(widget, &alloc);
    attrs.x = alloc.x;
    attrs.y = alloc.y;
    attrs.width = alloc.width;
    attrs.height = alloc.height;
    attrs.window_type = GDK_WINDOW_CHILD;
    attrs.wclass = GDK_INPUT_OUTPUT;
    attrs.event_mask = gtk_widget_get_events(widget) | GDK_EXPOSURE_MASK;

    attrs_mask = GDK_WA_X | GDK_WA_Y;

    priv->window = gdk_window_new(gtk_widget_get_parent_window(widget), &attrs, attrs_mask);
    gdk_window_set_user_data(priv->window, widget);
    gtk_widget_set_window(widget, priv->window);
    //style
}
static gboolean my_widget_draw(GtkWidget *widget, cairo_t *cr)
{
    MyWidgetPrivate *priv = MY_WIDGET(widget)->priv;
    GtkAllocation alloc;
    gtk_widget_get_allocation(widget,&alloc);
    cairo_set_source_rgb(cr,0,0,1);
    cairo_rectangle(cr,0*priv->value,0,(double)alloc.width,(double)alloc.height);
    cairo_fill(cr);
    // cairo_destroy(cr);
    return FALSE;
}
static void my_widget_get_preferred_height(GtkWidget *widget, gint *minimum_height, gint *natural_height)
{
    (void)widget;
    *minimum_height = 90;
    *natural_height = 300;
}
static void my_widget_get_preferred_width(GtkWidget *widget, gint *minimum_width, gint *natural_width)
{
    (void)widget;
    *minimum_width = 90;
    *natural_width = 300;
}

/* Public API */
GtkWidget *my_widget_new(void){
    return (g_object_new(MY_TYPE_WIDGET,NULL));
}

gdouble my_widget_get_value(MyWidget *widget){
    g_return_val_if_fail(MY_IS_WIDGET(widget),0);
    return (widget->priv->value);
}

void my_widget_set_value(MyWidget *widget, gdouble value){
    g_return_if_fail(MY_IS_WIDGET(widget));
    widget->priv->value=value;
    gtk_widget_queue_draw(GTK_WIDGET(widget));
}