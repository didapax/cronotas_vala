/* tempo.c generated by valac 0.40.8, the Vala compiler
 * generated from tempo.vala, do not modify */

/*
Cronotas (c) Didapax Sistem Daniel Alfonsi 
2019
*/


#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>


#define CRONO_TYPE_TEMPO (crono_tempo_get_type ())
#define CRONO_TEMPO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CRONO_TYPE_TEMPO, cronotempo))
#define CRONO_TEMPO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CRONO_TYPE_TEMPO, cronotempoClass))
#define CRONO_IS_TEMPO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CRONO_TYPE_TEMPO))
#define CRONO_IS_TEMPO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CRONO_TYPE_TEMPO))
#define CRONO_TEMPO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CRONO_TYPE_TEMPO, cronotempoClass))

typedef struct _cronotempo cronotempo;
typedef struct _cronotempoClass cronotempoClass;
typedef struct _cronotempoPrivate cronotempoPrivate;
enum  {
	CRONO_TEMPO_0_PROPERTY,
	CRONO_TEMPO_NUM_PROPERTIES
};
static GParamSpec* crono_tempo_properties[CRONO_TEMPO_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define CRONO_TYPE_F_CONFIG (crono_f_config_get_type ())
typedef struct _cronof_config cronof_config;
#define _g_free0(var) (var = (g_free (var), NULL))

struct _cronotempo {
	GtkDialog parent_instance;
	cronotempoPrivate * priv;
	GtkDialog* dialog;
};

struct _cronotempoClass {
	GtkDialogClass parent_class;
};

struct _cronotempoPrivate {
	GtkStatusIcon* tray_icon1;
	GtkMenu* menu_system;
	GtkBuilder* builder;
	GtkSpinButton* escala;
	GtkButton* cro_play;
	GtkLabel* lminuto;
	guint time_crono;
	gint second;
	gint minute;
	gint num_minute;
	gboolean state_crono;
	gboolean play;
	gboolean stop;
};

struct _cronof_config {
	gchar* id;
	gchar* ruta;
	gchar* color;
};


static gpointer crono_tempo_parent_class = NULL;
extern cronof_config crono_fconfig;

GType crono_tempo_get_type (void) G_GNUC_CONST;
#define CRONO_TEMPO_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), CRONO_TYPE_TEMPO, cronotempoPrivate))
cronotempo* crono_tempo_new (void);
cronotempo* crono_tempo_construct (GType object_type);
GType crono_f_config_get_type (void) G_GNUC_CONST;
cronof_config* crono_f_config_dup (const cronof_config* self);
void crono_f_config_free (cronof_config* self);
void crono_f_config_copy (const cronof_config* self,
                          cronof_config* dest);
void crono_f_config_destroy (cronof_config* self);
void crono_tempo_escala_change_value (cronotempo* self);
static void _crono_tempo_escala_change_value_gtk_spin_button_value_changed (GtkSpinButton* _sender,
                                                                     gpointer self);
void crono_tempo_croplay (cronotempo* self);
static void _crono_tempo_croplay_gtk_button_clicked (GtkButton* _sender,
                                              gpointer self);
gboolean crono_tempo_on_timer_event (cronotempo* self);
static gboolean _crono_tempo_on_timer_event_gsource_func (gpointer self);
void crono_tempo_create_menu_system (cronotempo* self);
static void crono_tempo_menu_system_popup (cronotempo* self,
                                    guint button,
                                    guint time);
static void _crono_tempo_menu_system_popup_gtk_status_icon_popup_menu (GtkStatusIcon* _sender,
                                                                guint button,
                                                                guint activate_time,
                                                                gpointer self);
static void crono_tempo_dialog_response (cronotempo* self,
                                  GtkDialog* dialog,
                                  gint response_id);
gchar* crono_formatT (gint valor);
static void _crono_tempo_dialog_response_gtk_dialog_response (GtkDialog* _sender,
                                                       gint response_id,
                                                       gpointer self);
static void __lambda5_ (cronotempo* self);
static void ___lambda5__gtk_menu_item_activate (GtkMenuItem* _sender,
                                         gpointer self);
static void crono_tempo_finalize (GObject * obj);


static gpointer
_g_object_ref0 (gpointer self)
{
#line 30 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	return self ? g_object_ref (self) : NULL;
#line 121 "tempo.c"
}


static void
_crono_tempo_escala_change_value_gtk_spin_button_value_changed (GtkSpinButton* _sender,
                                                                gpointer self)
{
#line 33 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	crono_tempo_escala_change_value ((cronotempo*) self);
#line 131 "tempo.c"
}


static void
_crono_tempo_croplay_gtk_button_clicked (GtkButton* _sender,
                                         gpointer self)
{
#line 35 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	crono_tempo_croplay ((cronotempo*) self);
#line 141 "tempo.c"
}


cronotempo*
crono_tempo_construct (GType object_type)
{
	cronotempo * self = NULL;
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
	GtkSpinButton* _tmp12_;
	GtkSpinButton* _tmp13_;
	GtkBuilder* _tmp14_;
	GObject* _tmp15_;
	GtkButton* _tmp16_;
	GtkButton* _tmp17_;
	GtkBuilder* _tmp18_;
	GObject* _tmp19_;
	GtkLabel* _tmp20_;
	GtkDialog* _tmp21_;
	GError * _inner_error_ = NULL;
#line 25 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	self = (cronotempo*) g_object_new (object_type, NULL);
#line 26 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	self->priv->second = 0;
#line 27 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	self->priv->minute = 0;
#line 28 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp0_ = gtk_builder_new ();
#line 28 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	if (_tmp0_) {
#line 28 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		g_object_set_data ((GObject *) _tmp0_, "vala-creation-function", "crono.tempo.new");
#line 184 "tempo.c"
	}
#line 28 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_g_object_unref0 (self->priv->builder);
#line 28 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	self->priv->builder = _tmp0_;
#line 29 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp1_ = self->priv->builder;
#line 29 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp2_ = crono_fconfig;
#line 29 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp3_ = _tmp2_.ruta;
#line 29 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp4_ = g_strconcat (_tmp3_, "tempo.ui", NULL);
#line 29 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp5_ = _tmp4_;
#line 29 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	gtk_builder_add_from_file (_tmp1_, _tmp5_, &_inner_error_);
#line 29 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_g_free0 (_tmp5_);
#line 29 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 29 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 29 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		g_clear_error (&_inner_error_);
#line 29 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		return NULL;
#line 212 "tempo.c"
	}
