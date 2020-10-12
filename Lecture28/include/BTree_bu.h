#ifndef BTREE_H
#define BTREE_H

#include <cstdlib>
#include <iostream>


template<class T>
class BTree{

	private:
	
		struct node{
			
			bool leaf;
			int maxVals;
			T* values;
			node **childPtrs;
			int numVals;
			
			void checkMemory(){
				
				if (this == NULL) {
					std::cerr <<  "Out of Memory" << std::endl;
					exit (-1);
				} 	
			}
			
			node( unsigned int vIn, bool isLeaf ) : 
				leaf(isLeaf), maxVals(vIn), values(new T[maxVals]), 
				childPtrs(new node*[maxVals+1]), numVals(0) {
				
				checkMemory();
				
			}
			
			node* operator=(const node* assign){
				
				if(this != (void *)&assign){
					this->leaf = assign->leaf;
					this->numVals = assign->numVals;
					this->maxVals = assign->maxVals;
					
					for(unsigned int i = 0; i < this->numVals; i++){
						
						this->values[i] = assign->numVals[i];
						
					}
					
					for(unsigned int i = 0; i < this->maxVals; i++){
						this->childPtrs[i] = assign->childPtrs[i];
					}
					
				}
				
				return *this;
			}
			
		};

		node *root;
		unsigned int v;
		
		void copy( node*& destination, node*& origin ){
			
			// Set the newNode equal to the old 
			node* newNode = new node(v, origin->leaf);
			
			// Call the leftmost 
			copy(newNode->childPtrs[0], origin->childPtrs[0]);
			
			// Iterate through the rest of the values and pointers
			for(unsigned int iter = 0; iter < v; iter++){
				
				newNode->values[v] = origin->values[v];
				
				copy(newNode->childPtrs[iter+1], origin->childPtrs[iter+1]);
			}
			
			destination = newNode;
			
		}
		
		void deleteTree( node*& theNode ){
			
			if(theNode == NULL)
				return;
			
			for(unsigned int iter = 0; iter < v+1; iter++){
				
				deleteTree( theNode->childPtrs[iter] );
				delete theNode->childPtrs[iter];
				
			}
			
			delete theNode->childPtrs;
			delete theNode->values;

		}

		
	
		void insert(node*& theNode, T value){
			
			if(theNode->leaf && theNode->numVals < v){
				
				insertNonFull( theNode, value );
				
			}
			else if(theNode->leaf && theNode->numVals == v){
				
				node* riseNode = new node(v, false);
				
				int midPoint = v/2;
				
				node* smallerVals = new node(v, true);
				node* largerVals = new node(v, true);
				
				unsigned int iter = 0, jter=0;
				bool inserted = false;
				
				// Get all the values less than value while less than the midpoint
				while(jter < midPoint){
					
					if( theNode->values[iter] > value && !inserted){
						
						smallerVals->values[jter] = value;
						inserted = true;
					}
					else{
						smallerVals->values[jter] = theNode->values[iter];
						iter++; 
					}

					jter++;
					smallerVals->numVals++;
				}
				std::cout << std::endl;
				
				
				std::cout << "First: ";
				for(unsigned int kter = 0; kter < jter; kter++){
					
					std::cout << smallerVals->values[kter] << " ";
				}
				std::cout << std::endl;
				
				if(iter == jter && value < theNode->values[iter + 1]){
					
					riseNode->values[0] = value;
					riseNode->numVals++;
				}
				else{
					
					riseNode->values[0] = theNode->values[iter];
					riseNode->numVals++;
					iter++;
				}
				
				jter = 0;
				while(iter < theNode->numVals ){
					
					if( theNode->values[iter] > value && !inserted){
						
						largerVals->values[jter] = value;
						inserted = true;
					}
					else{
						largerVals->values[jter] = theNode->values[iter];
						iter++;
					}
					jter++;
					largerVals->numVals++;
				}	

				std::cout << "Second: ";
				for(unsigned int kter = 0; kter < jter; kter++){
					
					std::cout << largerVals->values[kter] << " ";
				}
				std::cout << std::endl;				
				
				theNode = riseNode;
				theNode->childPtrs[0] = smallerVals;
				theNode->childPtrs[1] = largerVals;
				
			}
			// The node is not a leaf 
			else{
				
				// Find the node pointing to the range for the node 
				/*unsigned int iter = 0;
				while( theNode->values[iter] < value && iter < theNode->numVals ){
					iter++;
				}
				
				std::cout << "Else Case: " << iter << std::endl;
				insert(theNode->childPtrs[iter], value);
				
				// If current node not full, find the location
				if(theNode->numVals < v){
					
					unsigned int jter = 0;
					
					while( theNode->values[jter] < theNode->childPtrs[iter]->values[0]){
						jter++;
					}
					
					theNode->childPtrs[jter] = theNode->childPtrs[iter]->childPtrs[0];
					theNode->childPtrs[jter+1] = theNode->childPtrs[iter]->childPtrs[1];
					theNode->values[jter] = theNode->childPtrs[iter]->values[0];
					
				}
				
				node* riseNode = new node(v, false);
				
				int midPoint = v/2;
				
				node* smallerVals = new node(v, false);
				node* largerVals = new node(v, false);
				
				unsigned int jter = 0; */
			}
			

		}
		
