/*
 * helper_win_lin.h
 *
 * Convenience macros simplifying ZMK's keymap configuration.
 * See https://github.com/urob/zmk-nodefree-config for documentation.
 */

#pragma once

/* ZMK_UNICODE */
#define LIN_UNICODE_LEAD &macro_tap &kp LS(LC(U))   // Linux
#define WIN_UNICODE_LEAD &macro_tap &kp RALT &kp U  // Windows + WinCompose (default)
#define LIN_UNICODE_TRAIL &macro_tap &kp SPACE     // Linux
#define WIN_UNICODE_TRAIL &macro_tap &kp RET       // Windows + WinCompose (default)

#define UC_MACRO_LIN(name, unicode_bindings) \
    / { \
        macros { \
            name: name { \
                compatible = "zmk,behavior-macro"; \
                label = ZMK_HELPER_STRINGIFY(UC_MACRO_ ## name); \
                wait-ms = <0>; \
                tap-ms = <0>; \
                #binding-cells = <0>; \
                bindings = <LIN_UNICODE_LEAD>, <&macro_tap unicode_bindings>, <LIN_UNICODE_TRAIL>; \
            }; \
        }; \
    };

#define UC_MACRO_WIN(name, unicode_bindings) \
    / { \
        macros { \
            name: name { \
                compatible = "zmk,behavior-macro"; \
                label = ZMK_HELPER_STRINGIFY(UC_MACRO_ ## name); \
                wait-ms = <0>; \
                tap-ms = <0>; \
                #binding-cells = <0>; \
                bindings = <WIN_UNICODE_LEAD>, <&macro_tap unicode_bindings>, <WIN_UNICODE_TRAIL>; \
            }; \
        }; \
    };

#define ZMK_UNICODE_SINGLE_LIN(name, L0, L1, L2, L3) \
    UC_MACRO_LIN(name ## _lower, &kp L0 &kp L1 &kp L2 &kp L3) \
    UC_MODMORPH(name, &name ## _lower, &none)

#define ZMK_UNICODE_SINGLE_WIN(name, L0, L1, L2, L3) \
    UC_MACRO_WIN(name ## _lower, &kp L0 &kp L1 &kp L2 &kp L3) \
    UC_MODMORPH(name, &name ## _lower, &none)

#define ZMK_UNICODE_PAIR_LIN(name, L0, L1, L2, L3, U0, U1, U2, U3) \
    UC_MACRO_LIN(name ## _lower, &kp L0 &kp L1 &kp L2 &kp L3) \
    UC_MACRO_LIN(name ## _upper, &kp U0 &kp U1 &kp U2 &kp U3) \
    UC_MODMORPH(name, &name ## _lower, &name ## _upper)

#define ZMK_UNICODE_PAIR_WIN(name, L0, L1, L2, L3, U0, U1, U2, U3) \
    UC_MACRO_WIN(name ## _lower, &kp L0 &kp L1 &kp L2 &kp L3) \
    UC_MACRO_WIN(name ## _upper, &kp U0 &kp U1 &kp U2 &kp U3) \
    UC_MODMORPH(name, &name ## _lower, &name ## _upper)
