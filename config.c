/* config.c generated by valac 0.40.8, the Vala compiler
 * generated from config.vala, do not modify */

/*
Cronotas (c) Didapax Sistem Daniel Alfonsi 
2019
*/


#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <gdk/gdk.h>
#include <sqlite3.h>


#define CRONO_TYPE_CONFIG (crono_config_get_type ())
#define CRONO_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CRONO_TYPE_CONFIG, cronoconfig))
#define CRONO_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CRONO_TYPE_CONFIG, cronoconfigClass))
#define CRONO_IS_CONFIG(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CRONO_TYPE_CONFIG))
#define CRONO_IS_CONFIG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CRONO_TYPE_CONFIG))
#define CRONO_CONFIG_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CRONO_TYPE_CONFIG, cronoconfigClass))

typedef struct _cronoconfig cronoconfig;
typedef struct _cronoconfigClass cronoconfigClass;
typedef struct _cronoconfigPrivate cronoconfigPrivate;
enum  {
	CRONO_CONFIG_0_PROPERTY,
	CRONO_CONFIG_NUM_PROPERTIES
};
static GParamSpec* crono_config_properties[CRONO_CONFIG_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define CRONO_TYPE_F_CONFIG (crono_f_config_get_type ())
typedef struct _cronof_config cronof_config;

struct _cronoconfig {
	GtkDialog parent_instance;
	cronoconfigPrivate * priv;
	GtkDialog* dialog;
	GtkButton* btn_aplicar;
	GtkEntry* ruta;
	GtkComboBox* estilo;
};

struct _cronoconfigClass {
	GtkDialogClass parent_class;
};

struct _cronoconfigPrivate {
	GtkBuilder* builder;
	GtkListStore* list_box;
	GtkTreeIter iter_box;
	gchar* micolor;
};

struct _cronof_config {
	gchar* id;
	gchar* ruta;
	gchar* color;
};


static gpointer crono_config_parent_class = NULL;
extern cronof_config crono_fconfig;
extern sqlite3* crono_db_config;
extern gint crono_rc;

GType crono_config_get_type (void) G_GNUC_CONST;
#define CRONO_CONFIG_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), CRONO_TYPE_CONFIG, cronoconfigPrivate))
cronoconfig* crono_config_new (void);
cronoconfig* crono_config_construct (GType object_type);
GType crono_f_config_get_type (void) G_GNUC_CONST;
cronof_config* crono_f_config_dup (const cronof_config* self);
void crono_f_config_free (cronof_config* self);
void crono_f_config_copy (const cronof_config* self,
                          cronof_config* dest);
void crono_f_config_destroy (cronof_config* self);
void crono_config_click_aplicar_config (cronoconfig* self);
static void _crono_config_click_aplicar_config_gtk_button_clicked (GtkButton* _sender,
                                                            gpointer self);
void crono_config_changed (cronoconfig* self);
static void _crono_config_changed_gtk_combo_box_changed (GtkComboBox* _sender,
                                                  gpointer self);
void crono_config_llenar_estilo (cronoconfig* self);
void crono_config_aplicar_color (cronoconfig* self,
                                 const gchar* color);
static void crono_config_finalize (GObject * obj);


static gpointer
_g_object_ref0 (gpointer self)
{
#line 21 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	return self ? g_object_ref (self) : NULL;
#line 100 "config.c"
}


static void
_crono_config_click_aplicar_config_gtk_button_clicked (GtkButton* _sender,
                                                       gpointer self)
{
#line 24 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	crono_config_click_aplicar_config ((cronoconfig*) self);
#line 110 "config.c"
}


static void
_crono_config_changed_gtk_combo_box_changed (GtkComboBox* _sender,
                                             gpointer self)
{
#line 27 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	crono_config_changed ((cronoconfig*) self);
#line 120 "config.c"
}


cronoconfig*
crono_config_construct (GType object_type)
{
	cronoconfig * self = NULL;
	GtkBuilder* _tmp0_;
	GtkBuilder* _tmp1_;
	cronof_config _tmp2_;
	const gchar* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	GtkBuilder* _tmp6_;
	GObject* _tmp7_;
	GtkDialog* _tmp8_;
	GtkBuilder* _tmp9_;
	GtkBuilder* _tmp10_;
	GObject* _tmp11_;
	GtkButton* _tmp12_;
	GtkButton* _tmp13_;
	GtkBuilder* _tmp14_;
	GObject* _tmp15_;
	GtkEntry* _tmp16_;
	GtkBuilder* _tmp17_;
	GObject* _tmp18_;
	GtkComboBox* _tmp19_;
	GtkComboBox* _tmp20_;
	cronof_config _tmp21_;
	const gchar* _tmp22_;
	gchar* _tmp23_;
	GtkEntry* _tmp24_;
	cronof_config _tmp25_;
	const gchar* _tmp26_;
	GtkDialog* _tmp27_;
	GError * _inner_error_ = NULL;
#line 18 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	self = (cronoconfig*) g_object_new (object_type, NULL);
#line 19 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp0_ = gtk_builder_new ();
#line 19 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	if (_tmp0_) {
#line 19 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
		g_object_set_data ((GObject *) _tmp0_, "vala-creation-function", "crono.config.new");
#line 165 "config.c"
	}
#line 19 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_object_unref0 (self->priv->builder);
#line 19 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	self->priv->builder = _tmp0_;
#line 20 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp1_ = self->priv->builder;
#line 20 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp2_ = crono_fconfig;
#line 20 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp3_ = _tmp2_.ruta;
#line 20 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp4_ = g_strconcat (_tmp3_, "config.ui", NULL);
#line 20 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp5_ = _tmp4_;
#line 20 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	gtk_builder_add_from_file (_tmp1_, _tmp5_, &_inner_error_);
#line 20 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_free0 (_tmp5_);
#line 20 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 20 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 20 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
		g_clear_error (&_inner_error_);
#line 20 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
		return NULL;
#line 193 "config.c"
	}
