struct _GSList
{
  gpointer data;
  GSList *next;
};

struct _GList
{
  gpointer data;
  GList *next;
  GList *prev;
};

struct _GTypeClass {
    GType g_type;
};

struct  _GObjectClass
{
  GTypeClass   g_type_class;
  GSList      *construct_properties;
  gsize   flags;
  gpointer  pdummy[6];
};

struct _GTypeInstance {
    GTypeClass *g_class;
};

struct  _GObject
{
  GTypeInstance  g_type_instance;
  guint ref_count;
  // GData *qdata;
};