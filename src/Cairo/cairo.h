#define FFI_LIB "/usr/lib/x86_64-linux-gnu/libcairo.so"

typedef struct _cairo_t cairo_t;
typedef struct _cairo_surface cairo_surface_t;
typedef struct _cairo_pattern cairo_pattern_t;
typedef int cairo_bool_t;

typedef enum _cairo_content {
    CAIRO_CONTENT_COLOR    = 0x1000,
    CAIRO_CONTENT_ALPHA    = 0x2000,
    CAIRO_CONTENT_COLOR_ALPHA = 0x3000
} cairo_content_t;

typedef enum _cairo_status {
    CAIRO_STATUS_SUCCESS = 0,

    CAIRO_STATUS_NO_MEMORY,
    CAIRO_STATUS_INVALID_RESTORE,
    CAIRO_STATUS_INVALID_POP_GROUP,
    CAIRO_STATUS_NO_CURRENT_POINT,
    CAIRO_STATUS_INVALID_MATRIX,
    CAIRO_STATUS_INVALID_STATUS,
    CAIRO_STATUS_NULL_POINTER,
    CAIRO_STATUS_INVALID_STRING,
    CAIRO_STATUS_INVALID_PATH_DATA,
    CAIRO_STATUS_READ_ERROR,
    CAIRO_STATUS_WRITE_ERROR,
    CAIRO_STATUS_SURFACE_FINISHED,
    CAIRO_STATUS_SURFACE_TYPE_MISMATCH,
    CAIRO_STATUS_PATTERN_TYPE_MISMATCH,
    CAIRO_STATUS_INVALID_CONTENT,
    CAIRO_STATUS_INVALID_FORMAT,
    CAIRO_STATUS_INVALID_VISUAL,
    CAIRO_STATUS_FILE_NOT_FOUND,
    CAIRO_STATUS_INVALID_DASH,
    CAIRO_STATUS_INVALID_DSC_COMMENT,
    CAIRO_STATUS_INVALID_INDEX,
    CAIRO_STATUS_CLIP_NOT_REPRESENTABLE,
    CAIRO_STATUS_TEMP_FILE_ERROR,
    CAIRO_STATUS_INVALID_STRIDE,
    CAIRO_STATUS_FONT_TYPE_MISMATCH,
    CAIRO_STATUS_USER_FONT_IMMUTABLE,
    CAIRO_STATUS_USER_FONT_ERROR,
    CAIRO_STATUS_NEGATIVE_COUNT,
    CAIRO_STATUS_INVALID_CLUSTERS,
    CAIRO_STATUS_INVALID_SLANT,
    CAIRO_STATUS_INVALID_WEIGHT,
    CAIRO_STATUS_INVALID_SIZE,
    CAIRO_STATUS_USER_FONT_NOT_IMPLEMENTED,
    CAIRO_STATUS_DEVICE_TYPE_MISMATCH,
    CAIRO_STATUS_DEVICE_ERROR,

    CAIRO_STATUS_LAST_STATUS
} cairo_status_t;

typedef enum _cairo_antialias {
    CAIRO_ANTIALIAS_DEFAULT,
    CAIRO_ANTIALIAS_NONE,
    CAIRO_ANTIALIAS_GRAY,
    CAIRO_ANTIALIAS_SUBPIXEL
} cairo_antialias_t;

typedef enum _cairo_fill_rule {
    CAIRO_FILL_RULE_WINDING,
    CAIRO_FILL_RULE_EVEN_ODD
} cairo_fill_rule_t;

typedef enum _cairo_line_cap {
    CAIRO_LINE_CAP_BUTT,
    CAIRO_LINE_CAP_ROUND,
    CAIRO_LINE_CAP_SQUARE
} cairo_line_cap_t;

typedef enum _cairo_line_join {
    CAIRO_LINE_JOIN_MITER,
    CAIRO_LINE_JOIN_ROUND,
    CAIRO_LINE_JOIN_BEVEL
} cairo_line_join_t;

typedef enum _cairo_operator {
    CAIRO_OPERATOR_CLEAR,

    CAIRO_OPERATOR_SOURCE,
    CAIRO_OPERATOR_OVER,
    CAIRO_OPERATOR_IN,
    CAIRO_OPERATOR_OUT,
    CAIRO_OPERATOR_ATOP,

    CAIRO_OPERATOR_DEST,
    CAIRO_OPERATOR_DEST_OVER,
    CAIRO_OPERATOR_DEST_IN,
    CAIRO_OPERATOR_DEST_OUT,
    CAIRO_OPERATOR_DEST_ATOP,

    CAIRO_OPERATOR_XOR,
    CAIRO_OPERATOR_ADD,
    CAIRO_OPERATOR_SATURATE,

    CAIRO_OPERATOR_MULTIPLY,
    CAIRO_OPERATOR_SCREEN,
    CAIRO_OPERATOR_OVERLAY,
    CAIRO_OPERATOR_DARKEN,
    CAIRO_OPERATOR_LIGHTEN,
    CAIRO_OPERATOR_COLOR_DODGE,
    CAIRO_OPERATOR_COLOR_BURN,
    CAIRO_OPERATOR_HARD_LIGHT,
    CAIRO_OPERATOR_SOFT_LIGHT,
    CAIRO_OPERATOR_DIFFERENCE,
    CAIRO_OPERATOR_EXCLUSION,
    CAIRO_OPERATOR_HSL_HUE,
    CAIRO_OPERATOR_HSL_SATURATION,
    CAIRO_OPERATOR_HSL_COLOR,
    CAIRO_OPERATOR_HSL_LUMINOSITY
} cairo_operator_t;

