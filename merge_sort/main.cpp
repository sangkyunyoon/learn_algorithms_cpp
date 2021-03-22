//
// Created by Sangkyun Yoon on 3/12/21.
//
#include <iostream>

void merge_sort(int *pInt, int pInt1[-1], int i, int i1);

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

void merge(int *data, int *tmp, int start, int mid, int end) {
    if(start < mid)
}

void merge_sort(int *data, int *tmp, int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        merge_sort(data, tmp, start, mid); //partition
        merge_sort(data, tmp, mid + 1, end);//partition
        merge(data, tmp, start, mid, end); //merge & sort
    }
}

void merge_sort(int* data, int length) {
    int tmp[length];
    merge_sort(data, tmp, 0, length - 1);
}

int main() {

    return 0;
}