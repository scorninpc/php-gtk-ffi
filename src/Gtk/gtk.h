#define FFI_LIB "/usr/lib/x86_64-linux-gnu/libgtk-3.so.0"

typedef struct _GdkWindow GdkWindow;
typedef struct _GdkDevice GdkDevice;
typedef struct _GdkRectangle GdkRectangle;

typedef struct _GdkPixbuf    GdkPixbuf;
typedef struct _GdkPixbufClass GdkPixbufClass;

typedef struct _GtkWidget GtkWidget;
typedef struct _GtkWidgetClassPrivate  GtkWidgetClassPrivate;
typedef struct _GtkWidgetClass  GtkWidgetClass;

typedef struct _GtkBox GtkBox;
typedef struct _GtkPaned GtkPaned;
typedef struct _GtkContainer GtkContainer;
typedef struct _GtkContainerClass GtkContainerClass;
typedef struct _GtkWindow GtkWindow;

typedef struct _GObject GInitiallyUnowned;

typedef void* gpointer;
typedef char gchar;
typedef bool gboolean;
typedef unsigned long gulong;
typedef int gint;
typedef unsigned int guint;
typedef signed char gint8;
typedef signed char guint8;
typedef signed short guint16;
typedef unsigned int guint32;
typedef unsigned long gulong;
typedef double gdouble;
typedef float gfloat;
typedef gulong GType;
typedef unsigned int gsize;
typedef guint32 gunichar;

//
typedef struct _GSList GSList;



typedef enum
{
  GTK_BASELINE_POSITION_TOP,
  GTK_BASELINE_POSITION_CENTER,
  GTK_BASELINE_POSITION_BOTTOM
} GtkBaselinePosition;

typedef enum
{
  GTK_ORIENTATION_HORIZONTAL,
  GTK_ORIENTATION_VERTICAL
} GtkOrientation;

typedef enum
{
  GTK_PACK_START,
  GTK_PACK_END
} GtkPackType;

struct _GSList
{
  gpointer data;
  GSList *next;
};

//
typedef struct _GList GList;

struct _GList
{
  gpointer data;
  GList *next;
  GList *prev;
};

typedef struct {
  gint x;
  gint y;
  gint width;
  gint height;
} GtkAllocation;

typedef struct _GValue                  GValue;
typedef union  _GTypeCValue             GTypeCValue;
typedef struct _GTypePlugin             GTypePlugin;
typedef struct _GTypeClass              GTypeClass;
typedef struct _GTypeInterface          GTypeInterface;
typedef struct _GTypeInstance           GTypeInstance;
typedef struct _GTypeInfo               GTypeInfo;
typedef struct _GTypeFundamentalInfo    GTypeFundamentalInfo;
typedef struct _GInterfaceInfo          GInterfaceInfo;
typedef struct _GTypeValueTable         GTypeValueTable;
typedef struct _GTypeQuery    GTypeQuery;

typedef struct _GObject                  GObject;
typedef struct _GObjectClass             GObjectClass;
typedef struct _GObject                  GInitiallyUnowned;
typedef struct _GObjectClass             GInitiallyUnownedClass;
typedef struct _GObjectConstructParam    GObjectConstructParam;

typedef struct _GtkWidgetPrivate       GtkWidgetPrivate;


typedef struct _GTypeClass {
    GType g_type;
} GTypeClass;

struct  _GObjectClass
{
  GTypeClass   g_type_class;
  GSList      *construct_properties;
  gsize   flags;
  gpointer  pdummy[6];
};

typedef struct _GTypeInstance {
    GTypeClass *g_class;
} GTypeInstance;

struct  _GObject
{
  GTypeInstance  g_type_instance;
  guint ref_count;
  // GData *qdata;
};

// typedef void  (*GCallback)              (gpointer *widget, GdkEvent *data);

/**
 * https://www.cs.tut.fi/lintula/manual/gtk/gtk/gtk-standard-enumerations.html#GTKWINDOWPOSITION
 * https://lazka.github.io/pgi-docs/Gtk-3.0/enums.html
 *
 */
