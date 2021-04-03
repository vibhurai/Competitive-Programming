import java.util.*;

public class Main {

    static String[][] main_op;

    // This method calculates cost.
    public double get_steps(String[][] op, String x, String y) {

        double[][] ans = new double[x.length() + 1][y.length() + 1]; // matix for cost get_steps

        for (int i = 0; i <= x.length(); i++) {
            ans[i][0] = i * 1;
            op[i][0] = "delete";
        }

        for (int i = 0; i <= y.length(); i++) {
            ans[0][i] = i * 1;
            op[0][i] = "insert"; // op is matrix for tracking back operations
        }

        int m = x.length();
        int n = y.length();

        for (int i = 1; i <= m; i++) {

            for (int j = 1; j <= n; j++) {

                if (x.charAt(i - 1) == y.charAt(j - 1)) {
                    ans[i][j] = ans[i - 1][j - 1] + 0; // copy
                    op[i][j] = "copy";
                } else if (x.charAt(i - 1) != y.charAt(j - 1)) {

                    double replace = ans[i - 1][j - 1] + 2; // replace
                    double insert = ans[i][j - 1] + 1; // insert
                    double delete = ans[i - 1][j] + 1; // delete

                    double min;

                    if (replace > insert) {
                        min = insert;
                        op[i][j] = "insert";
                        ans[i][j] = min;
                    } else {
                        min = replace;
                        op[i][j] = "replace";
                        ans[i][j] = min;
                    }

                    if (min > delete) {
                        min = delete;
                        op[i][j] = "delete";
                        ans[i][j] = min;
                    }

                }

                if (i > 1 && j > 1 && x.charAt(i - 1) == y.charAt(j - 2) && x.charAt(i - 2) == y.charAt(j - 1)
                        && (ans[i - 2][j - 2] + 1.5) < ans[i][j]) {
                    ans[i][j] = ans[i - 2][j - 2] + 1.5; // twiddle
                    op[i][j] = "twiddle";
                }

            } // end of j for loop

        } // end of i for loop

        for (int i = 0; i <= m - 1; i++) {

            if ((ans[i][n] + 5) < ans[m][n]) {
                ans[m][n] = ans[i][n] + 5; // kill
                op[m][n] = "kill " + (i + 1);

            }

        }

        System.out.println("sequence of operations: ");

        Main ed1 = new Main();
        ed1.optimal_sequence(op, x.length(), y.length()); // to print sequence

        return ans[m][n];// return cost

    }

    // This method prints sequence of operations.
    public void optimal_sequence(String[][] dop, int o, int p) {

        int o1 = 0;
        int p1 = 0;

        if (o == 0 && p == 0) {
            return;
        }

        if (dop[o][p] == "copy" || dop[o][p] == "replace") {
            o1 = o - 1;
            p1 = p - 1;
        } else if (dop[o][p] == "twiddle") {
            o1 = o - 2;
            p1 = p - 2;
        } else if (dop[o][p] == "delete") {
            o1 = o - 1;
            p1 = p;
        } else if (dop[o][p] == "insert") {
            o1 = o;
            p1 = p - 1;
        } else {

            try {
                StringTokenizer st1 = new StringTokenizer(dop[o][p]);
                st1.nextToken();
                String k = st1.nextToken();
                int k1 = Integer.parseInt(k);
                k1 = k1 - 1;
                o1 = k1;
                p1 = p;
            } catch (Exception e) {
                System.out.println(e);
            }

        }

        optimal_sequence(dop, o1, p1);

        System.out.println(dop[o][p]);

    }

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        System.out.println("Enter first string");
        String one = scan.nextLine();

        System.out.println("Enter second string");
        String two = scan.nextLine();
        Main temp = new Main();

        String[][] main_op = new String[one.length() + 1][two.length() + 1];

        double result = temp.get_steps(main_op, one, two);
        System.out.println("optimal cost is : " + result);

        scan.close();

    }

}