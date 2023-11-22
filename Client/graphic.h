typedef enum {
	SINGLE,
	ONLINE,
	EXIT
}PLAYMODE;
typedef enum {
	DIAMOND, SPADE, HEART, CLUB, UNKNOWN_SHAPE
}CARD_SHAPE;
typedef enum {
	CALL, RAISE, FOLD, ALL_IN, CHECK
}BET;
typedef enum {
	UNKNOWN_DECK, HIGH_CARD, ONE_PAIR, TWO_PAIR, TRIPLE, STRAIGHT, FLUSH, FULL_HOUSE, FOUR_CARD, STRAIGHT_FLUSH, ROYAL
}HAND;

void cursor();
PLAYMODE get_menu_playmode();
int get_menu_capital();
void set_table();
BET get_menu_bet();
void set_card(CARD_SHAPE shape, int num, int player, int card_order);
void set_money(int player_num, int player_money);