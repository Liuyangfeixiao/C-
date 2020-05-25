package BinaryTree;

class ThNode {
    char data;            //存放结点值
    ThNode lchild, rchild;        //左、右孩子或线索的指针
    int ltag, rtag;        //左、右标志

    public ThNode()        //默认构造方法
    {
        lchild = rchild = null;
        ltag = rtag = 0;
    }

    public ThNode(char d)        //重载构造方法
    {
        data = d;
        lchild = rchild = null;
        ltag = rtag = 0;
    }


}

public class ThreadClass {
    ThNode b;
    ThNode root;
    ThNode pre;
    String btsr;

    public ThreadClass() {
        root = null;
    }

    public void CreateThread() {
        root = new ThNode();
        root.ltag = 0;
        root.rtag = 1;
        root.rchild = b;
        if (b == null) {
            root.ltag = 0;
            root.lchild = root;
        } else {
            root.lchild = b;
            pre = root;
            Thread(b);
            pre.rchild = root;
            pre.rtag = 1;
            root.rchild = pre;
        }
    }

    public void Thread(ThNode p) {
        if (p != null) {
            Thread(p.lchild);           //左子树线索化
            if (p.lchild == null) {     //前驱线索
                p.lchild = pre;         //节点p 添加前驱线索
                p.ltag = 1;
            } else
                p.ltag = 0;
            if (pre.rchild == null) {   //后继线索
                pre.rchild = p;         //节点pre添加后继线索
                pre.rtag = 1;
            } else pre.rtag = 0;
            pre = p;                    //置 p 节点为下一次访问节点的前驱节点
            Thread(p.rchild);           //右子树线索化
        }
    }
    /*线索树的中序遍历*/
    public void ThInOrder()
    {
        ThNode p = root.lchild;         //p 指向根节点
        while (p != null)               //找中序开始节点
        {
            while (p != null && p.ltag == 0)    //找到初始节点
                p = p.lchild;
            System.out.print(p.data + " ");
            while (p != root && p.rtag == 1)    //如果是线索，一直找下去
            {
                p = p.rchild;
                System.out.print(p.data + " ");
            }
            p = p.rchild;                   //如果不是线索，转向右子树
        }
    }
}
