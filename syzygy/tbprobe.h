
#ifndef TBPROBE_H
#define TBPROBE_H

#include "../common.h"
#include "../board.h"

extern int TBlargest; // 5 if 5-piece tables, 6 if 6-piece tables were found.

void init_tablebases(char *path);
int probe_wdl(const Board &b, int *success);
int probe_dtz(const Board &b, int *success);
int root_probe(const Board *b, MoveList &rootMoves, ScoreList &scores, int &TBScore);
int root_probe_wdl(const Board *b, MoveList &rootMoves, ScoreList &scores, int &TBScore);

#endif
