#include "raylib.h"
#include "Ball.h"
#include "Paddle.h"
#include "Collisions.h"
#include "Text2.h"

using namespace std;

Ball ball;
Paddle paddle;
Collisions collision;

Text2* playerPointsText = nullptr;
Text2* playerLivesText = nullptr;

Text2* outComeText = nullptr;
Text2* finalPointsTexts = nullptr;

int screenWidth = 800;
int screenHeight = 450;

int playerPoints = 0;
int playerLives = 3;

int inGame = 1;

void Update() {
    if (inGame == 0) { //Menu ------------------------------------------------
        //then menu
    }
    else if (inGame == 1) { //In game ----------------------------------------

        ball.Update();
        paddle.Update();

        //Points -------------------------------------------------------------
        if (ball.GetX() < 0) {
            --playerLives;

            if (playerLives <= 0) { //Checking loss 
                inGame = 3;
            }

            ball.SetX(screenWidth / 2); //remplacer par position relative au paddle (+ centrer paddle pourquoi pas) + ajout option clicker sur espace pour renvoyer la balle
            ball.Released(0); //0 -> will stop the ball from moving around

            playerLivesText->SetText2(to_string(playerLives));
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
    else if (inGame == 2) { //End menu win------------------------------------
        //then end menu win
        outComeText->SetText2("Wow, what a victory");
    }
    else if (inGame == 3) { //End menu loss-----------------------------------
        //then end menu loss
        outComeText->SetText2("Guess you lose...");
        //finalPointsTexts->SetText2()
    }
}

void Draw() {
    BeginDrawing();

    ClearBackground(BLACK);

    switch (inGame) { //Game loop --------------------------------------------
    case 1:
        playerPointsText->Draw();
        playerLivesText->Draw();

        ball.Draw();
        paddle.Draw();

        break;
    case 2:
        outComeText->Draw();
        finalPointsTexts->Draw();

        break;
    case 3:
        outComeText->Draw();
        finalPointsTexts->Draw();

        break;
    default:
        break;
    }

    EndDrawing();
}

int main(int argc, char* argv[])
{

    InitWindow(screenWidth, screenHeight, "PongToBB");
    SetTargetFPS(60);

    //Assets -------------------------------------------------------------
    ball = Ball(100, 100, 32, 32, 5, false);
    paddle = Paddle(10, 180, 32, 128, 5);
    //--------------------------------------------------------------------

    //Texts --------------------------------------------------------------
    playerPointsText = new Text2(100, 100, to_string(playerPoints), 20, LIGHTGRAY);
    playerLivesText = new Text2(screenWidth - 100, 100, to_string(playerLives), 20, LIGHTGRAY);

    outComeText = new Text2(100, screenHeight / 3, "", 40, LIGHTGRAY);
    finalPointsTexts = new Text2(150, screenHeight / 2, "Score: " + to_string(playerPoints), 20, LIGHTGRAY);
    //--------------------------------------------------------------------

    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }

    CloseWindow();

    //Delete [memory security]--------------------------------------------
    delete playerLivesText;
    delete playerPointsText;
    //--------------------------------------------------------------------

    return 0;
}