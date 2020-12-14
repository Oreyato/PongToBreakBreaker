#include "raylib.h"
#include "Ball.h"
#include "Paddle.h"
#include "Collisions.h"
#include "Text2.h"

using namespace std;

Ball ball;
Paddle paddle;
Collisions collision;

int screenWidth = 800;
int screenHeight = 450;

int playerPoints = 0;
int playerLives = 3;

Text2 playerPointsText = Text2(100, 100, to_string(playerPoints), 20, LIGHTGRAY);
Text2 playerLivesText = Text2(screenWidth - 100, 100, to_string(playerLives), 20, LIGHTGRAY);

void Update() {
    ball.Update();
    paddle.Update();

    //Points -------------------------------------------------------------
    if (ball.GetX() < 0) {
        --playerLives;
        ball.SetX(screenWidth / 2); //remplacer par position relative au paddle (+ centrer paddle pourquoi pas) + ajout option clicker sur espace pour renvoyer la balle
        playerLivesText.SetText2(to_string(playerLives));
    }
    //--------------------------------------------------------------------

    //Collisions ---------------------------------------------------------
    RectangleAABB ballRect = ball.GetRect();
    RectangleAABB paddleRect = paddle.GetRect();

    bool colliding = collision.AABBCollision(ballRect, paddleRect);

    if (colliding) {
        ball.HorizontalBounce(paddleRect.x + paddleRect.width);
    }
    //--------------------------------------------------------------------
}

void Draw() {
    BeginDrawing();

    ClearBackground(BLACK);

    playerPointsText.Draw();
    playerLivesText.Draw();

    ball.Draw();
    paddle.Draw();

    EndDrawing();
}

int main(int argc, char* argv[])
{

    InitWindow(screenWidth, screenHeight, "PongToBB");
    SetTargetFPS(60);

    ball = Ball(100, 100, 32, 32, 5);
    paddle = Paddle(10, 180, 32, 128, 5);

    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }

    CloseWindow();

    return 0;
}