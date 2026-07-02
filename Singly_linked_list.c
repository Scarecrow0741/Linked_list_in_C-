#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int element ;
    struct node* next ;
} node ;

void insert_beginning( node** root , int value ){
    node* new_node = malloc(sizeof(node));
    if( new_node == NULL ){
        exit(1);
    }
    
    new_node -> element = value ;
    new_node -> next = *root ;
    *root = new_node ;
}

void insert_end( node** root , int value ){
    node* new_node = malloc(sizeof(node));
    if( new_node == NULL ){
        exit(1);
    }

    new_node -> next = NULL ;
    new_node -> element = value ;
    // if the linklist is empty at the start
    if ( *root == NULL ){ 
       *root = new_node ;
       return ;
    }
    node* curr = *root ;
    while ( curr -> next != NULL ){
        curr = curr -> next ;
    }    
    curr -> next = new_node ;
}

void insert_after(node* root , int value ){
    node* new_node = malloc(sizeof(node));
    if( new_node == NULL ){
        exit(1) ;
    }
    new_node -> element = value ;
    new_node -> next = root -> next ;
    root -> next = new_node ;
}

void insert_sort( node** root , int value ){
    if ( *root == NULL || (*root)-> element >= value ){
        insert_beginning( root , value );
        return;
    }
    
    node* curr = *root ;
    while( curr -> next  != NULL ){
        if( curr -> next -> element >= value ){
            insert_after( curr , value);
            return;
        }
        curr = curr -> next ;
    }
    insert_after(curr , value);
}

void delete_after( node* root ){
    root -> next = root -> next -> next ;
}

void deallocate( node ** root ){
    node* curr = *root ;
    while ( curr != NULL ){
        node* aux = curr ;
        curr = curr -> next ;
        free(aux);
    }
    *root = NULL ;
}

void reverse( node** root ){
    node* prev = NULL ;
    node* curr = *root ;
    while( curr != NULL ){
        node* nex = curr-> next ;
        curr -> next = prev ;
        prev = curr ;
        curr = nex ;
    }
    *root = prev ;
}

int main (){
    // node* root = NULL ;
    node* root = malloc(sizeof(node));
    if ( root == NULL ){
        exit(2);
    }
    root -> element = 4 ;
    root -> next = NULL ;
    
    insert_beginning( &root, 3 );
    insert_end( &root , 5 );
    insert_end( &root , 6 );
    insert_beginning( &root, 3 );
    // insert_beginning( &root, 1);
    // insert_after( root, 2 );
    // insert_sort( &root,9 );
    // delete_after(root);
    // reverse( &root );

    for( node* curr = root ; curr != NULL ; curr = curr -> next ){
        printf("%d\n", curr -> element );
    }
    deallocate(&root);

}