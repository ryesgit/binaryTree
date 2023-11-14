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

Node *initializeQueue()
{
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

    p("Number of levels: \n");
    s("%i", &numberOfLevels);

    nodes = getNumberOfNodes(numberOfLevels);
    p("Number of nodes: %i\n", nodes);
}