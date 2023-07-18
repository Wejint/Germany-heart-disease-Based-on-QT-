#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

// 水果类型 我这边用enum声明了b，s，c，l四种水果
enum class FruitType {
    Banana,
    Strawberry,
    Cherry,
    Lemon
};

// 牌  
class Card {
public:
    Card(FruitType fruit, int count) : fruit(fruit), count(count) {}
    FruitType getFruit() const { return fruit; }
    int getCount() const { return count; }
private:
    FruitType fruit;
    int count;
};

// 玩家
class Player {
public:
    Player() : score(0) {}
    void addCard(const Card& card) { cards.push_back(card); }
    void addScore(int points) { score += points; }
    int getScore() const { return score; }
    bool hasCards() const { return !cards.empty(); }
    void printCards() const {
        cout << "Player's cards: ";
        for (const auto& card : cards) {
            cout << "(" << static_cast<int>(card.getFruit()) << ", " << card.getCount() << ") ";
        }
        cout << endl;
    }
    bool operator<(const Player& other) const {
        return cards.size() < other.cards.size();
    }
private:
    vector<Card> cards;
    int score;
};

// 游戏
class Game {
public:
    Game() {
        // 初始化牌堆
        for (int i = 0; i < 5; i++) {
            deck.push_back(Card(FruitType::Banana, 5));
        }
        for (int i = 0; i < 3; i++) {
            deck.push_back(Card(FruitType::Strawberry, 3));
            deck.push_back(Card(FruitType::Cherry, 3));
        }
        deck.push_back(Card(FruitType::Lemon, 2));
        deck.push_back(Card(FruitType::Lemon, 2));
        deck.push_back(Card(FruitType::Lemon, 1));
        // 洗牌
        srand(time(nullptr));
        random_shuffle(deck.begin(), deck.end());
        // 初始化玩家
        for (int i = 0; i < 4; i++) {
            players.push_back(Player());
        }
        // 发牌
        for (int i = 0; i < 56; i++) {
            players[i % 4].addCard(deck[i]);
        }
        // 初始化出牌堆
        for (int i = 0; i < 4; i++) {
            openCards.push_back(players[i].hasCards() ? players[i].cards.back() : Card(FruitType::Banana, 0));
        }
    }
    void start() {
        while (true) {
            // 打印出牌堆
            printOpenCards();
            // 依次出牌
            for (int i = 0; i < 4; i++) {
                // 玩家已经出局
                if (!players[i].hasCards()) {
                    continue;
                }
                // 玩家出牌
                cout << "Player " << i << " turn: ";
                players[i].printCards();
                Card card = players[i].cards.back();
                players[i].cards.pop_back();
                openCards[i] = card;
                // 判断是否按铃铛
                if (isRingBell()) {
                    cout << "Player " << i << " rings the bell!" << endl;
                    // 判断是否正确
                    if (isValid()) {
                        cout << "Correct! Player " << i << " gets the cards." << endl;
                        players[i].addScore(1);
                        for (auto& card : openCards) {
                            players[i].addCard(card);
                        }
                        openCards.clear();
                        // 重新洗牌
                        random_shuffle(deck.begin(), deck.end());
                        for (auto& player : players) {
                            random_shuffle(player.cards.begin(), player.cards.end());
                        }
                        // 初始化出牌堆
                        for (int j = 0; j < 4; j++) {
                            openCards.push_back(players[j].hasCards() ? players[j].cards.back() : Card(FruitType::Banana, 0));
                        }
                    }
                    else {
                        cout << "Wrong! Player " << i << " gives cards to others." << endl;
                        for (int j = 0; j < 4; j++) {
                            if (j != i && players[j].hasCards()) {
                                players[j].addCard(deck.back());
                                deck.pop_back();
                            }
                        }
                    }
                    // 重新开始出牌
                    i = -1;
                    // 等待一段时间
                    this_thread::sleep_for(chrono::seconds(1));
                }
            }
            // 判断是否结束
            if (isGameOver()) {
                break;
            }
        }
        // 打印分数
        for (int i = 0; i < 4; i++) {
            cout << "Player " << i << " score: " << players[i].getScore() << endl;
        }
        // 打印胜利者
        auto winner = max_element(players.begin(), players.end());
        cout << "Player " << distance(players.begin(), winner) << " wins!" << endl;
    }
private:
    vector<Card> deck; // 牌堆
    vector<Player> players; // 玩家
    vector<Card> openCards; // 出牌堆
    bool isRingBell() const {
        int sum = 0;
        for (const auto& card : openCards) {
            sum += card.getCount() * static_cast<int>(card.getFruit()) + 1;
        }
        return sum % 5 == 0;
    }
    bool isValid() const {
        int sum = 0;
        for (const auto& card : openCards) {
            sum += card.getCount() * static_cast<int>(card.getFruit()) + 1;
        }
        return sum % 5 == 0 && openCards.back().getCount() == 1;
    }
    bool isGameOver() const {
        int count = 0;
        for (const auto& player : players) {
            if (!player.hasCards()) {
                count++;
            }
        }
        return count >= 3;
    }
    void printOpenCards() const {
        cout << "Open cards: ";
        for (const auto& card : openCards) {
            cout << "(" << static_cast<int>(card.getFruit()) << ", " << card.getCount() << ") ";
        }
        cout << endl;
    }
};

int main() {
    Game game;
    game.start();
    return 0;
}