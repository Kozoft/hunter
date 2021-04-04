#include <SFML/Graphics.hpp>
#include <iostream>
#include "ResourcePath.hpp"
using namespace sf;
int main(int, char const**)
{
    Color arr[] {Color::Red, Color::Yellow, Color::Green, Color::Blue, Color::Magenta};
    bool i = false;
    bool in = false;
    double X = 0;
    double Y = 0;
    double a = 0, b = 0, c = 0, d = 0;
    double X2 = 0;
    double Y2 = 0;
    double a2 = 0, b2 = 0, c2 = 0, d2 = 0;
    int x1 = 100;
    int x2 = 10;
    RenderWindow window(VideoMode(2000, 1000), "SLOH N MYXA");
    CircleShape oxotnik(20.f);
    CircleShape dobocha1(200.f);
    CircleShape dobocha2(2.f);
    CircleShape pula(10.f, 5);
    CircleShape strelka(90.f, 3);
    strelka.setPosition(825, 600);
    dobocha1.setFillColor(Color::Cyan);
    dobocha2.setFillColor(Color::Cyan);
    oxotnik.setPosition(50, rand() % 1000);
    dobocha1.setPosition(rand() % 2000, rand() % 1000);
    dobocha2.setPosition(rand() % 2000, rand() % 1000);
    c = dobocha1.getPosition().x;
    d = dobocha1.getPosition().y;
    c2 = dobocha2.getPosition().x;
    d2 = dobocha2.getPosition().y;
    pula.setPosition(oxotnik.getPosition().x, oxotnik.getPosition().y);
    int xp = -10;
    
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    Text text1("", font, 50);
    text1.setFillColor(Color::Green);
    text1.setPosition(c, d - 60);
    Text text2("", font, 50);
    text2.setFillColor(Color::Green);
    text2.setPosition(c2, d2 - 60);
    Text text3("TA-DA!", font, 500);
    text3.setFillColor(Color::Black);
    text3.setPosition(-1000, -1000);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                window.close();
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Space) {
                i = true;
            }
            if (event.type == Event::KeyPressed && (event.key.code == Keyboard::Down || event.key.code == Keyboard::S)) {
                oxotnik.setPosition(oxotnik.getPosition().x, oxotnik.getPosition().y + 12);
            }
            if (event.type == Event::KeyPressed && (event.key.code == Keyboard::Up || event.key.code == Keyboard::W)) {
                oxotnik.setPosition(oxotnik.getPosition().x, oxotnik.getPosition().y - 12);
            }
            if (event.type == Event::KeyPressed && (event.key.code == Keyboard::Left || event.key.code == Keyboard::A)) {
                oxotnik.setPosition(oxotnik.getPosition().x - 12, oxotnik.getPosition().y);
            }
            if (event.type == Event::KeyPressed && (event.key.code == Keyboard::Right || event.key.code == Keyboard::D)) {
                oxotnik.setPosition(oxotnik.getPosition().x + 12, oxotnik.getPosition().y);
            }
            if (!(0 <= oxotnik.getPosition().x <= window.getSize().x)){
                oxotnik.setPosition(50, rand() % 1000);
            }
        }
        if (c != dobocha1.getPosition().x) {
            c = dobocha1.getPosition().x;
        }
        if (d != dobocha1.getPosition().y) {
            d = dobocha1.getPosition().y;
        }
        if (c2 != dobocha2.getPosition().x) {
            c2 = dobocha2.getPosition().x;
        }
        if (d2 != dobocha2.getPosition().y) {
            d2 = dobocha2.getPosition().y;
        }
        oxotnik.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
        if (pula.getGlobalBounds().intersects(dobocha1.getGlobalBounds())) {
            x1 -= 1;
            a = rand() % 2000;
            b = rand() % 1000;
            X = (a - dobocha1.getPosition().x) / 10000;
            Y = (b - dobocha1.getPosition().y) / 10000;
            in = false;
            i = false;
            dobocha1.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
        }
        if (pula.getGlobalBounds().intersects(dobocha2.getGlobalBounds())) {
            x2 -= 1;
            a2 = rand() % 2000;
            b2 = rand() % 1000;
            X2 = (a2 - dobocha1.getPosition().x) / 10000;
            Y2 = (b2 - dobocha1.getPosition().y) / 10000;
            in = false;
            i = false;
            dobocha2.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
        }
        text1.setString(std::to_string(x1));
        text2.setString(std::to_string(x2));
        text1.setPosition(c, d - 60);
        text2.setPosition(c2, d2 - 60);
        if (rand() % 10000 == 5) {
            dobocha1.setPosition(rand() % 2000, rand() % 1000);
        }
        if (rand() % 10000 == 5) {
            dobocha2.setPosition(rand() % 2000, rand() % 1000);
        }
        if (!i) {
            pula.setPosition(oxotnik.getPosition().x * 10, oxotnik.getPosition().y);
        }
        if (xp / 10 > 2000) {
            in = true;
        }
        if (!i && xp / 10 != oxotnik.getPosition().x){
            xp = oxotnik.getPosition().x * 10;
        }
        if (i && xp / 10 > 0) {
            if (in) {
                xp -= 6 ;
            } else {
                xp += 6;
            }
                pula.setPosition(xp / 10, pula.getPosition().y);
                pula.setFillColor(arr[rand() % 4]);
        } else if (i && xp / 10 <= 0) {
            in = false;
            i = false;
            xp = oxotnik.getPosition().x * 10;
        }
        if (c != a) {
            dobocha1.setPosition(c + X, d);
            c = dobocha1.getPosition().x;
        } else {
            X = 0;
            Y = 0;
        }
        if (d != b) {
            dobocha1.setPosition(c, d + Y);
            d = dobocha1.getPosition().y;
        } else {
            X = 0;
            Y = 0;
        }
        if ((X < 0 && c < a) || (X > 0 && c > a)){
            c = a;
            X = 0;
        }
        if ((Y < 0 && d < b) || (Y > 0 && d > b)){
            d = b;
            Y = 0;
        }
        if (c2 != a2) {
            dobocha2.setPosition(c2 + X2, d2);
            c2 = dobocha2.getPosition().x;
        } else {
            X2 = 0;
            Y2 = 0;
        }
        if (d2 != b2) {
            dobocha2.setPosition(c2, d2 + Y2);
            d2 = dobocha2.getPosition().y;
        } else {
            X2 = 0;
            Y2 = 0;
        }
        if ((X2 < 0 && c2 < a2) || (X2 > 0 && c2 > a2)){
            c2 = a2;
            X2 = 0;
        }
        if ((Y2 < 0 && d2 < b2) || (Y2 > 0 && d2 > b2)){
            d2 = b2;
            Y2 = 0;
        }
        window.clear();
        window.draw(oxotnik);
        if (i) {
            window.draw(pula);
        }
        if (x1 > 0) {
            window.draw(dobocha1);
            window.draw(text1);
        } else {
            dobocha1.setPosition(-100, -100);
        }
        if (x2 > 0) {
            window.draw(dobocha2);
            window.draw(text2);
        } else {
            dobocha2.setPosition(-100, -100);
        }
        if (x1 <= 0 && x2 <= 0) {
            text3.setPosition(100, 50);
            window.draw(strelka);
        }
        if (x1 <= 0 && x2 <= 0 && pula.getGlobalBounds().intersects(text3.getGlobalBounds())) {
            in = false;
            i = false;
            text3.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
        }
        window.draw(text3);
        window.display();
    }
    return EXIT_SUCCESS;
}
