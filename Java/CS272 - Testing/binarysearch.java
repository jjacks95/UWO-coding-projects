package testing;
import java.util.*;

public class binarysearch {

//private int target;
public static int binarysearch(int[] a, int target){
    return binarysearch(a, 0, a.length-1, target);
}

public static int binarysearch(int[] a, int start, int end, int target){
    int middle = (start + end) / 2;
    if(end < start)
        return -1;
    if(target==a[middle])
        return middle;
    if(target<a[middle]){
        return binarysearch(a, start, middle - 1, target);
    }
    else{
        return binarysearch(a, middle + 1, end, target);
    }
}
    public static void main(String[] args){
        Random r = new Random();
        int target = r.nextInt(20);
        int number;
        int[] a = new int[10];
        for(int i = 0; i<10; i++){
            number = r.nextInt(50);
            a[i] = number;
        }
        System.out.println(Arrays.toString(a));
        System.out.println(target);
        System.out.println(binarysearch(a, target));
    }
} 
    
    /*
    private int KEY_NOT_FOUND;
  
    int binary_search(int A[], int key, int imin, int imax){
    // test if array is empty
    if (imax < imin)
    // set is empty, so return value showing not found
    return KEY_NOT_FOUND;
    else
    {
    
    // calculate midpoint to cut set in half
    int imid = midpoint(imin, imax);
 
    // three-way comparison
    if (A[imid] > key)
    // key is in lower subset
    return binary_search(A, key, imin, imid-1);
    
    else if (A[imid] < key)
    // key is in upper subset
    return binary_search(A, key, imid+1, imax);
    else
    // key has been found
    return imid;
    }
}

    private int midpoint(int imin, int imax) {
        throw new UnsupportedOperationException("Not supported yet."); 
    //To change body of generated methods, choose Tools | Templates.
    }
*/
