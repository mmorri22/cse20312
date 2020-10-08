#ifndef SORDLLIST_H
#define SORDLLIST_H

#include<string>
#include<iostream>

#include"DLList.h"

template<typename T>
class SorDLList: public DLList<T>{
	
    public:
	
        SorDLList():DLList<T>(){}
		
        ~SorDLList(){}
		
        void Insert (T value){
            typename DLList<T>::node* temp = new typename DLList<T>::node(value);
            if (this->IsEmpty()){
                this->head = temp;
                this->tail = temp;
            }
            else{
                typename DLList<T>::node* prev = NULL;
                typename DLList<T>::node* curr = this->head;
                /* traverse the list to find the correct location */
                while( curr->data < temp->data && curr != NULL ){
                    prev = curr;
                    if (prev->next != NULL){
                        curr = curr->next;
                    }
                    else{
                        curr = NULL;
                        break;
                    }
                }
                /* insert the node, temp, at the right location */
                /* the right location is between prev and curr */
                /* when temp is in the middle */
                if (curr != NULL){

                    // the condition where there is only one element
                    // and temp is inserted in front of that
                    if (curr == this->head){

                        this->head = temp;
                        temp->prev = NULL;
                        temp->next = curr;
                        curr->prev = temp;
                    }
                    else{
                        temp->next = curr; // set temp's next value
                        curr->prev = temp;
                        prev->next = temp;
                        temp->prev = prev;
                    }
                }
                // when temp is insert as the last one
                else{
                    prev->next = temp;
                    temp->prev = prev;
                    temp->next = NULL;
                    this->tail = temp;
                }
            }
        }

        friend std::ostream& operator << (std::ostream& output, const SorDLList<T> theSor){
            typename DLList<T>::node* curr;
            if (theSor.IsEmpty())
		   {
			  output << "The list is empty" << std::endl;;
		   }
		   else
		   {
			  /* set the current pointer to the first
			  ** node of the list */
			  curr = theSor.head;

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
};

#endif
