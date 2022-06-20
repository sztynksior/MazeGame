#include "Game.h"

Game::Game(int pWidth, int pLength)
{
    this->windowWidth = pWidth;
    this->windowLength = pLength;
}

Game& Game::getInstance(int pWidth, int pLength)
{
    static Game instance(pWidth, pLength);
    return instance;
}

void Game::runGame()
{
    sf::RenderWindow window(sf::VideoMode(this->windowWidth, this->windowLength), "MazeGame");
    window.setVerticalSyncEnabled(true);
    
    std::filesystem::path pathFileTextureFlor = std::filesystem::current_path().append("MazeGameSprites\\florTexture.jpg");

    TextureMenager T1("Textures");
    T1.SetTextureMap();
    sf::Texture fg;

    SquareMaze SM1(T1.getTextureWithGivenName("SquareFloor"), T1.getTextureWithGivenName("SquareWall"), T1.getTextureWithGivenName("SquareDoor"), {0, 0}, 20, 20);

    Player p1(T1.getTextureWithGivenName("Player"), { 1 * 16, 0 });

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        p1.setingMoveDirectionOnKeyPressed();
        p1.movement();

        window.clear();
        window.draw(SM1);
        window.draw(p1);
        window.display();
    }
}
