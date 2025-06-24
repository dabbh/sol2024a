#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
Player *addPlayer(Sports *s,const char *name,int height,int year){
	Player *p = malloc(sizeof(Player));
	p->name = malloc(strlen(name) + 1);
	strcpy(p->name, name);
	p->height = height;
	p->YOB = year;
	p->ID = s->numallpl++;
	s->allPls = realloc(s->allPls, s->numallpl * sizeof(Player*));
	s->allPls[s->numallpl - 1] = p;
	return p;
}