 #include<stdio.h>
 #include<iostream>


 template<typename T>
 class Nodesingle
  {
  public:
    T val;
    Nodesingle *next;

     Nodesingle() : val(NULL),next(NULL)  {};
  };

  template<typename T>
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
