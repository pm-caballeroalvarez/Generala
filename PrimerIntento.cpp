#include <iostream>
using namespace std;


int main() {
    cout << "Tabla Matriz" << endl;
    int n;
    cout << "Ingrese cantidad de jugadores " << endl;
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




    return 0;
}