// Soal : https://codeforces.com/contest/706/problem/B
import java.util.Arrays;
import java.util.Scanner;

public class B_Interesting_drink {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int ar[] = new int[n];

        for (int i = 0; i < ar.length; i++) {
            ar[i] = in.nextInt();
        }

        Arrays.sort(ar);

        int t = in.nextInt();

        while(t > 0){
            t--;

            int a = in.nextInt();

            int l = 0, r = n-1, ans = 0;

            while(l <= r){
                int m = (l + r) / 2;

                if(ar[m] <= a){
                    ans = m + 1;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }

            System.out.println(ans);
        }


        in.close();
    }
}