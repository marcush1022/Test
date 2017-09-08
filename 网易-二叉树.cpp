/*
链接：https://www.nowcoder.com/questionTerminal/d567727f21a247f7b64ba32431cb9a19
来源：牛客网

有一棵二叉树，树上每个点标有权值，权值各不相同，请设计一个算法算出权值最大的叶节点到权值最小的叶节点的距离。
二叉树每条边的距离为1，一个节点经过多少条边到达另一个节点为这两个节点之间的距离。
给定二叉树的根节点root，请返回所求距离。

解：对二叉树节点进行编码，然后以编码建图，然后图的begin就是编码最小的，end就是编码最大的
然后去重求距离
*/

class Tree {
public:
    void code(TreeNode *root, map<int, string> &mp, string str)
    {
        if(root->left==NULL && root->right==NULL)
        {
            mp[root->val]=str;
            return ;
        }
        if(root->left)
            code(root->left, mp, str+'1');
        if(root->right)
            code(root->right, mp, str+'0');
    }
 
    int getDis(TreeNode* root) {
        // write code here
        map<int, string> mp;
        string str;
        code(root, mp, str);
        map<int, string>::iterator it=mp.begin();
        string s1=it->second;
        it=--mp.end();
        string s2=it->second;
        int i=0, j=0;
        while(i<s1.length() && j<s2.length() && s1[i]==s2[j])
        {
            ++i;
            ++j;
        }
        return s1.length()-i+s2.length()-j;
    }
};
