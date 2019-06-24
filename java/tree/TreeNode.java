package tree;

/**
 * 树的节点结构
 */
public class TreeNode<T> {
    T value;

    TreeNode<T> leftChild;
    TreeNode<T> rightChild;

    TreeNode(T value){
        this.value = value;
    }
    TreeNode(){}

    /**
     * 增加左子节点
     */
    public void addLeft(T value){
        TreeNode<T> leftChild = new TreeNode<T>(value);
        this.leftChild = leftChild;
    }

    /**
     * 增加右子节点
     */
    public void addRight(T value){
        TreeNode<T> rightChild = new TreeNode<T>(value);
        this.rightChild = rightChild;
    }

    /**
     * 重载equal方法
     */
    public boolean equals(Object obj){
        if(!(obj instanceof TreeNode)){
            return false;
        }
        return this.value.equals(((TreeNode<?>)obj).value);
    }

    /**
     * 重载hashCode方法
     */
    public int hashCode(){
        return this.value.hashCode();
    }

    public String toString(){
        return this.value==null?" ":this.value.toString();
    }
}

