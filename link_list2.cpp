#include<iostream>
#include<stdio.h>
using namespace std;
class node
{
public:
    int info;
    node *next;
};
node *create(int data)
{
    node *ptr= new node;
    ptr->info=data;
    ptr->next=NULL;
    return ptr;
}
void display(node *head)
{
    node *ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->info<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL";
}
void insert_at(node *head,int key,int data)
{
    node *ptr=head;
    while(ptr->info!=key)
    {
        ptr=ptr->next;
    }
    node *pnew=create(data);
    pnew->next=ptr->next;
    ptr->next=pnew;
}
node *insert_start(node *head,int data)
{
    node *pnew=create(data);
    pnew->next=head;
    node *newhead;
    newhead=pnew;
    return newhead;
}
node *reverse_list(node *head)
{
    node *prev=NULL;
    node *curr=head->next;
    node *next;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
node *reverse(node *head)
{
//Using recursion
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node *newhead= reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
node *reversek(node *head,int k)
{
    node *prev=NULL;
    node *curr=head;
    node *next;
    int count=0;
    while(count<k and curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL)
    {
        head->next=reversek(next,k);
    }
    return prev;
}
void make_cycle(node *head,int pos)
{
    node *temp=head;
    int count=1;
    node *startnode;
    while(temp->next!=NULL)
    {
        if(count==pos)
        {
            startnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}
bool dectect_cycle(node *head)
{
    node *fast=head;
    node *slow=head;
    while(fast!=NULL and fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return true;
        }

    }
    return false;
}
void remove_cycle(node *head)
{
    node* slow =head;
    node* fast =head;
    do {
        slow=slow->next;
        fast=fast->next->next;
    } while(slow!=fast);

    fast=head;
    while(slow->next!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}
int main()
{
    node *head,*p1,*p2,*p3;
    p1=create(10);
    p2=create(20);
    p3=create(30);
    head=p1;
    p1->next=p2;
    p2->next=p3;
    p3->next=NULL;
    display(head);
    /*  insert_at(head,30,99);
        cout<<endl;
        display(head);
        head=insert_start(head,88);
        cout<<endl;
        display(head);
        cout<<endl;
        head=reverse(head);
        display(head);
        cout<<endl;
        head=reversek(head,2);
        display(head);
        */
    //make_cycle(head,2);
    //display(head);
    cout<<endl;
    cout<<"cycle in list => "<<dectect_cycle(head);
    make_cycle(head,2);
    cout<<endl;
    cout<<"cycle in list => "<<dectect_cycle(head);
    cout<<endl;
    remove_cycle(head);
    cout<<endl;
    cout<<"cycle in list => "<<dectect_cycle(head);
    cout<<endl<<"After remove the cycle"<<endl;
    display(head);
    return 0;
}
