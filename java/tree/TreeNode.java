package tree;

/**
 * ���Ľڵ�ṹ
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
     * �������ӽڵ�
     */
    public void addLeft(T value){
        TreeNode<T> leftChild = new TreeNode<T>(value);
        this.leftChild = leftChild;
    }

    /**
     * �������ӽڵ�
     */
    public void addRight(T value){
        TreeNode<T> rightChild = new TreeNode<T>(value);
        this.rightChild = rightChild;
    }

    /**
     * ����equal����
     */
    public boolean equals(Object obj){
        if(!(obj instanceof TreeNode)){
            return false;
        }
        return this.value.equals(((TreeNode<?>)obj).value);
    }

    /**
     * ����hashCode����
     */
    public int hashCode(){
        return this.value.hashCode();
    }

    public String toString(){
        return this.value==null?" ":this.value.toString();
    }
}

