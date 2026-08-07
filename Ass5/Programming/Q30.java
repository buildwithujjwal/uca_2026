import java.util.*;
class Q30 {

    PriorityQueue<Integer> minHeap;
    PriorityQueue<Integer> maxHeap;

    public Q30() {

        minHeap = new PriorityQueue<>();
        maxHeap = new PriorityQueue<>(Collections.reverseOrder());
    }
    
    public void insert(int num) {

        if(minHeap.isEmpty()) {
            minHeap.add(num);
        }

        else if(num >= minHeap.peek()) {
            minHeap.add(num);
            if( (minHeap.size() - maxHeap.size()) > 1 ) maxHeap.add(minHeap.poll());
        }

        else {
            maxHeap.add(num);
            if( (maxHeap.size() - minHeap.size()) > 1 ) minHeap.add(maxHeap.poll());
        }
    }
    
    public float getMedian() {

        if(minHeap.size() == maxHeap.size()) return ((float)minHeap.peek() + (float)maxHeap.peek()) / 2;      
        else {
            if(minHeap.size() > maxHeap.size()) return minHeap.peek();
            return maxHeap.peek();
        }
    }

    public static void main(String[] args) {
        Q30 q30 = new Q30();

        q30.insert(5);
        System.out.println("Median after inserting 5: " + q30.getMedian());

        q30.insert(15);
        System.out.println("Median after inserting 15: " + q30.getMedian());

        q30.insert(1);
        System.out.println("Median after inserting 1: " + q30.getMedian());

        q30.insert(3);
        System.out.println("Median after inserting 3: " + q30.getMedian());

        q30.insert(8);
        System.out.println("Median after inserting 8: " + q30.getMedian());

        q30.insert(7);
        System.out.println("Median after inserting 7: " + q30.getMedian());

        q30.insert(9);
        System.out.println("Median after inserting 9: " + q30.getMedian());
    }
}