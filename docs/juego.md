Guía de cómo jugar Blackjack en consola (C++) - Paso a paso
Objetivo del juego
El objetivo es sumar 21 puntos, o quedar lo más cerca posible sin pasarse, y ganarle al crupier.
Si te pasas de 21, pierdes la mano aunque el crupier también se pase después.
Si el crupier se pasa de 21 y tú no, tú ganas.

Antes de empezar
Compila y ejecuta el juego en consola.
El juego empieza con un saldo inicial de 1000.
Se usa un zapato con 6 barajas, en total 312 cartas.
En cada ronda debes apostar antes de que se repartan las cartas.
Paso 1: Apostar
El juego te muestra tu saldo actual.
Escribe tu apuesta. Debe ser entre 10 y 500.
Si escribes menos de 10 o más de 500, el juego te lo vuelve a pedir.
La apuesta se resta de tu saldo al iniciar la ronda y se paga al final según el resultado.
Paso 2: Reparto inicial
Se reparten 2 cartas para ti y 2 cartas para el crupier.
Tus 2 cartas se ven completas.
Del crupier solo se ve 1 carta, la otra queda oculta hasta el final.
Si tienes As + carta de 10 puntos (10, J, Q o K) en las 2 primeras cartas, tienes Blackjack natural y ganas 3 a 2.
Paso 3: Seguro (solo si el crupier muestra un As)
Si la carta visible del crupier es un As, el juego te pregunta si quieres seguro.
El seguro cuesta la mitad de tu apuesta.
Si el crupier tiene Blackjack, el seguro te devuelve lo apostado y no pierdes la apuesta principal completa.
Si el crupier no tiene Blackjack, pierdes el seguro y la mano sigue normal.
Si no quieres seguro, escribe que no y sigue la mano.
Paso 4: Tu turno - qué puedes hacer
En tu turno el juego te muestra tus cartas, tus puntos y las opciones. Puedes elegir:

Pedir carta (Hit): te dan otra carta. Puedes pedir las que quieras hasta plantarte o pasarte de 21.
Plantarte (Stand): te quedas con tus cartas y termina tu turno.
Doblar (Double): duplicas tu apuesta, recibes solo 1 carta más y tu turno termina. Solo conviene cuando tienes una mano fuerte, por ejemplo 10 u 11.
Dividir (Split): si tus 2 primeras cartas tienen el mismo valor, puedes dividirlas en 2 manos. Cada mano juega por separado con su propia apuesta.
Valor de las cartas
Cartas del 2 al 10 valen su número.
J, Q y K valen 10 puntos.
El As vale 11 puntos, pero si con 11 te pasas de 21, vale 1 punto. Ejemplo: As + 9 = 20, As + 9 + 5 = 15 porque el As pasa a valer 1.
Paso 5: Turno del crupier
Cuando terminas tu turno, el crupier muestra su carta oculta.
El crupier está obligado a pedir carta hasta llegar a 17 puntos o más.
Si el crupier tiene 16 o menos, pide carta.
Si el crupier tiene 17 o más, se planta.
Si el crupier se pasa de 21, tú ganas la mano.
Paso 6: Resultado de la ronda
Ganas 1 a 1 si tienes más puntos que el crupier sin pasarte de 21. Ejemplo: apuestas 100 y ganas, recibes 200 en total.
Blackjack natural: ganas 3 a 2. Ejemplo: apuestas 100 y sacas Blackjack, recibes 250 en total.
Empate: si tú y el crupier tienen los mismos puntos, es empate. Se te devuelve tu apuesta completa, no ganas ni pierdes.
Pierdes: si te pasas de 21 o el crupier tiene más puntos que tú sin pasarse.
Paso 7: Seguir jugando o salir
Al terminar la ronda el juego te muestra tu nuevo saldo.
Si tu saldo llega a 0 o no te alcanza para apostar 10, el juego termina.
Si todavía tienes saldo, puedes jugar otra ronda.
Para salir, elige la opción de salir cuando el juego te lo pregunte.
Ejemplo de una partida completa
Saldo: 1000. Apuestas 100. Saldo queda en 900.
Tus cartas: 10 + 8 = 18. Carta visible del crupier: 6.
Te plantas con 18.
El crupier muestra su carta oculta: 6 + 10 = 16, pide carta y saca 7 = 23. Se pasó.
Ganas. Te devuelven 200. Nuevo saldo: 1100.
