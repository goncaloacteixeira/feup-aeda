//
// Created by skidr on 29/11/2019.
//

#ifndef SORTING_SORTING_ALGS_H
#define SORTING_SORTING_ALGS_H

#include <vector>
#include <algorithm>

using namespace std;

template <class Comparable>
void insertionSort(vector<Comparable> &v)
{
    for (unsigned int p = 1; p < v.size(); p++)
    {
        Comparable tmp = v[p];
        int j;
        for (j = p; j > 0 && tmp < v[j-1]; j--)
            v[j] = v[j-1];
        v[j] = tmp;
    }
}


template <class Comparable>
void selectionSort(vector<Comparable> &v )
{
    typename vector<Comparable>::iterator it;
    for(it = v.begin(); it != v.end()-1; ++it )
        iter_swap(it, min_element(it, v.end()));
}


template <class Comparable>
void bubbleSort(vector<Comparable> &v)
{
    for(unsigned int j=v.size()-1; j>0; j--)
    {
        bool troca=false;
        for(unsigned int i = 0; i<j; i++)
            if(v[i+1] < v[i]) {
                swap(v[i],v[i+1]);
                troca = true;
            }
        if (!troca) return;
    }
}

template <class Comparable>
void shellSort(vector<Comparable> &v)
{
    int j;
    for (int gap = v.size()/2; gap > 0; gap /= 2)
        for (unsigned int i = gap; i < v.size(); i++)
        {
            Comparable tmp = v[i];
            for (j = i; j >= gap && tmp < v[j-gap]; j -= gap)
                v[j] = v[j-gap];
            v[j] = tmp;
        }
}


// internal method that makes recursive calls. v is an array of
// Comparable terms. tmpArray is an array to place the merged result.
// left (right) is the left(right)-most index of the subarray
template <class Comparable>
void merge(vector <Comparable> & v, vector<Comparable> &tmpArray,
           int leftPos, int rightPos, int rightEnd)
{
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;
    while ( leftPos <= leftEnd && rightPos <= rightEnd )
        if ( v[leftPos] <= v[rightPos] )
            tmpArray[tmpPos++] = v[leftPos++];
        else
            tmpArray[tmpPos++] = v[rightPos++];
    while ( leftPos <= leftEnd )
        tmpArray[tmpPos++] = v[leftPos++];
    while ( rightPos <= rightEnd )
        tmpArray[tmpPos++] = v[rightPos++];
    for ( int i = 0; i < numElements; i++, rightEnd-- )
        v[rightEnd] = tmpArray[rightEnd];
}



// internal method that makes recursive calls
// v is an array of Comparable terms
// tmpArray is an array to place the merged result
// left (right) is the left(right)-most index of the subarray
template <class Comparable>
void mergeSort(vector <Comparable> & v,
               vector<Comparable> & tmpArray, int left, int right)
{
    if (left < right)
    {
        int center = (left + right) / 2;
        mergeSort(v, tmpArray, left, center);
        mergeSort(v, tmpArray, center + 1, right);
        merge(v, tmpArray, left, center +1, right);
    }
}

template <class Comparable>
void mergeSort(vector <Comparable> & v) {
    vector<Comparable> tmpArray(v.size());
    mergeSort(v, tmpArray, 0, v.size()-1);
}


/* determina o valor do pivot como sendo a mediana de 3 valores: elementos
extremos e central do vetor */
template <class Comparable>
const Comparable &median3(vector<Comparable> &v, int left,
                          int right)
{
    int center = (left+right) /2;
    if (v[center] < v[left])
        swap(v[left], v[center]);
    if (v[right] < v[left])
        swap(v[left], v[right]);
    if (v[right] < v[center])
        swap(v[center], v[right]);
//coloca pivot na posicao right-1
    swap(v[center], v[right-1]);
    return v[right-1];
}

template <class Comparable>
void quickSort(vector<Comparable> &v, int left, int right)
{
    if (right-left <= 10) // se vetor pequeno
        insertionSort<Comparable>(v);
    else {
        Comparable x = median3(v,left,right); // x é o pivot
        int i = left; int j = right-1; // passo de partição
        for(; ; ) {
            while (v[++i] < x) ;
            while (x < v[--j]) ;
            if (i < j)
                swap(v[i], v[j]);
            else break;
        }
        swap(v[i], v[right-1]); //repoe pivot
        quickSort(v, left, i-1);
        quickSort(v, i+1, right);
    }
}

template <class Comparable>
void quickSort(vector<Comparable> &v)
{
    quickSort(v,0,v.size()-1);
}



#endif //SORTING_SORTING_ALGS_H
