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

#ifndef MENUENTRY_H_
#define MENUENTRY_H_

#include <string>

namespace display {

    class Menu;
    class Display;

    /**
     * \class MenuEntry
     * \brief Represents a basic menu entry.
     *
     * For create a own menu entry type, e.g. Menu derive from this class.
     */
    class MenuEntry {
    public:

        /**
         * \brief Constructor
         * \param xTitle Title of the entry in parent menu.
         * \param xPos Position of the entry in parent menu.
         * \param xParent The parent menu.
         */
        MenuEntry(std::string const &xTitle, unsigned int xPos, Menu *xParent = nullptr);

        /**
         * \brief Destructor
         */
        virtual ~MenuEntry();

        /**
         * \brief Returns the parent menu.
         */
        Menu *parent() const { return mParent; }

        /**
         * \brief Sets the parent menu.
         */
        void setParent(Menu *xParent);

        /**
         * \brief Returns the entry title in the parent menu.
         * \return Const reference.
         */
        const std::string &title() const { return mTitle; }

        /**
         * \brief Returns the entry title in the parent menu.
         * \return Reference.
         */
        std::string &title() { return mTitle; }

        /**
         * \brief Sets the entry title in the parent menu.
         */
        void setTitle(std::string const &xTitle);

        /**
         * \brief Returns the position in the parent menu.
         */
        unsigned int position() { return mPosition; }

        /**
         * \brief Sets the position in the parent menu.
         */
        void setPosition(unsigned int xPos);

        /**
         * \brief Render the menu entry on the display.
         * \param xDisplay The Display to render on.
         */
        virtual void render(Display *xDisplay) = 0;

    private:
        std::string mTitle;
        unsigned int mPosition;
        Menu *mParent;
    };
}

#endif
