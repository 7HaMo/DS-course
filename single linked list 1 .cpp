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
    int improve_search(int val)
    {
      int ind=0;
      for(Node* cur=head,*prv=nullptr;cur;prv=cur,cur=cur->next)
      {
        
        if(cur->data==val)
        if(!prv)
        return ind;
        else
        {
        swap(prv->data,cur->data);
        return ind-1;
        }
        ++ind ;
      }
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
    Node* get_back(int n)
    {
      int count=lenght;
      
      for(Node* cur=head;cur;cur=cur->next)                //problem four
      {
        if(count==1&&n==1)
        return head;
        else if(n==1)
        return tail;                                                        //four
        else if(count==n)                       //o(n)time
        return cur;                             //o(1)space
        count--;
      }
      return nullptr;
    }
    bool Is_same(const liked_list& other)
    { 
      if (lenght==other.lenght&&lenght==0)
      return true;
      else if(lenght==other.lenght)
     {                                                        //problem five
      Node* temp_other=other.head;//
      for(Node*cur =head;cur;cur=cur->next)
      {
        if(cur->data!=temp_other->data)
          return false;
        temp_other=temp_other->next;
      }
          return true;;
     }
      else
      return false;
}
    void add_element(int val){
    Node* newnode=new Node(val);
    if(head==nullptr)
    {
     head=newnode;
     newnode->next=nullptr;
    }                                     // problem six part one 
    else
    {
     newnode->next=head;
     head=newnode;
    }
}
    Node* Get_tail()
    {
      if (head==nullptr)
      return nullptr;
      Node* cur=head;
      while (cur->next!=nullptr)
      {                                        // problem six part two
        cur=cur->next;
      }
      return cur;
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
};
int main()
{
 liked_list l1;
 liked_list l2;
 l1.insert_end(7);
 l1.insert_end(6);
 l2.insert_end(7);
 l2.insert_end(6);
 cout <<l1.Is_same(l2)<<"\n";  // true
 l1.insert_front(2);
 l1.insert_front(1);  
 l1.print();           // 1 2 7 6 
 l1.delete_front();
 l1.print();           // 2 7 6  
 Node* res=l1.get_back(2);
 if(res==nullptr)
 cout<<"error:the indext not valid\n";
 else 
 cout << res->data<<"\n";   // 7
 l1.add_element(1);
 l1.print();                // 1 2 7 6 
 Node* res2=l1.Get_tail();  
 if(res2==nullptr)
 cout<<"NULL:the list is empty\n";
 else 
 cout << res2->data<<"\n";    // 6      
  return 0;
}