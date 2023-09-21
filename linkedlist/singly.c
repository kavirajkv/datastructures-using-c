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

/*inserting at end
to insert at end we have to traverse till end i.e reach till next is null and make that next point to new node*/
struct Node* insertatend(struct Node *head,int data){
    struct Node *newnode=createnode(data);
    if (head==NULL){
        return newnode;
    }
    struct Node *current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newnode;
    return head;
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

int main(){
    struct Node *head=NULL; //initializing a linked list

    int num;

    while(num!=-1){
        printf("enter a number to insert into linked list- enter -1 to stop: ");
        scanf("%d",&num);
        if(num!=-1){
            head=insertatbegin(head,num);
        }   
    }

    displaylist(head);
    head=deleteatfirst(head);
    displaylist(head);
    head=deleteatend(head);
    displaylist(head);
    freelist(head);

    return 1;

}

