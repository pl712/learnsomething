class TradeObject:

    def __init__(self, seller, buyer, ticker, price, amount):
        self.seller = seller #str
        self.buyer = buyer #str
        self.ticker = ticker #str
        self.price = price #price > 0
        self.amount = amount #amount > 0

class ExchangeUser:

    def __init__(self, usrName = 'testname'):
        self.holdings = {} # ticker: (amount, avgPrice)
        self.name = usrName

    def add_trade(self, trade:TradeObject):
        ticker = trade.ticker
        if self.name == trade.buyer:
            if ticker in self.holdings:
                #calculates the avg cost after buying at different prices.
                self.holdings[ticker] = (self.holdings[ticker][0] + trade.amount, (self.holdings[ticker][1] * self.holdings[ticker][0] + trade.price * trade.amount) / (self.holdings[ticker][0] + trade.amount))
                if self.holdings[ticker][0] == 0:
                    del self.holdings[ticker]
            else:
                self.holdings[ticker] = (trade.amount, trade.price)

        elif self.name == trade.seller:
            if ticker in self.holdings:
                self.holdings[ticker] = (self.holdings[ticker][0] - trade.amount, self.holdings[ticker][1])
                if self.holdings[ticker][0] == 0:
                    del self.holdings[ticker]
            else:
                self.holdings[ticker] = (-trade.amount, trade.price)

    def getHoldings(self):
        return self.holdings