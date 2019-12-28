using System;

namespace dragisa_drakula{
    class ojsa_prske{
        int x, y, z;
        public int X{
            get { return x; }
            set { x = X; }
        }
        public int Y{
            get { return y; }
            set { y = Y; }
        }
        public int Z{
            get { return z; }
            set { z = Z; }
        }
        public ojsa_prske(){
            x = 0;
            y = 0;
            z = 0;
        }
        public ojsa_prske(int X, int Y, int Z){
            x = X;
            y = Y;
            z = Z;
        }
        public double troll(ojsa_prske T2){
            return Math.Sqrt(Math.Pow((T2.x - this.x), 2) + Math.Pow((T2.y - this.y), 2) + Math.Pow((T2.z - this.z), 2));
        }
    }

    class ipak_se_okrece{
        static void Main(string[] Args){
            Console.WriteLine("Unesite broj tacka");
            int n = Convert.ToInt32(Console.ReadLine());
            ojsa_prske[] Kruzi = new ojsa_prske[n];
            for (int i = 0; i < n; i++){
                Console.WriteLine("Unesite 'x y z' u tom formatu za tacku {0}", i + 1);
                int[] args = new int[3];
                string[] input = Console.ReadLine().Split(' ');
                for (int j = 0; j < 3; j++)
                    args[j] = Convert.ToInt32(input[j]);
                Kruzi[i] = new ojsa_prske(args[0],args[1],args[2]);
            }

            Console.WriteLine("Kordinate tacka od k.pocetka:");
            for (int j = 0; j < n-1; j++){
                for (int i = 0; i < n-j-1; i++)
                    if ((Math.Abs(Kruzi[i].X) + Math.Abs(Kruzi[i].Y) + Math.Abs(Kruzi[i].Z)) > (Math.Abs(Kruzi[i+1].X) + Math.Abs(Kruzi[i+1].Y) + Math.Abs(Kruzi[i+1].Z))){
                        ojsa_prske p=Kruzi[i];
					    Kruzi[i]=Kruzi[i+1];
					    Kruzi[i+1]=p;
				    }
                Console.WriteLine("Tacka {0}, x:{1} y:{2} z:{3}",j+1,Kruzi[j].X,Kruzi[j].Y,Kruzi[j].Z);
            }
            Console.WriteLine("Tacka {0}, x:{1} y:{2} z:{3}",n-1,Kruzi[n-1].X,Kruzi[n-1].Y,Kruzi[n-1].Z);
            Console.WriteLine("Razdaljina izmedju najdaljih tacka je:{0}",Kruzi[0].troll(Kruzi[n-1]));
        }
    }
}
