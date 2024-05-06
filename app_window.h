#pragma once

#include <iostream>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

using namespace std;

struct AppWindow
{
    AppWindow(vector<vector<int64_t>> initCoord, vector<int64_t> initTwoPoint, int initScale, const int initSizeWidth) : 
    coord(initCoord), twoPoint(initTwoPoint), scale(initScale), SIZE_WIDTH(initSizeWidth)
    { }

    void runApp()
    {
        sf::RenderWindow window(sf::VideoMode(SIZE_WIDTH, SIZE_WIDTH), "app");

        // sf::CircleShape centerCircle(1);
        line[0].position.x = centerWindow + coord[twoPoint[0]][0] / scale;
        line[0].position.y = centerWindow - coord[twoPoint[0]][1] / scale;
        line[0].color = sf::Color::Red;
        line[1].position.x = centerWindow + coord[twoPoint[1]][0] / scale;
        line[1].position.y = centerWindow - coord[twoPoint[1]][1] / scale;
        line[1].color = sf::Color::Red;
        // centerCircle.setPosition(sf::Vector2f(centerWindow, centerWindow));
        // centerCircle.setFillColor(sf::Color::White);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(line, 2, sf::Lines);
            // window.draw(centerCircle);
            window.display();
        }
    }

private:
    const int SIZE_WIDTH;
    vector<vector<int64_t>> coord;
    vector<int64_t> twoPoint;
    int scale, centerWindow = SIZE_WIDTH / 2;
    sf::Vertex line[2];
};