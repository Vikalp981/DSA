#include<stdio.h>
#include<stdlib.h>
//creating structure
struct node{
    int data;
    struct node *next;

}*head;
//declaring all used functions as globally so that it can be accessed easily
void displayList();//function to display linked list
void insert_at_b(int data);//fuction to insert at beginning of linked list
void delete_at_m();//function to delete the element in a specified position
void delete_at_e();//function to delete last element
void delete_at_b();//function to delete the beginning element
void insert_at_m(int data, int position);//function to insert the element at a particular specified position
void insert_at_e(int data);//function to insert the element at the end position
int search(int key);//function to search the element in linked list
int count=0;//used to find the length of the linked list
//main function
int main(){
    struct node  *newnode , *temp;//declaring two pointers for accessing the data and address in the linked list
    head=0;
    int choice, opt_menu, key, data, position, index;
    //entering elements in the linked list
    while(choice){
        newnode = (struct node *)malloc(sizeof(struct node));//using malloc to typecast it into pointer
        printf("Enter data \n");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        //asking user to whether he wants to continue or not
        printf("Do you want to continue?\n");
        scanf("%d",&choice);
        count++;

    }
    //display the menu for user();
    while(1)
    {    
        printf("Menu\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at middle\n");
        printf("3. Insert at end\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at middle\n");
        printf("6. Delete at end\n");
        printf("7. Search an element\n");
        printf("8. exit\n");
        //asking user what he wants to do
        printf("Enter your choice : ");
        scanf("%d", &opt_menu);
        printf("\n");
        //using switch to call functions according to user demands
        switch(opt_menu)
        {
            case 1 :    //calling function to insert at beginning
                        printf("\nEnter data to insert at beginning of the list: ");
                        scanf("%d", &data);
                        insert_at_b(data);
                        displayList();
                        break;
            case 2 :    //calling function to insert at middle
                        printf("Enter data to insert at middle of the list: ");
                        scanf("%d", &data);
                        printf("Enter the position to insert new node: " );
                        scanf("%d", &position);
                        insert_at_m(data, position);
                        displayList();
                        break;
            case 3 :    //calling function to insert element at end
                        printf("\nEnter data to insert at end of the list: ");
                        scanf("%d", &data);
                        insert_at_e(data);
                        displayList();
                        break;
            case 4 :    //calling function to delete the beginning element
                        delete_at_b();
                        displayList();
                        break;
            case 5 :    //calling function to delete at specified position
                        delete_at_m();
                        displayList();
                        break;
            case 6 :    //calling function to delete at end
                        delete_at_e();
                        displayList();
                        break;
            case 7 :    //calling function to search the element
                        printf("\nEnter element to search: ");
                        scanf("%d", &key);
                        index = search(key);
                        if (index >= 0)
                            printf("%d found in the list at position %d\n", key, index + 1);
                        else
                            printf("%d not found in the list.\n", key);
                        break;
            case 8 :    //for exiting the program
                        exit(0);
                        break;
            default :
                        printf("Invalid choice");

        }
    }
   
    return 0;
}
//function to display linked list
void displayList()
{
    struct node *temp;

   
    if(head == 0)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != 0)
        {
            printf("Data = %d\n", temp->data); // Print data of current node
            temp = temp->next;                 // Move to next node
        }
    }
}
//fuction to insert at beginning of linked list
void insert_at_b(int data){
   
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newnode->data = data; // Link data part
        newnode->next = head; // Link address part

        head = newnode;
        printf("DATA INSERTED SUCCESSFULLY\n");
          }

   
}
//function to delete the element in a specified position
void delete_at_m(){
    struct node *temp, *nextnode;

    int position,i=1;
    printf("Enter the position");
    scanf("%d",&position);
    if(position>count){
        printf("invalid position");
    }
    else{
        temp=head;
        while(i<position-1){
            temp=temp->next;
            i++;
        }
        nextnode=temp->next;
        temp->next=nextnode->next;
        free(nextnode);
    }
}
//function to delete last element
void delete_at_e(){
    struct node *temp, *prevnode;

    if(head==0){
        printf("no list to delete");
    }
    else{
        temp=head;
        while(temp->next!=0){
            prevnode=temp;
            temp=temp->next;

        }
        if(temp==head){
            head=0;
            free(temp);
        }
        else{
            prevnode->next=0;
            free(temp);
        }
    }
}
//function to delete the beginning element
void delete_at_b(){
    struct node *temp;
    if(head==0){
        printf("no list to delete");
    }
    else{
        temp=head;
        head=head->next;
        free(temp);
    }
}
//function to insert the element at a particular specified position
void insert_at_m(int data, int position){
    int i;
    struct node *newnode,*temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == 0)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newnode->data = data; // Link data part
        newnode->next = 0;

        temp = head;

       
        for(i=2; i<=position-1; i++)
        {
            temp = temp->next;

            if(temp == 0)
                break;
        }

        if(temp != 0)
        {
            /* Link address part of new node */
            newnode->next = temp->next;

            /* Link address part of n-1 node */
            temp->next = newnode;

            printf("DATA INSERTED SUCCESSFULLY\n");
        }
        else
        {
            printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
        }
    }
}
//function to insert the element at the end position
void insert_at_e(int data){
    struct node *newnode,*temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == 0)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newnode->data = data;
        newnode->next = NULL;

        temp = head;

       
        while(temp->next != 0)
            temp = temp->next;

        temp->next = newnode; // Link address part

        printf("DATA INSERTED SUCCESSFULLY\n");
    }

}
//function to search the element in linked list
int search(int key){
    int index;
    struct node *curNode;

    index = 0;
    curNode = head;

    // Iterate till last element until key is not found
    while (curNode != NULL && curNode->data != key)
    {
        index++;
        curNode = curNode->next;
    }


    return (curNode != 0) ? index : -1;
}
