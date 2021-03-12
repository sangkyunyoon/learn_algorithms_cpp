# learn_algorithms_cpp
Learn Algorithms using C++

#이진 트리의 구현과 순회
기본적으로 가장 많이 사용되는 비선형 자료구조는 이진 트리(Binary Tree)입니다. 
이진 트리는 트리 자료구조를 활용한 대표적인 예시로 데이터의 탐색 속도 증진을 위해 사용하는 구조입니다. 

힙 정렬(Heap Sort)을 구현할 때 간단하게 이진 트리에 대해 다루어 본 적이 있습니다. 

실제로 트리를 제대로 구현하기 위해서는 포인터(Pointer)를 사용해야 합니다.
포인터를 이용해 특정한 루트(Root)에서 자식 노드로 접근할 수 있기 때문입니다.

하나의 노드는 모두 왼쪽 자식과 오른쪽 자식을 가질 수 있도록 설계가 되어있습니다. 

### 순회 방법
#### ① 전위 순회(Preorder Traversal)

  하나의 노드에 방문했을 때 다음의 순서를 따릅니다.

  (1) 먼저 자기 자신을 처리합니다.  
  (2) 왼쪽 자식을 방문합니다.  
  (3) 오른쪽 자식을 방문합니다.

#### ② 중위 순회(Inorder Traversal)

  하나의 노드에 방문했을 때 다음의 순서를 따릅니다.

  (1) 왼쪽 자식을 방문합니다.  
  (2) 먼저 자기 자신을 처리합니다.  
  (3) 오른쪽 자식을 방문합니다.

#### ③ 후위 순회(Postorder Traversal)

  (1) 왼쪽 자식을 방문합니다.  
  (2) 오른쪽 자식을 방문합니다.  
  (3) 먼저 자기 자신을 처리합니다.

~~~
#iclude <iostream>

int number = 15;

typedef struct Node* Tree;
typedef struct Node {
    int data;
    Tree leftChild, rightChild;
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
    preorder(&node[1]);
    std::cout << std::endl;
    inorder(&node[1]);
    std::cout << std::endl;
    postorder(&node[1]);
    return 0;
}
~~~