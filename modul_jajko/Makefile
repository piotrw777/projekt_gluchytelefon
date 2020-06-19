obj-m+=jajko.o

all:	unload compile load

compile:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules

clean:	unload
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
unload:
	-sudo rmmod jajko.ko
load:
	-sudo insmod jajko.ko
