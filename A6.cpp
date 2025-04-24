#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int number, solved, total_time;
	int problems[20];
} Team;

typedef struct
{
	int team, problem, time;
} Rejected;

int compare(const void *a, const void *b)
{
	Team *team_a = *(Team **)a;
	Team *team_b = *(Team **)b;

	if (team_a->solved != team_b->solved)
	{
		return team_b->solved - team_a->solved;
	}

	if (team_a->total_time != team_b->total_time)
	{
		return team_a->total_time - team_b->total_time;
	}

	if (team_a->number != team_b->number)
	{
		return team_a->number - team_b->number;
	}
}

int main()
{
	FILE *input = fopen("input.txt", "r");
	FILE *output = fopen("output.txt", "w");

	int C, N;
	fscanf(input, "%d %d", &C, &N);
	Team *teams[C];

	for (int i = 0; i < C; i++)
	{
		teams[i] = (Team *)calloc(1, sizeof(Team));
		teams[i]->number = i + 1;
	}

	Rejected reject[N];
	int r = 0, team, problem, time, status;
	for (int i = 0; i < N; i++)
	{
		fscanf(input, "%d %d %d %d", &team, &problem, &time, &status);

		int *problem_time = &(teams[team - 1]->problems[problem - 1]);
		if (status && (*problem_time > time || !(*problem_time)))
		{
			if (!(*problem_time))
			{
				teams[team - 1]->solved++;
			}
			teams[team - 1]->total_time += time - (*problem_time);
			*problem_time = time;
		}
		else if (!status)
		{
			reject[r].team = team;
			reject[r].problem = problem;
			reject[r].time = time;
			r++;
		}
	}

	for (int i = 0; i < r; i++)
	{
		team = reject[i].team;
		problem = reject[i].problem;
		time = reject[i].time;
		if (teams[team - 1]->problems[problem - 1] > time)
		{
			teams[team - 1]->total_time += 20 * 60;
		}
	}

	qsort(teams, C, sizeof(Team *), compare);

	for (int i = 0; i < C; i++)
	{
		fprintf(output, "%d ", teams[i]->number);
	}
}