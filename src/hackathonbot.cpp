//
// Created by Ethan on 9/13/2023.
//

#include "hackathonbot.h"
#include "action.h"

/*
You can only have 1 stock at a time, and cannot short a stock (can't sell without having an explicit stock)
Assume the initial stock cost was 100
If the stock goes up in price for 52 windows, sell //
If the stock goes down in price for 47 windows, sell //
If the stock drops by over 62% from the purchase price bought, sell //
If the stock raises by over 89% from the purchase price bought, sell //
If (after buying) the stock raises by >= 20%, drops by <= 15%, raises again by >= 30% and the percent change in the 3 series window is up by >= 50% sell
If (after buying) the stock drops by <= 15%, raises by >= 15%, drops again by >= 25% and the percent change OVERALL is down by >= 45% sell
If stock stays +-5% for 10 cycles (after buying), sell //
If the stock price is less than 52, buy//
If the stock drops in price for 5 windows (after selling), buy//
*/





HackathonBot::HackathonBot() {
    this->prevPrice.push_back(100);
}

void HackathonBot::takeAction(float price) {

    if (price > this->prevPrice.back()){
        this->bullish++;
        this->prevPrice.push_back(price);
    }else if (price < this->prevPrice.back()){
        this->bearish++;
        this->prevPrice.push_back(price);
    }else{
        this->bullish = 0;
        this->bearish = 0;
        this->prevPrice.push_back(price);
    }

    if (!this->holding) {
        if (price < 52.0 || this->bearish >= 5) {
            this->buy();
        }
        return;
    }

    if (this->holding) {
        if (this->bullish >= 52 || this->bearish >= 47){
            this->sell();
            return;
        }

        if (price < this->prevPrice.front() * 0.38 || price > this->prevPrice.front() * 1.89){
            this->sell();
            return;
        }

        if (this->prevPrice.size() == 10){
            float prevPrice = this->prevPrice.front();
            for (auto p : this->prevPrice){
                if (p < prevPrice * 0.95 || p > prevPrice * 1.05){
                    return;
                }
            }
            this->sell();
            return;
        }

        if (this->prevPrice.size() > 3){

            float first = this->prevPrice.front();
            float lastPrice1 = this->prevPrice.at(this->prevPrice.size() - 1);
            float lastPrice2 = this->prevPrice.at(this->prevPrice.size() - 2);
            float lastPrice3 = this->prevPrice.at(this->prevPrice.size() - 3);
            float lastPrice4 = this->prevPrice.at(this->prevPrice.size() - 4);

            if ((lastPrice2 >= lastPrice1 * 1.2 && lastPrice3 < lastPrice2 && lastPrice3 >= lastPrice2 * 0.85 && lastPrice4 > lastPrice3 * 1.3 && (lastPrice4 - lastPrice1) / lastPrice1 > 0.5)
                || (lastPrice2 < lastPrice1 && lastPrice2 >= lastPrice1 * 0.85 && lastPrice3 > lastPrice2 * 1.15 && lastPrice4 <= lastPrice3 * 0.75 && (lastPrice4 - first) / first <= -0.45))
            {
                this->sell();
                return;
            }
        }

        
    }
    


}

double HackathonBot::getBalance() {
    return this->balance;
}

bool HackathonBot::isHolding() {
    return this->holding;
}

void HackathonBot::buy() {
    this->holding = true;
    this->balance = 1;
}

void HackathonBot::sell() {
    this->holding = false;
    this->balance = 0;
    this->prevPrice.clear();
}
