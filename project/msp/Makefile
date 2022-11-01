COMMON_OBJECTS 	=
CPU 		=msp430g2553
CFLAGS		=-mmcu=${CPU} -I../h
LDFLAGS		=-L/opt/ti/msp430_gcc/include

CC		= msp430-elf-gcc
AS		= msp430-elf-as

all: button.elf

button.elf: ${COMMON_OBJECTS} buzzer.o state_machine.o interrupt_handler.o led.o switches.o main.o toggle.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button.elf
	msp430loader.sh button.elf

clean:
	rm -f *.o *.elf *.h~ *.c~ *.s~
