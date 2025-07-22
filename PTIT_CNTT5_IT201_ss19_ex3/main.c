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

void addValue(Node *node, int value) {
    if (node == NULL) {
        return;
    }
    if (value < node->data) {
        if (node->left == NULL) {
            node->left = createNode();
            node->left->data = value;
        } else {
            addValue(node->left, value);
        }
    } else if (value > node->data) {
        if (node->right == NULL) {
            node->right = createNode();
            node->right->data = value;
        } else {
            addValue(node->right, value);
        }
    }
}

int main() {
    Node *node1 = createNode();//2
    Node *node2 = createNode();//3
    Node *node3 = createNode();//4
    Node *node4 = createNode(); //5
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    int value;
    printf("Nhap gia tri: ");
    scanf("%d", &value);
    addValue(node1, value);
    preorder(node1);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    return 0;
}