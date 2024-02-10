#include <bits/stdc++.h>
using namespace std;
class Vector
{
    private:
    int size=0;        // user used
    int capacity=0;    // all size of array
    int* arr=nullptr;
    public:
    Vector(int size):size(size)
    {
        capacity=size+10;
       arr = new int[capacity];
    }
    void set(int index,int value)
    {
         arr[index]=value;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout <<"\n";
        
    }
    void push_back(int item)
    {
        if(capacity==size)                  // good solution
          expante();
        arr[size++]=item;
    }
    void expante()
    {
       capacity*=2;
       int* arr2=new int[capacity];            
       for (int i = 0; i < size; i++)
       {
         arr2[i]=arr[i];                
       }           
       swap(arr,arr2);   
       delete[]arr2;
      
    }
void insert (int index,int val)
{
    if (size==capacity)
     expante();
     for (int i = size-1; i>= index; --i)
     {
        arr[i+1]=arr[i];
     }
     arr[index]=val;
     ++size; 
}
void right_rotion()                                  // one problem 
{
    int last_element=arr[size-1];
    for (int i = size-1; i > 0; --i)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=last_element;
}
void right_rotion_steps(int time)                          // three problem 
{
    time%=size;

    while(time--)
    right_rotion();
}
void lift_rotuion()
{
    int first_element=arr[0];
    for (int i = 0; i < size-1; i++)                    // two problem
    {
        arr[i]=arr[i+1];
    }
    arr[size-1]=first_element;
}
int pop(int ind)
{
    int val=arr[ind];    
    for (int i = ind; i < size-1; i++)                   // four problem
    {
       arr[i]=arr[i+1];
    }
    size --;
  return val;
}
int find_transpostion(int val)
{
    for (int i=0;i<size-1;++i)                              //five problem
       if(arr[i]==val)                         
       {
         if(i==0)
        return 0; 
        swap(arr[i],arr[i-1]);
        return i-1;
        }
        return -1;
}
};
int main(){
   Vector v1(5);
   for (size_t i = 0; i<5; i++)
   {
    v1.set(i,i);
   }
v1.print();                          // 0 1 2 3 4  
v1.right_rotion();   
v1.print();                          // 4 0 1 2 3 
v1.insert(2,8);   
v1.print();                          // 4 0 8 1 2 3
v1.lift_rotuion();     
v1.print();                          // 0 8 1 2 3 4
v1.right_rotion_steps(3);      
v1.print();                          // 2 3 4 0 8 1
int index=v1.find_transpostion(3);   
v1.print();                          // 3 2 4 0 8 1
cout<<index;                         // 3 ==> index[0]
    return 0;
}