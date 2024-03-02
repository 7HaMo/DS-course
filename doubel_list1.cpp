#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next=nullptr;
    Node* prv=nullptr;
    Node(int data):data(data){};
};
class D_linked_list
{
  private:
  Node* head=nullptr;
  Node* tail = nullptr;
  int length=0;
  public:
  void print_reversed()
  {
    for(Node*cur=tail;cur;cur=cur->prv)
    {
        cout<<cur->data<<" ";
    }
    cout<<endl;
  }
  void print()
  {
    for(Node*cur=head;cur;cur=cur->next)
        cout<<cur->data <<" ";
    cout<<endl;
  }
   void link(Node* first,Node* seconde)
  {
    if(first)
    first->next=seconde;
    if(seconde)
    seconde->prv=first;
  } 
  void insert_end(int value)
  {
    Node*newnode=new Node(value);
    length++;
    if(!head)
    head=tail=newnode;
    else
    {
        link(tail,newnode);
        tail=newnode;
    }
  }
  void insert_front(int value)
  {
    Node* newnode = new Node(value);
    length++;
    if(!head)
    head=tail=newnode;
    else
    {
        link(newnode,head);
        head=newnode;
    }
  }
  void embed(Node* befor,int item)
  {
    Node* newnode = new Node(item);
    length ++;
    Node* next_node=befor->next;
    link(befor,newnode);
    link(newnode,next_node);
  }
  void insert_sorted(int value)
  {
    if(!head || value <= head->data)
    insert_front(value);
    else if(tail->data<=value)
    insert_end(value);
    else
    {
        for(Node*cur=head;cur;cur=cur->next)
      {
        if(value<=cur->data)
        {
            embed(cur->prv,value);
            /*Node* newnode = new Node(value);
            length++;
             link(cur->prv,newnode);
            link(newnode,cur); */
            break;
        }
      }
    }
  }
  /* void delete_all_nodes_with_key(int value)
  {
    for(Node*cur=head;cur;cur=cur->next)
    {
        if(cur->data==value)
        {
            link(cur->prv,cur->next);
            delete cur;
            length --;
        }

    }
  } */
  void delete_front()
  {
    if(!head)
    return;
    else if(length==1)
    {
      Node*cur=head;
      delete cur;
      length--;
      head=tail=nullptr;
    }else
    {
      Node*cur=head;
      head=head->next;
      delete cur;
      length--;
      head->prv=nullptr;
    }
  }
  void delete_end()
  {
    if(!head)
    return;
    else if(length==1)
    {
      Node*cur=tail;
      delete cur;
      length--;
      head=tail=nullptr;
    }
    else
    {
      Node* cur =tail;
      tail=tail->prv;
      delete cur;
      length--;
      tail->next=nullptr;
    }
  }
  Node* delete_and_link(Node* cur)
  {
    Node* pr=cur->prv;
    link(cur->prv,cur->next);
    delete cur;
    return pr;
  }
  void delete_all_node_with_keys(int value)
  {
    if(!head)
    return;
    insert_front(-value);
      for(Node*cur=head;cur;)               //problem one
      {
        if(cur->data==value)
        {                                     //o(n)time   o(1)memory
          cur=delete_and_link(cur);
          if(!cur->next)
          tail=cur;
        }else
        cur=cur->next;
      }
  delete_front();
  }
  void delete_even_positions()
  {
    if(!head)
    return;                                                   //problem two
      for(Node*cur=head;cur&& cur->next;cur=cur->next)
      {                                                 //o(n)time   o(1)memory
        delete_and_link(cur->next);
       if(!cur->next)
       tail=cur;
       
      }
  }
  void delete_odd_positions()
  {
    if(!head)                                    //problem three
    return;
    else if(length==1)          //o(n)time   o(1)memory
    delete_front();
    else
    {
      insert_front(-5);
      delete_even_positions();
      delete_front();
    }
  }
 bool is_plindroma()
 {                                     //problem five
  Node* cur_tail=tail;                 //o(n)time  
  int len=length/2;                    //o(1)memory
  for(Node*cur=head;len;cur=cur->next,cur_tail=cur_tail->prv,--len)
  if(cur->data!=cur_tail->data)
  return false;
  return true;
 }
};

int main ()
{
    D_linked_list s1;
    s1.insert_end(6);
    s1.insert_end(10);
    s1.insert_end(3);
    s1.insert_end(6);
    s1.insert_end(5);
    s1.print();           // 5 6 3 10 6
    s1.delete_all_node_with_keys(6);
    s1.print();           // 10 3 5
    s1.delete_even_positions();
    s1.print();           // 10 5
    s1.delete_odd_positions();
    s1.print();           // 5
    s1.insert_front(1);
    s1.insert_front(5);
  cout << s1.is_plindroma(); // 5 1 5 ==>true
}
