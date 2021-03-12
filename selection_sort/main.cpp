//
// Created by Sangkyun Yoon on 3/12/21.
//
#include <iostream>

int main() {
    int min, index, temp;
    int arr[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

    //정렬을 해야하는 수 만큼 루프를 돈다.
    for (int i = 0; i < 10; ++i) {
        //항상 최소값은 가장 큰수보다 큰 값으로 매번 초기화 되어야 한다.
        min = 9999;
        //정렬 대상을 최소값과 하나씩 비교하면서 정렬되지 않은 대상에서 최소값을 찾는다. 값과 위치 정보 획득
        for (int j = i; j < 10; ++j) {
            if(min > arr[j]) {
                min = arr[j];
                index = j;
            }
        }
        //i번째 위치의 값과 최소값을 스왑한다.
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;

        std::cout << i << ": ";
        for (int k = 0; k < 10; ++k) {
            std::cout << arr[k] << " ";
        }
        std::cout << std::endl;
    }

    //배열의 수 만큼 루프를 돌면서 값을 출력한다.
    for (int k = 0; k < 10; ++k) {
        std::cout << arr[k] << " ";
    }

    return 0;
}