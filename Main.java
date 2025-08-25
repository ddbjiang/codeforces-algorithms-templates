import java.util.*;
import java.io.*;


public class Main {
    static PrintWriter pw=new PrintWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args)throws Exception {
        BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
        Read in=new Read();
        
        
        
        pw.flush();
    }
    
	public static class Read {
        StreamTokenizer st=new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
        public int nextInt()throws IOException {
            st.nextToken();
            return (int)st.nval;
        }
        public long nextLong()throws IOException {
            st.nextToken();
            return (long)st.nval;
        }
        public double nextDouble()throws IOException {
            st.nextToken();                                                                                                                                                                           
            return st.nval;
        }
        public String nextword()throws Exception {
            st.nextToken();
            return st.sval;
        }
    }
}

