
#include"Tree.h"




//ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
//BTNode* tree = (BTNode*)malloc(sizeof(BTNode));

BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{

	
	if(a[*pi]== '#')
	{
		(*pi)++;
		return NULL;
	}
	else
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->data= a[*pi];
		(*pi)++;
		root->left= BinaryTreeCreate(a, pi);
		root->right= BinaryTreeCreate(a, pi);

		return root;
	}
}
//void BinaryTreeDestory(BTNode** root)

//int BinaryTreeSize(BTNode* root)
//int BinaryTreeLeafSize(BTNode* root)
//int BinaryTreeLevelKSize(BTNode* root, int k)

//BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
//����
void BinaryTreePrevOrder(BTNode* root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		printf("%c ",root->data);
		BinaryTreePrevOrder(root->left);
		BinaryTreePrevOrder(root->right);
	}
}


void BinaryTreeInOrder(BTNode* root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		BinaryTreePrevOrder(root->left);
		printf("%c ",root->data);
		BinaryTreePrevOrder(root->right);
	}
}
//void BinaryTreePostOrder(BTNode* root)

//�ǵݹ����
//�������
//void BinaryTreeLevelOrder(BTNode* root)
//�ж϶������Ƿ���ȫ������
//void BinaryTreeComplete(BTNode* root)