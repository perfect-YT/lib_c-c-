#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;

typedef struct BTNode
{
	BTDataType data;
	struct BTNode* left;
	struct BTNode* right;

}BTNode;

//ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int* pi);
//�����
void BinaryTreeDestory(BTNode** root);
//�ڵ����
int BinaryTreeSize(BTNode* root);
//Ҷ�Ӹ���
int BinaryTreeLeafSize(BTNode* root);
//��k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);
//��x�ڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
//����ǰ�к�
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);

//�ǵݹ����
//�������
void BinaryTreeLevelOrder(BTNode* root);
//�ж϶������Ƿ���ȫ������
void BinaryTreeComplete(BTNode* root);





