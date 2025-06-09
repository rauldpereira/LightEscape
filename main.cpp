#include "raylib.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdio>

const int MAZE_WIDTH = 25;
const int MAZE_HEIGHT = 17;
const int TILE_SIZE = 40;

class Player {
public:
    int tileX; 
    int tileY; 
    Color color;
    float moveDelay = 0.15f; // Delay entre movimentos contínuos
    float moveTimer = 0.0f;  // Timer para controlar o delay

    Player() {
        tileX = 1;
        tileY = 1;
        color = YELLOW;
    }

    // Reseta a posição do jogador para o início
    void ResetPosition() {
        tileX = 1;
        tileY = 1;
        moveTimer = 0.0f;
    }

    // Atualiza a posição do jogador conforme input e colisão com paredes
    void Update(const std::vector<std::vector<int>>& maze) {
        moveTimer -= GetFrameTime();
        
        // Movimenta para cima
        if ((IsKeyPressed(KEY_UP) || (IsKeyDown(KEY_UP) && moveTimer <= 0.0f)) && maze[tileY - 1][tileX] == 0) {
            tileY--;
            moveTimer = moveDelay;
        }
        // Movimenta para baixo
        else if ((IsKeyPressed(KEY_DOWN) || (IsKeyDown(KEY_DOWN) && moveTimer <= 0.0f)) && maze[tileY + 1][tileX] == 0) {
            tileY++;
            moveTimer = moveDelay;
        }
        // Movimenta para esquerda
        else if ((IsKeyPressed(KEY_LEFT) || (IsKeyDown(KEY_LEFT) && moveTimer <= 0.0f)) && maze[tileY][tileX - 1] == 0) {
            tileX--;
            moveTimer = moveDelay;
        }
        // Movimenta para direita
        else if ((IsKeyPressed(KEY_RIGHT) || (IsKeyDown(KEY_RIGHT) && moveTimer <= 0.0f)) && maze[tileY][tileX + 1] == 0) {
            tileX++;
            moveTimer = moveDelay;
        }
    }

    // Retorna a posição do jogador em pixels para desenhar na tela
    Vector2 GetPixelPosition() const {
        return {
            tileX * TILE_SIZE + TILE_SIZE / 2.0f,
            tileY * TILE_SIZE + TILE_SIZE / 2.0f
        };
    }

    // Desenha o jogador e sua coroa
    void Draw() {
        Vector2 pos = GetPixelPosition();
        DrawCircleV(pos, TILE_SIZE / 2, color);
    
        // Desenho da coroa 
        float crownBaseY = pos.y - TILE_SIZE / 2 + 4;
        float crownHeight = 18;
        float crownWidth = TILE_SIZE * 0.8f;
    
        // Triângulo central da coroa
        Vector2 centroTopo = {pos.x, crownBaseY - crownHeight};
        DrawTriangle(
            centroTopo,
            {pos.x - crownWidth / 3.2f, crownBaseY},
            {pos.x + crownWidth / 3.2f, crownBaseY},
            YELLOW
        );
        // Triângulo esquerdo
        Vector2 esquerdoTopo = {pos.x - crownWidth / 3.0f, crownBaseY - crownHeight / 1.4f};
        DrawTriangle(
            esquerdoTopo,
            {pos.x - crownWidth / 2.0f, crownBaseY},
            {pos.x - crownWidth / 6.0f, crownBaseY},
            YELLOW
        );
        // Triângulo direito
        Vector2 direitoTopo = {pos.x + crownWidth / 3.0f, crownBaseY - crownHeight / 1.4f};
        DrawTriangle(
            direitoTopo,
            {pos.x + crownWidth / 6.0f, crownBaseY},
            {pos.x + crownWidth / 2.0f, crownBaseY},
            YELLOW
        );
        // Bolinhas douradas nas pontas dos triângulos
        float ballRadius = 4.0f;
        DrawCircleV(centroTopo, ballRadius, GOLD);
        DrawCircleV(esquerdoTopo, ballRadius, GOLD);
        DrawCircleV(direitoTopo, ballRadius, GOLD);
    
        // Base da coroa
        DrawRectangle(pos.x - crownWidth / 2, crownBaseY, crownWidth, 4, GOLD);
    
        // Joias na base da coroa
        float dotRadius = 3.5f;
        DrawCircle(pos.x - crownWidth / 3, crownBaseY + 2, dotRadius, RED);
        DrawCircle(pos.x, crownBaseY + 2, dotRadius, PINK);
        DrawCircle(pos.x + crownWidth / 3, crownBaseY + 2, dotRadius, BLUE);
    }
};

// criação de labirintos (1 = parede, 0 = caminho)
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


