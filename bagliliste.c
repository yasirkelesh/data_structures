#include<stdio.h>
#include<stdlib.h>
struct n
{
    int x;
    struct n * next;
};typedef struct n node;
void b(node *r)
{
    node * iter = r;
    printf("%d\n", iter->x);
    iter = iter->next;
    while (iter != r)
    {
        printf("%d\n", iter->x);
        iter = iter->next;
    }
    
}
node * ekleSirali(node * r, int x)
{
    if(r == NULL)
    {
        r = (node *)malloc(sizeof(node));
        r->next = NULL;
        r->x = x;
        return(r);
    }
    if(r->x > x)
    {
        node * temp = (node *)malloc(sizeof(node));
        temp->x = x;
        temp->next = r;
        return temp;
    }
    node * iter = r;
    while (iter->next != NULL && iter->next->x < x)
    {
        iter = iter->next;
    }
    node * temp = (node *)malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp ->x = x;
    return r;
     

}
node * ekle(node *n, int a)
{
    node *iter;
    iter = n; 
    if(iter == NULL)
    {
        iter->next= (node *)malloc(sizeof(node));
        iter->next->x = a;
        iter->next->next = n;
    
        return n;
    }

    while (iter->next != n)
    {
        iter=iter->next;    
    }
    iter->next= (node *)malloc(sizeof(node));
    iter->next->x = a;
    iter->next->next = n;
    return n;

    
}
int main(){ 
    node * root  ;
    root = NULL;
    root= ekle(root,12);
    root= ekle(root,123);
    root= ekle(root,45);
    root= ekle(root,14);
    root= ekle(root,32);
    b(root);
}