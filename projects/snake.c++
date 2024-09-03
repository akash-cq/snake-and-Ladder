#include <iostream>
#include <ctime>
#include <conio.h>
#include <unistd.h>
using namespace std;
int i = 90000;
class Snake
{

    // data members
    int height, breadth, fruitX, fruitY, snakeX, snakeY, score, level, length, l, fx, fy, move, isEat, count;
    int xTail[100], yTail[100], obsX[5], obsY[10];
    char ab;

public:
    int gameOver, maxScore;
    // constructor initilised the values of data members
    Snake(int h, int b)
    {
        gameOver = 1;
        height = h;
        breadth = b;
        snakeX = height / 2;
        snakeY = breadth / 2;
        level = 0;
        score = 0;
        xTail[0] = snakeX;
        yTail[0] = snakeY;
        length = 1;
        l = 5;
        fx = 5;
        fy = 8;
        isEat = 0;
        maxScore = 0;
    }

    // decide what moves computer Snake take
    void AnotherSmove()
    {
        move = rand() % 4;
        srand(time(0));
    }

    // move the snake according to anotherSmove fxn
    void AnotherS()
    {
        AnotherSmove();
        switch (move)
        {
        case 0: // up
            fx--;
            break;
        case 1: // left
            fy--;
            break;
        case 2: // downs
            fx++;
            break;
        case 3: // right
            fy++;
            break;
        }
        if (fx == height)
            fx--;
        else if (fy == breadth)
            fy--;
        else if (fy == 0)
            fy++;
        else if (fx == 0)
            fx++;
        // if user head eat cmputer snake than give +30 score
        if (fx == snakeX && fy == snakeY && level > 1)
        {
            score += 30;
            isEat = 0;
            count = 0;
        }
    }

    // initilised obstacle place
    void Obstacle()
    {
        obsX[0] = rand() % (height - 5) + 1;
        srand(time(0));
        obsY[0] = rand() % (breadth - 5) + 1;
        srand(time(0));

        for (int i = 1; i < l; i++)
        {
            obsY[i] = obsY[0] + i;
        }
    }

    // this function increase the length
    void SnakeIncrease()
    {
        for (int i = length - 1; i > 0; i--)
        {
            xTail[i] = xTail[i - 1];
            yTail[i] = yTail[i - 1];
        }
        xTail[0] = snakeX;
        yTail[0] = snakeY;
    }

    // check snake bite itslef or not?
    void SelfCollison()
    {
        for (int i = 1; i < length; i++)
        {
            if (snakeX == xTail[i] && snakeY == yTail[i])
            {
                cout << endl
                     << "snake bit itself " << endl;
                cout << "game over!";
                gameOver = 0;
            }
            // check computer is not eat user snake
            if (fx == xTail[i] && fy == yTail[i] && level > 1)
            {
                cout << endl
                     << "your snake is eat by another snake!" << endl;
                gameOver = 0;
            }
        }
        // check user snake not touch to obstacle
        for (int k = 0; k < l; k++)
        {
            if (obsX[0] == snakeX && obsY[k] == snakeY)
            {
                cout << endl
                     << "game over becouse you touch inner wall! " << endl;
                gameOver = 0;
            }
        }
    }

    // upgrade the diffculty by cheking boundries according to level
    void Boundry()
    {
        if (level == 0) // if level 0 then no boundry collison
        {
            if (snakeX == height)
                snakeX = 1;
            else if (snakeY == breadth)
                snakeY = 1;
            else if (snakeY == 0)
                snakeY = height - 1;
            else if (snakeX == 0)
                snakeX = breadth - 1;
        }
        else
        {
            if ((snakeY == breadth || snakeX == height || snakeY == 0 || snakeX == 0))
                gameOver = 0;
        }
    }

    // generate the fruits
    int SetFruit()
    {
        fruitX = rand() % (height - 1) + 1;
        srand(time(0));
        fruitY = rand() % (breadth - 1) + 1;
        srand(time(0));

        for (int i = 0; i < l; i++)
        {
            if (fruitX == obsX[0] && fruitY == obsY[i])
            {
                return 0;
            }
        }
        return 1;
    }
    // print congratulation msg  with warnings to user after reaching next level
    void Cong()
    {
        system("cls");
        cout << "<<<<<<<<<<<<  congratulation you reach level: " << level << "   <<<<<<<<<<<<<<<<<" << endl;
        cout << "speed is increased and you can't touch the boundries:\n";
        cout << "self-collison is start\n";
        if (level > 1)
            cout << "A snake is come and try to eat you from now and you can also eat him \n";
        cout << "obstacle is increase\n";
        cout << "all the best!" << endl;
        usleep(1500000);
    }

