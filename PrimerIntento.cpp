#include <iostream>
#include <cstdlib>
using namespace std;

void jugada(int jugada[], int n_jugador, int num_jugada);
int tirarDados(int& vDado, int& nTirada);
int tiradaDados[5];

//-------------- -------------- ------- MAIN ------- --------- ------ 
int main() {
    

    cout << "Bienvenido al juego de la Generala" << endl << endl;
    int n;
    cout << "Ingrese cantidad de jugadores(3-5)" << endl;
    cin >> n;
    n+=1;
    int tabla[12][n];
    int i, j;
    // El siguiente ciclo crea la tabla con las categorias a la izquierda 
    //y los numeros de jugadores en la cima de las columnas
    // Deja el lugar i=0j=0 vacio
    for(i=0;i<12;i++)
    {
        for(j=0;j<n;j++)
        {
            tabla[i][j] = 0;
            if(i==0){tabla[i][j] = j;}
        }
        if(i>0){tabla[i][0] = i;}
    }
    // De aqui en adelante deberia decirle a los jugadores,  toma es tu turno. 
    // En tu turno te digo , te quedan 3 tiradas , , Apreta 1 para hacer la tirada
    // luego se muestran los resultados de la tirada
    // seguido de eso se muestran las posibles combinacinoes que puede hacer con esa tirada. 
    // aca le pregunto, deseas hacer uso de alguna de estas combinaciones?  o deseas volver a tirar? 
    // Si elige tirar repito lo anterior hasta que no le queden mas tiradas
    // si elige hacer uso de las combinaciones, le resto la cantidad de tiradas que le quedaban
    // y le muestro el menu de nuevo de las que tenia disponibles. 
    // cuando elija la opcion le sumo los puntos correspondientes  y paso al proximo jugador. 
    
    



    // Seed y variable para la funcion rand
    srand(time(NULL));
    int valorDado;
    int nTirada= 0;
    // la nTirada deberia resetearse a 0 cada vez que sea el turno de otro jugador. 
    // utilizara el valor en esa variable para computar si es servida o no la jugada de escalera, poker, full o generala.
    // tiradaDados es el array modificado que queda para usar en la proxima funcion.
    nTirada = tirarDados(valorDado, nTirada);

    // debo diseñar aqui el menu.



  
    jugada(tiradaDados,1,2);
    cout << endl;
    cout << endl;






    // El siguiente ciclo muestra la tabla. 
    for(i=0;i<12;i++)
    {
        for(j=0;j<n;j++)
        {
            cout << tabla[i][j] << " ";
        }
    cout << endl;
    }
    cout << endl << endl;
    int m1=0,m2=0,m3=0,m4=0,m5=0; 
    // el siguiente ciclo suma los puntos en la tabla // los tachados son -1 y no los suma
    for(j=1;j<n;j++)
    {
        for(i=1;i<12;i++)
        {
            if((j==1) && (tabla[i][j]>0)){m1+= tabla[i][j];}
            if((j==2) && (tabla[i][j]>0)){m2+= tabla[i][j];}
            if((j==3) && (tabla[i][j]>0)){m3+= tabla[i][j];}
            if((j==4) && (tabla[i][j]>0)){m4+= tabla[i][j];}
            if((j==5) && (tabla[i][j]>0)){m5+= tabla[i][j];}
        }
    }
    int listaMejores[5]={m1,m2,m3,m4,m5};
    int ganador=0, posicion;
    // El siguiente ciclo determina el ganador por busqueda de maximo.
    for(i=0;i<5;i++)
    {
        if(i==0 || listaMejores[i]> ganador)
        {   
            ganador = listaMejores[i];
            posicion = i+1;
        }
    }
    cout << "El ganador fue el jugador N° " << posicion << " con " << ganador << " puntos" << endl;
    return 0;
}
// ---    ----   ----  ----  ---- FIN DEL MAIN --- ---- ---- ---- ------ ----------




int tirarDados(int& vDado , int& nTirada)
    {
        int i;
        for(i=0;i<5;i++)
        {
            vDado =  1 + rand() % 6;
            tiradaDados[i] = vDado;
        }
        int h; 
        cout << "La tirada es la siguiente: " << endl;
        for(h=0;h<5;h++)
        {
            cout << " " << tiradaDados[h] << " ";
        }
    cout << endl;
    return nTirada+1;
    }



/*

4. Crear una función denominada “jugar” que evalúe el resultado de acuerdo a la jugada realizada (tirar), 
del jugador que corresponda y cargue la matriz. \ 
Jugar deberá evaluar los juegos (escalera,full,poker,generala) para asignar puntos 


y 
de no haber juegos aplicar lógica para seleccionar el valor de los números, 
por ejemplo si son todos distintos tomar el menor y 
si hay dos  iguales anotar la suma siempre que la casilla no haya sido ocupada con algún resultado previo 
*/




