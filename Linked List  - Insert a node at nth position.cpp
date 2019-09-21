#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};

struct Node* head;
void print()
{
    struct Node* temp;
    temp = head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

void receursive_print(struct Node* temp)
{
     if(temp==NULL)
     {
         printf("\n");
         return;
     }
     printf("%d ",temp->data);
     receursive_print(temp->link);

}
void receursive_reverse_print(struct Node* temp)
{
     if(temp==NULL)
     {
         //printf("\n");
         return;
     }

     receursive_reverse_print(temp->link);
     printf("%d ",temp->data);
}
int lastButNotTheLeast()
{
    struct Node* temp;
    temp=head;
    if(temp == NULL || temp->link== NULL)
        return -1;
    while(temp!=NULL)
    {
        if(temp->link->link == NULL)
            return temp->data;

        temp=temp->link;

    }
}
void insert(int value, int pos)
{
    struct Node* temp1 = (struct Node*) malloc(sizeof(struct Node));
    temp1->data = value;
    if(pos==1){
        temp1->link = head;
        head = temp1;
        return;
    }
    struct Node* temp2;
    temp2 = head;
    for(int i=0; i<pos-2;i++)
    {
        temp2=temp2->link;
    }
    temp1->link = temp2->link;
    temp2->link = temp1;
}
void Delete(int pos)
{
    struct Node* temp1 = head;
    if(pos==1)
    {
        head=temp1->link;
        free(temp1);
        return;
    }
    int i;
    for(i=0;i<pos-2;i++)
    {
        temp1=temp1->link;
    }
    struct Node* temp2 = temp1->link;
    temp1->link = temp2->link;
    free(temp2);

}
void key_delete(int key)
{
    struct Node* temp = head;
    if(temp!=NULL && temp->data == key)
    {
        head = temp->link;
        free(temp);
        return;
    }
    struct Node* prev;
    if(temp==NULL){
        printf("Not possible\n");
        return;
    }

    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->link;
    }
    prev->link = temp->link;
    free(temp);
}
void reverse()
{
    struct Node *current,*prev, *next;
    current = head;
    prev = NULL;
    while(current!=NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void reverse_recursion(struct Node *p)
{
    if(p->link==NULL){
        head = p;
        return;
    }
    reverse_recursion(p->link);
    struct Node *q=p->link;
    q->link = p;
    p->link = NULL;

}
int main()
{
    head=NULL;
    insert(2,1);
    insert(3,2);
    insert(4,1);
    insert(5,3);
    insert(7,5);
    //print();
    receursive_print(head);
   // receursive_reverse_print(head);
    /*
    printf("%d\n",lastButNotTheLeast());
    Delete(1);
    print();
    printf("\n");
    Delete(3);
    print();
    printf("\n");
    key_delete(5);
    print();
    key_delete(7);
    print();
    key_delete(2);
    print();
    key_delete(7);
    print();
    */
    //reverse();
   // print();
    reverse_recursion(head);
    receursive_print(head);
    //print();
    return 0;
}
