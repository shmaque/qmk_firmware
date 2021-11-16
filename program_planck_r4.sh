echo "Programming in 10 seconds... enter DFU mode now"
sleep 10

dfu-programmer atmega32u4 erase && \
dfu-programmer atmega32u4 flash planck_rev4_shmaque.hex && \
dfu-programmer atmega32u4 reset
