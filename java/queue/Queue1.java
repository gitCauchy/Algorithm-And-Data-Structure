package queue;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
public class Queue1<E> extends  LinkedList<E> implements List<E> ,java.io.Serializable {

  
    private transient Entry<E> front;
    private transient int size;

  
    private transient Entry<E> rear;

    public Iterator<E> singleListIterator() {
        return new QueueIterator();
    }


    public Queue1() {
        this.front = this.rear = null;
    }

    public boolean add(E e) {
        Entry<E> newData = new Entry<E>(e, null);
        if (this.rear == null) {
            this.rear = newData;
            this.front = this.rear;
        } else {
            Entry<E> preElement = this.front;
            while (preElement.next != null) {
                preElement = preElement.next;
            }
            preElement.next = newData;
        }
        size++;
        return true;
    }


    public boolean append(E e) {
        return add(e);
    }

    
    public E get(int index) {
        return this.front.element;
    }

    public E getFirst() {
        return get(0);
    }


    public E delete() {
        E result = null;
        Entry<E> entry = this.front;
        if (entry != null) {
            result = entry.element;
            this.front = entry.next;
            entry = null;
        }
        size--;
        return result;
    }

  
    public int size() {
        return size;
    }

    private static class Entry<E> {
        E element;
        Entry<E> next;

        public Entry(E element, Entry<E> next) {
            this.element = element;
            this.next = next;
        }
    }

    private class QueueIterator implements Iterator<E> {
        private Entry<E> itFront = front;

        public boolean hasNext() {
            return itFront != null;
        }

        public E next() {
            E result = itFront.element;
            itFront = itFront.next;
            return result;
        }

        public void remove() {
            throw new UnsupportedOperationException("can not remove");
        }
    }

}
