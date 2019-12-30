

struct _GtkContainerClass
{
  GtkWidgetClass parent_class;
  gpointer padding[8];
};

// GTKCONTAINER

void gtk_container_add (GtkContainer *container, GtkWidget *widget);

void gtk_container_remove (GtkContainer *container, GtkWidget *widget);

// void gtk_container_add_with_properties (GtkContainer *container, GtkWidget *widget, gchar *first_prop_name, ...);

// void gtk_container_check_resize (GtkContainer *container);

void gtk_container_foreach (GtkContainer *container, GCallback callback, gpointer callback_data);

GList * gtk_container_get_children (GtkContainer *container);

// GtkWidgetPath * gtk_container_get_path_for_child (GtkContainer *container, GtkWidget *child);


GtkWidget * gtk_container_get_focus_child (GtkContainer *container);

void gtk_container_set_focus_child (GtkContainer *container, GtkWidget *child);

// GtkAdjustment * gtk_container_get_focus_vadjustment (GtkContainer *container);

// void gtk_container_set_focus_vadjustment (GtkContainer *container, GtkAdjustment *adjustment);

// GtkAdjustment * gtk_container_get_focus_hadjustment (GtkContainer *container);

// void gtk_container_set_focus_hadjustment (GtkContainer *container, GtkAdjustment *adjustment);


GType gtk_container_child_type (GtkContainer *container);

void gtk_container_child_get (GtkContainer *container, GtkWidget *child, gchar *first_prop_name, ...);

void gtk_container_child_set (GtkContainer *container, GtkWidget *child, gchar *first_prop_name, ...);

void gtk_container_child_get_property (GtkContainer *container, GtkWidget *child, gchar *property_name, GValue *value);

void gtk_container_child_set_property (GtkContainer *container, GtkWidget *child, gchar *property_name, GValue *value);

void gtk_container_child_get_valist (GtkContainer *container, GtkWidget *child, gchar *first_property_name, va_list var_args);

void gtk_container_child_set_valist (GtkContainer *container, GtkWidget *child, gchar *first_property_name, va_list var_args);

void gtk_container_child_notify (GtkContainer *container, GtkWidget *child, gchar *child_property);

// void gtk_container_child_notify_by_pspec (GtkContainer *container, GtkWidget *child, GParamSpec *pspec);

void gtk_container_forall (GtkContainer *container, GCallback callback, gpointer callback_data);

guint gtk_container_get_border_width (GtkContainer *container);

void gtk_container_set_border_width (GtkContainer *container, guint border_width);

// void gtk_container_propagate_draw (GtkContainer *container, GtkWidget *child, cairo_t *cr);

// GParamSpec * gtk_container_class_find_child_property (GObjectClass *cclass, gchar *property_name);

// void gtk_container_class_install_child_property (GtkContainerClass *cclass, guint property_id, GParamSpec *pspec);

// void gtk_container_class_install_child_properties (GtkContainerClass *cclass, guint n_pspecs, GParamSpec **pspecs);

// GParamSpec ** gtk_container_class_list_child_properties (GObjectClass *cclass, guint *n_properties);

void gtk_container_class_handle_border_width (GtkContainerClass *klass);

