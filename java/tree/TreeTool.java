package tree;
//下面代码中的方法好多都用到了递归的思想。
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 *判断树中节点个数，下面的+1代表root节点,要是返回0，代表跳出程序，不会执行下面的return语句。
 */
public class TreeTools {
    public static <T> int getTreeNum(TreeNode<T> root){
        if(root == null){
            return 0;
        }
        return getTreeNum(root.leftChild) + getTreeNum(root.rightChild)+1;
    }

    /**
     * 判断树的深度
     */
    public static <T> int getTreeDepth(TreeNode<T> root){
        if(root == null){
            return 0;
        }
        int leftDepth = getTreeDepth(root.rightChild)+1;
        int rightDepth = getTreeDepth(root.rightChild)+1;
        return Math.max(leftDepth,rightDepth);
    }

    /**
     * 访问node节点
     */
    private static <T> void visitNode(TreeNode<T> node){
        System.out.print(node.value + "\t");
    }

    /**
     * 前序遍历
     */
    public static <T> void preOrderTravel(TreeNode<T> root){
        if(root == null){
            return ;
        }
        visitNode(root);
        if(root.leftChild != null){
            preOrderTravel(root.leftChild);
        }
        visitNode(root);
        if(root.rightChild != null){
            preOrderTravel(root.rightChild);
        }
    }

    /**
     * 中序遍历
     */
    public static<T> void midOrderTravel(TreeNode<T> root){
        if(root == null){
            return ;
        }
        if(root.leftChild != null){
            midOrderTravel(root.leftChild);
        }
        visitNode(root);
        if(root.rightChild != null){
            midOrderTravel(root.rightChild);
        }

    }
    /**
     * 后序遍历
     */
    public static<T> void backOorderTravel(TreeNode<T> root){
        if(root == null){
            return ;
        }
        if(root.leftChild != null){
            backOorderTravel(root.leftChild);
        }
        visitNode(root);
        if(root.rightChild != null){
            backOorderTravel(root.rightChild);
        }
        visitNode(root);
    }

    /**
     * 分层遍历
     */
    public static<T> void levelTraval(TreeNode<T> root){
        Queue<TreeNode<T>> q = new LinkedList<TreeNode<T>>();
       /*
        补充知识点：
        offer添加一个元素并返回true，在有容量限制的队列中，最好 使用offer，如果空间限制返回false。
        用add()添加，如果失败则抛出IllegalStateException异常，成功true.
        poll移除并返回队列头部的元素，如果队列为空，返回null;remove队列为空则抛出异常；用于在队列的头部查询元素在队列为空时element抛出异常，peek抛出null
        */
        q.offer(root);
        while (!q.isEmpty()){
            TreeNode<T> temp = q.poll();
            visitNode(temp);
            if(temp.leftChild != null){
                q.offer(temp.leftChild);
            }
            if(temp.rightChild != null){
                q.offer(temp.rightChild);
            }
        }
    }

    /**
     *求第k层节点个数
     */
    public static <T> int getNumForKlevel(TreeNode<T> root,int k){
        if (root == null || k < 1){
            return 0;
        }
        if (k == 1){
            return 1;
        }
        int leftNum = getNumForKlevel(root.leftChild,k-1);
        int rightNum = getNumForKlevel(root.rightChild,k-1);
        return leftNum + rightNum;
    }

    /**
     *
     * 求二叉树中叶子节点的个数
     */
    public static <T> int getLeftNum(TreeNode<T> root){
        if(root == null){
            return 0;
        }
        if(root.leftChild == null && root.rightChild == null){
            return 1;
        }
        int leftNum = getLeftNum(root.leftChild);
        int rightNum = getLeftNum(root.rightChild);
        return leftNum + rightNum;
    }

    /**
     * 交换根节点的左右子树
     */
    public static <T> TreeNode<T> exchange(TreeNode<T> root){
        if(root == null){
            return null;
        }
        TreeNode<T> left = exchange(root.leftChild);
        TreeNode<T> right = exchange(root.rightChild);
        root.leftChild = right;
        root.rightChild = left;
        return root;
    }

    /**
     * 查看node是否是root的子节点
     */
    public static <T> boolean nodeIsChild(TreeNode<T> root,TreeNode<T> node){
        if(root == null || node == null){
            return false;
        }
        if(root == node){
            return true;
        }
        boolean isFind = nodeIsChild(root.leftChild,node);
        if(!isFind){
            isFind = nodeIsChild(root.leftChild,node);
        }
        return isFind;
    }


    /**
     * 返回两个节点lnode和rnode的以root为根节点的公共父节点
     */
    public static <T> TreeNode<T> findAllFatherNode(TreeNode<T> root, TreeNode<T> lNode, TreeNode<T> rNode){
        if (lNode == root || rNode == root){
            return root;
        }
        if(root == null || lNode == null || rNode == null){
            return null;
        }
        //如果lNode是左子树的节点
        if (nodeIsChild(root.leftChild,lNode)){
            if(nodeIsChild(root.rightChild,rNode)){
                return root;
            }else{
                return findAllFatherNode(root.leftChild,lNode,rNode);
            }
        }else{
            if(nodeIsChild(root.leftChild,rNode)){
                return root;
            }
            else{
                return findAllFatherNode(root.rightChild,lNode,rNode);
            }
        }
    }

    /**
     * 根据前序和中序构建二叉树
     */
    public static <T> TreeNode<T> getTreeFromPreAndMid(List<T> pre,List<T> mid){
        if(pre == null || mid == null || pre.size() == 0 || mid.size() == 0){
            return null;
        }
        if(pre.size() == 1){
            return new TreeNode<T>(pre.get(0));
        }
        TreeNode<T> root = new TreeNode<T>(pre.get(0));
        //找出根节点在中序中的位置
        int index = 0;
        while (!mid.get(index++).equals(pre.get(0))){
        }
        //构建左子树的前序
        List<T> preLeft = new ArrayList<T>(index);
        //左子树的中序
        List<T> midLeft  = new ArrayList<T>(index);
        for(int i = 1; i< index; i++){
            preLeft.add(pre.get(i));
        }
        for(int i = 0; i < index - 1;i++){
            midLeft.add(mid.get(i));
        }

        //重建左子树
;        root.leftChild = getTreeFromPreAndMid(preLeft,midLeft);
        //右子树的前序
        List<T> preRight = new ArrayList<T>(pre.size() - index - 1);
        //右子树的中序
        List<T> midRight = new ArrayList<T>(pre.size() - index -1);
        for (int i = 0;i <= pre.size() - index - 1;i++){
            preRight.add(pre.get(index + i));
        }
        for(int i = 0;i <= pre.size() - index -1;i++){
            midRight.add(mid.get(index + i));
        }
        //重建子树
        root.rightChild = getTreeFromPreAndMid(preRight,midRight);
        return root;
    }

    /**
     *查看node1和node2两颗树是否相等（两颗树所有节点都相等）
     */
    public static <T> boolean equals(TreeNode<T> node1,TreeNode<T> node2){
        if(node1 == null && node2 == null){
            return true;
        }else if(node1 == null ||node2 == null){
            return false;
        }
        boolean isEqual = node1.value.equals(node2.value);
        boolean isLeftEqual = equals(node1.leftChild,node2.leftChild);
        boolean isRightEqual = equals(node1.leftChild,node2.leftChild);
        return isEqual && isLeftEqual && isRightEqual;
    }

}
