/*
 * Copyright (C) 2016 Christian Paffhausen, <https://github.com/thepaffy/>
 *
 * This file is part of display.
 *
 * display is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Foobar is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "menu.h"
#include "display.h"

#include <cassert>

namespace display {

    Menu::Menu(std::string const &xTitle, unsigned int xPos, Menu *xParent)
            : MenuEntry(xTitle, xPos, xParent) {
    }

    Menu::~Menu() {
        for(MenuEntry *tEntry: mChildren) {
            delete tEntry;
        }
    }

    void Menu::render(Display *xDisplay) {
        xDisplay->clear();
    }

    void Menu::registerChild(MenuEntry *xChild) {
        assert(xChild->parent() == this);
        mChildren.emplace_back(xChild);
    }

    void Menu::unregisterChild(MenuEntry *xChild) {
        assert(xChild->parent() == this);
        mChildren.remove(xChild);
    }
}

