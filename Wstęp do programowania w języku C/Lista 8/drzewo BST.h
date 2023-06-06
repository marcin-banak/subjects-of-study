#ifndef DRZEWO_BST_H_INCLUDED
#define DRZEWO_BST_H_INCLUDED

struct node
{
    int val;
    struct node *right;
    struct node *left;
};
struct node* search(struct node*, int);
struct node* new_node(int);
struct node* insert(struct node*, int);
struct node* find_minimum(struct node*);
struct node* find_maximum(struct node*);
struct node* higher_node(struct node*, struct node*);
struct node* delete_node(struct node*, int);
void printBST(struct node*, int);

#endif