#line 21 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp6_ = self->priv->builder;
#line 21 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp7_ = gtk_builder_get_object (_tmp6_, "dialog_config");
#line 21 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp8_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp7_, gtk_dialog_get_type ()) ? ((GtkDialog*) _tmp7_) : NULL);
#line 21 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_object_unref0 (self->dialog);
#line 21 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	self->dialog = _tmp8_;
#line 22 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp9_ = self->priv->builder;
#line 22 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	gtk_builder_connect_signals (_tmp9_, NULL);
#line 23 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp10_ = self->priv->builder;
#line 23 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp11_ = gtk_builder_get_object (_tmp10_, "btn_aplicar");
#line 23 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp12_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp11_, gtk_button_get_type ()) ? ((GtkButton*) _tmp11_) : NULL);
#line 23 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_object_unref0 (self->btn_aplicar);
#line 23 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	self->btn_aplicar = _tmp12_;
#line 24 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp13_ = self->btn_aplicar;
#line 24 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	g_signal_connect_object (_tmp13_, "clicked", (GCallback) _crono_config_click_aplicar_config_gtk_button_clicked, self, 0);
#line 25 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp14_ = self->priv->builder;
#line 25 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp15_ = gtk_builder_get_object (_tmp14_, "ruta");
#line 25 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp16_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp15_, gtk_entry_get_type ()) ? ((GtkEntry*) _tmp15_) : NULL);
#line 25 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_object_unref0 (self->ruta);
#line 25 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	self->ruta = _tmp16_;
#line 26 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp17_ = self->priv->builder;
#line 26 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp18_ = gtk_builder_get_object (_tmp17_, "estilo");
#line 26 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp19_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp18_, gtk_combo_box_get_type ()) ? ((GtkComboBox*) _tmp18_) : NULL);
#line 26 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_object_unref0 (self->estilo);
#line 26 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	self->estilo = _tmp19_;
#line 27 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp20_ = self->estilo;
#line 27 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	g_signal_connect_object (_tmp20_, "changed", (GCallback) _crono_config_changed_gtk_combo_box_changed, self, 0);
#line 28 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	crono_config_llenar_estilo (self);
#line 29 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp21_ = crono_fconfig;
#line 29 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp22_ = _tmp21_.color;
#line 29 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp23_ = g_strdup (_tmp22_);
#line 29 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_free0 (self->priv->micolor);
#line 29 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	self->priv->micolor = _tmp23_;
#line 30 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp24_ = self->ruta;
#line 30 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp25_ = crono_fconfig;
#line 30 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp26_ = _tmp25_.ruta;
#line 30 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	gtk_entry_set_text (_tmp24_, _tmp26_);
#line 31 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp27_ = self->dialog;
#line 31 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	gtk_widget_show_all (G_TYPE_CHECK_INSTANCE_CAST (_tmp27_, gtk_widget_get_type (), GtkWidget));
#line 18 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	return self;
#line 273 "config.c"
}


