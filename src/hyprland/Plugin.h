/*
    Input Actions - Input handler that executes user-defined actions
    Copyright (C) 2024-2025 Marcin Woźniak

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#pragma once

#include "input/HyprlandInputBackend.h"

#include <libinputactions/Config.h>
#include <libinputactions/DBusInterface.h>

#include <hyprland/src/plugins/HookSystem.hpp>
#include <hyprland/src/managers/eventLoop/EventLoopTimer.hpp>
#undef HANDLE

class Plugin
{
    INPUTACTIONS_DECLARE_SINGLETON(Plugin)

public:
    Plugin(void *handle);

    void *handle() const;

private:
    void eventLoopTick();

    void *m_handle;
    HyprlandInputBackend *m_backend;
    libinputactions::Config m_config;
    libinputactions::DBusInterface m_dbusInterface;

    SP<CEventLoopTimer> m_eventLoopTimer;
};