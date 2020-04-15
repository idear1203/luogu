#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 30

typedef struct TreeNode
{
    struct TreeNode* left;
    struct TreeNode* right;
    char label;
} TREENODE;

void getResult(char* preorder, char* inorder);
TREENODE* createTree(char* preorder, char* inorder, int ps, int pe, int is, int ie);
int findInOrder(char* inorder, int start, int end, char target);
void postOrderTraverse(TREENODE* root);
void helper(char* preorder, char* inorder, int ps, int pe, int is, int ie);

void getResult(char* preorder, char* inorder)
{
    int n = strlen(preorder);
    helper(preorder, inorder, 0, n - 1, 0, n - 1);
    printf("\n");
}

void helper(char* preorder, char* inorder, int ps, int pe, int is, int ie)
{
    if (ps > pe)
    {
        return;
    }
    else
    {
        char target = preorder[ps];
        int idx = findInOrder(inorder, is, ie, target);
        helper(preorder, inorder, ps + 1, ps + idx - is, is, idx - 1);
        helper(preorder, inorder, ps + idx - is + 1, pe, idx + 1, ie);
        printf("%c", target);
    }
}

void getResult1(char* preorder, char* inorder)
{
    int n = strlen(preorder);
    TREENODE* root = createTree(preorder, inorder, 0, n - 1, 0, n - 1);
    postOrderTraverse(root);
    printf("\n");
}

TREENODE* createTree(char* preorder, char* inorder, int ps, int pe, int is, int ie)
{
    if (ps > pe)
    {
        return NULL;
    }

    TREENODE* node = (TREENODE*)malloc(sizeof(TREENODE));
    node->label = preorder[ps];
    node->left = NULL;
    node->right = NULL;
    if (ps < pe)
    {
        int idx = findInOrder(inorder, is, ie, node->label);
        node->left = createTree(preorder, inorder, ps + 1, ps + idx - is, is, idx - 1);
        node->right = createTree(preorder, inorder, ps + idx - is + 1, pe, idx + 1, ie);
    }

    return node;
}

int findInOrder(char* inorder, int start, int end, char target)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == target)
        {
            return i;
        }
    }

    return -1;
}

void postOrderTraverse(TREENODE* root)
{
    if (root == NULL)
    {
        return;
    }

    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    printf("%c", root->label);
}

int main()
{
    char preorder[SIZE] = { '\0' };
    char inorder[SIZE] = { '\0' };
    scanf("%s", inorder);
    scanf("%s", preorder);
    getResult(preorder, inorder);
    return 0;
}
