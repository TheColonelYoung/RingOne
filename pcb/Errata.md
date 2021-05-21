# Errata

## V1.0
- USB data lines are swapped
    - Consequences: USB communication is not working
    - Solution: remove 22R resistors on data lines and connect wires to resistors pads to reconnect lines properly

- Power switch detection have wrong voltage level
    - GPIO are 5V tolerant only when VDD is applied
    - Because switch is used to enable MCU power there is short interval when voltage higher then 3.6V is applied to GPIO
    - Consequences: There is possibility that MCU can be damaged during power enabling sequence
    - Solution: add 100k resistor to PWR_BTN connection, trace can be cut near PWR_BTN test point and is enough space to solder resistor to traces

- Zener diode on PWR_EN net have incorrect rating
    - Voltage produced by Schmitt trigger is equal to VCC (USB VCC - up to 5V), zener diode has rating of 3.3V
    - Zener diode will be open after power is enabled by power switch
    - Consequences: Zener diode damage, possible damage of Schmitt trigger
