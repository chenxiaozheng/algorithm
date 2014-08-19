#include <stdio.h>
#include "BStree.h"

int main(int argc, char *argv[])
{

	extern struct tree_node head;

    printf("head.num = %d\n", head.num);
    
    insert_tree_node(create_tree_node(10));
    insert_tree_node(create_tree_node(18));
    insert_tree_node(create_tree_node(12));
    insert_tree_node(create_tree_node(1));
    insert_tree_node(create_tree_node(9));
    insert_tree_node(create_tree_node(3));
    insert_tree_node(create_tree_node(50));
    insert_tree_node(create_tree_node(70));
    insert_tree_node(create_tree_node(100));
    insert_tree_node(create_tree_node(10000));

    print_tree_num(&head);

    tree_transfer_list(&head);

    return 0;

}

