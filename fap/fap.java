import java.util.Scanner;

public class fap{
    public static void main(String args[]){
        Scanner vagina = new Scanner(System.in);
        System.out.println("Enter how many bro's are there in 1 team:");
        int bros=vagina.nextInt();
        System.out.println("Enter how many no homo brojobs are there:");
        int n=vagina.nextInt();
        int[][] semen = new int[n][bros];
        int[][] penetratus = new int[n][2];
        int weiner=0;

        for(int i=0;i<n;i++){
            System.out.println("\nTeam "+Integer.toString(i+1)+":");
            penetratus[i][0]=0;
            penetratus[i][1]=i;
            for (int j=0;j<bros;j++){
                System.out.println("Enter the "+Integer.toString(j+1)+" bro's cumshot count:");
                semen[i][j]=vagina.nextInt();
                penetratus[i][0]+=semen[i][j];
                if (semen[i][j] > weiner)
                    weiner=semen[i][j];
            }
        }
        vagina.close();
        
        for (int i = 0; i < n-1; i++)
            for (int j = 0; j < n-i-1; j++)
                if (penetratus[j][0] < penetratus[j+1][0]){
                    int[] boobs=semen[j];
                    semen[j]=semen[j+1];
                    semen[j+1]=boobs;
                    boobs=penetratus[j];
                    penetratus[j]=penetratus[j+1];
                    penetratus[j+1]=boobs;
                }
                
        System.out.println("\nWe cum in pairs, the strongest teams:");
        for(int i=0;i<n;i++){
            System.out.println("#"+Integer.toString(i+1)+" - Team "+Integer.toString(penetratus[i][1]+1)+":");
            for (int j=0;j<bros;j++)
                System.out.println("Bro "+Integer.toString(j+1)+" - "+Integer.toString(semen[i][j])+" burst(s)");
            System.out.println("--\n"+Integer.toString(penetratus[i][0])+" cumshot(s)\n");
        }
        System.out.println("Iron balls, the strongest bro unleashed "+Integer.toString(weiner)+" shot(s)!");
    }
}
