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

/*將二叉树转换成链表的函数， 该函数暂时有问题 2014-08-19,23:06*/
static tree_node *tree_transfer_list(struct tree_node *dest)
{
    struct tree_node *ptemp1 = NULL;
    struct tree_node *ptemp2 = NULL;
    struct tree_node *p_tree = dest;

    if(p_tree->left)
    {
        ptemp1 = tree_transfer_list(p_tree->left);
        p_tree->right = ptemp1;
    }
    else
    {
        ptemp2 = tree_transfer_list(p_tree->right);
        p_tree->left = ptemp2;
    }
    
    return p_tree;

/*void print_list(struct tree_node *dest)
{
    
}*/

