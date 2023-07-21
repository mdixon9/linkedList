#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


// -------------------------
// Define Node class
// -------------------------
class MyNode
{
    public:
        // basic singly linked list node structure
        int data;
        MyNode *next;

        // Default constructor if no argument is passed
        MyNode()
        {
            int data = 0;
            next     = nullptr;
        }

        // Called when argument is passed to create new node
        MyNode(int data)
        {
            this->data = data;
            this->next = nullptr;
        }   
};


// -------------------------
// Define Linked list class
// -------------------------
class LinkedList
{
    private:
        MyNode *head;

    public:
        LinkedList()
        {
            head = nullptr;
        }

        /**
         * @brief Create a new node object
         * 
         * @param n value to be stored in new node
         * @return MyNode* 
         */
        MyNode *create_new_node(int n = -1)
        {
            MyNode *new_node = new MyNode(n);

            return new_node;
        }

        // ------------------------------------------
        // function for inserting node into the list 
        // ------------------------------------------
        void insert_sort(int num)
        {
            // creates new node each time function is called
            MyNode *insert_node = create_new_node(num);

            // define travel and trail node for traversing the list
            MyNode *travel_node = head; 
            MyNode *trail_node  = nullptr;

            // -------------------------------
            // begin logic for insertion sort
            // -------------------------------

            // check if list is empty before inserting new node
            if (head == nullptr)
            {
                head = insert_node;
            }

            // list isnt empty
            else
            {
                // find insertion point for new node
                while (insert_node->data >= travel_node->data && 
                        travel_node->next != nullptr)
                {   
                    // travel and trail go to the next nodes
                    trail_node  = travel_node;
                    travel_node = travel_node->next;
                }

                // ------------------------------------------------------------
                // check if node get inserted before or after the travel node?
                // ------------------------------------------------------------

                // ----------------------
                // after the travel node
                // ----------------------
                if (insert_node->data >= travel_node->data)
                {
                    insert_node->next = travel_node->next;
                    travel_node->next = insert_node;
                }

                // ----------------------
                // before the travel node
                // ----------------------
                else
                {
                    // check for new head node
                    if (trail_node == nullptr)
                    {
                        // est. new head node
                        insert_node->next = travel_node;
                        head              = insert_node;
                    }

                    // not a new head node
                    else
                    {
                        insert_node->next = travel_node;
                        trail_node->next  = insert_node;
                    }
                }
                
            }
        }

        // -------------------------
        // Reverses the linked list
        // -------------------------
        void reverse()
        {
            // -------------------------------------------------------------------------
            // Using pointers
            // -------------------------------------------------------------------------

            if (head == nullptr)
            {
                printf("List is empty\n");
                return;
            }

            MyNode *travel_node = head;
            MyNode *trail_node  = nullptr;
            MyNode *next_node;

            
            while(next_node != nullptr)
            {
            // -----------------------------------------------------------------
            // stores the next node so that we can still point to the next node
            //     after modifying the current node
            // -----------------------------------------------------------------
                next_node = travel_node->next;

                // points the current node to the previous node
                travel_node->next = trail_node;

                // goes to the next node
                trail_node  = travel_node;
                travel_node = next_node;
            } // END while - loop walking the list

            head = trail_node;
        }

        // -----------------------
        // Prints the linked list
        // -----------------------
        void print_list()
        {
            MyNode *travel_node = head;

            while (travel_node != nullptr)
            {
                printf("%d -> ", travel_node->data);
                travel_node = travel_node->next;
            }

            printf("NULL");
            printf("\n");
            
        }

        // -------------------------------------
        //* Deletes all of the nodes in the list
        // -------------------------------------
        void delete_nodes()
        {
            printf("\nDeleting the list...\n");

            MyNode *delete_node = head;

            while (head != nullptr)
            {
                delete_node = head;
                head = head->next;

                delete delete_node;
            }

            printf("List has been sucessfully deleted\n");
        }
};

int main()
{
    LinkedList my_list;

    int nums[] = {12, 45, 2, 6, 8, 356, 89, 3};
    int len    = sizeof(nums) / sizeof(nums[0]);


    // inserts items into list
    for (int i = 0; i < len; i++)
    {
        my_list.insert_sort( nums[i] );
    }

    // prints the list
    my_list.print_list();


    // deletes the nodes in the list
    my_list.delete_nodes();

    return 0;
}