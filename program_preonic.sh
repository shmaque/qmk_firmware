echo "Programming in 20 seconds... enter DFU mode now"
sleep 20

dfu-programmer atmega32u4 erase && \
dfu-programmer atmega32u4 flash preonic_rev3_shmaque.bin && \
dfu-programmer atmega32u4 reset
