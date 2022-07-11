#include<stdio.h>
#include<stdlib.h>
struct n
{
    int x;
    struct n * next;
    struct n * prev;
    
};typedef struct n node;
void b(node *r)
{
    while (r != NULL)
    {
        printf("%d\n", r->x);
        r = r->next;
    }
    
}
node * ekleSirali(node * r, int x)
{
    if(r == NULL)//Linklist boşsa 
    {
        r = (node *)malloc(sizeof(node));
        r->next = NULL;
        r->prev = NULL;
        r->x = x;
        return(r);
    }
    if(r->x > x)//ilk elemandan küçükse
    {
        node * temp = (node *)malloc(sizeof(node));
        temp->x = x;
        temp->next = r;
        temp->prev = NULL;
        r->prev = temp;
        return temp;
    }
    node * iter = r;
    while (iter->next != NULL && iter->next->x < x)
    {
        iter = iter->next;
    }
    if(iter->next == NULL)
    {
        node * temp = (node *)malloc(sizeof(node));
        temp->next = NULL;
        temp->prev = iter;
        iter->next = temp;
        temp ->x = x;
        return r;
    }
    node * temp = (node *)malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->prev = iter;
    temp->next->prev = temp;
    temp ->x = x;
    return r;
     

}

node * ekele(node *n, int a)
{
    node * k;
    k = n;
    while (k->next != NULL)
    {
        k=k->next;    
    }
    k->next= (node *)malloc(sizeof(node));
    k->next->x = a;
    k->next->next = NULL; 
    return n;
    
}
node * sil(node *n, int a)
{
    node * r;
    node * s;
    r = n; 
    if(n->x == a)
    {
        s = n;
        n = n->next; 
        free(s);
        return n;
    }
    while(r->next->x != a && r->next != NULL)
            r=r->next;
    if(r->next == NULL)
            return n;

    s=r->next;
    r->next = r->next->next;
    if(r->next != NULL) 
        r->next->prev = r;
    free(s);
    return n;
}
int main(){ 
    node * root  ;
    root = NULL;
    root= ekleSirali(root,32);
    root= ekele(root,12);
    
    root= ekele(root,34);
    root= ekele(root,245);
    root= ekele(root,15);
    root= sil(root,15);
    root= ekele(root,14);
    root= sil(root,23);
     
    //root= ekleSirali(root,32);
    b(root);
    //root->x = 31;
    //root->next = NULL;
 
    
    /*for (int i = 0; i < 5; i++)
    {
        iter->next = (node *)malloc(sizeof(node));
        iter = iter->next;
        iter->x = i*10;
        iter->next = NULL;
    }
    //b(root);
    node * yaso;
    yaso = root;
    for(int i = 0; i<2; i++)
    {
        yaso=yaso->next;
    }
    node * temp;
    temp = (node *)malloc(sizeof(node));
    temp->x = 15;
    temp->next =yaso->next;
    yaso->next =temp;*/
   

}