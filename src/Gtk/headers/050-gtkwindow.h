// GTKWINDOW
GtkWidget *gtk_window_new (GtkWindowType);
void gtk_window_set_title (GtkWindow *, const gchar *);
void gtk_window_get_title (GtkWindow *);
void gtk_window_set_resizable (GtkWindow *, gboolean);
gboolean gtk_window_get_resizable (GtkWindow *);
void gtk_window_set_modal (GtkWindow *, gboolean);
gboolean gtk_window_get_modal (GtkWindow *);
void gtk_window_set_default_size (GtkWindow *, gint, gint);
void gtk_window_get_default_size (GtkWindow *window, gint *width, gint *height);
void gtk_window_set_position (GtkWindow *, GtkWindowPosition);
void gtk_window_get_position (GtkWindow *window, gint *root_x, gint *root_y);
void gtk_window_set_transient_for (GtkWindow *, GtkWindow *);
void gtk_window_set_attached_to (GtkWindow *, GtkWidget *);
void gtk_window_set_destroy_with_parent (GtkWindow *, gboolean);
void gtk_window_set_hide_titlebar_when_maximized (GtkWindow *, gboolean);