/* 
 * File:   main.cpp
 * Author: Rafa
 *
 * Created on 23 de diciembre de 2015, 23:07
 */

#include <cstdlib>
#include <ESE/Core/Application.hpp>
#include <memory>

#include "GameScene.hpp"
#include "MenuScene.hpp"

using namespace std;

class Main : public ESE::Application {
private:
    ESE::Scene* gameScene, *menuScene;
public:
    Main();
    ~Main();
};

Main::Main() {
    getWindow()->create(sf::VideoMode(500,500),"Snake");
    
    ESE::ResourceManager::instance()->fonts()->loadFromFile("font","boldfont.ttf");
    
    menuScene = new MenuScene(getWindow());
    
    getSceneManager()->addScene(*menuScene);
    getSceneManager()->activateScene("MenuScene");
}

Main::~Main() {
    delete menuScene;
}

/*
 * 
 */
int main(int argc, char** argv) {

    Main application;
    
    application.run();
    
    return 0;
}

