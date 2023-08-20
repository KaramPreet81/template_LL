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

  tempalte<typename T>
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
 
 template<typename T>
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