typedef struct {
    double x, y, width, height;
} cairo_rectangle_t;

typedef struct {
    cairo_status_t     status;
    cairo_rectangle_t *rectangles;
    int                num_rectangles;
} cairo_rectangle_list_t;

cairo_t * cairo_create (cairo_surface_t *target);
cairo_t * cairo_reference (cairo_t *cr);
void cairo_destroy (cairo_t *cr);
cairo_status_t cairo_status (cairo_t *cr);
void cairo_save (cairo_t *cr);
void cairo_restore (cairo_t *cr);
cairo_surface_t * cairo_get_target (cairo_t *cr);
void cairo_push_group (cairo_t *cr);
void cairo_push_group_with_content (cairo_t *cr, cairo_content_t content);
cairo_pattern_t * cairo_pop_group (cairo_t *cr);
void cairo_pop_group_to_source (cairo_t *cr);
cairo_surface_t * cairo_get_group_target (cairo_t *cr);
void cairo_set_source_rgb (cairo_t *cr, double red, double green, double blue);
void cairo_set_source_rgba (cairo_t *cr, double red, double green, double blue, double alpha);
void cairo_set_source (cairo_t *cr, cairo_pattern_t *source);
void cairo_set_source_surface (cairo_t *cr, cairo_surface_t *surface, double x, double y);
cairo_pattern_t * cairo_get_source (cairo_t *cr);
enum cairo_antialias_t;
void cairo_set_antialias (cairo_t *cr, cairo_antialias_t antialias);
cairo_antialias_t cairo_get_antialias (cairo_t *cr);
void cairo_set_dash (cairo_t *cr, const double *dashes, int num_dashes, double offset);
int cairo_get_dash_count (cairo_t *cr);
void cairo_get_dash (cairo_t *cr, double *dashes, double *offset);
enum cairo_fill_rule_t;
void cairo_set_fill_rule (cairo_t *cr, cairo_fill_rule_t fill_rule);
cairo_fill_rule_t cairo_get_fill_rule (cairo_t *cr);
enum cairo_line_cap_t;
void cairo_set_line_cap (cairo_t *cr, cairo_line_cap_t line_cap);
cairo_line_cap_t cairo_get_line_cap (cairo_t *cr);
enum cairo_line_join_t;
void cairo_set_line_join (cairo_t *cr, cairo_line_join_t line_join);
cairo_line_join_t cairo_get_line_join (cairo_t *cr);
void cairo_set_line_width (cairo_t *cr, double width);
double cairo_get_line_width (cairo_t *cr);
void cairo_set_miter_limit (cairo_t *cr, double limit);
double cairo_get_miter_limit (cairo_t *cr);
enum cairo_operator_t;
void cairo_set_operator (cairo_t *cr, cairo_operator_t op);
cairo_operator_t cairo_get_operator (cairo_t *cr);
void cairo_set_tolerance (cairo_t *cr, double tolerance);
double cairo_get_tolerance (cairo_t *cr);
void cairo_clip (cairo_t *cr);
void cairo_clip_preserve (cairo_t *cr);
void cairo_clip_extents (cairo_t *cr, double *x1, double *y1, double *x2, double *y2);
cairo_bool_t cairo_in_clip (cairo_t *cr, double x, double y);
void cairo_reset_clip (cairo_t *cr);
cairo_rectangle_t;
cairo_rectangle_list_t;
void cairo_rectangle_list_destroy (cairo_rectangle_list_t *rectangle_list);
cairo_rectangle_list_t * cairo_copy_clip_rectangle_list (cairo_t *cr);
void cairo_fill (cairo_t *cr);
void cairo_fill_preserve (cairo_t *cr);
void cairo_fill_extents (cairo_t *cr, double *x1, double *y1, double *x2, double *y2);
cairo_bool_t cairo_in_fill (cairo_t *cr, double x, double y);
void cairo_mask (cairo_t *cr, cairo_pattern_t *pattern);
void cairo_mask_surface (cairo_t *cr, cairo_surface_t *surface, double surface_x, double surface_y);
void cairo_paint (cairo_t *cr);
void cairo_paint_with_alpha (cairo_t *cr, double alpha);
void cairo_stroke (cairo_t *cr);
void cairo_stroke_preserve (cairo_t *cr);
void cairo_stroke_extents (cairo_t *cr, double *x1, double *y1, double *x2, double *y2);
cairo_bool_t cairo_in_stroke (cairo_t *cr, double x, double y);
void cairo_copy_page (cairo_t *cr);
void cairo_show_page (cairo_t *cr);
unsigned int cairo_get_reference_count (cairo_t *cr);
cairo_status_t cairo_set_user_data (cairo_t *cr, const cairo_user_data_key_t *key, void *user_data, cairo_destroy_func_t destroy);
void * cairo_get_user_data (cairo_t *cr, const cairo_user_data_key_t *key);