

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
  class array{
   	private:
		vector<T> myarray ; 

	public:
		
		array() {} 
        	array(int size , T value) : myarray(size , value ){}	
	void insert(T data)
	{
		myarray.push_back(data);
	}	
	void deleteArray(T data)
	{
		for(int i= 0 ; i< myarray.size() ; i++ )
		{
			if(myarray[i] == data)
			{
				myarray.erase(myarray.begin() + i ) ;
			}
		}

	}

	void travelarray(){
		for( auto& it : myarray)
		{
			cout<< it << " " ;
		}
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
  Solution<int>::array array1(1,4);
  array1.insert(1);
  array1.insert(2) ;
  array1.insert(3) ;
  array1.insert(5);
  array1.deleteArray(3) ;
  array1.travelarray() ; 
  
  
  return 0;

}
