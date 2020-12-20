#include<stdio.h>
#include<stdlib.h>//.h>

struct node
{
    int val;
    struct node *next;
};

struct node* make_new(int x)
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    n->val=x;
    n->next=NULL;
    return n;
}

void printt(struct node* st)
{
    struct node * s = st;
    while(s->next!=NULL)
    {
        printf("%d -> ", s->val);
        s=s->next;
    }
    printf("%d \n ", s->val);
}    
struct node* insertt(struct node* h, struct node* neww)
{
    struct node* val = h;
    while(val->next!=NULL)
        val=val->next;
    val->next=neww;
    return h; 
}

struct node* add(struct node* h ,int x)
{
    struct node* p = h;
    while(p->next!=NULL)
    {
        p->val+=6;
        p=p->next;
    }
    p->val+=6;
    return h;
}

void skip(struct node* st)
{
    struct node * s = st;
    while(s!=NULL)
    {
        printf("%d -> ", s->val);
        if(s->next==NULL)
            break;
        s=s->next->next;
    }
}   

int main()
{
    struct node* head; head =make_new(12); 
    struct node*n = make_new(24);
    insertt(head, n);
    n = make_new(33);
    insertt(head, n);
    n = make_new(40);
    insertt(head, n);
    n = make_new(57);
    insertt(head, n);
    n = make_new(68);
    insertt(head, n);
    n = make_new(77);
    insertt(head, n);
    printt(head);
    head = add(head,6);
    printt(head);     
    skip(head);
    return 0;
}