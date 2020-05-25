package Search;
class BSTNode
{
    public int key;
    public BSTNode lchild;
    public BSTNode rchild;
    public BSTNode()
    { lchild = rchild = null;}
}
public class BST {
    public BSTNode r;       //根节点
    public BSTNode f;       //存放待删除节点的双亲节点
    public BST()
    {
        r = null;
    }
    /*BST的插入*/
    public void InsertBST(int k)
    {
        InsertBST1(r, k);
    }
    private BSTNode InsertBST1(BSTNode p, int k)
    {
        if (p==null)
        {
            p = new BSTNode();
            p.key = k;
        }
        else if (k < p.key)
            p.lchild = InsertBST1(p.lchild, k);
        else if (k > p.key)
            p.rchild = InsertBST1(p.rchild, k);
        return p;
    }
    /*创建BST，采用插入法*/
    public void createBST(int [] a)
    {
        r = new BSTNode();
        for (int i = 0; i < a.length; i++)
            InsertBST1(r, a[i]);
    }
    public BSTNode Search(int k)
    {
        return Search1(r, k);
    }
    private BSTNode Search1(BSTNode p, int k)
    {
        if (p == null)
            return null;
        if (k == p.key)
            return p;
        if (k < p.key)
            return Search1(p.lchild, k);        //在左子树中递归查找
        else return Search1(p.rchild, k);       //在右子树中递归查找
    }
    /*BST的删除*/
    public boolean DeleteBST(int k)
    {
        f = null;
        return DeleteBST1(r, k, -1);
    }
    private boolean DeleteBST1(BSTNode p, int k, int flag)
    {
        if (p == null)
            return false;
        if (p.key == k)
            return DeleteNode(p, f, flag);
        if (k < p.key){
            f = p;
            return DeleteBST1(p.lchild, k, 0);      //递归查找左子树
        }
        else {
            f = p;
            return DeleteBST1(p.rchild, k, 1);      //递归查找右子树
        }

    }
    private boolean DeleteNode(BSTNode p, BSTNode f, int flag)
    {
        if (p.rchild == null)       //如果 p 只有左孩子
        {
            if (flag == -1)         //如果p是根节点
                r = p.lchild;
            else if (flag == 0)     //如果 p 是父节点的左孩子
                f.lchild = p.lchild;
            else if (flag == 1)     //如果 p 是父节点的右孩子
                f.rchild = p.lchild;
        }
        else if (p.lchild == null)  //如果 p 只有右孩子
        {
            if (flag == -1)         // p 是根节点
                r = p.rchild;
            else if (flag == 0)     //p 是父节点的左孩子
                f.lchild = p.rchild;
            else if (flag == 1)     //p 是父节点的右孩子
                f.rchild = p.rchild;
        }
        else                        //p 有左右孩子
        {
            BSTNode f1 = p;         //f1 为 q 的父节点
            BSTNode q = p.lchild;   //q 作为 p 左子树的最大节点
            while (q.rchild != null)
            {
                f1 = q;
                q = q.rchild;
            }
            p.key = q.key;          //将 p 的值用 q 的值代替
            f1.rchild = q.lchild;   //删除节点 q
        }
        return true;
    }

    /*寻找节点x 和 y 的最小公共祖先*/
    public BSTNode Judge(BSTNode p , BSTNode x, BSTNode y)
    {
        if (p == null)
            return null;
        if (p != null) {
            if (x.key < p.key && y.key > p.key || x.key > p.key && y.key < p.key)
                return p;
            else if (x.key < p.key && y.key < p.key)
                return Judge(p.lchild, x, y);
            else if (x.key > p.key && y.key > p.key)
                return Judge(p.rchild, x, y);
        }
        return p;
    }
}
