import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class threeSum_ {
    public static List<List<Integer>>threesum(int[] num){
        Arrays.sort(num);
        List<List<Integer>>result=new ArrayList<>();
        int i=0;
        while(i<num.length-2){
            int j=i+1;
            int k=num.length-1;
            int s=num[i]+num[j]+num[k];
            while(j<k){
                if(i<k&&s<0){
                    k++;
                }else if(s>0){
                    k--;
                }
                else{
                    List<Integer>e=new ArrayList<>();
                    e.add(num[i]);
                    e.add(num[j]);
                    e.add(num[k]);
                    result.add(e);

                    while(j<k&&num[j]==num[j+1]){
                        j++;
                    }
                    j++;
                    }
                    while(j<k&&num[k]==num[k-1]){
                        k--;
                    }
                    k--;
                }
                while(i<num.length-2&&num[i]==num[i++]){
                    i++;
                }
                i++;
            }
        return result;
        }

    public static void main(String[] args) {
        int[]num={-1,-2,0,3,2,1,4};

    }

}




