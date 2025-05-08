
#include "raylib.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdio>

// Tamanho do labirinto
const int MAZE_WIDTH = 25;
const int MAZE_HEIGHT = 17;
const int TILE_SIZE = 40;

class Player {
public:
    int tileX;
    int tileY;
    Color color;
    float moveDelay = 0.15f;
    float moveTimer = 0.0f;

    Player() {
        tileX = 1;
        tileY = 1;
        color = YELLOW;
    }

    void ResetPosition() {
        tileX = 1;
        tileY = 1;
        moveTimer = 0.0f;
    }

    void Update(const std::vector<std::vector<int>>& maze) {
        moveTimer -= GetFrameTime();
        
        if ((IsKeyPressed(KEY_UP) || (IsKeyDown(KEY_UP) && moveTimer <= 0.0f)) && maze[tileY - 1][tileX] == 0) {
            tileY--;
            moveTimer = moveDelay;
        }
        else if ((IsKeyPressed(KEY_DOWN) || (IsKeyDown(KEY_DOWN) && moveTimer <= 0.0f)) && maze[tileY + 1][tileX] == 0) {
            tileY++;
            moveTimer = moveDelay;
        }
        else if ((IsKeyPressed(KEY_LEFT) || (IsKeyDown(KEY_LEFT) && moveTimer <= 0.0f)) && maze[tileY][tileX - 1] == 0) {
            tileX--;
            moveTimer = moveDelay;
        }
        else if ((IsKeyPressed(KEY_RIGHT) || (IsKeyDown(KEY_RIGHT) && moveTimer <= 0.0f)) && maze[tileY][tileX + 1] == 0) {
            tileX++;
            moveTimer = moveDelay;
        }
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

std::vector<std::vector<int>> maze2 = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,1},
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
            { maze1, {11, 13} },
            { maze2, {19, 15} },
            { maze3, {20, 7} }
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

    float tempoFinal = 0.0f;

    void Update() {
        if (gameOver) return;
    
        player.Update(levels[currentLevel].maze);
        timer -= GetFrameTime();
    
        if (timer <= 0) gameOver = true;
    
        if (CheckVictory()) {
            if (currentLevel == levels.size() - 1) {
                tempoFinal = timer; // Salva o tempo restante ao vencer a última fase
            }
            NextLevel();
        }
    }

    bool CheckVictory() {
        return (player.tileX == (int)levels[currentLevel].exit.x && player.tileY == (int)levels[currentLevel].exit.y);
    }

    void Draw() {
        if (gameOver && venceu) {
            const int screenWidth = GetScreenWidth();

            const char* vitoriaMsg = "Vitória!";
            int vitoriaFontSize = 40;
            int vitoriaWidth = MeasureText(vitoriaMsg, vitoriaFontSize);
            DrawText(vitoriaMsg, (screenWidth - vitoriaWidth) / 2, 180, vitoriaFontSize, GREEN);
    
            char tempoMsg[64];
            snprintf(tempoMsg, sizeof(tempoMsg), "Tempo restante: %.2f segundos", tempoFinal);
            int tempoFontSize = 30;
            int tempoWidth = MeasureText(tempoMsg, tempoFontSize);
            DrawText(tempoMsg, (screenWidth - tempoWidth) / 2, 240, tempoFontSize, YELLOW);
    
            const char* instrucaoMsg = "Pressione ENTER para voltar ao menu";
            int instrucaoFontSize = 30;
            int instrucaoWidth = MeasureText(instrucaoMsg, instrucaoFontSize);
            DrawText(instrucaoMsg, (screenWidth - instrucaoWidth) / 2, 300, instrucaoFontSize, WHITE);
    
            return;
        }
        if (gameOver) {
            const int screenWidth = GetScreenWidth();
            const char* gameOverMsg = "Game Over!";
            int fontSize = 40;
            int textWidth = MeasureText(gameOverMsg, fontSize);
            DrawText(gameOverMsg, (screenWidth - textWidth) / 2, 250, fontSize, RED);
            return;
        }

        auto& maze = levels[currentLevel].maze;
        for (int y = 0; y < MAZE_HEIGHT; y++) {
            for (int x = 0; x < MAZE_WIDTH; x++) {
                if (maze[y][x] == 1) {
                    DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLACK);
                } else {
                    if (abs(player.tileX - x) <= 1 && abs(player.tileY - y) <= 1)
                        DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, LIGHTGRAY);
                }
            }
        }
    
        player.Draw();
    
        Vector2 exit = levels[currentLevel].exit;
        if (abs(player.tileX - exit.x) <= 1 && abs(player.tileY - exit.y) <= 1)
            DrawRectangle(exit.x * TILE_SIZE, exit.y * TILE_SIZE, TILE_SIZE, TILE_SIZE, GOLD);
    
        DrawText(TextFormat("Tempo: %.2f", timer), 10, 10, 20, DARKBLUE);
    
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
            if (game.gameOver && game.venceu && IsKeyPressed(KEY_ENTER)) {
                game = Game();
                inMenu = true;
            } else {
                game.Update();
            }

            BeginDrawing();
            ClearBackground(BLACK);
            game.Draw();
            EndDrawing();
        }
    }

    CloseWindow();
    return 0;
}