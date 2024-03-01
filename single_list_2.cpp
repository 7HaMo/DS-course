#include <bits/stdc++.h>
using namespace std;
struct Node 
{
    int data=0;
    Node* next=nullptr;
    Node(int data):data(data){}
};
class liked_list
{
    private:
    Node* head=nullptr;
    Node* tail=nullptr;
    int lenght=0;
   public:
    void print()
   {
    for(Node* cur=head;cur!=nullptr;cur=cur->next)
    {
        cout << cur->data <<" ";
    }
    cout << endl;
   } 
   Node*get_inth(int n)
   {
    int count=1;
    for(Node* cur=head;cur;cur=cur->next)
    {
      if(count==n)
      return cur;
      count++;
    }
    return nullptr;
   }
   void insert_end(int value)
   {
    Node* newnode=new Node(value);
    if(!head)
      head=tail=newnode;
    else
    {
     tail->next=newnode;
     tail=newnode;
     }
    lenght++;

   }
    Node* search(int val)
    {
      for(Node* cur=head;cur!=nullptr;cur=cur->next)
    {
       if(cur->data==val)
       return cur;
    }
    return nullptr;
    }
    Node* get(int number)
    {
      int count=1;
       for(Node* cur=head;cur!=nullptr;cur=cur->next)
    {
      if(count==number)
      return cur;
      count++;
    }
    return nullptr;
    }
    int search_index(int val)
    {
      int index=0;
      for(Node* cur=head;cur;cur=cur->next,index++)
      if(cur->data==val)
      return index;
      return -1;
    }
    void insert_front(int value)
    {
      Node* newnode=new Node(value);
      if(lenght==0)                           // problem tow
      head=newnode;
      else
      {
      newnode->next=head;
      head=newnode;
      }
      lenght++;
    }
    void delete_front()
    {
      if(lenght==0)
      return;                                     //problem three
      else if(lenght==1)
      {
      Node* cur=head=tail;         //two
      delete cur;
      head=tail=nullptr;
      }
      else
      {
        Node* cur=head;
        head=head->next;
        delete cur;
      }
      lenght--;
    }
 ~liked_list()
    {
      Node* cur=head;
      while (cur)
      {                                  //problem 0ne
        head=head->next;
        delete cur;
        cur=head;
      }
    } 
    void delete_end()
    {
        if(lenght==1)
        head=tail=nullptr;
        else
        {
            Node*cur=head;
            while (cur->next!=tail)
            {
                cur=cur->next;
            }
            delete cur->next;
            tail=cur;
            cur->next=nullptr;
            lenght--;
        }
    }
    //====================================== the problems answers=================================================
  void delete_next_node(Node*prv)
  {
    Node*to_delete=prv->next;
    bool is_tail=to_delete==tail;
    prv->next=prv->next->next;
    delete to_delete;
    if(is_tail)
    tail=prv;
  }
  void delete_node_with_key(int value)
  { 
    if(lenght==0)
    cout <<"the list is empty\n";
    else if(head->data==value)
     delete_front();
     else if(tail->data==value)
     delete_end();
     else 
     {                                                       
        for(Node*cur=head,*prv=nullptr;cur;prv=cur,cur=cur->next)
        {
            if(cur->data==value)
            {                                           //problem one
                delete_next_node(prv);             //o(n)time  o(1)memory
                lenght--;
                 break;
            }
        }
     }
  }
  void swap_pairs()
{
    if(lenght<2)
    return;
    else
    {
      for(Node*cur=head;cur&&cur->next;cur=cur->next)    //problem two
     {
        swap(cur->data,cur->next->data);               //o(n) time  o(1) memory
        cur=cur->next;
     }
    }
}
    void reverse()
    {
        if(lenght<2)
        return;
        else
        {
         tail=head;
         Node*prv=head;
         for( Node* cur=head->next;cur;)                   //problem three
              { 
                Node*next=cur->next;              
                cur->next=prv;                              //o(n)time   o(1)memory
                prv=cur;
                cur=next;
              }
         head=prv;
         tail->next=nullptr;
        }
    } 
  void delete_even_positions()
  {
    if(lenght<2)
    return;
    else 
    {                                                   //problem four
      for(Node*cur=head;cur;cur=cur->next)
        delete_next_node(cur);                          //o(n)time   o(1)memory
    }
  }
  void embed_after(Node* prv,int val)
  {
    Node*newnode=new Node(val);
    lenght++;
    newnode->next=prv->next;
    prv->next=newnode;
  }

  void insert_sorted(int value)
  {
    if(!lenght||value <= head->data)
    insert_front(value);
    else if(value>=tail->data)
    insert_end(value);
    else                                       //problem five         o(n)time  o(1)memory
    {
        for(Node*cur=head,*prv=nullptr;cur;prv=cur,cur=cur->next)
        {
            if(cur->data>=value)
           { 
            embed_after(prv,value);
            break;
           }
        }
    }
  }
};
int main()
{
 liked_list l1;
 l1.insert_end(5);
 l1.insert_end(6);
 l1.insert_end(8);
 l1.insert_end(9);
 l1.insert_end(3);
 l1.print();          // 5 6 8 9 3 
 l1.delete_node_with_key(8);
 l1.print();          // 5 6 9 3
 l1.swap_pairs();
 l1.print();          // 6 5 3 9 
 l1.reverse();
 l1.print();          // 9 3 5 6
 l1.delete_even_positions();
 l1.print();          // 9 5
 l1.insert_sorted(3);
 l1.print();          // 3 9 5
}
    
