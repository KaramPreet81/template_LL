#include<stdio.h>
#include<iostream>
#include "single.h"
#include "array.h"

int main(){
	Solution<int>::Linkedlist q1 ; 
	q1.InsertEnd(10) ; 
	q1.InsertEnd(12);
	q1.InsertEnd(15) ; 
	q1.InsertEnd(20) ; 
	q1.DelnodeAtend() ;
	q1.print() ;

	Solution<int>::MyArray qa1 ; 
	qa1.insert(10) ; 
	qa1.insert(20) ; 
	qa1.insert(30) ; 
	qa1.deque() ;
     
}
