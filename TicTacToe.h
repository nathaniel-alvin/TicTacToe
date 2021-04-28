struct Node
{
	char x; // X or O or -
	// Node *u, *ur, *r, *rd, *d, *dl, *l, *lu;
	Node *lu, *u, *ur, *l, *r, *dl, *d, *rd;
};

class TicTacToe
{
	private:
		Node *head, *cursor;
		char curPlayer, winner;
	public:
		TicTacToe();
		Node* getHead();
		void display(); // remove parameter curHead
		bool move(char direction);
		bool setNode(char player);
		char getWinner();
		char getWinner(char player); // helper method
};

/*
	topLeft 	top 	topRight
	left 		mid 	right
	botLeft 	bot 	botRight
*/
