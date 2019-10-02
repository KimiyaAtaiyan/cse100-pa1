/*
 * Author: Kimiya Ataiyan 
 * UserID: kataiyan
 * Date: 10/1/19
 * Filename: BST.hpp
 * Source of help: tutors in Lab 
 */

#ifndef BST_HPP
#define BST_HPP
#include <iostream>
#include <vector>
#include "BSTIterator.hpp"
#include "BSTNode.hpp"
using namespace std;

template <typename Data>
class BST {
	protected:
		// pointer to the root of this BST, or 0 if the BST is empty
		BSTNode<Data>* root;

		// number of Data items stored in this BST.
		unsigned int isize;

		// height of this BST.
		int iheight;

	public:
		/** Define iterator as an aliased typename for BSTIterator<Data>. */
		typedef BSTIterator<Data> iterator;

		/** Default constructor.
		 *  Initialize an empty BST.
		 */
		BST() : root(0), isize(0), iheight(-1) {}

		/** TODO */
		virtual ~BST() { deleteAll(root); }

		/* 
		 * Function name: insert(const Data&item)
		 * Function prototype: virtual bool insert(const Data& item)
		 * Definition: insert a copy of item into BST tree if not duplicate
		 * Return: return true if inserted, return false if not inserted
		 */

		virtual bool insert(const Data& item) {

			//start at root node and iterate through RHS or LHS of tree 
			if( root != 0){

				BSTNode<Data>* temp = root;	
				int height = 0;

				while(height <= iheight){

					//iterate through LHS
					if(item < temp->data){

						if(temp->left == 0){
							temp->left = new BSTNode<Data>(item);
							temp->left->parent = temp;
							isize++;
							if(height == iheight){
								iheight++;
							}
							return true;
						}
						else{
							temp = temp->left;
						}

					}
					else if( temp->data < item){	//iterate through RHS

						if(temp->right == 0){
							temp->right = new BSTNode<Data>(item);
							temp->right->parent = temp;
							isize++;
							if(height == iheight){
								iheight++;
							}
							return true;
						}
						else{
							temp = temp->right;
						}
					}
					else{
						return false;

					}
					height++;
				}

			}
			else{	//set root to 1 if first element inserted

				root = new BSTNode<Data>(item);
				isize++;
				iheight = 0;
				return true;

			}
		}

		/*
		 * Function name: find(const Data& item)
		 * Function Prototype: virtual iterator find(const Data& item) const
		 * Description: looks for an item in a BST tree and returns iterator pointing to that item
		 * Return: iterator pointing to found node or nullptr if not found
		 */

		virtual iterator find(const Data& item) const { 

			//compare to root to decide whether to iterate through LHS or RHS

			//iterate through LHS
			BSTNode<Data> * temp = root;
			int height = 0;
			bool found = false;

			while(height <= iheight){
				if( item < temp->data){

					temp = temp->left;
					if(temp->data == item){
						found = true;
						return BSTIterator<Data>(temp);
					}
				}
				else if( temp->data < item){ 	//iterate through LHS

					temp = temp->right;
					if(temp->data == item){
						found = true;
						return BSTIterator<Data>(temp);
					}
				}
				else{	//if root is item
					found = true;
					return BSTIterator<Data>(temp);

				}

			}

			if(found == false){
				return BSTIterator<Data>(nullptr);
			}
		}

		/*
		 * Function name: size
		 * Functin prototype: unsigned int size() const
		 * Description: returns size of BST which is # of nodes
		 * Return: unsigned int
		 */
		unsigned int size() const { 

			return isize;	
		}

		/*
		 * Function name: height
		 * Function prototype: int height() const
		 * Description: returns height of the tree
		 * Return: int
		 */
		int height() const { 

			return iheight;	
		}

		/*
		 * Function name: empty 
		 * Function Prototype: bool empty() const
		 * Description: checks if BST is empty 
		 * Return: true if no nodes in tree,false otherwise
		 */
		bool empty() const { 

			if(isize == 0){
				return true;
			}
			else{
				return false;
			}
		}

		/** TODO */
		iterator begin() const { return BST::iterator(first(root)); }

		/** Return an iterator pointing past the last item in the BST.
		*/
		iterator end() const { 

			return typename BST<Data>::iterator(0); 

		}

		/** TODO */
		vector<Data> inorder() const {

			//inorder traversal collection : Left, Root, Right

			vector<Data> list;	
			BSTNode<Data> *temp = root;
			BSTNode<Data> *temp2;
			bool LHSDone = false;


			while(temp != NULL){

				if(temp->left == 0){

					list.push_back(temp->data);
					temp = temp -> right;
				}
				else{
					//make temp2 the right child of the right most node in LHS	

					temp2 = temp->left;
					while(temp2->right != 0 && temp2->right != temp){

						temp2 = temp2->right;
					}

					if( temp2->right == 0){
						temp2->right = temp;
						temp = temp->left;
					}
					else{
						temp2->right = 0;
						list.push_back(temp->data);
						temp = temp->right;
					}
				}
			}



			return list;
		}


	private:

		static BSTNode<Data>* first(BSTNode<Data>* root) {


			BSTNode<Data> * temp = root;

			if(root == NULL){
				return nullptr;
			}

			while(temp->left != 0){
				temp = temp->left;
			}

			return temp;


		}

		/** TODO */
		static void deleteAll(BSTNode<Data>* n) {
			/* Pseudocode:
			   if current node is null: return;
			   recursively delete left sub-tree
			   recursively delete right sub-tree
			   delete current node
			   */
		}
};

#endif  // BST_HPP
