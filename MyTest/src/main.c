/***************************************************************
���ݽṹ֮����
    ��������
        ����
        ɾ��
        ����
        �޸�
***************************************************************/
#include <stdio.h>
#include <stdlib.h>

//�ڵ�Ľṹ��
typedef struct student{
    int iScore;
    struct student *next;

}Linklist;

//��������,����n��������Ҫ�������ٸ��ڵ�
Linklist *creat_linklist(int n){
    int i = 0;
    Linklist *head, *node, *end;    //����ͷ�ڵ㣬β�ڵ㣬�м�ڵ�
    head = (Linklist*)malloc(sizeof(Linklist));
    head = end;                     //��ʼ����Ϊ�գ�ͷ�ڵ����β�ڵ�

    for(i;i<n;i++){
        node = (Linklist*)malloc(sizeof(Linklist));
        printf("�������%dѧ���ĳɼ�\n", i+1);
        scanf("%d", &node->iScore);
        end->next = node;
        end = node;
    }
    end->next = NULL;       //���һλָ��ָ���
    return head;
}

//����ڵ�
void insert_Linklist(Linklist *head,int n){
    int i;
    Linklist *p = head, *in_list;                 //����ָ��p���������ͷ�ڵ㣬ָ��in_list����Ҫ����Ľڵ�

    while(i < n && p != NULL){
        p = p->next;
        i++;
    }

    if(p != NULL){
        in_list = (Linklist*)malloc(sizeof(Linklist));
        printf("������Ҫ���������\n");
        scanf("%d", &in_list->iScore);

        in_list->next = p->next;
        p->next = in_list;
    }else{
        printf("�ڵ㲻����\n");
    }
}

//ɾ���ڵ�
void delete_Linklist(Linklist *head,int n){
    int i = 0;
    Linklist *p = head, *last_de_list;

    while(i < n && p != NULL){
        last_de_list = p;             //��de_list����p
        p = p->next;              //�ⲽ��p������һ�����������Ҫɾ�����Ǹ�����de_list��Ȼ��pǰ����Ǹ�
        i++;
    }

    if(p != NULL){
        last_de_list->next = p->next;
        free(p);
    }else{
        printf("�ڵ㲻����\n");
    }
}

//�޸Ľڵ�
void change_Linklist(Linklist *head, int n){
    int i = 0;
    Linklist *p = head;

    while(i < n && p != NULL){
        p = p->next;
        i++;
    }

    if(p != NULL){
        printf("�������޸ĵ�����\n");
        scanf("%d", &p->iScore);
    }else{
        printf("�ڵ㲻����\n");
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

