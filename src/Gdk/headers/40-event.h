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