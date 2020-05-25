package BinaryTree;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class BTtreeClass {
    BTNode<Character> b;
    String bstr;

    public BTtreeClass() {
        b = null;
    }

    public void CreateBTree(String str) {
        Stack<BTNode> st = new Stack<BTNode>();
        BTNode<Character> p = null;
        boolean flag = true;
        char ch;
        int i = 0;
        int len = str.length();
        while (i < len) {
            ch = str.charAt(i);
            switch (ch) {
                case '(':
                    st.push(p);
                    flag = true;
                    break;
                case ')':
                    st.pop();
                    break;
                case ',':
                    flag = false;
                    break;
                default:
                    p = new BTNode<Character>(ch);
                    if (b == null)
                        b = p;
                    else {
                        if (flag) {
                            if (!st.empty()) {
                                st.peek().lchild = p;
                            }
                        } else {
                            if (!st.empty()) {
                                st.peek().rchild = p;
                            }
                        }
                    }
                    break;
            }
            i++;
        }
    }

    public String toString(BTNode<Character> t) {
        if (t != null) {
            bstr += t.data;         //输出根节点值
            if (t.lchild != null || t.rchild != null) {
                bstr += "(";        //有孩子节点时输出“（”
                toString(t.lchild); //递归输出左子树
                if (t.rchild != null)
                    bstr += ",";    //有右孩子时输出“，”
                toString(t.rchild); //递归输出右子树
                bstr += ")";
            }
        }
        return bstr;
    }

    public BTNode<Character> findNode(BTNode<Character> t, char x) {
        BTNode<Character> p;
        if (t == null)
            return null;
        else if (t.data == x)
            return t;
        else {
            p = findNode(t.lchild, x);
            if (p != null)
                return p;
            else return findNode(t.rchild, x);
        }
    }

    public int height(BTNode<Character> t) {
        int h_l, h_r;
        if (t == null)
            return 0;
        else {
            h_l = height(t.lchild);
            h_r = height(t.rchild);
            return Math.max(h_l, h_r) + 1;
        }
    }

    public static int nodeCount(BTNode<Character> t) {
        if (t == null)
            return 0;
        else {
            return nodeCount(t.rchild) + nodeCount(t.lchild) + 1;
        }
    }

    public void levelOrder(BTtreeClass bt) {
        BTNode<Character> p;
        Queue<BTNode> qu = new LinkedList<>();
        qu.offer(bt.b);  //根节点进队

        while (!qu.isEmpty()) {
            p = qu.poll();  //队首元素出队
            System.out.print(p.data + " ");  //访问p节点
            if (p.rchild != null)               //有右孩子时将其进队
                qu.offer(p.rchild);
            if (p.lchild != null)               //有左孩子时将其进队
                qu.offer(p.lchild);
        }
    }

    public int minBranch(BTNode root) {
        if (root == null)
            return 0;
        int left = minBranch(root.lchild);
        int right = minBranch(root.rchild);
        if (left != 0 && right != 0)
            return 1 + Math.min(left, right);
        return 1 + left + right;
    }

    public int CountK(BTtreeClass bt, int k) {
        if (k < 1)
            return 0;
        Queue<BTNode> qu = new LinkedList<>();
        BTNode<Character> p = null;
        int cnt = 1;
        qu.offer(bt.b);

        while (!qu.isEmpty()) {
            if (cnt == k) {
                int i = 0;
                while (!qu.isEmpty()) {
                    p = qu.poll();
                    if (p.lchild == null && p.rchild == null)
                        i++;
                }
                return i;
            }
            int n = qu.size();
            for (int j = 0; j < n; j++) {
                p = qu.poll();
                if (p.lchild != null)
                    qu.offer(p.lchild);
                if (p.rchild != null)
                    qu.offer(p.rchild);
            }
            cnt++;

        }
        return 0;
    }

    public void outputK(BTNode b, int k) {
        if (b == null)
            return;
        System.out.print(k + " ");
        outputK(b.lchild, k + 1);
        outputK(b.rchild, k + 1);
    }

    public boolean judgeMirror(BTNode root1, BTNode root2) {
        if (root1 == null && root2 == null)
            return true;
        if (root1 == null || root2 == null)
            return false;
        if (root1.data != root2.data)
            return false;
        return (judgeMirror(root1.rchild, root2.lchild) && judgeMirror(root1.lchild, root2.rchild));
    }
    public int levelK(BTtreeClass bt, int k)
    {
        int cnt = 1;
        Queue<BTNode> qu = new LinkedList<>();
        BTNode p = new BTNode();
        qu.offer(bt.b);
        while (!qu.isEmpty())
        {
           if (cnt == k)
               return qu.size();
           Integer n = qu.size();
           for (Integer i = 0; i < n; i++)
           {
               p = qu.poll();
               if (p.lchild != null)
                   qu.offer(p.lchild);
               if (p.rchild != null)
                   qu.offer(p.rchild);
           }
           cnt++;
        }
        return 0;
    }
BTNode<Integer> root;
    public BTNode commonAncestor(BTNode<Integer> x, BTNode<Integer> y)
    {
        Queue<BTNode> st1 = new LinkedList<>();
        Queue<BTNode> st2 = new LinkedList<>();
        findAncestor(root, x, st1);
        findAncestor(root, y, st2);
        BTNode<Integer> p = new BTNode<>();
        while (!st1.isEmpty() && !st2.isEmpty())
        {
            if (st1.peek() == st2.peek()) {
                p = st1.peek();
                st1.poll();
                st2.poll();
            }
            else break;
        }
        if (!st1.isEmpty()&& !st2.isEmpty())
            return p;
        else return null;
    }

    private boolean findAncestor(BTNode<Integer> t, BTNode<Integer> x, Queue<BTNode> st)
    {
        if (t == null)
            return false;
        st.offer(t);
        boolean b = false;
        if (t.data == x.data)
            b = true;
        else if (t.lchild != null)
            b = findAncestor(t.lchild, x, st);
        if (!b && t.rchild != null)
            b = findAncestor(t.rchild, x, st);
        if (b == false)
            st.poll();
        return b;
    }
    public BTNode getParent(BTNode root,BTNode x, BTNode y)
    {
        if (root == null)
            return null;
        if (root.data == x.data || root.data == y.data)
            return root;
        BTNode left = getParent(root.lchild, x, y);
        BTNode right = getParent(root.rchild, x, y);
        if (left != null && right != null)
            return root;
        if (left == null)
            return right;
        else
            return left;
    }


}
