/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package testing;

/**
 *
 * @author Josh Jackson
 */
public class reverse {
    public static int reverse(int A[], int n){
    
        if(n == 1){
            System.out.println(A[0]);
            System.exit(0);
            }else
                System.out.println(A[n-1]);
                return reverse(A,n-1);
        }
    public static void main(String[] args){
        int n = 10;
        int A[];
        A = new int[] {1,2,3,4,5,6,7,8,9,10};
        System.out.println(reverse(A, n));
    }
}
