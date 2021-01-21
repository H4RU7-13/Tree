#include "BinTree.h"
#include <iostream>
#include <stack>
#include <queue>

bool BinSearchTree::find(int k)
{
    TreeNode* tmp = root;
    while (tmp != nullptr)
    {
        if (tmp->key == k)
        {
            return true;
        }
        if (k < tmp->key)
        {
           tmp = tmp->left;
        }
        else
        {
            tmp = tmp->right;
        }
    }
    return false;
}

bool BinSearchTree::findRecursive(TreeNode* rt, int k)
{
    if (rt == nullptr)
    {
        return false;
    }
    if (k == rt->key)
    {
        return true;
    }
    if (k < rt->key)
    {
        return findRecursive(rt->left, k);
    }
    else
    {
        return findRecursive(rt->right, k);
    }
}

bool BinSearchTree::find_R(int k)
{
    return findRecursive(root, k);
}



void BinSearchTree::insert(int k)
{
    TreeNode* N = new TreeNode(k);
    TreeNode* tmp = root;

    if (root == nullptr)
    {
        root = N;
        return;
    }

    TreeNode* parent = nullptr;

    while (tmp != nullptr)
    {
        if (k == tmp->key) 
        {
            return;
        }
        if (k > tmp->key)
        {
            parent = tmp;
            tmp = tmp->right;
        }
        else
        {
            parent = tmp;
            tmp = tmp->left;
        }
    }
    if (parent->key < k)
    {
        parent->right = N;
    }
    else
    {
        parent->left = N;
    }
}

void BinSearchTree::insert_1(int k)
{
    TreeNode* N = new TreeNode(k);
    TreeNode* tmp = root;

    if (root == nullptr)
    {
        root = N;
        return;
    }

    TreeNode* parent = nullptr;

    while (tmp != nullptr)
    {
        if (k >= tmp->key)
        {
            parent = tmp;
            tmp = tmp->right;
        }
        else
        {
            parent = tmp;
            tmp = tmp->left;
        }
    }
    if (parent->key < k)
    {
        parent->right = N;
    }
    else
    {
        parent->left = N;
    }
}

void BinSearchTree::insertRecursive(TreeNode* &rt, int k)
{
    if (rt == nullptr)
    {
        rt = new TreeNode(k);
        return;
    }
    if (k == rt->key)
    {
        return;
    }
    if (k < rt->key)
    {
        insertRecursive(rt->left, k);
    }
    else
    {
        insertRecursive(rt->right, k);
    }
}

void BinSearchTree::insert_R(int k)
{
    insertRecursive(root, k);
}

void BinSearchTree::LNR_rec(TreeNode* rt)
{
    if (rt != nullptr)
    {
        LNR_rec(rt->left);
        cout << rt->key << endl;
        LNR_rec(rt->right);
    }
}

void BinSearchTree::LNR()
{
    LNR_rec(root);
}

void BinSearchTree::LRN()
{

}

void BinSearchTree::NLR_I()
{
    stack <TreeNode*> stck;
    TreeNode* tmp = root;
    while (true)
    {
        while (tmp != nullptr)
        {
            stck.push(tmp);
            cout << tmp->key << endl;
            tmp = tmp->left; 
        }
        if (stck.empty())
        {
            return;
        }
        tmp = stck.top();
        stck.pop();
        tmp = tmp->right;
    }
}

void BinSearchTree::Level_TR()
{
    TreeNode* tmp = root;
    queue <TreeNode*> qu1;

    if (tmp != nullptr)
    {
        qu1.push(tmp);
    }
    while (!qu1.empty())
    {
        tmp = qu1.front();
        cout << tmp->key << endl;
        qu1.pop();
        if (tmp->left)
        {
            qu1.push(tmp->left);
        }
        if (tmp->right)
        {
            qu1.push(tmp->right);
        }
    }
}

