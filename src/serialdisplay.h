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

#ifndef SERIALDISPLAY_H_
#define SERIALDISPLAY_H_

#include "display.h"
#include <string>

namespace display {

    struct SerialDisplayPrivate;

    /**
     * \class SerialDisplay
     * \brief Implementation of LCDM001 (kernelconcepts.de)
     */
    class SerialDisplay : public Display {
    public:

        /**
         * Cursor mode enum.
         */
        enum CursorMode {
            CM_Off,             //!< Cursor off.
            CM_Blink,           //!< Cursor blinking.
            CM_UnderScore,      //!< Cursor underscore.
            CM_UnderScoreBlink  //!< Cursor underscore and blinking.
        };

        /**
         * Key enum.
         * The LCDM001 has 4 hardware keys.
         */
        enum Key {
            K_Left = 1,     //!< Key left.
            K_Right = 2,    //!< Key right.
            K_Up = 3,       //!< Key up.
            K_Down = 4      //!< Key down.
        };

        /**
         * \brief Constructor
         * \param xDeviceName The devicename, e.g. "/dev/ttyS0"
         * \param xRows Number of rows of the display
         * \param xColumns Number of columns of the display
         */
        SerialDisplay(std::string const &xDeviceName, unsigned int xRows =
        4, unsigned int xColumns = 20);

        /**
         * \brief Destructor
         */
        virtual ~SerialDisplay();

        void clear();

        void resetCursor();

        void setCursor(unsigned int xRow, unsigned int xColumn);

        /**
         * \brief Set the cursor on display to a mode.
         * \param xMode The cursor mode
         */
        void setCursorMode(CursorMode xMode);

        SerialDisplay &put(char xChar, unsigned int xRow, unsigned int xColumn);

        SerialDisplay &write(const char *xLine, unsigned int xLength,
                             unsigned int xRow, unsigned int xColumn);

        SerialDisplay &writeLine(const char *xLine, unsigned int xLength);

    private:
        std::string rowAndColumnToString(unsigned int xRow, unsigned int xColumn);

        SerialDisplayPrivate *m;
    };

}

#endif /* SERIALDISPLAY_H_ */
