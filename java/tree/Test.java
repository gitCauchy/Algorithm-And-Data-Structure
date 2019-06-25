package tree;

import java.util.ArrayList;
import java.util.List;

public class Test {
    public static void main(String[] args) {
        TreeNode<Integer> t = new TreeNode<Integer>(1);
        t.addLeft(2);
        t.addRight(3);
        t.leftChild.addLeft(4);
        t.leftChild.addRight(5);
        System.out.println("�����������");
        TreeTools.midOrderTravel(t);
        System.out.println("\nǰ���������");
        TreeTools.preOrderTravel(t);
        System.out.println("\n�����������");
        TreeTools.backOorderTravel(t);
        System.out.println("\n�����������");
        TreeTools.levelTraval(t);
        System.out.println("\n������ȣ�" + TreeTools.getTreeDepth(t));
        System.out.println("����Ҷ�Ӹ�����" + TreeTools.getLeftNum(t));
        System.out.println("���Ľڵ������" + TreeTools.getTreeNum(t));
        System.out.println("��2��ڵ����Ϊ��" + TreeTools.getNumForKlevel(t,2));
        List<Integer> pre = new ArrayList<Integer>();
        pre.add(1);
        pre.add(2);
        pre.add(4);
        pre.add(5);
        pre.add(3);
        List<Integer> mid = new ArrayList<Integer>();
        mid.add(4);
        mid.add(2);
        mid.add(5);
        mid.add(1);
        mid.add(3);
        TreeNode<Integer> root = TreeTools.getTreeFromPreAndMid(pre,mid);
        System.out.println("\nͨ��ǰ������򹹽������ԣ�");
        TreeTools.levelTraval(root);
        System.out.println("\n���������Ƚϲ��ԣ�");
        System.out.println(TreeTools.equals(t,root));




    }
}