void BinSearchTree::Level_Print()
{
    TreeNode* tmp = root;
    queue <TreeNode*> qu1;
    int current, next;

    if (tmp != nullptr)
    {
        qu1.push(tmp);
        current = 1;
    }
    while (current != 0)
    {
        next = 0;
        for (int i = 0; i < current; i++)
        {
            tmp = qu1.front();
            cout << tmp->key << "  ";
            qu1.pop();
            if (tmp->left)
            {
                qu1.push(tmp->left);
                next++;
            }
            if (tmp->right)
            {
                qu1.push(tmp->right);
                next++;
            }
        }
        cout << endl;
        current = next;
    }
}

int BinSearchTree::Height()
{
    TreeNode* tmp = root;
    queue <TreeNode*> qu1;
    int current, next;
    int height = -1;

    if (tmp != nullptr)
    {
        qu1.push(tmp);
        current = 1;
    }
    while (current != 0)
    {
        next = 0;
        for (int i = 0; i < current; i++)
        {
            tmp = qu1.front();
            
            qu1.pop();
            if (tmp->left)
            {
                qu1.push(tmp->left);
                next++;
            }
            if (tmp->right)
            {
                qu1.push(tmp->right);
                next++;
            }
        }
        current = next;
        height++;
    }
    return height;
}

void BinSearchTree::LNR_I()
{
    stack <TreeNode*> stck;
    TreeNode* tmp = root;
    while (true)
    {
        while (tmp != nullptr)
        {
            stck.push(tmp);
            tmp = tmp->left;
        }
        if (stck.empty())
        {
            return;
        }
        tmp = stck.top();
        cout << tmp->key << endl;
        stck.pop();
        tmp = tmp->right;
    }
}

int BinSearchTree::Count_2_sons_I()
{
    stack <TreeNode*> stck;
    TreeNode* tmp = root;
    int count = 0;
    while (true)
    {
        while (tmp != nullptr)
        {
            stck.push(tmp);
            tmp = tmp->left;
        }
        if (stck.empty())
        {
            return count;
        }
        tmp = stck.top();
        if (tmp->left && tmp->right) count++;
        stck.pop();
        tmp = tmp->right;
    }
}

int BinSearchTree::Count_2_R()
{
    return Count_2_sons_R_P(root);
}

int BinSearchTree::Height_R()
{
    return Height_R_P(root);
}

int BinSearchTree::Min()
{
    TreeNode* tmp = root;

    while (tmp->left)
    {
        tmp = tmp->left;
    }
    return tmp->key;
}

int BinSearchTree::Min_R()
{
    return Min_RP(root);
}

int BinSearchTree::Max()
{
    TreeNode* tmp = root;

    while (tmp->right)
    {
        tmp = tmp->right;
    }
    return tmp->key;
}

int BinSearchTree::Max_R()
{
    return Max_RP(root);
}

void BinSearchTree::count_0()
{
    TreeNode* tmp = root;
    queue <TreeNode*> qu1;
    int current, next;

    if (tmp != nullptr)
    {
        qu1.push(tmp);
        current = 1;
    }
    while (current != 0)
    {
        next = 0;
        for (int i = 0; i < current; i++)
        {
            tmp = qu1.front();
            //cout << tmp->key << "  ";
            if (tmp->key == 0)cout << current - 1<< endl;
            qu1.pop();
            if (tmp->left)
            {
                qu1.push(tmp->left);
                next++;
            }
            if (tmp->right)
            {
                qu1.push(tmp->right);
                next++;
            }
        }
        cout << endl;
        current = next;
    }
}

void BinSearchTree::count_0_R()
{
    count_0_RP(root);
}

bool BinSearchTree::isFull()
{
    TreeNode* tmp = root;
    queue <TreeNode*> qu1;
    int current, next;
    int count = 1;

    if (tmp != nullptr)
    {
        qu1.push(tmp);
        current = 1;
    }
    while (current != 0)
    {
        next = 0;
        for (int i = 0; i < current; i++)
        {
            tmp = qu1.front();
            
            qu1.pop();
            if (tmp->left)
            {
                qu1.push(tmp->left);
                next++;
            }
            if (tmp->right)
            {
                qu1.push(tmp->right);
                next++;
            }
        }
        if (current != count)
        {
            return false;
        }
        count *= 2;
        current = next;
    }
    return true;
}