		void insertNonFull(node*& theNode, T value){
			
			int iter = theNode->numVals - 1;
			
			if(theNode->leaf == true){
				
				while(iter >= 0 && theNode->values[iter] > value){
					
					theNode->values[iter+1] = theNode->values[iter];
					iter--;
					
				}
				
				theNode->values[iter+1] = value;
				theNode->numVals++;
				
				
				for(int i = 0; i < theNode->numVals; i++){
					
					std::cout << theNode->values[i] << " ";
				}
				std::cout << std::endl;
			}
			
		}
		
		
		void search(node*& theNode, const T& searchVal){
			
			if(theNode == NULL){
				
				std::cout << searchVal << " not Found" << std::endl;
			}
			
			unsigned int iter = 0;
			while( iter < theNode->numVals && theNode->values[iter] < searchVal ){
				
				std::cout << theNode->values[iter] << " ";
				iter++;
				
			}
			
			std::cout << "iter? " << iter << std::endl;
			
			if( theNode->values[iter] == searchVal ){
				
				std::cout << theNode->values[iter] << "... Value found!";
				return;
			}
			
			else{
				std::cout << "... descending level..." << " " << theNode->values[iter] << std::endl;
				search(theNode->childPtrs[iter], searchVal);
			}
			
		}
		
		void printInOrder( std::ostream& out, node*& theNode ){
			
			if( theNode == NULL ){
				return;
			}
			
			for(unsigned int iter = 0; iter < theNode->numVals; iter++){
				
				printInOrder(out, theNode->childPtrs[iter]);
				
				std::cout << theNode->values[iter] << " ";
				
			}
			
			printInOrder(out, theNode->childPtrs[theNode->numVals]);
		}


	public:
	
		BTree( unsigned int kIn ) : root( NULL ), v( kIn ) {}
		
		~BTree(){
			
			deleteTree(root);
			
		}
		
		BTree(const BTree<T>& copyTree){
			
			copy( this->root, copyTree->root );
			
		}
		
		BTree<T>& operator=(const BTree<T>& assign){
				
			if(this != &assign){
				
				if(this->root == NULL)
					return *this;
				
				copy( this->root, assign->root );
				
			}
			
			return *this;
			
		}
		
		// The main function that inserts a new value in this B-Tree 
		void insert(T value) 
		{ 
			// If tree is empty 
			if (root == NULL) 
			{ 
				// Allocate memory for root 
				root = new node(v, true); 
				root->values[0] = value;  // Insert value 
				root->numVals = 1;  // Update number of values in root 
			} 
			else if( root->numVals < v && root->leaf ){
				
				insertNonFull( root, value );

			}
			else{
			
				// Otherwise, we recursively call the insert method 
				insert(this->root, value);
				
				std::cout << "The root now contains ";
				
				for(unsigned int iter = 0; iter < root->numVals; iter++){
					
					std::cout << root->values[iter] << " ";
				}
				std::cout << std::endl;
				
				std::cout << "Left: ";
				for(unsigned int kter = 0; kter < root->childPtrs[1]->numVals; kter++){
					
					std::cout << root->childPtrs[1]->values[kter] << " ";
				}
				std::cout << std::endl;	
			
			}
			
		}
		
		
		void search(const T& searchVal){
			
			std::cout << "Searching for " << searchVal << "..." << std::endl;
			
			search(root, searchVal);
			
			std::cout << std::endl;
			
		}
		
		
		void printInOrder( std::ostream& out ){
			
			std::cout << "In-Order Print: ";
			printInOrder( out, root );
			std::cout << std::endl;
		}

};

#endif