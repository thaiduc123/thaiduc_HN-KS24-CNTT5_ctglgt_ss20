#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    int id;
    char name[20];
    char address[50];
} Student;

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode() {
    int value;
    printf("Nhap gia tri bat ki: ");
    scanf("%d", &value);
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorder(Node *node) {
    if (node == NULL) {
        return;
    }
    printf("%d\n", node->data);
    preorder(node->left);
    preorder(node->right);
}

int findLevel(Node *root, int value) {
    if (root == NULL){
        return -1;
    }
    if (root->data == value){
        return 0;
    }
    int left = findLevel(root->left, value);
    if (left != -1){
        return left + 1;
    }
    int right = findLevel(root->right, value);
    if (right != -1) {
        return right + 1;
    }
    return -1;
}

int main() {
    Node *node1 = createNode();//2
    Node *node2 = createNode();//3
    Node *node3 = createNode();//4
    Node *node4 = createNode(); //5
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    preorder(node1);
    int value;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);
    int level = findLevel(node1, value);
    if (level != -1) {
        printf("Node level: %d\n", level);
    } else {
        printf("Khong tim thay gia tri %d trong cay\n", value);
    }
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    return 0;
}