#
# Copyright (C) 2021 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/languages_full.mk)

# Inherit some common Lineage stuff
#WITH_GMS := true
$(call inherit-product, vendor/lineage/config/common_full_phone.mk)

# Inherit from RMX2050 device
$(call inherit-product, $(LOCAL_PATH)/device.mk)

PRODUCT_BRAND := realme
PRODUCT_DEVICE := RMX2050
PRODUCT_MANUFACTURER := realme
PRODUCT_NAME := lineage_RMX2050
PRODUCT_MODEL := RMX2050

PRODUCT_GMS_CLIENTID_BASE := android-oppo
