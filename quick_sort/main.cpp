//
// Created by Sangkyun Yoon on 3/15/21.
//
#include <iostream>
using namespace std;

void quick_sort(int *data, int start, int end) {
    if(start >= end) { //원소가 1개인 경우
        return;
    }

    int key = start; //pivot 값을 임의로 첫번째로 설정
    int i = start + 1; //pivot 값을 제외한 첫 번째 값을 start로 설정
    int j = end;
    int temp;

    while(i <= j) { //엇갈릴 때까지 반복
        //start의 위치 찾기, 작은값은 건너뛰고 pivot 값보다 큰 값
        while(data[i] <= data[key]) { //키 값보다 큰 값을 만날 때
            i++;
        }
        //end의 위치 찾기, 큰값은 건너뛰고 pivot 값보다 작은 값
        while(data[j] >= data[key] && j > start) {
            j--;
        }
        //pivot(key) 기준 큰값의 위치와 작은 값의 위치를 찾은 상태
        //start와 end의 위치을 교환
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
void swap(int* data, int start, int end) {
    int temp = data[start];
    data[start] = data[end];
    data[end] = temp;
}
//pivot 기준으로 작은 값은 왼쪽에 큰 값은 오른쪽으로 정렬한다. (pivot을 기준으로 나눌 수 있게 된다.)
int partition(int* data, int start, int end) {
    int pivot = data[(start + end) / 2];
    //3, 9, 4, 7, 0, 1, 5, 8, 6, 2
    /*
     pivot  = 0

     start
     if(3 < 0) : start = 0, value = 3

     end
     if(2 > 0) : end = 8, value = 6
     if(6 > 0) : end = 7, value = 8
     if(8 > 0) : end = 6, value = 5
     if(5 > 0) : end = 5, value = 1
     if(1 > 0) : end = 4, value = 0

     swap
     if(start(0) <= end(4)) : 0, 9, 4, 7, 3, 1, 5, 8, 6, 2
     start = 1, end = 3

     if(9 <= 0) : start = 1;
     if(7 > 0) : end = 2
     if(4 > 0) : end = 1
     if(9 > 0) : end = 0
     if(0 > 0) : end = 0

    */
    while (start <= end) {
        while (data[start] < pivot) {
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
void quickSort(int* data, int start, int end) {
    int part2 = partition(data, start, end);
    if(start < part2 - 1) {
        quickSort(data, start, part2 - 1);
    }
    if(part2 < end) {
        quickSort(data, part2, end);
    }
}
void printArray(int* data, int length) {
    for (int i = 0; i < length; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
int main() {
    int number = 10;
    int data1[] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
    int data2[] = {3, 9, 4, 7, 0, 1, 5, 8, 6, 2};

    quick_sort(data1, 0, number - 1);
    printArray(data1, number);

    quickSort(data2, 0, number - 1);
    printArray(data2, number);

    return 0;
}