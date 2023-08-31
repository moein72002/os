obj-m += mod_table_print.o
KERNEL = $(shell uname -r)
all:
    make -C /lib/modules/$(KERNEL)/build M=$(PWD) modules
clean:
    make -C /lib/modules/$(KERNEL)/build M=$(PWD) clean