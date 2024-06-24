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
	Gtk.StatusIcon tray_icon;
	string lcd;
   public class cronotas:Gtk.Window{
      private tab separar;
      private Gtk.Menu menu_system;
      private dialog_jornada jornadas;
      private tempo temporizador;
      private config dialog_config;
      private Gtk.MenuItem menu_trabajo;
      uint time_trabajo;
      int min_trabajo;
      int hour_trabajo;
      int num_jornada;
      int ht;
      bool tra;
      bool state_trabajo;
      bool play=true;
      bool stop=false;
      bool check_jornada;
      public cronotas(){
         init_datos();         
         init();
      }
      public void init(){
			lcd="Pause Ht";
         check_jornada=true;
         tra = false;
         tray_icon = new Gtk.StatusIcon.from_file(fconfig.ruta+"gnote-panel.png");
         tray_icon.set_visible(true);
      	create_menu_system();
         tray_icon.popup_menu.connect(menu_system_popup);
         for (int i=1; i<=max_nota; i++){     
            separar = new tab(i);
         }
         actualiza_tray();
         aplicar_color(fconfig.color);
      }
      private void menu_system_popup(uint button, uint time) {
   		menu_system.popup(null, null, null, button, time);
      }
      public bool on_time_trabajo(){ 
         if(state_trabajo==play){
            tray_icon.set_from_file(fconfig.ruta+"gnote-panel.png");
            check_jornada=false;
            ht++;
            min_trabajo++;
            hour_trabajo++;
            if (min_trabajo==3600) min_trabajo=0;
            lcd=formatT(hour_trabajo/3600)+":"+ formatT(min_trabajo/60) + " Ht";
            tray_icon.set_tooltip_text("Tiempo Trabajado - "+formatT(hour_trabajo/3600)+":"+ formatT(min_trabajo/60) + " ");
            if (ht==34){
               tray_icon.set_from_file(fconfig.ruta+"gnote-panel-2.png");
               guarda_trabajo(hour_trabajo, min_trabajo,formatT(hour_trabajo/3600)+":"+ formatT(min_trabajo/60) + " Ht");
               ht=0;
            }
         }
         return state_trabajo;
      }
      public void time_trabajo_play(){
         if (check_jornada==true){
            menu_trabajo.set_label("Pausar Trabajo");
            state_trabajo=play;
            time_trabajo=Timeout.add (1000,on_time_trabajo); 
            init_trabajo();
            Process.spawn_command_line_async ("notify-send 'Cronotas!' 'Inicio de Jornada de Trabajo...'");
         } 
         else{
            state_trabajo=stop;
            menu_trabajo.set_label("Iniciar Trabajo");
            lcd=" Pause Ht";
            actualiza_tray();
            check_jornada=true;
         }
      }
      public void actualiza_tray(){
          if (now_tareas()){
             tray_icon.set_from_file(fconfig.ruta+"gnote-panel-1.png");
             tray_icon.set_tooltip_text("Tiene Notas Para Hoy...");
             Process.spawn_command_line_async ("notify-send 'Cronotas!' 'Tiene Notas Pendientes Para Hoy...'");
          }else{
             tray_icon.set_from_file(fconfig.ruta+"gnote-panel.png");
             tray_icon.set_tooltip_text("Cronotas 0.2 - Sin Notas Pendientes");
          }        
      }
      public void init_trabajo(){ 
         Statement stmt2;
         var now = new DateTime.now_local ();
         string errmsg;
         string mi_fecha = formatT(now.get_day_of_month())+"/"+formatT(now.get_month())+"/"+now.get_year().to_string();
         string query2 = "SELECT count(*) from jornada where fecha='"+mi_fecha+"';";
	      rc=db.prepare_v2(query2,-1,out stmt2);
         stmt2.step();
         num_jornada=int.parse(stmt2.column_text(0));
         if (num_jornada==0){
            query2 = "INSERT INTO jornada (id, fecha, hx,mx,horas,mes,ano) values("+(count_jornadas()+1).to_string()+
                     ",'"+mi_fecha+"',0,0,'00:00 Ht','"+formatT(now.get_month())+"','"+now.get_year().to_string()+"');";
    	      rc = db.exec (query2, null, out errmsg);
            if (rc != Sqlite.OK) stderr.printf ("Error: %s\n", errmsg); 
         }
         else{
               query2 = "SELECT * from jornada where fecha='"+mi_fecha+"';";
         	   db.prepare_v2(query2,-1,out stmt2);
               stmt2.step();
               min_trabajo = int.parse(stmt2.column_text(3));         
               hour_trabajo =int.parse(stmt2.column_text(2));         
         }
      }
      public void create_menu_system() {
   		menu_system = new Gtk.Menu();
         var menu_nueva = new ImageMenuItem.from_stock(Stock.NEW, null);
   		menu_nueva.activate.connect(()=>{separar = new tab(crear_ficha());});
   		menu_system.append(menu_nueva);
         var menu_tempo = new Gtk.MenuItem.with_label ("Temporizador");
   		menu_tempo.activate.connect(()=>{temporizador = new tempo();});
   		menu_system.append(menu_tempo);
         var separator1 = new Gtk.SeparatorMenuItem();
   		menu_system.append(separator1);
         menu_trabajo = new Gtk.MenuItem.with_label ("Iniciar Trabajo");
   		menu_trabajo.activate.connect(time_trabajo_play);
   		menu_system.append(menu_trabajo);
         var menu_jornada = new Gtk.MenuItem.with_label ("Reporte de Jornadas");
   		menu_jornada.activate.connect(()=>{jornadas = new dialog_jornada();});
   		menu_system.append(menu_jornada);
         var menu_config = new Gtk.MenuItem.with_label ("Configuración");
   		menu_config.activate.connect(()=>{dialog_config = new config();});
   		menu_system.append(menu_config);
         var separator2 = new Gtk.SeparatorMenuItem();
   		menu_system.append(separator2);
   		var menu_about = new ImageMenuItem.from_stock(Stock.ABOUT, null);
   		menu_about.activate.connect(about_clicked);
   		menu_system.append(menu_about);
   		var menu_quit = new ImageMenuItem.from_stock(Stock.QUIT, null);
   		menu_quit.activate.connect(Gtk.main_quit);
   		menu_system.append(menu_quit);
   		menu_system.show_all();
      }
      private void about_clicked() {
   		var about = new Gtk.AboutDialog();
         about.set_logo(new Gdk.Pixbuf.from_file(fconfig.ruta+"notes-app.png"));
   		about.website = "http://www.didapax.com.ve";
         about.website_label = "Didapax Sistem";
   		about.set_version("0.2.1");
   		about.set_program_name("Cronotas");
   		about.set_comments("Cronometros y Notas al mismo Tiempo");
   		about.set_copyright("Daniel Alfonsi -Didapax- (c)2018 ");
   		about.run();
   		about.hide();
      }
      public static int main(string[] args){
         Gtk.init (ref args);
         var app = new cronotas();
         Gtk.main ();
         return 0;
      }
     public void aplicar_color(string color){
   		var screen = Gdk.Screen.get_default();	
   		var css_provider = new CssProvider();
   		css_provider.load_from_path(fconfig.ruta+color+".css");
   		var style_context = this.get_style_context();		
   		style_context.add_provider_for_screen(screen, css_provider, STYLE_PROVIDER_PRIORITY_USER);
      }
   }
}