cronoconfig*
crono_config_new (void)
{
#line 18 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	return crono_config_construct (CRONO_TYPE_CONFIG);
#line 282 "config.c"
}


void
crono_config_aplicar_color (cronoconfig* self,
                            const gchar* color)
{
	GdkScreen* screen = NULL;
	GdkScreen* _tmp0_;
	GdkScreen* _tmp1_;
	GtkCssProvider* css_provider = NULL;
	GtkCssProvider* _tmp2_;
	cronof_config _tmp3_;
	const gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	gchar* _tmp7_;
	gchar* _tmp8_;
	GtkStyleContext* style_context = NULL;
	GtkStyleContext* _tmp9_;
	GtkStyleContext* _tmp10_;
	GtkStyleContext* _tmp11_;
	GError * _inner_error_ = NULL;
#line 33 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	g_return_if_fail (CRONO_IS_CONFIG (self));
#line 33 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	g_return_if_fail (color != NULL);
#line 34 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp0_ = gdk_screen_get_default ();
#line 34 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp1_ = _g_object_ref0 (_tmp0_);
#line 34 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	screen = _tmp1_;
#line 35 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp2_ = gtk_css_provider_new ();
#line 35 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	if (_tmp2_) {
#line 35 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
		g_object_set_data ((GObject *) _tmp2_, "vala-creation-function", "crono.config.aplicar_color");
#line 322 "config.c"
	}
#line 35 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	css_provider = _tmp2_;
#line 36 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp3_ = crono_fconfig;
#line 36 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp4_ = _tmp3_.ruta;
#line 36 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp5_ = g_strconcat (_tmp4_, color, NULL);
#line 36 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp6_ = _tmp5_;
#line 36 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp7_ = g_strconcat (_tmp6_, ".css", NULL);
#line 36 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp8_ = _tmp7_;
#line 36 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	gtk_css_provider_load_from_path (css_provider, _tmp8_, &_inner_error_);
#line 36 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_free0 (_tmp8_);
#line 36 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_free0 (_tmp6_);
#line 36 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 36 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
		_g_object_unref0 (css_provider);
#line 36 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
		_g_object_unref0 (screen);
#line 36 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 36 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
		g_clear_error (&_inner_error_);
#line 36 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
		return;
#line 356 "config.c"
	}
#line 37 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp9_ = gtk_widget_get_style_context (G_TYPE_CHECK_INSTANCE_CAST (self, gtk_widget_get_type (), GtkWidget));
#line 37 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp10_ = _g_object_ref0 (_tmp9_);
#line 37 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	style_context = _tmp10_;
#line 38 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp11_ = style_context;
#line 38 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	gtk_style_context_add_provider_for_screen (screen, G_TYPE_CHECK_INSTANCE_CAST (css_provider, gtk_style_provider_get_type (), GtkStyleProvider), (guint) GTK_STYLE_PROVIDER_PRIORITY_USER);
#line 33 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_object_unref0 (style_context);
#line 33 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_object_unref0 (css_provider);
#line 33 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_object_unref0 (screen);
#line 374 "config.c"
}


void
crono_config_changed (cronoconfig* self)
{
	GValue val1 = {0};
	gboolean ff = FALSE;
	GtkComboBox* _tmp0_;
	GtkTreeIter _tmp1_ = {0};
	gboolean _tmp2_;
	GtkListStore* _tmp3_;
	GtkTreeIter _tmp4_;
	GValue _tmp5_ = {0};
	GValue _tmp6_;
	gchar* _tmp7_;
#line 40 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	g_return_if_fail (CRONO_IS_CONFIG (self));
#line 42 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp0_ = self->estilo;
#line 42 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp2_ = gtk_combo_box_get_active_iter (_tmp0_, &_tmp1_);
#line 42 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	self->priv->iter_box = _tmp1_;
#line 42 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	ff = _tmp2_;
#line 43 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp3_ = self->priv->list_box;
#line 43 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp4_ = self->priv->iter_box;
#line 43 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	gtk_tree_model_get_value (G_TYPE_CHECK_INSTANCE_CAST (_tmp3_, gtk_tree_model_get_type (), GtkTreeModel), &_tmp4_, 0, &_tmp5_);
#line 43 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	G_IS_VALUE (&val1) ? (g_value_unset (&val1), NULL) : NULL;
#line 43 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	val1 = _tmp5_;
#line 44 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp6_ = val1;
#line 44 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp7_ = g_strdup (g_value_get_string (&_tmp6_));
#line 44 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_free0 (self->priv->micolor);
#line 44 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	self->priv->micolor = _tmp7_;
#line 40 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	G_IS_VALUE (&val1) ? (g_value_unset (&val1), NULL) : NULL;
#line 421 "config.c"
}