#line 30 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp6_ = self->priv->builder;
#line 30 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp7_ = gtk_builder_get_object (_tmp6_, "tempo");
#line 30 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp8_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp7_, gtk_dialog_get_type ()) ? ((GtkDialog*) _tmp7_) : NULL);
#line 30 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_g_object_unref0 (self->dialog);
#line 30 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	self->dialog = _tmp8_;
#line 31 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp9_ = self->priv->builder;
#line 31 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	gtk_builder_connect_signals (_tmp9_, NULL);
#line 32 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp10_ = self->priv->builder;
#line 32 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp11_ = gtk_builder_get_object (_tmp10_, "escala");
#line 32 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp12_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp11_, gtk_spin_button_get_type ()) ? ((GtkSpinButton*) _tmp11_) : NULL);
#line 32 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_g_object_unref0 (self->priv->escala);
#line 32 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	self->priv->escala = _tmp12_;
#line 33 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp13_ = self->priv->escala;
#line 33 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	g_signal_connect_object (_tmp13_, "value-changed", (GCallback) _crono_tempo_escala_change_value_gtk_spin_button_value_changed, self, 0);
#line 34 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp14_ = self->priv->builder;
#line 34 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp15_ = gtk_builder_get_object (_tmp14_, "cro_play");
#line 34 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp16_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp15_, gtk_button_get_type ()) ? ((GtkButton*) _tmp15_) : NULL);
#line 34 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_g_object_unref0 (self->priv->cro_play);
#line 34 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	self->priv->cro_play = _tmp16_;
#line 35 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp17_ = self->priv->cro_play;
#line 35 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	g_signal_connect_object (_tmp17_, "clicked", (GCallback) _crono_tempo_croplay_gtk_button_clicked, self, 0);
#line 36 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp18_ = self->priv->builder;
#line 36 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp19_ = gtk_builder_get_object (_tmp18_, "lminutos");
#line 36 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp20_ = _g_object_ref0 (G_TYPE_CHECK_INSTANCE_TYPE (_tmp19_, gtk_label_get_type ()) ? ((GtkLabel*) _tmp19_) : NULL);
#line 36 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_g_object_unref0 (self->priv->lminuto);
#line 36 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	self->priv->lminuto = _tmp20_;
#line 37 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp21_ = self->dialog;
#line 37 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	gtk_widget_show_all (G_TYPE_CHECK_INSTANCE_CAST (_tmp21_, gtk_widget_get_type (), GtkWidget));
#line 25 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	return self;
#line 272 "tempo.c"
}


