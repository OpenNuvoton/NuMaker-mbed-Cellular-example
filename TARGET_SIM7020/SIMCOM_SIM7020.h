/*
 * Copyright (c) 2019, Arm Limited and affiliates.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SIMCOM_SIM7020_H_
#define SIMCOM_SIM7020_H_

#ifndef MBED_CONF_SIMCOM_SIM7020_TX
#define MBED_CONF_SIMCOM_SIM7020_TX D1
#endif
#ifndef MBED_CONF_SIMCOM_SIM7020_RX
#define MBED_CONF_SIMCOM_SIM7020_RX D0
#endif
#ifndef MBED_CONF_SIMCOM_SIM7020_BAUDRATE
#define MBED_CONF_SIMCOM_SIM7020_BAUDRATE 115200
#endif

#include "AT_CellularDevice.h"

namespace mbed {

class SIMCOM_SIM7020 : public AT_CellularDevice {
public:
    SIMCOM_SIM7020(FileHandle *fh);

protected: // AT_CellularDevice
    virtual AT_CellularNetwork *open_network_impl(ATHandler &at);
    virtual AT_CellularContext *create_context_impl(ATHandler &at, const char *apn, bool cp_req = false, bool nonip_req = false);
    virtual void set_ready_cb(Callback<void()> callback);

public:
    void handle_urc(FileHandle *fh);
};
} // namespace mbed
#endif // SIMCOM_SIM7020_H_
