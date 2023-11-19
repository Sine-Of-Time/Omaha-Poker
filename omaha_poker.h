#ifndef _POKER_H
#define _POKER_H
//
/* Maximum possible combinations == 4C2 (2 required player cards) * 5C3 (3 required community cards) */
#define MAX_COMBINATIONS 60

#define BIT(n)			(1UL << (n))
#define IS_SET(v, n)	((v) & BIT(n))
#define BIT_SET(v,n) ((v)|=BIT(n))

/* This enum represents the possible values a card can have. ONE is a dummy */
enum Value {
	ONE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
	EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};

/* This enum represents the possible suit a card can be. */
enum Suit {
	CLUB = 0, DIAMOND, HEART, SPADE
};

/* This structure represents a card with a given suit and value */
struct card {
	enum Value val;
	enum Suit suit;
};

/* This structure represents a single hand comprising of 5 cards: 2 from player cards and 3 from community cards.
 * It comprises of an array of "cards" defined above along with an unsigned long number (call it 'vector') 
 * of the hand representing the strength. 
 * It also maintains an array of 13 integers that records the number of times a card of a certain value appears in the hand*/
struct hand {
	struct card cards[5];
	unsigned int card_count[13]; /* 13 cards in all */
	unsigned long vector;
};

/* This structure represents a player. It comprises of: 
 * a) An array of MAX_COMBINATION number of hands. These are all possible hands the player can make given their 4 cards and the community cards. 
 * b) A pointer best_hand that points to the strongest hand in the array of hands. 
 */
struct player { //So player has two structs in it. One is a hand and the other is the best hand
	struct hand hands[MAX_COMBINATIONS]; 
	struct hand *best_hand;//Points to a specific hand
};

struct card parse_ref(const char *card);
void count_cards_ref(struct hand *h);
int is_flush_ref(struct hand *h);
int is_straight_ref(struct hand *h);
int is_straight_flush_ref(struct hand *h);
void eval_strength_ref(struct hand *h);
void print_hand_ref(struct hand *h);
void eval_players_best_hand_ref(struct player *p);
void copy_card_ref(struct card *dst, struct card *src);
void initialize_player_omaha_ref(struct player *p, struct card *player_cards, struct card *community_cards);
void process_input_omaha_ref(FILE *fp);


#endif
