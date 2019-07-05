package queue;

public class QueueTest {
    public static void main(String[] args) {
        Queue1<Integer> queue = new Queue1<Integer>();
        queue.append(123);
        queue.append(456);
        queue.append(789);
        queue.append(741);
        System.out.println(queue.getFirst());
        System.out.println(queue.size());
        queue.delete();
        System.out.println(queue.getFirst());
        System.out.println(queue.size());
        for (Integer val : queue)
           { System.out.println(val);
               System.out.println('\t');
           }
    }
}
