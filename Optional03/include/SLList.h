/**********************************************
* File: SLList.h
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file contains the function definitions and 
* structs for a Linked List Data structure 
**********************************************/

#ifndef SLLIST_H
#define SLLIST_H

#include "SLLNode.h"

template<class T>
class SLList{
	
	private:
	
		bool reorderList(node<T>* endOfList, node<T>*& beginList){
			
			bool reachedEnd = false;
			
			if( endOfList->next != NULL ){
				reachedEnd = reorderList( endOfList->next, beginList );
			}
			
			if( reachedEnd == false ){ 
			
				// Create the temp 
				node<T>* beginNext = beginList->next;
				node<T>* tempEnd = endOfList;
				
				// Reached the termination 
				if( tempEnd == beginList || tempEnd == beginList->next ){
					
					tempEnd->next = NULL;
					return true;
					
				}
				else{
					
					tempEnd->next = beginNext;
					beginList->next = tempEnd;
					
					beginList = beginNext;
					return false;
				}
			}
			else{
				
				return true;
			}
		}
		
		node<T>* head;	// Head pointer for Singly-Linked List
		
	public:
	
		/********************************************
		* Function Name  : SLList
		* Pre-conditions : none
		* Post-conditions: none
		* 
		* SLList Default Constructor 
		********************************************/
		SLList() : head(NULL) {}
		
		
		/********************************************
		* Function Name  : ~SLList
		* Pre-conditions : none
		* Post-conditions: none
		* 
		* Singly Linked List Destructor 
		********************************************/
		~SLList(){
			
			/*node* prev = NULL;
			node* curr = head;
				
			while(curr != NULL){
					
				prev = curr;
				curr = curr->next;
					
				delete prev;
			}*/
			delete head;
			
		}
		
		
		/********************************************
		* Function Name  : SLList
		* Pre-conditions : const SLList<T>& copy
		* Post-conditions: none
		* 
		* Copy Constructor for Singly Linked List 
		********************************************/
		SLList(const SLList<T>& copy) : head(NULL) {
			
			node<T>* curr = copy.head;
			
			while(curr != NULL){
				
				Insert(curr->data);
					
				curr = curr->next;
				
			}

		}
	
		/********************************************
		* Function Name  : operator=
		* Pre-conditions : const SLList<T>& assign
		* Post-conditions: SLList<T>&
		* 
		* Assignment Operator for Singly Linked List 
		********************************************/
		SLList<T>& operator=(const SLList<T>& assign){
				
			if(this != &assign){
				
				node<T>* curr = assign.head;
				
				while(curr != NULL){
					
					this->Insert(curr->data);
						
					curr = curr->next;
					
				}
			}
			return *this;
			
		}

		/********************************************
		* Function Name  : Insert
		* Pre-conditions : int value
		* Post-conditions: void   
		* 
		* Creates a Node with value, and inserts at 
		* the end of the Singly Linked List
		********************************************/
		void Insert (T value)
		{
		   node<T>* temp = new node<T>(value);

		   if ( IsEmpty() )
		   {
			   head = temp;
		   }
		   else
		   {
			  node<T>* prev =  NULL;
			  node<T>* curr = head;

			  /* traverse the list until the end */
			  while (curr != NULL)
			  {
				 prev = curr;
				 curr = curr->next;
			  }
		  
			  /* insert the node, temp, at the end */
			  prev -> next = temp;
		   }
		}
		
		
		/********************************************
		* Function Name  : push_front
		* Pre-conditions : T value
		* Post-conditions: none
		* 
		* Puts the element at the front
		* For O(1) insert time
		********************************************/
		void push_front(T value){
			
			// Create new node
			node<T>* temp = new node<T>(value);
			
			// Set temp->next = head
			temp -> next = head;
			
			// Set head equal to temp
			head = temp;
			
		}


		/********************************************
		* Function Name  : Delete
		* Pre-conditions : int data
		* Post-conditions: int    
		*  
		* Delets the first instance of data. Returns -1 
		* if not found
		********************************************/
		bool Delete (T target)
		{
		   node<T>* temp = new node<T>(); 
		   node<T>* prev = new node<T>(); 
		   node<T>* curr = new node<T>();

		   if (IsEmpty ())
		   {
			  std::cout << "Can't delete from an empty list" << std::endl;
			  return (-1);
		   }

		   /* if the target value is the first in the list, move head */
		   else if (target == head -> data)
		   {
			  temp = head;
			  head = head -> next;
			  free (temp);
			  return true;
		   }
		   
		   /* traverse the list until the target value is found */
		   else
		   {
			  prev = head;
			  curr = head -> next;

			  while (curr != NULL && curr -> data != target)
			  {
				 prev = curr;
				 curr = curr -> next;
			  }
			  
			  if(curr != NULL)
			  {
				/* delete the node the contains the target value */
				temp = curr;
				prev -> next = curr -> next;
				free(temp);
				return true;
			  }
			  else
			  {
				std::cout << target << " was not in the list" << std::endl;
				return false;
			  }
		   }      
		}


		/********************************************
		* Function Name  : IsEmpty
		* Pre-conditions : node* head
		* Post-conditions: int    
		* 
		* Bool returns if the list contains values
		********************************************/
		bool IsEmpty () const{
			
			return head == NULL;
		   
		}
		
		
		/********************************************
		* Function Name  : contains
		* Pre-conditions : const T& searchVal
		* Post-conditions: bool
		* 
		* Returns whether the list contains the element 
		********************************************/
		bool contains(const T& searchVal) const{

		   if (IsEmpty()) {
			   
			  return false;
			  
			}
			else{
				
				node<T>* prev =  NULL;
				node<T>* curr = head;
				
				while (curr != NULL && curr -> data != searchVal){
					prev = curr;
					curr = curr -> next;
				}

				return curr != NULL;
			}
		}


		/********************************************
		* Function Name  : operator<<
		* Pre-conditions : std::ostream& output, const SLList<T>& theList 
		* Post-conditions: std::ostream&
		* 
		* Overloaded friend ostream operator for SLList 
		********************************************/
		friend std::ostream& operator<<( std::ostream& output, const SLList<T>& theList ){
			
		   node<T>* curr;

		   if (theList.IsEmpty())
		   {
			  output << "The list is empty" << std::endl;;
		   }
		   else
		   {
			  /* set the current pointer to the first
			  ** node of the list */
			  curr = theList.head;

			  /* Until the end of the list */
			  while (curr != NULL)
			  {
				  /* print the current data item */
				  output << curr->data << " ";

				  /* move to the next node */
				  curr = curr -> next;
			  }
		   } 

		   return output;
		}
		
		void reorderList() {
			
			// Start both pointers at the head node
			node<T>* endOfList = head;
			node<T>* beginList = head;
			
			reorderList( endOfList, beginList );
		}

};

#endif