typedef enum
{
  GTK_WINDOW_TOPLEVEL,
  GTK_WINDOW_POPUP
} GtkWindowType;

typedef enum
{
  GTK_WIN_POS_NONE,
  GTK_WIN_POS_CENTER,
  GTK_WIN_POS_MOUSE
} GtkWindowPosition;


// GTK
void gtk_init(int *, char **[]);
void gtk_main();
void gtk_main_quit();







// GDK

typedef enum {
  GDK_WINDOW_TYPE_HINT_NORMAL  = 0,
  GDK_WINDOW_TYPE_HINT_DIALOG  = 1,
  GDK_WINDOW_TYPE_HINT_MENU  = 2,
  GDK_WINDOW_TYPE_HINT_TOOLBAR   = 3,
  GDK_WINDOW_TYPE_HINT_SPLASHSCREEN  = 4,
  GDK_WINDOW_TYPE_HINT_UTILITY   = 5,
  GDK_WINDOW_TYPE_HINT_DOCK  = 6,
  GDK_WINDOW_TYPE_HINT_DESKTOP   = 7,
  GDK_WINDOW_TYPE_HINT_DROPDOWN_MENU   = 8,
  GDK_WINDOW_TYPE_HINT_POPUP_MENU  = 9,
  GDK_WINDOW_TYPE_HINT_TOOLTIP   = 10,
  GDK_WINDOW_TYPE_HINT_NOTIFICATION  = 11,
  GDK_WINDOW_TYPE_HINT_COMBO   = 12,
  GDK_WINDOW_TYPE_HINT_DND   = 13
} GdkWindowTypeHint;

typedef enum
{
  GDK_NOTHING		= -1,
  GDK_DELETE		= 0,
  GDK_DESTROY		= 1,
  GDK_EXPOSE		= 2,
  GDK_MOTION_NOTIFY	= 3,
  GDK_BUTTON_PRESS	= 4,
  GDK_2BUTTON_PRESS	= 5,
  GDK_3BUTTON_PRESS	= 6,
  GDK_BUTTON_RELEASE	= 7,
  GDK_KEY_PRESS		= 8,
  GDK_KEY_RELEASE	= 9,
  GDK_ENTER_NOTIFY	= 10,
  GDK_LEAVE_NOTIFY	= 11,
  GDK_FOCUS_CHANGE	= 12,
  GDK_CONFIGURE		= 13,
  GDK_MAP		= 14,
  GDK_UNMAP		= 15,
  GDK_PROPERTY_NOTIFY	= 16,
  GDK_SELECTION_CLEAR	= 17,
  GDK_SELECTION_REQUEST = 18,
  GDK_SELECTION_NOTIFY	= 19,
  GDK_PROXIMITY_IN	= 20,
  GDK_PROXIMITY_OUT	= 21,
  GDK_DRAG_ENTER        = 22,
  GDK_DRAG_LEAVE        = 23,
  GDK_DRAG_MOTION       = 24,
  GDK_DRAG_STATUS       = 25,
  GDK_DROP_START        = 26,
  GDK_DROP_FINISHED     = 27,
  GDK_CLIENT_EVENT	= 28,
  GDK_VISIBILITY_NOTIFY = 29,
  GDK_NO_EXPOSE		= 30,
  GDK_SCROLL            = 31,
  GDK_WINDOW_STATE      = 32,
  GDK_SETTING           = 33,
  GDK_OWNER_CHANGE      = 34,
  GDK_GRAB_BROKEN       = 35,
  GDK_DAMAGE            = 36
} GdkEventType;





// GdkEventButton
struct _GdkEventButton
{
  GdkEventType type;
  GdkWindow *window;
  gint8 send_event;
  guint32 time;
  gdouble x;
  gdouble y;
  gdouble *axes;
  guint state;
  guint button;
  GdkDevice *device;
  gdouble x_root, y_root;
} ;
typedef struct _GdkEventButton GdkEventButton;

