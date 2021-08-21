#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head;

void insert_beginning();
void delete_beginning();
void insert_last();
void delete_last();
void insert_at(int x);
void delete_at(int x);
void print_nodes();


int main(){

    insert_at(1);
    insert_at(2);
    insert_at(3);
    insert_at(4);
    delete_at(3);


    print_nodes();


    return 0;
}

void insert_beginning(){
    struct node* p_new_node;
    p_new_node =(struct node*)malloc(sizeof(struct node));
    int val;
    puts("enter data for node:");
    scanf("%d",&val);

    if (head==NULL){
        p_new_node->data=val;
        p_new_node->next=0;
        p_new_node->prev=0;
        head=p_new_node;
        
        
    }else{
        p_new_node->next=head;
        p_new_node->prev=NULL;
        p_new_node->data=val;
        head->prev=p_new_node;
        head=p_new_node;

    }
    puts("inserted in the beginning");


}

void delete_beginning(){
    if(head ==0){
        puts("nothing to remove");
    }
    else if (head->next==0){
        head=0;
    }else {
        (head->next)->prev=0;
        head=head->next;
    }
    puts("deleted first node");
}

void insert_last(){
    struct node* p_new_node;
    p_new_node =(struct node*)malloc(sizeof(struct node));
    int val;
    puts("enter data for node:");
    scanf("%d",&val);
    p_new_node->data=val;
    p_new_node->next=0;
    struct node* p_temp=head;

    if (head==0){
        head=p_new_node;
        p_new_node->prev=0;
    }
    else{
        while(p_temp->next != 0){
            p_temp=p_temp->next;
        }
        p_temp->next=p_new_node;
        p_new_node->prev=p_temp;
    }
    


}

void delete_last(){
    struct node * temp=head;
    if (head==0){
        puts("nothing to delete");
    }
    else{
        if(head->next==0){
            head=0;
        }else{

        while(temp->next!=0){
            temp=temp->next;
        
        }
        (temp->prev)->next=0;

        }
    }
    puts("last node deleted");
}

void insert_at(int x){

    struct node* temp=head;
    
    
    int no_nodes=0;
    while(temp!=0){
        no_nodes++;
        temp=temp->next;
    }
    temp=head;
    printf("no of nodes:%d\n",no_nodes);


    if(x==1){
        insert_beginning();
        return;
    }else if (x==no_nodes+1){
        insert_last();
        return;

    }else{
   
        struct node* p_new_node;
        p_new_node =(struct node*)malloc(sizeof(struct node));
        int val;
        puts("enter data for node:");
        scanf("%d",&val);
        p_new_node->data=val;
        
        while(x>1){
            temp=temp->next;
            x--;
        }
        temp->prev->next=p_new_node;
        p_new_node->prev=temp->prev->next;
        temp->prev=p_new_node;
        p_new_node->next=temp;
        puts("node inserted");


    }
    
}

void print_nodes(){
    struct node* temp=head;
    puts("the nodes are:");
    while(temp!=0){
        printf("%d \n",temp->data);
        temp=temp->next;
    }

}

void delete_at(int x){
    struct node* temp=head;
    
    
    int no_nodes=0;
    while(temp!=0){
        no_nodes++;
        temp=temp->next;
    }
    temp=head;
    printf("no of nodes:%d\n",no_nodes);


    if(x==1){
        delete_beginning();
        return;
    }else if (x==no_nodes){
        delete_last();
        return;

    }else{
        
        while(x>1){
            temp=temp->next;
            x--;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;



    }
    
}