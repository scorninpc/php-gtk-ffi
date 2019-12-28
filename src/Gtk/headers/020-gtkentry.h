// GTKENTRY

typedef enum
{
  GTK_ENTRY_ICON_PRIMARY,
  GTK_ENTRY_ICON_SECONDARY
} GtkEntryIconPosition;

typedef struct _GtkEntry              GtkEntry;
typedef struct _GtkEntryClass         GtkEntryClass;

struct _GtkEntry
{
  GtkWidget  parent_instance;
};

struct _GtkEntryClass
{
  GtkWidgetClass parent_class;

  gpointer padding[8];
};




// GType gtk_entry_get_type (void);
GtkWidget* gtk_entry_new (void);
// GtkWidget* gtk_entry_new_with_buffer (GtkEntryBuffer *buffer);
// GtkEntryBuffer* gtk_entry_get_buffer (GtkEntry *entry);
// void gtk_entry_set_buffer (GtkEntry *entry, GtkEntryBuffer *buffer);
void gtk_entry_set_visibility (GtkEntry *entry, gboolean visible);
gboolean gtk_entry_get_visibility (GtkEntry *entry);
void gtk_entry_set_invisible_char (GtkEntry *entry, gunichar ch);
gunichar gtk_entry_get_invisible_char (GtkEntry *entry);
void gtk_entry_unset_invisible_char (GtkEntry *entry);
void gtk_entry_set_has_frame (GtkEntry *entry, gboolean setting);
gboolean gtk_entry_get_has_frame (GtkEntry *entry);
void gtk_entry_set_overwrite_mode (GtkEntry *entry, gboolean overwrite);
gboolean gtk_entry_get_overwrite_mode (GtkEntry *entry);
void gtk_entry_set_max_length (GtkEntry *entry, gint max);
gint gtk_entry_get_max_length (GtkEntry *entry);
guint16 gtk_entry_get_text_length (GtkEntry *entry);
void gtk_entry_set_activates_default (GtkEntry *entry, gboolean setting);
gboolean gtk_entry_get_activates_default (GtkEntry *entry);
void gtk_entry_set_alignment (GtkEntry *entry, gfloat xalign);
gfloat gtk_entry_get_alignment (GtkEntry *entry);
// void gtk_entry_set_completion (GtkEntry *entry, GtkEntryCompletion *completion);
// GtkEntryCompletion *gtk_entry_get_completion (GtkEntry *entry);
void gtk_entry_set_progress_fraction (GtkEntry *entry, gdouble fraction);
gdouble gtk_entry_get_progress_fraction (GtkEntry *entry);
void gtk_entry_set_progress_pulse_step (GtkEntry *entry, gdouble fraction);
gdouble gtk_entry_get_progress_pulse_step (GtkEntry *entry);
void gtk_entry_progress_pulse (GtkEntry *entry);
const gchar* gtk_entry_get_placeholder_text (GtkEntry *entry);
void gtk_entry_set_placeholder_text (GtkEntry *entry, const gchar *text);
// void gtk_entry_set_icon_from_paintable (GtkEntry *entry, GtkEntryIconPosition  icon_pos, GdkPaintable *paintable);
void gtk_entry_set_icon_from_icon_name (GtkEntry *entry, GtkEntryIconPosition  icon_pos, const gchar *icon_name);
// void gtk_entry_set_icon_from_gicon (GtkEntry *entry, GtkEntryIconPosition  icon_pos, GIcon *icon);
// GtkImageType gtk_entry_get_icon_storage_type (GtkEntry *entry, GtkEntryIconPosition  icon_pos);
// GdkPaintable * gtk_entry_get_icon_paintable (GtkEntry *entry, GtkEntryIconPosition  icon_pos);
const gchar* gtk_entry_get_icon_name (GtkEntry *entry, GtkEntryIconPosition  icon_pos);
// GIcon* gtk_entry_get_icon_gicon (GtkEntry *entry, GtkEntryIconPosition  icon_pos);
void gtk_entry_set_icon_activatable (GtkEntry *entry, GtkEntryIconPosition  icon_pos, gboolean activatable);
gboolean gtk_entry_get_icon_activatable (GtkEntry *entry, GtkEntryIconPosition  icon_pos);
void gtk_entry_set_icon_sensitive (GtkEntry *entry, GtkEntryIconPosition  icon_pos, gboolean sensitive);
gboolean gtk_entry_get_icon_sensitive (GtkEntry *entry, GtkEntryIconPosition  icon_pos);
gint gtk_entry_get_icon_at_pos (GtkEntry *entry, gint x, gint y);
void gtk_entry_set_icon_tooltip_text (GtkEntry *entry, GtkEntryIconPosition  icon_pos, const gchar *tooltip);
gchar * gtk_entry_get_icon_tooltip_text (GtkEntry *entry, GtkEntryIconPosition  icon_pos);
void gtk_entry_set_icon_tooltip_markup (GtkEntry *entry, GtkEntryIconPosition  icon_pos, const gchar *tooltip);
gchar * gtk_entry_get_icon_tooltip_markup (GtkEntry *entry, GtkEntryIconPosition  icon_pos);
// void gtk_entry_set_icon_drag_source (GtkEntry *entry, GtkEntryIconPosition  icon_pos, GdkContentFormats *formats, GdkDragAction actions);
gint gtk_entry_get_current_icon_drag_source (GtkEntry *entry);
void gtk_entry_get_icon_area (GtkEntry *entry, GtkEntryIconPosition icon_pos, GdkRectangle *icon_area);
void gtk_entry_reset_im_context (GtkEntry *entry);
// void gtk_entry_set_input_purpose (GtkEntry *entry, GtkInputPurpose purpose);
// GtkInputPurpose gtk_entry_get_input_purpose (GtkEntry *entry);
// void gtk_entry_set_input_hints (GtkEntry *entry, GtkInputHints hints);
// GtkInputHints   gtk_entry_get_input_hints (GtkEntry *entry);
// void gtk_entry_set_attributes (GtkEntry *entry, PangoAttrList *attrs);
// PangoAttrList  *gtk_entry_get_attributes (GtkEntry *entry);
// void gtk_entry_set_tabs (GtkEntry *entry, PangoTabArray *tabs);
// PangoTabArray *gtk_entry_get_tabs (GtkEntry *entry);
gboolean gtk_entry_grab_focus_without_selecting (GtkEntry *entry);
// void gtk_entry_set_extra_menu (GtkEntry *entry, GMenuModel *model);
// GMenuModel * gtk_entry_get_extra_menu (GtkEntry *entry);


const gchar *gtk_entry_get_text (GtkEntry *entry);
void gtk_entry_set_text (GtkEntry *entry, const gchar *text);