// GdkEventKey
struct _GdkEventKey
{
  GdkEventType type;
  GdkWindow *window;
  gint8 send_event;
  guint32 time;
  guint state;
  guint keyval;
  guint16 hardware_keycode;
  guint16 key_scancode;
  guint8 group;
  guint is_modifier : 1;
};
typedef struct _GdkEventKey	    GdkEventKey;

// GdkEvent
struct _GdkEvent
{
  GdkEventButton	    button;
  GdkEventKey	    	key;
};
typedef struct _GdkEvent GdkEvent;

// G

typedef void  *GCallback (gpointer *widget, GdkEvent *data);

typedef enum
{
	G_CONNECT_AFTER	= 1 << 0,
	G_CONNECT_SWAPPED	= 1 << 1
} GConnectFlags;

gulong g_signal_connect_object (gpointer instance, const gchar *detailed_signal, GCallback c_handler, gpointer gobject, GConnectFlags connect_flags);

typedef struct {
	guint in_marshal;
	guint is_invalid;
} GClosure;

typedef void *GClosureNotify (gpointer data, GClosure *closure);

typedef enum {
	G_SIGNAL_RUN_FIRST = 1 << 0,
	G_SIGNAL_RUN_LAST = 1 << 1,
	G_SIGNAL_RUN_CLEANUP = 1 << 2,
	G_SIGNAL_NO_RECURSE = 1 << 3,
	G_SIGNAL_DETAILED = 1 << 4,
	G_SIGNAL_ACTION = 1 << 5,
	G_SIGNAL_NO_HOOKS = 1 << 6,
	G_SIGNAL_MUST_COLLECT = 1 << 7,
	G_SIGNAL_DEPRECATED   = 1 << 8
} GSignalFlags;

typedef struct
{
	guint		signal_id;
	const gchar  *signal_name;
	GType		itype;
	GSignalFlags signal_flags;
	GType		return_type; /* mangled with G_SIGNAL_TYPE_STATIC_SCOPE flag */
	guint		n_params;
	const GType  *param_types; /* mangled with G_SIGNAL_TYPE_STATIC_SCOPE flag */
} GSignalQuery;


guint g_signal_lookup (const gchar *name, GType itype);
void g_signal_query (guint signal_id, GSignalQuery *query);
GClosure *g_cclosure_new_swap (GCallback callback_func, gpointer user_data, GClosureNotify destroy_data);
gulong g_signal_connect_closure (gpointer instance, const gchar *detailed_signal, GClosure *closure, gboolean after);


GType g_type_fundamental (GType type_id);
const gchar *g_type_name (GType type);

typedef enum {
	GDK_COLORSPACE_RGB
} GdkColorspace;

struct _GdkPixbuf {
	GObject parent_instance;
	GdkColorspace colorspace;
	int n_channels;
	int bits_per_sample;
	int width, height;
	int rowstride;
	guint has_alpha : 1;
};

struct _GdkPixbufClass {
    GObjectClass parent_class;
};

struct _GError {
  // GQuark       domain;
  gint         code;
  gchar       *message;
};
typedef struct _GError GError;

GdkPixbuf *gdk_pixbuf_new_from_file (const char *filename, GError **error);

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
GdkPixbuf * gtk_entry_get_icon_pixbuf (GtkEntry *entry, GtkEntryIconPosition icon_pos);
void gtk_entry_set_icon_from_pixbuf (GtkEntry *entry, GtkEntryIconPosition icon_pos, GdkPixbuf *pixbuf);
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

