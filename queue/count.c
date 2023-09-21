//queue implementation using linkedlist

#include<stdio.h>
#include<stdlib.h>

//create a structure for node
struct Node
{
    int data;
    struct Node *next;
};


//function to create a node
/*to create a node first allocate memory for the node
-then initialize newnode's data to data and next to null now a node with data and null address created */
struct Node* createnode(int data){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL){
        printf("memory allocation failed");
        exit(1);
    }
    else{
        newnode->data=data;
        newnode->next=NULL;
        return newnode;
    }
}


//to insert at front we need address of head hence we can point newnode's next to head*/
struct Node* insertatbegin(struct Node *head,int data){
    struct Node *newnode=createnode(data);
    newnode->next=head;
    return newnode;
}

/*deleting a node at end of a linked list
it can be implemented by using two variable current and previous current is to iterate by next and previous will be current
then the previous->will be null and current will be freed*/
struct Node* deleteatend(struct Node *head){
    if (head==NULL){
        return NULL;
    }
    if (head->next==NULL){
        free(head);
        return NULL;
    }
    struct Node *current=head;
    struct Node *previous=NULL;

    while(current->next!=NULL){
        previous=current;
        current=current->next;
    }
    previous->next=NULL;
    free(current);
    return head;

}

/*for displaying linked list get to the head and iterate to next till next=null*/
void displaylist(struct Node *head){
    struct Node *current=head;
    while(current!=NULL){
        printf("%d ->",current->data);
        current=current->next;
    }
    printf("NULL\n");
}

int countlist(struct Node *head){
    struct Node *current=head;
    int count=0;
    while(current!=NULL){
        if(current->data){
            count=count+1;
        }
        current=current->next;
    }
    return count;
}

/*In C dynamnic memory allocated cannot be automatically removed
 hence we have free it after using the memory space */
void freelist(struct Node *head){
    struct Node *current=head;
    while(current!=NULL){
        struct Node *temp=current;
        current=current->next;
        free(temp);
    }

}



void enque(struct Node **head,int data){
    *head=insertatbegin(*head,data);
}

void deque(struct Node **head){
    *head=deleteatend(*head);

}

int isempty(struct Node **head){
    if(head==NULL){
        return 0;
    }
    else{
        return 1;
    }

}

void printqueue(struct Node *head){
    displaylist(head);
}


int main(){
    struct Node *head=NULL;
    int ans,cou;
    
    enque(&head,1);
    enque(&head,2);
    enque(&head,3);
    printqueue(head);

    cou=countlist(head);
    printf("the no of elemets is %d",cou);

    deque(&head);
    ans=isempty(&head);
    if(ans){
        printf("Queue has elements\n");
    }
    else{
        printf("Queue is empty\n");
    }
    printqueue(head);

    freelist(head);
    return 1;

}


