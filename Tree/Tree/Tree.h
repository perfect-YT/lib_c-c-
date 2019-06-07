#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;

typedef struct BTNode
{
	BTDataType data;
	struct BTNode* left;
	struct BTNode* right;

}BTNode;

//通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int* pi);
//清除树
void BinaryTreeDestory(BTNode** root);
//节点个数
int BinaryTreeSize(BTNode* root);
//叶子个数
int BinaryTreeLeafSize(BTNode* root);
//第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
//找x节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
//遍历前中后
void BinaryTreePrevOrder(BTNode* root);
void BinaryTreeInOrder(BTNode* root);
void BinaryTreePostOrder(BTNode* root);

//非递归遍历
//层序遍历
void BinaryTreeLevelOrder(BTNode* root);
//判断二叉树是否完全二叉树
void BinaryTreeComplete(BTNode* root);





