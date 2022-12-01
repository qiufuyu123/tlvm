all:
	cd tlvm && make all
	cd test && make all
	./tlvmtest
clean:
	cd tlvm && make clean
	cd test && make clean