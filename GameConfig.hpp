/* 
 * File:   GameConfig.hpp
 * Author: Rafa
 *
 * Created on 5 de enero de 2016, 13:43
 */

#ifndef GAMECONFIG_HPP
#define	GAMECONFIG_HPP

class GameConfig {
public:
    typedef unsigned int Difficulty;
    typedef unsigned int Skin;
    
    static const Difficulty EASY = 0, NORMAL = 1, HARD = 2, PSYCHOPATH = 3;
    static const Skin STANDARD = 0, RANDOM = 1, EPILEPTIC = 2;
    
    GameConfig(Difficulty difficulty, Skin skin);
    virtual ~GameConfig();
    
    void setDifficulty(Difficulty difficulty) { this->difficulty = difficulty; }
    void setSkin(Skin skin) { this->skin = skin; }
    
    Difficulty getDifficulty() const { return difficulty; }
    Skin getSkin() const { return skin; }
    
    static Difficulty getMaxDifficulty() { return PSYCHOPATH; }
    static Difficulty getMinDifficulty() { return EASY; }
    
    static Skin getMaxSkin() { return EPILEPTIC; }
    static Skin getMinSkin() { return STANDARD; }
    
private:
    Difficulty difficulty;
    Skin skin;
};

#endif	/* GAMECONFIG_HPP */

