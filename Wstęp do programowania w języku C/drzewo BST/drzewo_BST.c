#include "drzewo_BST.h"
#include <stdlib.h>
#include <stdbool.h>
int COUNT = 10;

// zadania na C
struct node* new_node(int x) // tworzenie nowego wezla
{
    struct node *node;
    node = malloc(sizeof(struct node));
    node->val = x;
    node->left = NULL;
    node->right = NULL;

    return node;
}
struct node* search(struct node *root, int x) // szukanie wartosci w drzewie binarnym
{
    if(root==NULL || root->val==x)
        return root;
    else if(x>root->val)
        return search(root->right, x);
    else
        return search(root->left,x);
}
struct node* insert(struct node *root, int x)
{
    if(root==NULL)
        return new_node(x);
    else if(x > root->val)
        root->right = insert(root->right, x);
    else
        root->left = insert(root->left,x);
    return root;
}
struct node* find_minimum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left != NULL) // wezel z najmniejsza wartoscia nie bedzie mial lewego dziecka
        return find_minimum(root->left);
    return root;
}
struct node* find_maximum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->right != NULL) // wezel z najwieksza wartoscia nie bedzie mial prawego dziecka
        return find_maximum(root->right);
    return root;
}
struct node* higher_node(struct node *root, struct node *node)
{
    if(root->left == node || root->right == node)
        return root;
    if(root->val > node->val)
        return higher_node(root->left, node);
    else
        return higher_node(root->right, node);
}
struct node* delete_node(struct node *root, int x)
{
    // szukanie elementu do usuniecia
    if(root==NULL)
        return NULL;
    if (x>root->val)
        root->right = delete_node(root->right, x);
    else if(x<root->val)
        root->left = delete_node(root->left, x);
    else
    {
        // bezdzietny
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }

        // jedno dziecko
        else if(root->left==NULL || root->right==NULL)
        {
            struct node *temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }

        // dwoje dzieci
        else
        {
            struct node *temp = find_minimum(root->right);
            root->val = temp->val;
            root->right = delete_node(root->right, temp->val);
        }
    }
    return root;
}
void printBST(struct node *root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    printBST(root->right, space); // rekurencyjne wypisanie prawego poddrzewa
    printf("\n");

    for (int i = COUNT; i < space; i++) // usadowienie wezla na odpowiedniej pozycji
        printf(" ");
    printf("%d\n", root->val);

    printBST(root->left, space); // rekurencyjne wypisanie lewego poddrzewa
}

// zadania na WDI
void count_nodes(struct node *root, int *quantity)
{
    if (root == NULL)
        return;
    (*quantity)++;
    count_nodes(root->left, quantity);
    count_nodes(root->right, quantity);
}
void find_height(struct node *root, int *max_h, int curr_h)
{
    if (root == NULL)
    {
        if (*max_h < curr_h)
            *max_h = curr_h;
        return;
    }
    find_height(root->left, max_h, curr_h + 1);
    find_height(root->right, max_h, curr_h + 1);
}
void CheckTree(struct node *root, bool *valid)
{
    if (*valid == false)
        return;
    if (root->left->val >= root->val)
    {   
        *valid = false;
    }
    if (root->right->val <= root->val)
    {
        *valid = false;
    }
    CheckTree(root->left, valid);
    CheckTree(root->right, valid);
    return;
}
void JoinTrees(struct node *root1, struct node *root2)
{
    struct node *temp = root2;
    while (temp->left != NULL)
        temp = temp->left;
    temp->left = root1;
}
void InsertIter(struct node *root, int val)
{
    struct node *temp = root;
    while ((temp->left != NULL && val < temp->val) || (temp->right != NULL && val > temp->val))
    {
        if (val > temp->val)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    if (val > temp->val)
    {
        temp->right = new_node(val);
    }
    else
    {
        temp->left = new_node(val);
    }
}