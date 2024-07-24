#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <ctime>
#include <algorithm>
#include <semaphore.h>
#include <string>

using namespace std;

void displayBoard(), *p = 0, stopcheck();
const int dicet[8] = {1, 6, 2, 3, 4, 5, 6, 6};
int dice[3], plays, gotein;
const string RESET_CLR = "\e[0m", RED_CLR = "\e[31m", GRN_CLR = "\e[32m", YELO_CLR = "\e[33m", BLU_CLR = "\e[34m", RED_BG = "\e[0;41m", GRN_BG = "\e[0;42m", YELO_BG = "\e[0;43m", BLU_BG = "\e[0;44m", flash = "\e[107m \e[0m";
string track[52], ltrack[4][5];
void trackreset(int i = 0) // track[i][3]=background by Tens digit; track[i][5]= Ones value
{
	track[i] = "\e[40m0\e[0m", track[i][5] += i % 10, track[i][3] += (i / 10);
}
void ltrackreset(int i = 0, int j = 0) // track[i][j] i player, jth position on out track
{
	ltrack[i][j] = "\e[41m \e[0m", ltrack[i][j][3] += i;
}
inline void cls() { printf("\e[H\e[J"); }
inline void plswait(long double k)
{
	struct timespec remaining, request = {static_cast<long>(k),
										  static_cast<long>(long((k - (long)k) * 1000000000) % 1000000000)};
	nanosleep(&request, &remaining);
}

