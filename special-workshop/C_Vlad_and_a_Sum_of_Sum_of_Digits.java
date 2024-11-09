// Soal : https://codeforces.com/contest/1926/problem/C
import java.util.Scanner;

public class C_Vlad_and_a_Sum_of_Sum_of_Digits {
    static int getSumDigit(int a){
        int result = 0;
        while (a > 0) {
            result += a % 10;
            a/= 10;
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int t = in.nextInt(), MAX = 2 * (int)1e5;
        int sum[] = new int[MAX + 1];
        sum[0] = 0;

        for (int i = 1; i <= MAX; i++) {
            sum[i] = sum[i-1] + getSumDigit(i);
        }
        
        while (t > 0) {
            t--;
            int n = in.nextInt();
            System.out.println(sum[n]);
        }

        in.close();
    }
}