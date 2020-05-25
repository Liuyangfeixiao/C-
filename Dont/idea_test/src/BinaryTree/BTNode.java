package BinaryTree;
public class BTNode<E>{
    E data;
    BTNode lchild;
    BTNode rchild;
    public BTNode()
    { lchild = rchild = null; }
    public BTNode(E d)
    { data = d; lchild = rchild = null; }
}
