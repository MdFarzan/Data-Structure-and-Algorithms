//Doubly linked list
#include<stdio.h>
#include<conio.h>

//operations
void ins_beg();
void ins_bet();
void ins_end();
void rem_beg();
void rem_bet();
void rem_end();

void forw_trav();
void backw_trav();
int count();
void isEmpty();
void search();
void delete_list();

//node structure
struct node{
	struct node *next;
	int data;
	struct node *prev;

}*head=NULL,*temp;
void main(){
int ch;
char y;
do{
clrscr();

printf("Enter your choice from below- \n");
printf("1> Insert in beginning\n");
printf("2> Insert in between\n");
printf("3> Insert in end\n");
printf("4> Remove from beginning\n");
printf("5> Remove from between\n");
printf("6> Remove from end\n");
printf("7> Forward traversing\n");
printf("8> Backward traversing\n");
printf("9> Count nodes\n");
printf("10> Is list empty?\n");
printf("11> Search an element\n");
printf("12< Delete list\n");

printf("\nYour choice: ");
scanf("%d",&ch);

switch(ch){
	case 1:
		ins_beg();
		break;
	case 2:
		ins_bet();
		break;
	case 3:
		ins_end();
		break;
	case 4:
		rem_beg();
		break;
	case 5:
		rem_bet();
		break;
	case 6:
		rem_end();
		break;
	case 7:
		forw_trav();
		break;
	case 8:
		backw_trav();
		break;
	case 9:
		printf("There is %d elements in list.\n",count());
		break;
	case 10:
		isEmpty();
		break;
	case 11:
		search();
		break;
	case 12:
		delete_list();
		break;
	default:
		printf("Please enter a valid choice!\n");

}
printf("\nFor continue press y: ");
y=getche();
	}while(y=='y'||y=='Y');
}

//Insert node in beginning
void ins_beg(){
	temp=(struct node*)malloc(sizeof(struct node));
	if(!temp){
	printf("Try again inserting!");
	return;
	}

	printf("Enter value: ");
	scanf("%d",&temp->data);

	temp->next=temp->prev=NULL;

	if(head==NULL)
	head=temp;
	else{
	temp->next=head;
	head->prev=temp;
	head=temp;

	}

}

void ins_end(){
struct node *trav;
	temp=(struct node *)malloc(sizeof(struct node));
	if(!temp){
	printf("Please try again inserting.\n");
	return;
	}

	printf("Enter value: ");
	scanf("%d",&temp->data);

	temp->next=temp->prev=NULL;

	if(head==NULL)
	head=temp;

	else{
	trav=head;
	while(trav->next!=NULL)
	trav=trav->next;

	trav->next=temp;
	temp->prev=trav;
	}



}
void ins_bet(){
int p,i;
struct node *trav,*trav2;

	if(head==NULL){
	printf("List is empty!");
	return;
	}

	printf("Enter position: ");
	scanf("%d",&p);

	i=count();
	if(p<=i){
	temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter value: ");
	scanf("%d",&temp->data);
	trav=head;
	for(i=1;i<p-1;i++){
		trav=trav->next;
	}

	trav2=trav->next;



	temp->prev=trav;
	trav->next=temp;

	trav2->prev=temp;
	temp->next=trav2;
	}

	else{
	printf("There are %d node, and you entered %d. So not possible.",i,p);
	}
}

void rem_beg(){

	if(head==NULL){
	printf("Doubly linked list is empty already!\n");
	}
	else{
	temp=head;
	head=head->next;
	head->prev=NULL;

	free(temp);
	}
}
void rem_end(){

	if(head==NULL)
	printf("List is empty already\n");

	else{
	temp=head;

	while(temp->next->next!=NULL)
	temp=temp->next;

	free(temp->next);
	temp->next=NULL;

	}

}
void rem_bet(){
int p,i;
struct node *rem;
	printf("Enter position: ");
	scanf("%d",&p);
	i=count();
	if(p<=i){
		temp=head;
		for(i=1;i<p-1;i++)
		temp=temp->next;


		rem=temp->next;
		temp->next=rem->next;
		rem->prev=temp;

		free(rem);





	}
	else{
	printf("There are only %d nodes and you entered %d. So not possible!\n",i,p);
	}
}

void forw_trav(){
	if(head==NULL)
	printf("List is empty. There's nothing to print.");

	else{
		temp=head;

		while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
		}
	}

}
void backw_trav(){
	if(head==NULL)
	printf("List is empty!\n");
	else{
	temp=head;
	while(temp->next!=NULL)
	temp=temp->next;



	while(temp!=NULL){
	printf("%d\t",temp->data);
	temp=temp->prev;
	}


	}
}

int count(){
int i=0;
	temp=head;
	while(temp!=NULL){
	i++;
	temp=temp->next;
	}

	return i;

	}

void isEmpty(){
	if(head==NULL)
	printf("List is empty.\n");

	else{
	printf("Not empty.");
	}
}

void search(){
int key,flag=0;
	if(head==NULL)
	printf("List is empty!\n");
	else{
	printf("Enter key: ");
	scanf("%d",&key);

	temp=head;

	while(temp!=NULL){
		if(temp->data==key){
		printf("Element found.\n");
		flag=1;
		break;
					}
		temp=temp->next;

	}
	if(flag==0)
	printf("Element not found.\n");
	}

}

void delete_list(){
		while(temp!=NULL){
		temp=head;
		head=head->next;
		free(temp);
		}
		head=NULL;
	printf("List deallocated successfully\n");
}
