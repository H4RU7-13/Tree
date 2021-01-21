#pragma once
#include <iostream>
using namespace std;

struct TreeNode
{
	int key;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int k, TreeNode* l = nullptr, TreeNode* r = nullptr) :key(k), left(l), right(r) {};
};

class BinSearchTree
{private:
	TreeNode* root;
	void LNR_rec(TreeNode* rt);
	bool findRecursive(TreeNode* rt,int k);
	void insertRecursive(TreeNode* &rt, int k);
	int Count_2_sons_R_P(TreeNode* rt);
	void NLR_R(TreeNode* rt);
	int Height_R_P(TreeNode* rt);
	void LRN_R_P(TreeNode* rt);
	bool isFull_RL(TreeNode* rt, int h);
	bool isPerf_RL(TreeNode* rt, int h);
	void Del_all_elm_RP(TreeNode*& rt);
	void Del_by_height_RP(TreeNode* rt,int h);
	int Min_RP(TreeNode* rt);
	int Max_RP(TreeNode* rt);
	void sol_2_RP(TreeNode* rt);
	void count_0_RP(TreeNode* rt);
	void printLevel_R(TreeNode* rt);
	void printGivenLevel(TreeNode* rt,int h);
	int getLevelUtil(TreeNode* rt, int info, int h);
	int getLevel(TreeNode* rt, int info);
	bool printL(TreeNode* rt, int h);
	
public:
	BinSearchTree() :root(nullptr) {};
	~BinSearchTree() {};
	bool find(int k);
	bool find_R(int k);
	void insert(int k);
	void insert_1(int k);
	void insert_R(int k);
	void LNR();
	void LRN();
	void NLR_I();
	void Level_TR();
	void Level_Print();
	int Height();
	void LNR_I();
	int Count_2_sons_I();
	int Count_2_R();
	int Height_R();
	int Min();
	int Min_R();
	int Max();
	int Max_R();
	void count_0();
	void count_0_R();
	bool isFull();
	bool isFull_R();
	bool isPerf();
	bool isPerf_R();
	void sol_2();
	void sol_2_R();
	void Del_all_elm_I();
	void Del_all_elm_R();
	void Del_by_height(int h);
	void Del_by_height_R(int h);
};