GtkWidget * gtk_box_new (GtkOrientation orientation, gint spacing);
void gtk_box_pack_start (GtkBox *box, GtkWidget *child, gboolean expand, gboolean fill, guint padding);
void gtk_box_pack_end (GtkBox *box, GtkWidget *child, gboolean expand, gboolean fill, guint padding);
gboolean gtk_box_get_homogeneous (GtkBox *box);
void gtk_box_set_homogeneous (GtkBox *box, gboolean homogeneous);
gint gtk_box_get_spacing (GtkBox *box);
void gtk_box_set_spacing (GtkBox *box, gint spacing);
void gtk_box_reorder_child (GtkBox *box, GtkWidget *child, gint position);
void gtk_box_query_child_packing (GtkBox *box, GtkWidget *child, gboolean *expand, gboolean *fill, guint *padding, GtkPackType *pack_type);
void gtk_box_set_child_packing (GtkBox *box, GtkWidget *child, gboolean expand, gboolean fill, guint padding, GtkPackType pack_type);
GtkBaselinePosition gtk_box_get_baseline_position (GtkBox *box);
void gtk_box_set_baseline_position (GtkBox *box, GtkBaselinePosition position);
GtkWidget * gtk_box_get_center_widget (GtkBox *box);
void gtk_box_set_center_widget (GtkBox *box, GtkWidget *widget);



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

// void gtk_container_child_get (GtkContainer *container, GtkWidget *child, gchar *first_prop_name, ...);

// void gtk_container_child_set (GtkContainer *container, GtkWidget *child, gchar *first_prop_name, ...);

// void gtk_container_child_get_property (GtkContainer *container, GtkWidget *child, gchar *property_name, GValue *value);

// void gtk_container_child_set_property (GtkContainer *container, GtkWidget *child, gchar *property_name, GValue *value);

// void gtk_container_child_get_valist (GtkContainer *container, GtkWidget *child, gchar *first_property_name, va_list var_args);

// void gtk_container_child_set_valist (GtkContainer *container, GtkWidget *child, gchar *first_property_name, va_list var_args);

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



GtkWidget *gtk_paned_new (GtkOrientation orientation);
void gtk_paned_add1 (GtkPaned *paned, GtkWidget *child);
void gtk_paned_add2 (GtkPaned *paned, GtkWidget *child);
void gtk_paned_pack1 (GtkPaned *paned, GtkWidget *child, gboolean resize, gboolean shrink);
void gtk_paned_pack2 (GtkPaned *paned, GtkWidget *child, gboolean resize, gboolean shrink);
GtkWidget *gtk_paned_get_child1 (GtkPaned *paned);
GtkWidget *gtk_paned_get_child2 (GtkPaned *paned);
void gtk_paned_set_position (GtkPaned *paned, gint position);
gint gtk_paned_get_position (GtkPaned *paned);
// GdkWindow *gtk_paned_get_handle_window (GtkPaned *paned);
void gtk_paned_set_wide_handle (GtkPaned *paned, gboolean wide);
gboolean gtk_paned_get_wide_handle (GtkPaned *paned);

// GTKWINDOW

GtkWidget * gtk_window_new (GtkWindowType type);

void gtk_window_set_title (GtkWindow *window, gchar *title);

// void gtk_window_set_wmclass (GtkWindow *window, gchar *wmclass_name, gchar *wmclass_class);

void gtk_window_set_resizable (GtkWindow *window, gboolean resizable);

gboolean gtk_window_get_resizable (GtkWindow *window);

// void gtk_window_add_accel_group (GtkWindow *window, GtkAccelGroup *accel_group);

// void gtk_window_remove_accel_group (GtkWindow *window, GtkAccelGroup *accel_group);

gboolean gtk_window_activate_focus (GtkWindow *window);

gboolean gtk_window_activate_default (GtkWindow *window);

void gtk_window_set_modal (GtkWindow *window, gboolean modal);

void gtk_window_set_default_size (GtkWindow *window, gint width, gint height);

// void gtk_window_set_default_geometry (GtkWindow *window, gint width, gint height);

// void gtk_window_set_geometry_hints (GtkWindow *window, GtkWidget *geometry_widget, GdkGeometry *geometry, GdkWindowHints geom_mask);

// void gtk_window_set_gravity (GtkWindow *window, GdkGravity gravity);

// GdkGravity gtk_window_get_gravity (GtkWindow *window);

void gtk_window_set_position (GtkWindow *window, GtkWindowPosition position);

