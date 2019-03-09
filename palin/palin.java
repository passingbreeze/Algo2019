import java.io.*;

public class palin {
    private static StringBuilder oriStr = new StringBuilder();
    private static StringBuilder revStr = new StringBuilder();
    private static StringBuilder s = new StringBuilder();
    private static StringBuilder r = new StringBuilder();
    private static StringBuilder result = new StringBuilder();
    private static BufferedWriter bws =  new BufferedWriter(new OutputStreamWriter(System.out));

    private static String chkPseudopalin(String o, String rev){
        if(o.equals(rev))
            return "1\n";
        int dIdx;
        s.append(o);
        r.append(rev);
        for (dIdx = 0; dIdx < o.length(); dIdx++)
            if(o.charAt(dIdx) != rev.charAt(dIdx))
                break;
        s.deleteCharAt(dIdx);
        r.deleteCharAt(r.length()-1-dIdx);
        if((s.toString()).equals(r.toString()))
            return "2\n";
        else{
            s.setLength(0);
            r.setLength(0);
            s.append(o);
            r.append(rev);
            s.deleteCharAt(s.length()-1-dIdx);
            r.deleteCharAt(dIdx);
            return ((r.toString()).equals(s.toString())) ? "2\n" : "3\n";
        }
    }

    public static void main(String[] args) throws IOException {
//        long begin = System.currentTimeMillis();
        try{
            int sNum = 0;
            BufferedReader br = new BufferedReader(new FileReader("palin.inp"));
            BufferedWriter bw = new BufferedWriter(new FileWriter("palin.out"));

            sNum = Integer.parseInt(br.readLine());

            for (int i = 0; i < sNum; i++){
                oriStr.append(br.readLine());
                revStr.append(oriStr.toString()).reverse();
                result.append(chkPseudopalin(oriStr.toString(),revStr.toString()));
                revStr.setLength(0);
                oriStr.setLength(0);
                s.setLength(0);
                r.setLength(0);
            }
            result.deleteCharAt(result.length()-1);
            bw.write(result.toString());
            bw.close();
        }
        catch(FileNotFoundException e) {
            bws.write("File Not Found.");
            bws.close();
        }
//        long end = System.currentTimeMillis();
//        System.out.printf("Exec time : %.3f sec(s)", ((end-begin)/1000.0));
    }

}
