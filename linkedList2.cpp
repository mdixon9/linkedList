#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * @brief contains a value and pointer to another node of same type
 * 
 */
struct node {
    
    int data;
    node *next;
};

// Instantiate the head node a travel node and a trail node
node *head_node   = nullptr;
node *travel_node = nullptr;
node *trail_node  = nullptr;

/**
 * @brief Create a new node object
 * 
 * @param value - the value stored at that object default to -1
 * @return node* - returns the address of the new node object
 */
node *createNewNode(int value = -1){

    // allocates space in memory for type node
    node *new_node = new node;

    new_node->data = value;
    new_node->next = nullptr;

    return (new_node);
} // END of create_new_node

/**
 * @brief - algorithm for inserting a new node into a linked list
 * 
 * @param head_node - references the head node of the linked list 
 * @param the_new_node - references the new node that is to be inserted
 * @return node* - returns the address of the head node
 */
node *insertNode(node *head_node, node *the_new_node)
{
    // if list is empty then head node will be null
    if (head_node == nullptr)
    {
        head_node = the_new_node;
    }

    // list is not empty... find the correct insertion point for new node
    else
    {
        // travel node points to the address of the head node
        travel_node = head_node;
        
        // find insertion point
        while (travel_node->data < the_new_node->data && 
                    travel_node->next != nullptr){
            trail_node  = travel_node;
            travel_node = travel_node->next;
        }
        // insert before insertion point
        if (the_new_node->data <= travel_node->data)
        {
            // reassign head value with new node value if duplicate
            if (((trail_node == nullptr || (trail_node == head_node) &&
                the_new_node->data <= head_node->data)))
            {
                the_new_node->next = head_node;
                head_node         = the_new_node;
            }
            // insert before insertion point
            else
            {
                trail_node->next  = the_new_node;
                the_new_node->next = travel_node;
            }
        }
        // else insert after the insertion point
        else {
            the_new_node->next = travel_node->next;
            travel_node->next = the_new_node;
        }
    }

    return head_node;
} // END of insertNode

/**
 * @brief - steps through each node and prints the results after each iteration
 * 
 * @param head_node - pointer to the first node object in the linked list
 * @param node_data - value stored 
 */
void walkPrint(node *head_node, int node_data)
{
    printf("After Insert of %d: ", node_data);

    // the node walk is used to traverse the linked list
    node *walk = head_node;

    // iterate until the end of the list
    while (walk != nullptr){
        printf("%d%s", walk->data, (walk != nullptr) ? ", ":"");
        walk = walk -> next;
    }

    printf("NULL\n");
} // END of walkPrint


/**
 * @brief - reverses the linked list using recursion
 * 
 * @param head_node - references the head node of the linked list
 */
void reverse(node *head_node)
{
    if(head_node->next != nullptr)
    {
        reverse(head_node->next);
    }

    printf("%d ", head_node->data);
    return;
}

/**
 * @brief - deletes all of the nodes in the list
 * 
 * @param head_node - references the head node to the linked list
 */
void delete_nodes(node *head_node)
{
    printf("\nDeleting the list...\n");

    node *delete_node = head_node;

    while (head_node != nullptr)
    {
        delete_node = head_node;
        head_node   = head_node->next;

        delete delete_node;

        printf("*\n");
    }

    printf("List has been sucessfully deleted\n");
}

int main()
{
    int lst []  = { 4, 7, 9, 2, 3, 2, 9};
    int len = sizeof(lst) / sizeof(int);  

    // creates, inserts and then prints the linked list for each elem in lst[]
    for (int idx = 0; idx < len; ++idx)
    {
        // creates a new node for each elem in list
        node *the_new_node = createNewNode( lst[idx] );
        head_node          = insertNode(head_node, the_new_node);
        walkPrint(head_node, lst[idx]);
    }

    printf("\nReversed\n");
    reverse(head_node);
    printf("\n");


    delete_nodes(head_node);

    return 0;
}
