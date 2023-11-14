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

void addTree(Node *node, char value)
{
    if (node->left == NULL)
    {
        Node leftNode = {value, NULL, NULL};
        node->left = &leftNode;
        return;
    }

    if (node->right == NULL)
    {
        Node rightNode = {value, NULL, NULL};
        node->right = &rightNode;
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
    int i;
    char value;
    char rootValue;
    Node *currentNode;

    presentNodes = 0;

    p("Number of levels: \n");
    s("%i", &numberOfLevels);

    nodes = getNumberOfNodes(numberOfLevels);
    p("Number of nodes: %i\n", nodes);

    Node root = {'a', NULL, NULL};
    currentNode = &root;
    presentNodes++;

    while (presentNodes <= nodes)
    {
        addTree(currentNode, 'b');
        presentNodes++;
    }

    p("Expected to be b: %c", root.right->value);
}