# tools
Unless stated otherwise to every file in this repository applies:

Copyright: © 2019-now fistmedia

License: <a href="https://www.gnu.org/licenses/lgpl-3.0.txt">GNU Lesser General Public License v3.0 or later</a>

	using System.Linq;

	void search_new_girl() {
		while(true) {
			Console.WriteLine("I Love You");
			string reply = Console.ReadLine();

			if (new[] {"love", "too"}.All(word => reply.ToLower().Contains(word)))
				break;
		}
	}