class player
{
public:
	bool beat = 0, active = 1;
	string oout, nam = "A";
	int id = 0, tokco = 4, offset = 52, *prog, *pos;
	player() : id(pcount++), tokco(gotein), oout("\e[0;1;91m#\e[0m")
	{
		prog = new int[tokco], pos = new int[tokco], oout[9] += id, oout[7] += id;
		for (int i = 0; i < tokco; prog[i] = -1, pos[i++] = -1)
			;
		offset -= (id + 1) * 13; // printf("Enter player %i name:",id);cin>>nam;
		// cout<<oout<<endl;
	}
	int canmove(int n)
	{ // return which token can move n steps; return token+=4 if an opponent token is being wrecked
		int x = -1;
		if (!anyopen() and n != 6)
			return x; // none open
		if (anyclose() and n == 6)
			return aclosed();
		for (int i = 0; x < (4 * (rand() & 1)) && i < tokco; i++)
		{
			// open
			if (beat)
			{
				if ((prog[i] + n) == 8 || (prog[i] == 51 && n == 1) || (prog[i] + n) == 13 || (prog[i] + n) == 21 || (prog[i] + n) == 26 || (prog[i] + n) == 34 || (prog[i] + n) == 39 || (prog[i] + n) == 47)
				{
					x = i;
					continue;
				} // on a stop
				for (int j = 0; j < tokco; j++)
				{
					if (prog[i] != 51)
					{
						if (i != j && (prog[i] + n != prog[j]))
						{ // no overlap with friend tokens
							x = i;
							if (prog[i] + n < 51)
							{
								if (track[(pos[i] + n) % 52][2] == '4')
									; // empty track
								else
									x += 4; // opp on track (since it's neither empty nor friend)
							}
							else
								; // it's getting into the leaving track;
						}
					}
					else
					{
						if (i != j && ((prog[i] + n) % 52) != prog[j])
						{ // no overlap with friend tokens
							x = i;
							if (track[(pos[i] + n) % 52][2] == '4')
								; // empty track
							else
								x += 4; // opp on track
						}
					}
				}
			}
			else // no beat yet
			{
				if ((prog[i] + n) == 8 || (prog[i] == 51 && n == 1) || (prog[i] + n) == 13 || (prog[i] + n) == 21 || (prog[i] + n) == 26 || (prog[i] + n) == 34 || (prog[i] + n) == 39 || (prog[i] + n) == 47)
				{
					x = i;
					continue;
				} // on a home color stop
				for (int j = 0; j < tokco; j++)
				{
					if (i != j && ((prog[i] + n) % 52) != prog[j])
					{ // no overlap with friend tokens
						x = i;
						if (track[(pos[i] + n) % 52][2] == '4')
							; // empty track
						else
							x += 4; // opp on track
					}
				}
			}
		}
	}
	int aclosed()
	{
		int x = -1;
		for (int i = 0; i < tokco; i++)
			if (prog[i] < 0)
				x = i;
		return x;
	}
	void bury(int p)
	{
		for (int i = 0; i < tokco; i++)
			if (pos[i] == p)
			{
				prog[i] = -1;
				track[pos[i]] = flash;
				displayBoard();
				trackreset(pos[i]);
				displayBoard();
				pos[i] = -1;
			}
	}
	void mov(int i, int n)
	{
		if (i < 4)
		{
			if (prog[i] < 0 && n == 6)
			{
				printf("\e[10%imToken opened\t\e[0m", id);
				prog[i] = 0, pos[i] = offset,
				track[pos[i]] = oout;
				return;
			}
			else if (beat)
			{
				if (prog[i] < 51)
				{
					trackreset(pos[i]);
					if ((prog[i] + n) > 50)
					{
						prog[i] += n + 1;
						pos[i] = prog[i] % 52;
						if (prog[i] == 57)
							return;
						ltrack[id][pos[i]] = oout;
					}
					else
						prog[i] += n, pos[i] += n, pos[i] %= 52, track[pos[i]] = oout;
				}
				else if (prog[i] == 51)
				{
					trackreset(pos[i]);
					prog[i] = n - 1, pos[i] = offset + n - 1, track[pos[i]] = oout;
				}
				else
				{
					ltrackreset(pos[i]), prog[i] += n, pos[i] += n;
					if (prog[i] == 57)
						return;
					ltrack[id][pos[i]] = oout;
				}
			}
			else
			{
				trackreset(pos[i]);
				prog[i] += n, prog[i] %= 52, pos[i] += n, pos[i] %= 52, track[pos[i]] = oout;
			}
		}
		else
		{
			trackreset(pos[i]);
			int o = track[(pos[i] + n) % 52][7] - '1';
			((player *)p)[o].bury((pos[i] + n) % 52);
			prog[i] += n, pos[i] += n, pos[i] %= 52, beat = 1;
			return;
		}
	}
	bool anyopen()
	{
		bool x = 0;
		for (int i = 0; i < tokco && !x; i++)
			x = (prog[i] >= 0 && prog[i] < 58);
		return x;
	}
	bool anyclose()
	{
		bool x = 0;
		for (int i = 0; i < tokco && !x; x = (prog[i++] < 0))
			;
		return x;
	}
	bool win()
	{
		bool x = 1;
		for (int i = 0; i < tokco && x; x = (prog[i++] == 58))
			;
		return x;
	}
	static int pcount, winp;
};
int player::pcount = 0;
int player::winp = 1;
pthread_t tid[4];
player *plid = 0;
int *turns = 0;
sem_t di, bo; // dice sem, board sem
void displayBoard()
{
	stopcheck();
	plswait(0.5);
	cls();
	cout << " _______________________________\n"
		 << "|" << BLU_BG << "            \e[0m|" << track[10] << "|" << track[11] << "|" << track[12] << "|" << YELO_BG << "            \e[0m|\n"
		 << "|" << BLU_BG << "            \e[0m|" << track[9] << YELO_BG << "|" << ltrack[2][0] << "|" << track[13] << "|" << YELO_BG << "            \e[0m|\n"
		 << "|" << BLU_BG << "            \e[0m|" << track[8] << YELO_BG << "|" << ltrack[2][1] << "|\e[0m" << track[14] << "|" << YELO_BG << "            \e[0m|\n"
		 << "|" << BLU_BG << "            \e[0m|" << track[7] << YELO_BG << "|" << ltrack[2][2] << "|\e[0m" << track[15] << "|" << YELO_BG << "            \e[0m|\n"
		 << "|" << BLU_BG << "            \e[0m|" << track[6] << YELO_BG << "|" << ltrack[2][3] << "|\e[0m" << track[16] << "|" << YELO_BG << "            \e[0m|\n"
		 << "|" << BLU_BG << "            \e[0m|" << track[5] << YELO_BG << "|" << ltrack[2][4] << "|\e[0m" << track[17] << "|" << YELO_BG << "            \e[0m|\n"
		 << "|" << track[51] << BLU_BG << "|" << track[0] << "|\e[0m" << track[1] << "|" << track[2] << "|" << track[3] << "|" << track[4] << "|\e[100m       \e[0m|" << track[18] << "|" << track[19] << "|" << track[20] << "|" << track[21] << "|" << track[22] << "|" << track[23] << "|\n"
		 << "|" << track[50] << BLU_BG << "|" << ltrack[3][0] << "|" << ltrack[3][1] << "|" << ltrack[3][2] << "|" << ltrack[3][3] << "|" << ltrack[3][4] << "|\e[0;100m       \e[0m" << GRN_BG << "|" << ltrack[1][4] << "|" << ltrack[1][3] << "|" << ltrack[1][2] << "|" << ltrack[1][1] << "|" << ltrack[1][0] << "|\e[0m" << track[24] << "|\n"
		 << "|" << track[49] << "|" << track[48] << "|" << track[47] << "|" << track[46] << "|" << track[45] << "|" << track[44] << "|\e[0;100m       \e[0m|" << track[30] << "|" << track[29] << "|" << track[28] << "|" << track[27] << GRN_BG << "|" << track[26] << "|\e[0m" << track[25] << "|\n"
		 << "|" << RED_BG << "            \e[0m|" << track[43] << RED_BG << "|" << ltrack[0][4] << "|\e[0m" << track[31] << "|" << GRN_BG << "            \e[0m|\n"
		 << "|" << RED_BG << "            \e[0m|" << track[42] << RED_BG << "|" << ltrack[0][3] << "|\e[0m" << track[32] << "|" << GRN_BG << "            \e[0m|\n"
		 << "|" << RED_BG << "            \e[0m|" << track[41] << RED_BG << "|" << ltrack[0][2] << "|\e[0m" << track[33] << "|" << GRN_BG << "            \e[0m|\n"
		 << "|" << RED_BG << "            \e[0m|" << track[40] << RED_BG << "|" << ltrack[0][1] << "|\e[0m" << track[34] << "|" << GRN_BG << "            \e[0m|\n"
		 << "|" << RED_BG << "            \e[0m|" << track[39] << "|" << ltrack[0][0] << "|\e[0m" << track[35] << "|" << GRN_BG << "            \e[0m|\n"
		 << "|" << RED_BG << "            \e[0m|" << track[38] << "|" << track[37] << "|" << track[36] << "|" << GRN_BG << "            \e[0m|\n"
		 << " -------------------------------\n";
	// for(int i=1;i<45;printf("%i",i++%10));

	for (int i = 0; i < plays; i++)
	{
		int offx = 5, offy = 14;
		if (i > 1)
			offy = 5;
		if ((i + 1) & 2)
			offx = 25;
		printf("\e[%i;%iH", offy, offx);
		for (int j = 0; j < gotein; j++)
			if (plid && (plid[i].prog[j] < 0))
				cout << plid[i].oout << "\e[4" << char('1' + i) << "m";
		offy = 5 + i;
		printf("\e[%i;46H\e[10%improg,pos %i:", offy, i + 1, i);
		for (int j = 0; j < gotein; j++)
			if (plid)
				printf("(%i,%i) ", plid[i].prog[j], plid[i].pos[j]);
	}
	printf("\e[18;1H");
}
void *playerTurn(void *I)
{
	unsigned long id = (unsigned long)I;
	sem_wait(&di);
	int m[3] = {0};
	printf("\e[0;3%imPlayer %i has dice\t", id + 1, id);
	plswait(1);
	dice[0] = dicet[rand() % 8];
	printf("\e[0;3%imPlayer %i roll 1:%i||", id + 1, id, dice[0]);
	if (dice[0] == 6)
	{
		dice[1] = dicet[rand() % 7];
		plswait(1);
		printf("\e[0;3%imPlayer %i roll 2:%i||", id + 1, id, dice[1]);
		if (dice[1] == 6)
		{
			dice[2] = dicet[rand() % 6];
			plswait(1);
			printf("\e[0;3%imPlayer %i roll 3:%i\t\e[0m\n", id + 1, id, dice[2]);
			if (dice[2] == 6)
			{
				printf("\e[0;1;91mTOO MANY SIXES\nPASSING TURN FROM PLAYER %i\n\e[0m", id);
				dice[0] = 0, dice[1] = 0, dice[2] = 0;
				sem_post(&di); // printf("\nKKKKK%ul",id);
				pthread_exit((void *)(id + 10));
			}
		}
	}
	if (!plid[id].anyopen() && dice[0] != 6)
	{
		sem_post(&di);
		pthread_exit((void *)(id + 20));
	}
	for (int i = 0; i < 3; m[i] = dice[i], dice[i++] = 0)
		; // copying moves of dice to this player's turn's moves array
	sem_post(&di);
	sem_wait(&bo);
	printf("\e[0;3%imPlayer %i has board\t\e[0m", id + 1, id);
	/////////////////////////movement management
	//////////////////////////////////////////////
	int tok = -1;
	if (!plid[id].anyopen())
		printf("\e[10;46HNone open of %i\e[19;1H", id);
	// some are open
	for (int i = 0; m[i] && i < 3; i++)
		if (plid[id].canmove(m[i]) > -1)
		{
			tok = plid[id].canmove(m[i]);
			plid[id].mov(tok, m[i]);
		}

	sem_post(&bo);
	pthread_exit((void *)id);
}

