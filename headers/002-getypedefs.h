typedef struct _GObject GInitiallyUnowned;
typedef struct _GSList GSList;
typedef struct _GList GList;
typedef struct _GValue GValue;
typedef union  _GTypeCValue GTypeCValue;
typedef struct _GTypePlugin GTypePlugin;
typedef struct _GTypeClass GTypeClass;
typedef struct _GTypeInterface GTypeInterface;
typedef struct _GTypeInstance GTypeInstance;
typedef struct _GTypeInfo GTypeInfo;
typedef struct _GTypeFundamentalInfo GTypeFundamentalInfo;
typedef struct _GInterfaceInfo GInterfaceInfo;
typedef struct _GTypeValueTable GTypeValueTable;
typedef struct _GTypeQuery GTypeQuery;
typedef struct _GObject GObject;
typedef struct _GObjectClass GObjectClass;
typedef struct _GObject GInitiallyUnowned;
typedef struct _GObjectClass GInitiallyUnownedClass;
typedef struct _GObjectConstructParam GObjectConstructParam;
typedef struct _GTypeClass GTypeClass;
typedef struct _GTypeInstance GTypeInstance;

typedef struct {
	guint in_marshal;
	guint is_invalid;
} GClosure;

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