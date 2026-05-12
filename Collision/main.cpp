#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Teste de Colisao");
    
    sf::RectangleShape Player;
    Player.setFillColor (sf::Color::Green);
    Player.setSize({100, 100});
    Player.setPosition({100, 100});

    sf::RectangleShape Wall;
    Wall.setFillColor (sf::Color::Red);
    Wall.setSize({100, 100});
    Wall.setPosition({300, 100});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        //Aqui esta como o player se movimenta no cenario.

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            Player.move({1, 0});

            //O programa verifica se a tecla foi digitada, caso seja, o player se movimenta.
        }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            Player.move({-1, 0});
        }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            Player.move({0, -1});
        }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            Player.move({0, 1});
        }
        

        if(Player.getGlobalBounds().findIntersection(Wall.getGlobalBounds()))
        {
           Player.setFillColor(sf::Color::Blue);


            //Aqui o programa verifica se o player encosta na "parede". Caso encoste, a cor do player muda para azul.
        }
        else
        {
            Player.setFillColor(sf::Color::Green);
        }

        window.clear();
        window.draw(Player);
        window.draw(Wall);
        //window.draw(sprite);
        window.display();
    }
}
