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