bool BinSearchTree::isFull_R()
{
    return isFull_RL(root, Height());
}

bool BinSearchTree::isPerf()
{
    return false;
}

bool BinSearchTree::isPerf_R()
{
    return false;
}

void BinSearchTree::sol_2()
{
    stack <TreeNode*> stck;
    TreeNode* tmp = root;
    while (true)
    {
        while (tmp != nullptr)
        {
            stck.push(tmp);
            tmp = tmp->left;
        }
        if (stck.empty())
        {
            return;
        }
        tmp = stck.top();
        if (tmp->left == nullptr && tmp->right == nullptr)
        {
            cout << tmp->key << endl;
        }
        stck.pop();
        tmp = tmp->right;
    }
}

void BinSearchTree::sol_2_R()
{
    sol_2_RP(root);
}

void BinSearchTree::Del_all_elm_I()
{
    TreeNode* tmp = root;
    queue <TreeNode*> qu1;
    int current = 0, next;

    if (tmp != nullptr)
    {
        qu1.push(tmp);
        current = 1;
    }
    while (current != 0)
    {
        next = 0;
        for (int i = 0; i < current; i++)
        {
            tmp = qu1.front();
            qu1.pop();
            if (tmp->left)
            {
                qu1.push(tmp->left);
                next++;
            }
            if (tmp->right)
            {
                qu1.push(tmp->right);
                next++;
            }
            delete tmp;
            //tmp = nullptr;
        }
        cout << endl;
        current = next;
    }
    root = nullptr;
}

void BinSearchTree::Del_all_elm_R()
{
    Del_all_elm_RP(root);
}

void BinSearchTree::Del_by_height(int k)
{
    TreeNode* tmp = root;
    queue <TreeNode*> qu1;
    int current, next;
    int height = -1;

    if (tmp != nullptr)
    {
        qu1.push(tmp);
        current = 1;
    }
    while (current != 0)
    {
        next = 0;
        for (int i = 0; i < current; i++)
        {
            tmp = qu1.front();

            qu1.pop();
            if (tmp->left)
            {
                qu1.push(tmp->left);
                next++;
            }
            if (tmp->right)
            {
                qu1.push(tmp->right);
                next++;
            }
        }
        current = next;
        height++;
        if (height == k)
        {
            while (!qu1.empty())
            {
                tmp = qu1.front();
                Del_all_elm_RP(tmp);
                qu1.pop();
            }
            return;
        }
    }
}

void BinSearchTree::Del_by_height_R(int h)
{
    Del_by_height_RP(root, h);
}

int BinSearchTree::Count_2_sons_R_P(TreeNode* rt)
{
    if (rt == nullptr)
    {
        return 0;
    }

    int Left_count = Count_2_sons_R_P(rt->left);
    int Right_count = Count_2_sons_R_P(rt->right);

    if (rt->left != nullptr && rt->right != nullptr)
    {
        return Left_count + Right_count + 1;
    }
    if (rt->left != nullptr)
    {
        return Left_count;
    }
    if (rt->right != nullptr)
    {
        return Right_count;
    }
    return 0;
}

void BinSearchTree::NLR_R(TreeNode* rt)
{
    if (rt != nullptr)
    {
        cout << rt->key << endl;
        NLR_R(rt->left);
        NLR_R(rt->right);
    }
}

int BinSearchTree::Height_R_P(TreeNode* rt)
{
    if (rt == nullptr)
    {
        return -1;
    }

    int HL = Height_R_P(rt->left);
    int HR = Height_R_P(rt->right);

    return HL > HR ? HL + 1: HR + 1;
}

void BinSearchTree::LRN_R_P(TreeNode* rt)
{

}

bool BinSearchTree::isFull_RL(TreeNode* rt,int h)
{
    if (rt == nullptr)
    {
        return false;
    }
    if ((rt->left == nullptr && rt->right == nullptr) && h == 0)
    {
        return true;
    }

    return isFull_RL(rt->left, h - 1) && isFull_RL(rt->right, h - 1);
}

