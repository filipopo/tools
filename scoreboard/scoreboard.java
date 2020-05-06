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

public class scoreboard {
	private static String e_synonyms() {
		String[] array = {
			"Enter ",
			"Put in ",
			"Put out ",
			"Give me ",
			"Davai ",
			"Gurni "
		};

		int random = ThreadLocalRandom.current().nextInt(0, array.length);
		return array[random];
	};

	private static String p_synonyms() {
		String[] array = {
			"bro",
			"contestant",
			"kursadžija",
			"sperminator",
			"pussy destroyer",
			"brat moj"
		};

		int random = ThreadLocalRandom.current().nextInt(0, array.length);
		return array[random];
	};

	private static String t_synonyms() {
		String[] array = {
			"team",
			"no homo brojob",
			"gangbang",
			"braća bez gaća",
			"meat beaters",
			"sinners group"
		};

		int random = ThreadLocalRandom.current().nextInt(0, array.length);
		return array[random];
	};

	private static String s_synonyms() {
		String[] array = {
			"cumshot count",
			"amount of spilled milk",
			"amount of dick juice",
			"merilo svršotine",
			"white stuff amount",
			"pena od sapunjanje"
		};

		int random = ThreadLocalRandom.current().nextInt(0, array.length);
		return array[random];
	};

    public static void main(String args[]) {
        Scanner vagina = new Scanner(System.in);

        System.out.println(e_synonyms() + "how many " + p_synonyms() + "'s are there in 1 " + t_synonyms() + ":");
        int bros = vagina.nextInt();

        System.out.println(e_synonyms() + "how many " + t_synonyms() + "'s are there:");
        int n = vagina.nextInt();

		int weiner = 0;
		team[] penetratus = new team[n];

        for(int i = 0;i < n;i++) {
			penetratus[i] = new team(bros, i);

            System.out.println("\n" + t_synonyms() + " " + Integer.toString(i + 1) + ":");
			String adj = "st";

            for (int j = 0;j < bros;j++) {
                System.out.println(e_synonyms() + "the " + Integer.toString(j + 1) + adj + " " + p_synonyms() + "'s " + s_synonyms() + ":");
				int temp = vagina.nextInt();
                penetratus[i].members[j] = temp;

                if (temp > weiner)
                    weiner = temp;

				if (j < 1)
					adj = "nd";
				else if (j < 2)
					adj = "rd";
				else
					adj = "th";
            }
        }
        vagina.close();

        for (int i = 0;i < n - 1;i++)
            for (int j = 0;j < n - i - 1;j++)
                if (penetratus[j].semen() < penetratus[j + 1].semen()) {
                    team boobs = penetratus[j];
                    penetratus[j] = penetratus[j + 1];
                    penetratus[j + 1] = boobs;
                }

        System.out.println("\nWe cum in pairs, the strongest " + t_synonyms() + "'s:");
        for(int i = 0;i < n;i++) {
            System.out.println("#" + Integer.toString(i + 1) + " - " + t_synonyms() + " " + Integer.toString(penetratus[i].index + 1) + ":");

            for (int j = 0;j < bros;j++)
                System.out.println(p_synonyms() + " " + Integer.toString(j + 1) + "'s " + s_synonyms() + " is " + Integer.toString(penetratus[i].members[j]));

            System.out.println("--\n" + Integer.toString(penetratus[i].semen()) + " " + s_synonyms() + "\n");
        }
        System.out.println("Iron balls, the strongest " + p_synonyms() + "'s " + s_synonyms() + " is " + Integer.toString(weiner) + "!?!");
    }
}
