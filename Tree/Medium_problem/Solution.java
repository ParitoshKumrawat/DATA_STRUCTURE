package Tree.Medium_problem;
import java.util.*;

class Node{
    int val;
    Node left;
    Node right;

    Node(int val){
        this.val = val;
        left = null;
        right =null;
    }
}

public class Solution {
    int maxHeight(Node root){
        if(root == null)return 0;

        int max = 0;
        Queue<Node> q = new LinkedList<>();
        q.add(root);

        while(!q.isEmpty()){
           int size = q.size();

           for(int i =0 ; i<size ; i++){
            Node front = q.poll();

            if(front.left != null)q.add(front.left);
            if(front.right != null)q.add(front.right);
           }
           max++;
        }

        return max;
    }

    public static void main(String[] args){
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.left.right.left =new Node(6);
        root.left.right.right =new Node(7);

        Solution sol =new Solution();

        int ans = sol.maxHeight(root);

        System.out.println("Max Height : "+ans);

    }
}
