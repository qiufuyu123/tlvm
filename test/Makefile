SRC=main.c
all: $(SRC)
	#cd ../build && gcc $(OBJS) -o tlvm.out
	gcc  $(SRC) -I ../include -o ../tlvmtest -L../ -ltlvm -Wl,-rpath=./
	
clean:
	-rm -rf test