#include<stdio.h>
#include<stdlib.h>
struct n
{
    int x;
    struct n * next;
};typedef struct n node;
void b(node *r)
{
    while (r != NULL)
    {
        printf("%d\n", r->x);
        r = r->next;
    }
    
}
void ekele(node *n, int a)
{
    while (n->next != NULL)
    {
        n=n->next;    
    }
    n->next= (node *)malloc(sizeof(node));
    n->next->x = a;
    n->next->next = NULL; 
    
}
int main(){ 
    node * root  ;
    root = (node *)malloc(sizeof(node));
    root->x = 31;
    root->next = NULL;
    node * iter;
    iter = root;
 
    
    for (int i = 0; i < 5; i++)
    {
        iter->next = (node *)malloc(sizeof(node));
        iter = iter->next;
        iter->x = i*10;
        iter->next = NULL;
    }
    b(root);
}
