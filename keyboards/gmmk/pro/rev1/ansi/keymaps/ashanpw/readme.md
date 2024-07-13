# Description

Pretty simple keymap with a few handy tools on a 2nd layer and rotary encoder.

# Encoder

Holding tab and scrolling encoder will allow scrolling through applications, as if using alt + tab  
Holding ctrl and scrolling encoder will allow scrolling through chrome tabs  
FN + Encoder scroll is media next/prev  
FN + Encoder press is media pause  
default encoder behavior is volume up/down

# Function Layer

FN + \ is used to put keyboard into bootloader mode  
FN + ESC is the same as alt F4, for closing applications  
FN + F1 is to close current browser tab  
FN + Q moves current application one monitor to the left  
FN + W maximizes current application  
FN + E moves current application one monitor to the right  
FN + S minimizes current application  
FN + F is used in junction with the "Popout tab" extension to chrome (https://chrome.google.com/webstore/detail/popout-tab/pcfcieidiaaobigemjnkclebhnmgfbco) to pop out current tab to its own window

# Flashing

-   Open the QMK MSYS application
-   Go to the qmk_firmware folder (e.g. C:\Users\{USER}\Documents\qmk_firmware)
-   Run this command to compele `qmk compile -kb gmmk/pro/rev1/ansi -km ashanpw`
-   Put keyboard into bootloader mode (CAPS + some key)
-   Then run this comment qmk flash -kb `gmmk/pro/rev1/ansi -km ashanpw`
