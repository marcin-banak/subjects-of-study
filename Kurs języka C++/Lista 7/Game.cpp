#include "Game.h++"

using namespace GameState;

Board::Board() {
    this->board = new char *[size];
    for (int i = 0; i < size; i++)
        this->board[i] = new char[size];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            this->board[i][j] = '.';
}

Board::~Board() {
    for (int i = 0; i < size; i++)
        delete board[i];
    delete board;
}

char **Board::GetBoard() {
    return board;
}

void Board::SetField(std::pair<int, int> coord, char player) {
    this->board[coord.first][coord.second] = player;
}

short Board::GetSize() {
    return size;
}

bool Board::isFree(int i, int j) {
    return this->board[i][j] == '.';
}

Game::Game(bool player) : board() {
    // this->board = Board();
    turn = player;
}

void Game::Start() {
    Player::Print(board);
    do
    {
        if (turn) {
            board.SetField(Player::Move(board), 'X');
            turn = false;
        }
        else {
            board.SetField(AI::Move(board), 'O');
            turn = true;
        }
        Player::Print(board);
    } while (this->isEnded() == -1);

    if (this->isEnded() == 1) {
        if (!turn)
            std::cout << "Player wins!\n";
        else
            std::cout << "Computer wins!\n";
    }
    else
        std::cout << "Game ended with a tie!\n";
}

short Game::isEnded() {
    char **aux = board.GetBoard();

    // Kolumny i rzędy.
    for (int i = 0; i < board.GetSize(); i++) {
        // printf("%c %c %c", aux[i][0], aux[i][1], aux[i][2]);
        if (aux[i][0] == aux[i][1] && aux[i][1] == aux[i][2] && aux[i][0] != '.')
            return 1;
        // printf("%c %c %c\n", aux[0][i], aux[1][i], aux[2][i]);
        if (aux[0][i] == aux[1][i] && aux[1][i] == aux[2][i] && aux[0][i] != '.')
            return 1;
    }

    // Skosy.
    if (aux[0][0] == aux[1][1] && aux[1][1] == aux[2][2] && aux[1][1] != '.')
        return 1;
    if (aux[0][2] == aux[1][1] && aux[1][1] == aux[2][0] && aux[1][1] != '.')
        return 1;

    // Czy remis.
    for (int i = 0; i < board.GetSize(); i++)
        for (int j = 0; j < board.GetSize(); j++)
            if (aux[i][j] == '.')
                return -1;
    return 0;
}

std::pair<int, int> AI::Move(GameState::Board &board) {
    // Środek.
    if (board.isFree(1, 1))
        return std::pair<int, int>{1, 1};

    // Pola po krzyżu.
    else if (board.isFree(0, 1))
        return std::pair<int, int>{0, 1};
    else if (board.isFree(1, 0))
        return std::pair<int, int>{1, 0};
    else if (board.isFree(2, 1))
        return std::pair<int, int>{2, 1};
    else if (board.isFree(1, 2))
        return std::pair<int, int>{1, 2};

    // Rogi
    else if (board.isFree(0, 0))
        return std::pair<int, int>{0, 0};
    else if (board.isFree(2, 2))
        return std::pair<int, int>{2, 2};
    else if (board.isFree(0, 2))
        return std::pair<int, int>{0, 2};
    return std::pair<int, int>{2, 0};
}

std::pair<int, int> Player::Move(GameState::Board &board) {
    char row;
    int col;
    std::cout << "Choose a field \"row column\"\n";
    std::cin >> row >> col;

    while (row < 'A' || row > 'C' || col < 0 ||col > 2 || !board.isFree(row - 'A', col)) {
        std::cout << "Invalid coordinates!\n";
        std::cin >>row >> col;
    }

    return std::pair<int, int>{row - 'A', col};
}

void Player::Print(GameState::Board &board) {
    char **aux = board.GetBoard();
    std::cout << std::flush << "Tic Tac Toe\n";
    std::cout << "Player - X : Computer - O\n\n";

    std::cout << "   0   1   2  \n";
    printf("A  %c | %c | %c \n",
           aux[0][0] == '.' ? ' ' : aux[0][0],
           aux[0][1] == '.' ? ' ' : aux[0][1],
           aux[0][2] == '.' ? ' ' : aux[0][2]);
    std::cout << "  -----------\n";

    printf("B  %c | %c | %c \n",
           aux[1][0] == '.' ? ' ' : aux[1][0],
           aux[1][1] == '.' ? ' ' : aux[1][1],
           aux[1][2] == '.' ? ' ' : aux[1][2]);
    std::cout << "  -----------\n";

    printf("C  %c | %c | %c \n",
           aux[2][0] == '.' ? ' ' : aux[2][0],
           aux[2][1] == '.' ? ' ' : aux[2][1],
           aux[2][2] == '.' ? ' ' : aux[2][2]);
}