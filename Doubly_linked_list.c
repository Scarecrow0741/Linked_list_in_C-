#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node {
    int element ;
    struct node* next ;
    struct node* prev ;
} node ;

void deallocate( node** tail , node** head){
    if ( tail == NULL ){
        return ;
    }
    node* curr = *tail ; 
    while ( curr -> next != NULL ){
        curr = curr -> next ;
        free( curr -> prev );
    }
    free(curr); 
    *tail = NULL ;
    *head = NULL ;
}

void insert_beginning( node** tail , int value ){
    node* new_node = malloc(sizeof(node));
    if ( new_node == NULL ){
        return ;
    }
    new_node -> element = value ;
    new_node -> prev = NULL ;
    new_node -> next = *tail ;
    (*tail) -> prev = new_node ;
    *tail = new_node ;
}

void insert_end( node** head , int value ){
    node* new_node = malloc(sizeof(node));
    if( new_node == NULL ){
        return ;
    }
    new_node -> element = value ;
    new_node -> next = NULL ;
    new_node -> prev = *head ;
    (*head) -> next = new_node ;
    *head = new_node ;
}

void init( node** head , node** tail , int value ){
    // for when the list is empty
    node* new_node = malloc(sizeof(node));
    if( new_node == NULL ){
        return ;
    }
    new_node -> element = value ;
    new_node -> next = NULL;
    new_node -> prev = NULL ;
    *tail = new_node ;
    *head = new_node ;
}

void insert_after( node* noode , int value ){
    node* new_node = malloc(sizeof(node));
    if( new_node == NULL ){
        return ;
    }
    new_node -> element = value ;
    new_node -> prev = noode ;
    new_node -> next = noode -> next ;
    noode -> next -> prev = new_node ;
    noode -> next = new_node ;
}

void insert_before( node* noode , int value ){
    node* new_node = malloc(sizeof(node));
    if( new_node == NULL ){
        return ;
    }
    new_node -> element = value ;
    new_node -> prev = noode -> prev ;
    new_node -> next = noode ;
    noode -> prev -> next = new_node ;
    noode -> prev = new_node ;
} 

int main(){
    // node* tail = NULL ;
    // node* head = NULL ;
    node* tail = malloc(sizeof(node));
    tail -> element = 1 ;
    tail -> prev = NULL ;
    tail -> next = malloc(sizeof(node));
    node* head = tail -> next ;
    head -> element = 2 ;
    head -> prev = tail ;
    head -> next = NULL ;
    // init( &tail , &head , 1 );
    // insert_beginning( &tail , 0 );
    insert_end( &head , 4 );
    insert_after( head -> prev , 3 );
    insert_before( tail -> next , 9 );

    for( node* curr = tail ; curr != NULL ; curr = curr -> next ){
        printf("%d ", curr -> element );
    }

    deallocate( &tail , &head ) ;
    return 0 ;
}