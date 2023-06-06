#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "drzewo BST.h"

void help();
int COUNT = 10;

int main()
{
    /*struct node *root = new_node(13);     //kod testowy
    insert(root,5);
    insert(root,1);
    insert(root,15);
    insert(root,9);
    insert(root,7);
    insert(root,12);
    insert(root,30);
    insert(root,25);
    insert(root,40);
    insert(root, 45);
    insert(root, 42);*/

    bool running = true;
    struct node *root = NULL;
    while(running)
    {
        printf("Podaj komende: ");
        char command[7] = "";
        scanf("%s", command);

        if(strcmp(command, "ins") == 0)
        {
            int x;
            scanf("%d", &x);
            if(root == NULL)
                root = new_node(x);
            else if(search(root, x) != NULL)
                fprintf(stderr, "wartosc juz znajduje sie w drzewie.\n");
            else
                insert(root, x);
        }
        else if(strcmp(command, "del") == 0)
        {
            int x;
            scanf("%d", &x);
            root = delete_node(root, x);
        }
        else if(strcmp(command, "srch") == 0)
        {
            int x;
            scanf("%d", &x);
            if(search(root, x) == NULL)
                printf("NIE\n");
            else
                printf("TAK\n");
        }
        else if(strcmp(command, "min") == 0)
        {
            if(root == NULL)
                fprintf(stderr, "drzewo nie przechowuje zadnych wartosci.\n");
            else
                printf("%d\n", find_minimum(root)->val);
        }
        else if(strcmp(command, "max") == 0)
        {
            if(root == NULL)
                fprintf(stderr, "drzewo nie przechowuje zadnych wartosci.\n");
            else
                printf("%d\n", find_maximum(root)->val);
        }
        else if(strcmp(command, "prev") == 0)
        {
            int x;
            scanf("%d", &x);
            if(find_minimum(root)->val == x || root == NULL)
                fprintf(stderr, "w drzewie nie figuruje poprzednik dla wartosci %d.\n", x);
            else
            {
                struct node *temp_node = search(root,x);
                if(temp_node->left == NULL)
                {
                    struct node *curr_node = higher_node(root, temp_node);
                    while(curr_node->val > temp_node->val)
                        curr_node = higher_node(root, curr_node);
                    printf("%d\n", curr_node->val);
                }
                else
                    printf("%d\n", find_maximum(temp_node->left)->val);
            }
        }
        else if(strcmp(command, "next") == 0)
        {
            int x;
            scanf("%d", &x);
            if(find_maximum(root)->val == x)
                fprintf(stderr, "w drzewie nie figuruje nastepnik dla wartosci %d.\n", x);
            else
            {
                struct node *temp_node = search(root,x);
                if(temp_node->left == NULL)
                {
                    struct node *curr_node = higher_node(root, temp_node);
                    while(curr_node->val < temp_node->val)
                        curr_node = higher_node(root, curr_node);
                    printf("%d\n", curr_node->val);
                }
                else
                    printf("%d\n", find_minimum(temp_node->right)->val);
            }
        }
        else if(strcmp(command, "print") == 0)
            printBST(root, 0);
        else if(strcmp(command, "help") == 0)
            help();
        else if(strcmp(command,"quit") == 0)
            running = false;
        else
            fprintf(stderr, "niepoprawna komenda (wpisz help aby wyswitelic liste wszystkich komend)");
    }
    return 0;
}

// funkcjonalność drzewa
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
    else if(x>root->val)
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

//funkcjonalność programu
void help()
{
    printf("ins X\ndel X\nsrch X\nmax\nprev X\nnext X\nprint\n");
}