void jugada(int jugada[], int n_jugador, int num_jugada)
{
    int a,j;
    int ph,puntos;
    // El siguiente ciclo ordena la jugada de menor a mayor
    for(a=0;a<5;a++)
    {
        for(j=1;j<5;j++)
        {
            if(jugada[j-1] > jugada[j])
            {
                ph = jugada[j-1];
                jugada[j-1] = jugada[j];
                jugada[j] = ph;
            }

        }
    }
    
    // podria setear tantas variables como categorias, y en el caso en qeu se cumpla la condiciones sumarle los puntos.
   // si no van a tener un menos uno, y directamente se lo asigno a esa categoria. 
   // eso para cerrar la categoria
   // le voy a poner el -1 de comienzo, y sumarle uno luego para tomarlo en cuenta. 
   // de esa forma voy a tener una forma de saber si esta cerrado. 
   // no para
   // tengo que decidir como voy a decidir si lo puedo sumar a la matriz. 
   // al momento
    
    int uno=0, dos=0, tres=0, cuatro=0, cinco=0, seis=0;
    for(a=0;a<5;a++)
    {
        if(jugada[a]==1){uno++;}
        if(jugada[a]==2){dos++;}
        if(jugada[a]==3){tres++;}
        if(jugada[a]==4){cuatro++;}
        if(jugada[a]==5){cinco++;}
        if(jugada[a]==6){seis++;}
    }
    cout << "Puedes anotar " << uno << "al 1 " << endl;
    cout << "Puedes anotar " << dos << "al 2" << endl;
    cout << "Puedes anotar " << tres << "al 3 " << endl;
    cout << "Puedes anotar " << cuatro << "al 4 " << endl;
    cout << "Puedes anotar " << cinco << "al 5 " << endl;
    cout << "Puedes anotar " << seis << "al 6 " << endl;
    //generala - me falta agregar la posibilidad de generala doble. * TAMB ME FALTA AGREGAR QUE AGREGUE LOS PUNTOS A LA MATRIZ 
    // Y me falta la logica de que decida a donde anotar. 
    if(jugada[0] == jugada[1]== jugada[2] == jugada[3]== jugada[4])
    {
        cout << "Generala!";
        
        if(num_jugada==1)
        {
            cout << " y servida!" << endl;
            cout << "Jugador N° " << n_jugador << " gana el juego! " << endl;
            puntos = 10000;
            return;
        }
        cout << " son 100 puntos" << endl;
        puntos = 100;
        return;
    }
    // escalera
    else if(((jugada[0]==1)&(jugada[1]==2)&(jugada[2]==3)&(jugada[3]==4)&(jugada[4]==5)) ||((jugada[0]==2)&(jugada[1]==3)&(jugada[2]==4)&(jugada[3]==5)&(jugada[4]==6)) ||((jugada[0]==1)&(jugada[1]==3)&(jugada[2]==4)&(jugada[3]==5)&(jugada[4]==6)))
    {   
        cout << "Es escalera ";
        if(num_jugada==1)
        {
            cout << " y servida! son 25 puntos" << endl;
            puntos = 25;
            return;
        }
        else
        {
            cout << " son 20 puntos " << endl;
            puntos = 20;
            return;
        }
    }
    // poker, solo si 1,2222 o , 1111,2
    else if((jugada[0]==jugada[3])|| (jugada[1]==jugada[4]))
    {
        cout << "Es poker ";
        if(num_jugada==1)
        {
            cout << " y servido! son 45 puntos" << endl;
            puntos = 45;
            return;
        }
        else
        {
            cout << " son 40 puntos " << endl;
            puntos = 40;
            return;
        }
        }
    //full, solo si 111,22 o , 11,222
    else if((jugada[0]==jugada[2])|| (jugada[2]==jugada[4]))
    {
        cout << "Es full ";
        if(num_jugada==1)
        {
            cout << " y servido! son 35 puntos" << endl;
            puntos = 35;
            return;
        }
        else
        {
            cout << " son 30 puntos " << endl;
            puntos = 30;
            return;
        }
    }

    
    
    


}









  




















/*

7. Los datos se deben ir guardando en un archivo de registros con el siguiente formato: 
    * Id de jugada (un número por jugada, para lo cual tienen que buscar el último ingresado) 
    * Nombre del jugador 
    * Fecha (AAAAMMDD) 
    * Puntaje 
8. Por último hacer un ranking de los 3 mejores cargando los datos del archivo en una lista ordenada. 

*/