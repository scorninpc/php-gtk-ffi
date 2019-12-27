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
typedef struct _GObject                  GInitiallyUnowned;
typedef struct _GObjectClass             GInitiallyUnownedClass;
typedef struct _GObjectConstructParam    GObjectConstructParam;

struct  _GObject
{
  GTypeInstance g_type_instance;
  guint ref_count;
  GData *qdata;
};

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