void gtk_window_set_transient_for (GtkWindow *window, GtkWindow *parent);

void gtk_window_set_attached_to (GtkWindow *window, GtkWidget *attach_widget);

void gtk_window_set_destroy_with_parent (GtkWindow *window, gboolean setting);

void gtk_window_set_hide_titlebar_when_maximized (GtkWindow *window, gboolean setting);

// void gtk_window_set_screen (GtkWindow *window, GdkScreen *screen);

// GdkScreen * gtk_window_get_screen (GtkWindow *window);

gboolean gtk_window_is_active (GtkWindow *window);

gboolean gtk_window_is_maximized (GtkWindow *window);

gboolean gtk_window_has_toplevel_focus (GtkWindow *window);

GList * gtk_window_list_toplevels (void);

void gtk_window_add_mnemonic (GtkWindow *window, guint keyval, GtkWidget *target);

void gtk_window_remove_mnemonic (GtkWindow *window, guint keyval, GtkWidget *target);

// gboolean gtk_window_mnemonic_activate (GtkWindow *window, guint keyval, GdkModifierType modifier);

gboolean gtk_window_activate_key (GtkWindow *window, GdkEventKey *event);

gboolean gtk_window_propagate_key_event (GtkWindow *window, GdkEventKey *event);

GtkWidget * gtk_window_get_focus (GtkWindow *window);

void gtk_window_set_focus (GtkWindow *window, GtkWidget *focus);

GtkWidget * gtk_window_get_default_widget (GtkWindow *window);

void gtk_window_set_default (GtkWindow *window, GtkWidget *default_widget);

void gtk_window_present (GtkWindow *window);

void gtk_window_present_with_time (GtkWindow *window, guint32 timestamp);

void gtk_window_close (GtkWindow *window);

void gtk_window_iconify (GtkWindow *window);

void gtk_window_deiconify (GtkWindow *window);

void gtk_window_stick (GtkWindow *window);

void gtk_window_unstick (GtkWindow *window);

void gtk_window_maximize (GtkWindow *window);

void gtk_window_unmaximize (GtkWindow *window);

void gtk_window_fullscreen (GtkWindow *window);

// void gtk_window_fullscreen_on_monitor (GtkWindow *window, GdkScreen *screen, gint monitor);

void gtk_window_unfullscreen (GtkWindow *window);

void gtk_window_set_keep_above (GtkWindow *window, gboolean setting);

void gtk_window_set_keep_below (GtkWindow *window, gboolean setting);

// void gtk_window_begin_resize_drag (GtkWindow *window, GdkWindowEdge edge, gint button, gint root_x, gint root_y, guint32 timestamp);

void gtk_window_begin_move_drag (GtkWindow *window, gint button, gint root_x, gint root_y, guint32 timestamp);

void gtk_window_set_decorated (GtkWindow *window, gboolean setting);

void gtk_window_set_deletable (GtkWindow *window, gboolean setting);

// void gtk_window_set_mnemonic_modifier (GtkWindow *window, GdkModifierType modifier);

void gtk_window_set_type_hint (GtkWindow *window, GdkWindowTypeHint hint);

void gtk_window_set_skip_taskbar_hint (GtkWindow *window, gboolean setting);

void gtk_window_set_skip_pager_hint (GtkWindow *window, gboolean setting);

void gtk_window_set_urgency_hint (GtkWindow *window, gboolean setting);

void gtk_window_set_accept_focus (GtkWindow *window, gboolean setting);

void gtk_window_set_focus_on_map (GtkWindow *window, gboolean setting);

void gtk_window_set_startup_id (GtkWindow *window, gchar *startup_id);

void gtk_window_set_role (GtkWindow *window, gchar *role);

gboolean gtk_window_get_decorated (GtkWindow *window);

gboolean gtk_window_get_deletable (GtkWindow *window);

GList * gtk_window_get_default_icon_list (void);

const gchar * gtk_window_get_default_icon_name (void);

void gtk_window_get_default_size (GtkWindow *window, gint *width, gint *height);

