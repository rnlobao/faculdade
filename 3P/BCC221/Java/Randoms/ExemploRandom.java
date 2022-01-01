import java.util.*;

public class ExemploRandom {
    public static void myRandomMath(int m_ini, int m_final) {
        int tot = (m_final - m_ini) + 1;
        int n;
        int hist[] = new int [tot];
        for (int i = 0; i < 100000; i++) {
            n = (int)(Math.random() * (m_final-m_ini+1)+m_ini);
            hist[n-m_ini]++;
        }
        System.out.println(hist);
    }
}
