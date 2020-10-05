//
//  main.cpp
//  actividad 1.2
//
//  Created by Jorge Becker on 9/8/20.
//  Copyright © 2020 Jorge Becker. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <vector>
#include "ordenamienot.h"
#include "Busqueda.h"

using namespace std;

int main() {
    
    int count;
    cout << "Enter array size: ";
    cin >> count;

    // generate a random vector array of float of size count
    vector<int> arr_f;
    for (size_t i = 0; i < count; i++)
    {
        arr_f.push_back((int)rand()%100);
    }

    int select;
    int cantidad;
    int num;
    cout<<"Cuantas busquedas deseas realizar?"<<endl;
    cin>>cantidad;
    Busqueda<int> o1;//Creacion del objeto de busqueda

    for (int i=0; i<cantidad; i++) {//For para realizar el ordenamiento y busqueda la cantidad de veces seleccionado
        
        
        cout<<"Que numero deseas buscar? ";//Seleccion de numero a buscar
        cin >>num;
        cout<<"¿Que método de ordenamiento desdeas utilizar? "<<endl;//Menu de opcionde de ordenamiento
        cout<<"1) insertion sort"<<endl;
        cout<<"2) Bubble sort"<<endl;
        cout<<"3) Quick sort"<<endl;
        cin>>select;
        
        int posicion=o1.BusquedaSecuencial(num, arr_f);//Busqueda secuencial de la seleccion
        cout<<"Busqueda secuencial: "<<posicion<<endl;
        
        
        
        vector<int> arr_c(arr_f);
        if (select==1){
            cout<<"Ordenado con Insertion sort"<<endl;
            InsertionSort<int> inssort;//Ordenamiento por Insertion sort
            inssort.sort(arr_c);
        }
        
        if (select==2){
            cout<<"Ordenado con Bubble sort"<<endl;
            BubbleSort<int> bubsort;//Ordenamiento por Bubble sort
            bubsort.sort(arr_c);
        }
        
        if (select==3){
            cout<<"Ordenado con Quick sort"<<endl;
            Quicksort<int> quicksort;//Ordenamiento por Quick sort
            quicksort.sort(arr_c);
        }
        
        
        int ordenado=o1.BusquedaBinaria(num, arr_c);//Busqueda binaria del arreglo ordenado previamente
        cout<<"Posicion en el arreglo ordenado: "<<ordenado<<endl;
    }
    

}
