package BinaryTree;

public class Main {
    public static void main(String[] args) {
        BTtreeClass bt = new BTtreeClass();
        bt.bstr = "A(B(C,D),E(F,G(H,X)))";
        bt.CreateBTree(bt.bstr);
        bt.levelOrder(bt);
        int i = bt.CountK(bt,3);
        System.out.println(i);
        bt.outputK(bt.b, 1);
        System.out.println(bt.judgeMirror(bt.b, bt.b));


    }
}
