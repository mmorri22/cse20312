#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include "BST.h"

template< class T >
class SplayTree : public BST<T>{
	
	private:
	
		void splay( BSTNode<T>*& valueNode, BSTNode<T>*& parent, BSTNode<T>*& grand){
				
			// Recursively Seek Location
			if( parent->left != NULL && valueNode->data < parent->data ){
				
				splay( valueNode, parent->left, parent);
				
			}
			if( parent->right != NULL && parent->data < valueNode->data ){

				splay( valueNode, parent->right, parent);
				
			}

			/* When recurse back up, we need to swap current and parent */
			/* Four cases */
			BSTNode<T>* tempPar = parent;
			BSTNode<T>* tempGrand = grand;
			
			// Case 1: Zig-Zig Left 
			if( grand->data > parent->data && parent->data > valueNode->data ){

				//std::cout << "Case 1" << std::endl;
				tempPar->left = valueNode->right;
				valueNode->right = tempPar;
				tempGrand->left = tempPar->right;
				tempPar->right = tempGrand;
				grand = valueNode;
				
			}

			// Case 2: Zig-Zag Left 
			else if( grand->data > parent->data && parent->data < valueNode->data ){

				tempPar->right = valueNode->left;
				valueNode->left = tempPar;
				tempGrand->left = valueNode->right;
				valueNode->right = tempGrand;
				grand = valueNode;

			}

			// Case 3: Zig-Zig Right 
			else if( grand->data < parent->data && parent->data < valueNode->data ){

				tempPar->right = valueNode->left;
				valueNode->left = tempPar;
				tempGrand->right = tempPar->left;
				tempPar->left = tempGrand;
				grand = valueNode;
			}

			// Case 4: Zig-Zag Right 
			else if( grand->data < parent->data && parent->data > valueNode->data ){

				tempPar->left = valueNode->right;
				valueNode->right = tempPar;
				tempGrand->right = valueNode->left;
				valueNode->left = tempGrand;
				grand = valueNode;
			}				
			
				
		}
	
		// Zig Level
		void splay( BSTNode<T>*& valueNode, BSTNode<T>*& curr ){
			
			if( valueNode->data < curr->data && curr->left == NULL ){
				
				BSTNode<T>* temp = this->root;
				this->root = valueNode;
				valueNode->right = temp;
				
			}
			else if( curr->data < valueNode->data && curr->right == NULL ){
				
				BSTNode<T>* temp = this->root;
				this->root = valueNode;
				valueNode->left = temp;
				
			}
			else{
				
				// We must Zig-Zig or Zig-Zag. Pass curr and parent
				if( valueNode->data < curr->data ){
					
					splay( valueNode, curr->left, this->root);
					
				}
				else if( valueNode->data > curr->data ){
						
					splay( valueNode, curr->right, this->root);
					
				}
				else{
					
					// Duplicate - Do nothing
				}
				
			}
			
		}
		
