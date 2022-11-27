OBJS= main.o

all: $(OBJS)
	#cd ../build && gcc $(OBJS) -o tlvm.out
	cd ../build && ar rcs libtlvm.a $(OBJS)
%.o:%.c
	gcc -I ../include $< -c -o ../build/$@


clean:
	cd ../build && rm $(OBJS) -rf