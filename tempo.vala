/*
Cronotas (c) Didapax Sistem Daniel Alfonsi 
2019
*/
using Gtk;
using crono;

namespace crono{
    class tempo: Gtk.Dialog {
      private Gtk.StatusIcon tray_icon1;
      private Gtk.Menu menu_system;
      private Builder builder;
      public Gtk.Dialog dialog; 
      private SpinButton escala;   
      private Button cro_play;
      private Label lminuto;
      uint time_crono;
      int second;
      int minute;
      int num_minute;
      bool state_crono;
      bool play=true;
      bool stop=false;
      
      public tempo(){
         second = 0;
         minute = 0;
         builder = new Builder();
         builder.add_from_file (fconfig.ruta+"tempo.ui");
         dialog = builder.get_object("tempo") as Gtk.Dialog;
         builder.connect_signals (null);
         escala = builder.get_object("escala") as SpinButton;
         escala.value_changed.connect(escala_change_value);
         cro_play = builder.get_object("cro_play") as Button;         
         cro_play.clicked.connect(croplay);
			lminuto = builder.get_object("lminutos") as Label;         
         dialog.show_all();
      }
      public void escala_change_value(){
			lminuto.label=escala.get_value().to_string();
		}
      public void croplay(){
         num_minute = (int)escala.get_value();
         minute=num_minute*60;
         second = 60;
         state_crono=play;
         time_crono=Timeout.add (1000,on_timer_event);
         tray_icon1 = new Gtk.StatusIcon.from_file(fconfig.ruta+"indicator1.png");
         tray_icon1.set_visible(true);
         create_menu_system();
         tray_icon1.popup_menu.connect(menu_system_popup);
         dialog.destroy();
      }
      void dialog_response (Gtk.Dialog dialog, int response_id) {
   		switch (response_id) {
   			case Gtk.ResponseType.OK:
               tray_icon1.set_visible(false);
  				break;
   		}
   			dialog.destroy();
   	}
      public bool on_timer_event () {
         if (state_crono ==play){
            second--;
            minute--;
            if (minute == (num_minute*60/2)) tray_icon1.set_from_file(fconfig.ruta+"indicator2.png");
            if (second == 0) second =60;
            tray_icon1.set_tooltip_text(formatT(minute/60)+":"+formatT(second));
            if(minute == 0){
               state_crono=stop;
               tray_icon1.set_from_file(fconfig.ruta+"indicator3.png");
               Process.spawn_command_line_async ("notify-send 'Temporizador.' 'Alarma!! Tiempo Completado...'");
               var messagedialog = new Gtk.MessageDialog (this, Gtk.DialogFlags.MODAL,Gtk.MessageType.INFO, Gtk.ButtonsType.OK,
                  "Tiempo Completado "+num_minute.to_string()+" Min..");                  
       	   	messagedialog.response.connect (dialog_response);
        	   	messagedialog.show ();
            }
         }
         return state_crono;
      }
      private void menu_system_popup(uint button, uint time) {
   		menu_system.popup(null, null, null, button, time);
      }
      public void create_menu_system() {
   		menu_system = new Gtk.Menu();
   		var menu_quit = new Gtk.MenuItem.with_label ("Detener Temporizador");
   		menu_quit.activate.connect(()=>{state_crono=stop;tray_icon1.set_visible(false);});
   		menu_system.append(menu_quit);
   		menu_system.show_all();
      }

   }
}

