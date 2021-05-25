#include <iostream>

 //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
//Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    
    ListNode *getMid(ListNode *start, ListNode *end)
    {
       if (start == nullptr) return nullptr;
       ListNode *slow, *fast;
       slow = fast = start;

       while (fast != end)
       {
           fast = fast->next;
           if (fast != end)
           {
               slow = slow->next;
               fast = fast->next;
           }
       }

       return slow;
    }
    
    TreeNode* populateTree(ListNode *start, ListNode *end)
    {
        if (start == end || start == nullptr) return nullptr;
       
        ListNode *mid;
        TreeNode *root;
        mid = getMid(start, end);
        if (mid == nullptr) return nullptr;
        root = new TreeNode(mid->val);
        
        //find mid here
        root->left = populateTree(start, mid);
        root->right = populateTree(mid->next, end);
               
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return new TreeNode(head->val);
    
        TreeNode *root = populateTree(head, nullptr);
        return root;
        
    }
};

void inorder(TreeNode *root)
{
    if (root == nullptr) return;
    inorder(root->left);
    std::cout << root->val << ", ";
    inorder(root->right);
}

int main()
{
    Solution solution;

    ListNode *head = nullptr;
    head = new ListNode(0);
    
    ListNode *p = head;
    for (int i = 1; i < 10; ++i)
    {
        p->next = new ListNode(i);
        p = p->next;
    }
    p = head;
    while (p)
    {
        std::cout << p->val << "->";
        p = p->next;
    }
    std::cout << '\n';

    TreeNode *root = solution.sortedListToBST(head);
    inorder(root);
    std::cout << std::endl;

    return 0;
}