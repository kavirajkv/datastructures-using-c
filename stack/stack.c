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

/*inserting at front 
to insert at front we need address of head hence we can point newnode's next to head*/
struct Node* insertatbegin(struct Node *head,int data){
    struct Node *newnode=createnode(data);
    newnode->next=head;
    return newnode;
}


/*deleting a node in front of a linked list
it can be implemented by making head->next to head and head->next to null*/
struct Node* deleteatfirst(struct Node *head){
    if (head==NULL){
        return NULL;
    }
    struct Node *temp=head;
    head=head->next;
    free(temp);
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

void stackpush(struct Node **head,int data){
    *head=insertatbegin(*head,data);
}

void stackpop(struct Node **head){
    *head=deleteatfirst(*head);

}

int stackpeek(struct Node *head){
    return head->data;
}

void printstack(struct Node *head){
    displaylist(head);
}

int main(){
    struct Node *head=NULL;
    
    stackpush(&head,1);
    stackpush(&head,2);
    stackpush(&head,3);

    printstack(head);
    printf("peeked element %d\n",stackpeek(head));
    stackpop(&head);
    printstack(head);

    freelist(head);
    return 1;

}
