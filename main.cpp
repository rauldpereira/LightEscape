
#include "raylib.h"
#include <vector>
#include <cstdlib>
#include <ctime>

// Tamanho do labirinto
const int MAZE_WIDTH = 25;
const int MAZE_HEIGHT = 17;
const int TILE_SIZE = 40;

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

    void ResetPosition() {
        tileX = 1;
        tileY = 1;
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

std::vector<std::vector<int>> maze1 = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1},
    {1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1},
    {1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1},
    {1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1},
    {1,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1},
    {1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1},
    {1,0,1,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,1},
    {1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1},
    {1,1,1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1},
    {1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1},
    {1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,1},
    {1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

std::vector<std::vector<int>> maze2 = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
    {1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
    {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1},
    {1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1},
    {1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1},
    {1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
    {1,1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1},
    {1,0,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1},
    {1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

std::vector<std::vector<int>> maze3 = {
    {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
    {1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

struct Level {
    std::vector<std::vector<int>> maze;
    Vector2 exit;
};

class Game {
public:
    Player player;
    float timer;
    bool gameOver;
    bool venceu;
    int difficulty;
    int currentLevel;
    std::vector<Level> levels;

    Game() : timer(60.0f), gameOver(false), venceu(false), difficulty(1), currentLevel(0) {
        levels = {
            { maze1, {23, 1} },
            { maze2, {23, 8} },
            { maze3, {1, 1} }
        };
    }

    void SetDifficulty(int difficultyChoice) {
        difficulty = difficultyChoice;
        if (difficulty == 1) timer = 120.0f;
        if (difficulty == 2) timer = 60.0f;
        if (difficulty == 3) timer = 45.0f;
    }

    void NextLevel() {
        currentLevel++;
        if (currentLevel >= levels.size()) {
            venceu = true;
            gameOver = true;
        } else {
            player.ResetPosition();
        }
    }

    void Update() {
        if (gameOver) return;

        player.Update(levels[currentLevel].maze);
        timer -= GetFrameTime();

        if (timer <= 0) gameOver = true;

        if (CheckVictory()) NextLevel();
    }

    bool CheckVictory() {
        return (player.tileX == (int)levels[currentLevel].exit.x && player.tileY == (int)levels[currentLevel].exit.y);
    }

    void Draw() {
        auto& maze = levels[currentLevel].maze;
        for (int y = 0; y < MAZE_HEIGHT; y++) {
            for (int x = 0; x < MAZE_WIDTH; x++) {
                if (maze[y][x] == 1) {
                    DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, DARKGRAY);
                } else {
                    if (abs(player.tileX - x) <= 1 && abs(player.tileY - y) <= 1)
                        DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, LIGHTGRAY);
                }
            }
        }

        player.Draw();

        Vector2 exit = levels[currentLevel].exit;
        if (abs(player.tileX - exit.x) <= 2 && abs(player.tileY - exit.y) <= 2)
            DrawRectangle(exit.x * TILE_SIZE, exit.y * TILE_SIZE, TILE_SIZE, TILE_SIZE, GOLD);

        DrawText(TextFormat("Tempo: %.2f", timer), 10, 10, 20, DARKBLUE);

        if (gameOver) {
            DrawText(venceu ? "Vitória!" : "Game Over!", 300, 250, 40, venceu ? GREEN : RED);
        }
    }

    void DrawDifficultyMenu() {
        const int screenWidth = GetScreenWidth();
        DrawText("Escolha uma Dificuldade:", screenWidth/2 - 200, 200, 40, WHITE);
        DrawText("1 - Fácil", screenWidth/2 - 100, 260, 30, WHITE);
        DrawText("2 - Médio", screenWidth/2 - 100, 310, 30, WHITE);
        DrawText("3 - Difícil", screenWidth/2 - 100, 360, 30, WHITE);
    }
};

int main() {
    InitWindow(MAZE_WIDTH * TILE_SIZE, MAZE_HEIGHT * TILE_SIZE, "LightEscape");
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
