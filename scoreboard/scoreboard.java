import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;

class team {
  public int index;
  public int[] members;
  public int semen() {
    int temp = 0;
    for(int num : members)
      temp += num;

    return temp;
  }

  public team(int bros, int index) {
    members = new int[bros];
    this.index = index;
  }
}

class synonyms {
  private static synonyms singleObj;

  private synonyms() {}

  public static synonyms instance() {
    if (singleObj == null)
      singleObj = new synonyms();

    return singleObj;
  }

  public String getRandom(String[] arr) {
    int random = ThreadLocalRandom.current().nextInt(0, arr.length);
    return arr[random];
  }

  public String[] enterS = {
    "Enter ",
    "Put in ",
    "Put out ",
    "Give me ",
    "Davai ",
    "Gurni "
  };

  public String[] playerS = {
    "bro",
    "contestant",
    "kursadžija",
    "sperminator",
    "pussy destroyer",
    "brat moj"
  };

  public String[] teamS = {
    "team",
    "no homo brojob",
    "gangbang",
    "braća bez gaća",
    "meat beaters",
    "sinners group"
  };

  public String[] semenS = {
    "cumshot count",
    "amount of spilled milk",
    "amount of dick juice",
    "merilo svršotine",
    "white stuff amount",
    "pena od sapunjanje"
  };
}

public class scoreboard {
  public static void main(String args[]) {
    synonyms s = synonyms.instance();
    Scanner vagina = new Scanner(System.in);

    System.out.println(s.getRandom(s.enterS) + "how many " + s.getRandom(s.playerS) + "'s are there in 1 " + s.getRandom(s.teamS) + ":");
    int bros = vagina.nextInt();

    System.out.println(s.getRandom(s.enterS) + "how many " + s.getRandom(s.teamS) + "'s are there:");
    int n = vagina.nextInt();

    int weiner = 0;
    team[] penetratus = new team[n];

    for(int i = 0; i < n; i++) {
      penetratus[i] = new team(bros, i);

      System.out.println("\n" + s.getRandom(s.teamS) + " " + Integer.toString(i + 1) + ":");
      String adj = "st";

      for (int j = 0; j < bros; j++) {
        System.out.println(s.getRandom(s.enterS) + "the " + Integer.toString(j + 1) + adj + " " + s.getRandom(s.playerS) + "'s " + s.getRandom(s.semenS) + ":");
        int temp = vagina.nextInt();
        penetratus[i].members[j] = temp;

        if (temp > weiner)
           weiner = temp;

        switch (j) {
          case 0: adj = "nd"; break;
          case 1: adj = "rd"; break;
          default: adj = "th";
        }
      }
    }
    vagina.close();

    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - i - 1; j++) {
        if (penetratus[j].semen() < penetratus[j + 1].semen()) {
          team boobs = penetratus[j];
          penetratus[j] = penetratus[j + 1];
          penetratus[j + 1] = boobs;
        }
      }
    }

    System.out.println("\nWe cum in pairs, the strongest " + s.getRandom(s.teamS) + "'s:");
    for (int i = 0; i < n; i++) {
      System.out.println("#" + Integer.toString(i + 1) + " - " + s.getRandom(s.teamS) + " " + Integer.toString(penetratus[i].index + 1) + ":");

      for (int j = 0; j < bros; j++)
        System.out.println(s.getRandom(s.playerS) + " " + Integer.toString(j + 1) + "'s " + s.getRandom(s.semenS) + " is " + Integer.toString(penetratus[i].members[j]));

      System.out.println("--\n" + Integer.toString(penetratus[i].semen()) + " " + s.getRandom(s.semenS) + "\n");
    }
    System.out.println("Iron balls, the strongest " + s.getRandom(s.playerS) + "'s " + s.getRandom(s.semenS) + " is " + Integer.toString(weiner) + "!?!");
  }
}
