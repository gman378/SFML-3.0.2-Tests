#include <SFML/Graphics.hpp>
#include <experimental/random>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Jogo do bloquinho- 0.1");
    window.setFramerateLimit(30); //Se aumentar o jogo quebra. NAO MEXA.

    sf::RectangleShape Object;

    Object.setFillColor(sf::Color::Blue);
    Object.setSize({100.f, 100.f});

    float x = static_cast<float> (std::experimental::randint(10, (int) (window.getSize().x - Object.getSize().x)));

    Object.setPosition({ x, 10.f});

    sf::Vector2i pos_mouse_win;
    sf::Vector2f pos_mouse_coord; //Aqui o aplicativo coordena a posiçao do mouse.

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

                pos_mouse_win = sf::Mouse::getPosition(window);
                pos_mouse_coord = window.mapPixelToCoords(pos_mouse_win);
        }

        Object.move({0.0f, 10.04f});

        if(Object.getPosition().y > 1080.f)
        {
             float x = static_cast<float> (std::experimental::randint(10, (int) (window.getSize().x - Object.getSize().x)));
            Object.setPosition({x, 10.f}); 
            
        }
        
        

        window.clear();
        window.draw(Object);
        window.display();
    }

    return EXIT_SUCCESS;
}
