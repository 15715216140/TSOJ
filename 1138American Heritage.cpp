1138:American Heritage
�Ѷȣ� �������    ʱ�����ƣ� 1000MS   �ռ����ƣ� 16MB   �ύ���� 7   ͨ������ 2 ��Ŀ��Դ: nuistoj
��Ŀ����
��Ŀ����:
Farmer John takes the heritage of his cows very seriously. He is not, however, a truly fine bookkeeper. He keeps his cow genealogies as binary trees and, instead of writing them in graphic form, he records them in the more linear tree in-order" and tree pre-order" notations.

Your job is to create the `tree post-order" notation of a cow"s heritage after being given the in-order and pre-order notations. Each cow name is encoded as a unique letter. (You may already know that you can frequently reconstruct a tree from any two of the ordered traversals.) Obviously, the trees will have no more than 26 nodes.

Here is a graphical representation of the tree used in the sample input and output:

              C
            /   
           /     
          B       G
         /      /
        A   D   H
           / 
          E   F

The in-order traversal of this tree prints the left sub-tree, the root, and the right sub-tree.

The pre-order traversal of this tree prints the root, the left sub-tree, and the right sub-tree.

The post-order traversal of this tree print the left sub-tree, the right sub-tree, and the root.

----------------------------------------------------------------------------------------------------------------------------
��Ŀ���⣺
����һ�ö�������ǰ�����(preorder)���������(inorder)�������ĺ������(postorder)��

����Ҫ֪���ģ�
1���������� ��ض�����������ϻ��������ҵ���

2������ ���������ӳ�Ķ����������档
����������
Line 1:

The in-order representation of a tree.

Line 2:

The pre-order representation of that same tree.

���������
A single line with the post-order representation of the tree.

��������:
ABEDFCHG

CBADEFGH

�������:
AEFDBHGC
#include <iostream>
#include <algorithm>
using namespace std;
string in, pre;
void f(int root, int be, int end) {
	if(end < be)	return ;
	int i = be;
	while(in[i] != pre[root])	i++;
	f(root+1,be,i-1);
	f(root+1+i-be,i+1,end);
	cout << in[i];
	return ;
}
int main() {
	cin >> in >> pre;
	f(0,0,in.size()-1);
	return 0;
}
