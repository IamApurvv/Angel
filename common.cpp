#include <cassert>
#include "common.h"
int bitScanForward(uint64_t bb)
{
    assert(bb); // ctz(0) is undefined
    return __builtin_ctzll(bb);
}

int bitScanReverse(uint64_t bb)
{
    assert(bb); // clz(0) is undefined
    return __builtin_clzll(bb) ^ 63;
}

int count(uint64_t bb)
{
    return __builtin_popcountll(bb);
}

// Given a start time_point, returns the seconds elapsed using C++11's
// std::chrono::high_resolution_clock
uint64_t getTimeElapsed(ChessTime startTime)
{
    auto endTime = ChessClock::now();
    std::chrono::milliseconds timeSpan =
        std::chrono::duration_cast<std::chrono::milliseconds>(
            endTime - startTime);
    return (uint64_t)timeSpan.count() + 1;
}

std::string moveToString(Move m)
{
    char startFile = 'a' + (getStartSq(m) & 7);
    char startRank = '1' + (getStartSq(m) >> 3);
    char endFile = 'a' + (getEndSq(m) & 7);
    char endRank = '1' + (getEndSq(m) >> 3);
    std::string moveStr = {startFile, startRank, endFile, endRank};
    if (getPromotion(m))
        moveStr += " nbrq"[getPromotion(m)];
    return moveStr;
}
