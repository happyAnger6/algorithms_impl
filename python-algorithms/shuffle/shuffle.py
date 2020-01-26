from collections import namedtuple

Card = namedtuple('Card', ['rank', 'suit'])

class FrenchDeck:
    ranks = [str(n) for n in range(2, 11)] + list('JQKA')
    suits = 'spades diamonds clubs hearts'.split()
    def __init__(self):
        self._cards = [Card(rank, suit) for suit in self.suits
                                       for rank in self.ranks]
        self._cards.append(Card('black','joker'))
        self._cards.append(Card('red', 'joker'))

    def __len__(self):
        return len(self._cards)

    def __getitem__(self, item):
        return self._cards[item]

    def shuffle(self):
        old_cards = self._cards
        import random
        for i in range(len(old_cards)):
            ix = random.randrange(i, len(old_cards))
            old_cards[i], old_cards[ix] = old_cards[ix], old_cards[i]
        self._cards = old_cards

if __name__ == "__main__":
    cards = FrenchDeck()
    for card in cards:
        print(card)

    cards.shuffle()
    for card in cards:
        print(card)




