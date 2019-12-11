#define FFI_LIB "/usr/lib/x86_64-linux-gnu/libwebkit2gtk-4.0.so"

/**
 * https://webkitgtk.org/reference/webkit2gtk/1.9.3/WebKitWebView.html
 */


typedef char   gchar;
typedef struct _WebKitWebView WebKitWebView;



WebKitWebView *webkit_web_view_new(void);
void webkit_web_view_load_uri(WebKitWebView *web_view, const gchar *uri);