// This methods are here because GCallback has GdkEvent to pass that for now
//		need to pass correct params as FFI not support variadic function
typedef void *GCallback (gpointer *widget, GdkEvent *data);
typedef void *GClosureNotify (gpointer data, GClosure *closure);
guint g_signal_lookup (const gchar *name, GType itype);
void g_signal_query (guint signal_id, GSignalQuery *query);
GClosure *g_cclosure_new_swap (GCallback callback_func, gpointer user_data, GClosureNotify destroy_data);
gulong g_signal_connect_closure (gpointer instance, const gchar *detailed_signal, GClosure *closure, gboolean after);
gulong g_signal_connect_object (gpointer instance, const gchar *detailed_signal, GCallback c_handler, gpointer gobject, GConnectFlags connect_flags);
