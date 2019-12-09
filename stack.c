#include"stack.h"
Stack* createStack(int capacity){
	Stack *stack = malloc(sizeof(Stack));
	stack->capacity=capacity;
	stack->top=-1;
	stack->task=malloc(stack->capacity*sizeof(int)); 	//stack->task holds task  numbers. 
	stack->values=malloc(stack->capacity*sizeof(int));	//1->insert 2->delete 3->find minimum 4->search value 
	return stack;
}
int isFull(Stack* stack){
	return stack->top == stack->capacity-1; //If top equals to capacity-1, stack is full
}
int isEmpty(Stack* stack){
	return stack->top == -1 ; //If top equals to -1, stack is empty
}
void push(Stack* stack,int t, int item){
	if(!isFull(stack)){    //In push operation,top increases so index of values and index of tasks increases and  
		stack->top=stack->top+1; //task number that has max index is t and value that has max index is item. 
		stack->values[stack->top]=item;
		stack->task[stack->top]=t;
	}
	else{ //If stack is full, push operation does not work
		printf("Stack is full...\n");
	}
}
int pop(Stack* stack){ //
	int data;
	if(!isEmpty(stack)){ //In pop operation,top decreases so index of values and index of tasks decreases.
		data=stack->values[stack->top]; // This operation returns value that has max index
		stack->top=stack->top-1;
		return data;
	}
	else{ //If stack is empty, pop operation does not work
		printf("Stack is empty...\n");		
	}
}
