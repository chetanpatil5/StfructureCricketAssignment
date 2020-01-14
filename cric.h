
#include<stdio.h>

typedef struct Player
{
	char player_name[20];
	char player_skill[15];
	int runs;
	int wickets;
	int jersey_no;
	int avg_runs;
	int economy;
}Player;

typedef struct Team
{
	int team_id;
	int wins;
	int loose;
	int team_runs;
	int team_wickets;
	Player p[3];
}Team;

void accept(Team *tarr);
void display(Team *tarr);
void playmatch(Team *t_bat, Team *t_bowl);