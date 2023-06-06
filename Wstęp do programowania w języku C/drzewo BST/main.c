#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "drzewo_BST.h"
#include "drzewo_BST.c"

void help();

int main()
{
    struct node *root1 = new_node(13);     //kod testowy
    insert(root1, 5);
    insert(root1, 10);
    insert(root1, 15);
    insert(root1, 9);
    insert(root1, 7);
    insert(root1, 12);
    insert(root1, 30);
    insert(root1, 25);
    insert(root1, 40);
    insert(root1, 45);
    insert(root1, 42);
    struct node *root2 = new_node(76);
    InsertIter(root2, 1000);
    InsertIter(root2, 564);
    InsertIter(root2, 432);
    JoinTrees(root1, root2);
    printBST(root2, 0);

    /*bool running = true;
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
        else if(strcmp(command, "count") == 0)
        {
            int nodes = 0;
            count_nodes(root, &nodes);
            printf("%d\n", nodes);
        }
        else if(strcmp(command, "height") == 0)
        {
            int h = 0;
            find_height(root, &h, 0);
            printf("%d\n", h);
        }
        else if(strcmp(command, "print") == 0)
            printBST(root, 0);
        else if(strcmp(command, "help") == 0)
            help();
        else if(strcmp(command,"quit") == 0)
            running = false;
        else
            fprintf(stderr, "niepoprawna komenda (wpisz help aby wyswitelic liste wszystkich komend)\n");
    }*/
    return 0;
}

// funkcjonalność drzewa


//funkcjonalność programu
void help()
{
    printf("ins X\ndel X\nsrch X\nmax\nprev X\nnext X\ncount\nheight\nprint\nquit\n");
}
