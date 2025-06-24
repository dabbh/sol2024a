#include <stdio.h>
#include <stdlib.h>
#define MAXPL 15
#define NL 3
typedef enum {premier,national,artzit} league;
typedef struct {
	char *name;
	int ID;
	int height;
	int YOB;
} Player;
typedef struct Team {
	char *name;
	Player *players[MAXPL];
	int shirts[MAXPL];
	int numpl;
} Team;
typedef struct Lteam {
	Team *myT;
	struct Lteam *next;
} Lteam;
typedef struct Sports {
	Lteam *league[NL];
	int numallpl;
	Player **allPls;
} Sports;
Sports *initseason(){
	Sports *s = malloc(sizeof(Sports));
	for(int i = 0; i < NL; i++) {
		s->league[i] = NULL;
	}
	s->numallpl = 0;
	s->allPls = NULL;
	return s;
}