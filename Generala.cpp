#include <iostream>
#include <cstdlib>
using namespace std;

void jugada(int jugada[], int n_jugador, int num_jugada, int matriz[][12]);
int tirarDados(int& vDado, int& nTirada);
int tiradaDados[5];

int main() {

    cout << "Bienvenido al juego de la Generala" << endl << endl;
    int n;
    cout << "Ingrese cantidad de jugadores(3-5)" << endl;
    cin >> n;
    n+=1;
    int tabla[n][12];
    int i, j;
    // El siguiente ciclo crea la tabla con las categorias en columnas 
    //y los numeros de jugadores en la izquierda , para poder pasar la matriz como parametro en la funcion jugada
    // Deja el lugar i=0j=0 vacio 
    for(i=0;i<n;i++)
    {
        for(j=0;j<12;j++)
        {
            tabla[i][j] = 0;
            if(i==0){tabla[i][j] = j;}
        }
        if(i>0){tabla[i][0] = i;}
    }
    // Seed y variable para la funcion rand
    srand(time(NULL));
    int valorDado;
    int nTirada= 0;
   

    int k;
    for(k=0;k<11;k++)
    {
        for(i=1;i<=n-1;i++)
        {
        nTirada=0;
        cout << "Turno del jugador N° " << i << endl;
        for(j=1;j<=3;j++)
        {
        nTirada = tirarDados(valorDado, nTirada);
        jugada(tiradaDados,i,nTirada, tabla);
        }

        if(tabla[i][11]>1000){break;}
        }
        if(tabla[i][11]>1000){break;}
    }

    // El siguiente ciclo muestra la tabla.  

    cout <<endl;
    cout << "La tabla de resultados es la siguiente " << endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<12;j++)
        {
            cout << tabla[i][j] << " ";
        }
    cout << endl;
    }
    cout << endl << endl;
    int m1=0,m2=0,m3=0,m4=0,m5=0; 
    // el siguiente ciclo suma los puntos en la tabla // los tachados son -1 y no los suma
    for(i=1;i<n;i++)
    {
        for(j=1;j<12;j++)
        {
            if((i==1) && (tabla[i][j]>0)){m1+= tabla[i][j];}
            if((i==2) && (tabla[i][j]>0)){m2+= tabla[i][j];}
            if((i==3) && (tabla[i][j]>0)){m3+= tabla[i][j];}
            if((i==4) && (tabla[i][j]>0)){m4+= tabla[i][j];}
            if((i==5) && (tabla[i][j]>0)){m5+= tabla[i][j];}
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

int tirarDados(int& vDado , int& nTirada)
    {
        int i;
        for(i=0;i<5;i++)
        {
            vDado =  1 + rand() % 6;
            tiradaDados[i] = vDado;
        }
        int a,j;
        int ph;
    // El siguiente ciclo ordena la jugada de menor a mayor
        for(a=0;a<5;a++)
        {
            for(j=1;j<5;j++)
        {
            if(tiradaDados[j-1] > tiradaDados[j])
            {
                ph = tiradaDados[j-1];
                tiradaDados[j-1] = tiradaDados[j];
                tiradaDados[j] = ph;
            }

        }
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

// matriz[n_jugador][categoria] = -1; para tachar la categoria

void jugada(int jugada[], int n_jugador, int num_jugada, int matriz[][12])
{
    cout << "Evaluando... " << endl;
    int a,j;
    int ph;
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
    

    // El ciclo siguiente suma los numeros iguales
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
    int flag=0;
    // Generala, servida, simple y doble
    if(jugada[0] == jugada[1]== jugada[2] == jugada[3]== jugada[4])
    {
        cout << "Generala!";
        flag++;
        if(num_jugada==1)
        { 
            cout << " y servida!" << endl;
            cout << "Jugador N° " << n_jugador << " gana el juego! " << endl;
            matriz[n_jugador][11]=10000;
            return;
        }
        if((matriz[n_jugador][10]>0) && (matriz[n_jugador][11]==0))
        {
            cout<< "Doble generala, son 100 puntos" << endl;
            matriz[n_jugador][11] = 100;
            return;
        }
        cout << " son 50 puntos" << endl;
        if(matriz[n_jugador][10] == 0) {matriz[n_jugador][10]=50;}
        return;
    }
    // escalera
    else if(((jugada[0]==1)&(jugada[1]==2)&(jugada[2]==3)&(jugada[3]==4)&(jugada[4]==5)) ||((jugada[0]==2)&(jugada[1]==3)&(jugada[2]==4)&(jugada[3]==5)&(jugada[4]==6)) ||((jugada[0]==1)&(jugada[1]==3)&(jugada[2]==4)&(jugada[3]==5)&(jugada[4]==6)))
    {   
        cout << "Es escalera ";
        flag++;
        if((num_jugada==1) && matriz[n_jugador][7]==0)
        {
            cout << " y servida! son 25 puntos" << endl;
            matriz[n_jugador][7]=25;
            return;
        }
        else
        {
            if(matriz[n_jugador][7]==0)
            {
            cout << " son 20 puntos " << endl;
            matriz[n_jugador][7]=20;
            return;
            }
        }
    }
    // poker, solo si x,yyyy o , xxxx,y
    else if((jugada[0]==jugada[3])|| (jugada[1]==jugada[4]))
    {
        cout << "Es poker ";
        flag++;
        if((num_jugada==1)&& (matriz[n_jugador][9]==0))
        {
            cout << " y servido! son 45 puntos" << endl;
            matriz[n_jugador][9]=45;
            return;
        }
        else
        {
            if(matriz[n_jugador][9]==0)
            {
            cout << " son 40 puntos " << endl;
            matriz[n_jugador][9]=40;
            return;
            }
        }
        }
    //full, solo si xxx,yy o , xx,yyy
    else if(((jugada[0]==jugada[1]==jugada[2]) && (jugada[3]==jugada[4]))|| ((jugada[0]==jugada[1]) && (jugada[2]==jugada[3]==jugada[4])))
    {
        cout << "Es full ";
        flag++;
        if((num_jugada==1) && (matriz[n_jugador][8]==0))
        {
            cout << " y servido! son 35 puntos" << endl;
            matriz[n_jugador][8]=35;
            return;
        }
        else
        {
            if(matriz[n_jugador][8]==0)
            {
            cout << " son 30 puntos " << endl;
            matriz[n_jugador][8]=30;
            return;
            }
        }
    }
    // Logica de tachado y anotado de categorias numericas
    if((flag==0) && (num_jugada==3))
    {

        if(matriz[n_jugador][1]==0)
        {
            if(uno==0)
            {
                matriz[n_jugador][1]=-1;
                cout << " Se tacho el 1 " << endl;
                return;
            }
            else
            {
            cout << "Se anoto " << uno * 1<< " al 1 " << endl;
            matriz[n_jugador][1]= uno * 1;
            return;
            }
        }
        else if(matriz[n_jugador][2]==0)
        {
            if(dos*2 ==0)
            { matriz[n_jugador][2]=-1;
            cout << " Te tacho el 2 " << endl;
            return;
            }
            else
            {
            cout << "Se anoto  " << dos * 2<< " al 2" << endl;
            matriz[n_jugador][2]= dos * 2;
            return;
            }
        }
        else if(matriz[n_jugador][3]==0)
        {
            if(tres* 3 ==0)
            { 
            matriz[n_jugador][3]=-1;
            cout << " Te tacho el 3 " << endl;
            return;
            }
            else
            {
            cout << "Se anoto  " << tres * 3<< " al 3 " << endl;
            matriz[n_jugador][3]= tres * 3;
            return;
            }
        }
        else if(matriz[n_jugador][4]==0)
        {   
            if(cuatro * 4 ==0)
            {
            matriz[n_jugador][4]=-1;
            cout << " Te tacho el 4 " << endl;
            return;
            }
            else
            {
            cout << "Se anoto  " << cuatro * 4<< " al 3 " << endl;
            matriz[n_jugador][4]= cuatro * 4;
            return;
            }
        }
        else if(matriz[n_jugador][5]==0)
        {
            if(cinco * 5 == 0)
            {
            matriz[n_jugador][5]=-1;
            cout << " Te tacho el 5 " << endl;
            return;
            }
            else
            {
            cout << "Se anoto " << cinco * 5<< " al 5 " << endl;
            matriz[n_jugador][5]= cinco * 5;
            return;
            }
        }
        else if(matriz[n_jugador][6]==0)
        {
            if(seis * 6 ==0)
            {
            matriz[n_jugador][6]=-1;
            cout << "Se tacho el 6 " << endl;
            return;
            }
            else
            {
            cout << "Se anoto " << seis * 6<< " al 6 " << endl;
            matriz[n_jugador][6]= seis * 1;
            return;
            }
        }
        if((matriz[n_jugador][1]!=0)&& (matriz[n_jugador][2]!=0)&&(matriz[n_jugador][3]!=0)&&(matriz[n_jugador][4]!=0)&&(matriz[n_jugador][5]!=0)&&(matriz[n_jugador][6])!=0)
        {
            if(matriz[n_jugador][11]==0)
            {
                cout << "Se procedio a tachar la Doble Generala por tener las categorias numericas llenas" << endl;
                matriz[n_jugador][11]=-1;
                return;
            }
            else if(matriz[n_jugador][10]==0)
            {
                cout << "Se procedio a tachar la Generala por tener las categorias numericas llenas y tambien la Doble Generala" << endl;
                matriz[n_jugador][10]=-1;
                return;
            }
            else if(matriz[n_jugador][9]==0)
            {
                cout << "Se procedio a tachar el Poker por tener las categorias numericas llenas y tambien la Doble Generala y la generala" << endl;
                matriz[n_jugador][9]=-1;
                return;
            }
            else if(matriz[n_jugador][8]==0)
            {
                cout << "Se procedio a tachar el Full por tener las categorias numericas llenas y tambien la Doble Generala y la generala y el poker" << endl;
                matriz[n_jugador][8]=-1;
                return;
            }
            else if(matriz[n_jugador][7]==0)
            {
                cout << "Se procedio a tachar la escalera por tener las categorias numericas llenas y tambien la Doble Generala, la generala, el poker y el full" << endl;
                matriz[n_jugador][7]=-1;
                return;
            }
            
        }
    }
    // Mensaje si salio categoria especial
    else if(flag==1)
    {
        num_jugada=3;
        cout << "Usted consiguio una categoria especial, se le anoto para su comodidad" << endl;
        return;

    }


}



// Me queda pendiente la ultima parte

/*

7. Los datos se deben ir guardando en un archivo de registros con el siguiente formato: 
    * Id de jugada (un número por jugada, para lo cual tienen que buscar el último ingresado) 
    * Nombre del jugador 
    * Fecha (AAAAMMDD) 
    * Puntaje 
8. Por último hacer un ranking de los 3 mejores cargando los datos del archivo en una lista ordenada. 

*/