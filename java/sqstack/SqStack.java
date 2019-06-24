package sqstack;

public class SqStack implements Stack {
    private Object[] elem;
    private int top;

    public SqStack(int maxsize){
        top = 0;
        elem = new Object[maxsize];
    }

    public void clear() {
        while (top != 0){
            elem[top] = null;

        }

    }


    public boolean empty() {
        return top == 0;
    }


    public int length() {
        int i = 0;
        while (top != 0){
            i++;
            --top;
        }
        return i;
    }


    public Object peek() {
        return elem[top - 1];
    }


    public void push(Object x) {
        elem[top] = x;
        top++;
    }

    public Object pop() {
        return elem[--top];
    }


    public void display() {
        for(int i = top - 1;i >= 0;i--){
            System.out.print(elem[i]);
        }

    }
}
