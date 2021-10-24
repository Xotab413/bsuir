
#include "Functions.h"

int main()
{
    tree* root = NULL;
    menu(&root);
    treeDestroy(root);
    return 0;
}
