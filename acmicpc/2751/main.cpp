//
// Created by Sangkyun Yoon on 3/18/21.
//
#include <iostream>
#include <algorithm>
using namespace std;
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

    sort(arr, arr + N);

    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}