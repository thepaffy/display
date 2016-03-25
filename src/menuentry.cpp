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

#include "menuentry.h"
#include "menu.h"

#include <cassert>

namespace display {

    MenuEntry::MenuEntry(std::string const &xTitle, unsigned int xPos, Menu *xParent) :
            mTitle(xTitle), mPosition(xPos), mParent(xParent)  {
        assert(!mTitle.empty());
        assert(mPosition >= 0);

        mParent->registerChild(this);
    }

    MenuEntry::~MenuEntry() {
        if(mParent) {
            mParent->unregisterChild(this);
        }
    }

    void MenuEntry::setParent(Menu *xParent) {
        if (mParent) // unregister first on old parent
            mParent->unregisterChild(this);

        mParent = xParent;

        if (mParent)
            mParent->registerChild(this);
    }

    void MenuEntry::setTitle(std::string const &xTitle) {
        assert(!xTitle.empty());
        mTitle = xTitle;
    }

    void MenuEntry::setPosition(unsigned int xPos) {
        assert(xPos >= 0);
        mPosition = xPos;
    }
}