cronotempo*
crono_tempo_new (void)
{
#line 25 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	return crono_tempo_construct (CRONO_TYPE_TEMPO);
#line 281 "tempo.c"
}


static gchar*
double_to_string (gdouble self)
{
	gchar* result = NULL;
	gchar* _tmp0_;
	gchar* _tmp1_;
	gint _tmp1__length1;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* _tmp4_;
#line 883 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp0_ = g_new0 (gchar, G_ASCII_DTOSTR_BUF_SIZE);
#line 883 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp1_ = _tmp0_;
#line 883 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp1__length1 = G_ASCII_DTOSTR_BUF_SIZE;
#line 883 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp2_ = g_ascii_dtostr (_tmp1_, G_ASCII_DTOSTR_BUF_SIZE, self);
#line 883 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp3_ = g_strdup (_tmp2_);
#line 883 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp4_ = _tmp3_;
#line 883 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	_tmp1_ = (g_free (_tmp1_), NULL);
#line 883 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	result = _tmp4_;
#line 883 "/usr/share/vala-0.40/vapi/glib-2.0.vapi"
	return result;
#line 313 "tempo.c"
}


void
crono_tempo_escala_change_value (cronotempo* self)
{
	GtkLabel* _tmp0_;
	GtkSpinButton* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
#line 39 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	g_return_if_fail (CRONO_IS_TEMPO (self));
#line 40 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp0_ = self->priv->lminuto;
#line 40 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp1_ = self->priv->escala;
#line 40 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp2_ = double_to_string (gtk_spin_button_get_value (_tmp1_));
#line 40 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp3_ = _tmp2_;
#line 40 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	gtk_label_set_label (_tmp0_, _tmp3_);
#line 40 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_g_free0 (_tmp3_);
#line 338 "tempo.c"
}


static gboolean
_crono_tempo_on_timer_event_gsource_func (gpointer self)
{
	gboolean result;
	result = crono_tempo_on_timer_event ((cronotempo*) self);
#line 47 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	return result;
#line 349 "tempo.c"
}


static void
_crono_tempo_menu_system_popup_gtk_status_icon_popup_menu (GtkStatusIcon* _sender,
                                                           guint button,
                                                           guint activate_time,
                                                           gpointer self)
{
#line 51 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	crono_tempo_menu_system_popup ((cronotempo*) self, button, activate_time);
#line 361 "tempo.c"
}


