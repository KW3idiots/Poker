typedef enum {
	SINGLE,
	ONLINE,
	EXIT
}PLAYMODE;
typedef enum {
	DIAMOND, SPADE, HEART, CLUB, UNKNOWN
}CARD_SHAPE;
typedef enum {
	CALL, RAISE, FOLD, ALL_IN
}BET;
void cursor();
PLAYMODE get_menu_playmode();
int get_menu_capital();
void set_table();
BET get_menu_bet();
void set_card(CARD_SHAPE shape, int num, int player, int card_order);