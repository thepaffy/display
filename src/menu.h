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

#ifndef MENU_H_
#define MENU_H_

#include "menuentry.h"
#include <list>

namespace display {

    /**
     * \class Menu
     * \brief Represents a menu.
     * A Menu can have children menu entries.
     */
    class Menu : public MenuEntry {
    public:

        /**
         * \brief Constructor
         * \param xTitle Title of the entry in parent menu.
         * \param xPos Position of the entry in parent menu.
         * \param xParent The parent menu.
         */
        Menu(std::string const &xTitle, unsigned int xPos, Menu *xParent = nullptr);

        /**
         * \brief Destructor
         */
        virtual ~Menu();

        virtual void render(Display *xDisplay);

        /**
         * \brief Register a child.
         * \param xChild The child. The childs parent must be equal with the instance of registration.
         */
        void registerChild(MenuEntry *xChild);

        /**
         * \brief Unregister a child.
         * \param xChild The child. The childs parent must be equal with the instance of registration.
         */
        void unregisterChild(MenuEntry *xChild);

    private:
        std::list<MenuEntry *> mChildren;
    };
}

#endif /* MENU_H_ */
