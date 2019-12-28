#define FFI_LIB "/usr/lib/x86_64-linux-gnu/libgtk-3.so"

typedef char   gchar;
typedef short  gshort;
typedef long   glong;
typedef int    gint;
typedef gint   gboolean;
typedef unsigned char   guchar;
typedef unsigned short  gushort;
typedef unsigned long   gulong;
typedef unsigned int    guint;
typedef float   gfloat;
typedef double  gdouble;
typedef void* gpointer;
typedef const void *gconstpointer;
typedef gint            grefcount;
typedef volatile gint   gatomicrefcount;
typedef gulong GType;

typedef struct _GObject                  GObject;
typedef struct _GObjectClass             GObjectClass;
typedef struct _GObjectConstructParam    GObjectConstructParam;

typedef struct _GSList GSList;
struct _GSList
{
  gpointer data;
  GSList *next;
};

struct _GdkPoint
{
  gint x;
  gint y;
};
typedef struct _GdkPoint GdkPoint;


struct _GdkRectangle
{
    int x, y;
    int width, height;
};
typedef struct _GdkRectangle          GdkRectangle;

typedef const char GdkAtom;

typedef struct _GdkRGBA               GdkRGBA;
typedef struct _GdkContentFormats     GdkContentFormats;
typedef struct _GdkContentProvider    GdkContentProvider;
typedef struct _GdkCursor             GdkCursor;
typedef struct _GdkTexture            GdkTexture;
typedef struct _GdkDevice             GdkDevice;
typedef struct _GdkDrag               GdkDrag;
typedef struct _GdkDrop               GdkDrop;

typedef struct _GdkClipboard          GdkClipboard;
typedef struct _GdkDisplayManager     GdkDisplayManager;
typedef struct _GdkDisplay            GdkDisplay;
typedef struct _GdkSurface             GdkSurface;
typedef struct _GdkKeymap             GdkKeymap;
typedef struct _GdkAppLaunchContext   GdkAppLaunchContext;
typedef struct _GdkSeat               GdkSeat;
typedef struct _GdkSnapshot           GdkSnapshot;

typedef struct _GdkDrawingContext     GdkDrawingContext;
typedef struct _GdkDrawContext        GdkDrawContext;
typedef struct _GdkCairoContext       GdkCairoContext;
typedef struct _GdkGLContext          GdkGLContext;
typedef struct _GdkVulkanContext      GdkVulkanContext;


typedef enum
{
  GDK_LSB_FIRST,
  GDK_MSB_FIRST
} GdkByteOrder;

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

  /* The next few modifiers are used by XKB, so we skip to the end.
   * Bits 15 - 25 are currently unused. Bit 29 is used internally.
   */
  
  GDK_SUPER_MASK    = 1 << 26,
  GDK_HYPER_MASK    = 1 << 27,
  GDK_META_MASK     = 1 << 28,
  
  GDK_MODIFIER_RESERVED_29_MASK  = 1 << 29,

  GDK_RELEASE_MASK  = 1 << 30,

  /* Combination of GDK_SHIFT_MASK..GDK_BUTTON5_MASK + GDK_SUPER_MASK
     + GDK_HYPER_MASK + GDK_META_MASK + GDK_RELEASE_MASK */
  GDK_MODIFIER_MASK = 0x5c001fff
} GdkModifierType;

typedef enum
{
  GDK_GRAB_SUCCESS         = 0,
  GDK_GRAB_ALREADY_GRABBED = 1,
  GDK_GRAB_INVALID_TIME    = 2,
  GDK_GRAB_NOT_VIEWABLE    = 3,
  GDK_GRAB_FROZEN          = 4,
  GDK_GRAB_FAILED          = 5
} GdkGrabStatus;

typedef enum
{
  GDK_OWNERSHIP_NONE,
  GDK_OWNERSHIP_SURFACE,
  GDK_OWNERSHIP_APPLICATION
} GdkGrabOwnership;

typedef enum
{
  GDK_MODIFIER_INTENT_PRIMARY_ACCELERATOR,
  GDK_MODIFIER_INTENT_CONTEXT_MENU,
  GDK_MODIFIER_INTENT_EXTEND_SELECTION,
  GDK_MODIFIER_INTENT_MODIFY_SELECTION,
  GDK_MODIFIER_INTENT_NO_TEXT_INPUT,
  GDK_MODIFIER_INTENT_SHIFT_GROUP,
  GDK_MODIFIER_INTENT_DEFAULT_MOD_MASK,
} GdkModifierIntent;

