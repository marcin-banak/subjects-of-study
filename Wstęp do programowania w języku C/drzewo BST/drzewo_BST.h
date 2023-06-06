#ifndef DRZEWO_BST_H_INCLUDED
#define DRZEWO_BST_H_INCLUDED
#include <stdbool.h>

struct node
{
    int val;
    struct node *right;
    struct node *left;
};
// C
struct node* search(struct node*, int);
struct node* new_node(int);
struct node* insert(struct node*, int);
struct node* find_minimum(struct node*);
struct node* find_maximum(struct node*);
struct node* higher_node(struct node*, struct node*);
struct node* delete_node(struct node*, int);
void printBST(struct node*, int);
// WDI
void count_nodes(struct node*, int*); // podpunkt 2
void find_height(struct node*, int*, int); // podpunkt 3
void CheckTree(struct node*, bool*); // podpunkt 5
void JoinTrees(struct node*, struct node*); // podpunkt 6
void InsertIter(struct node*, int); // podpunkt 7

#endif