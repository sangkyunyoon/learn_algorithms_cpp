//
// Created by Sangkyun Yoon on 3/12/21.
//
#include <iostream>
using namespace std;

void print_array(int *data, int length) {
    for (int i = 0; i < length; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void merge(int *data, int *tmp, int start, int mid, int end) {
    for (int i = start; i <= end; i++) {
        tmp[i] = data[i];
    }
    int part1 = start;
    int part2 = mid + 1;
    int index = start;
    while (part1 <= mid && part2 <= end) {
        if(tmp[part1] <= tmp[part2]) {
            data[index] = tmp[part1];
            part1++;
        } else {
            data[index] = tmp[part2];
            part2++;
        }
        index++;
    }
    for (int i = 0; i <= mid - part1; i++) {
        data[index + i] = tmp[part1 + i];
    }
}

void merge_sort(int *data, int *tmp, int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        merge_sort(data, tmp, start, mid); //partition
        merge_sort(data, tmp, mid + 1, end);//partition
        merge(data, tmp, start, mid, end); //merge & sort
    }
}

void merge_sort(int *data, int length) {
    int tmp[length];
    merge_sort(data, tmp, 0, length - 1);
}

int main() {
    int length = 10;
    int data[] = {3, 9, 4, 7, 5, 0, 1, 6, 8, 2};
    print_array(data, length);
    merge_sort(data, length);
    print_array(data, length);
    return 0;
}