//
// Created by Sangkyun Yoon on 3/12/21.
//
#include <iostream>

using namespace std;

int main() {
    int temp;
    int arr[] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

    //배열의 수 만큼 루프를 돌면서...
    for (int i = 0; i < 10; i++) {
        //
        for (int j = 0; j < 9 - i; j++) {
            //오름차순
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            //내림차순
            /*
            if(arr[j] < arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
            */
        }
        std::cout << i << ": ";
        for (int k = 0; k < 10; ++k) {
            std::cout << arr[k] << " ";
        }
        std::cout << endl;
    }
    //배열의 수 만큼 루프를 돌면서 값을 출력한다.
    for (int k = 0; k < 10; ++k) {
        std::cout << arr[k] << " ";
    }
    return 0;
}