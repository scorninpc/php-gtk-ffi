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