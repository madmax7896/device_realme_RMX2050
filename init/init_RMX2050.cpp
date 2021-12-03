/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <android-base/logging.h>
#include <android-base/properties.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>
#include <sys/sysinfo.h>

#include "property_service.h"
#include "vendor_init.h"

void property_override(char const prop[], char const value[]) {
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void property_override_multifp(char const buildfp[], char const systemfp[],
        char const bootimagefp[], char const vendorfp[], char const value[]) {
    property_override(buildfp, value);
    property_override(systemfp, value);
    property_override(bootimagefp, value);
    property_override(vendorfp, value);
}

void load_RMX2050() {
    property_override("ro.product.name", "RMX2050");
    property_override("ro.product.model", "RMX2050");
    property_override("ro.product.system.model", "RMX2050");
    property_override("ro.build.product", "RMX2050");
    property_override("ro.product.device", "RMX2050");
    property_override("ro.build.description", "redfin-user 11 RQ3A.210905.001 7511028 release-keys");
}

void vendor_load_properties() {

    load_RMX2050();

    property_override("ro.oem_unlock_supported", "0");
    property_override_multifp("ro.build.fingerprint", "ro.system.build.fingerprint", "ro.bootimage.build.fingerprint",
        "ro.vendor.build.fingerprint", "google/redfin/redfin:11/RQ3A.210905.001/7511028:user/release-keys");
}
