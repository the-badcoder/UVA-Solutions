// Don't place your source in a package
import java.util.*;
import java.io.*;
import java.math.*;

// Please name your class Main
class Main {

    public static void main (String[] args) throws IOException {
       Scanner in  = new Scanner( System.in );
       int t = in.nextInt();
       BigDecimal ans, inp;
       for( int cs=1; cs<=t; cs++ ) {
           ans = BigDecimal.ZERO;
           while( true ) {
               inp = in.nextBigDecimal();
               if( inp.equals( BigDecimal.ZERO ) ) break;
               ans = ans.add( inp );
           }
           //ans.stripTrailingZeros( ).toPlainString();
           //ans = ans.stripTrailingZeros( ).toPlainString();
           System.out.println(  ans.stripTrailingZeros( ).toPlainString() );
       }
    }

}
