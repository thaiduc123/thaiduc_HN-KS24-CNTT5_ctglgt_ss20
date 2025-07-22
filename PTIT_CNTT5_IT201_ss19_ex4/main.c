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
    node->data;
    preorder(node->left);
    preorder(node->right);
}

void countLeaves(Node *node, int *count) {
    if (node == NULL) {
        return;
    }
    if (node->left == NULL && node->right == NULL) {
        (*count)++;
    }
    countLeaves(node->left, count);
    countLeaves(node->right, count);
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
    int number = 0;
    countLeaves(node1, &number);
    printf("So nut la: %d\n", number);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    return 0;
}