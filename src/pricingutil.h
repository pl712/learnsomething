//
// Created by Ethan on 8/18/2023.
//

#ifndef LEARNSOMETHING_PRICINGUTIL_H
#define LEARNSOMETHING_PRICINGUTIL_H


class PricingUtil {
  public:
    PricingUtil();
    float calcVal(float prevPrice, float interest, float oleoConstant);
    float getVal();
  private:
    float val;
};


#endif //LEARNSOMETHING_PRICINGUTIL_H
