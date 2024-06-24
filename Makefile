OS = LINUX
PKGS = \
    --pkg gtk+-3.0 \
    --pkg sqlite3 
FLAGS = -v -g --save-temps --vapidir=vapi --enable-checking --enable-gobject-tracing 
FILES = \
    cronotas.vala\
    database.vala\
    tab.vala\
    jornada.vala\
    config.vala\
    tempo.vala

#ruta de instalacion
RUTA := $$HOME/.cronotas

#desktop
DESK:= [Desktop Entry]
VERSION:= Version=1.0
TYPE:= Type=Application
NAME:= Name=Cronotas 0.2
COMM:= Comment=cronometro y notas
CEXEC:= $(RUTA)/cronotas
CICON:= $(RUTA)/notes-app.png
CPATH:= $(RUTA)
TERMINAL:= Terminal=false
START:= StartupNotify=false
CNAME:= Name[es_VE]=Cronotas 0.2.0

ifeq ($(OS),WIN32)
	LIBS = \
       -X -LC:\Windows\System32 \
       -X -LC:\vala-0.12.0\lib \
       -X "C:\Program Files\Microsoft SDKs\Windows\v7.0A\Lib\OpenGL32.lib" \
       -X -IC:\cygwin\usr\include\w32api \
       -X -IC:\vala-0.12.0\include\SDL \
       -X -lgsl \
       -X -lgdk-3\
       -X -lmingw32
 endif

all: $(FILES)
	valac $(FLAGS) $(PKGS) -o cronotas $(FILES)

clean:
	find . -type f -name "*.so" -exec rm -f {} \;
	find . -type f -name "*.a" -exec rm -f {} \;
	find . -type f -name "*.o" -exec rm -f {} \;
	find . -type f -name "*.h" -exec rm -f {} \;
	find . -type f -name "*.c" -exec rm -f {} \;
	find . -type f -name "*.vala~" -exec rm -f {} \;
	#rm cronotas

install:
	mkdir $(RUTA)
	cp *.ui $(RUTA)
	cp *.png $(RUTA)
	cp *.css $(RUTA)
	cp cronotas $(RUTA)
	printf '$(DESK)\n$(VERSION)\n$(TYPE)\n$(NAME)\n$(COMM)\nExec='$(CEXEC)'\nIcon='$(CICON)'\nPath='$(CPATH)'\n$(TERMINAL)\n$(START)\n$(CNAME)' > $(RUTA)/cronotas.desktop
	cp $(RUTA)/cronotas.desktop $$HOME/Escritorio

