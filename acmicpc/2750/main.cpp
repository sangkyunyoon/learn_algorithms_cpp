//
// Created by Sangkyun Yoon on 3/18/21.
//
#include <iostream>
using namespace std;
void swap(int* data, int start, int end) {
    int temp = data[start];
    data[start] = data[end];
    data[end] = temp;
}
int partition(int* data, int start, int end) {
    int pivot = data[(start + end) / 2];

    while(start <= end) {
        while(data[start] < pivot) {
            start++;
        }
        while(data[end] > pivot) {
            end--;
        }
        if(start <= end) {
            swap(data, start, end);
            start++;
            end--;
        }
    }

    return start;
}
void quick_sort(int* data, int start, int end) {
    int part2 = partition(data, start, end);
    if(start < part2 - 1) {
        quick_sort(data, start, part2 - 1);
    }
    if(part2 < end) {
        quick_sort(data, part2, end);
    }
}
int main() {
    int N;
    cin >> N;
    if(N < 1 || N > 1000000) {
        exit(0);
    }

    int index, min, temp;
    int arr[N];
    for (int k = 0; k < N; ++k) {
        cin >> arr[k];
    }

    quick_sort(arr, 0, N - 1);

    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}