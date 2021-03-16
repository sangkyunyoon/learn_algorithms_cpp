//
// Created by Sangkyun Yoon on 3/15/21.
//
#include <iostream>
using namespace std;

void quick_sort(int *data, int start, int end) {
    if(start >= end) { //원소가 1개인 경우
        return;
    }

    int key = start;
    int i = start + 1;
    int j = end;
    int temp;

    while(i <= j) { //엇갈릴 때까지 반복
        while(data[i] <= data[key]) { //키 값보다 큰 값을 만날 때
            i++;
        }
        while(data[j] >= data[key] && j > start) {
            j--;
        }
        // {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
        if(i > j) {
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        } else {
            temp = data[j];
            data[j] = data[i];
            data[i] = temp;
        }
    }

    quick_sort(data, start, j - 1);
    quick_sort(data, j + 1, end);

}
int main() {
    int number = 10;
    int data[] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

    quick_sort(data, 0, number - 1);

    for (int i = 0; i < number; ++i) {
        cout << data[i] << " ";
    }
    return 0;
}