void
crono_tempo_croplay (cronotempo* self)
{
	GtkSpinButton* _tmp0_;
	gint _tmp1_;
	gboolean _tmp2_;
	cronof_config _tmp3_;
	const gchar* _tmp4_;
	gchar* _tmp5_;
	gchar* _tmp6_;
	GtkStatusIcon* _tmp7_;
	GtkStatusIcon* _tmp8_;
	GtkStatusIcon* _tmp9_;
	GtkDialog* _tmp10_;
#line 42 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	g_return_if_fail (CRONO_IS_TEMPO (self));
#line 43 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp0_ = self->priv->escala;
#line 43 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	self->priv->num_minute = (gint) gtk_spin_button_get_value (_tmp0_);
#line 44 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp1_ = self->priv->num_minute;
#line 44 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	self->priv->minute = _tmp1_ * 60;
#line 45 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	self->priv->second = 60;
#line 46 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp2_ = self->priv->play;
#line 46 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	self->priv->state_crono = _tmp2_;
#line 47 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	self->priv->time_crono = g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) 1000, _crono_tempo_on_timer_event_gsource_func, g_object_ref (self), g_object_unref);
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp3_ = crono_fconfig;
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp4_ = _tmp3_.ruta;
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp5_ = g_strconcat (_tmp4_, "indicator1.png", NULL);
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp6_ = _tmp5_;
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp7_ = gtk_status_icon_new_from_file (_tmp6_);
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	if (_tmp7_) {
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		g_object_set_data ((GObject *) _tmp7_, "vala-creation-function", "crono.tempo.croplay");
#line 411 "tempo.c"
	}
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_g_object_unref0 (self->priv->tray_icon1);
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	self->priv->tray_icon1 = _tmp7_;
#line 48 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_g_free0 (_tmp6_);
#line 49 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp8_ = self->priv->tray_icon1;
#line 49 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	gtk_status_icon_set_visible (_tmp8_, TRUE);
#line 50 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	crono_tempo_create_menu_system (self);
#line 51 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp9_ = self->priv->tray_icon1;
#line 51 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	g_signal_connect_object (_tmp9_, "popup-menu", (GCallback) _crono_tempo_menu_system_popup_gtk_status_icon_popup_menu, self, 0);
#line 52 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp10_ = self->dialog;
#line 52 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	gtk_widget_destroy (G_TYPE_CHECK_INSTANCE_CAST (_tmp10_, gtk_widget_get_type (), GtkWidget));
#line 433 "tempo.c"
}


static void
crono_tempo_dialog_response (cronotempo* self,
                             GtkDialog* dialog,
                             gint response_id)
{
#line 54 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	g_return_if_fail (CRONO_IS_TEMPO (self));
#line 54 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	g_return_if_fail (GTK_IS_DIALOG (dialog));
#line 55 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	switch (response_id) {
#line 55 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		case GTK_RESPONSE_OK:
#line 450 "tempo.c"
		{
			GtkStatusIcon* _tmp0_;
#line 57 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp0_ = self->priv->tray_icon1;
#line 57 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			gtk_status_icon_set_visible (_tmp0_, FALSE);
#line 58 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			break;
#line 459 "tempo.c"
		}
		default:
#line 55 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		break;
#line 464 "tempo.c"
	}
#line 60 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	gtk_widget_destroy (G_TYPE_CHECK_INSTANCE_CAST (dialog, gtk_widget_get_type (), GtkWidget));
#line 468 "tempo.c"
}


static void
_crono_tempo_dialog_response_gtk_dialog_response (GtkDialog* _sender,
                                                  gint response_id,
                                                  gpointer self)
{
#line 75 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	crono_tempo_dialog_response ((cronotempo*) self, _sender, response_id);
#line 479 "tempo.c"
}


