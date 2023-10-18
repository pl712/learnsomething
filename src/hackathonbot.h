//
// Created by Ethan on 9/13/2023.
//

#include <vector>
#include <deque>
#include "action.h"
using namespace std;

#ifndef LEARNSOMETHING_HACKATHONBOT_H
#define LEARNSOMETHING_HACKATHONBOT_H

class HackathonBot {
public:
    HackathonBot();
    void takeAction(float price);
    double getBalance();
    bool isHolding();
private:
    double balance;
    bool holding;
    deque<float> prevPrice;
    int bullish = 0;
    int bearish = 0;
    void buy();
    void sell();
};

#endif //LEARNSOMETHING_HACKATHONBOT_H
