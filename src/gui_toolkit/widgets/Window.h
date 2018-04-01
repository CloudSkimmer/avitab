/*
 *   AviTab - Aviator's Virtual Tablet
 *   Copyright (C) 2018 Folke Will <folko@solhost.org>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU Affero General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU Affero General Public License for more details.
 *
 *   You should have received a copy of the GNU Affero General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef SRC_GUI_TOOLKIT_WIDGETS_WINDOW_H_
#define SRC_GUI_TOOLKIT_WIDGETS_WINDOW_H_

#include <functional>
#include <string>
#include <map>
#include "Widget.h"

namespace avitab {

class Window: public Widget {
public:
    using WindowCallback = std::function<void()>;
    enum class Symbol {
        CLOSE,
        LEFT, RIGHT, UP, DOWN,
        PREV, NEXT,
        PLUS, MINUS,
    };

    Window(WidgetPtr parent, const std::string &title);
    void setOnClose(WindowCallback cb);
    void hideScrollbars();
    int getContentWidth();
    void addSymbol(Symbol smb, WindowCallback cb);
private:
    std::map<Symbol, WindowCallback> callbacks;

    const void *symbolToLVSymbol(Symbol symbol);
};

} /* namespace avitab */

#endif /* SRC_GUI_TOOLKIT_WIDGETS_WINDOW_H_ */
