/**
 * This is Journal Entry #8
 * journal8.java
 * 
 * This journal entry is using the given KMP algorithm from Unit 8
 * and implementing different test cases of a pattern search 
 * I have included a scanner import to allow for user input of any pattern 
 * and text
 * 
 * Athabasca University ID - 3181465
 * Author- Joshua Samuel Jackson
 * Date - September 5, 2014.
 *.
 */

package journal;
import java.util.Scanner;
public class journal8 {
    private final int R;       // the radix
    private int[][] dfa;       // the KMP automoton

    private char[] pattern;    // either the character array for the pattern
    private String pat;        // or the pattern string

    // create the DFA from a String
    public journal8(String pat) {
        this.R = 256;
        this.pat = pat;

        // build DFA from pattern
        int M = pat.length();
        dfa = new int[R][M]; 
        dfa[pat.charAt(0)][0] = 1; 
        for (int X = 0, j = 1; j < M; j++) {
            for (int c = 0; c < R; c++) 
                dfa[c][j] = dfa[c][X];     // Copy mismatch cases. 
            dfa[pat.charAt(j)][j] = j+1;   // Set match case. 
            X = dfa[pat.charAt(j)][X];     // Update restart state. 
        } 
    } 

    // create the DFA from a character array over R-character alphabet
    public journal8(char[] pattern, int R) {
        this.R = R;
        this.pattern = new char[pattern.length];
        for (int j = 0; j < pattern.length; j++)
            this.pattern[j] = pattern[j];

        // build DFA from pattern
        int M = pattern.length;
        dfa = new int[R][M]; 
        dfa[pattern[0]][0] = 1; 
        for (int X = 0, j = 1; j < M; j++) {
            for (int c = 0; c < R; c++) 
                dfa[c][j] = dfa[c][X];     // Copy mismatch cases. 
            dfa[pattern[j]][j] = j+1;      // Set match case. 
            X = dfa[pattern[j]][X];        // Update restart state. 
        } 
    } 

    // return offset of first match; N if no match
    public int search(String txt) {

        // simulate operation of DFA on text
        int M = pat.length();
        int N = txt.length();
        int i, j;
        for (i = 0, j = 0; i < N && j < M; i++) {
            j = dfa[txt.charAt(i)][j];
        }
        if (j == M) return i - M;    // found
        return N;                    // not found
    }


    // return offset of first match; N if no match
    public int search(char[] text) {

        // simulate operation of DFA on text
        int M = pattern.length;
        int N = text.length;
        int i, j;
        for (i = 0, j = 0; i < N && j < M; i++) {
            j = dfa[text[i]][j];
        }
        if (j == M) return i - M;    // found
        return N;                    // not found
    }


    // test client
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Pattern: ");
        String pat = sc.nextLine();
        System.out.println("Enter Text: ");
        String txt = sc.nextLine();
        char[] pattern = pat.toCharArray();
        char[] text    = txt.toCharArray();

        journal8 kmp1 = new journal8(pat);
        int offset1 = kmp1.search(txt);

        journal8 kmp2 = new journal8(pattern, 256);
        int offset2 = kmp2.search(text);

        // print results
        System.out.println("text:    " + txt);
        
        System.out.print("pattern: ");
        
        for (int i = 0; i < offset1; i++)
            System.out.print(" ");
        System.out.println(pat);

        System.out.print("pattern: ");
        for (int i = 0; i < offset2; i++)
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
 * Exception Thrown String Index out of range
 * 
 * Output as expected program cannot process anything must have characters
 * 
 * ///Test Case#4 (no data for pattern but for text)
 * Input:
 * Enter Pattern: <Enter>
 * Enter Text: abcdefg
 * 
 * Output:
 * Exception Thrown Out of Bounds
 * 
 * Output expected, pattern is necessary for completion of methods
 * 
 * ///Test Case#5 (no data for text but for pattern)
 * Input:
 * Enter Pattern: abc
 * Enter Text: <Enter>

 * Output:
 * text:    
 * pattern: abc
 * pattern: abc
 * 
 * Output as expected 
 * Program will function with non matching pattern putting it outside of the text
 * but without a pattern it cannot function because it has nothing to do.
 */
