/*
Cronotas (c) Didapax Sistem Daniel Alfonsi 
2019
*/
using Gtk;
using Sqlite;
using crono;

namespace crono{
   struct f_notas{
      string id;
      string fecha;
      string nombre;
      string nota;
      int proteger;
      int completar;
      string color;
      bool visible;
   }
   struct f_config{
      string id;
      string ruta;
      string color;
   }
   f_config fconfig;
   f_notas ficha[100];
   int max_nota;
   int rc;
   Database db;
   Database db_config;
   Statement stmt;
   Statement stmt_config;   
   public void init_datos(){
      create_config();
      create_tables();
      llenarFichas();
   }
   public void create_tables(){
      string errmsg;
      rc = Database.open (fconfig.ruta+"notas.db", out db);
      string query = """CREATE TABLE IF NOT EXISTS nota (id INT PRIMARY KEY NOT NULL,fecha DATE,nombre TEXT,nota TEXT,proteger INT,completar INT,color TEXT, pcolor TEXT);""";
	   rc = db.exec (query, null, out errmsg);
      query = """CREATE TABLE IF NOT EXISTS jornada (id INT PRIMARY KEY NOT NULL,fecha DATE,hx INT,mx INT,horas TEXT,mes TEXT,ano TEXT);""";
	   rc = db.exec (query, null, out errmsg);
      query = """SELECT count(*) from nota;""";
	   db.prepare_v2(query,-1,out stmt);
      stmt.step();
      max_nota=int.parse(stmt.column_text(0));
      if (rc != Sqlite.OK) stderr.printf ("Error: %s\n", errmsg);
      else if (max_nota==0){
            print("No hay datos\n");
            query = "INSERT INTO nota (id,fecha,nombre,nota,proteger,completar,color) values("+(max_nota+1).to_string()+
                    ",'00/00/0000','Nota"+(max_nota+1).to_string()+"','',0,0,'amarillo.css');";
      	   rc = db.exec (query, null, out errmsg);
            if(rc==Sqlite.OK) max_nota++; else print("Error: %s",errmsg);
         }
   }
   public void create_config(){
      string errmsg;
      Statement stmt_config;
      rc = Database.open (Environment.get_home_dir()+"/.cronotas/config.db", out db_config);
      string query = """CREATE TABLE IF NOT EXISTS config (id INT PRIMARY KEY NOT NULL,ruta TEXT, color TEXT);""";
	   rc = db_config.exec (query, null, out errmsg);
      if (!if_config()){
          query = "INSERT INTO config (id,ruta,color) values(0,'"+Environment.get_home_dir()+"/.cronotas/','amarillo');";
      	 rc = db_config.exec (query, null, out errmsg);
          if(rc!=Sqlite.OK) print("Error: %s\n",errmsg);
      }
      query = "SELECT * from config;";
	   rc=db_config.prepare_v2(query,-1,out stmt_config);
      stmt_config.step();
      fconfig.id= stmt_config.column_text(0);
      fconfig.ruta = stmt_config.column_text(1);
      fconfig.color = stmt_config.column_text(2);      
   }
   public bool if_config(){
      Statement stmt_config;
      string query = "SELECT COUNT(*)  from config;";
	   rc=db_config.prepare_v2(query,-1,out stmt_config);
      stmt_config.step();
      if (int.parse(stmt_config.column_text(0))>0) return true; else return false;        
   }
   public void llenarFichas(){      
      string query = """select * from nota order by fecha desc;""";
	   db.prepare_v2(query,-1,out stmt);
      for (int i=1; i<=max_nota; i++){
         stmt.step();
         ficha[i].id = stmt.column_text(0);
         ficha[i].fecha = stmt.column_text(1);
         ficha[i].nombre = stmt.column_text(2);
         ficha[i].nota = stmt.column_text(3);
         ficha[i].proteger = stmt.column_int(4);
         ficha[i].completar = stmt.column_int(5);      
         ficha[i].color = stmt.column_text(6);      
         ficha[i].visible=true;
      }
   }
   public string formatT(int valor){
      string s_valor="00";
      if (valor <10) s_valor = "0"+valor.to_string();
      else s_valor = valor.to_string();
      return s_valor;
   }
   public int max_id(){
      Statement stmt;
      string query = "SELECT MAX(id) from nota;";
	   rc=db.prepare_v2(query,-1,out stmt);
      stmt.step();      
      return stmt.column_int(0);
   }
   public int crear_ficha(){
      string errmsg;
      max_nota++; //posicion de la memoria en la ficha
      int new_nota = max_id()+1;
      string query = "INSERT INTO nota (id,fecha,nombre,nota,proteger,completar,color) values("+new_nota.to_string()+",'00/00/0000','Nota"+new_nota.to_string()+
                     "','',0,0,'amarillo');";
      rc = db.exec (query, null, out errmsg);
      ficha[max_nota].id = new_nota.to_string();
      ficha[max_nota].fecha = "00/00/0000";
      ficha[max_nota].nombre = "Nota" + new_nota.to_string();
      ficha[max_nota].nota = "";
      ficha[max_nota].proteger = 0;
      ficha[max_nota].completar = 0;
      ficha[max_nota].color="amarillo";
      if(rc!=Sqlite.OK) print("Error: %s\n",errmsg);
      return max_nota;
   }
   public void guardar(string nombre,string nota,string color, string id){
      string errmsg;
      string query = "UPDATE nota SET nombre ='"+nombre+"' ,nota='"+nota+
                     "', color='"+color+"'WHERE id="+id+";";
      int rc = db.exec (query, null, out errmsg);
      if(rc!=Sqlite.OK) print("Error: %s\n",errmsg);
   }
   public int count_jornadas(){
      Statement stmt2;
      string query2 = "SELECT count(*) from jornada;";
	   rc=db.prepare_v2(query2,-1,out stmt2);
      stmt2.step();
      return int.parse(stmt2.column_text(0));
   }
   public void guarda_trabajo(int hx, int mx, string lcd){ 
      var now = new DateTime.now_local ();
      string mi_fecha = formatT(now.get_day_of_month())+"/"+formatT(now.get_month())+"/"+now.get_year().to_string();
      string errmsg;
      string query2 = "UPDATE jornada SET hx="+hx.to_string()+",mx= "+mx.to_string()+",horas='"+lcd+"' WHERE fecha='"+mi_fecha+"';";
      rc = db.exec (query2, null, out errmsg);
      if(rc!=Sqlite.OK)
         print("Error: %s\n",errmsg);
   }
   public bool if_tareas_hoy(int id){ 
      Statement stmt_tareas;
      var now = new DateTime.now_local ();
      string mi_fecha = formatT(now.get_day_of_month())+"/"+formatT(now.get_month())+"/"+now.get_year().to_string();
      string query = "SELECT COUNT(*)  from nota where fecha='"+mi_fecha+"' and id="+id.to_string()+";";
	   rc=db.prepare_v2(query,-1,out stmt_tareas);
      stmt_tareas.step();
      if (int.parse(stmt_tareas.column_text(0))>0) return true; else return false;      
   }
   public bool now_tareas(){ 
      Statement stmt_tareas;
      var now = new DateTime.now_local ();
      string mi_fecha = formatT(now.get_day_of_month())+"/"+formatT(now.get_month())+"/"+now.get_year().to_string();
      string query = "SELECT COUNT(*)  from nota where fecha='"+mi_fecha+"';";
	   rc=db.prepare_v2(query,-1,out stmt_tareas);
      stmt_tareas.step();
      if (int.parse(stmt_tareas.column_text(0))>0) return true; else return false;      
   }   
}
