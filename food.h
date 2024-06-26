#include <graphics.h>
#include <ctime>

class food
{
private:
        POS foodPos;
public :
        void draw();
        void generate(int, int);
        bool update(int, int);
};
void food::draw()
{
     setcolor(RED);
     rectangle(foodPos.x, foodPos.y, foodPos.x+30, foodPos.y+30);
     setfillstyle(INTERLEAVE_FILL, RED);
     floodfill(foodPos.x+15, foodPos.y+15, RED);
}

void food::generate(int snakeHeadx, int snakeHeady)
{
     srand(time(0));
     foodPos.x = 30*(rand()%15 + 1);
     srand(time(0));
     foodPos.y = 30*(rand()%15 + 1);
     if (foodPos.x == snakeHeadx && foodPos.y == snakeHeady)
          generate(snakeHeadx, snakeHeady);
}

bool food::update(int snakeHeadx, int snakeHeady) 
{
     if (foodPos.x == snakeHeadx && foodPos.y == snakeHeady)
          return true;
     else
          return false;
}
