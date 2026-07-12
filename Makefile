NAME = push_swap
CHECKER = checker
CC = gcc
CLFAGS = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -f

SRC = disorder \
		normalize \
		operations_swap \
		operations_push \
		operations_rotate \
		operations_rev_rotate \
		push_swap \
		sort_adaptive \
		sort_complex \
		sort_medium \
		sort_simple \
		stack_operations \
		stack \
		utils_find \
		utils	\
		utils_write \
		utils_parsing \
		utils_push_swap \
		utils_simple \
		utils_medium \
		bench \

SRC_MAIN = main.c
SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))
TEST_SRCS = $(wildcard tests/test_*.c)
TEST_TARGETS = $(TEST_SRCS:tests/test_%.c=test_%)


all: $(NAME) $(CHECKER)

$(NAME): $(OBJS) $(SRC_MAIN)
	$(CC) $(CFLAGS) $(SRC_MAIN) $(OBJS) -o $(NAME)

$(CHECKER): $(OBJS) checker_linux
	cp checker_linux $(CHECKER)
	chmod +x $(CHECKER)

$(TEST_TARGETS): test_%: tests/test_%.c $(NAME)
	$(CC) $(CFLAGS) $< -L. -push_swap -o $@

all_tests: $(TEST_TARGETS)

single_test: $(NAME)
	$(CC) $(CFLAGS) tests/test_$(TEST).c -L. -push_swap -o test_$(TEST)
	./test_$(TEST)

# Esegue tutti i test
run_tests: all_tests
	@for test in $(TEST_TARGETS); do \
		echo "================== $$test =================="; \
		./$$test; \
		echo; \
	done

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(TEST_TARGETS) $(CHECKER)

re: fclean all

debug:
	@echo "SRC = $(SRC)"
	@echo "OBJS = $(OBJS)"

.PHONY: all clean fclean re bonus all_tests run_tests
