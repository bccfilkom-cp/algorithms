// Soal : https://codeforces.com/contest/329/problem/B
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class B_Biridian_Forest {
    static class Point {
        int x, y;
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt(), m = in.nextInt();
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        in.nextLine();

        String[] ar = new String[n];
        int[][] dis = new int[n][m];
        boolean[][] vis = new boolean[n][m];
        Point start = null, end = null;

        for (int i = 0; i < n; i++) {
            ar[i] = in.nextLine();
            for (int j = 0; j < m; j++) {
                char ch = ar[i].charAt(j);
                if (ch == 'E') {
                    end = new Point(i, j);
                } else if (ch == 'S') {
                    start = new Point(i, j);
                }
            }
        }

        Queue<Point> q = new ArrayDeque<>();
        if (end != null) {
            q.add(end);
            vis[end.x][end.y] = true;
        }

        int steps = 0;

        while (!q.isEmpty()) {
            Point p = q.poll();
            int curDist = dis[p.x][p.y];
            
            if (p.x == start.x && p.y == start.y) {
                steps = curDist;
            }

            for (int i = 0; i < 4; i++) {
                int newx = p.x + dx[i], newy = p.y + dy[i];
                if (newx >= 0 && newx < n && newy >= 0 && newy < m 
                        && !vis[newx][newy] && ar[newx].charAt(newy) != 'T') {
                    q.add(new Point(newx, newy));
                    vis[newx][newy] = true;
                    dis[newx][newy] = curDist + 1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch = ar[i].charAt(j);
                if (Character.isDigit(ch) && vis[i][j] && dis[i][j] <= steps) {
                    ans += ch - '0';
                }
            }
        }

        System.out.println(ans);
        in.close();
    }
}
