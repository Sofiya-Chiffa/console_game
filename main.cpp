#include <iostream>
#include <random>
#include <ctime>
#include <Windows.h>

using namespace std;

string RandName() {
	srand(time(0));
	char a[] = {'a', 'e', 'y', 'u', 'i', 'o'};
	char b[] = {'q', 'w', 'r', 't', 'p', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c' , 'v', 'b', 'n', 'm'};
	int len = rand() % 8;
	len = len + (len % 2);
	string name = "";
	int l = rand() % 2;
	for (int i = 0; i < len; ++i) {
		if (l % 2 == 0) {
			name += b[rand() % 20];
		}
		else {
			name += a[rand() % 6];
		}
		l += 1;
	}
	return name;
}

class player {
public:
	string name;
	int hp;
	int exp;
	int lvl;
	int atk;


	player(string Name, int Hp=100, int Lvl=1, int Atk=21) {
		name = Name;
		lvl = Lvl;
		hp = Hp * lvl;
		atk = Atk * lvl;
		exp = 0;
	}

	void print_info() {
		cout << name << " hp=" << hp << endl;
	}

	void fight(player sb) {
		srand(time(0));
		while (hp > 0 && sb.hp > 0) {
			hp -= rand() % atk;
			sb.hp -= rand() % sb.atk;
			system("cls");
			cout << name << "-" << hp << "\n";
			cout << sb.name << "-" << sb.hp << "\n";
			Sleep(400);
		}
		if (hp > 0) {
			while (hp < 100 * lvl) {
				hp += 5;
				Sleep(400);
				system("cls");
				if (hp > 100) { hp = 100; }
				cout << name << " " << hp;
			}
			exp += 15;
			levelUP();
			cout << "\n";
		}
	}

	void levelUP() {
		if (lvl * 100 <= exp) {
			exp = lvl * 10 - exp;
			lvl += 1;
			hp += 100;
			atk += 20;
			for (int i = 0; i < 10; ++i) {
				system("cls");
				cout << "New level! " << lvl << "!\n";
				Sleep(300);
			}
			Sleep(400);
		}
	}
};

int main()
{
	srand(time(0));
	player pl1("Afina");
	player pl2(RandName());
	while (pl1.hp > 0) {
		player pl2(RandName(), rand() % 50 + 60, 1 + rand() % pl1.lvl);
		pl1.fight(pl2);
	}
}