// Estrutura para representar um nível
struct Level {
    std::vector<std::vector<int>> maze;
    Vector2 exit; // Posição da saída
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
        // Inicializa os níveis e as posições de saída
        levels = {
            { maze1, {11, 13} },
            { maze2, {19, 15} },
            { maze3, {20, 7} }
        };
    }

    // Define a dificuldade e ajusta o tempo
    void SetDifficulty(int difficultyChoice) {
        difficulty = difficultyChoice;
        if (difficulty == 1) timer = 120.0f;
        if (difficulty == 2) timer = 60.0f;
        if (difficulty == 3) timer = 45.0f;
    }

    // Avança para o próximo nível ou finaliza o jogo se acabou
    void NextLevel() {
        currentLevel++;
        if (currentLevel >= levels.size()) {
            venceu = true;
            gameOver = true;
        } else {
            player.ResetPosition();
        }
    }

    float tempoFinal = 0.0f; // Guarda o tempo restante ao vencer

    // Atualiza o estado do jogo
    void Update() {
        if (gameOver) return;
    
        player.Update(levels[currentLevel].maze);
        timer -= GetFrameTime();
    
        if (timer <= 0) gameOver = true;
    
        if (CheckVictory()) {
            if (currentLevel == levels.size() - 1) {
                tempoFinal = timer;
            }
            NextLevel();
        }
    }

    // Verifica se o jogador chegou na saída
    bool CheckVictory() {
        return (player.tileX == (int)levels[currentLevel].exit.x && player.tileY == (int)levels[currentLevel].exit.y);
    }

    // Desenha o labirinto, jogador, saída e HUD
    void Draw() {
        // Tela de vitória
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
        // Tela de game over
        if (gameOver) {
            const int screenWidth = GetScreenWidth();
            const char* gameOverMsg = "Game Over!";
            int fontSize = 40;
            int textWidth = MeasureText(gameOverMsg, fontSize);
            DrawText(gameOverMsg, (screenWidth - textWidth) / 2, 250, fontSize, RED);
            return;
        }

        // Desenha o labirinto
        auto& maze = levels[currentLevel].maze;
        for (int y = 0; y < MAZE_HEIGHT; y++) {
            for (int x = 0; x < MAZE_WIDTH; x++) {
                if (maze[y][x] == 1) {
                    DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, BLACK); // Parede
                } else {
                    // Só desenha o chão se estiver próximo do jogador (efeito de "luz")
                    if (abs(player.tileX - x) <= 1 && abs(player.tileY - y) <= 1)
                        DrawRectangle(x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE, LIGHTGRAY);
                }
            }
        }
    
        player.Draw(); // Desenha o jogador
    
        // Desenha a saída se estiver próxima do jogador
        Vector2 exit = levels[currentLevel].exit;
        if (abs(player.tileX - exit.x) <= 1 && abs(player.tileY - exit.y) <= 1)
            DrawRectangle(exit.x * TILE_SIZE, exit.y * TILE_SIZE, TILE_SIZE, TILE_SIZE, GOLD);
    
        // HUD do tempo
        DrawText(TextFormat("Tempo: %.2f", timer), 10, 10, 20, DARKBLUE);
    
    }

    // Desenha o menu de seleção de dificuldade
    void DrawDifficultyMenu() {
        const int screenWidth = GetScreenWidth();
        const char* msg = "Escolha uma Dificuldade:";
        int fontSize = 40;
        int textWidth = MeasureText(msg, fontSize);
        DrawText(msg, (screenWidth - textWidth) / 2, 200, fontSize, WHITE);
        DrawText("1 - Fácil", screenWidth/2 - 100, 260, 30, WHITE);
        DrawText("2 - Médio", screenWidth/2 - 100, 310, 30, WHITE);
        DrawText("3 - Difícil", screenWidth/2 - 100, 360, 30, WHITE);
    }
};

// Desenha a tela inicial do jogo
void DrawStartScreen() {
    const int screenWidth = GetScreenWidth();
    DrawText("Light", screenWidth/2 - 70, 150, 60, YELLOW);
    DrawText("Escape", screenWidth/2 - 110, 220, 60, YELLOW);
    DrawText("Pressione ENTER para começar", screenWidth/2 - 220, 320, 30, WHITE);
}

int main() {
    InitWindow(MAZE_WIDTH * TILE_SIZE, MAZE_HEIGHT * TILE_SIZE, "LightEscape");
    SetTargetFPS(60);

    Game game;
    bool showStartScreen = true;
    bool inMenu = false;

    while (!WindowShouldClose()) {
        if (showStartScreen) {
            // Tela inicial
            if (IsKeyPressed(KEY_ENTER)) {
                showStartScreen = false;
                inMenu = true;
            }
            BeginDrawing();
            ClearBackground(BLACK);
            DrawStartScreen();
            EndDrawing();
        }
        else if (inMenu) {
            // Menu de dificuldade
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
            // Jogo em andamento
            if (game.gameOver && game.venceu && IsKeyPressed(KEY_ENTER)) {
                game = Game(); // Reinicia o jogo
                showStartScreen = true;
                inMenu = false;
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