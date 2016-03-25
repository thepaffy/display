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

#include "action.h"

#include <cassert>

namespace display {

    Action::Action(cback xCallbackFunction, std::string const &xTitle, unsigned int xPos, Menu *xParent)
            : MenuEntry(xTitle, xPos, xParent), mCallbackFunction(xCallbackFunction) {
        assert(mCallbackFunction);
    }

    void Action::setCallbackFunction(cback xCallbackFunction) {
        assert(xCallbackFunction);
        mCallbackFunction = xCallbackFunction;
    }
}
