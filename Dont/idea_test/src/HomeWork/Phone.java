package HomeWork;

public class Phone {
    String brand;
    int price;

    public void call() {
        System.out.println("打电话");
    }

    public void sendMessage() {
        System.out.println("发短信");
    }
}
/*code war 7kyu printerError*/
class Printer {

    public static String printerError(String s) {
        int len = s.length();
        int cnt = 0;
        for (int i = 0; i < len; i++)
        {
            if (s.charAt(i) > 'm')
                cnt++;
        }
        String str = String.valueOf(cnt) + "/" +String.valueOf(len);
        return str;
    }
    public long sum(long m)
    {
        long n = 0;
        double cnt = Math.sqrt(4*m);
        while (m>=0)
        {
            if (n*(n+1) == cnt)
                return n;
            else if (n*(n+1) > cnt)
                break;
            n++;
        }
        return -1;
    }
}