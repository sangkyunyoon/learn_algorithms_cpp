//
// Created by Sangkyun Yoon on 3/18/21.
//
#include <iostream>
using namespace std;
int main() {
    int SIZE = 3;
    int index, min, temp;
    int arr[SIZE];
    for (int k = 0; k < SIZE; ++k) {
        cin >> arr[k];
        if(arr[k] < 1 || arr[k] > 1000000) {
            return 1;
        }
    }

    for (int i = 0; i < SIZE; ++i) {
        min = 1000001;
        for (int j = i; j < SIZE; ++j) {
            if(min > arr[j]) {
                min = arr[j];
                index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }

    for (int l = 0; l < SIZE; ++l) {
        cout << arr[l] << " ";
    }

    return 0;
}