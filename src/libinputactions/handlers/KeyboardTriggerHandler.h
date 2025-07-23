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

#include "TriggerHandler.h"

namespace libinputactions
{

class KeyboardTriggerHandler : public TriggerHandler
{
public:
    bool handleEvent(const InputEvent &event) override;

protected:
    std::unique_ptr<TriggerActivationEvent> createActivationEvent() const override;

private:
    bool handleEvent(const KeyboardKeyEvent &event);

    bool m_block;
    std::set<uint32_t> m_keys;
    uint32_t m_firstKey{};

    friend class TestKeyboardTriggerHandler;
};

}