gboolean gtk_window_get_destroy_with_parent (GtkWindow *window);

gboolean gtk_window_get_hide_titlebar_when_maximized (GtkWindow *window);

GdkPixbuf * gtk_window_get_icon (GtkWindow *window);

GList * gtk_window_get_icon_list (GtkWindow *window);

const gchar * gtk_window_get_icon_name (GtkWindow *window);

// GdkModifierType gtk_window_get_mnemonic_modifier (GtkWindow *window);

gboolean gtk_window_get_modal (GtkWindow *window);

void gtk_window_get_position (GtkWindow *window, gint *root_x, gint *root_y);

const gchar * gtk_window_get_role (GtkWindow *window);

void gtk_window_get_size (GtkWindow *window, gint *width, gint *height);

const gchar * gtk_window_get_title (GtkWindow *window);

GtkWindow * gtk_window_get_transient_for (GtkWindow *window);

GtkWidget * gtk_window_get_attached_to (GtkWindow *window);

GdkWindowTypeHint gtk_window_get_type_hint (GtkWindow *window);

gboolean gtk_window_get_skip_taskbar_hint (GtkWindow *window);

gboolean gtk_window_get_skip_pager_hint (GtkWindow *window);

gboolean gtk_window_get_urgency_hint (GtkWindow *window);

gboolean gtk_window_get_accept_focus (GtkWindow *window);

gboolean gtk_window_get_focus_on_map (GtkWindow *window);

// GtkWindowGroup * gtk_window_get_group (GtkWindow *window);

gboolean gtk_window_has_group (GtkWindow *window);

GtkWindowType gtk_window_get_window_type (GtkWindow *window);

void gtk_window_move (GtkWindow *window, gint x, gint y);

// gboolean gtk_window_parse_geometry (GtkWindow *window, gchar *geometry);

// void gtk_window_reshow_with_initial_size (GtkWindow *window);

void gtk_window_resize (GtkWindow *window, gint width, gint height);

// void gtk_window_resize_to_geometry (GtkWindow *window, gint width, gint height);

void gtk_window_set_default_icon_list (GList *list);

void gtk_window_set_default_icon (GdkPixbuf *icon);

gboolean gtk_window_set_default_icon_from_file (gchar *filename, GError **err);

void gtk_window_set_default_icon_name (gchar *name);

void gtk_window_set_icon (GtkWindow *window, GdkPixbuf *icon);

void gtk_window_set_icon_list (GtkWindow *window, GList *list);

gboolean gtk_window_set_icon_from_file (GtkWindow *window, gchar *filename, GError **err);

void gtk_window_set_icon_name (GtkWindow *window, gchar *name);

void gtk_window_set_auto_startup_notification (gboolean setting);

// gdouble gtk_window_get_opacity (GtkWindow *window);

// void gtk_window_set_opacity (GtkWindow *window, gdouble opacity);

gboolean gtk_window_get_mnemonics_visible (GtkWindow *window);

void gtk_window_set_mnemonics_visible (GtkWindow *window, gboolean setting);

gboolean gtk_window_get_focus_visible (GtkWindow *window);

void gtk_window_set_focus_visible (GtkWindow *window, gboolean setting);

// void gtk_window_set_has_resize_grip (GtkWindow *window, gboolean value);

// gboolean gtk_window_get_has_resize_grip (GtkWindow *window);

// gboolean gtk_window_resize_grip_is_visible (GtkWindow *window);

// gboolean gtk_window_get_resize_grip_area (GtkWindow *window, GdkRectangle *rect);

// GtkApplication * gtk_window_get_application (GtkWindow *window);

// void gtk_window_set_application (GtkWindow *window, GtkApplication *application);

void gtk_window_set_has_user_ref_count (GtkWindow *window, gboolean setting);

void gtk_window_set_titlebar (GtkWindow *window, GtkWidget *titlebar);

GtkWidget * gtk_window_get_titlebar (GtkWindow *window);

void gtk_window_set_interactive_debugging (gboolean enable);



