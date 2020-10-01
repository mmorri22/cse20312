#ifndef AVLTREE_H
#define AVLTREE_H

#include "BST.h"

template< class T >
class AVLTree : public BST<T>{
	
	private:
	
		void checkRotate( BSTNode<T>*& currPtr ){
			
			// Check for balance 
			unsigned int leftHeight = this->maxHeight( currPtr->left );
			unsigned int rightHeight = this->maxHeight( currPtr->right );
			
			// If the left height is greater than the right by 2 or more
			if( leftHeight > rightHeight + 1 ){
				
				rotateRight( currPtr, currPtr->left );
				
				// If the rotation made the balance incorrect the opposite direction 
				if( this->maxHeight( currPtr->right ) > this->maxHeight( currPtr->left ) + 1 ){
					
					BSTNode<T>* grandPtr = currPtr;
					BSTNode<T>* parentPtr = currPtr->right;
					BSTNode<T>* childPtr = currPtr->right->left;
					
					// First, set the parent's right child to the child's left 
					parentPtr->left = childPtr->right;
					
					// Next, set the grandparents's left child to the child's right 
					grandPtr->right = childPtr->left;
					
					// Set child's left pointer to parent 
					childPtr->right = parentPtr;
					
					// Set right child's pointer to grantparent 
					childPtr->left = grandPtr;
										
					// Update the currPtr to the child
					currPtr = childPtr;
					
				}
				
			}
			
			// If the right height is greater than the left by 2 or more
			else if( rightHeight > leftHeight + 1 ){
				
				rotateLeft( currPtr, currPtr->right );
				
				// If the rotation made the balance incorrect the opposite direction 
				if( this->maxHeight( currPtr->left ) > this->maxHeight( currPtr->right ) + 1 ){
					
					BSTNode<T>* grandPtr = currPtr;
					BSTNode<T>* parentPtr = currPtr->left;
					BSTNode<T>* childPtr = currPtr->left->right;
					
					// First, set the parent's right child to the child's left 
					parentPtr->right = childPtr->left;
					
					// Next, set the grandparents's left child to the child's right 
					grandPtr->left = childPtr->right;
					
					// Set child's left pointer to parent 
					childPtr->left = parentPtr;
					
					// Set right child's pointer to grantparent 
					childPtr->right = grandPtr;
										
					// Update the currPtr to the child
					currPtr = childPtr;
					
				}
				
			}			
		}
	
		// Private rotateLeft method
		void rotateLeft( BSTNode<T>*& parent, BSTNode<T>*& rightChild ){
			
			// Create pointers to the parent and right child
			BSTNode<T>* parentPtr = parent;
			BSTNode<T>* childPtr = rightChild;
			
			// Set the parent's right child to the child's left 
			parentPtr->right = childPtr->left;
			
			// Set the childPtr's left child to the parent 
			childPtr->left = parentPtr;
			
			// Update the parent pointer to the child 
			parent = childPtr;
		}
		
		// Private rotateRight method
		void rotateRight( BSTNode<T>*& parent, BSTNode<T>*& leftChild ){
			
			// Create pointers to the parent and right child
			BSTNode<T>* parentPtr = parent;
			BSTNode<T>* childPtr = leftChild;
			
			// Set the parent's right child to the child's left 
			parentPtr->left = childPtr->right;
			
			// Set the childPtr's left child to the parent 
			childPtr->right = parentPtr;
			
			// Update the parent pointer to the child 
			parent = childPtr;
			
		}

		// Private Insert Method
		void Insert( BSTNode<T>*& currPtr, const T& value ){
			
			// If the pointer is Null, we found our location 
			// Set the pointer to the new value
			if( currPtr == NULL ){
				currPtr = new BSTNode< T >(value);
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
			
			
			// Check the Rotation 
			checkRotate( currPtr );
			
		}
		
		
		// Public method - Find and delete the element
		bool remove( BSTNode<T>*& currPtr, const T& element ){
			
			// If we hit NULL, element is not in the tree
			if( currPtr == NULL ){
				return false;
			}

			else{
				
				bool wasDeleted = false;
				
				// Otherwise, check left if the element is less than the data
				if( element < currPtr->data ){
					wasDeleted = remove( currPtr->left, element );
				}
				
				// Otherwise, check right if the element is greater than the data			
				else if( element > currPtr->data ) {
					wasDeleted = remove( currPtr->right, element );
				}
				
				// If the parent has two children
				else if( currPtr->left != NULL && currPtr->right != NULL ){
					
					// Set the currNode's data to the min's value 
					// Pass currPtr->right to get the minimum to the right
					currPtr->data = this->findMin( currPtr->right )->data;
					
					// Now we have a duplicate value
					// so recursively delete the duplicate
					wasDeleted = this->remove( currPtr->right, currPtr->data );
				}
				
				// If there is only one child or no children
				else{
					
					// Create a temp Node pointer, just like in Linked Lists 
					// Make it point to the currPtr
					BSTNode<T>* temp = currPtr; 
					
					// Set the currPtr to the non NULL child
					currPtr = ( currPtr->left != NULL ) ? currPtr->left : currPtr->right;
					
					// Delete temp
					delete temp;
					
					wasDeleted = true;
					
				}
				
				if( currPtr != NULL ){
					checkRotate( currPtr );
				}
				
				return wasDeleted;
			}
		}
	
	
	public:
	
		// Constructor
		AVLTree() : BST<T>() {}
	
		// Required Destructor for AVL Tree
		~AVLTree() {}
		
		// Public Insert Method
		void Insert( const T& value ){
			
			Insert( this->root, value );
		}
		
		// Public remove method 
		bool remove( const T& element ){
			
			// Call the private recursive method
			return remove( this->root, element );
			
		}
		
		// Print the InOrder and Pre-Order Traversal 
		friend std::ostream& operator<<( std::ostream& output, const AVLTree<T>& theTree ){
			
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