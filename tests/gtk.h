#define FFI_LIB "/usr/lib/x86_64-linux-gnu/libgtk-3.so"



typedef struct _GtkWidget GtkWidget;
typedef struct _GtkWindow GtkWindow;



typedef enum
{
  GTK_WINDOW_TOPLEVEL,
  GTK_WINDOW_POPUP
} GtkWindowType;


// GTK
void gtk_init(int *, char **[]);
void gtk_main();
void gtk_main_quit();


// GTKWINDOW
GtkWidget *gtk_window_new(GtkWindowType);

// GTKWIDGET
void gtk_widget_show_all(GtkWidget *);

// GTKCONTAINER
typedef struct _GtkContainer GtkContainer;

void gtk_container_add (GtkContainer *container, GtkWidget *widget);