bool BinSearchTree::isPerf_RL(TreeNode* rt, int h)
{
    if (rt == nullptr)  
    {
        return false;
    }

    if ((rt->left == nullptr && rt->right == nullptr) && h == 0)
    {
        return true;
    }

    if (h == 1 && rt->left != nullptr) // kaxvac che aj vordu goyutyunic
    {
        return true;
    }

    if (h == 1 && rt->right != nullptr && rt->left == nullptr)
    {
        return false;
    }

    if ((isFull_RL(rt->left, h - 1) && (isFull_RL(rt->right, h - 2) || isPerf_RL(rt->right, h - 1))) || (isPerf_RL(rt->left, h - 1) && isFull_RL(rt->right, h - 2)))
    {
        return true;
    }
}

void BinSearchTree::Del_all_elm_RP(TreeNode* &rt)
{
    if (rt == nullptr) 
    {
        return;
    }
    Del_all_elm_RP(rt->left);
    Del_all_elm_RP(rt->right);
    cout << "alert1";
    TreeNode* tmp = rt;
    rt = nullptr;
    delete tmp;
    cout << "alert2";
    return;
}

void BinSearchTree::Del_by_height_RP(TreeNode* rt, int k)
{
    if (rt == nullptr)
    {
        return;
    }
    else if (k == 0)
    {
        Del_all_elm_RP(rt);
    }
    Del_by_height_RP(rt->left, k - 1);
    Del_by_height_RP(rt->right, k - 1);
}

int BinSearchTree::Min_RP(TreeNode* rt)
{
    if (rt->left == nullptr)
    {
        return rt->key;
    }
    return Min_RP(rt->left);
}

int BinSearchTree::Max_RP(TreeNode* rt)
{
    if (rt->right == nullptr)
    {
        return rt->key;
    }
    return Max_RP(rt->right);
}

void BinSearchTree::sol_2_RP(TreeNode* rt)
{
    if (rt == nullptr)
    {
        return;
    }

    if (rt->left == nullptr && rt->right == nullptr)
    {
        cout << rt->key << endl;
        return;
    }
    
    if (rt->left)
    {
        sol_2_RP(rt->left);
    }
    if (rt->right)
    {
        sol_2_RP(rt->right);
    }
}

void BinSearchTree::count_0_RP(TreeNode* rt)
{
    int h = Height_R_P(rt);

    for (int i = 1; i <= h; i++)
    {
        if (printL(rt, i))
        {
            cout << i << endl;
        }
    }
}

void BinSearchTree::printLevel_R(TreeNode* rt)
{
    int h = Height_R_P(rt);
    
    for (int i = 1; i <= h; i++)
    {
        printGivenLevel(rt, i);
        cout << endl;
    }
}

void BinSearchTree::printGivenLevel(TreeNode* rt, int h)
{
    if (rt== NULL)
        return;
    if (h == 1) 
    {
        cout << rt->key << " ";
    }
    else if (h > 1)
    {
        printGivenLevel(rt->left, h - 1);
        printGivenLevel(rt->right, h - 1);
    }
}

int BinSearchTree::getLevelUtil(TreeNode* rt, int info, int h)
{
    if (rt == nullptr)
        return 0;

    if (rt->key == info)
        return h;

    int downlevel = getLevelUtil(rt->left, info, h + 1);
        
    if (downlevel != 0)
        return downlevel;

    downlevel = getLevelUtil(rt->right, info, h + 1);
        
    return downlevel;
}

int BinSearchTree::getLevel(TreeNode* rt, int info = 0)//funkcian kareli e ogtagorcel nayv ayl tveri hamar,bayc tvayl depqum info = 0
{
    return getLevelUtil(rt, info, 1);
}

bool BinSearchTree::printL(TreeNode* rt, int h)
{
    if (rt == NULL)
        return;
    if (h == 1 && rt->key == 0)
    {
        return true;
    }
    else if (h > 1)
    {
        printGivenLevel(rt->left, h - 1);
        printGivenLevel(rt->right, h - 1);
    }
}

