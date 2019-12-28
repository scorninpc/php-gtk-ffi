struct _GtkWidget
{
  GInitiallyUnowned parent_instance;
  GtkWidgetPrivate *priv;
};

struct _GtkWidgetClass
{
  GInitiallyUnownedClass parent_class;

  guint activate_signal;
  GtkWidgetClassPrivate *priv;

  gpointer padding[8];
};

// GTKWIDGET
GtkWidget *gtk_widget_new (GType, const gchar *, ...);
void gtk_widget_destroy (GtkWidget *);
gboolean gtk_widget_in_destruction (GtkWidget *);
void gtk_widget_destroyed (GtkWidget *, GtkWidget **);
void gtk_widget_unparent (GtkWidget *);
void gtk_widget_show (GtkWidget *);
void gtk_widget_show_now (GtkWidget *);
void gtk_widget_hide (GtkWidget *);
void gtk_widget_show_all (GtkWidget *);
void gtk_widget_map (GtkWidget *);
void gtk_widget_unmap (GtkWidget *);
void gtk_widget_realize (GtkWidget *);
void gtk_widget_queue_draw (GtkWidget *);
void gtk_widget_queue_resize (GtkWidget *);
void gtk_widget_queue_resize_no_redraw (GtkWidget *);
void gtk_widget_queue_allocate (GtkWidget *);
gint gtk_widget_get_scale_factor (GtkWidget *);
void gtk_widget_size_allocate (GtkWidget *, GtkAllocation *);