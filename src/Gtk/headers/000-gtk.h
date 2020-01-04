typedef struct _GdkWindow GdkWindow;
typedef struct _GdkDevice GdkDevice;
typedef struct _GdkRectangle GdkRectangle;

typedef struct _GdkPixbuf    GdkPixbuf;
typedef struct _GdkPixbufClass GdkPixbufClass;

typedef struct _GtkWidget GtkWidget;
typedef struct _GtkWidgetClassPrivate  GtkWidgetClassPrivate;
typedef struct _GtkWidgetClass  GtkWidgetClass;

typedef struct _GtkAccelGroup GtkAccelGroup;
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
  GDK_SHIFT_MASK    = 1 << 0,
  GDK_LOCK_MASK     = 1 << 1,
  GDK_CONTROL_MASK  = 1 << 2,
  GDK_MOD1_MASK     = 1 << 3,
  GDK_MOD2_MASK     = 1 << 4,
  GDK_MOD3_MASK     = 1 << 5,
  GDK_MOD4_MASK     = 1 << 6,
  GDK_MOD5_MASK     = 1 << 7,
  GDK_BUTTON1_MASK  = 1 << 8,
  GDK_BUTTON2_MASK  = 1 << 9,
  GDK_BUTTON3_MASK  = 1 << 10,
  GDK_BUTTON4_MASK  = 1 << 11,
  GDK_BUTTON5_MASK  = 1 << 12,
  GDK_MODIFIER_RESERVED_13_MASK  = 1 << 13,
  GDK_MODIFIER_RESERVED_14_MASK  = 1 << 14,
  GDK_MODIFIER_RESERVED_15_MASK  = 1 << 15,
  GDK_MODIFIER_RESERVED_16_MASK  = 1 << 16,
  GDK_MODIFIER_RESERVED_17_MASK  = 1 << 17,
  GDK_MODIFIER_RESERVED_18_MASK  = 1 << 18,
  GDK_MODIFIER_RESERVED_19_MASK  = 1 << 19,
  GDK_MODIFIER_RESERVED_20_MASK  = 1 << 20,
  GDK_MODIFIER_RESERVED_21_MASK  = 1 << 21,
  GDK_MODIFIER_RESERVED_22_MASK  = 1 << 22,
  GDK_MODIFIER_RESERVED_23_MASK  = 1 << 23,
  GDK_MODIFIER_RESERVED_24_MASK  = 1 << 24,
  GDK_MODIFIER_RESERVED_25_MASK  = 1 << 25,
  GDK_SUPER_MASK    = 1 << 26,
  GDK_HYPER_MASK    = 1 << 27,
  GDK_META_MASK     = 1 << 28,
  GDK_MODIFIER_RESERVED_29_MASK  = 1 << 29,
  GDK_RELEASE_MASK  = 1 << 30,
  GDK_MODIFIER_MASK = 0x5c001fff
} GdkModifierType;

typedef enum
{
  GTK_ACCEL_VISIBLE        = 1 << 0,
  GTK_ACCEL_LOCKED         = 1 << 1,
  GTK_ACCEL_MASK           = 0x07
} GtkAccelFlags;

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