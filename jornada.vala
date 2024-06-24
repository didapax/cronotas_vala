/*
Cronotas (c) Didapax Sistem Daniel Alfonsi 
2019
*/
using Gtk;
using Sqlite;
using GLib;
using crono;

namespace crono{
    class dialog_jornada: Gtk.Dialog {
      private Builder builder;
      private Gtk.Dialog dialog; 
      private TreeView lista;
      private ComboBox combo_mes;
      private Label label_total;
      private Label lfecha;
      private Label ldia;
      private Label lmes;    
      private Calendar calendar;
		Gtk.ListStore list_box = new Gtk.ListStore (1, typeof (string));
  		Gtk.TreeIter iter_box;   
      Gtk.CellRendererText cell = new Gtk.CellRendererText ();
      Statement stmt_jornada;
      Gtk.ListStore list_store = new Gtk.ListStore (2, typeof (string), typeof (string));
      Gtk.TreeIter iter;   

      public dialog_jornada(){
			var now = new DateTime.now_local ();
         builder = new Builder();
         builder.add_from_file (fconfig.ruta+"jornada.ui");
         builder.connect_signals (null);
         dialog = builder.get_object("jornadas") as Gtk.Dialog;
         lista= builder.get_object("lista") as TreeView;
         lista.cursor_changed.connect(cursor_changed);
         calendar= builder.get_object("calendar") as Calendar;
         combo_mes= builder.get_object("combo_mes") as ComboBox;
         combo_mes.changed.connect(changed);
         label_total = builder.get_object("label_total") as Label;
			lfecha = builder.get_object("lfecha") as Label;
			ldia = builder.get_object("ldia") as Label;
			lmes = builder.get_object("lmes") as Label;        
         lista.insert_column_with_attributes (-1, "Fecha", cell, "text", 0);
		   lista.insert_column_with_attributes (-1, "Horas Trabajadas", cell, "text", 1);
         dialog.show_all();
         llenar_meses();
         label_total.label=sum_total("Todo");
         lmes.label = "Todos";
         calendar.year = now.get_year ();
         calendar.month = now.get_month ()-1;
         calendar.day = now.get_day_of_month ();         
      }
      public void cursor_changed (){
			string dia1;
			string dia2;			
         Gtk.TreeSelection sel;
         Gtk.TreeModel model;
         Gtk.TreeIter iter1;
         GLib.Value val1;
         GLib.Value val2;
         sel = lista.get_selection();
         bool ff = sel.get_selected(out model, out iter1);
         list_store.get_value (iter1,0, out val1);
         list_store.get_value (iter1,1, out val2);
			dia1 = (string)val1;
			dia2 = dia1[0:2];
			if (dia2 != null){
				lfecha.label = dia1;
				ldia.label= (string)val2;
				calendar.day =  int.parse(dia2);
			}
      }      
      public string sum_total(string mes){ //id,fecha,hx,mx,horas,mes
         var now = new DateTime.now_local ();
         string query;
         if(mes=="Todo")query = "SELECT *  FROM jornada;"; 
         else  query = "SELECT *  FROM jornada where mes='"+mes+"' and ano='"+now.get_year().to_string()+"';";
   	   rc=db.prepare_v2(query,-1,out stmt_jornada);
         list_store.clear();
         while (stmt_jornada.step() == Sqlite.ROW){
      		list_store.append (out iter);
      		list_store.set (iter, 0, stmt_jornada.column_text(1), 1, stmt_jornada.column_text(4));
         }
         lista.set_model (list_store);
         if(mes=="Todo")query = "select sum(hx) from jornada;"; 
         else  query = "select sum(hx) from jornada where mes='"+mes+"' and ano='"+now.get_year().to_string()+"';";   
     	   rc=db.prepare_v2(query,-1,out stmt_jornada);
         stmt_jornada.step();
         if (stmt_jornada.column_type(0)!=Sqlite.NULL) return (int.parse(stmt_jornada.column_text(0))/3600).to_string()+" Horas Trabajadas"; else return "0 Horas Trabajadas";
      }
      public void changed(){
			var now = new DateTime.now_local ();
         string[] mes={"Todo","Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
         GLib.Value val1;
         bool ff= combo_mes.get_active_iter(out iter_box);
         list_box.get_value(iter_box,0, out val1);
         lmes.label=mes[int.parse((string)val1)];
         label_total.label=sum_total((string)val1);
         calendar.year = now.get_year ();
         calendar.month = int.parse((string)val1)-1;         
      }
      public void llenar_meses(){
         Gtk.CellRendererText cell_box = new Gtk.CellRendererText ();
         list_box.clear();
         for (int i=1; i<=12; i++){
            list_box.append (out iter_box);
            list_box.set(iter_box,0,formatT(i));
         }
         combo_mes.set_model(list_box);
      }
   }
}

