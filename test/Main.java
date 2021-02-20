import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int zs = sc.nextInt();
    for (int qqq = 0; qqq < zs; qqq++) {
      int n = sc.nextInt();
      for (int i = 0; i < n; i++) {
        String s = sc.next();
        char ch = '3';
        for (int j = 0; j < s.length(); j++) {
          if (s.charAt(j) == '0') {
            if (ch == '0' || ch == '2') {
              System.out.print("1");
              ch = '1';
            }
            if (ch == '1') {
              System.out.print("0");
              ch = '0';
            }
          }
          if (s.charAt(j) == '1') {
            if (ch == '0' || ch == '1') {
              System.out.print("1");
              ch = '2';
            }
            if (ch == '2') {
              System.out.print("0");
              ch = '1';
            }
          }
        }
        System.out.println("");
      }
    }
  }
}