    // draw the pattern
    void Draw()
    {
        int k = 0;
        cout << "level- " << level << endl;
        cout << "Score: " << score << endl;
        for (int i = 0; i <= height; i++)
        {

            for (int j = 0; j <= breadth; j++)
            {

                if (i == 0 || i == height || j == 0 || j == breadth)
                    cout << "# "; // boundries
                else
                {
                    int flag = 0, s1 = 0, fl = 0;
                    if (i == xTail[0] && j == yTail[0])
                    {
                        cout << "@ "; // head of snake
                        flag = 1;
                    }
                    for (k = 1; k < length && level > 0; k++)
                    {
                        if (i == xTail[k] && j == yTail[k])
                        {
                            cout << "O "; // snake tail
                            flag = 1;
                        }
                    }
                    // print obstacle
                    for (k = 0; k < l; k++)
                    {
                        if (obsX[0] == i && obsY[k] == j)
                        {
                            cout << "# ";
                            fl = 1;
                        }
                    }
                    if (i == fx && j == fy && isEat == 1)
                    {
                        cout << "$ "; // print computer snake
                        s1 = 1;
                    }
                    if (i == fruitX && j == fruitY)
                    {
                        cout << "* "; // fruit
                    }
                    else if (flag == 0 && fl == 0 && s1 == 0)
                        cout << "  ";
                }
            }
            cout << endl;
        }
    }
    // move the snake
    void Run()
    {

        if (_kbhit())
        {
            if (isEat == 0 && level > 1)
            {
                count++;
            }
            ab = _getch();
        }
        switch (ab)
        {
        case 'w': // up
            snakeX--;
            break;
        case 'a': // left
            snakeY--;
            break;
        case 's': // downs
            snakeX++;
            break;
        case 'd': // right
            snakeY++;
            break;
        }
        AnotherS();     // computer snake movement
        SelfCollison(); // fxn call to check snake bit itself or not
        FoodCheck();    // check snake eat food or not
        Boundry();
        if (level > 0) // if level is not 0 then snake increase fxn call
        {

            SnakeIncrease();
        }
        else
        {
            xTail[0] = snakeX;
            yTail[0] = snakeY;
        }

        if (count == 10) // to genrate enemy after few time if he is eaten by user
        {
            isEat = 1;
        }
    }

    // snake eat food or not and also increment the score as well as levels
    void FoodCheck()
    {
        if (snakeX == fruitX && snakeY == fruitY)
        {
            if (score == 5)
            { // level 0 is completed
                level = 1;
                Cong();
                i = 70000;
                snakeX = height / 2;
                snakeY = breadth / 2;
                xTail[0] = snakeX;
                yTail[0] = snakeY;
                l += 2;
                Obstacle();
            }
            else if (score == 60)
            { // level 1 is completed
                level = 2;
                Cong();
                i = 60000;
                snakeX = height / 2;
                snakeY = breadth / 2;
                xTail[0] = snakeX;
                yTail[0] = snakeY;
                fx = 9;
                fy = 3;
                l += 3;
                length = 0;
                isEat = 1;
                count = 0;
            }
            if (level == 0)
                score++;
            else if (level == 1)
            {
                score += 5;
            }
            else if (level == 2)
            {

                score += 10;
            }
            if (score > 5)
                length++;
            int flag = SetFruit();
            if (flag == 0)
                flag = SetFruit();
        }
    }
    // code is start from scratch
    void Again(int h, int b)
    {
        gameOver = 1;
        height = h;
        breadth = b;
        snakeX = height / 2;
        snakeY = breadth / 2;
        level = 0;
        score = 0;
        xTail[0] = snakeX;
        yTail[0] = snakeY;
        length = 1;
        i = 90000;
        l = 5;
        for (int i = 1; i < 100; i++)
        {
            yTail[i] = -1;
            xTail[i] = -1;
        }
        fx = 5;
        fy = 8;
        isEat = 0;
        count = 0;
        Obstacle();
        SetFruit();
    }

    void Want()
    {
        // check game is over then user want to play again or not
        char yesNo;
        if (gameOver == 0)
        {
            if (maxScore < score)
                maxScore = score;
            cout << "Do you want play again if yes eneter Y/y otherwise N/n:\n";
            cin >> yesNo;
            switch (yesNo)
            {
            case 'y':
            case 'Y':
                Again(20, 20);
                break;
            case 'n':
            case 'N':
                gameOver = 0;
                break;
            default:
                cout << "no commned found for this\n";
            }
        }
    }
};

int main()
{

    cout << "Rules for Game:" << endl;
    cout << "1. you can touch the boundry if level is 0 " << endl;
    cout << "2. you can cross the boundry and you'r snake come from another direction if level 0." << endl;
    cout << "1. Don't touch the boundry and snake body otherwise game is over  if level is 1 and level 2. " << endl;
    cout << "4. After level increase speed of snake is also increase.\n";
    cout << "5. score is increase by 1 if level is 0 in level 2 score is increment by +5 and in level 2 score is increment by +10.\n";
    cout << "6. you face many obstacle during game from level 0.\n";
    usleep(3000000);

    Snake start(20, 20);

    char yesNo;
    int flag = start.SetFruit();
    if (flag == 0)
        flag = start.SetFruit();
    start.Obstacle();
    while (start.gameOver)
    {
        system("cls");
        start.Draw();
        start.Run();
        start.Want();
        usleep(i);
    }
    system("cls");
    cout << "Your higest Score is = " << start.maxScore;
    //            |=> this can give error first times due to space so fix it according to it
    cout << endl
         << "thankyou for playing!";
}
