#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

// linked list struct
struct node{
	int var;
	struct node * next;	
};

// iterate over linkedlist
void printlist(struct node * head){
	int tmp = 0;
	
	struct node * current = head;
	while(1){
		printf("Item no. %d in linkedlist is: %d\n", tmp + 1, current -> var);
		if (current -> next == NULL){
			break;
		}
		else{
			current = current -> next;
			++tmp;
		}
	}
}

// insert beginning, need to change head so double pointer(head points to head, head to node)
void addstart(struct node ** head){
	int num;	
	printf("What number to add to start?\n");
	scanf("%d", &num);
	
	struct node * newnode = NULL;
	newnode = (struct node *) malloc(sizeof(struct node));
	newnode -> var = num;
	newnode -> next = *head;
	*head = newnode;
}

// insert to end
void addend(struct node * head){
	int num;
	printf("What number to add to end?\n");
	scanf("%d", &num);
	struct node * current = head;
	while(current -> next != NULL){
		current = current -> next;
	}

	current -> next = (struct node *) malloc(sizeof(struct node));
	current -> next -> var = num;
	current -> next -> next = NULL;
}

// insert in specified place
void addspecific(struct node * head){
	int pos;
	int num;
	int tmp = 0;
	printf("Which position do you want to add?\n");
	scanf("%d", &pos);
	
	switch(num){
		case 1:
			printf("You should use addstart function!\n");
			break;
		default:
			printf("What number do you want to add at position %d?\n", pos);
			scanf("%d", &num);
			// arrive at the element just before the position
			while(tmp < pos - 1){
				if (head -> next == NULL){
					printf("The given index has exceeded the list, operation fault!\n");
					return;
				}
				head = head -> next;
				++tmp;
			}

			if (head -> next == NULL){
				printf("You should use addend function!\n");
				return;
			}
			else{
				struct node * newnode = (struct node *) malloc(sizeof(struct node));
				newnode -> var = num;
				newnode -> next = head -> next;
				head -> next = newnode;
			}
	}
}


// remove first item
void remfirst(struct node ** head){
	*head  = (*head) -> next;
	printf("First item removed\n");
}


// remove last item
void remlast(struct node * head){
	while(head -> next -> next != NULL){
		head = head -> next;
	}
	head -> next = NULL;
	printf("Last item removed\n");
}


// remove specific item
void remspec(struct node * head){
	int pos;
	int tmp = 0;
	struct node * current = NULL;

	printf("Which item do you want to remove?\n");
	scanf("%d", &pos);
	
	if (pos == 1){
		printf("Just use remfirst, operation haulted!\n");
		return;
	}
	else{
		while(tmp < pos - 2){
			if(head -> next == NULL){
				printf("Position entered exceeded list, operation haulted!\n");
				return;
			}
			head = head -> next;
		}
		current = head -> next -> next;
		head -> next = current;
	}
}

// remove by value
void remvalue(struct node * head){


}

int main(){
	int i;
	int num;
	int tmp = 0;
	int input;

	printf("Please provide total inputs: ");
	scanf("%d", &num);

	// initialize head
	struct node * head = NULL;
	head = (struct node *) malloc(sizeof(struct node));
	head -> var = -1;
	head -> next = NULL;

	// initialize current(in order to not change head)
	struct node * current = head;

	// put user input into linkedlist
	// remember to not declare more memory than what's needed
	while(tmp < num){
		printf("Please provide input number %d: ", tmp + 1);
		scanf("%d", &input);
		current -> var = input;
		if (num - tmp == 1){
			current -> next = NULL;
		}
		else{
			current -> next = (struct node *) malloc(sizeof(struct node));
			current = current->next;
		}
		++tmp;	
	}
	

	// iterate linkedlist
	printlist(head);

	// add to start
	addstart(&head);
	printlist(head);
	
	// add to end
	addend(head);
	printlist(head);

	// add in specific place
	addspecific(head);
	printlist(head);

	// remove first item
	remfirst(&head);
	printlist(head);

	// remove last item
	remlast(head);
	printlist(head);

	// remove specific item
	remspec(head);
	printlist(head);

	// remove by value
	remvalue(head);
	printlist(head);

	// free memory
	free(head);
	return 0;
}

