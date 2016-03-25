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

#ifndef DISPLAY_H_
#define DISPLAY_H_

namespace display {

    /**
     * \class Display
     * \brief A abstract class which represents a display with rows and columns
     *
     * For implement a serial or parallel display create a class e.g. SerialDisplay and derive from this class.
     */
    class Display {

    public:

        /**
         * \brief Constructor
         * \param xRows Number of rows of the display
         * \param xColumns Number of columns of the display
         */
        Display(unsigned int xRows, unsigned int xColumns)
                : mRows(xRows), mColumns(xColumns) {
        }

        /**
         * \brief Destructor
         */
        virtual ~Display() {
        }

        /**
         * \brief Clears the display and set the cursor position to the left-top corner.
         */
        virtual void clear() = 0;

        /**
         * \brief Set the cursor position to the left-top corner
         */
        virtual void resetCursor() = 0;

        /**
         * \brief Set the cursor to a position.
         * \param xRow Row where the cursor to set.
         * \param xColumn Column where the cursor to set.
         */
        virtual void setCursor(unsigned int xRow, unsigned int xColumn) = 0;

        /**
         * \brief Writes a single char to the display at row xRow and column xColumn.
         * \param xChar The single char to write.
         * \param xRow The row where the char to write.
         * \param xColumn The column where the char to write.
         * \return The same display.
         */
        virtual Display &put(char xChar, unsigned int xRow, unsigned int xColumn) = 0;

        /**
         * \brief Writes a string at a position to the display.
         * \param xLine The string to write.
         * \param xLength The string length.
         * \param xRow The row where the string to write.
         * \param xColumn The column where the string starts.
         * \return The same display.
         */
        virtual Display &write(const char *xLine, unsigned int xLength, unsigned int xRow, unsigned int xColumn) = 0;

        /**
         * \brief Writes a string at the current row to the display.
         * \param xLine The string to write.
         * \param xLength The string length.
         * \return The same display.
         */
        virtual Display &writeLine(const char *xLine, unsigned int xLength) = 0;

        /**
         * \brief Returns number of rows of the display
         */
        unsigned int rows() const {
            return mRows;
        }

        /**
         * \brief Returns number of columns of the the display
         */
        unsigned int columns() const {
            return mColumns;
        }

    private:
        unsigned int mRows;
        unsigned int mColumns;
    };

}

#endif /* DISPLAY_H_ */
