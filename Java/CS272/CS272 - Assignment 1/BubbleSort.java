public class BubbleSort{
    public static void swap(int[]a,int left,int right){
        int temp = a[left];
        a[left]=a[right];
        a[right]=temp;
    }
    public static void bubbleSort(int[] a){
        boolean exchange;
        do{ //after one pass largest unsorted # propagates to final position
            exchange = false;
            for( int i = 1 ; i < a.length ; i++ ) // no range shortening
                if( a[i-1] > a[i] ){
                    swap(a,i-1,i);
                    exchange = true;
                }
        }while(exchange);
    }
    public static void bubbleSortRangeShortening(int[] a){
        boolean exchange;
        int n = a.length;
        do{ //after one pass largest unsorted # bubbles to final position
            exchange = false;
            for( int i = 1 ; i < n ; i++ ) // no range shortening
                if( a[i-1] > a[i] ){
                    swap(a,i-1,i);
                    exchange = true;
                }
            n--; // shorten range
        }while(exchange);
    }
    private static int[][] getTestCase(){
        int[][] a = {   {1,2,3,4,5,6,7,8,9,10},
                        {10,9,8,7,6,5,4,3,2,1},
                        {1,3,2,4,5,7,6,8,10,9},
                        {1},
                        {} 
                    };
        return a;
    }
    
    public static void main(String[] args){
        System.out.println("Test Cases: Bubble sort until there are no exchanges");
        int[][]testCase = getTestCase();
        for(int[] t: testCase){
            System.out.format("%-18s","Before sorting: ");
            for(int i: t)
                System.out.print(i+",");
            System.out.println();
            bubbleSort(t);
            System.out.format("%-18s","After sorting: ");
            for(int i: t)
                System.out.print(i+",");
            System.out.println();
        }
       
        System.out.println("\nTest Cases: Bubble sort until there are no exchanges with smaller range on each pass:");
        testCase = getTestCase();
        for(int[] t: testCase){
            System.out.format("%-18s","Before sorting: ");            
            for(int i: t)
                System.out.print(i+",");
            System.out.println();
            bubbleSortRangeShortening(t);
            System.out.format("%-18s","After sorting: ");
            for(int i: t)
                System.out.print(i+",");
            System.out.println();
        }
    }
}