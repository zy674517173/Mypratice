/***************************************************************
数据结构之链表：
    完成链表的
        创建
        删除
        插入
        修改
***************************************************************/
#include <stdio.h>
#include <stdlib.h>

//节点的结构体
typedef struct student{
    int iScore;
    struct student *next;

}Linklist;

//创建链表,传入n，代表需要创建多少个节点
Linklist *creat_linklist(int n){
    int i = 0;
    Linklist *head, *node, *end;    //创建头节点，尾节点，中间节点
    head = (Linklist*)malloc(sizeof(Linklist));
    head = end;                     //初始链表为空，头节点等于尾节点

    for(i;i<n;i++){
        node = (Linklist*)malloc(sizeof(Linklist));
        printf("请输入第%d学生的成绩\n", i+1);
        scanf("%d", &node->iScore);
        end->next = node;
        end = node;
    }
    end->next = NULL;       //最后一位指针指向空
    return head;
}

//插入节点
void insert_Linklist(Linklist *head,int n){
    int i;
    Linklist *p = head, *in_list;                 //定义指针p储存链表的头节点，指针in_list储存要插入的节点

    while(i < n && p != NULL){
        p = p->next;
        i++;
    }

    if(p != NULL){
        in_list = (Linklist*)malloc(sizeof(Linklist));
        printf("请输入要插入的数据\n");
        scanf("%d", &in_list->iScore);

        in_list->next = p->next;
        p->next = in_list;
    }else{
        printf("节点不存在\n");
    }
}

//删除节点
void delete_Linklist(Linklist *head,int n){
    int i = 0;
    Linklist *p = head, *last_de_list;

    while(i < n && p != NULL){
        last_de_list = p;             //令de_list等于p
        p = p->next;              //这步令p等于下一个，就是最后要删除的那个，但de_list仍然是p前面的那个
        i++;
    }

    if(p != NULL){
        last_de_list->next = p->next;
        free(p);
    }else{
        printf("节点不存在\n");
    }
}

//修改节点
void change_Linklist(Linklist *head, int n){
    int i = 0;
    Linklist *p = head;

    while(i < n && p != NULL){
        p = p->next;
        i++;
    }

    if(p != NULL){
        printf("请输入修改的数据\n");
        scanf("%d", &p->iScore);
    }else{
        printf("节点不存在\n");
    }
}

int main(){
    Linklist *head,*p;

    head = creat_linklist(5);
    p = head;

    while(p->next != NULL){
        p = p->next;
        printf("%d", p->iScore);
    }
    return 0;
}

