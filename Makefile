SRC = mian.c
NAME = mian

all:
	cc $(SRC) -o $(NAME)

clean:
	rm $(NAME)
