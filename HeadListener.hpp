/* 
 * File:   HeadListener.hpp
 * Author: Rafa
 *
 * Created on 27 de diciembre de 2015, 2:01
 */

#ifndef HEADLISTENER_HPP
#define	HEADLISTENER_HPP

class HeadListener {
public:
    virtual void powerUpTaken() = 0;
    virtual void dead() = 0;
};

#endif	/* HEADLISTENER_HPP */

