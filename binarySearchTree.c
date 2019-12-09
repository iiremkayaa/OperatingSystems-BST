#include"binarySearchTree.h"
Node* createNode(int value){
	Node *newNode = malloc(sizeof(Node));
	newNode->data = value;            
	newNode->left = NULL;
	newNode->right= NULL;
	return newNode;
}
void inorder(Node *root){ //This function prints elements of node according to in order traversal
	if (root != NULL){
		inorder(root->left);
		printf("%d->",root->data);
		inorder(root->right);
	}
}
Node* insert(Node* root,int data){ //In this function, data is inserted to node and returns new node
		if(root == NULL){
			return createNode(data);
		}
		else if(data <= root->data){
			root->left = insert(root->left,data);
		}
		else{
			root->right = insert(root->right,data);	
		}	
		return root;
}
int search(Node* root,int data){ //This function returns -1 if node does not include data. 
	int step=1; //If node includes data, this function return how many steps the value is found
	while(1){	
		if (root == NULL){  
			return -1;
		} 
	    	else if (root->data == data){
			return step;
		} 
	    	else if (root->data < data){ 
	      		root=root->right;
			step++;
		}
		else if(root->data > data){		     
		   	root=root->left;
			step++;
		} 
	}  
}
Node* minValueNode(Node* node){ //This function returns node that has minimum value
	Node *current=node;
	while(current->left != NULL){
		current=current->left;
	}
	return current;
}
Node* deleteNode(Node* root,int data){ //This function does deletion operation of given data and returns new node 
		if(root ==NULL){
			return root;
		}
		if(data < root->data){
			root->left=deleteNode(root->left,data);
		}
		else if(data > root->data){	
			root->right=deleteNode(root->right,data);
		}
		else {
			if(root->left ==NULL){
				Node *temp=root->right;
				free(root);
				return temp;
			}
			else if(root->right==NULL){
				Node *temp=root->left;
				free(root);
				return temp;
			}
			Node *temp=minValueNode(root->right);
			root->data=temp->data;
			root->right=deleteNode(root->right,temp->data);
		}
		return root;
}
