#include <iostream>
#include <vector>

void getAvailableMoves(std::vector<std::vector<int>>& moves, std::pair<int, int> position, char pieceType) {
    int row = position.first;
    int col = position.second;

    switch (pieceType) {
        case 'R': // Rook (ладья)
            for (int i = row - 1; i >= 0; --i) {
                moves[i][col] = 1;
                if (moves[i][col] == 1) break;
            }
            for (int i = row + 1; i < 8; ++i) {
                moves[i][col] = 1;
                if (moves[i][col] == 1) break;
            }
            for (int j = col - 1; j >= 0; --j) {
                moves[row][j] = 1;
                if (moves[row][j] == 1) break;
            }
            for (int j = col + 1; j < 8; ++j) {
                moves[row][j] = 1;
                if (moves[row][j] == 1) break;
            }
            break;
        case 'P': // Pawn (пешка)
            if (row > 0) {
                if (col > 0 && moves[row - 1][col - 1] == 0) moves[row - 1][col - 1] = 1;
                if (col < 7 && moves[row - 1][col + 1] == 0) moves[row - 1][col + 1] = 1;
            }
            break;
        case 'B': // Bishop (слон)
            for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
                moves[i][j] = 1;
                if (moves[i][j] == 1) break;
            }
            for (int i = row - 1, j = col + 1; i >= 0 && j < 8; --i, ++j) {
                moves[i][j] = 1;
                if (moves[i][j] == 1) break;
            }
            for (int i = row + 1, j = col - 1; i < 8 && j >= 0; ++i, --j) {
                moves[i][j] = 1;
                if (moves[i][j] == 1) break;
            }
            for (int i = row + 1, j = col + 1; i < 8 && j < 8; ++i, ++j) {
                moves[i][j] = 1;
                if (moves[i][j] == 1) break;
            }
            break;
        case 'Q': // Queen (ферзь)
            // Same logic as Rook and Bishop combined
            break;
        case 'K': // King (король)
            // Check all 8 possible moves around the king
            break;
        case 'N': // Knight (конь)
            // Check all 8 possible moves of the knight
            break;
    }
}

int main() {
    std::vector<std::vector<int>> moves(8, std::vector<int>(8, 0));
    std::pair<int, int> position(1, 0); // Example position (1, 0)
    char pieceType = 'R'; // Example piece type 'R' (Rook)

    getAvailableMoves(moves, position, pieceType);

    // Print the available moves
    for (const auto& row : moves) {
        for (int move : row) {
            std::cout << move << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
