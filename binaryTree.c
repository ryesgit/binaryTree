#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define p printf
#define s scanf

typedef struct Node
{
    char value;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Queue
{
    Node *node;
    struct Queue *next;
} Queue;

void enqueue(Queue *queue, Node *node)
{
    Queue *currentQueue = queue;

    while (currentQueue->next != NULL)
    {
        currentQueue = currentQueue->next;
    }

    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->node = node;
    newQueue->next = NULL;
    currentQueue->next = newQueue;
}

Node *dequeue(Queue *queue)
{
    if (queue->next == NULL)
    {
        return NULL;
    }

    Queue *tempQueue = queue->next;
    Node *tempNode = tempQueue->node;

    queue->next = tempQueue->next;

    return tempNode;
}

void addTree(Node *node, char value)
{
    if (node->left == NULL)
    {
        Node *leftNode = (Node *)malloc(sizeof(Node));
        leftNode->value = value;
        leftNode->left = NULL;
        leftNode->right = NULL;
        node->left = leftNode;
        return;
    }

    if (node->right == NULL)
    {
        Node *rightNode = (Node *)malloc(sizeof(Node));
        rightNode->value = value;
        rightNode->left = NULL;
        rightNode->right = NULL;
        node->right = rightNode;
        return;
    }
}

int getNumberOfNodes(int numberOfLevels)
{

    int nodes;
    numberOfLevels--;

    if (numberOfLevels < 1)
    {
        nodes = pow(2, numberOfLevels);
    }

    else
    {
        nodes = pow(2, numberOfLevels + 1) - 1;
    }

    return nodes;
}

void writeToNode(Node *node)
{

    char value;

    s("%s", &value);

    node->value = value;
}

void main()
{
    int numberOfLevels;
    int nodes;
    int presentNodes;
    char value;
    char rootValue;
    Node *currentNode;

    presentNodes = 0;

    p("Number of levels: \n");
    s("%i", &numberOfLevels);

    nodes = getNumberOfNodes(numberOfLevels);
    p("Number of nodes: %i\n", nodes);

    Node root = {'a', NULL, NULL};
    Queue queue = {&root, NULL};
    currentNode = &root;
    presentNodes++;
    while (presentNodes <= nodes - 1)
    {
        if (currentNode->left == NULL || currentNode->right == NULL)
        {
            p("Value for node #%i", presentNodes);
            s("%s", &value);
            addTree(currentNode, value);
            presentNodes++;
            continue;
        }

        if (currentNode->left->left == NULL || currentNode->left->right == NULL)
        {
            p("Queuing left node\n");
            enqueue(&queue, currentNode->left);
        }

        if (currentNode->right->left == NULL || currentNode->right->right == NULL)
        {
            p("Queuing right node\n");
            enqueue(&queue, currentNode->right);
        }

        currentNode = dequeue(&queue);
    }

    Node rootRight = *(root.right);
    Node rootRightLeft = *(rootRight.left);
    p("Expected to be f: %c", rootRightLeft.value);
}