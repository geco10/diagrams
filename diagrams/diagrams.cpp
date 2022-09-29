#include <iostream>
#include<SFML/Graphics.hpp>
#include"x_axis.h"
int main(){
        sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
        x_axis xa;
        xa.setLegnth(60);
        xa.setLoc(40,40);
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear(sf::Color(225,225,225));
            window.draw(xa);
            window.display();
        }

        return 0;
}