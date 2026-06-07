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

    Object.setPosition({ x, 10.f}); //Aqui aonde defino o spawn do bloquinho.

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        Object.move({0.0f, 0.04f}); //Aqui o bloquinho se movimenta para baixo.

        if(Object.getPosition().y > 1080.f) 
        {
             float x = static_cast<float> (std::experimental::randint(10, (int) (window.getSize().x - Object.getSize().x))); //Quando o bloquinho sair da tela, ele reinicia e volta para um novo lugar. indo para um loop.
            Object.setPosition({x, 10.f}); //Aqui o bloquinho volta ao lugar original
            
        }

       if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right) && Object.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) //Codigo atualizado
        {
            float x = static_cast<float> (std::experimental::randint(10, (int) (window.getSize().x - Object.getSize().x)));
            Object.setPosition({x, 10.f}); //Bloquinho volta ao lugar original
        }
        

        window.clear();
        window.draw(Object);
        window.display();
    }
}
