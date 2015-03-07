ifneq ($(KERNELRELEASE),)
	obj-m := mmap_driver.o
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build 
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
clean:
	rm -rf *.ko *.o *.order *~ *symvers *.mod.c
endif

 
