//
// Created by skidr on 29/11/2019.
//

#include <iostream>
#include <chrono>

#include "sorting_algs.h"

using namespace std;


void testInsertSort(vector<int> *vec) {
    auto start = chrono::high_resolution_clock::now();
    insertionSort<int>(*vec);
    auto duration = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start);

    cout << "insertion sort took: " << duration.count() << " microseconds (" << duration.count() / 1e6 << " seconds)" << endl;
}

void testSelSort(vector<int> *vec) {
    auto start = chrono::high_resolution_clock::now();
    selectionSort<int>(*vec);
    auto duration = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start);

    cout << "selection sort took: " << duration.count() << " microseconds (" << duration.count() / 1e6 << " seconds)" << endl;
}

void testBubbleSort(vector<int> *vec) {
    auto start = chrono::high_resolution_clock::now();
    bubbleSort<int>(*vec);
    auto duration = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start);

    cout << "bubble sort took: " << duration.count() << " microseconds (" << duration.count() / 1e6 << " seconds)" << endl;
}

void testShellSort(vector<int> *vec) {
    auto start = chrono::high_resolution_clock::now();
    shellSort<int>(*vec);
    auto duration = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start);

    cout << "shell sort took: " << duration.count() << " microseconds (" << duration.count() / 1e6 << " seconds)" << endl;
}

void testMergeSort(vector<int> *vec) {
    auto start = chrono::high_resolution_clock::now();
    mergeSort<int>(*vec);
    auto duration = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start);

    cout << "merge sort took: " << duration.count() << " microseconds (" << duration.count() / 1e6 << " seconds)" << endl;
}

void testQuickSort(vector<int> *vec) {
    auto start = chrono::high_resolution_clock::now();
    quickSort<int>(*vec);
    auto duration = chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start);

    cout << "quick sort took: " << duration.count() << " microseconds (" << duration.count() / 1e6 << " seconds)" << endl;
}



int main() {
    srand(1);
    vector<int> model;

    for (int i = 0; i < 50000; i++)
        model.emplace_back(rand() % 500000);

    vector<int> toSort;

    toSort = {model.begin(), model.end()};
    testInsertSort(&toSort);

    toSort = {model.begin(), model.end()};
    testSelSort(&toSort);

    toSort = {model.begin(), model.end()};
    testBubbleSort(&toSort);

    toSort = {model.begin(), model.end()};
    testShellSort(&toSort);

    toSort = {model.begin(), model.end()};
    testMergeSort(&toSort);

    toSort = {model.begin(), model.end()};
    testQuickSort(&toSort);

}
