Guía de compilación - Blackjack en consola (C++)
Archivos del proyecto
Carpeta src/ con los archivos .cpp y .h del juego: main.cpp, Carta, Mano, Mazo, Jugador, Crupier y Juego.
Carpeta docs/ con compilacion.md, uml.pdf, juego.md y documento-formal.pdf.
Archivo README.md en la raíz del repositorio.
Requisitos
Windows con Visual Studio instalado (con la opción Desarrollo de escritorio con C++).
O tener instalado el compilador cl desde el Símbolo del sistema para desarrolladores de Visual Studio.
No se necesita ninguna librería externa, solo la librería estándar de C++.
Guía 1: Compilación con cl (línea de comandos)
Abre el Símbolo del sistema para desarrolladores de Visual Studio. Está en el menú Inicio, carpeta Visual Studio.
Ve a la carpeta del proyecto con el comando cd. Ejemplo: cd C:\Users\TuUsuario\Desktop\ProyectoProgracion-I
Ve a la carpeta src: cd src
Compila todos los archivos .cpp con este comando:
cl /EHsc /std:c++17 *.cpp
Si no hay errores, se crea el archivo main.exe.
Para jugar, escribe en la misma ventana: main.exe y presiona Enter.
Si aparece un error, revisa que estés en la carpeta src y que todos los .h y .cpp estén en esa misma carpeta.
Error común: si dice que cl no se reconoce, es porque no abriste el Símbolo del sistema para desarrolladores, sino el cmd normal. Ciérralo y abre el correcto.
Guía 2: Compilación con Visual Studio
Abre Visual Studio.
Crea un proyecto nuevo: Archivo > Nuevo > Proyecto > Aplicación de consola en C++.
Ponle un nombre al proyecto, por ejemplo Blackjack, y elige dónde guardarlo.
En el Explorador de soluciones, borra el archivo de ejemplo que viene por defecto.
Agrega los archivos del proyecto: clic derecho en el proyecto > Agregar > Elemento existente.
Selecciona todos los archivos .cpp y .h de la carpeta src y agrégalos.
Verifica que en el Explorador de soluciones aparezcan todos: main.cpp, Carta.h, Carta.cpp, Mano.h, Mano.cpp, Mazo.h, Mazo.cpp, Jugador.h, Jugador.cpp, Crupier.h, Crupier.cpp, Juego.h y Juego.cpp.
Compila con Ctrl + Shift + B o con el menú Compilar > Compilar solución.
Si sale 0 errores en la parte de abajo, la compilación fue correcta.
Para jugar, presiona Ctrl + F5 o el botón Ejecutar sin depurar. Se abre la consola del juego.
Si sale un error, haz doble clic en el error en la lista de errores para ver en qué archivo y línea está.
Cómo verificar que quedó bien
El juego debe abrir sin cerrar la consola de inmediato.
Debe mostrar el saldo inicial 1000 y pedir una apuesta entre 10 y 500.
Debe repartir 2 cartas para el jugador y 2 para el crupier.
Debe permitir pedir, plantarse, doblar, dividir y seguro cuando corresponde.