typedef enum
{
  GDK_EXPOSURE_MASK             = 1 << 1,
  GDK_POINTER_MOTION_MASK       = 1 << 2,
  GDK_BUTTON_MOTION_MASK        = 1 << 4,
  GDK_BUTTON1_MOTION_MASK       = 1 << 5,
  GDK_BUTTON2_MOTION_MASK       = 1 << 6,
  GDK_BUTTON3_MOTION_MASK       = 1 << 7,
  GDK_BUTTON_PRESS_MASK         = 1 << 8,
  GDK_BUTTON_RELEASE_MASK       = 1 << 9,
  GDK_KEY_PRESS_MASK            = 1 << 10,
  GDK_KEY_RELEASE_MASK          = 1 << 11,
  GDK_ENTER_NOTIFY_MASK         = 1 << 12,
  GDK_LEAVE_NOTIFY_MASK         = 1 << 13,
  GDK_FOCUS_CHANGE_MASK         = 1 << 14,
  GDK_STRUCTURE_MASK            = 1 << 15,
  GDK_PROPERTY_CHANGE_MASK      = 1 << 16,
  GDK_PROXIMITY_IN_MASK         = 1 << 18,
  GDK_PROXIMITY_OUT_MASK        = 1 << 19,
  GDK_SUBSTRUCTURE_MASK         = 1 << 20,
  GDK_SCROLL_MASK               = 1 << 21,
  GDK_TOUCH_MASK                = 1 << 22,
  GDK_SMOOTH_SCROLL_MASK        = 1 << 23,
  GDK_TOUCHPAD_GESTURE_MASK     = 1 << 24,
  GDK_TABLET_PAD_MASK           = 1 << 25,
  GDK_ALL_EVENTS_MASK           = 0x3FFFFFE
} GdkEventMask;

typedef enum {
  GDK_GL_ERROR_NOT_AVAILABLE,
  GDK_GL_ERROR_UNSUPPORTED_FORMAT,
  GDK_GL_ERROR_UNSUPPORTED_PROFILE,
  GDK_GL_ERROR_COMPILATION_FAILED,
  GDK_GL_ERROR_LINK_FAILED
} GdkGLError;

typedef struct _GdkWindow GdkWindow;
typedef struct _GdkDevice GdkDevice;

typedef struct _GTypeClass {
    GType g_type;
} GTypeClass;

typedef enum {
  GDK_VULKAN_ERROR_UNSUPPORTED,
  GDK_VULKAN_ERROR_NOT_AVAILABLE,
} GdkVulkanError;

typedef enum
{
  GDK_SURFACE_TYPE_HINT_NORMAL,
  GDK_SURFACE_TYPE_HINT_DIALOG,
  GDK_SURFACE_TYPE_HINT_MENU,		/* Torn off menu */
  GDK_SURFACE_TYPE_HINT_TOOLBAR,
  GDK_SURFACE_TYPE_HINT_SPLASHSCREEN,
  GDK_SURFACE_TYPE_HINT_UTILITY,
  GDK_SURFACE_TYPE_HINT_DOCK,
  GDK_SURFACE_TYPE_HINT_DESKTOP,
  GDK_SURFACE_TYPE_HINT_DROPDOWN_MENU,	/* A drop down menu (from a menubar) */
  GDK_SURFACE_TYPE_HINT_POPUP_MENU,	/* A popup menu (from right-click) */
  GDK_SURFACE_TYPE_HINT_TOOLTIP,
  GDK_SURFACE_TYPE_HINT_NOTIFICATION,
  GDK_SURFACE_TYPE_HINT_COMBO,
  GDK_SURFACE_TYPE_HINT_DND
} GdkSurfaceTypeHint;

typedef enum
{
  GDK_AXIS_IGNORE,
  GDK_AXIS_X,
  GDK_AXIS_Y,
  GDK_AXIS_PRESSURE,
  GDK_AXIS_XTILT,
  GDK_AXIS_YTILT,
  GDK_AXIS_WHEEL,
  GDK_AXIS_DISTANCE,
  GDK_AXIS_ROTATION,
  GDK_AXIS_SLIDER,
  GDK_AXIS_LAST
} GdkAxisUse;

typedef enum
{
  GDK_AXIS_FLAG_X        = 1 << GDK_AXIS_X,
  GDK_AXIS_FLAG_Y        = 1 << GDK_AXIS_Y,
  GDK_AXIS_FLAG_PRESSURE = 1 << GDK_AXIS_PRESSURE,
  GDK_AXIS_FLAG_XTILT    = 1 << GDK_AXIS_XTILT,
  GDK_AXIS_FLAG_YTILT    = 1 << GDK_AXIS_YTILT,
  GDK_AXIS_FLAG_WHEEL    = 1 << GDK_AXIS_WHEEL,
  GDK_AXIS_FLAG_DISTANCE = 1 << GDK_AXIS_DISTANCE,
  GDK_AXIS_FLAG_ROTATION = 1 << GDK_AXIS_ROTATION,
  GDK_AXIS_FLAG_SLIDER   = 1 << GDK_AXIS_SLIDER,
} GdkAxisFlags;

