#include "raylib.h"
#include <vector>
#include <cstdlib>
#include <ctime>

// Tamanho do labirinto
const int MAZE_WIDTH = 20;
const int MAZE_HEIGHT = 15;
const int TILE_SIZE = 40;

// Definição da posição da saída
const int EXIT_TILE_X = MAZE_WIDTH - 2;
const int EXIT_TILE_Y = MAZE_HEIGHT - 2;
const Vector2 exitPosition = { EXIT_TILE_X * TILE_SIZE, EXIT_TILE_Y * TILE_SIZE };

class Player {
public:
    int tileX;
    int tileY;
    Color color;

    Player() {
        tileX = 1;
        tileY = 1;
        color = YELLOW;
    }

    void Update(const std::vector<std::vector<int>>& maze) {
        if (IsKeyPressed(KEY_UP) && maze[tileY - 1][tileX] == 0) tileY--;
        if (IsKeyPressed(KEY_DOWN) && maze[tileY + 1][tileX] == 0) tileY++;
        if (IsKeyPressed(KEY_LEFT) && maze[tileY][tileX - 1] == 0) tileX--;
        if (IsKeyPressed(KEY_RIGHT) && maze[tileY][tileX + 1] == 0) tileX++;
    }

    Vector2 GetPixelPosition() const {
        return {
            tileX * TILE_SIZE + TILE_SIZE / 2.0f,
            tileY * TILE_SIZE + TILE_SIZE / 2.0f
        };
    }

    void Draw() {
        DrawCircleV(GetPixelPosition(), TILE_SIZE / 2, color);
    }
};

class Maze {
public:
    std::vector<std::vector<int>> grid;

    Maze() {
        grid.resize(MAZE_HEIGHT, std::vector<int>(MAZE_WIDTH, 1));
        GenerateMaze();
    }

    void GenerateMaze() {
        for (int y = 1; y < MAZE_HEIGHT - 1; y++) {
            for (int x = 1; x < MAZE_WIDTH - 1; x++) {
                grid[y][x] = 0;
            }
        }
    }

    void Draw(const Player& player) {
        for (int y = 0; y < MAZE_HEIGHT; y++) {
            for (int x = 0; x < MAZE_WIDTH; x++) {
                if (grid[y][x] == 1) {
                    DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, DARKGRAY);
                } else {
                    if (abs(player.tileX - x) <= 1 && abs(player.tileY - y) <= 1) {
                        DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, LIGHTGRAY);
                    }
                }
            }
        }
    }
};

class Game {
public:
    Player player;
    Maze maze;
    float timer;
    bool gameOver;
    bool venceu;
    int difficulty;

    Game() : timer(60.0f), gameOver(false), venceu(false), difficulty(1) {}

    void SetDifficulty(int difficultyChoice) {
        difficulty = difficultyChoice;
        if (difficulty == 1) timer = 120.0f; // Fácil
        if (difficulty == 2) timer = 60.0f;  // Médio
        if (difficulty == 3) timer = 45.0f;  // Difícil
    }

    void Update() {
        if (gameOver) return;

        player.Update(maze.grid);
        timer -= GetFrameTime();

        if (timer <= 0) {
            gameOver = true;
        }

        if (!venceu && CheckVictory()) {
            venceu = true;
            gameOver = true;
        }
    }

    bool CheckVictory() {
        return (player.tileX == EXIT_TILE_X && player.tileY == EXIT_TILE_Y);
    }

    void Draw() {
        maze.Draw(player);
        player.Draw();

        if (abs(player.tileX - EXIT_TILE_X) <= 2 && abs(player.tileY - EXIT_TILE_Y) <= 2) {
            DrawRectangle(EXIT_TILE_X * TILE_SIZE, EXIT_TILE_Y * TILE_SIZE, TILE_SIZE, TILE_SIZE, GOLD);
        }

        DrawText(TextFormat("Tempo: %.2f", timer), 10, 10, 20, DARKBLUE);

        if (gameOver) {
            if (venceu) {
                DrawText("Vitória!", 300, 250, 40, GREEN);
            } else {
                DrawText("Game Over!", 300, 250, 40, RED);
            }
        }
    }

    void DrawDifficultyMenu() {
        const int screenWidth = GetScreenWidth();
    
        const char* title = "Escolha uma Dificuldade:";
        const char* easy = "1 - Easy  ";
        const char* medium = "2 - Medium";
        const char* hard = "3 - Hard  ";
    
        int titleWidth = MeasureText(title, 40);
        int easyWidth = MeasureText(easy, 30);
        int mediumWidth = MeasureText(medium, 30);
        int hardWidth = MeasureText(hard, 30);
    
        DrawText(title, (screenWidth - titleWidth) / 2, 200, 40, WHITE);
        DrawText(easy, (screenWidth - easyWidth) / 2, 250, 30, WHITE);
        DrawText(medium, (screenWidth - mediumWidth) / 2, 300, 30, WHITE);
        DrawText(hard, (screenWidth - hardWidth) / 2, 350, 30, WHITE);
    }
    
};

int main() {
    InitWindow(800, 600, "LightEscape");
    SetTargetFPS(60);

    Game game;
    bool inMenu = true;

    while (!WindowShouldClose()) {
        if (inMenu) {
            if (IsKeyPressed(KEY_ONE)) {
                game.SetDifficulty(1);
                inMenu = false;
            }
            if (IsKeyPressed(KEY_TWO)) {
                game.SetDifficulty(2);
                inMenu = false;
            }
            if (IsKeyPressed(KEY_THREE)) {
                game.SetDifficulty(3);
                inMenu = false;
            }

            BeginDrawing();
            ClearBackground(BLACK);
            game.DrawDifficultyMenu();
            EndDrawing();
        } else {
            game.Update();

            BeginDrawing();
            ClearBackground(BLACK);
            game.Draw();
            EndDrawing();
        }
    }

    CloseWindow();
    return 0;
}
