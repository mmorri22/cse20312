#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include "BST.h"

template< class T >
class SplayTree : public BST<T>{
	
	private:

		void Insert( BSTNode< T >*& currPtr, const T& value ){
			
			// If the pointer is Null, we found our location 
			// Set the pointer to the new value
			if( currPtr == NULL ){
				
				currPtr = new BSTNode< T >(value);
				return;
			}
			
			// If value is less than current data, recurse left
			else if( value < currPtr->data ){
				Insert( currPtr->left, value );
			}
			
			// If value is greater than current data, recurse right
			else if( value > currPtr->data ){
				Insert( currPtr->right, value );
			}
			else{
				// Print that we found a duplicate
				std::cout << value << " is a duplicate " << std::endl;
			}			
			
		}
	
		void splay( T& value, BSTNode<T>*& parent, BSTNode<T>*& grand){
				
			// Recursively Seek Location - Go Left
			if( parent->left != NULL && value < parent->data && value != parent->left->data ){
				splay( value, parent->left, parent);
			}
			
			// Recursively Seek Location - Go Right
			if( parent->right != NULL && value > parent->data && value != parent->right->data ){
				splay( value, parent->right, parent);
			}

			/* When recurse back up, we need to swap current and parent */
			/* Four cases */
			BSTNode<T>* tempPar = parent;
			BSTNode<T>* tempGrand = grand;
			
			// At this point the child to splay is either left, right, or doesn't exist			
			// First, let's consider the cases where the value is NOT in the tree
			if( (tempPar->left == NULL && value < tempPar->data) || 
				 (tempPar->right == NULL && value > tempPar->data) ){
				
				value = tempPar->data;
				return;
			}
			
			// Set the temporary child pointer 
			BSTNode<T>* tempChild;
			
			if( tempPar->data > value ){
				tempChild = tempPar->left;
			}
			else{
				tempChild = tempPar->right;
			}
			
			// Case 1: Zig-Zig Left 
			if( tempGrand->data > tempPar->data && tempPar->data > value ){

				tempPar->left = tempChild->right;
				tempGrand->left = tempPar->right;
				tempPar->right = tempGrand;
				tempChild->right = tempPar;
				
				grand = tempChild;
			}

			// Case 2: Zig-Zag Left 
			else if( tempGrand->data > tempPar->data && tempPar->data < value ){

				tempPar->right = tempChild->left;
				tempGrand->left = tempChild->right;
				tempChild->left = tempPar;
				tempChild->right = tempGrand;
				
				grand = tempChild;
			}

			// Case 3: Zig-Zig Right 
			else if( tempGrand->data < tempPar->data && tempPar->data < value ){

				tempPar->right = tempChild->left;
				tempGrand->right = tempPar->left;
				tempPar->left = tempGrand;
				tempChild->left = tempPar;
				grand = tempChild;

			}

			// Case 4: Zig-Zag Right 
			else if( tempGrand->data > tempPar->data && tempPar->data < value ){

				tempPar->left = tempChild->right;
				tempGrand->right = tempChild->left;
				tempChild->right = tempPar;
				tempChild->left = tempGrand;
				
				grand = tempChild;
			}				
		}
	
		// First Level for Zig
		void splay( BSTNode<T>*& curr, T& value ){
			
			// If value < curr->data and left node is null, then value is not in the tree
			if( value < curr->data && curr->left == NULL ){
				
				// We requested an element in the Splay that is smaller than the root and root->left is null 
				// This means the root should stay at the top. Do nothing 
				return;
				
			}
			else if( curr->data < value && curr->right == NULL ){
				
				// We requested an element in the Splay that is larger than the root and root->right is null 
				// This means the root should stay at the top. Do nothing 
				return;
				
			}
			else if( curr->left != NULL && curr->left->data == value ){
				
				// Zig Left 
				BSTNode<T>* tempPar = curr;
				BSTNode<T>* tempChild = curr->left;
				
				tempPar->left = tempChild->right;
				tempChild->right = tempPar;
				
				curr = tempChild;
			}
			else if( curr->right != NULL && curr->right->data == value ){
				
				// Zig Right 
				BSTNode<T>* tempPar = curr;
				BSTNode<T>* tempChild = curr->right;
				
				tempPar->right = tempChild->left;
				tempChild->left = tempPar;
				
				curr = tempChild;
			}
			else{
				
				// We must Zig-Zig or Zig-Zag. Pass curr and parent
				if( value < curr->data ){
					
					splay( value, curr->left, curr );	// Account for Two Levels
					
					splay( curr, value );	// Fix on the last level 
				}
				else if( value > curr->data ){
	
					splay( value, curr->right, curr );	// Account for Two Levels
					
					splay( curr, value );	// Fix on the last level
				}
				else{
					
					// The value requested in the root, so it should stay in place.
				}
			}
		}
		
		// Public method - Find and delete the element
		bool remove( BSTNode<T>*& currPtr, const T& element ){
			
			// If we hit NULL, element is not in the tree
			if( currPtr == NULL ){
				return false;
			}

			// Otherwise, check left if the element is less than the data
			if( element < currPtr->data ){
				return remove( currPtr->left, element );
			}
			
			// Otherwise, check right if the element is greater than the data			
			else if( element > currPtr->data ) {
				return remove( currPtr->right, element );
			}
			
			// If the parent has two children
			else if( currPtr->left != NULL && currPtr->right != NULL ){
				
				// Set the currNode's data to the min's value 
				// Pass currPtr->right to get the minimum to the right
				splay( this->root, this->findMax( currPtr->left )->data);
								
				BSTNode<T>* temp = this->root->right;
				
				this->root->right = this->root->right->right;
				
				delete temp;
				
				return true;
				// currPtr->data = this->findMax( currPtr->left )->data;
				
				// Now we have a duplicate value
				// so recursively delete the duplicate
				// return remove( currPtr->left, currPtr->data );
			}
			
			// If there is only one child 
			else{
				
				// Create a temp Node pointer, just like in Linked Lists 
				// Make it point to the currPtr
				BSTNode<T>* temp = currPtr; 
				
				// Set the currPtr to the non NULL child
				currPtr = ( currPtr->left != NULL ) ? currPtr->left : currPtr->right;
				
				// Delete temp
				delete temp;
				
				return true;
				
			}
			
		}
	
	public:
	
		SplayTree() : BST<T>() {}
	
		~SplayTree() {}
		
		void Insert( const T& valueIn ){
			
			T value = valueIn;
			
			// Insert in its correct location
			this->Insert( this->root, valueIn );
			
			// Splay the value to the top of the tree
			splay( this->root, value );
		}
		
		bool contains( const T& valueIn ){
		
			if( this->root == NULL )
				return false;

			T value = valueIn;
				
			splay( this->root, value );
						
			return this->root->data == valueIn;
		}
		
		bool remove( const T& element ){
					
			T value = element;
			
			contains( value );
			
			return this->remove( this->root, element );				
			
		}
		
		// Print the InOrder and Pre-Order Traversal 
		friend std::ostream& operator<<( std::ostream& output, const SplayTree<T>& theTree ){
			
			// Pass the ostream and the root to print in order recursively
			output << "In-Order  : ";
			theTree.printInOrder( output, theTree.root );
			
			output << "\nPre-Order : ";
			theTree.printPreOrder( output, theTree.root );
			
			output << "\nPost-Order: ";
			theTree.printPostOrder( output, theTree.root );
			
			output << "\nLevel-Order: ";
			theTree.printLevelOrder( output, theTree.root );
			
			return output;
			
		}
	
};

#endif