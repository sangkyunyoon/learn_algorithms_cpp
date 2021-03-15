//
// Created by Sangkyun Yoon on 3/12/21.
//
#include <iostream>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int j, temp;
    int arr[] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

    for (int i = 0; i < 9; i++) {
        j = i;
        while(j >= 0 && arr[j] > arr[j + 1]) {
            swap(arr[j], arr[j + 1]);
            //swap(&arr[j], &arr[j + 1]);
            j--;
        }
        std::cout << i << ": ";
        for (int k = 0; k < 10; ++k) {
            std::cout << arr[k] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}