typedef enum
{
  GDK_ACTION_COPY    = 1 << 0,
  GDK_ACTION_MOVE    = 1 << 1,
  GDK_ACTION_LINK    = 1 << 2,
  GDK_ACTION_ASK     = 1 << 3
} GdkDragAction;

typedef struct _GObjectClass {
    GTypeClass g_type_class;
    GSList *construct_properties;
    gpointer pdummy[8];
} GObjectClass;



typedef struct _GdkEventAny	    GdkEventAny;
typedef struct _GdkEventMotion	    GdkEventMotion;
typedef struct _GdkEventButton	    GdkEventButton;
typedef struct _GdkEventTouch       GdkEventTouch;
typedef struct _GdkEventScroll      GdkEventScroll;  
typedef struct _GdkEventKey	    GdkEventKey;
typedef struct _GdkEventFocus	    GdkEventFocus;
typedef struct _GdkEventCrossing    GdkEventCrossing;
typedef struct _GdkEventConfigure   GdkEventConfigure;
typedef struct _GdkEventProximity   GdkEventProximity;
typedef struct _GdkEventDND         GdkEventDND;
typedef struct _GdkEventSetting     GdkEventSetting;
typedef struct _GdkEventGrabBroken  GdkEventGrabBroken;
typedef struct _GdkEventTouchpadSwipe GdkEventTouchpadSwipe;
typedef struct _GdkEventTouchpadPinch GdkEventTouchpadPinch;
typedef struct _GdkEventPadButton   GdkEventPadButton;
typedef struct _GdkEventPadAxis     GdkEventPadAxis;
typedef struct _GdkEventPadGroupMode GdkEventPadGroupMode;

typedef struct _GdkEventSequence    GdkEventSequence;
typedef union  _GdkEvent	    GdkEvent;

typedef enum
{
  GDK_NOTHING,
  GDK_DELETE,
  GDK_DESTROY,
  GDK_MOTION_NOTIFY,
  GDK_BUTTON_PRESS,
  GDK_BUTTON_RELEASE,
  GDK_KEY_PRESS,
  GDK_KEY_RELEASE,
  GDK_ENTER_NOTIFY,
  GDK_LEAVE_NOTIFY,
  GDK_FOCUS_CHANGE,
  GDK_CONFIGURE,
  GDK_PROXIMITY_IN,
  GDK_PROXIMITY_OUT,
  GDK_DRAG_ENTER,
  GDK_DRAG_LEAVE,
  GDK_DRAG_MOTION,
  GDK_DROP_START,
  GDK_SCROLL,
  GDK_GRAB_BROKEN,
  GDK_TOUCH_BEGIN,
  GDK_TOUCH_UPDATE,
  GDK_TOUCH_END,
  GDK_TOUCH_CANCEL,
  GDK_TOUCHPAD_SWIPE,
  GDK_TOUCHPAD_PINCH,
  GDK_PAD_BUTTON_PRESS,
  GDK_PAD_BUTTON_RELEASE,
  GDK_PAD_RING,
  GDK_PAD_STRIP,
  GDK_PAD_GROUP_MODE,
  GDK_EVENT_LAST        /* helper variable for decls */
} GdkEventType;

typedef enum
{
  GDK_TOUCHPAD_GESTURE_PHASE_BEGIN,
  GDK_TOUCHPAD_GESTURE_PHASE_UPDATE,
  GDK_TOUCHPAD_GESTURE_PHASE_END,
  GDK_TOUCHPAD_GESTURE_PHASE_CANCEL
} GdkTouchpadGesturePhase;

typedef enum
{
  GDK_SCROLL_UP,
  GDK_SCROLL_DOWN,
  GDK_SCROLL_LEFT,
  GDK_SCROLL_RIGHT,
  GDK_SCROLL_SMOOTH
} GdkScrollDirection;

typedef enum
{
  GDK_NOTIFY_ANCESTOR		= 0,
  GDK_NOTIFY_VIRTUAL		= 1,
  GDK_NOTIFY_INFERIOR		= 2,
  GDK_NOTIFY_NONLINEAR		= 3,
  GDK_NOTIFY_NONLINEAR_VIRTUAL	= 4,
  GDK_NOTIFY_UNKNOWN		= 5
} GdkNotifyType;

typedef enum
{
  GDK_CROSSING_NORMAL,
  GDK_CROSSING_GRAB,
  GDK_CROSSING_UNGRAB,
  GDK_CROSSING_GTK_GRAB,
  GDK_CROSSING_GTK_UNGRAB,
  GDK_CROSSING_STATE_CHANGED,
  GDK_CROSSING_TOUCH_BEGIN,
  GDK_CROSSING_TOUCH_END,
  GDK_CROSSING_DEVICE_SWITCH
} GdkCrossingMode;

