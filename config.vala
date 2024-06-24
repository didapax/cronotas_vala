/*
Cronotas (c) Didapax Sistem Daniel Alfonsi 
2019
*/
using Gtk;
using crono;

namespace crono{
    class config: Gtk.Dialog {
      private Builder builder;
      public Gtk.Dialog dialog; 
      public Button btn_aplicar;
      public Entry ruta; 
      public ComboBox estilo; 
	   Gtk.ListStore list_box = new Gtk.ListStore (1, typeof (string));
  		Gtk.TreeIter iter_box;  
      string micolor; 
      public config(){
         builder = new Builder();
         builder.add_from_file (fconfig.ruta+"config.ui");
         dialog = builder.get_object("dialog_config") as Gtk.Dialog;
         builder.connect_signals (null);
         btn_aplicar = builder.get_object("btn_aplicar") as Button;
         btn_aplicar.clicked.connect(click_aplicar_config);
         ruta = builder.get_object("ruta") as Entry;
         estilo = builder.get_object("estilo") as ComboBox;
         estilo.changed.connect(changed);
         llenar_estilo();
         micolor= fconfig.color;
         ruta.text = fconfig.ruta;
         dialog.show_all();
      }
     public void aplicar_color(string color){
   		var screen = Gdk.Screen.get_default();	
   		var css_provider = new CssProvider();
   		css_provider.load_from_path(fconfig.ruta+color+".css");
   		var style_context = this.get_style_context();		
   		style_context.add_provider_for_screen(screen, css_provider, STYLE_PROVIDER_PRIORITY_USER);
      }
      public void changed(){
         GLib.Value val1;
         bool ff= estilo.get_active_iter(out iter_box);
         list_box.get_value(iter_box,0, out val1);
         micolor=(string)val1;
      }
      public void click_aplicar_config(){
         string errmsg;
         string query = "UPDATE config SET ruta='"+ruta.text+"', color='"+micolor+"' WHERE id=0;";
         rc = db_config.exec (query, null, out errmsg);
         if(rc!=Sqlite.OK)print("Error: %s\n",errmsg);   
         aplicar_color(micolor);
         dialog.destroy();
      }  
      public void llenar_estilo(){
         Gtk.CellRendererText cell_box = new Gtk.CellRendererText ();
         list_box.clear();
         list_box.append (out iter_box);
         list_box.set(iter_box,0,"amarillo");
         list_box.append (out iter_box);
         list_box.set(iter_box,0,"azul");
         list_box.append (out iter_box);
         list_box.set(iter_box,0,"rosa");
         list_box.append (out iter_box);
         list_box.set(iter_box,0,"marron");
         list_box.append (out iter_box);
         list_box.set(iter_box,0,"verde");
         estilo.set_model(list_box);
      }
   }
}

