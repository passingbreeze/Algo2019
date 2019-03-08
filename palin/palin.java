import java.io.*;
import java.util.*;

public class palin {
    private static ArrayList<String> strList = new ArrayList<>();
    private static BufferedWriter bws =  new BufferedWriter(new OutputStreamWriter(System.out));

    static boolean isPalin(String s){
        int mid = s.length()/2;
        int diff = (s.length())&1;
        String r = new StringBuilder(s.substring(mid+diff)).reverse().toString();
        return s.substring(0,mid).equals(r);
    }

    static ArrayList<String> delAchr(String o){
        ArrayList<String> setStr = new ArrayList<>();
        StringBuilder temp = new StringBuilder();
        for (int i = 0; i < o.length(); i++){
            temp.append(o.substring(0,i));
            temp.append(o.substring(i+1));
            setStr.add(temp.toString());
            temp.setLength(0);
        }
        return setStr;
    }

    static Boolean isPseudoPalin(String o){
        ArrayList<String> lst = delAchr(o);
        for (int i = 0; i < lst.size(); i++)
            if(isPalin(lst.get(i)))
                return true;
        return false;
    }

    public static void main(String[] args) throws IOException {
//        long begin = System.currentTimeMillis();
        try{
            int sNum = 0;
            BufferedReader br = new BufferedReader(new FileReader("palin.inp"));
            BufferedWriter bw = new BufferedWriter(new FileWriter("palin.out"));
            StringBuilder result = new StringBuilder();
            sNum = Integer.parseInt(br.readLine());

            for (int i = 0; i < sNum; i++)
                strList.add(br.readLine());

            for (int i = 0; i < strList.size(); i++) {
                if(isPalin(strList.get(i)))
                    result.append("1\n");
                else{
                    if(isPseudoPalin(strList.get(i)))
                        result.append("2\n");
                    else
                        result.append("3\n");
                }
            }
            result.deleteCharAt(result.length()-1);
            bw.write(result.toString());
            bw.close();
        }
        catch(FileNotFoundException e) {
            bws.write("File Not Found.");
        }
//
//        long end = System.currentTimeMillis();
//        System.out.printf("Exec time : %.3f sec(s)", ((end-begin)/1000.0));
    }

}
