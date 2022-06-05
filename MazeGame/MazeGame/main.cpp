
#include "MazeGenerator.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

void gotoxy(int a, int b)
{
    COORD pos = { a, b };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{

    MazeGenerator maze1(50, 15, { 1, 0 });
    int cellWidth = 2; //TO DO: dodaj takie pole do klasy MazeCell

    for (int i = 0; i < maze1.getMaxMazeX(); i++)
    {
        for (int j = 0; j < maze1.getMaxMazeY(); j++)
        {
            for (int nI = 0; nI < cellWidth; nI++)
            {
                for (int nJ = 0; nJ < cellWidth; nJ++)
                {
                    if (nI == 0 and nJ == 0)
                    {
                        gotoxy(i * cellWidth + 1, j * cellWidth + 1);
                        std::cout << " ";
                    }
                    else
                    {
                        gotoxy(i * cellWidth + nI + 1, j * cellWidth + nJ + 1);
                        std::cout << "X";
                    }
                }
            }
        }
    }

    for (int i = 0; i < maze1.getMaxMazeX(); i++)
    {
        for (int j = 0; j < maze1.getMaxMazeY(); j++)
        {
            for (int p = 0; p < maze1.getAccessToCellWithGivenCoordinates({ i, j })->numberOfNeigbours(); p++)
            {
                if (maze1.getAccessToCellWithGivenCoordinates({ i, j })->getNeigbourFromVector(p) == fromWhichSide::Top)
                {
                    gotoxy(i * cellWidth + 1, j * cellWidth - 1 + 1);
                    std::cout << " ";
                }
                else if (maze1.getAccessToCellWithGivenCoordinates({ i, j })->getNeigbourFromVector(p) == fromWhichSide::Right)
                {
                    gotoxy(i * cellWidth + 1 + 1, j * cellWidth + 1);
                    std::cout << " ";
                }
                else if (maze1.getAccessToCellWithGivenCoordinates({ i, j })->getNeigbourFromVector(p) == fromWhichSide::Bottom)
                {
                    gotoxy(i * cellWidth + 1, j * cellWidth + 1 + 1);
                    std::cout << " ";
                }
                else if (maze1.getAccessToCellWithGivenCoordinates({ i, j })->getNeigbourFromVector(p) == fromWhichSide::Left)
                {
                    gotoxy(i * cellWidth - 1 + 1, j * cellWidth + 1);
                    std::cout << " ";
                }
            }
        }
    }

    for (int i = 0; i <= maze1.getMaxMazeX() * cellWidth; i++)
    {
        for (int j = 0; j <= maze1.getMaxMazeY() * cellWidth; j++)
        {
            if (i == 0 or j == 0 or i == maze1.getMaxMazeX())
            {
                gotoxy(i, j);
                std::cout << "X";
            }
        }
    }

    gotoxy(1, 0);
    std::cout << "@";

    gotoxy(maze1.getMaxMazeX() * cellWidth - 1, maze1.getMaxMazeY() * cellWidth);
    std::cout << "@X";
}

//sfml-audio.lib;sfml-graphics.lib;sfml-window.lib;sfml-system.lib;