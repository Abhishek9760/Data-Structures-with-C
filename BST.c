#include <stdio.h>
#include <math.h>

int fact(int n)
{
    if (n == 1)
        return 1;
    return n * fact(n - 1);
};

int combo(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
};

int maxUnlabelledTrees(int nodes)
{
    // MAX NO. OF TREES POSSIBLE WITH GIVEN NODES(UNLABELLED)
    return combo(2 * nodes, nodes) / (nodes + 1);
};

int maxHeightTrees(int nodes)
{
    // NO. OF MAX HEIGHT TREES POSSIBLE WITH GIVEN NODES(UNLABELLED)
    return (int)pow(2, nodes - 1);
};

int maxLabelledTrees(int nodes)
{
    // MAX NO. OF TREES POSSIBLE WITH GIVEN NODES(ABELLED)
    return maxUnlabelledTrees(nodes) * fact(nodes);
};

int minNodes(int height)
{
    // MINIMUM NO. OF NODES WITH GIVEN HEIGHT
    return height + 1;
};

int maxNodes(int height)
{
    // MAXIMUM NO. OF NODES WITH GIVEN HEIGHT
    return (int)pow(2, height + 1) - 1;
};

int maxHeight(int nodes)
{
    // MAXIMUM HEIGHT WITH GIVEN NODES
    return nodes - 1;
};

int minHeight(int nodes)
{
    // MINIMUM HEIGHT WITH GIVEN NODES
    return (int)log2(nodes + 1) - 1;
};

int main()
{
    int n;
    printf("Enter no. of nodes :");
    scanf("%d", &n);
    printf("%d", minHeight(n));
};