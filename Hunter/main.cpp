#include <SFML/Graphics.hpp>
#include <iostream>
#include "ResourcePath.hpp"
using namespace sf;
int main(int, char const**)
{
    Color arr[] {Color::Red, Color::Yellow, Color::Green, Color::Blue, Color::Magenta};
    bool i = false;
    bool in = false;
    bool pu = false;
//    srand(time(0));
    RenderWindow window(VideoMode(2000, 1000), "OXOTHNK");
//    window.setFramerateLimit(25);
//    struct s {
//            double X;
//            double Y;
//            s()
//            {
//                X = rand() % 2000;
//                Y = rand() % 1000;
//                cnt = (rand() % 628) / 100;
//            }
//        double cnt;
//        void move()
//        {
//            Y++;
//            X += cos(cnt);
//            cnt += 0.01;
//            if (Y > 1000){
//                Y = -10;
//            }
//            if (X > 2000){
//                X = -10;
//            }
//            if (cnt > 3.1415926 * 2) {
//                cnt = 0;
//            }
//        }
//    };
    CircleShape circle1(20.f);
    CircleShape circle2(20.f);
    CircleShape circle21(20.f);
    CircleShape pula(10.f, 5);
    circle2.setFillColor(Color::Cyan);
    circle21.setFillColor(Color::Cyan);
    circle1.setPosition(50, rand() % 1000);
    circle2.setPosition(rand() % 2000, rand() % 1000);
    circle21.setPosition(rand() % 2000, rand() % 1000);
    pula.setPosition(circle1.getPosition().x, circle1.getPosition().y);
    int xp = circle1.getPosition().x * 10;
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
                if (pu){
                    pula.setPosition(pula.getPosition().x, pula.getPosition().y + 12);
                    window.draw(pula);
                    window.display();
                }
                else {
                circle1.setPosition(circle1.getPosition().x, circle1.getPosition().y + 12);
                window.draw(circle1);
                window.display();
                }
            }
            if (event.type == Event::KeyPressed && (event.key.code == Keyboard::Up || event.key.code == Keyboard::W)) {
                if (pu){
                    pula.setPosition(pula.getPosition().x, pula.getPosition().y - 12);
                    window.draw(pula);
                    window.display();
                }
                else {
                circle1.setPosition(circle1.getPosition().x, circle1.getPosition().y - 12);
                window.draw(circle1);
                window.display();
                }
            }
            if (event.type == Event::KeyPressed && (event.key.code == Keyboard::Left || event.key.code == Keyboard::A)) {
                if (pu){
                    pula.setPosition(pula.getPosition().x - 12, pula.getPosition().y);
                    window.draw(pula);
                    window.display();
                }
                else {
                circle1.setPosition(circle1.getPosition().x - 12, circle1.getPosition().y);
                window.draw(circle1);
                window.display();
                }
            }
            if (event.type == Event::KeyPressed && (event.key.code == Keyboard::Right || event.key.code == Keyboard::D)) {
                if (pu){
                    pula.setPosition(pula.getPosition().x + 12, pula.getPosition().y);
                    window.draw(pula);
                    window.display();
                }
                else {
                circle1.setPosition(circle1.getPosition().x + 12, circle1.getPosition().y);
                window.draw(circle1);
                window.display();
                }
            }
            if (!(0 <= circle1.getPosition().x <= window.getSize().x)){
                circle1.setPosition(50, rand() % 1000);
            }
        }
        if (rand() % 333 <= 111) {
            circle1.setFillColor(Color(rand() % 255, 255, 255));
        } else if (rand() % 333 <= 222) {
            circle1.setFillColor(Color(255, rand() % 255, 255));
        } else {
            circle1.setFillColor(Color(255, 255, rand() % 255));
        }
        window.clear();
        window.draw(circle1);
        window.draw(circle2);
        window.draw(circle21);
        if (pula.getGlobalBounds().intersects(circle2.getGlobalBounds())) {
            circle2.setFillColor(Color::Red);
            circle2.setPosition(rand() % 2000, rand() % 1000);
            in = false;
            i = false;
            pu = false;
            xp = circle1.getPosition().x * 10;
            circle2.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
        }
        if (pula.getGlobalBounds().intersects(circle21.getGlobalBounds())) {
            circle21.setFillColor(Color::Red);
            circle21.setPosition(rand() % 2000, rand() % 1000);
            in = false;
            i = false;
            pu = false;
            xp = circle1.getPosition().x * 10;
            circle21.setFillColor(Color(rand() % 255, rand() % 255, rand() % 255));
        }
        if (rand() % 10000 == 5) {
            circle2.setPosition(rand() % 2000, rand() % 1000);
            
        }
        if (rand() % 10000 == 5) {
            circle21.setPosition(rand() % 2000, rand() % 1000);
        }
        if (!i) {
            pula.setPosition(circle1.getPosition().x * 10, circle1.getPosition().y);
        }
        if (xp / 10 > 2000) {
            in = true;
        }
        if (!i && xp / 10 != circle1.getPosition().x){
            xp = circle1.getPosition().x * 10;
            
        }
        if (i && xp / 10 > 0) {
            pu = true;
            if (in) {
                xp -= 6 ;
            } else {
                xp += 6;
            }
                pula.setPosition(xp / 10, pula.getPosition().y);
                pula.setFillColor(arr[rand() % 4]);
                window.draw(pula);
        } else if (i && xp / 10 <= 0) {
            pu = false;
            in = false;
            i = false;
            xp = circle1.getPosition().x * 10;
        }
        window.display();
 
//    s arr[200];
//    CircleShape sn(5.f);
//    while (window.isOpen()) {
//        Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == Event::Closed) {
//                window.close();
//            }
//            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
//                window.close();
//            }
//        }
//            window.clear();
//            for (int i = 0; i < 200; i ++) {
//                    arr[i].move();
//                        sn.setPosition(arr[i].X, arr[i].Y);
//                        window.draw(sn);
//                        }
//                    window.display();
            }
    return EXIT_SUCCESS;
}
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include "ResourcePath.hpp"
//using namespace sf;
//int main(int, char const**)
//{
//    srand(time(0));
//    RenderWindow window(VideoMode(2000, 1000), "OXOTHNK");
//    window.setFramerateLimit(25);
//    struct s {
//            double X;
//            double Y;
//            s()
//            {
//                X = rand() % 2000;
//                Y = rand() % 1000;
//                cnt = (rand() % 628) / 100;
//            }
//        double cnt;
//        void move()
//        {
//            Y++;
//            X += cos(cnt);
//            cnt += 0.01;
//            if (Y > 1000){
//                Y = -10;
//            }
//            if (X > 2000){
//                X = -10;
//            }
//            if (cnt > 3.1415926 * 2) {
//                cnt = 0;
//            }
//        }
//    };
//    s arr[200];
//    CircleShape sn(5.f);
//    while (window.isOpen()) {
//        Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == Event::Closed) {
//                window.close();
//            }
//            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
//                window.close();
//            }
//        }
//            window.clear();
//            for (int i = 0; i < 200; i ++) {
//                    arr[i].move();
//                        sn.setPosition(arr[i].X, arr[i].Y);
//                        window.draw(sn);
//                        }
//                    window.display();
//}
