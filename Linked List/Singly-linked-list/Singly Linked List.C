#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
//program of singly linked list
//insert operations
void ins_beg();
void ins_end();
void ins_bet();
//remove operations
void rem_beg();
void rem_end();
void rem_bet();
//More operations
void print_list();
void search();
int count();
void isEmpty();
void clear_list();
//node structure
struct node{
	int data;
	struct node *next;
}*head=NULL;
	struct node *temp;
void main(){
int ch;
char y;
do{
clrscr();

printf("Enter your choice: \n");
printf("1> insert at beginning\n");
printf("2> insert in between\n");
printf("3> insert at end\n");
printf("4> remove at beginning\n");
printf("5> remove from between\n");
printf("6> remove at end\n");
printf("7> print list\n");
printf("8> search\n");
printf("9> count\n");
printf("10> check is list empty?\n");
printf("11> Clear complete list\n");

printf("Your choice: ");
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
		print_list();
		break;
	case 8:
		search();
		break;
	case 9:
		printf("Total node is: %d",count());
		break;
	case 10:
		isEmpty();
		break;
	case 11:
		clear_list();
		break;
	default:
		printf("Please enter a valid choice!\n");


}
printf("\nFor continue press y: ");
y=getche();
}while(y=='y');
}

void ins_beg(){


	temp=(struct node *)malloc(sizeof(struct node));
	if(!temp){
	printf("Try again to insert!\n");
	return ;
	}

	else{
		printf("Enter value: ");
		scanf("%d",&temp->data);
		temp->next=NULL;
		//setting in sequence
		if(head==NULL)
		head=temp;

		else{
			temp->next=head;
			head=temp;
		}
	}
}

void ins_end(){
struct node *trav;
temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter value: ");
	scanf("%d",&temp->data);
	temp->next=NULL;

	if(head==NULL)
	head=temp;
	else{

	trav=head;
	while(trav->next!=NULL)
	trav=trav->next;

	trav->next=temp;

		}
 }

void ins_bet(){
int c,p,i;
struct node *trav;
c=count();
	printf("Enter position: ");
	scanf("%d",&p);
	if(p>c){
		printf("There are only %d nodes you entered %d. So not possible\n!",c,p);
	}
	else{
		trav=head;
		i=1;
		while(i<p-1){
		trav=trav->next;
		i++;
		}
		temp=(struct node *)malloc(sizeof(struct node));

		printf("Enter value: ");
		scanf("%d",&temp->data);

		temp->next=trav->next;
		trav->next=temp;
	}

}

void rem_beg(){
	if(head==NULL)
	printf("List is empty already!\n");

	else{
	temp=head;
	head=head->next;

	free(temp);
	}
}

void rem_end(){
	if(head==NULL)
	printf("List is already empty!\n");

	else{
	temp=head;

	while(temp->next->next!=NULL)
	free(temp->next);
	temp->next=NULL;


	}
}

void rem_bet(){
int p,i;
struct node *rem;
	if(head==NULL)
	printf("Empty already!\n");

	else{
		printf("Enter position: ");
		scanf("%d",&p);

	       i=count();
	       if(p>i)
			printf("Their are %d node in list and you entered %d. So not possible!\n",i,p);

	       else{
			temp=head;
			for(i=1;i<p-1;i++)
			temp=temp->next;

			printf("value is %d",temp->data);

			rem=temp->next;

			temp->next=temp->next->next;

			free(rem);

	       }

	}
}

void print_list(){
	if(head==NULL)
	printf("List is empty already!\n");

	else{
		temp=head;
		while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
		}

	}
}

void search(){
int key,f=0;
	if(head==NULL)
	printf("List is empty!\n");

	else{
		printf("Enter key: ");
		scanf("%d",&key);
		temp=head;
		while(temp!=NULL){
		if(key==temp->data){
		printf("Element found!\n");
		f=1;
		break;
		}
		temp=temp->next;
		}

	}
	if(f==0)
	printf("Element not found!\n");
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
	printf("List is Empty.\n");
	else
	printf("List is not empty.\n");
}

void clear_list(){
int i=1;
struct node *rem;
	if(head==NULL)
	printf("List is empty already.\n");

	else{
	clrscr();
	while(head!=NULL){
	temp=head;
	head=head->next;
	free(temp);
	printf("%d is deallocated.\n",i);
	i++;
	}


	printf("Congratulations! All node is deallocated successfully.\n");
	}
}