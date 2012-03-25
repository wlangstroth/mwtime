OPTIONS=-Wall

all: clean build

build:
	clang $(OPTIONS) mwtime.c -o mwtime

clean:
	rm -f mwtime

tidy:
	indent -bad -bap -i2 -l80 tardis.c
