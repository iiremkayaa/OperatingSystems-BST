#include<stdio.h>
#include<stdlib.h>
#include"binarySearchTree.h"
#include"stack.h"
#include"time.h"
int printRandoms(int lower, int upper){  //This function return random number between lower and upper
        int num = (rand() % (upper - lower + 1)) + lower; 
        return num;
}
int main(){
	Node *newNode = createNode(4);
    	Node *head = newNode;
	Stack *newStack=createStack(10);
    	insert(head,2);
    	insert(head,8);
    	insert(head,15);
	insert(head,7);
	printf("Initial tree\n"); //Initial binary search tree: 2 4 7 8 15
	inorder(head);
    	srand(time(0)); 
	for(int i = 0; i<10;i++){ //The randomTaskId represents random task id.
		int randomTaskId=printRandoms(1, 4);
		printf("\ntask->");
		if(randomTaskId == 1){
			int insertedValue;
			printf("insert:"); //In insert operation,if the value is in binary search tree, the operation does not work
			scanf("%d",&insertedValue);
			if(search(head,insertedValue) != -1){
				printf("%d could not insert because binary search tree includes %d.\n",insertedValue,insertedValue);
			}
			else{
				insert(head,insertedValue);
				push(newStack,1,insertedValue); //TaskId and value pushes to stack 	
			}					//because it causes modification in binary search tree
			inorder(head);
		}
		if(randomTaskId == 2){
			int deletedValue;
			printf("delete:"); //In delete operation, if the value is not in binary search tree, the operation does not work
			scanf("%d",&deletedValue);
			if(search(head,deletedValue) == -1){
				printf("%d could not delete because binary search tree does not include %d.\n",deletedValue,deletedValue);
			}
			else{
				deleteNode(head,deletedValue);
				push(newStack,2,deletedValue); //TaskId and value pushes to stack 
 			}				       //because it causes modification in binary search tree
			inorder(head);
		}
		if(randomTaskId == 3){ //Minimum value is printed but does not pushes to stack 
			printf("min\nminval %d is found.",minValueNode(head)->data); //because there is no modification in binary search tree
		}
		if(randomTaskId == 4){      //If search function returns -1, the value is not in binary search tree   
			int searchedValue;  //but it returns number that is not -1, this number is how many steps the value is found.
			printf("search:");
			scanf("%d",&searchedValue);
			if(search(head,searchedValue) == -1){
				printf("searched %d is not found.",searchedValue); 
			}
			else{
				printf("searched %d is found in %d steps.",searchedValue,search(head,searchedValue));
			}
		} 
	}
	int backStep;
	printf("\nhow many steps back:");
	scanf("%d",&backStep);
	int step=0;
	while(step < backStep){ //Elements is popped from stack given steps time
		if(isEmpty(newStack)){
			printf("There is no task to be undone.\n");
			break;
		}
		else{
			int value=pop(newStack);
			int task=newStack->task[newStack->top+1];
			if(task == 1){
				deleteNode(head,value);
				printf("inserted value %d is deleted.\n",value);
			}
			else if(task == 2){
				insert(head,value);
				printf("deleted value %d is inserted.\n",value);
			}	
			inorder(head);
			printf("\n");	
		}
		step++;

	}
	return 0;

}
