#ifndef __MOVEORDER_H__
#define __MOVEORDER_H__

#include <cmath>
#include "board.h"
#include "common.h"
#include "searchparams.h"

enum MoveGenStage
{
    STAGE_NONE,
    STAGE_HASH_MOVE,
    STAGE_CAPTURES,
    STAGE_QUIETS,
    STAGE_QS_CAPTURES,
    STAGE_QS_PROMOTIONS,
    STAGE_QS_CHECKS,
    STAGE_QS_DONE
};

struct ScoredMove
{
    Move m;
    int16_t score;

    ScoredMove() = default;
    ScoredMove(Move _m, int16_t _score)
    {
        m = _m;
        score = _score;
    }
};

inline bool operator==(const ScoredMove &lhs, const ScoredMove &rhs) { return lhs.score == rhs.score; }
inline bool operator!=(const ScoredMove &lhs, const ScoredMove &rhs) { return !operator==(lhs, rhs); }
inline bool operator<(const ScoredMove &lhs, const ScoredMove &rhs) { return lhs.score < rhs.score; }
inline bool operator>(const ScoredMove &lhs, const ScoredMove &rhs) { return operator<(rhs, lhs); }
inline bool operator<=(const ScoredMove &lhs, const ScoredMove &rhs) { return !operator>(lhs, rhs); }
inline bool operator>=(const ScoredMove &lhs, const ScoredMove &rhs) { return !operator<(lhs, rhs); }

struct MoveOrder
{
    Board *b;
    int color;
    int depth;
    SearchParameters *searchParams;
    SearchStackInfo *ssi;
    MoveGenStage mgStage;
    Move hashed;
    MoveList legalMoves;
    SearchArrayList<ScoredMove> scores;
    unsigned int scoreSize;
    unsigned int quietStart;
    unsigned int index;
    int captureMargin;

    MoveOrder(Board *_b, int _color, int _depth, SearchParameters *_searchParams,
              SearchStackInfo *_ssi, Move _hashed, MoveList _legalMoves);
    MoveOrder(Board *_b, int _color, int _depth, SearchParameters *_searchParams,
              SearchStackInfo *_ssi, Move _hashed, MoveList _legalMoves, int _captureMargin);
    // Overloaded constructor for quiescence search
    MoveOrder(Board *_b, int _color, int _depth, SearchParameters *_searchParams);

    void generateMoves();
    Move nextMove();
    void updateHistories(Move bestMove);
    void updateCaptureHistories(Move bestMove);

private:
    void scoreCaptures();
    void scoreQuiets();
    void findQuietStart();
};

#endif