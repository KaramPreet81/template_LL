

#include<vector>
#include <iostream>
#include <stdio.h>
using namespace std;
template <class T>
class Solution
{
  public:
  class Nodesingle
  {
  public:
    T val;
    Nodesingle *next;

     Nodesingle() : val(NULL),next(NULL)  {};
  };
  class Linkedlist
  {
  public:
    Nodesingle *head;
    Nodesingle *tail;

  Linkedlist() : head(NULL) , tail(NULL){} ;
   // insert at end 
    void InsertEnd(T data)
    {
      Nodesingle *temp = new Nodesingle;
      temp->val = data;
      if (!head)
	{
	  head = temp;
	  tail = temp;
	}
      else
	{
	  tail->next = temp;
	  tail = temp;
	}
    }
     // insert at begin 
     void Insertbegin(T data)
     {
         Nodesingle *temp = new Nodesingle ;
         temp->val = data ;
         if(!head)
         {
             head = temp ;
             tail = temp ;
         }
         else{
             temp->next = head ; 
             head = temp ; 
         }
     }
     
    // travelling the linked list 
    void print ()
    {
    Nodesingle *temp = head;
    while(temp)
	    {
	        cout << temp->val << " ";
	        temp = temp->next;
	    }

    }
    
    void DelnodeAtend()
    {
        Nodesingle* temp = head ; 
        if(head == tail )
        {
            head = NULL ;
            tail = NULL ;
        }
        else {
            while(temp->next != tail)
            {
                temp = temp->next ; 
            }
            temp->next = NULL ;
            tail = temp ; 
        }
    }
    void Delwithdata(T data)
    {
        Nodesingle* temp = head ;
        while(temp->next->val != data )
        {
            temp = temp->next ; 
        }
        Nodesingle *previous = temp ; 
        previous = temp ; 
        temp = temp->next ; 
        previous->next = temp->next ; 
        delete temp , previous ; 
    }
    bool isEmpty() {
        return head == nullptr;
    }

    T front() {
        if (isEmpty()) {
            throw std::runtime_error("Linked list is empty");
        }
        return head->val;
    }
    
  };
  class NodeDoubly{
    public:
        NodeDoubly* prev ;
        T val ; 
        NodeDoubly* next ; 
        
    NodeDoubly() : prev(NULL) ,val(NULL) , next(NULL) {};
    
 };
 
 class Dlinkedlist{
   public :
   NodeDoubly *head ; 
   NodeDoubly *tail  ;
   
   Dlinkedlist() : head(NULL), tail(NULL){} ;
   
   void insertendDLL(T data)
   {
       NodeDoubly* newnode = new NodeDoubly ;
       newnode->val = data ; 
       if(!head)
       {
           head = newnode ; 
           tail = newnode ; 
       }
       else{
           tail->next = newnode; 
           newnode->prev = tail ; 
           newnode->next = NULL ; 
           tail = newnode ; 
       }
   }
   void insertbeginDLL(T data){
       NodeDoubly* newnode = new NodeDoubly ;
       newnode->val = data ; 
       if(!head)
       {
           head = newnode ; 
           tail = newnode ; 
       }
       else{
         newnode->next = head ; 
         newnode->prev = tail ; 
         head->prev = newnode ; 
         head = newnode ; 
       }
   }
   void travelDLL()
   {
       NodeDoubly* temp = head ; 
       while(temp)
       {
           cout<<temp->val<< " " ;
           temp = temp->next ; 
        }
       
    }
    void deleteEndDLL()
    {
        NodeDoubly *temp = head ; 
        if(!head){
            head = NULL  ;
            tail = NULL ; 
        }
        else{
            while(temp->next != tail )
            {
                temp = temp->next ; 
            }
            temp->next = NULL ;
            tail->prev = NULL; 
            tail = temp ; 
        }
    }
   
 };
 
 class CircularLL{
      public:
      Nodesingle* head ; 
      Nodesingle* tail ;
      
      CircularLL() : head(NULL) , tail(NULL){} ;
      
      void InsertCLL(T data)
      {
          Nodesingle* newnode = new Nodesingle ;
          newnode->val = data ; 
          if(!head)
          {
           head = newnode ;
           newnode->next = newnode ; 
           head = newnode ; 
           tail = newnode ; 
         }
       else{
         newnode->next = head ; 
         tail->next = newnode ; 
         tail = newnode ; 
       }
      }
      
      void  Deleteatend()
      {
         Nodesingle *temp = head ; 
        if(!head){
            head = NULL ;
            tail = NULL ; 
        }
        else{
            while(temp->next != tail )
            {
                temp = temp->next ; 
            }
            temp->next = NULL ;
            tail = temp ; 
        } 
      }
        
        void printCLL()
        {
            Nodesingle* temp = head ;
            while(temp)
            {
                cout << temp->val << " " ;
                temp = temp->next ;
                if(temp == head)
                break ; 
            }
        }
    };
class MyArray {
private:
    T* data;
    int size;
    int capacity;

public:
    MyArray() : data(nullptr), size(0), capacity(0) {}

    MyArray(int initialCapacity) : data(new T[initialCapacity]), size(0), capacity(initialCapacity) {}

    ~MyArray() {
        delete[] data;
    }

    void insert(T value) {
        if (size == capacity) {
            // Double the capacity if the array is full
            int newCapacity = capacity == 0 ? 1 : capacity * 2;
            T* newData = new T[newCapacity];

            // Copy elements from the old array to the new array
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }

            // Delete the old array and update data and capacity
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }

        // Insert the new element and increase the size
        data[size] = value;
        ++size;
    }

    void remove(T value) {
        int index = -1;
        for (int i = 0; i < size; ++i) {
            if (data[i] == value) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            // Shift elements to the left to overwrite the removed element
            for (int i = index; i < size - 1; ++i) {
                data[i] = data[i + 1];
            }
            // Decrease the size after removing the element
            --size;
        }
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
    void pop() {
        if (size > 0) {
            --size;
        }
    }
    void deque()
    {
        int index = 0 ; 
        if(index < size)
        {
            cout << data[index] ; 
        }
        size--  ; 
    }
};

};





int main ()
{
  
  Solution<int>::Linkedlist list1;
  list1.InsertEnd(1);
  list1.InsertEnd(4);
  list1.InsertEnd(2);
  list1.InsertEnd(3);
  list1.Insertbegin(5);
  list1.Insertbegin(7);
  list1.DelnodeAtend();
  list1.Delwithdata(1) ;
  list1.print();
  cout<<endl ;

  Solution<int>::Dlinkedlist list2;
  list2.insertendDLL(3);
  list2.insertendDLL(4);
  list2.insertbeginDLL(1);
  list2.insertbeginDLL(2);
  list2.deleteEndDLL();
  list2.travelDLL() ;
  cout<<endl ;  
  Solution<int>::CircularLL list3;
  list3.InsertCLL(3);
  list3.InsertCLL(1);
  list3.InsertCLL(2);
  list3.InsertCLL(4);
  list3.Deleteatend();
  list3.printCLL() ;
 cout<< endl ; 

 Solution<int>::MyArray array1 ; 
 array1.insert(1) ; 
 array1.insert(4) ; 
 array1.insert(2) ; 
 array1.insert(3) ; 
 array1.remove(4) ; 
 array1.print() ; 

  
  
  return 0;

}