static gint
_sqlite3_exec (sqlite3* self,
               const gchar* sql,
               sqlite3_callback callback,
               gpointer callback_target,
               gchar* * errmsg)
{
	gchar* _vala_errmsg = NULL;
	gint result = 0;
	const gchar* sqlite_errmsg = NULL;
	gint ec = 0;
	const gchar* _tmp0_ = NULL;
	gint _tmp1_;
	const gchar* _tmp4_;
#line 34 "/usr/share/vala-0.40/vapi/sqlite3.vapi"
	g_return_val_if_fail (self != NULL, 0);
#line 34 "/usr/share/vala-0.40/vapi/sqlite3.vapi"
	g_return_val_if_fail (sql != NULL, 0);
#line 36 "/usr/share/vala-0.40/vapi/sqlite3.vapi"
	_tmp1_ = sqlite3_exec (self, sql, callback, callback_target, (char**) (&_tmp0_));
#line 36 "/usr/share/vala-0.40/vapi/sqlite3.vapi"
	sqlite_errmsg = _tmp0_;
#line 36 "/usr/share/vala-0.40/vapi/sqlite3.vapi"
	ec = _tmp1_;
#line 37 "/usr/share/vala-0.40/vapi/sqlite3.vapi"
	if ((&_vala_errmsg) != NULL) {
#line 451 "config.c"
		const gchar* _tmp2_;
		gchar* _tmp3_;
#line 38 "/usr/share/vala-0.40/vapi/sqlite3.vapi"
		_tmp2_ = sqlite_errmsg;
#line 38 "/usr/share/vala-0.40/vapi/sqlite3.vapi"
		_tmp3_ = g_strdup (_tmp2_);
#line 38 "/usr/share/vala-0.40/vapi/sqlite3.vapi"
		_g_free0 (_vala_errmsg);
#line 38 "/usr/share/vala-0.40/vapi/sqlite3.vapi"
		_vala_errmsg = _tmp3_;
#line 462 "config.c"
	}
#line 40 "/usr/share/vala-0.40/vapi/sqlite3.vapi"
	_tmp4_ = sqlite_errmsg;
#line 40 "/usr/share/vala-0.40/vapi/sqlite3.vapi"
	sqlite3_free ((void*) _tmp4_);
#line 41 "/usr/share/vala-0.40/vapi/sqlite3.vapi"
	result = ec;
#line 41 "/usr/share/vala-0.40/vapi/sqlite3.vapi"
	if (errmsg) {
#line 41 "/usr/share/vala-0.40/vapi/sqlite3.vapi"
		*errmsg = _vala_errmsg;
#line 474 "config.c"
	} else {
#line 41 "/usr/share/vala-0.40/vapi/sqlite3.vapi"
		_g_free0 (_vala_errmsg);
#line 478 "config.c"
	}
#line 41 "/usr/share/vala-0.40/vapi/sqlite3.vapi"
	return result;
#line 482 "config.c"
}


