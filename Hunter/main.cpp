#include <SFML/Graphics.hpp>
#include <iostream>
#include "ResourcePath.hpp"
using namespace sf;
struct slon{
    CircleShape dobocha1;
    double X, Y, a, b, c, d;
    int XP;
    bool dead;
    int x1;
    
    slon(){
        dobocha1.setRadius(200.f);
        X = 0;
        Y = 0;
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        XP = 10;
        dead = false;
        x1 = 100;
    }
    
    void muve(){
        if (c != a && dead == false) {
            c += X;
        } else if (dead == false) {
            X = 0;
        }
        if (d != b && dead == false) {
            d += Y;
        } else if (dead == false) {
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
    void inDead(){
        c = -10000;
        d = -10000;
    }
    void sm(double x, double y){
        if (XP > 0) {
            X = (a - dobocha1.getPosition().x) / 8000;
            Y = (b - dobocha1.getPosition().y) / 8000;
        } else {
            X = (a - dobocha1.getPosition().x) / 16000;
            Y = (b - dobocha1.getPosition().y) / 16000;
        }
    }
};
struct hit{
    double c2 = 0, d2 = 0;
    int x2 = 10;
};
struct pul{
    CircleShape pula;
    bool i;
    bool i2;
    bool in;
    int xp;
    Color arr[4];
    pul(){
        pula.setRadius(10.f);
        arr[0] = Color::Red;
        arr[1] = Color::Yellow;
        arr[2] = Color::Green;
        arr[3] = Color::Magenta;
        i = false;
        i2 = false;
        in = false;
        xp = -10;
    }
    void muve(double xo, double yo){
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
            xp = xo * 10;
        } else {
            xp = xo * 10;
            pula.setPosition(-1000, yo);
        }
    }
};
int man()
{
    Color arr[] {Color::Red, Color::Yellow, Color::Green, Color::Green, Color::Magenta};
    bool pr = true;
    bool paus = true;
    RenderWindow window(VideoMode(2000, 1000), "SLOH N CHIT");
    window.clear(Color(250, 220, 100));
    CircleShape str(50.f, 3);
    RectangleShape str1(Vector2f(10.f, 100.f));
    RectangleShape str2(Vector2f(10.f, 100.f));
    CircleShape oxotnik(20.f);
    CircleShape dobocha2(300.f);
    slon slon;
    hit hit;
    pul pula;
    CircleShape strelka(90.f, 3);
    RectangleShape pause (Vector2f(100.f, 100.f));
    strelka.setPosition(725, 500);
    slon.dobocha1.setFillColor(Color::Cyan);
    dobocha2.setFillColor(Color(255, 255, 255, 128));
    oxotnik.setPosition(50, rand() % 1000);
    slon.dobocha1.setPosition(rand() % 2000, rand() % 1000);
    slon.dobocha1.setPosition(slon.dobocha1.getPosition().x - 90, slon.dobocha1.getPosition().y - 90);
    slon.c = slon.dobocha1.getPosition().x;
    slon.d = slon.dobocha1.getPosition().y;
    pula.pula.setPosition(oxotnik.getPosition().x, oxotnik.getPosition().y);
    sf::Font font;
    str.rotate(90.0);
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    Text text1("", font, 50);
    text1.setFillColor(Color::Green);
    text1.setPosition(slon.c, slon.d - 60);
    Text text2("", font, 50);
    text2.setFillColor(Color::Green);
    text2.setPosition(hit.c2, hit.d2 - 60);
    Text text3("YOU WIN", font, 300);
    text3.setFillColor(Color::Black);
    text3.setPosition(-1000, -1000);
    Text text4("YOU DEAD", font, 300);
    text4.setFillColor(Color::Black);
    text4.setPosition(-1000, -1000);
    Text pravila("PROBEL = STRELBA, w a s d = DVIZEHNE, p = OTRAZENIE PULI, SHACHALA YBEITE CHIT, POTOM CLONA", font, 30);
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
            if (Mouse::isButtonPressed(Mouse::Left)){
              if (IntRect(0, 0, 100, 100).contains(Mouse::getPosition(window))) {
                  paus = !paus;
              }
            }
            if (paus) {
                if (event.type == Event::KeyPressed && (event.key.code == Keyboard::E || event.key.code == Keyboard::Space)){
                    pula.i = true;
                    pula.i2 = false;
                    pr = false;
                }
                if (event.type == Event::KeyPressed && event.key.code == Keyboard::P) {
                    pula.i2 = true;
                }
                if (event.type == Event::KeyPressed && (event.key.code == Keyboard::Down || event.key.code == Keyboard::S)){
                    for (int i = 0; i < 12; i++) {
                        oxotnik.setPosition(oxotnik.getPosition().x, oxotnik.getPosition().y + 1);
                        window.draw(oxotnik);
                    }
                    pr = false;
                }
                if (event.type == Event::KeyPressed && (event.key.code == Keyboard::Up || event.key.code == Keyboard::W)){
                    for (int i = 0; i < 12; i++) {
                        oxotnik.setPosition(oxotnik.getPosition().x, oxotnik.getPosition().y - 1);
                        window.draw(oxotnik);
                    }
                    pr = false;
                }
                if (event.type == Event::KeyPressed && (event.key.code == Keyboard::Left || event.key.code == Keyboard::A)){
                    for (int i = 0; i < 12; i++) {
                        oxotnik.setPosition(oxotnik.getPosition().x - 1, oxotnik.getPosition().y);
                        window.draw(oxotnik);
                    }
                    pr = false;
                }
                if (event.type == Event::KeyPressed && (event.key.code == Keyboard::Right || event.key.code == Keyboard::D)) {
                    for (int i = 0; i < 12; i++) {
                        oxotnik.setPosition(oxotnik.getPosition().x + 1, oxotnik.getPosition().y);
                        window.draw(oxotnik);
                    }
                    pr = false;
                }
            }
        }
        str2.setPosition(str1.getPosition().x + 30, str1.getPosition().y);
        if (paus) {
            str.setPosition(90, -5);
            str1.setPosition(-9090, -985);
        } else {
            str.setPosition(-9090, -985);
            str1.setPosition(25, -5);
        }
        slon.c = slon.dobocha1.getPosition().x;
        slon.d = slon.dobocha1.getPosition().y;
        hit.c2 = dobocha2.getPosition().x;
        hit.d2 = dobocha2.getPosition().y;
        oxotnik.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
        if (hit.x2 > 0) {
            dobocha2.setPosition(slon.dobocha1.getPosition().x - 90, slon.dobocha1.getPosition().y - 90);
        }
        slon.a = oxotnik.getPosition().x;
        slon.b = oxotnik.getPosition().y;
        slon.sm(slon.dobocha1.getPosition().x, slon.dobocha1.getPosition().y);
        if (pula.pula.getGlobalBounds().intersects(slon.dobocha1.getGlobalBounds()) || pula.pula.getGlobalBounds().intersects(dobocha2.getGlobalBounds())) {
            if (pula.pula.getGlobalBounds().intersects(slon.dobocha1.getGlobalBounds())) {
                slon.x1 -= 1;
            } else {
                hit.x2 -= 1;
            }
            slon.a = oxotnik.getPosition().x;
            slon.b = oxotnik.getPosition().y;
            pula.in = false;
            pula.i = false;
            pula.i2 = false;
            slon.dobocha1.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
        }
        if (pula.pula.getGlobalBounds().intersects(dobocha2.getGlobalBounds())) {
            pula.in = false;
            pula.i = false;
            pula.i2 = false;
            dobocha2.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255, 128));
        }
        if (oxotnik.getGlobalBounds().intersects(slon.dobocha1.getGlobalBounds()) || oxotnik.getGlobalBounds().intersects(dobocha2.getGlobalBounds())) {
            oxotnik.setPosition(10000, 10000);
            slon.inDead();
            dobocha2.setPosition(-10000, -10000);
            pula.i = false;
            pula.i2 = false;
            slon.dead = true;
        }
        text1.setString(std::to_string(slon.x1));
        text2.setString(std::to_string(hit.x2));
        text1.setPosition(slon.c, slon.d - 60);
        text2.setPosition(hit.c2, hit.d2 - 60);
        if (paus) {
            pula.muve(oxotnik.getPosition().x, oxotnik.getPosition().y);
            slon.muve();
            slon.dobocha1.setPosition(slon.c, slon.d);
        }
        text1.setPosition(slon.c, slon.d - 60);
        window.clear();
        window.draw(oxotnik);
        if (pula.i) {
            window.draw(pula.pula);
        }
        if (slon.x1 > 0) {
            window.draw(slon.dobocha1);
            window.draw(text1);
        } else {
            slon.dobocha1.setPosition(-1000, -1000);
        }
        if (hit.x2 > 0) {
            window.draw(dobocha2);
            window.draw(text2);
        } else {
            dobocha2.setPosition(-1000, -1000);
        }
        if (slon.x1 <= 0 && hit.x2 <= 0) {
            text3.setPosition(100, 50);
            window.draw(strelka);
            text3.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
        }
        if (slon.x1 <= 0 && hit.x2 <= 0 && pula.pula.getGlobalBounds().intersects(text3.getGlobalBounds())) {
            pula.in = false;
            pula.i = false;
            text3.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
        }
        if (slon.dead) {
            text4.setPosition(100, 50);
            text4.setFillColor(Color::Yellow);
        }
        if (pr) {
            window.draw(pravila);
        }
        window.draw(text3);
        window.draw(text4);
        pause.setFillColor(Color(128, 256, 0));
        window.draw(pause);
        window.draw(str);
        window.draw(str1);
        window.draw(str2);
        window.display();
    }
}
int main(int, char const**)
{
    man();
    return EXIT_SUCCESS;
}
