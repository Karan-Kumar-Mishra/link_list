#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

class node
{
public:
    int info;
    node *next;
};
node* creat()
{
    node *ptr= new node;
    return ptr;
}
void display(node *head)
{
    while(head!=NULL)
    {
        cout<<"data is=>"<<head->info<<endl;
        head=head->next;
    }
    getch();
}
node* removeat_index(node *head,int index)
{
    node *ptr=head;
    while(ptr->info!=index)
    {
     ptr=ptr->next;
    }
    ptr=ptr->next;
    return head;

}
node* remove_after(node *head,int key)
{
  node *ptr= head;
  node *p2=ptr->next;
  while(p2->info!=key)
  {
    ptr=ptr->next;
    p2=p2->next;
  } 
  p2->next=ptr->next;
  delete ptr;
    return head;
}
node* removeat_last(node *head)
{
    node *p1,*p2;
    p1=head;
    p2=head->next;
    while(p2->next!=NULL)
    {
        p1=p1->next;
        p2=p2->next;
    }
    p1->next=NULL;
    delete p2;
    return head;
}
node* removeat_first(node *head)
{
  node *ptr= head->next;
  delete head;
  return ptr;
  
}
node* insertat_first(node *head,int data)
{
    node *a1=new node;
    a1->info=data;
    a1->next=head;
    return a1;
}
void insertat_last(node *head,int data)
{
    node *s1=head;
    while(s1->next!=NULL)
    {
        s1=s1->next;
    }

    node *a1=new node;
    s1->next=a1;
    a1->info=data;
    a1->next=NULL;

}
void insert_after(node *head,node *prevnode,int data)
{
    node *a1=new node;
    a1->info=data;
    a1->next=prevnode->next;
    prevnode->next=a1;

}
void insertat_index(node *head,int index,int data)
{
    node *p1,*p2;
    p1=head;

    while(p1->info!=index)
    {
        p1=p1->next;

    }
    p1->info=data;

}
node* searchnode(node *head,int key)
{
    node *ptr= head;
    while(ptr->info!=key)
    {
        ptr=ptr->next;
    }
    return ptr;
}
int main()
{
    node *head=NULL,*ptr;
    ptr=creat();
    ptr->info=00;
    head=ptr;
    
    int cmd,data1,data2,data3,data4,index,index_data1,index_data2;
    int index2;
    while(1)
    {
        clrscr();
        cout<<"1.insert at start "<<endl;
        cout<<"2.insert at index "<<endl;
        cout<<"3.insert at last "<<endl;
        cout<<"4.remove at start"<<endl;
        cout<<"5.remove at index"<<endl;
        cout<<"6.remove at last"<<endl;
        cout<<"7.display"<<endl;
        cout<<"8.exit"<<endl;
        cout<<"enter the command=>"<<endl;
        cin>>cmd;
        switch(cmd)
        {
        case 1:
            cout<<"enter the data=>"<<endl;
            cin>>data1;
            head=insertat_first(head,data1);
            break;
        case 2:
            cout<<"enter the data=>"<<endl;
            cin>>data2;
            cout<<"enter the index's data=>"<<endl;
            cin>>index_data1;
            insertat_index(head,index_data1,data2);
            break;
        case 3:
            cout<<"enter the data =>"<<endl;
            cin>>data4;
            insertat_last(head, data4);
            break;
        case 4:
            head=removeat_first(head);
            break;
        case 5:
            cout<<"enter the index=>"<<endl;
            cin>>index;
            removeat_index(head,index);
            break;
        case 6:
            removeat_last(head);
            break;
        case 7:
            display(head);
            break;
        case 8:
            return 0;
            break;
        default:
            cout<<"comman is not found"<<endl;
            break;
        }
        getch();
    }
    return 0;
}
    