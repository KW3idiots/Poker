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