void
crono_config_click_aplicar_config (cronoconfig* self)
{
	gchar* errmsg = NULL;
	gchar* query = NULL;
	GtkEntry* _tmp0_;
	const gchar* _tmp1_;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	const gchar* _tmp7_;
	gchar* _tmp8_;
	gchar* _tmp9_;
	gchar* _tmp10_;
	gchar* _tmp11_;
	sqlite3* _tmp12_;
	const gchar* _tmp13_;
	gchar* _tmp14_ = NULL;
	gint _tmp15_;
	gint _tmp16_;
	const gchar* _tmp18_;
	GtkDialog* _tmp19_;
#line 46 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	g_return_if_fail (CRONO_IS_CONFIG (self));
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp0_ = self->ruta;
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp1_ = gtk_entry_get_text (_tmp0_);
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp2_ = _tmp1_;
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp3_ = g_strconcat ("UPDATE config SET ruta='", _tmp2_, NULL);
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp4_ = _tmp3_;
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp5_ = g_strconcat (_tmp4_, "', color='", NULL);
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp6_ = _tmp5_;
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp7_ = self->priv->micolor;
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp8_ = g_strconcat (_tmp6_, _tmp7_, NULL);
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp9_ = _tmp8_;
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp10_ = g_strconcat (_tmp9_, "' WHERE id=0;", NULL);
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp11_ = _tmp10_;
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_free0 (_tmp9_);
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_free0 (_tmp6_);
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_free0 (_tmp4_);
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	query = _tmp11_;
#line 49 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp12_ = crono_db_config;
#line 49 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp13_ = query;
#line 49 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp15_ = _sqlite3_exec (_tmp12_, _tmp13_, NULL, NULL, &_tmp14_);
#line 49 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_free0 (errmsg);
#line 49 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	errmsg = _tmp14_;
#line 49 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	crono_rc = _tmp15_;
#line 50 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp16_ = crono_rc;
#line 50 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	if (_tmp16_ != SQLITE_OK) {
#line 560 "config.c"
		const gchar* _tmp17_;
#line 50 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
		_tmp17_ = errmsg;
#line 50 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
		g_print ("Error: %s\n", _tmp17_);
#line 566 "config.c"
	}
#line 51 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp18_ = self->priv->micolor;
#line 51 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	crono_config_aplicar_color (self, _tmp18_);
#line 52 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp19_ = self->dialog;
#line 52 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	gtk_widget_destroy (G_TYPE_CHECK_INSTANCE_CAST (_tmp19_, gtk_widget_get_type (), GtkWidget));
#line 46 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_free0 (query);
#line 46 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_free0 (errmsg);
#line 580 "config.c"
}


void
crono_config_llenar_estilo (cronoconfig* self)
{
	GtkCellRendererText* cell_box = NULL;
	GtkCellRendererText* _tmp0_;
	GtkListStore* _tmp1_;
	GtkListStore* _tmp2_;
	GtkTreeIter _tmp3_ = {0};
	GtkListStore* _tmp4_;
	GtkTreeIter _tmp5_;
	GtkListStore* _tmp6_;
	GtkTreeIter _tmp7_ = {0};
	GtkListStore* _tmp8_;
	GtkTreeIter _tmp9_;
	GtkListStore* _tmp10_;
	GtkTreeIter _tmp11_ = {0};
	GtkListStore* _tmp12_;
	GtkTreeIter _tmp13_;
	GtkListStore* _tmp14_;
	GtkTreeIter _tmp15_ = {0};
	GtkListStore* _tmp16_;
	GtkTreeIter _tmp17_;
	GtkListStore* _tmp18_;
	GtkTreeIter _tmp19_ = {0};
	GtkListStore* _tmp20_;
	GtkTreeIter _tmp21_;
	GtkComboBox* _tmp22_;
	GtkListStore* _tmp23_;
#line 54 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	g_return_if_fail (CRONO_IS_CONFIG (self));
#line 55 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp0_ = (GtkCellRendererText*) gtk_cell_renderer_text_new ();
#line 55 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	if (_tmp0_) {
#line 55 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
		g_object_set_data ((GObject *) _tmp0_, "vala-creation-function", "crono.config.llenar_estilo");
#line 620 "config.c"
	}
