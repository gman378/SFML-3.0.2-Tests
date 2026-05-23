#include <SFML/Graphics.hpp>
#include <experimental/random>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Teste de posicao");

    sf::RectangleShape Object;

    Object.setFillColor(sf::Color::Blue); //Aqui eu defino a cor do bloquinho.
    Object.setSize({100.f, 100.f}); //Aqi eu defino o tamanho do bloquinho.

    float x = static_cast<float> (std::experimental::randint(10, (int) (window.getSize().x - Object.getSize().x))); //Aqui aonde eh definido o movimento do bloquinho, com o uso da biblioteca "experimental" eu consigo fazer o movimento dele ser aleatorio.

    Object.setPosition({ x, 10.f});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        Object.move({0.0f, 0.04f});

        if(Object.getPosition().y > 1080.f)
        {
             float x = static_cast<float> (std::experimental::randint(10, (int) (window.getSize().x - Object.getSize().x)));
            Object.setPosition({x, 10.f}); 
            
        }

       // if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        //{
       //     Object.setPosition({x, 10.f});
       // }
        

        window.clear();
        window.draw(Object);
        window.display();
    }
}