int main()
{
	srand(time(0));
	char y = 'y';
	for (int i = 0; i < 52; trackreset(i++))
		; // track[i][3]=background by Tens digit; track[i][5]= Ones value
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 5; ltrackreset(i, j++))
			;
	cls();
	printf("\e[1;36;104mStarting Ludo!!!!\n\n\e[0mEnter number of players:\t"); /*cin>>plays; plays%=5;
	 printf("Enter number of tokens:\t");cin>>gotein;
	 if(plays<2 || gotein<1) {printf("\e[1;101mWāh, kyā kamāl kām kīyā.. jītē reh...\n\e[0m"); return 100;}
	 */
	plays = 4, gotein = 2;
	sem_init(&di, 0, 0);
	sem_init(&bo, 0, 0);
	displayBoard();
	plid = new player[plays];
	p = plid;
	int j = 0;
	sem_post(&di);
	sem_post(&bo);
	while (y == 'y')
	{
		// all players wait
		turns = new int[plays];
		for (int i = 0; i < plays; turns[i++] = i)
			;
		random_shuffle(turns, turns + plays);
		void *tret;
		cout << "\e[0mRound " << j++ << "\tTURN SEQUENCE:";
		for (int i = 0; i < plays; cout << turns[i++] << ' ')
			;
		cout << endl;
		for (int i = 0; i < plays; i++)
			pthread_create(&tid[i], 0, playerTurn, (void *)turns[i]);
		for (int i = 0; i < plays; /*printf("\e[0m\nmain:%i",(int*)tret)*/)
			pthread_join(tid[i++], &tret);

		displayBoard();
		delete[] turns;
		printf("Round %i, Enter y to continue to next round ", j);
		cin >> y;
	}
	delete[] plid;
}
void stopcheck()
{
	int stops[8] = {8, 0, 13, 21, 26, 34, 39, 47};
	for (int s = 0; s < 8; s++)
	{
		bool x = 0;
		if (plid)
			for (int i = 0; !x && i < plays; i++)
				for (int j = 0; !x && j < gotein; j++)
					if (plid[i].pos[j] == stops[s])
						track[plid[i].pos[j]] = plid[i].oout, x = 1;
	}
}