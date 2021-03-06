package sqstack;

public interface Stack {
    public void clear();
    public boolean empty();//判空
    public int length();//长度
    public Object peek();//取得栈顶元素
    public void push(Object x);//向栈顶添加元素
    public Object pop(); //删除并返回栈顶元素
    public void display();//打印栈中元素
}
