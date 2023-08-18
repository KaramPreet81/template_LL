#include<stdio.h>
#include<iostream>
#include "single.h"

int main(){
	Solution<int>::Linkedlist q1 ; 
	q1.InsertEnd(10) ; 
	q1.InsertEnd(12);
	q1.InsertEnd(15) ; 
	q1.InsertEnd(20) ; 
	q1.DelnodeAtend() ;
	q1.print() ; 
}
