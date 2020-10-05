//
//  main.cpp
//  buscando
//
//  Created by Jorge Becker on 8/31/20.
//  Copyright © 2020 Jorge Becker. All rights reserved.
//

#include <iostream>
#include "busqueda.h"
#include "Mytimer.h"
using namespace std;
int main(){
Busqueda<int> o1;
int busqueda1 = o1.BusquedaSecuencial(5000);
int busqueda2 = o1.BusquedaOrdenada1(5000);
int busqueda3 = o1.BusquedaOrdenada2(5000);
int busqueda4 = o1.BusquedaBinaria(50000);
    DECLARE_TIMING(t);
    START_TIMING(t);
    int tiempo1 = o1.BusquedaSecuencial(70000);
    STOP_TIMING(t);
    SHOW_TIMING(t, " secuencial");
    
    DECLARE_TIMING(a);
    START_TIMING(a);
    int tiempo2 = o1.BusquedaOrdenada1(70000);
    STOP_TIMING(a);
    SHOW_TIMING(a, " ordenada");
    
    DECLARE_TIMING(b);
    START_TIMING(b);
    int tiempo3 = o1.BusquedaOrdenada2(70000);
    STOP_TIMING(b);
    SHOW_TIMING(b, " ordenada");

    DECLARE_TIMING(c);
    START_TIMING(c);
    int tiempo4 = o1.BusquedaBinaria(70000);
    STOP_TIMING(c);
    SHOW_TIMING(c, " binaria");
    
    
cout<<"Busqueda secuencial: "<<busqueda1<<endl;
cout<<"Busqueda ordenada 1: "<<busqueda2<<endl;
cout<<"Busqueda ordenada 2: "<<busqueda3<<endl;
cout<<"Busqueda binaria: "<<busqueda4<<endl;
    
}
