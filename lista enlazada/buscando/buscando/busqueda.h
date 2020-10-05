//
//  busqueda.h
//  buscando
//
//  Created by Jorge Becker on 8/31/20.
//  Copyright © 2020 Jorge Becker. All rights reserved.
//


#define busqueda_h
#include <stdlib.h>
using namespace std;
#include <vector>
#include <iostream>

template<typename T>
class Busqueda
{
private:
    vector<T>arr;
    
public:
    Busqueda(){
        for (int i =0; i<100000; i++) {
            arr.push_back(rand()%60000);
        }
        
    };
    ~Busqueda(){};
    
    T BusquedaSecuencial( T search){
            for(int i=0; i<arr.size()-1; i++){
            if(arr[i]==search){
                return i;
            }
        }
        return -1;
        
    }


    T BusquedaOrdenada1(T search){
        sort(arr.begin(),arr.end());
        for(int i=0; i<arr.size()-1; i++){
            if(arr[i]>search){
                return -1;
                
            }
            if(arr[i]==search){
                return i;
            }
        }
        return -1;
    }
    
    T BusquedaOrdenada2 (T search){
        sort(arr.begin(),arr.end());
     int step=2;
        int start=0;
        int finish;
        while(start<arr.size()){
            finish=start+step;
            if(finish>arr.size()){
                finish=arr.size()-1;
            }
            if(arr[finish-1]>=search){
                for(int i=start; i<finish; i++){
                    if(arr[i]==search){
                        return i;
                    }
                }
                return -1;
            }
            start=finish;
        }
        return -1;

    }
    T BusquedaBinaria (T search){
        sort(arr.begin(),arr.end());
        int start=0;
        int finish=arr.size()-1;
        if(start>arr[finish] || search<arr[start]){
            return -1;
        }
        while(finish>=start){
            int med=(start+finish)/2;
            if(arr[med]==search){
                return med;
            }else if(search>arr[med]){
                start=med+1;
            }else{
                finish=med-1;
            }
        }
        return -1;
    }
    
};

