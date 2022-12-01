OBJS= main.c vmtype/TLError.c vmtype/TLString.c

all: $(OBJS)
	#cd ../build && gcc $(OBJS) -o tlvm.out
	gcc -I ../include $(OBJS) -lc -shared -o ../libtlvm.so -fPIC 
	

clean:
	-cd ../build && rm libtlvm.so -rf
	-rm ../libtlvm.so