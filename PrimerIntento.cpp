#include <iostream>
#include <cstdlib>
using namespace std;

void jugada(int jugada[], int n_jugador, int num_jugada);



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
int valorDado1, valorDado2, sumad1d2;
void tirar2Dados(int& valorDado1, int& valorDado2, int& sumad1d2);
{
    valorDado1 =  1 + rand() % 6;
    valorDado2 =  1 + rand() % 6;
    sumad1d2 = valorDado1 + valorDado2;
}


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
    int jugada[5]={0};
    for(a=0;a<5;a++)
    {
        for(j=1;j<=5;j++)
        {
            if(jugada[j-1] > jugada[j])
            {
                ph = jugada[j-1];
                jugada[j-1] = jugada[j];
                jugada[j] = ph;
            }

        }
    }
    //Hay tres posibilidades: 1-2-3-4-5 (escalera menor), 2-3-4-5-6 (escalera mayor) o 3-4-5-6-1
    // 65321
    //12356
    if((jugada[4]>jugada[3]>jugada[2]>jugada[1]>jugada[0]) || ((jugada[0]==1) && (jugada[4]>jugada[3]>jugada[2]>jugada[1])))
    {
        cout << "Es escalera" << endl;
        return;
    }
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
        else
        {
            cout<<"Es full" << endl;
            return;
        }




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


*/