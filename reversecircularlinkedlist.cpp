#include<iostream>
using namespace std;
//circular singly linked list

class node
{
     public:
     int data;
     node*next;
};

node*circular(int data)
{
     node*temp=new node();
     temp->data=data;
     temp->next=temp;
     
     return temp;
}

void insert_at_end(node**tail,int data)
{
     node*temp=new node();
     temp->data=data;
     
     temp->next=(*tail)->next;
     (*tail)->next=temp;
     *tail=temp;
}

void insert_at_begin(node**tail,int data)
{
     node*temp=new node();
     temp->data=data;
     
     temp->next=(*tail)->next;
     (*tail)->next=temp;
}

void reverse(node**tail)

{    node*head1=(*tail)->next;
     node*head=(*tail)->next;
     node*curr=NULL;
     node*temp=NULL;
     
     while(curr!=head)
     {
          curr=head->next;
          head->next=temp;
          temp=head;
          head=curr;
     }
     head->next=temp;
     *tail=temp;
     
     cout<<(*tail)->data;
}

int main()
{
     node*tail=new node();
     tail=circular(13);
     insert_at_end(&tail,20);
     insert_at_begin(&tail,2);
     insert_at_end(&tail,23);
     insert_at_end(&tail,45);
     insert_at_end(&tail,60);
     
     
     node*ptr=tail->next;
     do
     {
          cout<<ptr->data<<" ";
          ptr=ptr->next;
     }while(ptr!=tail->next);
     
     reverse(&tail);
     

}

