#ifndef __TIME_H__
#define __TIME_H__

// Search modes
constexpr int TIME = 1;
constexpr int DEPTH = 2;
// constexpr int NODES = 3;
constexpr int MOVETIME = 4;

// Time management constants
constexpr int MOVE_HORIZON = 40; // expect this many moves left in the game
constexpr int ENDGAME_HORIZON_LIMIT = 80;
constexpr int MOVE_HORIZON_DEC = 8;     // at the endgame horizon limit, move horizon decreases by this much
constexpr double TIME_FACTOR = 0.85;    // timeFactor = log b / (b - 1) where b is branch factor
constexpr double MAX_TIME_FACTOR = 5.0; // do not spend more than this multiple of time over the limit
constexpr double ALLOTMENT_FACTORS[10] = {1.0, 0.99, 0.38, 0.28, 0.23, 0.20, 0.18, 0.16, 0.14, 0.12};
constexpr double MAX_USAGE_FACTORS[10] = {1.0, 0.99, 0.74, 0.66, 0.62, 0.59, 0.56, 0.54, 0.52, 0.51};

struct TimeManagement
{
    int searchMode;
    int allotment;
    // Hard limit on time usage for this move, only for time-based searches
    int maxAllotment;
};

#endif