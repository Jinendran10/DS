#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
	int data;
	struct node*next;
}node;
node*create_node(int new_data){
	node*new_node=((node*)malloc(sizeof(node)));
	new_node->data=new_data;
	new_node->next=NULL;
	return new_node;
}
typedef struct Stack{
	node*head;
}Stack;
	
void initializeStack(Stack*stack){
	stack->head=NULL;
}
int IsEmptyStack(Stack* stack){
	return stack->head==NULL;
}
void push(Stack*stack,int new_data){
	node*new_node=create_node(new_data);
	if(!new_node){
		printf("Stack Overflow\n");
	}
	new_node->next=stack->head;
	stack->head=new_node;
	printf("The element %d has been added!\n",new_node->data);
}
void pop(Stack*stack){
	if(IsEmptyStack(stack)){
		printf("Stack underflow\n");
		return;
	}
	else{
		node*temp=((node*)malloc(sizeof(node)));
		temp=stack->head;
		printf("The removed element is:%d\n",stack->head->data); 
		stack->head=stack->head->next;
		free(temp);
	}
}
void peek(Stack*stack){
	if(!IsEmptyStack(stack)){
		printf("The topmost element is:%d\n",stack->head->data);
	}
	else{
		printf("Stack Empty\n");
	}
}
void main()
{	
	Stack stack;
	initializeStack(&stack);
	int ch;
	bool flag=true;
	while(flag){
		printf("Enter your choice:\n1.push\n2.pop\n3.peek\n4.stop\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				int el;
				printf("Enter the element to add to stack:");
				scanf("%d",&el);
				push(&stack,el);
				continue;
			case 2:
				pop(&stack);
				continue;
			case 3:
				peek(&stack);
				continue;
			case 4:
				flag=false;
				continue;
			default:
				printf("Invalid choice!try again\n");
			break;
		}
	}
}
	
