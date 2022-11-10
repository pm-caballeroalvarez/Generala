

 # Generala
Proyecto Integrador de AYED UTN 2022

Consignas

Generala
La generala es un juego de dados. Se juega con cinco dados y un cubilete; 
el número de jugadores es ilimitado, pero lo ideal es de 3 a 5. El 
objetivo del juego es lograr la mayor puntuación, de acuerdo a la 
valoración establecida para cada jugada posible en el juego, llamada 
categoría. (*Wikipedia)
Categorías
Para calcular el puntaje correspondiente a una categoría de números del 1 
al 6, se deben sumar los números iguales. Por ejemplo, si un jugador, 
tirara tres dados con el número 6, se sumará, 6+6+6=18, este resultado se 
anotará en la casilla correspondiente al número 6. Si son tres 1 se debe 
anotar 3 al 1, si hay dos 6 se debe anotar 12 al 6.
• 1: se coloca el número que dé la suma de 1 obtenidos.
• 2: se coloca el número que dé la suma de 2 obtenidos.
• 3: se coloca el número que dé la suma de 3 obtenidos.
• 4: se coloca el número que dé la suma de 4 obtenidos.
• 5: se coloca el número que dé la suma de 5 obtenidos.
• 6: se coloca el número que dé la suma de 6 obtenidos.
• Escalera: 25 puntos si es servida, 20 si fue armada. Se forma con una
progresión de números. Hay tres posibilidades: 1-2-3-4-5 (escalera menor), 
2-3-
4-5-6 (escalera mayor) o 3-4-5-6-1
• Full: 35 puntos si es servido o 30 puntos si es armado. Se forma con dos 
grupos
de dados iguales, uno de tres y otro de dos dados.
• Póker: 45 puntos si es servido o 40 puntos si es armado. Se forma con 
cuatro dados iguales.
• Generala: 50 puntos si se logra formar cinco números iguales en dos o 
tres tiros.
• Generala Doble: 100 puntos si se logra formar una segunda generala 
existiendo la primera en dos o tres tiros.
• Generala Servida: Cuando se logra la Generala de un solo tiro, se llama 
generala servida y en cualquier tiro se gana la partida.
Una vez lograda una categoría esta se considera "Cerrada", es decir, si el 
jugador la repite no la podrá usar, de tal forma que tendrá que buscar 
otra posible categoría con la combinación de dados obtenida. Por ejemplo, 
si el jugador tira 4-4-2-2-2, si ya había anotado el full, puede anotar la 
tirada en la categoría del 4 o del 2.




Realizar:
Un programa que simule el juego de generala, entre 3 y 5 jugadores. Para 
ello se deberá:
1) Solicitar al usuario que ingrese la cantidad de jugadores

2) Crear una matriz de acuerdo a esa cantidad para poder almacenar el 
resultado de cada jugada para cada jugador, ejemplo

3) Crear una función denominada “int tirar(int juego[])” que SIMULE una 
tirada de datos de forma aleatoria y retorne como parámetro un vector con 
los 5 resultados y en el nombre de la función un entero que indique si el 
resultado obtenido de los datos fue en 1,2 o 3 tiros.
4) Crear una función denominada “jugar” que evalúe el resultado de acuerdo 
a la jugada realizada (tirar), del jugador que corresponda y cargue la 
matriz.
5) Jugar deberá evaluar los juegos (escalera,full,poker,generala) para 
asignar puntos y de no haber juegos aplicar lógica para seleccionar el 
valor de los números, por ejemplo si son todos distintos tomar el menor y 
si hay dos iguales anotar la suma siempre que la casilla no haya sido 
ocupada con algún resultado previo.
6) Al finalizar el juego (11 tiros para cada jugador que se deben realizar 
alternando) se deberá mostrar los resultados y determinar el ganador.
7) Los datos se deben ir guardando en un archivo de registros con el 
siguiente formato:
a. Id de jugada (un número por jugada, para lo cual tienen que buscar el 
último
ingresado)
b. Nombre del jugador
c. Fecha (AAAAMMDD)
d. Puntaje
8) Por último hacer un ranking de los 3 mejores cargando los datos del 
archivo en una lista ordenada.
