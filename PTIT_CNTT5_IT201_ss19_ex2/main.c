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

typedef struct QueueNode {
    Node *treeNode;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, Node *treeNode) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

Node *dequeue(Queue *q) {
    if (isEmpty(q)) return NULL;
    QueueNode *temp = q->front;
    Node *treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return treeNode;
}

Node *createNode(int value) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("cap phat o nho khong thanh cong!");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}
void preorder(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
}

int main() {
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printf("Duyet cay theo inorder \n");
    inorder(root);
    printf("\nDuyet cay theo preorder \n");
    preorder(root);
    printf("\nDuyet cay theo postorder \n");
    postorder(root);
    printf("\nDuyet cay theo BFS\n");
    Queue q;
    initQueue(&q);
    enqueue(&q, root);
    while (!isEmpty(&q)) {
        Node *current = dequeue(&q);
        printf("%d ", current->data);
        if (current->left != NULL) {
            enqueue(&q, current->left);
        }
        if (current->right != NULL) {
            enqueue(&q, current->right);
        }
    }
    return 0;
}

