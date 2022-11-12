#include <iostream>
#include <cstdlib>
using namespace std;

void jugada(int jugada[], int n_jugador, int num_jugada);

void tirarDados(int& vDado);
int tiradaDados[5];



// MAIN 
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
    // seguido de eso se muestran 
    
    



    // Seed y variable para la funcion rand
    srand(time(NULL));
    int valorDado;


    // tiradaDados es el array modificado que queda para usar en la proxima funcion.
    tirarDados(valorDado);

   

   










  
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



/*


3. Crear una función denominada “int tirar(int juego[])” que SIMULE una tirada de datos de forma aleatoria 
y retorne como parámetro un vector con los 5 resultados y en el nombre de la función un entero que indique 
si el resultado obtenido de los datos fue en 1,2 o 3 tiros. 
*/

void tirarDados(int& vDado)
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
    }



/*

4. Crear una función denominada “jugar” que evalúe el resultado de acuerdo a la jugada realizada (tirar), 
del jugador que corresponda y cargue la matriz. \ 
Jugar deberá evaluar los juegos (escalera,full,poker,generala) para asignar puntos y 
de no haber juegos aplicar lógica para seleccionar el valor de los números, 
por ejemplo si son todos distintos tomar el menor y 
si hay dos  iguales anotar la suma siempre que la casilla no haya sido ocupada con algún resultado previo 
*/




void jugada(int jugada[], int n_jugador, int num_jugada)
{
    int a,j;
    int ph;

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
    for(j=0;j<5;j++){ cout<< " " << jugada[j] << " ";}
    //Hay tres posibilidades: 1-2-3-4-5 (escalera menor), 2-3-4-5-6 (escalera mayor) o 3-4-5-6-1
    // 65321
    //12356
   
    a=0;
    int cont1 = 0;
    int cont2 = 0;
    if(jugada[a] == jugada[a+1]== jugada[a+2] == jugada[a+3]== jugada[a+4])
    {
        cout << "Generala! " << endl;
        if(num_jugada==1) {

        cout << " y servida!" << endl;
        cout << "Jugador " << n_jugador << " gana el juego! " << endl;
        return ;
        }
    }
    else
    {
        for(a=1;a<5;a++)
        {
            if(jugada[a] == jugada[a-1]) {cont1++;}
        }   
        //1,2222 poker 3
        //1111,2 poker 3
        //111,22 full 3 
        //11,222 full 3
        if((cont1=3) && ((jugada[0]== jugada[3]) || (jugada[1]==jugada[4])))
        {
            cout<<"Es poker" << endl;
            return;
        }
        /*else // debo de definir mejor esto por que termina aca y nada que ver xd
        {
            cout<<"Es full" << endl;
            return;
        }
         if((jugada[0]<jugada[1]<jugada[2]<jugada[3]<jugada[4]) || ((jugada[0]==1) && (jugada[4]>jugada[3]>jugada[2]>jugada[1])))
    {
        cout << "Es escalera" << endl;
        return;
    }
*/



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