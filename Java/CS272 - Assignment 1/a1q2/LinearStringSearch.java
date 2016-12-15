/**
 * Program name - LinearStringSearch.java
 *
 * This program generates random strings then based on a forward search (beginning to end)
 * or reverse search (end to beginning) then it tracks which generated 
 * the faster result of finding the string within a random generated list
 *  
 * Athabasca University ID - 3181465
 * Author- Joshua Samuel Jackson
 * Date - August 5, 2014.
 */
package a1q2;
import java.util.Random;
public class LinearStringSearch {
    //defining array for strings and other variables needed
    String[] strings;
    String target;
    int searchStatistic;
    boolean direction;
    
    public LinearStringSearch(){
        //setting the base for the search statistic
        //this is the tracking to see which method preformed better
        searchStatistic = 0;
    }

    public LinearStringSearch(int searchStatistic){
        this.searchStatistic = searchStatistic;
    }

    
    static String generateRandomString(int len, char[] charSet){
        // generate a random string of length len from the characters in charSet
        Random r = new Random();
        char[] str = new char[len];
        for( int i = 0 ; i < len ; i++ )
            str[i] = charSet[r.nextInt(charSet.length)];
        
        return new String(str);
    }
    
    private void fwdSearch(String[] searchList, String target){
        //the forward search method
        //using a loop to search the list beginning to end
        for(int j = 0 ; j < searchList.length; j++)
            if( searchList[j].equals(target) ){
                searchStatistic = j <= (searchList.length/2) ? searchStatistic+1 : searchStatistic-1;
                System.out.println("Forward search Index: " + j + " Search Statistic: " + searchStatistic);                
                return;
            }
    }
    
    private  void rvsSearch(String[] searchList, String target){
        //reverse search method
        //using the same loop but reversing end to beginning 
        for(int j = 0 ; j < searchList.length; j++)
            if( searchList[searchList.length-(j+1)].equals(target) ){
                searchStatistic = j <= (searchList.length/2) ? searchStatistic-1 : searchStatistic+1;
                System.out.println("Reverse search Index: " + j + " Search Statistic: " + searchStatistic);
                return;
            }
    }
    
    public void search(String[] searchList, String target){
        //if statement to declare based on statistc which search to use
        if(searchStatistic > 0)
            fwdSearch(searchList, target);
        else if (searchStatistic < 0)
            rvsSearch(searchList,target);
        else
            if(direction){
                fwdSearch(searchList, target);
                direction = false;
            }else{
                rvsSearch(searchList, target);
                direction = true;
            }
    }
    
    public static void main(String[] args){
        //main method
        //setting character for the string to start and end with in this case 'a' and 'd'
        final char start = 'a', end = 'd';
        char[] charSet = new char[end-start+1];
        // building character set has letters 'a' through 'z'
        for( char c = start ; c <= end ; c++ )
            charSet[c-start] = c;
        //setting string lenth and array length
        int randomStringLength = 6;
        int randomStringArrayLength = 1000;
        String[] randomStrings = new String[randomStringArrayLength];
        //running through the array
        for(int i = 0 ; i < randomStrings.length ; i++){
            randomStrings[i] = generateRandomString(randomStringLength, charSet);
        }
        
        LinearStringSearch ss = new LinearStringSearch();
        //how many iterations to use
        int numOfIterations = 1000;
        //output of iterations with the index and statisitic for the searchs
        for(int i = 0 ; i < numOfIterations ; i++){
            String targetString = generateRandomString(randomStringLength, charSet);
            ss.search(randomStrings, targetString);
        }
    }
}
/**
 * Test Cases done on .txt file in same question folder.
 */