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

#include "HyprlandOnScreenMessageManager.h"
#include <hyprland/src/debug/HyprNotificationOverlay.hpp>

void HyprlandOnScreenMessageManager::showMessage(const QString &message)
{
    g_pHyprNotificationOverlay->addNotification(QString("[%1] %2").arg(PROJECT_NAME, message).toStdString().c_str(), ICONS_COLORS[1], 5000);
}

void HyprlandOnScreenMessageManager::hideMessage()
{
    g_pHyprNotificationOverlay->dismissNotifications(1);
}