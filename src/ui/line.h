#pragma once

#include "ui.h"
#include <string>

struct Line {
    std::string text {};
    int uiElementMaxLength {};
    UIAlignment alignment {};
};