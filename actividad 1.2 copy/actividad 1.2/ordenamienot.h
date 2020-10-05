//
//  ordenamienot.h
//  actividad 1.2
//
//  Created by Jorge Becker on 9/8/20.
//  Copyright © 2020 Jorge Becker. All rights reserved.
//

#ifndef ordenamienot_h
#define ordenamienot_h


#include <iostream>
#include <vector>

template <typename T>
class Sorter //Clase papa para intercambio de numeros en los metodos de ordenamiento
{
    public:
    Sorter() {};
    ~Sorter() {};

    void swap(int i, int j, std::vector<T> &arr)
    {
        T aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
    };

    virtual void sort(std::vector<T> &arr) {};
};

template <typename T>
class InsertionSort : public Sorter<T> //Clase para realizar el insertion sort
{
    public:
    InsertionSort() {};
    ~InsertionSort() {};

    void sort(std::vector<T> &arr)
    {
        T key;
        for (size_t i = 1; i < arr.size(); i++)
        {
            key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    };
};

template <typename T>
class BubbleSort : public Sorter<T>//Clase para realizar el bubble sort
{
    public:
    BubbleSort() {};
    ~BubbleSort() {};

    void sort(std::vector<T> &arr)
    {
        for (size_t i = 0; i < arr.size(); i++)
        {
            bool no_swap = true;
            for (size_t j = 0; j < arr.size() - i-1; j++)
            {
                if (arr[j] > arr[j+1]) {
                    Sorter<T>::swap(j, j+1, arr);
                    no_swap = false;
                }
            }
            if (no_swap)
                break;
        }
    };
};

template <typename T>
class Quicksort : public Sorter<T>//Clase para realizar el quick sort
{
    public:
    Quicksort() {};
    ~Quicksort() {};

    void sort(std::vector<T> &arr)
    {
        quicksort(arr, 0, arr.size() - 1);
    };

    void quicksort(std::vector<T> &arr, int low, int high)
    {
        if (low < high)
        {

            int pi = partition(arr, low, high);//Parte los elementos en 2 del arreglo
      

            quicksort(arr, low, pi - 1);
            quicksort(arr, pi + 1, high);
        }
    };


    int partition (std::vector<T> &arr, int low, int high)
    {
        T pivot = arr[high];//pivote
        int i = (low - 1);
      
        for (int j = low; j <= high - 1; j++)
        {
           
            if (arr[j] < pivot)
            {
                i++; // Aumenta la posicion del elemento mas chico
                Sorter<T>::swap(i, j, arr);
            }
        }
        Sorter<T>::swap(i+1, high, arr);
        return (i + 1);
    };
};


#endif /* ordenamienot_h */