gboolean
crono_tempo_on_timer_event (cronotempo* self)
{
	gboolean result = FALSE;
	gboolean _tmp0_;
	gboolean _tmp1_;
	gboolean _tmp42_;
	GError * _inner_error_ = NULL;
#line 62 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	g_return_val_if_fail (CRONO_IS_TEMPO (self), FALSE);
#line 63 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp0_ = self->priv->state_crono;
#line 63 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp1_ = self->priv->play;
#line 63 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	if (_tmp0_ == _tmp1_) {
#line 499 "tempo.c"
		gint _tmp2_;
		gint _tmp3_;
		gint _tmp4_;
		gint _tmp5_;
		gint _tmp11_;
		GtkStatusIcon* _tmp12_;
		gint _tmp13_;
		gchar* _tmp14_;
		gchar* _tmp15_;
		gchar* _tmp16_;
		gchar* _tmp17_;
		gint _tmp18_;
		gchar* _tmp19_;
		gchar* _tmp20_;
		gchar* _tmp21_;
		gchar* _tmp22_;
		gint _tmp23_;
#line 64 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		_tmp2_ = self->priv->second;
#line 64 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		self->priv->second = _tmp2_ - 1;
#line 65 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		_tmp3_ = self->priv->minute;
#line 65 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		self->priv->minute = _tmp3_ - 1;
#line 66 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		_tmp4_ = self->priv->minute;
#line 66 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		_tmp5_ = self->priv->num_minute;
#line 66 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		if (_tmp4_ == ((_tmp5_ * 60) / 2)) {
#line 531 "tempo.c"
			GtkStatusIcon* _tmp6_;
			cronof_config _tmp7_;
			const gchar* _tmp8_;
			gchar* _tmp9_;
			gchar* _tmp10_;
#line 66 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp6_ = self->priv->tray_icon1;
#line 66 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp7_ = crono_fconfig;
#line 66 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp8_ = _tmp7_.ruta;
#line 66 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp9_ = g_strconcat (_tmp8_, "indicator2.png", NULL);
#line 66 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp10_ = _tmp9_;
#line 66 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			gtk_status_icon_set_from_file (_tmp6_, _tmp10_);
#line 66 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_g_free0 (_tmp10_);
#line 551 "tempo.c"
		}
#line 67 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		_tmp11_ = self->priv->second;
#line 67 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		if (_tmp11_ == 0) {
#line 67 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			self->priv->second = 60;
#line 559 "tempo.c"
		}
#line 68 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		_tmp12_ = self->priv->tray_icon1;
#line 68 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		_tmp13_ = self->priv->minute;
#line 68 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		_tmp14_ = crono_formatT (_tmp13_ / 60);
#line 68 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		_tmp15_ = _tmp14_;
#line 68 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		_tmp16_ = g_strconcat (_tmp15_, ":", NULL);
#line 68 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		_tmp17_ = _tmp16_;
#line 68 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		_tmp18_ = self->priv->second;
#line 68 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		_tmp19_ = crono_formatT (_tmp18_);
#line 68 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		_tmp20_ = _tmp19_;
#line 68 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		_tmp21_ = g_strconcat (_tmp17_, _tmp20_, NULL);
#line 68 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		_tmp22_ = _tmp21_;
#line 68 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		gtk_status_icon_set_tooltip_text (_tmp12_, _tmp22_);
#line 68 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		_g_free0 (_tmp22_);
#line 68 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		_g_free0 (_tmp20_);
#line 68 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		_g_free0 (_tmp17_);
#line 68 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		_g_free0 (_tmp15_);
#line 69 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		_tmp23_ = self->priv->minute;
#line 69 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		if (_tmp23_ == 0) {
#line 597 "tempo.c"
			gboolean _tmp24_;
			GtkStatusIcon* _tmp25_;
			cronof_config _tmp26_;
			const gchar* _tmp27_;
			gchar* _tmp28_;
			gchar* _tmp29_;
			GtkMessageDialog* messagedialog = NULL;
			gint _tmp31_;
			gchar* _tmp32_;
			gchar* _tmp33_;
			gchar* _tmp34_;
			gchar* _tmp35_;
			gchar* _tmp36_;
			gchar* _tmp37_;
			GtkMessageDialog* _tmp38_;
			GtkMessageDialog* _tmp39_;
			GtkMessageDialog* _tmp40_;
			GtkMessageDialog* _tmp41_;
