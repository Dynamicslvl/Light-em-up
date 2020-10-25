#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "MyFunctions.h"
#include "MovableBlock.h"

using namespace sf;
using namespace std;

int main()
{
    //Create a room
    RenderWindow window(VideoMode(512, 512), "Sandbox", Style::Close | Style::Titlebar);
    //Background
    Texture spr_grid;
    spr_grid.loadFromFile("Sprites/spr_grid.png");
    RectangleShape back_grid;
    back_grid.setSize(Vector2f(512, 512));
    back_grid.setOrigin(0, 0);
    back_grid.setTexture(&spr_grid);
    //Pointer
    RectangleShape obj_pointer;
    obj_pointer.setSize(Vector2f(10, 10));
    obj_pointer.setOrigin(Vector2f(5, 5));
    obj_pointer.setFillColor(Color(255, 0, 255, 0));
    obj_pointer.setPosition((Vector2f) Mouse::getPosition(window));
    //Block
    RectangleShape obj_block;
    obj_block.setSize(Vector2f(64, 64));
    obj_block.setOrigin(Vector2f(32, 32));
    obj_block.setFillColor(Color(255, 255, 255, 255));
    obj_block.setPosition(Vector2f(256-32, 256-32));
    MovableBlock test;
    test.setBody(obj_block);
    //Set FPS
    window.setFramerateLimit(60);
    //Steps
    while (window.isOpen()) {
        Event e;
        //Window events
        while (window.pollEvent(e)) {
            switch (e.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::Resized:
                cout << e.size.width << " " << e.size.height << endl;
                break;
            case Event::TextEntered:
                if (e.text.unicode < 128) {
                    cout << (char) e.text.unicode;
                }
                break;
            }
        }
        //Pointer
        obj_pointer.setPosition((Vector2f)Mouse::getPosition(window));
        //Move
        test.moveByMouse(obj_pointer);
        test.limitPos();
        test.autoAlignToGrid();
        //Draw
        window.clear();
        window.draw(back_grid);
        window.draw(test.getBody());
        window.draw(obj_pointer);
        window.display();
    }
    return 0;
}