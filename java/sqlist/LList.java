package test;

public interface LList {

    public boolean isEmpty();
    public int lengthList();
    public void clearList();
    public Object getElem(int i) ;
    public Object  priorElem(int i);
    public Object nextElem(int i);
    public void insertList(int i ,Object x) throws Exception;
    public void deleteList(int i) throws Exception;
    public int localList(Object x);
   // public void traverseList();
    public void display();

}
