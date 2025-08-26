#pragma once

#include "genericGameConfig.h"

struct Location {

    constexpr static int s_startingRoom { 1 };
    constexpr static int s_startingFloor { 1 };

    Location() : floor { s_startingFloor }, room { s_startingRoom } {} 

    int floor {};
    int room {};

    void nextRoom() {
        ++room;
        if(room > GameConfig::s_maxRoom) {
            room = s_startingRoom; 
            ++floor;
        }

    }

    bool isGameOver() const {
        return (floor > GameConfig::s_maxFloor);
    }

    bool isBigEnemy() const {
        return (room == GameConfig::s_maxRoom);
    }
};