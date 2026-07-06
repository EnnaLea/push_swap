NAME = pushswap.a
CC = cc
CLFAGS = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -f

SRC = cost \
		disorder \
		main \
		normalize \
		operations \
		push_swap \
		sort_adaptive \
		sort_complex \
		sort_medium \
		sort_simple \
		stack_operations \
		stack \
		utils \

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))
TEST_SRCS = $(wildcard tests/test_*.c)
TEST_TARGETS = $(TEST_SRCS:tests/test_%.c=test_%)


$(NAME): $(OBJS)
	$(AR) $@ $^


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_TARGETS): test_%: tests/test_%.c $(NAME)
	$(CC) $(CFLAGS) $< -L. -lpushswap -o $@


all: $(NAME)

all_tests: $(TEST_TARGETS)

single_test: $(NAME)
	$(CC) $(CFLAGS) tests/test_$(TEST).c -L. -lpushswap -o test_$(TEST)
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
	$(RM) $(NAME) $(TEST_TARGETS)

re: fclean all

debug:
	@echo "SRC = $(SRC)"
	@echo "OBJS = $(OBJS)"

.PHONY: all clean fclean re bonus all_tests run_tests
