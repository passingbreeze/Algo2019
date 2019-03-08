import java.io.*;
import java.util.*;

public class palin {
    private static ArrayList<String> strList = new ArrayList<>();
    private static BufferedWriter bws =  new BufferedWriter(new OutputStreamWriter(System.out));

    private static String chkPseudopalin(String s, String r){
        if(s.equals(r))
            return "1\n";
        int dIdx;
        StringBuilder ns = new StringBuilder(s);
        StringBuilder nr = new StringBuilder(r);
        for (dIdx = 0; dIdx < s.length(); dIdx++)
            if(s.charAt(dIdx) != r.charAt(dIdx))
                break;
        ns.deleteCharAt(dIdx);
        nr.deleteCharAt(r.length()-1-dIdx);
        if((ns.toString()).equals(nr.toString()))
            return "2\n";
        else{
            ns.setLength(0);
            nr.setLength(0);
            ns.append(s);
            nr.append(r);
            ns.deleteCharAt(s.length()-1-dIdx);
            nr.deleteCharAt(dIdx);
            return ((nr.toString()).equals(ns.toString())) ? "2\n" : "3\n";
        }
    }

    public static void main(String[] args) throws IOException {
//        long begin = System.currentTimeMillis();
        try{
            int sNum = 0;
            BufferedReader br = new BufferedReader(new FileReader("palin.inp"));
            BufferedWriter bw = new BufferedWriter(new FileWriter("palin.out"));
            StringBuilder result = new StringBuilder();
            StringBuilder revStr = new StringBuilder();

            sNum = Integer.parseInt(br.readLine());

            for (int i = 0; i < sNum; i++)
                strList.add(br.readLine());

            for (int i = 0; i < strList.size(); i++){
                revStr.append(strList.get(i)).reverse();
                result.append(chkPseudopalin(strList.get(i),revStr.toString()));
                revStr.setLength(0);
            }
            result.deleteCharAt(result.length()-1);
            bw.write(result.toString());
            bw.close();
        }
        catch(FileNotFoundException e) {
            bws.write("File Not Found.");
        }
//        long end = System.currentTimeMillis();
//        System.out.printf("Exec time : %.3f sec(s)", ((end-begin)/1000.0));
    }

}
