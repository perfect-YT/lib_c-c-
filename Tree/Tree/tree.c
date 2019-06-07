
#include"Tree.h"




//通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
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
//遍历
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

//非递归遍历
//层序遍历
//void BinaryTreeLevelOrder(BTNode* root)
//判断二叉树是否完全二叉树
//void BinaryTreeComplete(BTNode* root)