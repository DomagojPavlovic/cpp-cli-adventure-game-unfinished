#pragma once

#include "uiAlignment.h"
#include "line.h"
#include "updateState.h"
#include <string>
#include <string_view>
#include <vector>
#include <map>

class UIElement {

public:

    UIElement(int startingLine, UIAlignment alignment) 
        : m_startingLine { startingLine }, m_alignment { alignment } {}

    virtual ~UIElement() = default;

    int getStartingLine() const { return m_startingLine; }

    virtual std::map<int, Line> getLines() = 0;

protected:
    
    int         m_startingLine {};
    UIAlignment m_alignment {};
};