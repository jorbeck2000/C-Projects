//
//  Busqueda.h
//  actividad 1.2
//
//  Created by Jorge Becker on 9/8/20.
//  Copyright © 2020 Jorge Becker. All rights reserved.
//

#ifndef Busqueda_h
#define Busqueda_h
using namespace std;
#include <vector>
#include <iostream>

template<typename T>
class Busqueda
{
private:
    vector<T>arr;
    
public:
    Busqueda(){};
    ~Busqueda(){};
    
T BusquedaSecuencial( T search, vector<T> arr){//Metodo para busqueda secuencial
        for(int i=0; i<arr.size(); i++){//Iteracion para realizar la busqueda en todas las posiciones del arreglo
        if(arr[i]==search){
            return i;
        }
    }
    return -1;
        
    };
    
T BusquedaBinaria(T search, vector<T> arr)//Metodo para busqueda binaria
    {
        sort(arr.begin(), arr.end());

        int inicio = 0;
        int fin = arr.size() - 1;
        if (inicio > arr[fin] || search < arr[inicio])
        {
            return -1;
        }
        while (fin >= inicio)
        {
            int med = (inicio + fin) / 2;
            if (arr[med] == search)
            {
                return med;
            }
            else if (search > arr[med])
            {
                inicio = med + 1;
            }
            else
            {
                fin = med - 1;
            }
        }
        return -1;
    };
};

    


#endif /* Busqueda_h */
