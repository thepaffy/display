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

#ifndef DISPLAY_ACTION_H
#define DISPLAY_ACTION_H

#include "menuentry.h"

/**
 * \brief Namespace for display.
 */
namespace display {

    /**
     * \brief Callback function type "cback"
     */
    typedef void (*cback)();

    /**
     * \class Action
     * \brief Represents a action.
     */
    class Action : public MenuEntry {
    public:

        /**
         * \brief Constructor
         * \param xCallbackFunction The callback function for the action.
         * \param xTitle Title of the entry in parent menu.
         * \param xPos Position of the entry in parent menu.
         * \param xParent The parent menu.
         */
        Action(cback xCallbackFunction, std::string const &xTitle, unsigned int xPos, Menu *xParent);

        /**
         * \brief Returns the callback function.
         */
        cback callbackFunction() { return mCallbackFunction; }

        /**
         * \brief Sets
         */
        void setCallbackFunction(cback xCallbackFunction);

        virtual void render(Display *) { /* Nothing to render here */ }

    private:
        cback mCallbackFunction;
    };
}

#endif //DISPLAY_ACTION_H
