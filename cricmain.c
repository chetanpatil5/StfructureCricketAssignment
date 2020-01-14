#include<stdio.h>
#include "cric.h"
#include <stdlib.h> 
#include<time.h> 

int main()
{
	srand(time(0));
	//struct Player p;
	struct Team t[2];
	for (int i = 0; i < 2; i++)
	{
		accept(&t[i]);

	}
	for (int i = 0; i < 2; i++)
	{
		display(&t[i]);
	}

	printf("\n Starting the match ....");
	printf("\n First Innings...");
	playmatch(&t[0], &t[1]);
	printf("\n Second Innings...");
	playmatch(&t[1], &t[0]);

	if (t[1].team_runs > t[0].team_runs) {
		printf("\n-----------------------------------------------------\n\n");
		printf("\n Team %d winss :)", t[1].team_id);
		printf("\n Team runs %d", t[1].team_runs);
		printf("\n Team wickets %d", t[1].team_wickets);

		printf("\n\n Team %d loses :(", t[0].team_id);
		printf("\n Team runs %d", t[0].team_runs);
		printf("\n Team wickets %d", t[0].team_wickets);
	}
	else if (t[1].team_runs < t[0].team_runs)
	{
		printf("\n-----------------------------------------------------\n\n");
		printf("\n Team %d winss :)", t[0].team_id);
		printf("\n Team runs %d", t[0].team_runs);
		printf("\n Team wickets %d", t[0].team_wickets);

		printf("\n\n Team %d loses :(", t[1].team_id);
		printf("\n Team runs %d", t[1].team_runs);
		printf("\n Team wickets %d", t[1].team_wickets);

	}
	else {
		printf("\n It is a draw");
	}
	//for (int i = 0; i < 2; i++)
	//{

	//}


	return 0;
}

