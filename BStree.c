/********************************

把二元查找树转变成排序的双向链表
输入一棵二元查找树，将该二元查找树转换成一个排序的双向链表。
要求不能创建任何新的结点，只调整指针的指向。

********************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BStree.h"

TREE_INIT_HEAD(head, 40);


int main(int argc, char *argv[])
{
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


    return 0;
}


struct tree_node *create_tree_node(int num)
{
    struct tree_node *dest = (struct tree_node *)malloc(sizeof(struct tree_node));
    if(dest == NULL)
    {
    	printf("[ERROR]: create tree node failed\n");
        return NULL;
    }

    else
    {
        dest->num = num;
        dest->left = NULL;
        dest->right = NULL;
    }

    return dest;
}

void insert_tree_node(struct tree_node * dest)
{
    if(dest == NULL)
    {
        printf("[ERROR]: dest node is NULL\n");
        return;
    }

    struct tree_node * ptree_node;
    for(ptree_node = &head; ptree_node != NULL; )
    {
        if(ptree_node->num > dest->num)
        {
            if(ptree_node->left == NULL)
            {
                ptree_node->left = dest;
                break;
            } 
            else
               ptree_node = ptree_node->left;
        }
        else if(ptree_node->num < dest->num)
        {
            if(ptree_node->right == NULL)
            {
            	ptree_node->right = dest;
            	break;
            }                
            else
               ptree_node = ptree_node->right;
        }
        else
            printf("[WARNING]: the insert num had exist.\n");
    }
    
}

void print_tree_num(struct tree_node *dest)
{
    struct tree_node *p_tree = dest;
    if(p_tree)
    {
        print_tree_num(p_tree->left);
        printf("p_tree.num = %d\n", p_tree->num);
        print_tree_num(p_tree->right);
    }

    return ;
}

