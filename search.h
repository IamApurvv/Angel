#ifndef __SEARCH_H__
#define __SEARCH_H__

#include "board.h"
#include "common.h"
#include "timeman.h"

struct TwoFoldStack
{
public:
    uint64_t keys[256];
    int rootEnd;
    int length;

    TwoFoldStack()
    {
        rootEnd = 0;
        length = 0;
    }
    ~TwoFoldStack() {}

    void push(uint64_t pos)
    {
        keys[length] = pos;
        length++;
    }

    void pop() { length--; }

    void clear()
    {
        rootEnd = 0;
        length = 0;
    }

    void setRootEnd() { rootEnd = length - 1; }

    bool find(uint64_t pos)
    {
        for (int i = length - 1; i >= 0; i--)
        {
            if (keys[i] == pos)
            {
                // If the repetition occurred in the actual game, search for a third repetition.
                // This allows two-folds to terminate search only when the two-fold occurred entirely within the search tree.
                if (i <= rootEnd)
                {
                    for (int j = i - 1; j >= 0; j--)
                    {
                        if (keys[j] == pos)
                            return true;
                    }
                }
                // The two-fold repetition occurred within the search tree, return true.
                else
                    return true;
            }
        }
        return false;
    }
};

/**
 * @brief Stores search info on a preallocated stack
 */
struct SearchStackInfo
{
    int ply;
    int staticEval;
    int **counterMoveHistory;
    int **followupMoveHistory;
};

void getBestMoveThreader(const Board *b, TimeManagement *timeParams, MoveList *movesToSearch);
void clearTables();
void setHashSize(uint64_t MB);
uint64_t getNodes();
void setMultiPV(unsigned int n);
void setNumThreads(int n);
void initPerThreadMemory();
void initReductionTable();
TwoFoldStack *getTwoFoldStackPointer();

// Pondering
void startPonder();
void stopPonder();

// Time constants
constexpr uint64_t ONE_SECOND = 1000;
constexpr uint64_t MAX_TIME = (1ULL << 63) - 1;

// Search parameters
constexpr int EASYMOVE_MARGIN = 150;
constexpr int NEAR_MATE_SCORE = 2500;
// An arbitrary value, but this leaves 266 plies to account for hash table grafting.
constexpr int MAX_PLY_MATE_SCORE = 32500;

#endif