#line 70 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp24_ = self->priv->stop;
#line 70 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			self->priv->state_crono = _tmp24_;
#line 71 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp25_ = self->priv->tray_icon1;
#line 71 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp26_ = crono_fconfig;
#line 71 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp27_ = _tmp26_.ruta;
#line 71 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp28_ = g_strconcat (_tmp27_, "indicator3.png", NULL);
#line 71 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp29_ = _tmp28_;
#line 71 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			gtk_status_icon_set_from_file (_tmp25_, _tmp29_);
#line 71 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_g_free0 (_tmp29_);
#line 72 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			g_spawn_command_line_async ("notify-send 'Temporizador.' 'Alarma!! Tiempo Completado...'", &_inner_error_);
#line 72 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			if (G_UNLIKELY (_inner_error_ != NULL)) {
#line 638 "tempo.c"
				gboolean _tmp30_ = FALSE;
#line 72 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
				g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
#line 72 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
				g_clear_error (&_inner_error_);
#line 72 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
				return _tmp30_;
#line 646 "tempo.c"
			}
#line 73 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp31_ = self->priv->num_minute;
#line 73 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp32_ = g_strdup_printf ("%i", _tmp31_);
#line 73 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp33_ = _tmp32_;
#line 73 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp34_ = g_strconcat ("Tiempo Completado ", _tmp33_, NULL);
#line 73 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp35_ = _tmp34_;
#line 73 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp36_ = g_strconcat (_tmp35_, " Min..", NULL);
#line 73 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp37_ = _tmp36_;
#line 73 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp38_ = (GtkMessageDialog*) gtk_message_dialog_new (G_TYPE_CHECK_INSTANCE_CAST (self, gtk_window_get_type (), GtkWindow), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", _tmp37_);
#line 73 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			if (_tmp38_) {
#line 73 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
				g_object_set_data ((GObject *) _tmp38_, "vala-creation-function", "crono.tempo.on_timer_event");
#line 668 "tempo.c"
			}
#line 73 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			g_object_ref_sink (_tmp38_);
#line 73 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp39_ = _tmp38_;
#line 73 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_g_free0 (_tmp37_);
#line 73 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_g_free0 (_tmp35_);
#line 73 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_g_free0 (_tmp33_);
#line 73 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			messagedialog = _tmp39_;
#line 75 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp40_ = messagedialog;
#line 75 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			g_signal_connect_object (G_TYPE_CHECK_INSTANCE_CAST (_tmp40_, gtk_dialog_get_type (), GtkDialog), "response", (GCallback) _crono_tempo_dialog_response_gtk_dialog_response, self, 0);
#line 76 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_tmp41_ = messagedialog;
#line 76 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			gtk_widget_show (G_TYPE_CHECK_INSTANCE_CAST (_tmp41_, gtk_widget_get_type (), GtkWidget));
#line 69 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
			_g_object_unref0 (messagedialog);
#line 692 "tempo.c"
		}
	}
#line 79 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp42_ = self->priv->state_crono;
#line 79 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	result = _tmp42_;
#line 79 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	return result;
#line 701 "tempo.c"
}


static void
crono_tempo_menu_system_popup (cronotempo* self,
                               guint button,
                               guint time)
{
	GtkMenu* _tmp0_;
#line 81 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	g_return_if_fail (CRONO_IS_TEMPO (self));
#line 82 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp0_ = self->priv->menu_system;
#line 82 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	gtk_menu_popup (_tmp0_, NULL, NULL, NULL, NULL, button, (guint32) time);
#line 717 "tempo.c"
}


static void
__lambda5_ (cronotempo* self)
{
	gboolean _tmp0_;
	GtkStatusIcon* _tmp1_;
#line 87 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp0_ = self->priv->stop;
#line 87 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	self->priv->state_crono = _tmp0_;
#line 87 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp1_ = self->priv->tray_icon1;
#line 87 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	gtk_status_icon_set_visible (_tmp1_, FALSE);
#line 734 "tempo.c"
}


static void
___lambda5__gtk_menu_item_activate (GtkMenuItem* _sender,
                                    gpointer self)
{
#line 87 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	__lambda5_ ((cronotempo*) self);
#line 744 "tempo.c"
}


