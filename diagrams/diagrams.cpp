#include <iostream>
#include<SFML/Graphics.hpp>
#include"x_axis.h"
int main(){
        sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
        std::vector<double> arr={10,8,-4,2,-7,-1,30};
        x_axis xa(&arr);
        xa.setLegnth(600);
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