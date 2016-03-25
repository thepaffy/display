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

#include "serialdisplay.h"
#include <boost/asio/serial_port.hpp>
#include <cstdlib>
#include <cassert>

using namespace boost::asio;

namespace display {
    struct SerialDisplayPrivate {
        io_service mIoService;
        serial_port *mSerialPort;
    };

    SerialDisplay::SerialDisplay(std::string const &xDeviceName, unsigned int xRows,
                                 unsigned int xColumns)
            : Display(xRows, xColumns) {
        assert(xRows <= 10 && xColumns <= 100);
        m = new SerialDisplayPrivate;
        m->mSerialPort = new serial_port(m->mIoService, xDeviceName.c_str());
        m->mSerialPort->set_option(serial_port_base::baud_rate(38400));
        m->mSerialPort->set_option(serial_port_base::character_size(8));
        m->mSerialPort->set_option(
                serial_port_base::stop_bits(serial_port_base::stop_bits::one));
        m->mSerialPort->set_option(
                serial_port_base::parity(serial_port_base::parity::none));
        m->mSerialPort->set_option(
                serial_port_base::flow_control(
                        serial_port_base::flow_control::software));
    }

    SerialDisplay::~SerialDisplay() {
        delete m;
    }

    void SerialDisplay::clear() {
        m->mSerialPort->write_some(buffer("~C"));
    }

    void SerialDisplay::resetCursor() {
        m->mSerialPort->write_some(buffer("~H"));
    }

    void SerialDisplay::setCursor(unsigned int xRow, unsigned int xColumn) {
        assert(xRow < rows() && xColumn < columns());
        std::string tCommand = "~P";
        tCommand += rowAndColumnToString(xRow, xColumn);
        m->mSerialPort->write_some(buffer(tCommand));
    }

    void SerialDisplay::setCursorMode(CursorMode xMode) {
        std::string tCommand = "~K";
        tCommand += std::to_string(xMode);
        m->mSerialPort->write_some(buffer(tCommand));
    }

    SerialDisplay &SerialDisplay::put(char xChar, unsigned int xRow,
                                      unsigned int xColumn) {
        assert(xRow < rows() && xColumn < columns());
        std::string tCommand = "~P";
        tCommand += rowAndColumnToString(xRow, xColumn);
        tCommand += xChar;
        m->mSerialPort->write_some(buffer(tCommand));
        return *this;
    }

    SerialDisplay &SerialDisplay::write(const char *xLine, unsigned int xLength,
                                        unsigned int xRow, unsigned int xColumn) {
        assert(xRow < rows() && xColumn < columns() && xLength < columns() - xColumn);
        std::string tCommand = "~P";
        tCommand += rowAndColumnToString(xRow, xColumn);
        tCommand.append(xLine, xLength);
        m->mSerialPort->write_some(buffer(tCommand));
        return *this;
    }

    SerialDisplay &SerialDisplay::writeLine(const char *xLine, unsigned int xLength) {
        assert(xLength < columns());
        std::string tCommand = std::string(xLine, xLength);
        m->mSerialPort->write_some(buffer(tCommand));
        return *this;
    }

    std::string SerialDisplay::rowAndColumnToString(unsigned int xRow,
                                                    unsigned int xColumn) {
        std::string tString = std::to_string(xRow);
        if (xColumn < 10)
            tString += "0";
        tString += std::to_string(xColumn);
        return tString;
    }

}
