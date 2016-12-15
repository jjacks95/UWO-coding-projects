/**
 * This is Journal Entry #10
 * journal10.java
 * 
 * This is a program of Rabin-Karp algorithm implementation
 * this program is another alternative string-search algorithm from one I did
 * earlier in the journal entry, this was done in preparation for the final exam
 * Although not writing this algorithm entirely on my own, I was using this as a 
 * learning tool for the final
 * 
 * Author- Joshua Jackson
 * Date - September 10, 2014.
 *.
 */

package journal;

import java.math.BigInteger;
import java.util.Random;
import java.util.Scanner;


public class journal10 {  
    private String pat;      // the pattern  // needed only for Las Vegas
    private long patHash;    // pattern hash value
    private int M;           // pattern length
    private long Q;          // a large prime, small enough to avoid long overflow
    private int R;           // radix
    private long RM;         // R^(M-1) % Q

    public journal10(int R, char[] pattern) {
        throw new UnsupportedOperationException("Operation not supported yet");
    }

    public journal10(String pat) {
        this.pat = pat;      // save pattern (needed only for Las Vegas)
        R = 256;
        M = pat.length();
        Q = longRandomPrime();

        // precompute R^(M-1) % Q for use in removing leading digit
        RM = 1;
        for (int i = 1; i <= M-1; i++)
           RM = (R * RM) % Q;
        patHash = hash(pat, M);
    } 

    // Compute hash for key[0..M-1]. 
    private long hash(String key, int M) { 
        long h = 0; 
        for (int j = 0; j < M; j++) 
            h = (R * h + key.charAt(j)) % Q; 
        return h; 
    } 

    // Las Vegas version: does pat[] match txt[i..i-M+1] ?
    private boolean check(String txt, int i) {
        for (int j = 0; j < M; j++) 
            if (pat.charAt(j) != txt.charAt(i + j)) 
                return false; 
        return true;
    }

    // Monte Carlo version: always return true
    private boolean check(int i) {
        return true;
    }

    // check for exact match
    public int search(String txt) {
        int N = txt.length(); 
        if (N < M) return N;
        long txtHash = hash(txt, M); 

        // check for match at offset 0
        if ((patHash == txtHash) && check(txt, 0))
            return 0;

        // check for hash match; if hash match, check for exact match
        for (int i = M; i < N; i++) {
            // Remove leading digit, add trailing digit, check for match. 
            txtHash = (txtHash + Q - RM*txt.charAt(i-M) % Q) % Q; 
            txtHash = (txtHash*R + txt.charAt(i)) % Q; 

            // match
            int offset = i - M + 1;
            if ((patHash == txtHash) && check(txt, offset))
                return offset;
        }

        // no match
        return N;
    }


    // a random 31-bit prime
    private static long longRandomPrime() {
        BigInteger prime = BigInteger.probablePrime(31, new Random());
        return prime.longValue();
    }

    // test client
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Word to search within the Text: ");
        String pat = sc.nextLine();
        System.out.println("Enter Text: ");
        String txt = sc.nextLine();

        journal10 searcher = new journal10(pat);
        int offset = searcher.search(txt);

        // print results
        System.out.println("text:    " + txt);

        // from brute force search method 1
        System.out.print("pattern: ");
        for (int i = 0; i < offset; i++)
            System.out.print(" ");
        System.out.println(pat);
    }
}
/**
 * Program Testing
 * ///Test Case#1 (matching pattern and text)
 * Input:
 * Enter Pattern:abc
 * Enter Text:abacadabrabcracabracadabrabrabracad 
 * 
 * Output:
 * text:    abacadabrabcracabracadabrabrabracad
 * pattern:          abc
 * 
 * Output as expected lines the pattern and matching with text underneath
 * 
 * ///Test Case#2 (not matching pattern and text)
 * Input:
 * Enter Pattern: yux
 * Enter Text: abacadabrabcracabracadabrabrabracad
 * 
 * Output:
 * text:    abacadabrabcracabracadabrabrabracad
 * pattern:                                    yux
 * 
 * Output as expected will put the non matching 
 * character set on the outside of text
 * 
 * ///Test Case#3 (no data <Enter> for both pattern and text)
 * Input:
 * Enter Pattern: <Enter>
 * Enter Text: <Enter>
 * 
 * Output:
 * text:    
 * pattern: 
 * 
 * Output as expected 
 * 
 * ///Test Case#4 (no data for pattern but for text)
 * Input:
 * Enter Pattern: <Enter>
 * Enter Text: abcdefg
 * 
 * Output:
 * text:    abcdegf
 * pattern: 
 * 
 * Output expected
 * 
 * ///Test Case#5 (no data for text but for pattern)
 * Input:
 * Enter Pattern: abc
 * Enter Text: <Enter>

 * Output:
 * text:    
 * pattern: abc
 * 
 * Output as expected 
 * Program will function regardless of input, empty spaces or no data is
 * recognized as a pattern or text to search for or be searched for.
 */