typedef struct _GdkEventClass GdkEventClass;
struct _GdkEventClass
{
  GObjectClass object_class;
};

struct _GdkEventAny
{
  GObject parent_instance;
  GdkEventType type;
  GdkSurface *surface;
  guint16 flags;
  gint8 send_event;
  GdkDevice *device;
  GdkDevice *source_device;
  GdkDisplay *display;
  GObject *target;
};

struct _GdkEventMotion
{
  GdkEventAny any;
  guint32 time;
  gdouble x;
  gdouble y;
  gdouble *axes;
  guint state;
  GdkDeviceTool *tool;
  gdouble x_root, y_root;
  GList *history;
};

struct _GdkEventButton
{
  GdkEventAny any;
  guint32 time;
  gdouble x;
  gdouble y;
  gdouble *axes;
  guint state;
  guint button;
  GdkDeviceTool *tool;
  gdouble x_root, y_root;
};

struct _GdkEventTouch
{
  GdkEventAny any;
  guint32 time;
  gdouble x;
  gdouble y;
  gdouble *axes;
  guint state;
  GdkEventSequence *sequence;
  gboolean emulating_pointer;
  gdouble x_root, y_root;
};

struct _GdkEventScroll
{
  GdkEventAny any;
  guint32 time;
  gdouble x;
  gdouble y;
  guint state;
  GdkScrollDirection direction;
  gdouble x_root, y_root;
  gdouble delta_x;
  gdouble delta_y;
  guint is_stop : 1;
};

struct _GdkEventKey
{
  GdkEventAny any;
  guint32 time;
  guint state;
  guint keyval;
  guint16 hardware_keycode;
  guint16 key_scancode;
  guint8 group;
  guint is_modifier : 1;
};

struct _GdkEventCrossing
{
  GdkEventAny any;
  GdkSurface *child_surface;
  guint32 time;
  gdouble x;
  gdouble y;
  gdouble x_root;
  gdouble y_root;
  GdkCrossingMode mode;
  GdkNotifyType detail;
  gboolean focus;
  guint state;
  GObject *related_target;
};

struct _GdkEventFocus
{
  GdkEventAny any;
  gint16 in;
  GdkCrossingMode mode;
  GdkNotifyType detail;
  GObject *related_target;
};

struct _GdkEventConfigure
{
  GdkEventAny any;
  gint x, y;
  gint width;
  gint height;
};

struct _GdkEventProximity
{
  GdkEventAny any;
  guint32 time;
};

struct _GdkEventGrabBroken {
  GdkEventAny any;
  gboolean keyboard;
  gboolean implicit;
  GdkSurface *grab_surface;
};

struct _GdkEventDND {
  GdkEventAny any;
  GdkDrop *drop;

  guint32 time;
  gshort x_root, y_root;
};

struct _GdkEventTouchpadSwipe {
  GdkEventAny any;
  gint8 phase;
  gint8 n_fingers;
  guint32 time;
  gdouble x;
  gdouble y;
  gdouble dx;
  gdouble dy;
  gdouble x_root, y_root;
  guint state;
};

struct _GdkEventTouchpadPinch {
  GdkEventAny any;
  gint8 phase;
  gint8 n_fingers;
  guint32 time;
  gdouble x;
  gdouble y;
  gdouble dx;
  gdouble dy;
  gdouble angle_delta;
  gdouble scale;
  gdouble x_root, y_root;
  guint state;
};

struct _GdkEventPadButton {
  GdkEventAny any;
  guint32 time;
  guint group;
  guint button;
  guint mode;
};

struct _GdkEventPadAxis {
  GdkEventAny any;
  guint32 time;
  guint group;
  guint index;
  guint mode;
  gdouble value;
};

struct _GdkEventPadGroupMode {
  GdkEventAny any;
  guint32 time;
  guint group;
  guint mode;
};

union _GdkEvent
{
  GdkEventAny		    any;
  GdkEventMotion	    motion;
  GdkEventButton	    button;
  GdkEventTouch             touch;
  GdkEventScroll            scroll;
  GdkEventKey		    key;
  GdkEventCrossing	    crossing;
  GdkEventFocus		    focus_change;
  GdkEventConfigure	    configure;
  GdkEventProximity	    proximity;
  GdkEventDND               dnd;
  GdkEventGrabBroken        grab_broken;
  GdkEventTouchpadSwipe     touchpad_swipe;
  GdkEventTouchpadPinch     touchpad_pinch;
  GdkEventPadButton         pad_button;
  GdkEventPadAxis           pad_axis;
  GdkEventPadGroupMode      pad_group_mode;
};

