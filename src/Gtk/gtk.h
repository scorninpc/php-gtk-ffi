#define FFI_LIB "/usr/lib/x86_64-linux-gnu/libgtk-3.so"

typedef struct _GdkWindow GdkWindow;
typedef struct _GdkDevice GdkDevice;
typedef struct _GdkRectangle GdkRectangle;

typedef struct _GtkWidget GtkWidget;
typedef struct _GtkWidgetClassPrivate  GtkWidgetClassPrivate;
typedef struct _GtkWidgetClass  GtkWidgetClass;

typedef struct _GtkBox GtkBox;
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

