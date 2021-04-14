#define NULL
#include <cstdlib>
struct node{
    int data;
    struct node *next;
};

typedef struct node node_t;
typedef struct node* nodeptr_t;

nodeptr_t build_one_two(){
//    创建两个空指针并初始化
    nodeptr_t head = NULL;
    nodeptr_t second = NULL;
    head = (nodeptr_t)(malloc(sizeof(node_t)));
    second = (nodeptr_t )(malloc(sizeof(node_t)));
//    给结构体指针指向的结构体的data赋值
    head -> data =  1;
    second -> data = 2;
    head -> next = second;
    second ->  next = NULL;
//    返回头指针
    return head;
}

nodeptr_t build_one_two_better(){
//    创建head指针
    nodeptr_t head = (nodeptr_t)(malloc(sizeof(node_t)));
//    给结构体指针指向的结构体的data赋值
    head -> data =  1;
    head -> next = (nodeptr_t)(malloc(sizeof(node_t)));
    head -> next -> data = 2;
    head ->  next -> next = NULL;
//    返回头指针
    return head;
}

//创建链表
nodeptr_t list_create(){
    nodeptr_t head = (nodeptr_t)(malloc(sizeof(node_t)));
    head -> data = 1;
    head -> next = NULL;
    return head;
}

//遍历链表，求链表节点个数
int count_array(nodeptr_t head){
    int count = 0;
    nodeptr_t current = head;
    while(current -> next != NULL)
    {
        count ++;
        current = current -> next;
    }
    return count;
}

//在链表结尾插入结点
nodeptr_t insert_tail(nodeptr_t head, int val){
    nodeptr_t current = head;
    for (; current -> next != NULL; current = current -> next);
    nodeptr_t new_node = (nodeptr_t)malloc(sizeof (node_t));
    new_node -> data = val;
    new_node -> next = NULL;
    current -> next = new_node;
    return head;
}

//在链表结尾删除结点
void delete_tail(nodeptr_t head){
    //处理链表长度为1的特殊情况
    if (head -> next == NULL)
    {
        free(head);
        return;
    }
    nodeptr_t current= head;
    for (; current -> next -> next != NULL; current = current -> next);
    free(current -> next);
    current -> next = NULL;
}

//在链表头结点添加结点

//在任意位置删除、添加结点