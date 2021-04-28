#include <iostream>
#include "TicTacToe.h"
using namespace std;

TicTacToe::TicTacToe() {
    head = nullptr;
    cursor = nullptr;
    curPlayer = 'X';

    // Creating node for each box
    Node *topLeft = new Node();
    Node *top = new Node();
    Node *topRight = new Node();
    Node *left = new Node();
    Node *mid = new Node();
    Node *right = new Node();
    Node *botLeft = new Node();
    Node *bot = new Node();
    Node *botRight = new Node();

    // header to the topLeft node
    head = topLeft;

    //cursor to the topleft node
    cursor = head;

    // set top left Node
    topLeft->r = top;
    topLeft->rd = mid;
    topLeft->d = left;

    // set top
    top->l = topLeft;
    top->r = topRight;
    top->d = mid;
    top->dl = left;
    top->rd = right;

    // set topRight
    topRight->l = top;
    topRight->dl = mid;
    topRight->d = right;

    // set left
    left->u = topLeft;
    left->ur = top;
    left->r = mid;
    left->rd = bot;
    left->d = botLeft;

    // set right
    right->u = topRight;
    right->lu = top;
    right->l = mid;
    right->dl = bot;
    right->d = botRight;

    // set mid
    mid->lu = topLeft;
    mid->u = top;
    mid->ur = topRight;
    mid->r = right;
    mid->rd = botRight;
    mid->d = bot;
    mid->dl = botLeft;
    mid->l = left;

    // set botLeft
    botLeft->u = left;
    botLeft->ur = mid;
    botLeft->r = bot;

    // set bot
    bot->l = botLeft;
    bot->lu = left;
    bot->u = mid;
    bot->ur = right;
    bot->r = botRight;

    // set botRight
    botRight->l = bot;
    botRight->lu = mid;
    botRight->u = right;

    display();

    bool done = false;
    while(!done) {
        char input;
        cin >> input;

        if(input == 'j') {
            setNode(curPlayer);
        }
        else {
            move(input);
        }
        display();
        if(getWinner() != 'n') {
            cout << "Winner is " + curPlayer;
            done = true;
        }
    }
}

Node* TicTacToe::getHead() { return head; }

void TicTacToe::display() {
    Node *curHead = head;

    bool done = false;
    while (!done) {
      while (curHead != nullptr) {
        if (curHead == cursor) {
          cout << ' ';
        } else {
          cout << curHead->x;
        }
        if (curHead->r == nullptr) {
            break;
        }
        curHead = curHead->r;
    }
    try {
      curHead = curHead->d->l->l;
    } catch (exception e) {
      done = true;
    }
    }

}
bool TicTacToe::move(char direction) {
    switch (direction) {
    case 'q':
        if (cursor->lu != nullptr) {
            if (cursor->lu->x == '-') {
                cursor = cursor->lu;
                return true;
            }
            else {
                cursor = cursor->lu;
                return move('q');
            }
        }
    case 'w':
        if (cursor->u != nullptr) {
            if (cursor->u->x == '-') {
                cursor = cursor->u;
                return true;
            } else {
              cursor = cursor->u;
              return move('w');
            }
        }
    case 'e':
      if (cursor->ur != nullptr) {
        if (cursor->ur->x == '-') {
          cursor = cursor->ur;
          return true;
        } else {
          cursor = cursor->ur;
          return move('e');
        }
      }
    case 'a':
      if (cursor->l != nullptr) {
        if (cursor->l->x == '-') {
          cursor = cursor->l;
          return true;
        } else {
          cursor = cursor->l;
          return move('a');
        }
      }
    case 'd':
      if (cursor->r != nullptr) {
        if (cursor->r->x == '-') {
          cursor = cursor->r;
          return true;
        } else {
          cursor = cursor->r;
          return move('d');
        }
      }
    case 'z':
      if (cursor->dl != nullptr) {
        if (cursor->dl->x == '-') {
          cursor = cursor->dl;
          return true;
        } else {
          cursor = cursor->dl;
          return move('z');
        }
      }
    case 'x':
      if (cursor->d != nullptr) {
        if (cursor->d->x == '-') {
          cursor = cursor->d;
          return true;
        } else {
          cursor = cursor->d;
          return move('x');
        }
      }
    case 'c':
      if (cursor->rd != nullptr) {
        if (cursor->rd->x == '-') {
          cursor = cursor->rd;
          return true;
        } else {
          cursor = cursor->rd;
          return move('c');
        }
      }
    return false;
    }
}
bool TicTacToe::setNode(char player) {
  try {
    cursor->x = player;
    if (!move('d'))
      if (!move('x'))
        if (!move('a'))
          if (!move('w'))
            if (!move('q'))
              if (!move('e'))
                if (!move('c'))
                  if (!move('z'))
                    ;

    if (curPlayer == 'x')
      curPlayer = 'o';
    else
      curPlayer = 'x';
    return true;
  } catch (exception e) {
    return false;
  }
}
char TicTacToe::getWinner() {
  char temp = 'n'; // no winner
  temp = getWinner('0');
  temp = getWinner('x');

  return temp;
}

char TicTacToe::getWinner(char player) {
    Node *current = head;
    int count;

    while (true) {
      if (current->x == player)
        count++;
      if (current->d != nullptr) {
        current = current->d;
      } else
        break;
      if (count == 3)
        return player;
    }
    // cek right
    current = head;
    count = 0;
    while (true) {
      if (current->x == player)
        count++;
      if (current->r != nullptr) {
        current = current->r;
      } else
        break;
      if (count == 3)
        return player;
    }
    // cek downright
    current = head;
    count = 0;
    while (true) {
      if (current->x == player)
        count++;
      if (current->rd != nullptr) {
        current = current->rd;
      } else
        break;
      if (count == 3)
        return player;
    }

    // cek
    current = head->r;
    count = 0;
    while (true) {
      if (current->x == player)
        count++;
      if (current->d != nullptr) {
        current = current->d;
      } else
        break;
      if (count == 3)
        return player;
    }
    // ----
    current = head->r->r;
    count = 0;
    while (true) {
      if (current->x == player)
        count++;
      if (current->d != nullptr) {
        current = current->d;
      } else
        break;
      if (count == 3)
        return player;
    }
    // ----
    current = head->d;
    count = 0;
    while (true) {
      if (current->x == player)
        count++;
      if (current->r != nullptr) {
        current = current->r;
      } else
        break;
      if (count == 3)
        return player;
    }
    // ----
    current = head->d->d;
    count = 0;
    while (true) {
      if (current->x == player)
        count++;
      if (current->r != nullptr) {
        current = current->r;
      } else
        break;
      if (count == 3)
        return player;
    }
    // ----
    current = head->d->d;
    count = 0;
    while (true) {
      if (current->x == player)
        count++;
      if (current->ur != nullptr) {
        current = current->ur;
      } else
        break;
      if (count == 3)
        return player;
    }
    // default
    return 'n';
}
