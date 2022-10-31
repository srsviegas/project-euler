"""
The file, poker.txt, contains one-thousand random hands dealt to two players. 
How many hands does Player 1 win?
"""

from collections import Counter


def getRank(hand):
    """ Define the rank of a given hand """
    nvalues = len(set(hand.values))
    straight = (nvalues == 5) and (hand.values[-1] - hand.values[0] == 4)
    flush = len(set(hand.suits)) == 1
    nOfKind = Counter(hand.values).most_common()[0]
    if straight and flush:
        if hand.values[-1] == 14:
            return ["Royal Flush", ""]
        else:
            return ["Straight Flush", ""]
    elif nOfKind[1] == 4:
        return ["Four of a Kind", nOfKind[0]]
    elif nOfKind[1] == 3 and nvalues == 2:
        return ["Full House", nOfKind[0]]
    elif flush:
        return ["Flush", ""]
    elif straight:
        return ["Straight", ""]
    elif nOfKind[1] == 3:
        return ["Three of a Kind", nOfKind[0]]
    elif nvalues == 3:
        return ["Two Pairs", ""]
    elif nOfKind[1] == 2:
        return ["One Pair", nOfKind[0]]
    else:
        return ["High Card", hand.values[-1]]

class Hand:
    values = {str(i):i for i in range(1, 10)}
    values.update({'T': 10, 'J': 11, 'Q': 12, 'K': 13, 'A': 14})

    ranks = {
        "High Card": 0,
        "One Pair": 1,
        "Two Pairs": 2,
        "Three of a Kind": 3,
        "Straight": 4,
        "Flush": 5,
        "Full House": 6,
        "Four of a Kind": 7,
        "Straight Flush": 8,
        "Royal Flush": 9
    }

    def __init__(self, cards):
        self.cards = cards
        self.suits = tuple(c[1] for c in self.cards)
        self.values = sorted(Hand.values[c[0]] for c in self.cards)
        self.rank = getRank(self)
    
    def __repr__(self) -> str:
        return f"{self.cards} {self.rank}"

    def play(self, other):
        """ Compare two hands and return true if self wins """
        # Winner is the one with the highest rank
        if Hand.ranks[self.rank[0]] > Hand.ranks[other.rank[0]]:
            return True
        elif Hand.ranks[other.rank[0]] > Hand.ranks[self.rank[0]]:
            return False
        # Same rank:
        else:
            # Winner is the one with the rank made of the highest value
            if self.rank[1] > other.rank[1]:
                return True
            elif other.rank[1] > self.rank[1]:
                return False
            # Winner is the one with the highest card
            v = max(set(self.values).symmetric_difference(set(other.values)))
            if v in self.values:
                return True
            else:
                return False


if __name__ == "__main__":
    rounds = open("054-poker.txt", "r")
    winsP1 = 0
    for round in rounds:
        round = round.split()
        p1 = Hand(round[:5])
        p2 = Hand(round[5:])
        if p1.play(p2):
            winsP1 += 1
            print(f'{p1}\n{p2}\n')

    print(f"\n----> PLAYER 1 won [{winsP1}] times <----")
    print(f"      PLAYER 2 won [{1000-winsP1}] times\n")