		void contains( const T& value, BSTNode<T>*& curr ){
			
			std::cout << value << " " << curr->data << std::endl;
			if( value < curr->data && curr->left == NULL ){
				
				// If not in the tree, return the curr
				BSTNode<T>* tempSplay = new BSTNode<T>(curr->data);
				splay(tempSplay, this->root);
				return;
			}
			else if( value > curr->data && curr->right == NULL) {
				
				// If not in the tree, return the curr
				BSTNode<T>* tempSplay = new BSTNode<T>(curr->data);
				splay(tempSplay, this->root);		
				return;
			}
			
			// Left Node is the value 
			else if( curr->left != NULL && curr->left->data == value ){
				
				BSTNode<T>* tempRoot = curr;
				BSTNode<T>* tempLeft = curr->left;

				tempRoot->left = tempLeft->right;
				tempLeft->left = tempRoot;
				curr = tempLeft;
			}
			
			// Right Node is the value 
			else if( curr->right != NULL && curr->right->data == value ){
				
				BSTNode<T>* tempRoot = curr;
				BSTNode<T>* tempRight = curr->right;

				tempRoot->right = tempRight->left;
				tempRight->right = tempRoot;
				curr = tempRight;
			}
			
			else{
				
				// Zig-Zig Left
				if( curr->left != NULL && value < curr->left->data && value < curr->data ){
					
					contains( value, curr->left->left, curr->left, this->root );
				}
				
				// Zig-Zag Left
				else if( curr->left != NULL && value > curr->left->data && value < curr->data ){
					
					contains( value, curr->left->right, curr->left, this->root );
				}
				
				// Zig-Zig Right 
				else if( curr->right != NULL && value > curr->right->data && value > curr->data ){
					
					contains( value, curr->right->right, curr->right, this->root );
				}

				// Zig-Zag Right 
				else if( curr->right != NULL && value < curr->right->data && value > curr->data ){
					
					contains( value, curr->right->left, curr->right, this->root );
				}
				
			}
			
		}
		
		
		void contains( const T& value, BSTNode<T>*& child, BSTNode<T>*& parent, BSTNode<T>*& grand){
				
			if(child == NULL)
				return;
			
			
			else if( child->data != value ){
				
				if( child->left == NULL && value < child->data ){
					
					// Splay the child to the root
					BSTNode<T>* tempSplay = new BSTNode<T>(child->data);
					splay(tempSplay, this->root);
					return;
				}
				
				else if( child->right == NULL && value > child->data ){
					
					// Splay the child to the root
					BSTNode<T>* tempSplay = new BSTNode<T>(child->data);
					splay(tempSplay, this->root);
					return;
				}
				
				else if( child->left != NULL && value < child->data ){
					
					contains( value, child->left, child, parent );
				}
				else if( child->right != NULL && value > child->data ){
					
					contains( value, child->right, child, parent);
				}
				
			}
			
			BSTNode<T>* tempPar = parent;
			BSTNode<T>* tempGrand = grand;
			BSTNode<T>* valueNode = child;
			
			if( parent->data == value ){
				
				if( parent->data < grand->data ){
					
					tempGrand->left = tempPar->right;
					tempPar->right = tempGrand;
					grand = tempPar;
				}
				else{
					
					tempGrand->right = tempPar->left;
					tempPar->left = tempGrand;
					grand = tempPar;					
				}
				
			}
			
			else if(child != NULL && child->data == value ){
				
				// Case 1: Zig-Zig Left 
				if( grand->data > parent->data && parent->data > valueNode->data ){

					tempPar->left = valueNode->right;
					valueNode->right = tempPar;
					tempGrand->left = tempPar->right;
					tempPar->right = tempGrand;
					grand = valueNode;
					
				}

				// Case 2: Zig-Zag Left 
				else if( grand->data > parent->data && parent->data < valueNode->data ){

					tempPar->right = valueNode->left;
					valueNode->left = tempPar;
					tempGrand->left = valueNode->right;
					valueNode->right = tempGrand;
					grand = valueNode;

				}

				// Case 3: Zig-Zig Right 
				else if( grand->data < parent->data && parent->data < valueNode->data ){
					
					tempPar->right = valueNode->left;
					valueNode->left = tempPar;
					tempGrand->right = tempPar->left;
					tempPar->left = tempGrand;
					grand = valueNode;
		
					
				}

				// Case 4: Zig-Zag Right 
				else if( grand->data < parent->data && parent->data > valueNode->data ){
					
					tempPar->left = valueNode->right;
					valueNode->right = tempPar;
					tempGrand->right = valueNode->left;
					valueNode->left = tempGrand;
					grand = valueNode;
				}						
			}
		}
		

	
	public:
	
		SplayTree() : BST<T>() {}
	
		~SplayTree() {}
		
		void Insert( const T & value )
		{
			
			BSTNode<T>* newNode = new BSTNode<T>(value);
			
			/* If the tree is empty, set as root */
			if( this->root == NULL ){
				this->root = newNode;
			}
			
			/* Otherwise, we will need to splay */
			else{
				
				splay(newNode, this->root);
				
			}
			
			if( this->root->left != NULL && this->root->left->data >= value ){
				
				BSTNode<T>* left = this->root->left;
				BSTNode<T>* left_child = this->root->left->right;
				
				this->root->left = left_child;
				left->right = this->root;
				this->root = left;
			}
			
			if( this->root->right != NULL && this->root->right->data <= value ){
				
				BSTNode<T>* right = this->root->right;
				BSTNode<T>* right_child = this->root->right->left;
				
				this->root->right = right_child;
				right->left = this->root;
				this->root = right;
			}
			
		}
		
		bool contains( const T& x ){
		
			if( this->root == NULL )
				return false;
		
			std::cout << x << std::endl;
		
			contains( x, this->root );
			
			return this->root->data == x;
		}
		
		const T& returnRootVal(){
			return this->root->data;
		}
	
};

#endif