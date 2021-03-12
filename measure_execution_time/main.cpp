//
// Created by Sangkyun Yoon on 3/12/21.
//
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int number = 15;

//typedef struct Node* NodePointer;
typedef struct Node {
    int data;
    Node* leftChild;
    Node* rightChild;
} Node;

void preorder(Node* node) {
    if(node) {
        std::cout << node->data << ' ';
        preorder(node->leftChild);
        preorder(node->rightChild);
    }
}

void inorder(Node* node) {
    if(node) {
        inorder(node->leftChild);
        std::cout << node->data << ' ';
        inorder(node->rightChild);
    }
}

void postorder(Node* node) {
    if(node) {
        postorder(node->leftChild);
        postorder(node->rightChild);
        std::cout << node->data << ' ';
    }
}

int main() {
    Node node[number + 1];
    for (int i = 1; i <= number; ++i) {
        node[i].data = i;
        node[i].leftChild = NULL;
        node[i].rightChild = NULL;
    }
    for (int j = 1; j <= number; ++j) {
        if(j % 2 == 0) {
            node[j / 2].leftChild = &node[j];
        } else {
            node[j / 2].rightChild = &node[j];
        }
    }
    auto start = std::chrono::high_resolution_clock::now();
    //auto start = high_resolution_clock::now();

    std::cout << "전위 순회: ";
    preorder(&node[1]);
    std::cout << std::endl;
    std::cout << "중위 순회: ";
    inorder(&node[1]);
    std::cout  << std::endl;
    std::cout << "후위 순회: ";
    postorder(&node[1]);
    std::cout << endl;

    auto stop = std::chrono::high_resolution_clock::now();
    //auto stop = high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    //auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds";
    return 0;
}