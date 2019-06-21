package sqstack;

public class TestSqStack {
    public static void main(String[] args) {
        SqStack stack = new SqStack(10);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push("sss");
        stack.display();
        System.out.println();
        System.out.println("判断栈是否为空：");
        System.out.println(stack.empty());
        System.out.println("删除栈顶元素：");
        stack.pop();
        stack.display();
        System.out.println();
        System.out.println("取栈顶元素：" + "\n" + stack.length());
        System.out.print("调用clear方法清空栈：");
        stack.clear();
        stack.display();
        System.out.println();
        System.out.println("栈已被清空！！");
        System.out.println("判断栈是否为空："+"\n" + stack.empty());
    }
}
