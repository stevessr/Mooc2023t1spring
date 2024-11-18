#include <stdio.h>
#include <string.h>

void getPostOrder(char *pre, char *in, int preStart, int inStart, int length)
{
    if (length <= 0)
        return;
    char root = pre[preStart];
    int rootIndex = -1;
    for (int i = inStart; i < inStart + length; i++)
    {
        if (in[i] == root)
        {
            rootIndex = i;
            break;
        }
    }
    int leftLength = rootIndex - inStart;
    getPostOrder(pre, in, preStart + 1, inStart, leftLength);
    int rightLength = length - leftLength - 1;
    getPostOrder(pre, in, preStart + leftLength + 1, rootIndex + 1, rightLength);
    printf("%c", root);
}

int main()
{
    char preOrder[200], inOrder[200];
    scanf("%s", preOrder);
    scanf("%s", inOrder);
    int length = strlen(preOrder);
    getPostOrder(preOrder, inOrder, 0, 0, length);
    printf("\n");
    return 0;
}
