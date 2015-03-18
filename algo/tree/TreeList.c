#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/* The node type from which both the tree and list are built */
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
typedef struct node *Node;



/*
 helper function -- given two list nodes, join them
 together so the second immediately follow the first.
 Sets the .next of the first and the .previous of the second.
*/
static void
join (Node a, Node b)
{
  a->right = b;
  b->left = a;
}


/*
 helper function -- given two circular doubly linked
 lists, append them and return the new list.
*/
static Node
append (Node a, Node b)
{
  Node aLast, bLast;

  if (a == NULL)
    return (b);
  if (b == NULL)
    return (a);

  aLast = a->left;
  bLast = b->left;

  join (aLast, b);
  join (bLast, a);

  return (a);
}


/*
 --Recursion--
 Given an ordered binary tree, recursively change it into
 a circular doubly linked list which is returned.
*/
static Node
treeToList (Node root)
{
  Node aList, bList;

  if (root == NULL)
    return (NULL);

  /* recursively solve subtrees -- leap of faith! */
  aList = treeToList (root->left);
  bList = treeToList (root->right);

  /* Make a length-1 list ouf of the root */
  root->left = root;
  root->right = root;

  /* Append everything together in sorted order */
  aList = append (aList, root);
  aList = append (aList, bList);

  return (aList);

}


/* Create a new node */
  Node newNode (int data)
  {
    Node node = (Node) malloc (sizeof (struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
  }


/* Add a new node into a tree */
  void treeInsert (Node * rootRef, int data)
  {
    Node root = *rootRef;
    if (root == NULL)
      *rootRef = newNode (data);
    else
      {
	if (data <= root->data)
	  treeInsert (&(root->small), data);
	else
	  treeInsert (&(root->large), data);
      }
  }


  void printList (Node head)
  {
    Node current = head;

    while (current != NULL)
      {
	printf ("%d ", current->data);
	current = current->large;
	if (current == head)
	  break;
        }
    printf ("\n");
  }


/* Demo that the code works */
  int main ()
  {
    Node root = NULL;
    Node head;

    treeInsert (&root, 4);
    treeInsert (&root, 2);
    treeInsert (&root, 1);
    treeInsert (&root, 3);
    treeInsert (&root, 5);
    head = treeToList (root);
    printList (head);		/* prints: 1 2 3 4 5  */
    return 0;
  }
