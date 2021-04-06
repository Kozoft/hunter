#include <SFML/Graphics.hpp>
#include <iostream>
#include "ResourcePath.hpp"
using namespace sf;
int main(int, char const**)
{
    Color arr[] {Color::Red, Color::Yellow, Color::Green, Color::Blue, Color::Magenta};
    bool i = false;
    bool i2 = false;
    bool in = false;
    double X = 0;
    double Y = 0;
    double a = 0, b = 0, c = 0, d = 0;
    double X2 = 0;
    double Y2 = 0;
    double a2 = 0, b2 = 0, c2 = 0, d2 = 0;
    int x1 = 100;
    int x2 = 10;
    bool dead = false;
    bool pr = true;
    RenderWindow window(VideoMode(2000, 1000), "SLOH N MYXA");
    CircleShape oxotnik(20.f);
    CircleShape dobocha1(200.f);
    CircleShape dobocha2(10.f, 5);
    CircleShape pula(10.f, 5);
    CircleShape strelka(90.f, 3);
    strelka.setPosition(725, 500);
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
    Text text3("YOU WIN", font, 300);
    text3.setFillColor(Color::Black);
    text3.setPosition(-1000, -1000);
    Text text4("YOU DEAD", font, 300);
    text4.setFillColor(Color::Black);
    text4.setPosition(-1000, -1000);
    Text pravila("e = STRELBA, w a s d = DVIZEHNE, q = OTRAZENIE PULI, SHACHALA YBEITE MYXY, POTOM CLONA", font, 30);
    pravila.setFillColor(Color::Red);
    pravila.setPosition(0, 200);
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
            if (event.type == Event::KeyPressed && (event.key.code == Keyboard::E || event.key.code == Keyboard::Space)) {
                i = true;
                i2 = false;
                pr = false;
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Q) {
                i2 = true;
            }
            if (event.type == Event::KeyPressed && (event.key.code == Keyboard::Down || event.key.code == Keyboard::S)) {
                oxotnik.setPosition(oxotnik.getPosition().x, oxotnik.getPosition().y + 12);
                pr = false;
            }
            if (event.type == Event::KeyPressed && (event.key.code == Keyboard::Up || event.key.code == Keyboard::W)) {
                oxotnik.setPosition(oxotnik.getPosition().x, oxotnik.getPosition().y - 12);
                pr = false;
            }
            if (event.type == Event::KeyPressed && (event.key.code == Keyboard::Left || event.key.code == Keyboard::A)) {
                oxotnik.setPosition(oxotnik.getPosition().x - 12, oxotnik.getPosition().y);
                pr = false;
            }
            if (event.type == Event::KeyPressed && (event.key.code == Keyboard::Right || event.key.code == Keyboard::D)) {
                oxotnik.setPosition(oxotnik.getPosition().x + 12, oxotnik.getPosition().y);
                pr = false;
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
            if (x2 <= 0) {
                x1 -= 1;
            }
            a = oxotnik.getPosition().x;
            b = oxotnik.getPosition().y;
            X = (a - dobocha1.getPosition().x) / 7000;
            Y = (b - dobocha1.getPosition().y) / 7000;
            in = false;
            i = false;
            i2 = false;
            dobocha1.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
        }
        if (pula.getGlobalBounds().intersects(dobocha2.getGlobalBounds()) || dobocha2.getGlobalBounds().intersects(dobocha1.getGlobalBounds())) {
            x2 -= 1;
            X2 = 0;
            Y2 = 0;
            a2 = 0;
            b2 = 0;
            a2 = oxotnik.getPosition().x + 25;
            b2 = oxotnik.getPosition().y;
            X2 = (a2 - dobocha1.getPosition().x) / 1000;
            Y2 = (b2 - dobocha1.getPosition().y) / 1000;
            in = false;
            i = false;
            i2 = false;
            dobocha2.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
        }
        if (oxotnik.getGlobalBounds().intersects(dobocha1.getGlobalBounds()) || oxotnik.getGlobalBounds().intersects(dobocha2.getGlobalBounds())) {
            oxotnik.setPosition(10000, 10000);
            dobocha1.setPosition(-10000, -10000);
            dobocha2.setPosition(-10000, -10000);
            i = false;
            i2 = false;
            dead = true;
        }
        text1.setString(std::to_string(x1));
        text2.setString(std::to_string(x2));
        text1.setPosition(c, d - 60);
        text2.setPosition(c2, d2 - 60);
        if (!i) {
            xp = -1000;
        }
        if (xp / 10 > 2000) {
            in = true;
        }
        if (i && xp / 10 > 0) {
            if (in || i2) {
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
        } else {
            xp = oxotnik.getPosition().x * 10;
            pula.setPosition(-1000, oxotnik.getPosition().y);
        }
        if (x2 <= 0) {
            if (c != a && dead == false) {
                dobocha1.setPosition(c + X, d);
                c = dobocha1.getPosition().x;
            } else if (dead == false) {
                X = 0;
                Y = 0;
            }
            if (d != b && dead == false) {
                dobocha1.setPosition(c, d + Y);
                d = dobocha1.getPosition().y;
            } else if (dead == false) {
                X = 0;
                Y = 0;
            }
            if (((X < 0 && c < a) || (X > 0 && c > a)) && dead == false){
                c = a;
                X = 0;
            }
            if (((Y < 0 && d < b) || (Y > 0 && d > b)) && dead == false){
                d = b;
                Y = 0;
            }
        }
        if (c2 != a2 && dead == false) {
            dobocha2.setPosition(c2 + X2, d2);
            c2 = dobocha2.getPosition().x;
        } else if (dead == false) {
            X2 = 0;
            Y2 = 0;
        }
        if (d2 != b2 && dead == false) {
            dobocha2.setPosition(c2, d2 + Y2);
            d = dobocha1.getPosition().y;
        } else if (dead == false) {
            X2 = 0;
            Y2 = 0;
        }
        if (((X2 < 0 && c2 < a2) || (X2 > 0 && c2 > a2)) && dead == false){
            c2 = a2;
            X2 = 0;
        }
        if (((Y2 < 0 && d2 < b2) || (Y2 > 0 && d2 > b2)) && dead == false){
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
            dobocha1.setPosition(-1000, -1000);
        }
        if (x2 > 0) {
            window.draw(dobocha2);
            window.draw(text2);
        } else {
            dobocha2.setPosition(-1000, -1000);
        }
        if (x1 <= 0 && x2 <= 0) {
            text3.setPosition(100, 50);
            window.draw(strelka);
            text3.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
        }
        if (x1 <= 0 && x2 <= 0 && pula.getGlobalBounds().intersects(text3.getGlobalBounds())) {
            in = false;
            i = false;
            text3.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
        }
        if (dead) {
            text4.setPosition(100, 50);
            text4.setFillColor(Color::Blue);
        }
        if (pr) {
            window.draw(pravila);
        }
        window.draw(text3);
        window.draw(text4);
        window.display();
    }
    return EXIT_SUCCESS;
}
