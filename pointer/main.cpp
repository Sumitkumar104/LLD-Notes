// 1. What will be the output of the following program?
#include <iostream>
using namespace std;

class TreeNode
{
    int val;
    // TreeNode left;     wrong way use pointer
    // TreeNode right;    wrong
};

// The issue here is that TreeNode left and TreeNode right are direct members of the TreeNode class. This causes infinite recursion when trying to instantiate a TreeNode object, as each TreeNode contains other TreeNode objects, which again contain TreeNode objects, and so on. This will eventually lead to a stack overflow error.

int main()
{
    int a = 32;
    int *ptr = &a; //  &a = hexa address of a
    char ch = 'A', &cho = ch;

    cho += a;
    *ptr += ch;
    cout << a << ", " << ch << endl;
    return 0;
}