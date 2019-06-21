package test;
public class SqList implements LList {

    private Object[] listElem;
    private int currentLen;


    public SqList(int maxSize) {
        currentLen = 0;
        listElem = new Object[maxSize];

    }


    public boolean isEmpty() {
        if (currentLen ==0 ){
            return true;
        }else{
            return false;
        }

    }


    public int lengthList() {
        return currentLen;
    }



    public void clearList() {
        currentLen = 0;

    }


    public Object getElem(int i)  {
        if (i < 0 || i > currentLen) {
            throw new IndexOutOfBoundsException("数组越界");
        } else {
            return listElem[i];
        }
    }


    public void insertList(int i, Object x) throws Exception {
        if(i < 0 || i > currentLen) {
            throw new Exception("顺序表已满，不能在进行插入操作了");
        }else if (currentLen ==listElem.length) {
            throw new IndexOutOfBoundsException("数组越界");
        } else {
            //插入操作
            for (int j = currentLen; j > i; j--)
                listElem[j] = listElem[j - 1];
                listElem[i] = x;
                currentLen++;
        }
    }


    public void deleteList(int i) throws Exception {
        if (i < 0 || i > currentLen) {
            throw new IndexOutOfBoundsException("数组越界");
        } else {
            //删除操作
            for (int j = i; j < currentLen; j++)
                listElem[j] = listElem[j + 1];
                currentLen--;
        }
    }

        public int localList(Object x) {
            int j = 0;
            while(j < currentLen && !listElem[j].equals(x)){
                j++;
            }
            if(j <currentLen)
                return j;
            else
                return -1;

        }



    public void display() {
        for (int j = 0;j < currentLen;j++){
            System.out.print(listElem[j] + " ");
        }

    }

    public Object  priorElem(int i){
        if(i > 0 && i < currentLen + 1){
            return listElem[i-1];
        }else{
            throw new IndexOutOfBoundsException("数组越界");
        }
    }
    public Object nextElem(int i){
        if(i==-1){
            return  listElem[0];
        }else if(i < currentLen-1 && i > -1){
            return listElem[i+1];

        }else{
            throw new IndexOutOfBoundsException("数组越界");
        }
    }

    public static void main(String[] args) throws Exception {
        SqList L = new SqList(10);
        for(int i = 0;i <= 8;i++){
            L.insertList(i,i);
        }
        L.display();
        L.deleteList(2);
        System.out.println();
        L.display();
        System.out.println();
        L.insertList(1,"ji");
        L.display();
        System.out.println();
        System.out.println(L.getElem(0));
        System.out.println(L.priorElem(8));
        System.out.println(L.nextElem(3));
        System.out.println(L.lengthList());
        System.out.println("判空:"+L.isEmpty());
        System.out.println(L.localList(0));
        L.clearList();
        System.out.println();
        System.out.println(L.lengthList());
    }
}
