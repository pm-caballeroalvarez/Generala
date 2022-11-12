#include <iostream>
#include <cstdlib>
using namespace std;

void jugada(int jugada[], int n_jugador, int num_jugada);

void tirarDados(int& valorDado1);
int tiradaDados[5];
int main() {
    bool a=1;
    // Este bracket es para que demarque la creacion de la matriz. 
    // Esta tabla es para llevar las cuentas. 

    if(a){
    cout << "Tabla Matriz" << endl;
    int n;
    cout << "Ingrese cantidad de jugadores(3-5)" << endl;
    cin >> n;

    int tabla[13][n];

    int i, j;
    for(i=0;i<13;i++)
    {
        
        for(j=0;j<n;j++)
        {
            
            tabla[i][j] = 0;
        }
        if(i>0)
        {
            tabla[i][0] = i;
        }
    }
    for(i=0;i<13;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==0)
            {
                tabla[i][j] = j;
            }
            cout << tabla[i][j] << " ";
        }
        
    cout << endl;
    }
    }
    
    srand(time(NULL));
    int valorDado1, valorDado2;

    void tirarDados(int& valorDado1);
    {
        int i;
        
        for(i=0;i<5;i++)
        {
            valorDado1 =  1 + rand() % 6;
            tiradaDados[i] = valorDado1;

        }
    }

    int h; 
    cout << "Mostrando la tirada de dados random" << endl;
    for(h=0;h<5;h++)
    {
        cout << " " << tiradaDados[h] << " ";
    }

    cout << endl;

    //esto debajo es para probar la funcion jugada, aver si con valores de dados toma el camino correcto
    // Debo evaluar si las condiciones de los if de eso son correctas antes de sumarlos a la matriz.
    // Luego me encargare de la funcion para cargarlo en la matriz *Aca es dondedebo aplicar la logica de que el programa seleccione
    // O debo dar a elegir en cada jugada.
    // Seran programas muy distintos. 
    // 
    int v[5]={0};
    int i;
    cout << "Ingrese valores vector" << endl;
    for(i=0;i<5;i++){
        cin>> v[i];
    
    }
    jugada(v,1,2);




    return 0;
}



/*


3. Crear una función denominada “int tirar(int juego[])” que SIMULE una tirada de datos de forma aleatoria 
y retorne como parámetro un vector con los 5 resultados y en el nombre de la función un entero que indique 
si el resultado obtenido de los datos fue en 1,2 o 3 tiros. 




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
6. Al finalizar el juego (11 tiros para cada jugador que se deben realizar alternando) se deberá mostrar 
los resultados y determinar el ganador. 


















7. Los datos se deben ir guardando en un archivo de registros con el siguiente formato: 
    * Id de jugada (un número por jugada, para lo cual tienen que buscar el último ingresado) 
    * Nombre del jugador 
    * Fecha (AAAAMMDD) 
    * Puntaje 
8. Por último hacer un ranking de los 3 mejores cargando los datos del archivo en una lista ordenada. 







Tengo que hacer la funcion que haga la tirada
Luego la que la evalue y la cargue. 
*/