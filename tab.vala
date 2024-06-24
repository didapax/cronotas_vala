/*
Cronotas (c) Didapax Sistem Daniel Alfonsi 
2019
*/
using Gtk;
using Gdk;
using Sqlite;
using GLib;
using crono;

namespace crono{
   public class tab:Gtk.Window{
      private Builder builder;
      private Gtk.Window window;
      private Button btn_fecha;
      private Button cerrar;
      private Button nota_fecha;
      private TextView textnota;
      private Calendar calendar;
      private Gtk.Dialog fecha;
      private Gtk.MenuItem menu_proteger;
      private Gtk.CheckMenuItem menu_above;
      private Gtk.MenuItem menu_guardar;
      private Button campana;
      private Button img_proteger;
      public Widget minimize;
      public Widget ico_cerrar;
      public Widget ico_campana;
      public Widget ico_candado;
      uint time_bar;
      int tmp;
      bool state;
      public tab(int num){
         init(num);
      }
      public void init(int num){
         minimize = new Image.from_file(fconfig.ruta+"minimize.png");
         ico_cerrar = new Image.from_file(fconfig.ruta+"cerrar.png");
         ico_campana = new Image.from_file(fconfig.ruta+"time.png");
         ico_candado = new Image.from_file(fconfig.ruta+"candado.png");
         var now = new DateTime.now_local ();
         builder = new Builder();
         builder.add_from_file (fconfig.ruta+"tab.ui");
         builder.connect_signals (null);
         window = builder.get_object("tab") as Gtk.Window;
         window.destroy.connect(window.close);
         window.set_icon_from_file(fconfig.ruta+"gnote-panel.png");
         menu_above = builder.get_object("menu_above") as Gtk.CheckMenuItem;
         menu_above.activate.connect(click_above);
         menu_guardar = builder.get_object("menu_guardar") as Gtk.MenuItem;
         menu_guardar.activate.connect(diskete);
         menu_proteger = builder.get_object("menu_proteger") as Gtk.MenuItem;
         menu_proteger.activate.connect(proteger_nota);
         nota_fecha = builder.get_object("nota_fecha") as Button;
         nota_fecha.clicked.connect(click_nota_fecha);
         btn_fecha = builder.get_object("btn_fecha") as Button;
         btn_fecha.button_press_event.connect(btn_fecha_button_press_event);
         cerrar = builder.get_object("cerrar") as Button;
         cerrar.clicked.connect(click_close);
         textnota = builder.get_object("textnota") as TextView;
         builder.connect_signals (this);
         fecha = builder.get_object("fecha") as Gtk.Dialog;
         fecha.close.connect(()=>{fecha.hide();});
         calendar = builder.get_object("calendar") as Calendar;
         campana = builder.get_object("campana") as Button;
         campana.set_image(ico_campana);
         img_proteger = builder.get_object("proteger") as Button;
         img_proteger.set_image(ico_candado);
         calendar.year = now.get_year ();
         calendar.month = now.get_month ()-1;
         calendar.day = now.get_day_of_month ();
         window.show_all();
         cerrar.set_image(ico_cerrar);
         tmp=num;
         leeFicha(tmp);
      }
		public bool btn_fecha_button_press_event(EventButton event){
			if (event.type == Gdk.EventType.@2BUTTON_PRESS )
				fecha.show_all();
				return true;
		}      
      public bool on_time_1(){
			if (state) window.set_title ("Nota "+lcd);
			return state;
		}
      public void click_above(){
         if (menu_above.active){
            if (ficha[tmp].proteger==1) cerrar.set_sensitive(true);
            cerrar.set_image(minimize);
            window.set_keep_above(true); 
            window. set_skip_pager_hint(false);
            window. set_skip_taskbar_hint(false);
            window.set_title ("Nota "+lcd);
            state=true;
            time_bar=Timeout.add (1000,on_time_1);
         }
         else{
            if (ficha[tmp].proteger==1) cerrar.set_sensitive(false);
            cerrar.set_image(ico_cerrar);
            window.set_keep_above(false);
            window. set_skip_pager_hint(true);
            window. set_skip_taskbar_hint(true);
            state=false;
         }
      }
      public void diskete(){
         ficha[tmp].visible=true;
         ficha[tmp].nota=textnota.buffer.text;
         guardar(ficha[tmp].nombre,textnota.buffer.text,ficha[tmp].color,ficha[tmp].id);
      }
      public void del_ficha(){
         var messagedialog = new Gtk.MessageDialog (this, Gtk.DialogFlags.MODAL,Gtk.MessageType.WARNING, Gtk.ButtonsType.OK_CANCEL,
                                                "Esta Seguro que desea Borrar la Nota.. ?");
         messagedialog.response.connect (dialog_response_delete);
         messagedialog.show ();
      }
      void dialog_response_delete (Gtk.Dialog dialog, int response_id) {
   		switch (response_id) {
   			case Gtk.ResponseType.OK:{
               string errmsg;
               string query = "DELETE FROM nota WHERE id="+ficha[tmp].id+";";
               rc = db.exec (query, null, out errmsg);
               if(rc!=Sqlite.OK)
                  print("Error: %s\n",errmsg);
               window.destroy();
					if (now_tareas()){
						tray_icon.set_from_file(fconfig.ruta+"gnote-panel-1.png");
						tray_icon.set_tooltip_text("Tiene Notas Para Hoy...");
					}
					else{
						tray_icon.set_from_file(fconfig.ruta+"gnote-panel.png");
						tray_icon.set_tooltip_text("Cronotas 0.2 - Sin Notas Pendientes");
					}               
               }
   			break;
   			case Gtk.ResponseType.CANCEL:
   				print ("good choice\n");
   			break;
   		}
 			dialog.destroy();
   	}
      public void proteger_nota(){
         string errmsg;
         string query;
         if (ficha[tmp].proteger==0){
            ficha[tmp].proteger=1;
            query = "UPDATE nota SET proteger=1 WHERE id="+ficha[tmp].id+";";
            rc = db.exec (query, null, out errmsg);
            if(rc!=Sqlite.OK) print("Error: %s\n",errmsg);
         }
         else
         {
            ficha[tmp].proteger=0;
            query = "UPDATE nota SET proteger=0 WHERE id="+ficha[tmp].id+";";
            rc = db.exec (query, null, out errmsg);
            if(rc!=Sqlite.OK) print("Error: %s\n",errmsg);
         }
         leeFicha(tmp);
      }
     public void proteger(int i){
         if (i==0){
            menu_proteger.set_label("Proteger Nota");
            cerrar.set_visible(true);
            cerrar.set_sensitive(true);
            menu_guardar.set_sensitive(true);
            btn_fecha.set_sensitive(true);
            textnota.set_editable(true);
            img_proteger.set_visible(false);            
         }
         else
         {
            menu_proteger.set_label("Desproteger Nota");
            cerrar.set_visible(false);
            cerrar.set_sensitive(false);
            menu_guardar.set_sensitive(false);
            btn_fecha.set_sensitive(false);
            textnota.set_editable(false);
            img_proteger.set_visible(true);
         }
      }
      public void click_nota_fecha(){
         string mi_fecha = formatT(calendar.day)+"/"+formatT(calendar.month+1)+"/"+calendar.year.to_string();
         string errmsg;
         string query = "UPDATE nota SET fecha='"+mi_fecha+"', nota='"+textnota.buffer.text+"' WHERE id="+ficha[tmp].id+";";
         rc = db.exec (query, null, out errmsg);
         ficha[tmp].fecha = mi_fecha;
         ficha[tmp].nota = textnota.buffer.text;
         leeFicha(tmp);
         if(rc!=Sqlite.OK) print("Error: %s\n",errmsg);
         fecha.hide();
      }
      public void click_close(){
         if (menu_above.active)
            window.iconify();
         else
            del_ficha();
      }
      public void leeFicha(int i){
         textnota.buffer.text="";
         textnota.buffer.text=ficha[i].nota;
         btn_fecha.label=ficha[i].fecha;
         proteger(ficha[i].proteger);
         if (if_tareas_hoy(int.parse(ficha[i].id))){
				campana.set_visible(true);
				tray_icon.set_from_file(fconfig.ruta+"gnote-panel-1.png");
				tray_icon.set_tooltip_text("Tiene Notas Para Hoy...");
			}
			else{
				 campana.set_visible(false);
				 tray_icon.set_from_file(fconfig.ruta+"gnote-panel.png");
				 tray_icon.set_tooltip_text("Cronotas 0.2 - Sin Notas Pendientes");
			}
      }
   }
}
