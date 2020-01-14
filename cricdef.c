#include<stdio.h>
#include "cric.h"

void accept(Team *tarr )
{
	printf("\nEnter the team_id :");
	scanf_s("%d", &tarr->team_id);
	tarr->loose = 0;
	tarr->team_runs = 0;
	tarr->team_wickets = 0;
	tarr->wins = 0;

	printf("\nEnter the name of the players of this team:");
	for (int i = 0; i < 3; i++)
	{
		tarr->p[i].jersey_no = i + 1;
		tarr->p[i].avg_runs = 0;
		tarr->p[i].economy = 0;
		tarr->p[i].runs = 0;
		tarr->p[i].wickets = 0;
		printf("\nName : ");
		scanf_s("%s", tarr->p[i].player_name,sizeof(tarr->p[i].player_name));

		printf("\nSkill : ");
		scanf_s("%s", tarr->p[i].player_skill, sizeof(tarr->p[i].player_skill));
		printf("\n\n--------------------------------\n");
	}


}

void display(Team *tarr)
{
	printf("\n\n====================================================================");
	printf("\nTeam Id : %d", tarr->team_id);
	for (int i = 0; i < 3; i++)
	{
		printf("\nName of the Player : %s", tarr->p[i].player_name);
		printf("\t Skill : %s", tarr->p[i].player_skill);
	}
	printf("\n");

}

void playmatch(Team *t_bat, Team *t_bowl)
{

	int over[5][6];
	int batsman = 0,bowler=0;

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 6; i++)
		{
			over[j][i] = rand() % 8;


			if (over[j][i] == 7)
			{
				//wicket
				t_bowl->team_wickets++;
				t_bowl->p[bowler].wickets++;
				over[j][i] = -1;
				batsman++;

			}
			printf("\n\n Rand output runs j=%d i=%d ,overRuns = %d \n\n", j, i, over[j][i]);
			if (batsman < 3  && over[j][i] != -1)
			{
				t_bat->p[batsman].runs = t_bat->p[batsman].runs + over[j][i];	//first initialise the runs to zero
				//also check whether k < 3 as 3 players are taken 
				t_bat->team_runs = t_bat->team_runs + over[j][i]; //team runs
			}
			else if (batsman >= 3)
			{
				printf("\n-----------------------------------------------------\n\n");
				printf("\n *** Overs completed %d ***", j);
				printf("\n bowling Team id %d", t_bowl->team_id);
				printf("\n Team runs %d", t_bowl->team_runs);
				printf("\n Team wickets %d", t_bowl->team_wickets);

				printf("\n\nbatting Team id %d", t_bat->team_id);
				printf("\n Team runs %d", t_bat->team_runs);
				printf("\n Team wickets %d", t_bat->team_wickets);
				return;
			}

		}
		bowler = (bowler + 1) % 3;
		printf("\n-----------------------------------------------------\n\n");
		printf("\n *** Overs completed %d ***", j);
		printf("\n bowling Team id %d", t_bowl->team_id);
		printf("\n Team runs %d", t_bowl ->team_runs);
		printf("\n Team wickets %d", t_bowl ->team_wickets);

		printf("\n\nbatting Team id %d", t_bat->team_id);
		printf("\n Team runs %d", t_bat->team_runs);
		printf("\n Team wickets %d", t_bat->team_wickets);
	}

}