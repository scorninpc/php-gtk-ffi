
GtkAccelGroup * gtk_accel_group_new (void);

// void gtk_accel_group_connect (GtkAccelGroup *accel_group, guint accel_key, GdkModifierType accel_mods, GtkAccelFlags accel_flags, GClosure *closure);

void gtk_accel_group_connect_by_path (GtkAccelGroup *accel_group, gchar *accel_path, GClosure *closure);

gboolean gtk_accel_group_disconnect (GtkAccelGroup *accel_group, GClosure *closure);

gboolean gtk_accel_group_disconnect_key (GtkAccelGroup *accel_group, guint accel_key, GdkModifierType accel_mods);

// gboolean gtk_accel_group_activate (GtkAccelGroup *accel_group, GQuark accel_quark, GObject *acceleratable, guint accel_key, GdkModifierType accel_mods);

void gtk_accel_group_lock (GtkAccelGroup *accel_group);

void gtk_accel_group_unlock (GtkAccelGroup *accel_group);

gboolean gtk_accel_group_get_is_locked (GtkAccelGroup *accel_group);

GtkAccelGroup * gtk_accel_group_from_accel_closure (GClosure *closure);

GdkModifierType gtk_accel_group_get_modifier_mask (GtkAccelGroup *accel_group);

gboolean gtk_accel_groups_activate (GObject *object, guint accel_key, GdkModifierType accel_mods);

GSList * gtk_accel_groups_from_object (GObject *object);

// GtkAccelKey * gtk_accel_group_find (GtkAccelGroup *accel_group, GtkAccelGroupFindFunc find_func, gpointer data);

gboolean gtk_accelerator_valid (guint keyval, GdkModifierType modifiers);

void gtk_accelerator_parse (gchar *accelerator, guint *accelerator_key, GdkModifierType *accelerator_mods);

gchar * gtk_accelerator_name (guint accelerator_key, GdkModifierType accelerator_mods);

gchar * gtk_accelerator_get_label (guint accelerator_key, GdkModifierType accelerator_mods);

void gtk_accelerator_parse_with_keycode (gchar *accelerator, guint *accelerator_key, guint **accelerator_codes, GdkModifierType *accelerator_mods);

// gchar * gtk_accelerator_name_with_keycode (GdkDisplay *display, guint accelerator_key, guint keycode, GdkModifierType accelerator_mods);

// gchar * gtk_accelerator_get_label_with_keycode (GdkDisplay *display, guint accelerator_key, guint keycode, GdkModifierType accelerator_mods);

void gtk_accelerator_set_default_mod_mask (GdkModifierType default_mod_mask);

GdkModifierType gtk_accelerator_get_default_mod_mask (void);