void
crono_tempo_create_menu_system (cronotempo* self)
{
	GtkMenu* _tmp0_;
	GtkMenuItem* menu_quit = NULL;
	GtkMenuItem* _tmp1_;
	GtkMenu* _tmp2_;
	GtkMenu* _tmp3_;
#line 84 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	g_return_if_fail (CRONO_IS_TEMPO (self));
#line 85 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp0_ = (GtkMenu*) gtk_menu_new ();
#line 85 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	if (_tmp0_) {
#line 85 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		g_object_set_data ((GObject *) _tmp0_, "vala-creation-function", "crono.tempo.create_menu_system");
#line 764 "tempo.c"
	}
#line 85 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	g_object_ref_sink (_tmp0_);
#line 85 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_g_object_unref0 (self->priv->menu_system);
#line 85 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	self->priv->menu_system = _tmp0_;
#line 86 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp1_ = (GtkMenuItem*) gtk_menu_item_new_with_label ("Detener Temporizador");
#line 86 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	if (_tmp1_) {
#line 86 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
		g_object_set_data ((GObject *) _tmp1_, "vala-creation-function", "crono.tempo.create_menu_system");
#line 778 "tempo.c"
	}
#line 86 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	g_object_ref_sink (_tmp1_);
#line 86 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	menu_quit = _tmp1_;
#line 87 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	g_signal_connect_object (menu_quit, "activate", (GCallback) ___lambda5__gtk_menu_item_activate, self, 0);
#line 88 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp2_ = self->priv->menu_system;
#line 88 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	gtk_menu_shell_append (G_TYPE_CHECK_INSTANCE_CAST (_tmp2_, gtk_menu_shell_get_type (), GtkMenuShell), menu_quit);
#line 89 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_tmp3_ = self->priv->menu_system;
#line 89 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	gtk_widget_show_all (G_TYPE_CHECK_INSTANCE_CAST (_tmp3_, gtk_widget_get_type (), GtkWidget));
#line 84 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_g_object_unref0 (menu_quit);
#line 796 "tempo.c"
}


static void
crono_tempo_class_init (cronotempoClass * klass)
{
#line 9 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	crono_tempo_parent_class = g_type_class_peek_parent (klass);
#line 9 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	g_type_class_add_private (klass, sizeof (cronotempoPrivate));
#line 9 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	G_OBJECT_CLASS (klass)->finalize = crono_tempo_finalize;
#line 809 "tempo.c"
}


static void
crono_tempo_instance_init (cronotempo * self)
{
#line 9 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	self->priv = CRONO_TEMPO_GET_PRIVATE (self);
#line 22 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	self->priv->play = TRUE;
#line 23 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	self->priv->stop = FALSE;
#line 822 "tempo.c"
}


static void
crono_tempo_finalize (GObject * obj)
{
	cronotempo * self;
#line 9 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, CRONO_TYPE_TEMPO, cronotempo);
#line 10 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_g_object_unref0 (self->priv->tray_icon1);
#line 11 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_g_object_unref0 (self->priv->menu_system);
#line 12 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_g_object_unref0 (self->priv->builder);
#line 13 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_g_object_unref0 (self->dialog);
#line 14 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_g_object_unref0 (self->priv->escala);
#line 15 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_g_object_unref0 (self->priv->cro_play);
#line 16 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	_g_object_unref0 (self->priv->lminuto);
#line 9 "/home/didapax/Yandex.Disk/proyectos/vala/cronotas.0.2.1/tempo.vala"
	G_OBJECT_CLASS (crono_tempo_parent_class)->finalize (obj);
#line 848 "tempo.c"
}


GType
crono_tempo_get_type (void)
{
	static volatile gsize crono_tempo_type_id__volatile = 0;
	if (g_once_init_enter (&crono_tempo_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (cronotempoClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) crono_tempo_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (cronotempo), 0, (GInstanceInitFunc) crono_tempo_instance_init, NULL };
		GType crono_tempo_type_id;
		crono_tempo_type_id = g_type_register_static (gtk_dialog_get_type (), "cronotempo", &g_define_type_info, 0);
		g_once_init_leave (&crono_tempo_type_id__volatile, crono_tempo_type_id);
	}
	return crono_tempo_type_id__volatile;
}