#line 55 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	g_object_ref_sink (_tmp0_);
#line 55 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	cell_box = _tmp0_;
#line 56 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp1_ = self->priv->list_box;
#line 56 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	gtk_list_store_clear (_tmp1_);
#line 57 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp2_ = self->priv->list_box;
#line 57 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	gtk_list_store_append (_tmp2_, &_tmp3_);
#line 57 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	self->priv->iter_box = _tmp3_;
#line 58 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp4_ = self->priv->list_box;
#line 58 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp5_ = self->priv->iter_box;
#line 58 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	gtk_list_store_set (_tmp4_, &_tmp5_, 0, "amarillo", -1);
#line 59 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp6_ = self->priv->list_box;
#line 59 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	gtk_list_store_append (_tmp6_, &_tmp7_);
#line 59 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	self->priv->iter_box = _tmp7_;
#line 60 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp8_ = self->priv->list_box;
#line 60 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp9_ = self->priv->iter_box;
#line 60 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	gtk_list_store_set (_tmp8_, &_tmp9_, 0, "azul", -1);
#line 61 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp10_ = self->priv->list_box;
#line 61 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	gtk_list_store_append (_tmp10_, &_tmp11_);
#line 61 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	self->priv->iter_box = _tmp11_;
#line 62 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp12_ = self->priv->list_box;
#line 62 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp13_ = self->priv->iter_box;
#line 62 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	gtk_list_store_set (_tmp12_, &_tmp13_, 0, "rosa", -1);
#line 63 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp14_ = self->priv->list_box;
#line 63 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	gtk_list_store_append (_tmp14_, &_tmp15_);
#line 63 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	self->priv->iter_box = _tmp15_;
#line 64 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp16_ = self->priv->list_box;
#line 64 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp17_ = self->priv->iter_box;
#line 64 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	gtk_list_store_set (_tmp16_, &_tmp17_, 0, "marron", -1);
#line 65 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp18_ = self->priv->list_box;
#line 65 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	gtk_list_store_append (_tmp18_, &_tmp19_);
#line 65 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	self->priv->iter_box = _tmp19_;
#line 66 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp20_ = self->priv->list_box;
#line 66 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp21_ = self->priv->iter_box;
#line 66 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	gtk_list_store_set (_tmp20_, &_tmp21_, 0, "verde", -1);
#line 67 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp22_ = self->estilo;
#line 67 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp23_ = self->priv->list_box;
#line 67 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	gtk_combo_box_set_model (_tmp22_, G_TYPE_CHECK_INSTANCE_CAST (_tmp23_, gtk_tree_model_get_type (), GtkTreeModel));
#line 54 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_object_unref0 (cell_box);
#line 698 "config.c"
}


static void
crono_config_class_init (cronoconfigClass * klass)
{
#line 9 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	crono_config_parent_class = g_type_class_peek_parent (klass);
#line 9 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	g_type_class_add_private (klass, sizeof (cronoconfigPrivate));
#line 9 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	G_OBJECT_CLASS (klass)->finalize = crono_config_finalize;
#line 711 "config.c"
}


static void
crono_config_instance_init (cronoconfig * self)
{
	GtkListStore* _tmp0_;
#line 9 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	self->priv = CRONO_CONFIG_GET_PRIVATE (self);
#line 15 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_tmp0_ = gtk_list_store_new (1, G_TYPE_STRING, -1);
#line 15 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	if (_tmp0_) {
#line 15 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
		g_object_set_data ((GObject *) _tmp0_, "vala-creation-function", "");
#line 727 "config.c"
	}
#line 15 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	self->priv->list_box = _tmp0_;
#line 731 "config.c"
}


static void
crono_config_finalize (GObject * obj)
{
	cronoconfig * self;
#line 9 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, CRONO_TYPE_CONFIG, cronoconfig);
#line 10 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_object_unref0 (self->priv->builder);
#line 11 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_object_unref0 (self->dialog);
#line 12 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_object_unref0 (self->btn_aplicar);
#line 13 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_object_unref0 (self->ruta);
#line 14 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_object_unref0 (self->estilo);
#line 15 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_object_unref0 (self->priv->list_box);
#line 17 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	_g_free0 (self->priv->micolor);
#line 9 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/config.vala"
	G_OBJECT_CLASS (crono_config_parent_class)->finalize (obj);
#line 757 "config.c"
}


GType
crono_config_get_type (void)
{
	static volatile gsize crono_config_type_id__volatile = 0;
	if (g_once_init_enter (&crono_config_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (cronoconfigClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) crono_config_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (cronoconfig), 0, (GInstanceInitFunc) crono_config_instance_init, NULL };
		GType crono_config_type_id;
		crono_config_type_id = g_type_register_static (gtk_dialog_get_type (), "cronoconfig", &g_define_type_info, 0);
		g_once_init_leave (&crono_config_type_id__volatile, crono_config_type_id);
	}
	return crono_config_type_id__volatile;
}


